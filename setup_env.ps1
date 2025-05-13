# Check if Python is installed
if (!(Get-Command python -ErrorAction SilentlyContinue)) {
    Write-Host "Error: Python is not installed or not in PATH" -ForegroundColor Red
    exit 1
}

# Check if virtualenv exists
if (!(Test-Path "venv")) {
    Write-Host "Creating virtual environment..." -ForegroundColor Green
    python -m venv venv
}

# Activate virtual environment
Write-Host "Activating virtual environment..." -ForegroundColor Green
.\venv\Scripts\Activate.ps1

# Run the example
Write-Host "Running Python example..." -ForegroundColor Green
python examples/List_Queue_Examples.py

# Deactivate virtual environment
deactivate

Write-Host "Done!" -ForegroundColor Green
