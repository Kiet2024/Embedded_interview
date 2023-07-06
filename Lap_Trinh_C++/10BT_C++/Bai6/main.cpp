#include <iostream>

/*
    Tạo một lớp phân số với các thuộc tính tử số và mẫu số và các phương
    thức để tính toán các phép tính toán cơ bản như cộng, trừ, nhân và chia.
*/

using namespace std;

class PhanSo{
    private:
        int tu_So;
        int mau_So;
    public:
        PhanSo(int tu_so, int mau_so);
        int getTuSo();
        int getMauSo();
        float Cong(PhanSo phanso);
        float Tru(PhanSo phanso);
        float Nhan(PhanSo phanso);
        float Chia(PhanSo phanso);
};

PhanSo::PhanSo(int tu_so, int mau_so){
    tu_So = tu_so;
    mau_So = mau_so;
}

int PhanSo::getTuSo(){
    return tu_So;
}

int PhanSo::getMauSo(){
    return mau_So;
}

float PhanSo::Cong(PhanSo phanso){
    int TuSo = tu_So * phanso.getMauSo() + phanso.getTuSo()*mau_So;
    int MaSo = mau_So * phanso.getMauSo();
    return (float)TuSo/MaSo;
}

float PhanSo::Tru(PhanSo phanso){
    int TuSo = tu_So * phanso.getMauSo() - phanso.getTuSo()*mau_So;
    int MaSo = mau_So * phanso.getMauSo();
    return (float)TuSo/MaSo;
}

float PhanSo::Nhan(PhanSo phanso){
    int TuSo = tu_So *phanso.getTuSo();
    int MaSo = mau_So * phanso.getMauSo();
    return (float)TuSo/MaSo;
}

float PhanSo::Chia(PhanSo phanso){
    int TuSo = tu_So * phanso.getMauSo() ;
    int MaSo = mau_So * phanso.getTuSo();
    return (float)TuSo/MaSo;
}



int main()
{
    PhanSo PhanSo1(7,5), PhanSo2(4,5);
    cout << "Tong 2 phan so = " << PhanSo1.Cong(PhanSo2) << endl;
    cout << "Hieu 2 phan so = " << PhanSo1.Tru(PhanSo2)  << endl;
    cout << "Tich 2 phan so = " << PhanSo1.Nhan(PhanSo2) << endl;
    cout << "Thuong 2 phan so = " << PhanSo1.Chia(PhanSo2) << endl;
    return 0;
}