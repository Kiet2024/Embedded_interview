#include <iostream>
#include <string>

/*
    Tạo một lớp động vật với các thuộc tính tên, tuổi và trọng lượng, và các
    phương thức để tính chỉ số BMI, so sánh tuổi và trọng lượng của các
    động vật khác nhau.
*/

using namespace std;

class DongVat{
    private:
        string Ten;
        int Tuoi;
        int TrongLuong;
        double ChieuCao;
        
    public:
       DongVat(string ten, int tuoi, int trongluong, double chieucao);
       void soSanhTuoi(DongVat dv);
       void soSanhTrongLuong(DongVat dv);
       void getThongTin();
       double BMI();
};

DongVat::DongVat(string ten, int tuoi, int trongluong, double chieucao){
    Ten = ten;
    Tuoi = tuoi;
    TrongLuong = trongluong;
    ChieuCao = chieucao; 
}

double DongVat::BMI(){
    return (TrongLuong/(ChieuCao*ChieuCao));
}

void DongVat::soSanhTuoi(DongVat dv) {
        if (Tuoi == dv.Tuoi) {
            cout << "" << Ten << " bang tuoi" << " " << dv.Ten << endl; 
        } else if (Tuoi > dv.Tuoi) {
            cout << "" << Ten << " lon tuoi hon" << " " << dv.Ten << endl; 
        } else {
            cout << "" << Ten << " nho tuoi hon" << " " << dv.Ten << endl; 
        }
}

void DongVat::soSanhTrongLuong(DongVat dv) {
        if (TrongLuong == dv.TrongLuong) {
            cout << "" << Ten << " nang bang" << " " << dv.Ten << endl; 
        } else if (Tuoi > dv.Tuoi) {
            cout << "" << Ten << " nang hon" << " " << dv.Ten << endl; 
        } else {
            cout << "" << Ten << " nhe hon" << " " << dv.Ten << endl; 
        }
}

void DongVat::getThongTin(){
    cout << "Ten: " << Ten << endl;
    cout << "Tuoi: " << Tuoi << endl;
    cout << "Trong luong: " << TrongLuong  << "KG" << endl;
    cout << "Chieu cao : " << ChieuCao << "M" << endl;
    cout << "BMI: " << BMI() << endl;
}



int main()
{
    DongVat DV1("Cho", 2, 20, 0.5), DV2("Meo", 1, 10, 0.3), DV3("Rua", 5, 7, 0.1);

    DV1.getThongTin();
    DV2.getThongTin();
    DV3.getThongTin();
    DV2.soSanhTuoi(DV3);
    DV2.soSanhTrongLuong(DV1);

    return 0;
} 