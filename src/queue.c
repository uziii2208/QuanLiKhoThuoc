#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "colors.h"

MedicineQueue* createQueue() {    MedicineQueue* q = (MedicineQueue*)malloc(sizeof(MedicineQueue));
    if (q == NULL) {
        fprintf(stderr, "Loi cap phat bo nho cho Queue\n");
        exit(1);
    }
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(MedicineQueue* q, Medicine medicine) {    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Loi cap phat bo nho cho Node moi\n");
        return;
    }
    
    newNode->data = medicine;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

Medicine* dequeue(MedicineQueue* q) {
    if (isEmpty(q)) {
        return NULL;
    }
      Node* temp = q->front;
    Medicine* medicine = (Medicine*)malloc(sizeof(Medicine));
    if (medicine == NULL) {
        fprintf(stderr, "Loi cap phat bo nho cho Medicine\n");
        return NULL;
    }
    
    *medicine = temp->data;
    q->front = temp->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    q->size--;
    return medicine;
}

Medicine* peek(MedicineQueue* q) {
    if (isEmpty(q)) {
        return NULL;
    }
    Medicine* medicine = (Medicine*)malloc(sizeof(Medicine));
    if (medicine == NULL) {
        fprintf(stderr, "Loi cap phat bo nho cho Medicine\n");
        return NULL;
    }
    *medicine = q->front->data;
    return medicine;
}

int isEmpty(MedicineQueue* q) {
    return q->front == NULL;
}

Medicine* searchByName(MedicineQueue* q, const char* name) {    Node* current = q->front;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            Medicine* medicine = (Medicine*)malloc(sizeof(Medicine));
            if (medicine == NULL) {
                fprintf(stderr, "Loi cap phat bo nho cho Medicine\n");
                return NULL;
            }
            *medicine = current->data;
            return medicine;
        }
        current = current->next;
    }
    return NULL;
}

Medicine* searchByType(MedicineQueue* q, const char* type) {
    Node* current = q->front;    while (current != NULL) {
        if (strcmp(current->data.type, type) == 0) {
            Medicine* medicine = (Medicine*)malloc(sizeof(Medicine));
            if (medicine == NULL) {
                fprintf(stderr, "Loi cap phat bo nho cho Medicine\n");
                return NULL;
            }
            *medicine = current->data;
            return medicine;
        }
        current = current->next;
    }
    return NULL;
}

void displayQueue(MedicineQueue* q) {
    if (isEmpty(q)) {
        printf("%s%s=== KHO THUOC TRONG ===%s\n", BRED, BOLD, RESET);
        return;
    }
    
    Node* current = q->front;
    // Print top border
    printf("\n%s%s", BBLUE, BOLD);
    printf("%s", BOX_TL);
    for(int i = 0; i < 80; i++) printf("%s", BOX_H);
    printf("%s\n", BOX_TR);
    
    // Print title
    printf("%s  %s=== DANH SACH THUOC TRONG KHO ===%s\n", BOX_V, BYELLOW, BBLUE);
    
    // Print header
    printf("%s  ", BOX_V);
    printf("%-20s %-10s %-15s %-10s %-15s %s%s\n", 
           "Ten", "Ma", "Loai", "So luong", "Gia (VND)", "Han su dung", RESET);
    
    // Print separator
    printf("%s%s%s", BBLUE, BOLD, BOX_V);
    for(int i = 0; i < 80; i++) printf("%s", BOX_H);
    printf("%s\n", BOX_V);
    
    while (current != NULL) {        char expiry_date_str[26];
        ctime_s(expiry_date_str, sizeof(expiry_date_str), &current->data.expiry_date);
        expiry_date_str[24] = '\0';  // Remove newline
          printf("%s%s%s  ", BBLUE, BOLD, BOX_V);
        // Print data in different colors
        printf("%s%-20s %s%-10s %s%-15s %s%-10d %s%-15.2f %s%s%s\n",
               GREEN, current->data.name,
               CYAN, current->data.code,
               YELLOW, current->data.type,
               MAGENTA, current->data.quantity,
               RED, current->data.price,
               WHITE, expiry_date_str,
               RESET);
        current = current->next;
    }
    
    // Print bottom border
    printf("%s%s%s", BBLUE, BOLD, BOX_BL);
    for(int i = 0; i < 80; i++) printf("%s", BOX_H);
    printf("%s%s\n", BOX_BR, RESET);
}

int removeExpiredMedicines(MedicineQueue* q) {
    if (isEmpty(q)) {
        return 0;
    }
    
    time_t now = time(NULL);
    int removed = 0;
    
    while (q->front != NULL && q->front->data.expiry_date < now) {
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
        removed++;
        q->size--;
    }
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    Node* current = q->front;
    while (current != NULL && current->next != NULL) {
        if (current->next->data.expiry_date < now) {
            Node* temp = current->next;
            current->next = temp->next;
            if (temp == q->rear) {
                q->rear = current;
            }
            free(temp);
            removed++;
            q->size--;
        } else {
            current = current->next;
        }
    }
    
    return removed;
}

void freeQueue(MedicineQueue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}
