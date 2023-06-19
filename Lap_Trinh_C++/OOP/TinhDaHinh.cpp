#include <iostream>

class ToanHoc{
    public:
        void tong(int a, int b);
        void tong(int a, int b, int c);
        int tong(int a, double b);
};

void ToanHoc::tong(int a, int b){
    printf("Tong a va b: %d\n", a + b);
}

void ToanHoc::tong(int a, int b, int c){
    printf("Tong a, b va c: %d\n", a + b + c);
}

int ToanHoc::tong(int a, double b){
    return a + (int)b;
}

template<typename var, typename varB>

var tong(var a, varB b){
    return var(a+b);
}

int main ()
{
    ToanHoc th;
    th.tong(7, 8);
    th.tong(2, 3, 4);
    printf("Tong a va b: %d\n",th.tong(7, 12.3));
    printf("Tong a va b: %f\n",tong(6, 12.3));
}