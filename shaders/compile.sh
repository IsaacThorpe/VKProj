#!/usr/bin/env bash

set -e

SHADER_DIR="shaders"
OUT_DIR="build/shaders"

echo "Compiling shaders in: $SHADER_DIR"
echo "Output directory: $OUT_DIR"

# Create output directory if it doesn't exist
mkdir -p "$OUT_DIR"

# Loop through shader files
find "$SHADER_DIR" -type f \( -name "*.vert" -o -name "*.frag" -o -name "*.comp" \) | while read -r shader; do
    filename=$(basename "$shader")
    output="$OUT_DIR/$filename.spv"

    echo "Compiling: $shader -> $output"

    glslc "$shader" -o "$output"
done

echo "All shaders compiled successfully."