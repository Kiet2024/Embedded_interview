#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

class MonAn{
    private:
        uint8_t ID;
        string TEN;
        double GIA;
    public:
        MonAn(string ten, double gia);
        uint8_t STT;
        uint8_t getID();
        string getTen();
        double getGia();
        void getThongTinMon();
};

MonAn::MonAn(string ten, double gia){
    static uint8_t id = 100;
    static uint8_t stt = 1;
    STT = stt;
    stt++;
    ID = id;
    id++;
    TEN = ten;
    GIA = gia;
}

uint8_t MonAn::getID(){
    return ID;
}

string MonAn::getTen(){
    return TEN;
}

double MonAn::getGia(){
    return GIA;
}

void MonAn::getThongTinMon(){
    printf( "      | %-4d| %-5d|    %-15s  |   %-10.3f|\n", STT, getID(), getTen().c_str() , getGia());
}

class QuanLy{
    private:
        list<MonAn> DATABASE;
        uint8_t SO_BAN;
        void themMon();
        void suaMon();
        void xoaMon();
        void danhSachMon();
        void setSoBan();
        void demo();
    public:
        QuanLy();
        list<MonAn> getDatabase();
        uint8_t getSoBan();
};


void QuanLy::themMon(){
    int key;
    string ten;
    double gia;
    cin.ignore(); // xoa ky tu dau tien trong bo nho dem
    cout << "Nhap ten mon: ";
    getline(cin, ten);
    cout << "Nhap gia: " ;
    cin >> gia;
    MonAn mon(ten, gia);
    DATABASE.push_back(mon);
    do {
        cout << "   1.Tiep tuc them mon" << endl;
        cout << "   0.Quay lai"<< endl;
        cout << "Moi nhap lua chon: ";
        cin  >> key;
    } while (key < 0 || key > 1);
    
    switch (key) {
    case 0:
        QuanLy();
        break;
    case 1:
        themMon();
        break;
    default:
        break;
    }
}
void QuanLy::danhSachMon(){
    if (DATABASE.empty()){
        cout << "Chua them data mon an" << endl;
    }
    else {
         cout << "                        Danh sach mon                  " << endl;
         cout << "      ==================================================" << endl;
         cout << "      | STT |  ID  |      TEN MON        |   GIA(VND)  |" << endl;
         cout << "      ==================================================" << endl;
        for (auto item: DATABASE) {
            item.getThongTinMon();
            cout << "      --------------------------------------------------" << endl;

        }
    }
    QuanLy(); 
}


void QuanLy::suaMon(){
    uint8_t id;
    string ten;
    double gia;
    int key;

    danhSachMon();
    cout << "Nhap ID: ";
    cin >> id;
    do
    {
        cout << "   1.Sua ten mon" << endl;
        cout << "   2.Sua gia mon" << endl;
        cout << "   0.Quay lai"    << endl;
        cout << "Moi nhap lua chon: ";
        cin  >> key;
    } while (key < 0 || key > 2);

    switch (key)
    {
    case 0:
        QuanLy();
        break;
    case 1:
        
        break;
    case 2:
  
        break;
    
    default:
        break;
    }
    cout << "Nhap ten mon: ";
    cin >> ten;
    cout << "Nhap gia: ";
    cin >> gia;
}
void QuanLy::setSoBan(){
    cout << "Moi nhap so ban: ";
    cin  >> SO_BAN;
    //menuQuanLy();
}

list<MonAn> QuanLy::getDatabase(){
    return this -> DATABASE;
}

uint8_t QuanLy::getSoBan(){
    return this -> SO_BAN;
}


QuanLy::QuanLy(){
    int key = 0;
    do {
        cout << "------Chuong trinh Quan ly------" << endl;
        cout << "   1.Them mon" << endl;
        cout << "   2.Sua mon" << endl;
        cout << "   3.Xoa mon" << endl;
        cout << "   4.Danh sach mon" << endl;
        cout << "   5.Thiet lap so ban" << endl;
        cout << "   0.Quay lai" << endl;
        cout << "Moi nhap lua chon: ";
        cin >> key;
    } while (key < 0 || key > 6);

    switch (key)
    {
    case 0:
        //Quay lai Menu chinh
        break;
    case 1:
        themMon();
        break;
    case 2:
        suaMon();
        break;
    case 3:
        //xoaMon();
        break;
    case 4:
        danhSachMon();
        break;
    case 5:
        setSoBan();
        break;
    default:
        break;
    }
    
}

class ThongTinBan{
    private:
        uint8_t SO_BAN;
        bool TRANG_THAI;
        typedef struct{
            MonAn MON;
            uint8_t SO_LUONG;
        }TypeMon;
        list<TypeMon> DATABASE_MON_AN;
    public:
        ThongTinBan(uint8_t soBan, bool trangThai);
        uint8_t getSoBan();
        bool getTrangThai();
        void danhSachMon();
        void themMon(MonAn mon, uint8_t soLuong);
        void suaMon(uint8_t id, uint8_t soLuong);
        void xoaMon(uint8_t id);
};




class NhanVien{
    private:
        list<MonAn> DATABASE_MON_AN;
        typedef struct{
            uint8_t SO_BAN;
            bool TRANG_THAI;
        }TypeThongTinBan;
    public:
        NhanVien();

};

int main()
{
    int key;
    cout << "------GIAO DIEN QUAN LY ORDER-------" << endl;
    cout << "   1.Quan ly" << endl;
    cout << "   2.Nhan vien" << endl;
    cout << "Moi nhap lua chon: ";
    cin  >> key;
    switch (key)
    {
    case 1:
        QuanLy();
        break;
    case 2:
        //NhanVien();
    default:
        break;
    }
    return 0;
}