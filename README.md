<details>

<summary>COMPILER</summary>
Compiler giống như 1 phần mềm dùng để chuyển ngôn ngữ bậc cao sang ngôn ngữ máy, đối với một ngôn ngữ lập trình (c/c++, python, java,...) thì có nhiều compiler.
    
![image](https://github.com/Kiet2024/Embedded_interview/assets/133784431/21423361-d502-41ca-9a00-9ac64500703c)

Để tạo file *.i từ file *.c thì gõ "gcc -E *.c -o *.i".( *.c là tên file .c)

Quá trình `tiền xử lý (Preprocessor)` xảy ra nó sẽ thay thế những đoạn chương trình Macro định nghĩa vào những đoạn chương trình đang gọi Macro, những phần command sẽ được bỏ qua.

Để tạo file `Assembly` code thì gõ "gcc *.i -S -o *.s".

Quá trình `linker` sẽ sắp xếp các object files + libraries vào file *.exe .

Bản chất file *.exe giống như file zip hay rar.
    
</details>

<details>
<summary>PHÂN VÙNG NHỚ</summary>
<img width="169" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/7b238944-eb43-4d35-a0dd-2e94ad70a421">

## Phân vùng Text:
- Quyền truy cập chỉ Read và nó chứa lệnh để thực thi nên tránh sửa đổi instruction.

- Chứa khai báo hằng số trong chương trình (.rodata)
```
// Ví dụ : chỉ đọc data
const int a = 9;
char *arr = "Hello";
```
## Phân vùng Data:
- Quyền truy cập là read-write.

- Chứa biến toàn cục or biến static với giá trị khởi tạo khác không.

- Được giải phóng khi kết thúc chương trình.
```
#include <stdio.h>

int x = 10; // biến toàn cục
static int a = 15; // biến static toàn cục

void test(){
 static int b = 10; // biến static cục bộ
 a = a + 20;
 prinf("test: %d\n", a);
}
int main (){

 test();
 a = a +15;
 prinf("main: %d\n", a);
 return 0;
 // Result: test = 35, main = 50
```
## Phân vùng BSS:
- Quyền truy cập là read-write.

- Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.

- Được giải phóng khi kết thúc chương trình.
```
static int a ; // biến static toàn cục phân vùng bss
/* khi giá trị được khởi tạo vd: a = 10 thì nó vẫn ở phân vùng bss */ 
void test(){
 static int b ; // biến static cục bộ
}
int main (){
}
```
## Phân vùng Stack:
- Quyền truy cập là read-write.

- Được sử dụng cấp phát cho biến local, input parameter của hàm,…

- Sẽ được giải phóng khi ra khỏi block code/hàm.
```
// int a, int b là input parameter
int sum(int a, int b){
  int c; // biến cục bộ ở phân vùng stack
  c = a + b;
  return c;
}
```
## Phân vùng Heap:
- Quyền truy cập là read-write.

- Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc,…

- Sẽ được giải phóng khi gọi hàm free,…
```
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void test1(){
  char arr[3]; // biến toàn cục
  printf("Dia chi arr: %p\n", arr);
}

void test2(){
/*
 Khi khai báo kiểu malloc, các ô nhớ sẽ được giữ nguyên bộ nhớ ban đầu (draf data hay dữ liệu rác).
 Kiểu trả về là con trỏ void (không có giá trị), tham số truyền vào là  size tính bằng byte.
 Vì hàm malloc trả về dạng void, vậy ta cần ép kiểu cho nó trở về đúng kiểu con trỏ mà ta sử dụng.
 Vì char có 1 byte nên khai báo sẽ được cấp 3 byte tương ứng 3 phần tử.
*/
  char *arr = (char*)malloc(sizeof(char)*3);
  // arr = (char*)realloc(arr,(sizeof(char)*5) // thay đổi kích thước mảng 5 byte tương ứng 5 phần tử
  printf("Dia chi arr: %p\n", arr);
  free(arr);
}

int main(){
  test1();
  test1();
  test2();
  test2();
}
/*
Result: khi chưa sử dụng lệnh free cho hàm malloc
Dia chi arr: 0061FF0D : khi gọi test1 lần 1 sau khởi tạo xong nó sẽ thoát ra và thu hồi vùng nhớ 
Dia chi arr: 0061FF0D : khi gọi test1 lần 2 nó khởi tạo địa chỉ trước đó vì địa chỉ đó vẫn còn trống.
Dia chi arr: 00BA2F20 : do malloc được lưu ở phân vùng Heap nên nó không thể tự thu hồi 
Dia chi arr: 00BA2F30

Result: khi sử dụng lệnh free cho hàm malloc
Dia chi arr: 0061FF0D
Dia chi arr: 0061FF0D
Dia chi arr: 00AD2F20
Dia chi arr: 00AD2F20
*/
```
    
</details>
    
 <details>
 <summary>MACRO - FUNCTION - INLINE</summary>
     
 ## Macro 
 - Macro không phải là hàm, cũng không phải là biến mà nó chỉ là 1 định nghĩa.
 - Macro được diễn ra ở quá trình tiền xử lý (preprocessor).
 - Thay thế định nghĩa macro vào đoạn code đã gọi.
     
 **VD1:**
 ```
 #define MAX 10
 Preprocessor khi gặp bất kỳ lời gọi MAX nào thì thay ngay bằng 10.
     
 #define SUM(a,b) a + b //SUM(a,b) gọi là định nghĩa
 Preprocessor khi gặp bất kỳ lời gọi SUM(first,last) nào thì thay ngay bằng (first+last).
 
 ```
     
 **VD2:**
 ```
  '\' trong Macro dùng để liên kết nội dung dòng bên dưới 
  #define CREATE_FUNC(ten_ham, noi_dung)    \
  void ten_ham(){                           \
     printf("%s\n",noi_dung);               \
  }
  CREATE_FUNC(test,"this is test\n"); // tạo ra hàm test
   /*
   void test(){                           
     printf("%s\n","this is test\n");       
  }
   */
  CREATE_FUNC(test2,"this is test2\n"); // tạo ra thêm hàm test2
  
 ```
 ## Function
- Khi thấy hàm được gọi, compiler sẽ phải lưu con trỏ chương trình Program Couter (PC) hiện tại vào Stack Pointer; chuyển Program Counter tới hàm được gọi, thực hiện hàm đó xong và lấy kết quả trả về; sau đó quay lại vị trí ban đầu trong stack trước khi gọi hàm và tiếp tục thực hiện chương trình.
- Như có thể thấy, các này khiến chương trình tốn thời gian hơn là chỉ cần thay thế đoạn code đã được compile (cách của inline function).
     
**VD: giả sử trường hợp 8 bit**
```
Trường hợp đang ở dưới thì khi đến 0x03 thì nó gặp 1 hàm. 
Lúc này nó sẽ lưu 0x03 vào Stack Pointer và PC nó sẽ vào hàm A để chạy từ 0xc1 đến 0xc6.
Sau khi PC chạy xong hàm A, lúc này nó sẽ vào Stack Pointer để lấy 0x03 gán cho PC và tiếp tục chạy từ 0x03 đến 0x08.
 
0x01   main (){           
0x02    while(1){     
0x03     A();
 .    
 .      }
0x08  }

0xc1    void A(){
  .
  .    
0xc6   }
```

## Inline
- Được xử lý bởi compiler
- Được khai báo với từ khóa inline
- Khi compiler thấy bất kỳ chỗ nào xuất hiện inline function, nó sẽ thay thế chỗ đó bởi định nghĩa của hàm đã được compiler tương ứng. –> Phần được thay thế không phải code mà là đoạn code đã được compiler.
     
## So sánh
- `Macro` đơn giản là chỉ `thay thế đoạn code macro vào chỗ được gọi` trước khi được biên dịch
- `Inline thay thế đoạn mã code đã được biên dịch vào chỗ được gọi`.
- `Hàm bình thường phải tạo một function call`, lưu địa chỉ trước khi gọi hàm vào stack sau đó mới thực hiện hàm và sau cùng là quay trở về địa chỉ trên stack trước khi gọi hàm và thực hiện tiếp chương trình
- `Macro khiến code trở nên dài` hơn rất nhiều so với bình thường `nhưng thời gian chạy nhanh`.
- `Hàm inline cũng khiến code dài hơn`, tuy nhiên nó làm `giảm thời gian chạy chương trình`.
- `Hàm bình thường` sẽ phải gọi function call nên `tốn thời gian hơn inline function` nhưng `code ngắn gọn hơn`.
   
</details>
    
    
<details>
<summary>TOÁN TỬ BITWISE</summary>
    
 ## Toán tử AND
 <img width="173" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/131b91c7-7404-42a1-89d4-00713f196a51">

 ## Toán tử OR
 <img width="173" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/e2779fd1-8884-4ab2-b2e9-fdaa875e1139">
 
 ## Toán tử NOT
 <img width="85" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/0d2bc1fd-1d6e-4067-8745-37b6efbd4714">

 ## Toán tử XOR
 <img width="175" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/28c77307-f094-4afa-b52e-925be353be09">
    
</details>

<details>
<summary>THAO TÁC BIT</summary>

<img width="355" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/02e222c1-e668-4939-a6ea-dd05e7eb746e">

Dịch trái (<<) 4 bit là bỏ đi 4 bit bên trái(ở đầu) và thêm 4 bit 0 vào bên phải(ở cuối)

<img width="357" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/085599a0-6a96-4d58-b47a-507eb1705ee4">

Dịch phải(>>) 1 bit là bỏ đi 1 bit bên phải(ở cuối) và thêm 1 bit 0 vào bên trái(ở đầu)
## Set 1 bit
```bit |= (1 << n); //(n là vị trí bit)```
## Clear 1 bit
```bit &= ~(1 << n);```
## Toggle 1 bit 
```bit ^= (1 << n);```
## Test 1 bit
``` 
// bit & (1 << n)
int bit = 5; // 0101
printf("%s",(((bit & (1<<2)) !=0)?"true":"false"));
 ```
</details>   
 
<details>
<summary>TYPEDEF</summary>
    
Typedef được sử dụng để tạo tên mới cho kiểu dữ liệu. 
```
typedef uint8_t u8;
u8 x = 10; // u8 bản chất nó là kiểu uint8_t
 ```
</details>
    
    
<details>
<summary>STRUCT - UNION</summary>
 
## Struct
 ### Size của Struct
 ```
 // Chương trình tính size của  1 struct
#include <stdio.h>
#include <stdint.h>

struct typeDate
{
    uint8_t arr1[10]; // 1 byte
    uint16_t arr2[7]; // 2 byte
    uint64_t arr3[5]; // 8 byte
    uint32_t arr4[1]; // 4 byte
};

int main ()
{
    printf("Size: %lu", sizeof(struct typeDate)); // result = 72 byte
    return 0;
}
 ```
 
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
### Cách tính số size :

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
### Cách tính số size

uint8_t có size 1 byte => arr1[11] cần 1*11 = 11 byte để lưu, mà 1 lần quét là 4 byte (byte cao nhất trong struct) 

=> arr1[11] = 11 byte + **1 byte dư** = 12 byte (cần 3 lần quét)

uint32_t có size 4 byte => arr2[4] cần 4*4 = 16 byte để lưu 

=>  arr2[4] = 16 byte  (cần 4 lần quét)

uint16_t có size 2 byte => arr3[7] cần 2*7 = 14 byte để lưu

=> arr2[7] = 14 byte + 2 byte dư = 16 byte (cần 4 lần quét)

==> tổng size = 12 byte + 16 byte + 16 byte = 44 byte

## Union  
 ```
typedef union
{
    /*size union = size member lớn nhất
      union là bộ nhớ dùng chung nên khi thay đổi member này sẽ ảnh hưởng đến
      member khác.
    */
    uint8_t test1[6]; // 6 byte
    uint8_t test2[2]; // 2 byte
}data_union;
 ```
## So sánh Struct - Union
Về mặt ý nghĩa, struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau:
- Struct: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding).
- Union : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác.

