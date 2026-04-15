#!/usr/bin/env bash

set -e

SHADER_DIR="shaders"
OUT_DIR="shaders"

echo "Compiling shaders in: $SHADER_DIR"

# Loop through shader files
find "$SHADER_DIR" -type f \( -name "*.vert" -o -name "*.frag" -o -name "*.comp" \) | while read -r shader; do
    filename=$(basename "$shader")
    output="$OUT_DIR/$filename.spv"

    echo "Compiling: $shader -> $output"

    glslc "$shader" -o "$output"

    if [ $? -ne 0 ]; then
        echo "Failed to compile $shader"
        exit 1
    fi
done

echo "All shaders compiled successfully."