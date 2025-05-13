#!/bin/bash

# Create virtual environment
python -m venv venv

# Activate virtual environment
if [ -d "venv/Scripts" ]; then
    source venv/Scripts/activate
else
    source venv/bin/activate
fi

# Run the example
python examples/List_Queue_Examples.py

# Deactivate virtual environment
deactivate
