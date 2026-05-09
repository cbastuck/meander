#!/usr/bin/env bash
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${REPO_ROOT}/build"
TOOLCHAIN="${REPO_ROOT}/3rdparty/vcpkg/scripts/buildsystems/vcpkg.cmake"
VCPKG_MANIFEST_DIR="${REPO_ROOT}/3rdparty"
FRONTEND_DIR="${REPO_ROOT}/meander/frontend"
HKP_FRONTEND_DIR="${REPO_ROOT}/hkp-frontend"
CONFIG="${1:-Release}"
EMBEDDED_FRONTEND="${2:-ON}"
UNIVERSAL_BINARY="${3:-OFF}"
VCPKG_TARGET_TRIPLET=""

if [[ "${EMBEDDED_FRONTEND}" != "ON" && "${EMBEDDED_FRONTEND}" != "OFF" ]]; then
    echo "ERROR: Second argument must be exactly ON or OFF."
    echo "Usage: ./build.sh [Release|Debug|RelWithDebInfo|MinSizeRel] [ON|OFF] [ON|OFF]"
    exit 2
fi

if [[ "${UNIVERSAL_BINARY}" != "ON" && "${UNIVERSAL_BINARY}" != "OFF" ]]; then
    echo "ERROR: Third argument must be exactly ON or OFF (universal binary)."
    echo "Usage: ./build.sh [Release|Debug|RelWithDebInfo|MinSizeRel] [ON|OFF] [ON|OFF]"
    exit 2
fi

if [[ "${EMBEDDED_FRONTEND}" == "OFF" && "${CONFIG}" != "Debug" && "${CONFIG}" != "debug" ]]; then
    echo "ERROR: Dev server mode only supports Debug builds."
    echo "Use: ./build.sh Debug OFF"
    exit 2
fi

if [[ "${UNIVERSAL_BINARY}" == "ON" ]]; then
    OSX_ARCHITECTURES="arm64;x86_64"
else
    OSX_ARCHITECTURES="$(uname -m)"
    if [[ "${OSX_ARCHITECTURES}" == "arm64" ]]; then
        VCPKG_TARGET_TRIPLET="arm64-osx"
    elif [[ "${OSX_ARCHITECTURES}" == "x86_64" ]]; then
        VCPKG_TARGET_TRIPLET="x64-osx"
    fi
fi

echo "==> Building meander frontend"
echo "    frontend: ${FRONTEND_DIR}"
echo "    embedded frontend: ${EMBEDDED_FRONTEND}"

if [[ "${EMBEDDED_FRONTEND}" == "ON" ]]; then
    if [[ ! -d "${HKP_FRONTEND_DIR}/node_modules" ]]; then
        echo "==> Installing hkp-frontend dependencies"
        npm --prefix "${HKP_FRONTEND_DIR}" ci
    fi

    if [[ ! -d "${FRONTEND_DIR}/node_modules" ]]; then
        echo "==> Installing frontend dependencies"
        npm --prefix "${FRONTEND_DIR}" ci
    fi

    npm --prefix "${FRONTEND_DIR}" run build
else
    echo "==> Skipping frontend build because embedded frontend is OFF"
fi

echo "==> Building meander (config: ${CONFIG})"
echo "    repo: ${REPO_ROOT}"
echo "    build: ${BUILD_DIR}"
echo "    universal binary: ${UNIVERSAL_BINARY}"
echo "    architectures: ${OSX_ARCHITECTURES}"

if [[ ! -f "${TOOLCHAIN}" ]]; then
    echo "ERROR: Missing vcpkg toolchain file: ${TOOLCHAIN}"
    echo "Ensure vcpkg is initialized at 3rdparty/vcpkg before running build.sh"
    exit 2
fi

if [[ ! -f "${VCPKG_MANIFEST_DIR}/vcpkg.json" ]]; then
    echo "ERROR: Missing vcpkg manifest: ${VCPKG_MANIFEST_DIR}/vcpkg.json"
    exit 2
fi

echo "    vcpkg manifest: ${VCPKG_MANIFEST_DIR}/vcpkg.json"
if [[ -n "${VCPKG_TARGET_TRIPLET}" ]]; then
    echo "    vcpkg triplet: ${VCPKG_TARGET_TRIPLET}"
fi

CMAKE_ARGS=(
    -B "${BUILD_DIR}"
    -S "${REPO_ROOT}"
    -DCMAKE_BUILD_TYPE="${CONFIG}"
    -DCMAKE_OSX_ARCHITECTURES="${OSX_ARCHITECTURES}"
    -DVCPKG_MANIFEST_DIR="${VCPKG_MANIFEST_DIR}"
    -DBUILD_HKP_SAUCER=ON
    -DMEANDER_USE_EMBEDDED_FRONTEND="${EMBEDDED_FRONTEND}"
    -GXcode
)

if [[ -n "${VCPKG_TARGET_TRIPLET}" ]]; then
    CMAKE_ARGS+=("-DVCPKG_TARGET_TRIPLET=${VCPKG_TARGET_TRIPLET}")
fi

cmake "${CMAKE_ARGS[@]}"

cmake --build "${BUILD_DIR}" --config "${CONFIG}" --parallel "$(sysctl -n hw.logicalcpu 2>/dev/null || nproc)"

echo "==> Done: ${BUILD_DIR}"
