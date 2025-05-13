# Build script for Windows
Write-Host "Dang tien hanh xay dung chuong trinh quan ly nha thuoc..." -ForegroundColor Green

# Create bin directory if it doesn't exist
if (!(Test-Path "bin")) {
    New-Item -ItemType Directory -Path "bin"
}

# Compile main program
Write-Host "Dang bien dich chuong trinh chinh..." -ForegroundColor Yellow
gcc -Wall -Wextra -g src/main.c src/queue.c -o bin/pharmacy.exe
if ($LASTEXITCODE -eq 0) {
    Write-Host "Bien dich chuong trinh chinh thanh cong!" -ForegroundColor Green
} else {
    Write-Host "Loi khi bien dich chuong trinh chinh!" -ForegroundColor Red
    exit 1
}

# Compile performance test
Write-Host "Dang bien dich bai test hieu suat..." -ForegroundColor Yellow
gcc -Wall -Wextra -g test/performance_test.c src/queue.c -o bin/performance_test.exe
if ($LASTEXITCODE -eq 0) {
    Write-Host "Bien dich bai test thanh cong!" -ForegroundColor Green
} else {
    Write-Host "Loi khi bien dich bai test!" -ForegroundColor Red
    exit 1
}

Write-Host "Xay dung hoan tat!" -ForegroundColor Green
Write-Host "`nDe chay chuong trinh:`n  .\\bin\\pharmacy.exe`nDe chay test hieu suat:`n  .\\bin\\performance_test.exe" -ForegroundColor Cyan
