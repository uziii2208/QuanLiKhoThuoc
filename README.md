
# Quản Lý Kho Thuốc (Queue với Danh Sách Liên Kết Đơn)

Chương trình quản lý kho thuốc sử dụng cấu trúc dữ liệu hàng đợi (Queue) được cài đặt bằng danh sách liên kết đơn trong C. Giao diện được cải thiện với màu sắc và ký tự khung ASCII.

## Tính năng

- ✨ Nhập thuốc mới (enqueue)
- 📦 Xuất thuốc (dequeue)
- 👀 Xem thuốc sắp xuất (peek)
- 🔍 Tìm kiếm thuốc (theo tên/loại)
- 📊 Hiển thị kho
- ⚠️ Quản lý thuốc hết hạn
- 📈 Thống kê kho

## Giao diện

- 🎨 Giao diện màu sắc đẹp mắt
- 📦 Ký tự khung ASCII cho bảng hiển thị
- ✨ Biểu tượng trạng thái (✓, →, ⚠)
- 🎯 Phân biệt trạng thái bằng màu sắc

## Cấu trúc dự án

```plaintext
/QuanLyKhoThuoc
│
├── /doc                 # Tài liệu
│   └── List_Queue_TongQuan.md
│
├── /examples            # Ví dụ minh họa
│   └── List_Queue_Examples.py
│
├── /src                 # Mã nguồn
│   ├── main.c           # Chương trình chính
│   ├── queue.h          # Header file
│   ├── queue.c          # Cài đặt Queue
│   └── colors.h         # Định nghĩa màu và khung
│
├── /test                # Kiểm thử
│   └── performance_test.c
│
├── README.md
└── Makefile
```

## Yêu cầu hệ thống

- Trình biên dịch C (GCC hoặc tương đương)
- Make (để build)
- Python 3.x (cho ví dụ minh họa - tùy chọn)

## Cài đặt và chạy

1. Clone repository:

   ```bash
   git clone https://github.com/uziii2208/QuanLiKhoThuoc.git
   cd QuanLyKhoThuoc
   ```

2. Biên dịch:

   ```bash
   make
   ```

3. Chạy chương trình:

   ```bash
   make run
   ```

4. Chạy kiểm thử hiệu năng:

   ```bash
   make test
   ```

## Cấu trúc dữ liệu

### Node (Nút)

```c
struct Node {
    Medicine data;      // Dữ liệu thuốc
    struct Node* next;  // Con trỏ đến node tiếp theo
};
```

### Queue (Hàng đợi)

```c
typedef struct {
    Node* front;   // Con trỏ đến đầu hàng đợi
    Node* rear;    // Con trỏ đến cuối hàng đợi
    int size;      // Số lượng phần tử
} MedicineQueue;
```

### Medicine (Thuốc)

```c
typedef struct {
    char name[100];     // Tên thuốc
    char code[20];      // Mã thuốc
    char type[50];      // Loại thuốc
    int quantity;       // Số lượng
    float price;        // Giá
    time_t expiry_date; // Hạn sử dụng
} Medicine;
```

## Các thao tác chính

| Thao tác | Độ phức tạp | Mô tả |
|----------|-------------|-------|
| enqueue  | O(1)        | Thêm thuốc vào cuối hàng đợi |
| dequeue  | O(1)        | Lấy thuốc từ đầu hàng đợi |
| peek     | O(1)        | Xem thuốc ở đầu hàng đợi |
| search   | O(n)        | Tìm kiếm thuốc theo tên/loại |

## Hiệu năng

- Quản lý được 100,000+ thuốc
- Tối ưu bộ nhớ với cấp phát động
- Giải phóng bộ nhớ tự động khi xuất thuốc
- Kiểm thử hiệu năng chi tiết trong `test/performance_test.c`

## Giao diện người dùng

### Màu sắc

```c
// Định nghĩa màu sắc
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
```

### Khung hiển thị (Box-drawing)

```c
#define BOX_TL "+"  // Góc trên bên trái
#define BOX_TR "+"  // Góc trên bên phải
#define BOX_BL "+"  // Góc dưới bên trái
#define BOX_BR "+"  // Góc dưới bên phải
#define BOX_H  "-"  // Đường ngang
#define BOX_V  "|"  // Đường dọc
```

### Biểu tượng trạng thái

- ✓ Thành công (màu xanh lá)
- → Thông tin (màu vàng)
- ⚠ Cảnh báo/Lỗi (màu đỏ)

## Đóng góp

Mọi đóng góp đều được hoan nghênh! Vui lòng:

1. Fork dự án
2. Tạo branch mới (`git checkout -b feature/TinhNangMoi`)
3. Commit thay đổi (`git commit -m 'Thêm tính năng mới'`)
4. Push lên branch (`git push origin feature/TinhNangMoi`)
5. Tạo Pull Request

## Giấy phép

Non-license
