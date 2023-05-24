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