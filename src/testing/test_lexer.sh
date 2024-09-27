#!/bin/bash

# Author: Your Name
# Year: 2023

set -uo pipefail

# Navigate to the parent directory where the Makefile is located
cd ..

# Check for Makefile presence
if [ ! -f "Makefile" ]; then
    echo "Makefile not found in the current directory."
    exit 1
fi

# Clean previous builds if the clean target exists
if make clean &> /dev/null; then
    echo "Cleaning previous builds..."
else
    echo "No clean target found in Makefile."
fi

set -e

# Generate parser files
if make build/parser.tab.cpp build/parser.tab.hpp; then
    echo "Generated parser files."
else
    echo "Failed to generate parser files. Ensure your Makefile has the correct targets."
    exit 1
fi

# Generate lexer file
if make build/lexer.yy.cpp; then
    echo "Generated lexer file."
else
    echo "Failed to generate lexer file. Ensure your Makefile has the correct targets."
    exit 1
fi

# Compile the lexer
echo "Compiling the lexer..."
if g++ -o lexer build/parser.tab.cpp build/lexer.yy.cpp -I include -lfl; then
    echo "Lexer compiled successfully."
else
    echo "Compilation failed."
    exit 1
fi

# Create output directory for test results
mkdir -p bin/output

# Test the lexer with a specified input file
INPUT_FILE="${1:-test_input.txt}"
LOG_FILE="bin/output/lexer_output.log"

echo "Testing lexer with input file: ${INPUT_FILE}..."
if ./lexer < "$INPUT_FILE" > "$LOG_FILE" 2>&1; then
    echo "Lexer test completed successfully."
    echo "Output logged to: ${LOG_FILE}"
else
    echo "Lexer test failed. Check the log for details."
    cat "$LOG_FILE"
fi

# Cleanup
echo "Cleaning up generated files..."
rm -f lexer build/parser.tab.cpp build/parser.tab.hpp build/lexer.yy.cpp

# Navigate back to the original directory
cd src
