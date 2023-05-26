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

    /*
    // VD: Con trỏ hàm
    void (*pheptoan)(int, int) = NULL;
    pheptoan = thuong;
    pheptoan(5,9);

    tinhtoan(8,9,hieu);
    */
    
    /*

    // VD: Con trỏ void
    int i = 30;
    double d =15.6;
    char c ='B';

    // con trỏ void có thể trỏ đến bất kỳ địa chỉ nào nhưng không thể trả về giá trị
    void *ptr = &i;

    // để lấy giá trị từ con trỏ void ta cần ép kiểu nó
    printf("i = %d\n",*(int *)ptr);

    ptr = &d;
    printf("d = %f\n",*(double *)ptr);

    ptr = &c;
    printf("c = %c\n",*(char *)ptr);

    ptr = &tong;
    ((void (*)(int, int))ptr)(9,16);

    */
    

    // VD: Con trỏ đến con trỏ

    char *array = "hello";
    char array1[] = "hello";
    char *array2[] = {"Hi", "hello", "world"};
    printf("test: %c\n",**(array2+1));
    printf("test: %c\n",*(*array2+1));

    int a = 15;
    int *ptr = &a;
    int **ptp = &ptr;
    printf("test: %d\n",**ptp);
    return 0;
}