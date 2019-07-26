#!/usr/bin/env bash

env

cd /build || exit

echo Build /src in "$(pwd)..."
cmake -DCMAKE_BUILD_TYPE=Debug /src

if [ "$SONAR" = "true" ]; then
  /build-wrapper-linux-x86/build-wrapper-linux-x86-64 --out-dir bw-output make clean all test
else
  make clean all test
fi