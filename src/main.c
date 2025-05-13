#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "queue.h"
#include "colors.h"

#define MAX_INPUT 100

// Helper function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Helper function to get date input
time_t getDateInput(const char* prompt) {
    int day, month, year;
    printf("%s (DD MM YYYY): ", prompt);
    scanf("%d %d %d", &day, &month, &year);
    clearInputBuffer();

    struct tm date = {0};
    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;
    date.tm_hour = 12;  // Set to noon to avoid timezone issues
    
    return mktime(&date);
}

// Function to input medicine details
Medicine inputMedicine() {
    Medicine med;    // Print header with box drawing
    printf("\n%s%s%s", BGREEN, BOLD, BOX_TL);
    for(int i = 0; i < 30; i++) printf("%s", BOX_H);
    printf("%s\n", BOX_TR);
    
    printf("%s  NHAP THONG TIN THUOC  %s\n", BOX_V, BOX_V);
    
    printf("%s", BOX_BL);
    for(int i = 0; i < 30; i++) printf("%s", BOX_H);
    printf("%s%s\n\n", BOX_BR, RESET);
    
    printf("%s%sTen thuoc:%s ", BWHITE, UNDER, RESET);
    fgets(med.name, sizeof(med.name), stdin);
    med.name[strcspn(med.name, "\n")] = 0;
    
    printf("%s%sMa thuoc:%s ", BCYAN, UNDER, RESET);
    fgets(med.code, sizeof(med.code), stdin);
    med.code[strcspn(med.code, "\n")] = 0;
      printf("%s%sLoai thuoc:%s ", BYELLOW, UNDER, RESET);
    fgets(med.type, sizeof(med.type), stdin);
    med.type[strcspn(med.type, "\n")] = 0;
    
    printf("%s%sSo luong:%s ", BMAGENTA, UNDER, RESET);
    scanf("%d", &med.quantity);
    clearInputBuffer();
    
    printf("%s%sGia (VND):%s ", BRED, UNDER, RESET);
    scanf("%f", &med.price);
    clearInputBuffer();
    
    printf("%s%sHan su dung%s ", BBLUE, UNDER, RESET);
    med.expiry_date = getDateInput("");
    
    return med;
}

// Function to print a medicine's details
void printMedicine(const Medicine* med) {
    if (med == NULL) {
        printf("Khong co du lieu thuoc!\n");
        return;
    }
      char date_str[26];
    ctime_s(date_str, sizeof(date_str), &med->expiry_date);
    date_str[24] = '\0';  // Remove newline
      // Print header with box drawing
    printf("\n%s%s%s", BBLUE, BOLD, BOX_TL);
    for(int i = 0; i < 40; i++) printf("%s", BOX_H);
    printf("%s\n", BOX_TR);
    
    printf("%s  %s%sTHONG TIN THUOC%s%s  %s\n", 
           BOX_V, BYELLOW, BOLD, RESET, BBLUE, BOX_V);
    
    printf("%s", BOX_BL);
    for(int i = 0; i < 40; i++) printf("%s", BOX_H);
    printf("%s%s\n\n", BOX_BR, RESET);
    
    // Print details with colors
    printf("%s%sTen:%s %s%s%s\n", BWHITE, BOLD, RESET, GREEN, med->name, RESET);
    printf("%s%sMa:%s %s%s%s\n", BWHITE, BOLD, RESET, CYAN, med->code, RESET);
    printf("%s%sLoai:%s %s%s%s\n", BWHITE, BOLD, RESET, YELLOW, med->type, RESET);
    printf("%s%sSo luong:%s %s%d%s\n", BWHITE, BOLD, RESET, MAGENTA, med->quantity, RESET);
    printf("%s%sGia:%s %s%.2f VND%s\n", BWHITE, BOLD, RESET, RED, med->price, RESET);
    printf("%s%sHan su dung:%s %s%s%s\n", BWHITE, BOLD, RESET, BLUE, date_str, RESET);
}

// Print menu and get user choice
int getMenuChoice() {
    // Print fancy header with double box
    printf("\n%s%s%s", BBLUE, BOLD, BOX_TL);
    for(int i = 0; i < 50; i++) printf("%s", BOX_H);
    printf("%s\n", BOX_TR);
      printf("%s  %s%s[ QUAN LY KHO THUOC - NHA THUOC LONG CHAU ]%s%s  %s\n", 
           BOX_V, BYELLOW, BOLD, RESET, BBLUE, BOX_V);
           
    printf("%s  %s%s[      GVHD : Nguyen Thi Thuy Trang       ]%s%s  %s\n",
           BOX_V, BCYAN, BOLD, RESET, BBLUE, BOX_V);
    
    printf("%s", BOX_BL);
    for(int i = 0; i < 50; i++) printf("%s", BOX_H);
    printf("%s%s\n", BOX_BR, RESET);    // Menu items with different colors and icons    printf("\n%s+------------------ CHUC NANG ------------------+%s\n", BBLUE, RESET);
    printf("%s[%s1%s] %s(*) Nhap thuoc moi%s\n", BWHITE, BYELLOW, BWHITE, GREEN, RESET);
    printf("%s[%s2%s] %s(-) Xuat thuoc%s\n", BWHITE, BYELLOW, BWHITE, RED, RESET);
    printf("%s[%s3%s] %s(>) Xem thuoc sap xuat%s\n", BWHITE, BYELLOW, BWHITE, YELLOW, RESET);
    printf("%s[%s4%s] %s(?) Tim kiem thuoc theo ten%s\n", BWHITE, BYELLOW, BWHITE, CYAN, RESET);
    printf("%s[%s5%s] %s(#) Tim kiem thuoc theo loai%s\n", BWHITE, BYELLOW, BWHITE, MAGENTA, RESET);
    printf("%s[%s6%s] %s(=) Hien thi kho thuoc%s\n", BWHITE, BYELLOW, BWHITE, BLUE, RESET);
    printf("%s[%s7%s] %s(!) Xoa thuoc het han%s\n", BWHITE, BYELLOW, BWHITE, RED, RESET);
    printf("%s[%s8%s] %s(@) Thong ke%s\n", BWHITE, BYELLOW, BWHITE, GREEN, RESET);
    printf("%s[%s0%s] %s(x) Thoat%s\n", BWHITE, BYELLOW, BWHITE, BRED, RESET);
    printf("%s+------------------------------------------------+%s\n", BBLUE, RESET);
      int choice;
    printf("\n%s%s> Chon chuc nang (0-8):%s ", BYELLOW, BOLD, RESET);
    scanf("%d", &choice);
    clearInputBuffer();
    
    return choice;
}

