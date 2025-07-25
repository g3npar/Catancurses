#!/bin/bash

# Path to the directory containing your Catan code and executable
CODE_DIR="/home/parinr/catancurses"
CATAN_FILE="${CODE_DIR}/catan"

# Function to compile and run the Catan file
run_catan() {
    clear  # Clear the terminal for a clean ncurses GUI
    echo "Compiling the project..."
    if make -C "$CODE_DIR"; then
        echo "Build successful. Running the application..."
        "$CATAN_FILE"
    else
        echo "Build failed. Fix the errors and save the file to retry."
    fi
}

# Initial run
run_catan

# Wait for user input to re-run the Catan file
while true; do
    echo "Press Enter to recompile and run the application..."
    read -r  # Wait for Enter key press
    run_catan
done