</details>

<details>
    <summary>STATIC</summary>

 ## Static cục bộ
Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được `khởi tạo 1 lần duy nhất` và `tồn tại suốt thời gian chạy chương trình`. `Giá trị của nó không bị mất đi ngay cả kết thúc hàm`. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì `biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó`. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.
```
// Ví dụ
#include <stdio.h>
    
void dem(){
    static int count = 10; // static cục bộ
    printf("count = %d\n",count);
    count++;
}
    
int main()
{
    dem();
    dem();
    dem();
    
    return 0;
}
/*
    Result:
    10
    11
    12
*/
```
## Static toàn cục
Static toàn cục mọi hàm có thể gọi nó được, nhưng nó chỉ có thể được `truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được`.
```
 // Ví dụ
 #include <stdio.h>

/*
    static toàn cục chỉ có thể lấy giá trị trong file chứa nó
    nên khi sử dụng extern để sử dụng biến, hàm đó ở file khác sẽ báo lỗi
*/

static int count = 16;

void dem(){
    printf("count = %d\n",count);
    count++;
}
int main()
{
    dem();
    dem();
}
/*
    Result: 
    16
    17
*/
```
</details>
    
<details>
<summary>POINTER</summary>
 
## Null Pointer
- Con trỏ null là con trỏ có giá trị và địa chỉ bằng 0.
- Khi khai báo 1 con trỏ:
    + Phải khai báo địa chỉ cho nó.
    + Nếu mà chưa sử dụng thì gán cho nó con trỏ null. 
    + Hoặc khi khai báo con trỏ và đã sử dụng nó rồi, khi không muốn sử dụng nó nữa thì phải gán nó lại là con trỏ null.
