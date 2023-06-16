#include <iostream>
#include <string>

using namespace std;

class SinhVien{
    public:
        string ten;
        static int tuoi; // static trong class cần phải khởi tạo lần đầu
};

int SinhVien::tuoi; // khởi tạo lần đầu và đc tồn tại hết vòng đời chương trình

int main()
{
    SinhVien sv1, sv2;

    printf("Dia chi sv1: %p\n", &sv1);
    printf("Dia chi sv1.ten: %p\n", &(sv1.ten));
    printf("Dia chi sv1.tuoi: %p\n", &(sv1.tuoi));

    sv1.tuoi = 10;

    printf("Dia chi sv2: %p\n", &sv2);
    printf("Dia chi sv2.ten: %p\n", &(sv2.ten));
    printf("Dia chi sv2.tuoi: %p\n", &(sv2.tuoi));

    sv2.tuoi = 30;

    printf("%d \n",sv1.tuoi);



}


