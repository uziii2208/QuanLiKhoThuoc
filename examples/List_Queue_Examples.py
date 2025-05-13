from datetime import datetime, timedelta
from typing import Optional
import os

# ANSI Color codes
class Colors:
    GREEN = '\033[32m'
    YELLOW = '\033[33m'
    RED = '\033[31m'
    BLUE = '\033[34m'
    CYAN = '\033[36m'
    MAGENTA = '\033[35m'
    RESET = '\033[0m'
    BOLD = '\033[1m'

# Box drawing characters
class BoxChars:
    TL = "┌"  # Top-left corner
    TR = "┐"  # Top-right corner
    BL = "└"  # Bottom-left corner
    BR = "┘"  # Bottom-right corner
    H = "─"   # Horizontal line
    V = "│"   # Vertical line

class Medicine:
    def __init__(self, name: str, code: str, type: str, quantity: int, price: float, expiry_date: datetime):
        self.name = name
        self.code = code
        self.type = type
        self.quantity = quantity
        self.price = price
        self.expiry_date = expiry_date

    def __str__(self):
        return f"{self.name} ({self.code}) - SL: {self.quantity}"

    def display_details(self):
        print(f"\n{Colors.BLUE}{Colors.BOLD}{BoxChars.TL}{BoxChars.H * 40}{BoxChars.TR}")
        print(f"{BoxChars.V}  THONG TIN THUOC  {BoxChars.V}")
        print(f"{BoxChars.BL}{BoxChars.H * 40}{BoxChars.BR}{Colors.RESET}\n")
        
        print(f"{Colors.BOLD}Ten:{Colors.RESET} {Colors.GREEN}{self.name}{Colors.RESET}")
        print(f"{Colors.BOLD}Ma:{Colors.RESET} {Colors.CYAN}{self.code}{Colors.RESET}")
        print(f"{Colors.BOLD}Loai:{Colors.RESET} {Colors.YELLOW}{self.type}{Colors.RESET}")
        print(f"{Colors.BOLD}So luong:{Colors.RESET} {Colors.MAGENTA}{self.quantity}{Colors.RESET}")
        print(f"{Colors.BOLD}Gia:{Colors.RESET} {Colors.RED}{self.price:,.0f} VND{Colors.RESET}")
        print(f"{Colors.BOLD}Han su dung:{Colors.RESET} {Colors.BLUE}{self.expiry_date.strftime('%d/%m/%Y')}{Colors.RESET}")

class Node:
    def __init__(self, data: Medicine):
        self.data = data
        self.next = None

class MedicineQueue:
    def __init__(self):
        self.front = None
        self.rear = None
        self.size = 0

    def enqueue(self, medicine: Medicine) -> None:
        new_node = Node(medicine)
        if self.rear is None:
            self.front = self.rear = new_node
        else:
            self.rear.next = new_node
            self.rear = new_node
        self.size += 1

    def dequeue(self) -> Optional[Medicine]:
        if self.is_empty():
            return None
        temp = self.front
        self.front = temp.next
        if self.front is None:
            self.rear = None
        self.size -= 1
        return temp.data

    def peek(self) -> Optional[Medicine]:
        return None if self.is_empty() else self.front.data

    def is_empty(self) -> bool:
        return self.front is None

    def search(self, name: str) -> Optional[Medicine]:
        current = self.front
        while current:
            if current.data.name.lower() == name.lower():
                return current.data
            current = current.next
        return None

    def display(self) -> None:
        if self.is_empty():
            print(f"{Colors.RED}{Colors.BOLD}⚠ Kho thuoc trong!{Colors.RESET}")
            return
        
        print(f"\n{Colors.BLUE}{Colors.BOLD}{BoxChars.TL}{BoxChars.H * 40}{BoxChars.TR}")
        print(f"{BoxChars.V}  DANH SACH THUOC  {BoxChars.V}")
        print(f"{BoxChars.BL}{BoxChars.H * 40}{BoxChars.BR}{Colors.RESET}\n")
        
        current = self.front
        while current:
            med = current.data
            print(f"{Colors.GREEN}✨ {med.name}{Colors.RESET}")
            print(f"   {Colors.BOLD}Ma:{Colors.RESET} {Colors.CYAN}{med.code}{Colors.RESET}")
            print(f"   {Colors.BOLD}Loai:{Colors.RESET} {Colors.YELLOW}{med.type}{Colors.RESET}")
            print(f"   {Colors.BOLD}So luong:{Colors.RESET} {Colors.MAGENTA}{med.quantity}{Colors.RESET}")
            print(f"   {Colors.BOLD}Gia:{Colors.RESET} {Colors.RED}{med.price:,.0f} VND{Colors.RESET}")
            print(f"   {Colors.BOLD}HSD:{Colors.RESET} {Colors.BLUE}{med.expiry_date.strftime('%d/%m/%Y')}{Colors.RESET}")
            print(f"   {BoxChars.H * 30}")
            current = current.next

def main():
    # Enable ANSI colors in Windows terminal
    if os.name == 'nt':
        os.system('color')

    # Tao queue mau
    queue = MedicineQueue()

    # Them mot so thuoc mau
    medicines = [
        Medicine("Paracetamol", "PCM001", "Giam dau", 100, 5000, 
                datetime.now() + timedelta(days=365)),
        Medicine("Amoxicillin", "AMX002", "Khang sinh", 50, 15000,
                datetime.now() + timedelta(days=180)),
        Medicine("Omeprazole", "OMP003", "Da day", 75, 8000,
                datetime.now() + timedelta(days=730))
    ]

    # Test cac thao tac
    print(f"\n{Colors.BLUE}{Colors.BOLD}=== THEM THUOC ==={Colors.RESET}")
    for med in medicines:
        queue.enqueue(med)
        print(f"{Colors.GREEN}✓ Da them:{Colors.RESET} {med.name}")

    print(f"\n{Colors.BLUE}{Colors.BOLD}=== HIEN THI KHO ==={Colors.RESET}")
    queue.display()

    print(f"\n{Colors.BLUE}{Colors.BOLD}=== TIM KIEM THUOC ==={Colors.RESET}")
    found = queue.search("Paracetamol")
    if found:
        print(f"{Colors.YELLOW}→ Tim thay thuoc:{Colors.RESET}")
        found.display_details()
    else:
        print(f"{Colors.RED}⚠ Khong tim thay thuoc!{Colors.RESET}")

    print(f"\n{Colors.BLUE}{Colors.BOLD}=== XUAT THUOC (FIFO) ==={Colors.RESET}")
    med = queue.dequeue()
    if med:
        print(f"{Colors.YELLOW}→ Da xuat thuoc:{Colors.RESET}")
        med.display_details()
    else:
        print(f"{Colors.RED}⚠ Kho trong!{Colors.RESET}")

    print(f"\n{Colors.BLUE}{Colors.BOLD}=== KHO SAU KHI XUAT ==={Colors.RESET}")
    queue.display()

if __name__ == "__main__":
    main()
