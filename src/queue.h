#ifndef QUEUE_H
#define QUEUE_H

#include <time.h>

typedef struct {
    char name[100];
    char code[20];
    char type[50];
    int quantity;
    float price;
    time_t expiry_date;
} Medicine;

typedef struct Node {
    Medicine data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} MedicineQueue;

// Khởi tạo queue
MedicineQueue* createQueue();

// Thêm thuốc vào queue
void enqueue(MedicineQueue* q, Medicine medicine);

// Lấy thuốc ra khỏi queue
Medicine* dequeue(MedicineQueue* q);

// Xem thuốc sắp được xuất
Medicine* peek(MedicineQueue* q);

// Kiểm tra queue rỗng
int isEmpty(MedicineQueue* q);

// Tìm kiếm thuốc theo tên
Medicine* searchByName(MedicineQueue* q, const char* name);

// Tìm kiếm thuốc theo loại
Medicine* searchByType(MedicineQueue* q, const char* type);

// Hiển thị toàn bộ kho
void displayQueue(MedicineQueue* q);

// Xóa thuốc hết hạn
int removeExpiredMedicines(MedicineQueue* q);

// Giải phóng bộ nhớ
void freeQueue(MedicineQueue* q);

#endif // QUEUE_H
