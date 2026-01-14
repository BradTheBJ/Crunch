#!/usr/bin/env bash
set -euo pipefail

BUILD_DIR=build
TYPE=Release   # default

case "${1:-}" in
  debug)
    TYPE=Debug
    shift
    ;;
  release)
    TYPE=Release
    shift
    ;;
esac

cmake -S . -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE="$TYPE" "$@"
cmake --build "$BUILD_DIR" --parallel
