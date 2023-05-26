#include <stdio.h>

/*
    static toàn cục chỉ có thể lấy giá trị trong file chứa nó
    nên khi dùng extern để sử dụng biến, hàm đó ở file khác sẽ báo lỗi
*/
extern int count = 16;

void dem(){
    printf("count = %d\n",count);
    count++;
}

int main()
{
    dem();
    dem();

}