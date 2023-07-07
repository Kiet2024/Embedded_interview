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
        uint8_t getID();
        string getTen();
        double getGia();
        void getThongTin();
};

MonAn::MonAn(string ten, double gia){
    static uint8_t id = 100;
    ID = id;
    id++;
    TEN = ten;
    GIA = gia;
}

uint8_t MonAn::getID(){
    return this -> ID;
}

string MonAn::getTen(){
    return this -> TEN;
}

double MonAn::getGia(){
    return this -> GIA;
}

void MonAn::getThongTin(){
    static uint8_t stt = 1;
    cout << "stt:" << stt++ << endl;
    cout << "id :" << getID() << endl;
    cout << "ten mon:" << getTen() << endl;
    cout << "gia:" << getGia() << endl;
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
    public:
        QuanLy();
        list<MonAn> getDatabase();
        uint8_t getSoBan();
};

void QuanLy::themMon(){
    string ten;
    double gia;
    cout << "Nhap ten mon: " << endl;
    cin >> ten;
    cout << "Nhap gia: " << endl;
    cin >> gia;
    MonAn mon(ten, gia);
    DATABASE.push_back(mon);
    QuanLy();
}
void QuanLy::danhSachMon(){
    cout << "   ************Danh sach mon*************" << endl;
    cout << "   ======================================" << endl;
    cout << "   | STT |  ID  |   TEN MON    |   GIA  |" << endl;
    cout << "   ======================================" << endl;
    for (MonAn item : DATABASE )
    {
        item.getThongTin();
    }
    //QuanLy();
    

}

void QuanLy::suaMon(){
    uint8_t id;
    string ten;
    double gia;
    int key = 0;
    // hien thi danh sach mon

    cout << "Nhap ID:";
    cin >> id;
    do
    {
        cout << "1.Sua ten mon" << endl;
        cout << "2.Sua gia mon" << endl;
        cout << "0.Quay lai"    << endl;
    } while (key < 0 || key > 2);
    
    switch (key)
    {
    case 0:
        // quay ve man hinh quan ly
        break;
    case 1:
        
        break;
    case 2:
  
        break;
    
    default:
        break;
    }
    cout << "Nhap ten mon: " << endl;
    cin >> ten;
    cout << "Nhap gia: " << endl;
    cin >> gia;
}

void QuanLy::setSoBan(){
    cout << "Moi nhap so ban: ";
    cin  >> SO_BAN;
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
        printf("-----Chuong trinh Quan ly-----\n");
        printf("1.Them mon\n");
        printf("2.Sua mon\n");
        printf("3.Xoa mon\n");
        printf("4.Danh sach mon\n");
        printf("5.Thiet lap so ban\n");
        printf("0.Quay lai\n");
        printf("Moi nhap lua chon:");
        scanf("%d", &key);
    } while (key < 0 || key > 6);

    switch (key)
    {
    case 0:
        // Quay lai Menu
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
    QuanLy();

    return 0;
}