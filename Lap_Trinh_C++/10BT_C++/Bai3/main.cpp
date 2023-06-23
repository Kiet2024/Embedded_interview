#include <iostream>

/*
    Tạo một lớp hình tròn với bán kính và các phương thức để tính chu vi
    và diện tích của hình tròn
*/


using namespace std;

#define PI 3.14

class HinhTron {
    private:
        double R;
    public:
        void setBanKinh(double R);
        void getHinhTron();
        double ChuVi();
        double DienTich();
       

};

void HinhTron::setBanKinh(double R){
    HinhTron::R = R;
}

double HinhTron::ChuVi(){
    return (2 * R * PI);
}

double HinhTron::DienTich(){
    return (R * R * PI);
}

void HinhTron::getHinhTron(){
    cout << "Chu vi = " << ChuVi() << endl;
    cout << "Dien tich = " << DienTich() << endl;
}


int main()
{
    HinhTron ht;
    ht.setBanKinh(5.6);
    ht.getHinhTron();

}