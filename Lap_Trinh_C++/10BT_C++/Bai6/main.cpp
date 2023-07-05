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
        void Cong(PhanSo phanso);
        void Tru(PhanSo phanso);
        void Nhan(PhanSo phanso);
        void Chia(PhanSo phanso);
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

void PhanSo::Cong(PhanSo phanso){
    
}



int main()
{


    return 0;
}