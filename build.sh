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
    exit 1
fi
