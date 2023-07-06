#include <iostream>
#include <string>

/*
    Tạo một lớp tài khoản ngân hàng với các thuộc tính số tài khoản, tên tài
    khoản và số dư, và các phương thức để rút, nộp tiền và kiểm tra số dư
    trong tài khoản.
*/

using namespace std;

class TaiKhoanNganHang{
    private:
        string tenTaiKhoan;
        int soTaiKhoan;
        int soDu = 0;
    public:
        TaiKhoanNganHang(string tenTK, int soTK);
        void rutTien(int soTienRut);
        void nopTien(int soTienNop);
        void checkSoDu();
};

TaiKhoanNganHang::TaiKhoanNganHang(string tenTK, int soTK){
    tenTaiKhoan = tenTK;
    soTaiKhoan = soTK;
}

void TaiKhoanNganHang::rutTien(int soTienRut){
    if (soDu > soTienRut){
        soDu = soDu - soTienRut;
        cout << "So TK: " << soTaiKhoan << "," << "Ten TK: " << tenTaiKhoan << endl;
        cout << "   Da rut thanh cong " << soTienRut << " VND" <<endl;
    }
    else {
        cout << "So TK: " << soTaiKhoan << "," << "Ten TK: " << tenTaiKhoan << endl;
        cout << "   So du trong tai khoan khong du" << endl;
    }
}

void TaiKhoanNganHang::nopTien(int soTienNop){
    soDu = soDu + soTienNop;
    cout << "So TK: " << soTaiKhoan << "," << "Ten TK: " << tenTaiKhoan << endl;
    cout << "   Da nop tien thanh cong " << soTienNop << " VND" << endl;
}

void TaiKhoanNganHang::checkSoDu(){
    cout << "So TK: " << soTaiKhoan << "," << "Ten TK: " << tenTaiKhoan << endl;
    cout << "   So tien hien tai: " << soDu << " VND" << endl;
}


int main()
{
    TaiKhoanNganHang KhachHang1("NGUYEN TUAN KIET", 18029271);
    KhachHang1.nopTien(5000000);
    KhachHang1.checkSoDu();
    KhachHang1.rutTien(500000);
    KhachHang1.checkSoDu();
    KhachHang1.rutTien(500000000);
}