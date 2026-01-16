#!/usr/bin/env bash
set -euo pipefail

rm -rf build

BUILD_DIR=build
TYPE=Debug

cmake -S . -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE="$TYPE" "$@"
cmake --build "$BUILD_DIR" --parallel
