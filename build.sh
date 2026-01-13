#!/usr/bin/env bash
set -euo pipefail

# Configure
BUILD_DIR=build
rm -rf "$BUILD_DIR"
mkdir "$BUILD_DIR"

cd "$BUILD_DIR"
# Ensure compatibility for some vendored CMakeLists (freetype etc.)
# Allow user to override by passing their own CMake args.
DEFAULT_CMAKE_FLAGS=("-DCMAKE_POLICY_VERSION_MINIMUM=3.5")
cmake -S .. -B "$BUILD_DIR" "${DEFAULT_CMAKE_FLAGS[@]}" "$@"

# Determine parallel build jobs (nproc on Linux, sysctl on macOS)
if command -v nproc >/dev/null 2>&1; then
  JOBS=$(nproc)
else
  JOBS=$(sysctl -n hw.ncpu 2>/dev/null || echo 2)
fi

# Build
cmake --build "$BUILD_DIR" --parallel "$JOBS"

# Try to run common-named binary, otherwise first executable in build/
export DYLD_LIBRARY_PATH="$BUILD_DIR:${DYLD_LIBRARY_PATH:-}"
export LD_LIBRARY_PATH="$BUILD_DIR:${LD_LIBRARY_PATH:-}"

if [ -x "$BUILD_DIR/Crunch" ]; then
  exec "$BUILD_DIR/Crunch"
fi

EXE=$(find "$BUILD_DIR" -maxdepth 2 -type f -perm -111 -not -name "*.so" -not -name "*.a" -print -quit 2>/dev/null || true)
if [ -n "$EXE" ]; then
  exec "$EXE"
fi

echo "Build finished; no runnable executable found in $BUILD_DIR"
exit 0
cmake ..

# Build the project using make
make

# Run the executable
./Crunch
