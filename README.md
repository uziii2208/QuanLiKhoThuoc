# Quan Ly Kho Thuoc (Queue voi DSLK don)

Chuong trinh quan ly kho thuoc su dung cau truc du lieu hang doi (Queue) duoc cai dat bang danh sach lien ket don trong C. Giao dien duoc cai thien voi mau sac va ky tu ASCII box-drawing.

## Tinh nang

- ✨ Nhap thuoc moi (enqueue)
- 📦 Xuat thuoc (dequeue)
- 👀 Xem thuoc sap xuat (peek)
- 🔍 Tim kiem thuoc (theo ten/loai)
- 📊 Hien thi kho
- ⚠️ Quan ly thuoc het han
- 📈 Thong ke kho

## Giao dien

- 🎨 Giao dien mau sac dep mat
- 📦 Box-drawing characters cho khung
- ✨ Bieu tuong trang thai (✓, →, ⚠)
- 🎯 Phan biet trang thai bang mau sac

## Cau truc du an

```plaintext
/QuanLyKhoThuoc
│
├── /doc                 # Tai lieu
│   └── List_Queue_TongQuan.md
│
├── /examples           # Vi du minh hoa
│   └── List_Queue_Examples.py
│
├── /src               # Ma nguon
│   ├── main.c         # Chuong trinh chinh
│   ├── queue.h        # Header file
│   ├── queue.c        # Cai dat Queue
│   └── colors.h       # Dinh nghia mau va khung
│
├── /test              # Kiem thu
│   └── performance_test.c
│
├── README.md
└── Makefile
```

## Yeu cau he thong

- Trinh bien dich C (GCC hoac tuong duong)
- Make (de build)
- Python 3.x (cho vi du minh hoa - tuy chon)

## Cai dat va Chay

1. Clone repository:

   ```bash
   git clone https://github.com/uziii2208/QuanLiKhoThuoc.git
   cd QuanLyKhoThuoc
   ```

2. Bien dich:

   ```bash
   make
   ```

3. Chay chuong trinh:

   ```bash
   make run
   ```

4. Chay test hieu nang:

   ```bash
   make test
   ```

## Cau truc du lieu

### Node (Nut)

```c
struct Node {
    Medicine data;      // Du lieu thuoc
    struct Node* next;  // Con tro den node tiep theo
};
```

### Queue (Hang doi)

```c
typedef struct {
    Node* front;   // Con tro den dau hang doi
    Node* rear;    // Con tro den cuoi hang doi
    int size;      // So luong phan tu
} MedicineQueue;
```

### Medicine (Thuoc)

```c
typedef struct {
    char name[100];     // Ten thuoc
    char code[20];      // Ma thuoc
    char type[50];      // Loai thuoc
    int quantity;       // So luong
    float price;        // Gia
    time_t expiry_date; // Han su dung
} Medicine;
```

## Cac thao tac chinh

| Thao tac | Do phuc tap | Mo ta |
|----------|-------------|-------|
| enqueue  | O(1)        | Them thuoc vao cuoi hang doi |
| dequeue  | O(1)        | Lay thuoc tu dau hang doi |
| peek     | O(1)        | Xem thuoc o dau hang doi |
| search   | O(n)        | Tim kiem thuoc theo ten/loai |

## Hieu nang

- Quan ly duoc 100,000+ thuoc
- Toi uu bo nho voi cap phat dong
- Giai phong bo nho tu dong khi xuat thuoc
- Test hieu nang chi tiet trong `test/performance_test.c`

## Giao dien nguoi dung

### Mau sac

```c
// Color definitions
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
```

### Box-drawing

```c
#define BOX_TL "+"  // Top-left corner
#define BOX_TR "+"  // Top-right corner
#define BOX_BL "+"  // Bottom-left corner
#define BOX_BR "+"  // Bottom-right corner
#define BOX_H  "-"  // Horizontal line
#define BOX_V  "|"  // Vertical line
```

### Bieu tuong trang thai

- ✓ Thanh cong (mau xanh la)
- → Thong tin (mau vang)
- ⚠ Canh bao/Loi (mau do)

## Dong gop

Moi dong gop deu duoc hoan nghenh! Vui long:

1. Fork du an
2. Tao branch moi (`git checkout -b feature/AmazingFeature`)
3. Commit thay doi (`git commit -m 'Add some AmazingFeature'`)
4. Push to branch (`git push origin feature/AmazingFeature`)
5. Tao Pull Request

## License

MIT