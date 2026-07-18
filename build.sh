#!/bin/bash

# STM32F407 Build Script
# Cleans and builds the project

echo "🔨 Building STM32F407 Drivers Project..."
echo ""

cd Debug

# Clean previous build
echo "🗑️  Cleaning previous build..."
make clean > /dev/null 2>&1

# Build
echo "⚙️  Compiling and linking..."
make all

# Check if build succeeded
if [ $? -eq 0 ]; then
    echo ""
    echo "✅ Build successful!"
    echo ""
    echo "📦 Output files:"
    ls -lh stm32f4xx_drivers.elf stm32f4xx_drivers.map stm32f4xx_drivers.list 2>/dev/null | awk '{print "   " $9 " (" $5 ")"}'
    echo ""
    echo "📊 Firmware size:"
    arm-none-eabi-size stm32f4xx_drivers.elf
else
    echo ""
    echo "❌ Build failed!"

    # Motivational quotes shown when build fails
    quotes=(
        "Failure is a stepping stone to success — keep pushing."
        "Don't be discouraged. Every error is a lesson."
        "Debugging is twice as hard as writing the code; keep going."
        "Perseverance is the key — retry with curiosity."
        "Every mistake teaches something new. Stay persistent."
    )

    # Color codes for quote display
    color_codes=("\e[1;31m" "\e[1;33m" "\e[1;32m" "\e[1;34m" "\e[1;35m")
    reset="\e[0m"

    idx=$((RANDOM % ${#quotes[@]}))

    # Print the quote with multiple colors (cycle colors per word)
    quote="${quotes[$idx]}"
    IFS=' ' read -r -a words <<< "$quote"
    n=${#color_codes[@]}

    printf "\n💬 Motivational quote:\n  "
    for i in "${!words[@]}"; do
        color=${color_codes[$((i % n))]}
        printf "%b%s%b" "$color" "${words[$i]}" "$reset"
        # print a space after each word (preserve spacing)
        printf " "
    done
    printf "\n\n"
    exit 1
fi
