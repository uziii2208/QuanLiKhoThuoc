#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../src/queue.h"
#include "../src/colors.h"  // Add colors header

// Utility function to generate random string
void random_string(char *str, size_t size) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (size_t i = 0; i < size-1; i++) {
        int key = rand() % (sizeof(charset) - 1);
        str[i] = charset[key];
    }
    str[size-1] = '\0';
}

// Generate random medicine for testing
Medicine generate_random_medicine() {
    Medicine med;
    
    // Generate random name (10 chars)
    random_string(med.name, 10);
    
    // Generate random code (6 chars)
    random_string(med.code, 6);
    
    // Generate random type from predefined types
    const char* types[] = {"Pain Relief", "Antibiotic", "Antacid", "Vitamin", "Antihistamine"};
    strcpy(med.type, types[rand() % 5]);
    
    // Random quantity between 1 and 1000
    med.quantity = rand() % 1000 + 1;
    
    // Random price between 1000 and 100000
    med.price = (float)(rand() % 99000 + 1000);
    
    // Random expiry date between now and 2 years
    med.expiry_date = time(NULL) + (rand() % (730 * 24 * 60 * 60));
    
    return med;
}

void test_performance() {
    MedicineQueue* queue = createQueue();
    clock_t start, end;
    double cpu_time_used;
    int i;
    
    // Print header
    printf("\n%s%s%s", BBLUE, BOLD, BOX_TL);
    for(int i = 0; i < 40; i++) printf("%s", BOX_H);
    printf("%s\n", BOX_TR);
    
    printf("%s  %s%sKIEM TRA HIEU NANG%s%s  %s\n", 
           BOX_V, BYELLOW, BOLD, RESET, BBLUE, BOX_V);
    
    printf("%s", BOX_BL);
    for(int i = 0; i < 40; i++) printf("%s", BOX_H);
    printf("%s%s\n\n", BOX_BR, RESET);
    
    // Test 1: Enqueue 100,000 items
    printf("%s%sTest 1:%s Them 100,000 thuoc...\n", BWHITE, BOLD, RESET);
    start = clock();
    for (i = 0; i < 100000; i++) {
        Medicine med = generate_random_medicine();
        enqueue(queue, med);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%s%sThoi gian thuc hien:%s %.2f giay\n", BCYAN, BOLD, RESET, cpu_time_used);
    printf("%s%sSo luong trong kho:%s %d\n\n", BGREEN, BOLD, RESET, queue->size);
    
    // Test 2: Search operations
    printf("%s%sTest 2:%s Thuc hien 1000 tim kiem ngau nhien...\n", BWHITE, BOLD, RESET);
    start = clock();
    for (i = 0; i < 1000; i++) {
        char random_type[20];
        random_string(random_type, 10);
        searchByType(queue, random_type);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%s%sThoi gian thuc hien:%s %.2f giay\n\n", BCYAN, BOLD, RESET, cpu_time_used);
    
    // Test 3: Dequeue 50,000 items
    printf("%s%sTest 3:%s Xuat 50,000 thuoc...\n", BWHITE, BOLD, RESET);
    start = clock();
    for (i = 0; i < 50000; i++) {
        Medicine* med = dequeue(queue);
        if (med != NULL) {
            free(med);
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%s%sThoi gian thuc hien:%s %.2f giay\n", BCYAN, BOLD, RESET, cpu_time_used);
    printf("%s%sSo luong con lai trong kho:%s %d\n\n", BGREEN, BOLD, RESET, queue->size);
    
    // Test 4: Memory usage check
    printf("%s%sTest 4:%s Kiem tra quan ly bo nho...\n", BWHITE, BOLD, RESET);
    size_t initial_size = queue->size;
    start = clock();
    freeQueue(queue);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%s%sThoi gian giai phong%s %zu %s%sphan tu:%s %.2f giay\n", 
           BCYAN, BOLD, RESET, initial_size, BCYAN, BOLD, RESET, cpu_time_used);
}

int main() {
    // Set random seed
    srand(time(NULL));
    
    // Run performance tests
    test_performance();
    
    return 0;
}
