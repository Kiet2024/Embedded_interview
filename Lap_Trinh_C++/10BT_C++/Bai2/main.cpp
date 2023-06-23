#include <stdio.h>
#include <math.h>
#include <iostream>

/*
    Tạo một lớp hình chữ nhật với các thuộc tính chiều dài, chiều rộng và
    các phương thức để tính chu vi, diện tích, đường chéo và kiểm tra xem
    nó có phải là hình vuông hay không
*/


using namespace std;

class HinhChuNhat{
    private:
        int ChieuDai;
        int ChieuRong;
    public:
        void setThongSo(int ChieuDai, int ChieuRong);
        void getHinhChuNhat();
        int ChuVi();
        int DienTich();
        int DuongCheo();
        
};

void HinhChuNhat::setThongSo(int ChieuDai, int ChieuRong){
    HinhChuNhat::ChieuDai = ChieuDai;
    HinhChuNhat::ChieuRong = ChieuRong;
}

int HinhChuNhat::ChuVi(){

    return 2*(ChieuDai + ChieuRong);
}

int HinhChuNhat::DienTich(){

    return (ChieuDai * ChieuRong);
}

int HinhChuNhat::DuongCheo(){

    return (sqrt(pow(ChieuDai,2)+pow(ChieuRong,2)));
}

void HinhChuNhat::getHinhChuNhat(){
    cout<< "Chieu dai = " << ChieuDai << endl;
    cout<< "Chieu rong = " << ChieuRong << endl;
    
    if (ChieuDai == ChieuRong)
    {
        cout<< "Day la hinh vuong" << endl;
    }
    else {
        cout<< "Day la hinh chu nhat" << endl;
    }
    cout << "Chu vi = " << ChuVi() << endl;
    cout << "Dien tich = " << DienTich() << endl;
    cout << "Duong cheo = " << DuongCheo() << endl;
}


int main()
{
    HinhChuNhat hcn ;
    hcn.setThongSo(4, 4);
    hcn.getHinhChuNhat();

}