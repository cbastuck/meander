# Repository

How the code is laid out: one superproject, five submodules, and a rule about which is which.

---

## Two kinds of directory

Everything lives under one checkout, but not everything lives in one
*repository*. Some directories are ordinary folders with their history in the
superproject; five are **git submodules** with histories of their own.

The distinction is invisible in a file listing and decides how a change is
committed, so it is worth knowing before the first commit rather than after.

| Directory | Repository | What it is |
|---|---|---|
| `hkp-frontend/` | superproject | React app: playground UI, board engine, every browser service |
| `hkp-rt/` | superproject | C++ runtime — audio, high performance, embedded in the apps |
| `meander/` | superproject | The Readymade desktop app: a saucer webview shell (`backend/`) around the frontend (`frontend/`) |
| `docs/` | superproject | These pages, and the small site that serves them |
| `3rdparty/`, `scripts/`, `deployments/` | superproject | Vendored dependencies, tooling, packaging |
| `hkp-node/` | **submodule** | Node.js runtime server, published as its own package |
| `hkp-python/` | **submodule** | Python runtime server, installed into its own virtualenv |
| `hkp-website/` | **submodule** | readymadeit.com — deployed on its own, to its own host |
| `meander-ios/` | **submodule** | SwiftUI shell embedding the mobile playground and an in-process `hkp-rt` |
| `meander-android/` | **submodule** | Android shell doing the same through a `WebView` |

---

## Why the split falls where it does

A submodule is not a way of tidying up a large tree — it is a separate release.
Each of the five is something a person can obtain **without this repository**:

- `hkp-node` is run with `npx hkp-node`, installed globally, or pulled as a
  container. Someone running a board's server half never clones the superproject.
- `hkp-python` is installed into a virtualenv, with optional extras for the heavy
  model dependencies.
- `hkp-website` is deployed to a web host on its own schedule, and its history is
  full of copy changes that mean nothing to the engine.
- `meander-ios` and `meander-android` are built by platform toolchains — Xcode
  and Gradle — with their own signing, store metadata and release cadence.

Whereas `hkp-frontend`, `hkp-rt` and `meander` are **one build and one release**:
the desktop app compiles the C++ runtime and embeds the frontend, and a change
that spans the three is one change. Splitting them would mean a version dance
between parts that are always shipped together.

The rule, stated once: **a submodule is a thing with its own release; a folder is
a thing released with everything else.**

---

## What the superproject records

Not the submodule's files — a **commit id** per submodule, saying which revision
of it this revision of the superproject expects. Two consequences follow, and
both surprise people once:

- **A change spanning both is two commits**, in order: commit inside the
  submodule, then commit the moved pointer in the superproject. Stopping after
  the first leaves a superproject that still names the old revision, which is how
  a fix that "is definitely committed" fails to arrive for somebody else.
- **`git status` in the superproject reports the submodule, not the file.** A
  line reading `M hkp-node` means that submodule's worktree differs from the
  recorded pointer — edited, or on a different commit — and says nothing about
  which files inside changed. `git status` inside the submodule, or
  `git submodule status`, answers that.

The submodules are addressed by **relative URLs** (`../hkp-node.git`) except the
website, which is on a different host entirely. A relative URL resolves against
wherever the superproject itself was cloned from, so the same `.gitmodules` works
for a clone over SSH and one over HTTPS without a per-user edit.

---

## Building

There is no build that builds everything, because the parts do not share a
toolchain:

| Part | Built with | Entry point |
|---|---|---|
| `hkp-rt` + `meander` (desktop) | CMake + vcpkg | `CMakeLists.txt` at the root — it adds `3rdparty`, `hkp-rt` and `meander`, and nothing else |
| `hkp-frontend`, `docs`, `hkp-website`, `hkp-node` | npm + Vite / tsc | `package.json` in each |
| `hkp-python` | hatchling, in a virtualenv | `pyproject.toml` |
| `meander-ios` | CMake + Xcode | `build-ios.sh` at the root, which builds the mobile web app first |
| `meander-android` | Gradle + NDK | `build.gradle.kts`, and `README-android.md` at the root |

The root scripts — `build.sh`, `build-ios.sh`, `build-linux.sh`,
`build-windows.ps1` — are the per-platform entry points, and each README at the
root (`README-macos.md`, `README-ios.md`, `README-android.md`, …) covers one
platform's prerequisites.

---

## Testing

`run-all-tests.sh` at the root runs six suites in order — hkp-python, hkp-node,
hkp-rt, the desktop backend, the frontend's demo-board regression, and the rest
of the frontend — and prints a pass/fail table rather than stopping at the first
failure, so one run tells you everything that is broken.

**CI is narrower than that.** `.github/workflows/run-all-tests.yml` checks out
with `submodules: false` and runs hkp-rt and hkp-frontend only. That is not an
oversight, it is the same split again: the submodules answer for themselves, and
a superproject workflow that cloned them would be testing somebody else's commit.
It does mean a change to hkp-node or hkp-python is covered by *its* repository's
tests and by whoever runs the script locally — worth remembering before relying
on a green tick here.

---

## What this costs, and where it shows up

A tool that reasons about "what changed" cannot ask one repository, because a
change genuinely spanning the tree is several diffs with nothing joining them.
The vocabulary checker is the worked example: `scripts/vocabulary.mjs` takes the
superproject's diff *and* each submodule's, because the paths it verifies live on
both sides of the boundary and a diff from the superproject alone reports
`hkp-node` as one changed path rather than the file inside it that moved.

Anything else that walks the tree — a search, a release script, a review — has
the same problem, and the same answer: iterate the list in `.gitmodules`.

---

## Rough index into the source

| Concern | Where |
|---|---|
| Which directories are submodules | `.gitmodules` |
| What the desktop build compiles | `CMakeLists.txt` |
| Running every suite | `run-all-tests.sh`, `run-all-cpp-tests.sh` |
| What CI covers | `.github/workflows/run-all-tests.yml` |
| Per-platform prerequisites | `README-macos.md`, `README-ios.md`, `README-android.md`, `README-linux.md`, `README-windows.md`, `README-web.md` |
| Iterating submodules in a script | `scripts/vocabulary.mjs` |

---

See also: **Runtime** (`concepts/runtime.md`) for what each of these parts *is*
in a running board, and **Vocabulary** (`vocabulary.md`) for the word-to-file
lookup across all of them.
