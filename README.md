# Compiler
Compiler giống như 1 phần mềm dùng để chuyển ngôn ngữ bậc cao sang ngôn ngữ máy, đối với một ngôn ngữ lập trình (c/c++, python, java,...) thì có nhiều compiler.
![image](https://github.com/Kiet2024/Embedded_interview/assets/133784431/21423361-d502-41ca-9a00-9ac64500703c)


Để tạo file *.i từ file *.c thì gõ "gcc -E *.c -o *.i".( *.c là tên file .c)

Quá trình `tiền xử lý (Preprocessor)` xảy ra nó sẽ thay thế những đoạn chương trình Macro định nghĩa vào những đoạn chương trình đang gọi Macro, những phần command sẽ được bỏ qua.

Để tạo file `Assembly` code thì gõ "gcc *.i -S -o *.s".

Quá trình `linker` sẽ sắp xếp các object files + libraries vào file *.exe .

Bản chất file *.exe giống như file zip hay rar.
# Các toán tử logic
 ## Toán tử AND
 <img width="173" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/131b91c7-7404-42a1-89d4-00713f196a51">

 ## Toán tử OR
 <img width="173" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/e2779fd1-8884-4ab2-b2e9-fdaa875e1139">
 
 ## Toán tử NOT
 <img width="85" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/0d2bc1fd-1d6e-4067-8745-37b6efbd4714">

 ## Toán tử XOR
 <img width="175" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/28c77307-f094-4afa-b52e-925be353be09">
 
# Thao tác Bit
<img width="355" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/02e222c1-e668-4939-a6ea-dd05e7eb746e">

Dịch trái (<<) 4 bit là bỏ đi 4 bit bên trái(ở đầu) và thêm 4 bit 0 vào bên phải(ở cuối)

<img width="357" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/085599a0-6a96-4d58-b47a-507eb1705ee4">

Dịch phải(>>) 1 bit là bỏ đi 1 bit bên phải(ở cuối) và thêm 1 bit 0 vào bên trái(ở đầu)
# Typedef
Typedef được sử dụng để tạo tên mới cho kiểu dữ liệu. 
```
typedef uint8_t u8;
u8 x = 10; // u8 bản chất nó là kiểu uint8_t
 ```
 # Tính size của Struct
Số byte cần quét trong 1 lần sẽ dựa trên byte lớn nhất trong struct

### Ví dụ 1:
```
struct typeDate
{
  // Số byte cần quét trong 1 lần = 8 byte
    uint8_t arr1[10]; // 1 byte
    uint16_t arr2[7]; // 2 byte
    uint64_t arr3[5]; // 8 byte
    uint32_t arr4[1]; // 4 byte
};
```
Cách tính số size :

uint8_t có size 1 byte => arr1[10] cần 1*10 = 10 byte để lưu, mà 1 lần quét là 8 byte (byte cao nhất trong struct) 

=> arr1[10] = 10 byte + **6 byte dư** = 10 byte (cần 2 lần quét)

uint16_t có size 2 byte => arr2[7] cần 2*7 = 14 byte để lưu, mà ở trên còn dư 6 byte, nên lúc này cần 1 lần quét là đủ 

=> arr2[7] = **6 byte (byte dư ở arr1)** + 8 byte = 14 byte.

uint64_t có size 8 byte => arr3[5] cần 8*5 = 40 byte để lưu 

=> arr3[5] = 40byte ( 5 lần quét).

uint32_t có size 4 byte => arr3[1] cần 4*1 = 4 byte để lưu, nên chỉ cần 1 lần quét

=>  arr3[1] = 4 byte + 4 byte dư = 8 byte

==> tổng size = 10 byte + 14 byte + 40 byte + 8 byte = 72 byte

### Ví dụ 2:
```
struct typeDate
{
  // Số byte cần quét trong 1 lần = 4 byte
    uint8_t arr1[11]; // 1 byte
    uint32_t arr2[4]; // 4 byte
    uint16_t arr3[7]; // 2 byte
};
```
Cách tính số size

uint8_t có size 1 byte => arr1[11] cần 1*11 = 11 byte để lưu, mà 1 lần quét là 4 byte (byte cao nhất trong struct) 

=> arr1[11] = 11 byte + **1 byte dư** = 12 byte (cần 3 lần quét)

uint32_t có size 4 byte => arr2[4] cần 4*4 = 16 byte để lưu 

=>  arr2[4] = 16 byte  (cần 4 lần quét)

uint16_t có size 2 byte => arr3[7] cần 2*7 = 14 byte để lưu

=> arr2[7] = 14 byte + 2 byte dư = 16 byte (cần 4 lần quét)

==> tổng size = 12 byte + 16 byte + 16 byte = 44 byte

