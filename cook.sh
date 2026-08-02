#!/bin/bash
set -e

mkdir -p build
rm -rf build/*
echo "[LOG] STATUS <==> Cleaning build files..."

echo "[LOG] STATUS <==> Preparing build files..."
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release

echo "[LOG] STATUS <==> Building..."
cmake --build build

./build/vulkan_engine
echo "[LOG] STATUS <==> Running Engine..."