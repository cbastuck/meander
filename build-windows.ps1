param(
  [ValidateSet('Debug', 'Release', 'RelWithDebInfo', 'MinSizeRel')]
  [string]$Configuration = 'Release',

  [ValidateSet('ON', 'OFF')]
  [string]$EmbeddedFrontend = 'ON',

  [ValidateSet('x64-windows', 'x64-windows-static')]
  [string]$VcpkgTriplet = 'x64-windows',

  [string]$Generator = 'Visual Studio 17 2022',
  [string]$Architecture = 'x64'
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

Write-Host "==> Building meander frontend"
Write-Host "    embedded frontend: $EmbeddedFrontend"

if ($EmbeddedFrontend -eq 'ON') {
  npm --prefix hkp-frontend ci
  npm --prefix meander/frontend ci
  npm --prefix meander/frontend run build
} else {
  Write-Host '==> Skipping frontend build because embedded frontend is OFF'
}

Write-Host "==> Configuring CMake"
cmake -B build -S . `
  -G "$Generator" -A $Architecture `
  -DCMAKE_TOOLCHAIN_FILE=3rdparty/vcpkg/scripts/buildsystems/vcpkg.cmake `
  -DVCPKG_MANIFEST_DIR=3rdparty `
  -DVCPKG_TARGET_TRIPLET=$VcpkgTriplet `
  -DBUILD_HKP_SAUCER=ON `
  -DMEANDER_USE_EMBEDDED_FRONTEND=$EmbeddedFrontend

Write-Host "==> Building CMake target (config: $Configuration)"
cmake --build build --config $Configuration --parallel

Write-Host '==> Done: build'
