#!/usr/bin/env bash

env

mkdir /build
cd /build || exit

echo Build /sources in "$(pwd)..."
cmake /sources

make clean all test

if [ "$SONAR" = "true" ]; then
  echo "Sonar is enabled"
  /build-wrapper-linux-x86/build-wrapper-linux-x86-64 --out-dir /bw-output make clean thvm
fi