// Function to display statistics
void displayStats(MedicineQueue* q) {    if (isEmpty(q)) {
        printf("Kho trong, khong co thong ke!\n");
        return;
    }
    
    int total_items = 0;
    float total_value = 0;
    Node* current = q->front;
    
    while (current != NULL) {
        total_items += current->data.quantity;
        total_value += current->data.quantity * current->data.price;
        current = current->next;
    }    // Print statistics header
    printf("\n%s%s%s", BGREEN, BOLD, BOX_TL);
    for(int i = 0; i < 40; i++) printf("%s", BOX_H);
    printf("%s\n", BOX_TR);
    
    printf("%s  %s%sTHONG KE KHO THUOC%s%s  %s\n", 
           BOX_V, BYELLOW, BOLD, RESET, BGREEN, BOX_V);
    
    printf("%s", BOX_BL);
    for(int i = 0; i < 40; i++) printf("%s", BOX_H);
    printf("%s%s\n\n", BOX_BR, RESET);

    // Statistics with colors
    printf("%s%sSo luong mat hang:%s %s%d%s\n", 
           BWHITE, BOLD, RESET, CYAN, q->size, RESET);
    printf("%s%sTong so thuoc:%s %s%d%s\n", 
           BWHITE, BOLD, RESET, YELLOW, total_items, RESET);
    printf("%s%sTong gia tri:%s %s%.2f VND%s\n", 
           BWHITE, BOLD, RESET, GREEN, total_value, RESET);
}

int main() {
    MedicineQueue* queue = createQueue();
    int running = 1;
    
    while (running) {
        int choice = getMenuChoice();
        
        switch (choice) {
            case 1: {  // Nhập thuốc
                Medicine med = inputMedicine();
                enqueue(queue, med);                printf("%s%s✓ Da nhap thuoc thanh cong!%s\n", BGREEN, BOLD, RESET);
                break;
            }
            
            case 2: {  // Xuất thuốc
                Medicine* med = dequeue(queue);
                if (med != NULL) {                    printf("%s%s→ Da xuat thuoc:%s\n", BYELLOW, BOLD, RESET);
                    printMedicine(med);
                    free(med);
                } else {
                    printf("Kho trong!\n");
                }
                break;
            }
            
            case 3: {  // Xem thuốc sắp xuất
                Medicine* med = peek(queue);                if (med != NULL) {
                    printf("%s%s→ Thuoc sap duoc xuat:%s\n", BYELLOW, BOLD, RESET);
                    printMedicine(med);
                    free(med);
                } else {
                    printf("%s%s⚠ Kho trong!%s\n", BRED, BOLD, RESET);
                }
                break;
            }
            
            case 4: {  // Tìm theo tên
                char name[100];                printf("Nhap ten thuoc can tim: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                
                Medicine* med = searchByName(queue, name);                if (med != NULL) {
                    printf("%s%s→ Tim thay thuoc:%s\n", BGREEN, BOLD, RESET);
                    printMedicine(med);
                    free(med);
                } else {
                    printf("%s%s⚠ Khong tim thay thuoc '%s'!%s\n", 
                           BRED, BOLD, name, RESET);
                }
                break;
            }
            
            case 5: {  // Tìm theo loại
                char type[50];                printf("Nhap loai thuoc can tim: ");
                fgets(type, sizeof(type), stdin);
                type[strcspn(type, "\n")] = 0;
                
                Medicine* med = searchByType(queue, type);                if (med != NULL) {
                    printf("%s%s→ Tim thay thuoc:%s\n", BGREEN, BOLD, RESET);
                    printMedicine(med);
                    free(med);
                } else {
                    printf("%s%s⚠ Khong tim thay thuoc loai '%s'!%s\n", 
                           BRED, BOLD, type, RESET);
                }
                break;
            }
            
            case 6:  // Hiển thị kho
                displayQueue(queue);
                break;
            
            case 7: {  // Xóa thuốc hết hạn
                int count = removeExpiredMedicines(queue);
                printf("%s%s✓ Da xoa %d thuoc het han!%s\n", BGREEN, BOLD, count, RESET);
                break;
            }
            
            case 8:  // Thống kê
                displayStats(queue);
                break;
            
            case 0:  // Thoát
                running = 0;
                break;
            
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    }
    
    // Cleanup
    freeQueue(queue);
    printf("\n%s%s✓ Chuong trinh ket thuc.%s\n", BGREEN, BOLD, RESET);
    return 0;
}