```
    int *ptr = NULL;
```
## Function Pointer
- Sau khi khai báo thì hàm cũng được lưu trữ tại một địa chỉ trong bộ nhớ, và do đó, chúng ta cũng có thể sử dụng con trỏ để lưu trữ địa chỉ và qua đó thao tác với chúng.
- Chúng ta gọi con trỏ lưu trữ địa chỉ của một hàm là con trỏ hàm trong c, và sử dụng nó để truy cập vào địa chỉ của hàm, cũng như thực thi các xử lý bên trong hàm đó.
 ```
    Cách khai báo:
        type (*fp) ( para_type_1, para_type_2, para_type_3,...);
    fp: tên con trỏ hàm.
    type: kiểu của con trỏ.
    para_type_1,.. : các kiểu của các đối số parameter.
 ```
 ```
 VD:
#include <stdio.h>

void tong(int a,int b){
    printf("tong %d va %d = %d\n", a, b, a + b);
}

void hieu(int a,int b){
    printf("hieu %d va %d = %d\n", a, b, a - b);
}

void tich(int a,int b){
    printf("tich %d va %d = %d\n", a, b, a * b);
}

void thuong(int a,int b){
    printf("thuong %d va %d = %f\n", a, b, (float)a/b);
}

void tinhtoan(int a, int b, void (*ptr)(int, int))
{   // thông qua con trỏ hàm để hàm làm input parameter
    printf("Chuong trin tinh toan\n");
    ptr(a,b);
}
int main()
{

    // void (*pheptoan)(int, int) = NULL;
    // pheptoan = thuong;
    // pheptoan(5,9);

    tinhtoan(8,9,hieu);
    return 0;
}
    
 ```
 ## Void Pointer
    
    
</details>
