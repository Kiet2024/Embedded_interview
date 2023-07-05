#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>


using namespace std;

typedef enum{
    NAM,
    NU
}TypeGioiTinh;

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}TypeHocLuc;

class SinhVien{
    private:
        int ID;
        string TEN;
        TypeGioiTinh GIOI_TINH;
        float TOAN;
        float LY;
        float HOA;
        int TUOI;
        TypeHocLuc HOC_LUC;
    public:
        SinhVien(string ten, TypeGioiTinh gioi_tinh, int tuoi, 
                 float toan, float ly, float hoa);
        uint8_t getID();
        float getTrung_Binh();
        void getThongTin();
        TypeHocLuc getHocLuc();
        TypeGioiTinh getGioiTinh();

};

SinhVien::SinhVien(string ten, TypeGioiTinh gioi_tinh, int tuoi, 
                   float toan, float ly, float hoa) {
    static int id = 100;
    ID = id;
    id++;
    TEN = ten;
    GIOI_TINH = gioi_tinh;
    TUOI = tuoi;
    TOAN = toan;
    LY = ly;
    HOA = hoa;
}

TypeGioiTinh SinhVien::getGioiTinh(){
    return GIOI_TINH;
}

TypeHocLuc SinhVien::getHocLuc(){
    if (getTrung_Binh() >= 8){
        HOC_LUC = GIOI;
    }
    else if(getTrung_Binh() >= 6.5){
        HOC_LUC = KHA;
    }
    else if(getTrung_Binh() >= 5) {
        HOC_LUC = TRUNG_BINH;
    }
    else {
        HOC_LUC = YEU;
    }
    return HOC_LUC;
}

float SinhVien::getTrung_Binh(){
    return (TOAN + LY + HOA)/3;
}

void SinhVien::getThongTin(){
    string hocluc;
    string gioitinh;
    if (getGioiTinh() == NAM) gioitinh = "Nam"; 
    else gioitinh = "Nu";

    if (getHocLuc() == GIOI) hocluc = "Gioi"; 
    else if (getHocLuc() == KHA) hocluc = "Kha";
    else if (getHocLuc() == TRUNG_BINH) hocluc = "Trung Binh";
    else if (getHocLuc() == YEU) hocluc = "Yeu";
    cout << "=====================================================================================================" << endl;
    cout << "|  ID  |           TEN          |   GIOI TINH  |  TUOI  |  TOAN  |  LY  |  HOA  |  DTB  |  HOC LUC  |"<< endl;
    cout << "=====================================================================================================" << endl;
    cout << "|  "<< ID << "|" << " "<< TEN <<"|" <<endl;
    cout << "" << TEN << endl;
    cout << "" << gioitinh << endl;
    cout << "" << TUOI << endl;
    //cout << "" << getTrung_Binh() << endl; 
    printf ("%f\n",getTrung_Binh());
    cout <<"" << hocluc << endl;
}

class QuanLySinhVien {
    private:
        list <SinhVien> Database;
    public:
        void themSinhVien();
        void getThongTinSinVien();
        void capNhatThongTin();
        
       
};

void QuanLySinhVien::themSinhVien(){
    string TEN;
    TypeGioiTinh GT;
    string gioi_tinh;
    float TOAN;
    float LY;
    float HOA;
    int TUOI;
    string hoc_luc;
    int SoLanThem;

    cout << "Nhap so sinh vien can them:" << endl;
    cin >> SoLanThem;
    while(SoLanThem > 0) {
        cout << "Moi nhap thong tin" << endl;
        cout << "Ten: ";
        cin >> TEN;

        cout << "Gioi tinh: ";
        cin >> gioi_tinh;
        GT = (gioi_tinh == "nam" || gioi_tinh == "Nam" || gioi_tinh == "NAM")?NAM:NU;
        cout << "Tuoi: ";
        cin >> TUOI;
        cout << "Toan: ";
        cin >> TOAN;
        cout << "Ly: ";
        cin >> LY;
        cout << "Hoa: ";
        cin >> HOA;
        SinhVien sv(TEN, GT, TUOI, TOAN, LY, HOA);

        Database.push_back(sv);
        SoLanThem--;
    }

    for (SinhVien sv : Database)
    {
        sv.getThongTin();
    }
    
    
}


int main()
{
    QuanLySinhVien sv;
    sv.themSinhVien();
   

    return 0;
}


//  Menu(){
//             cout << "1.Them sinh vien." << endl;
//             cout << "2.Cap nhat thong tin sinh vien boi ID." << endl;
//             cout << "3.Xoa sinh vien boi ID." << endl;
//             cout << "4.Tim kiem sinh vien theo ten." << endl;
//             cout << "5.Sap xep sinh vien theo diem trung binh (GPA)." << endl;
//             cout << "6.Sap xep sinh vien theo ten." << endl;
//             cout << "7.Hien thi danh sach sinh vien." << endl;
//         };