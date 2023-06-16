#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    public:
        //SinhVien(int tuoi = 5, int lop = 16); //constructor có tham số đầu vào
        void setThongTin(string ten, int tuoi); // method
        void hienthi(); // method
    protected: // class con có thể sử dụng được
        int TUOI; //property
        string TEN;

};

void DoiTuong::hienthi(){
    cout<<"Day la class DoiTuong\n";
    cout<<"Ten:" <<TEN<<endl;
    cout<<"Lop: " <<TUOI<<endl;
       
}

void DoiTuong::setThongTin(string ten, int tuoi){
   TEN = ten;
   TUOI = tuoi;
}

// kế thừa class DoiTuong
class SinhVien: public DoiTuong{ 
    public:
        // ghi đè lên class DoiTuong;
        void setThongTin(string ten, int tuoi, int mssv);
        void hienthi();
    private:
        int MSSV;
 
};

void SinhVien::setThongTin(string ten, int tuoi, int mssv){
    TEN = ten;
    TUOI = tuoi;
    MSSV = mssv;

};

void SinhVien::hienthi(){
    cout<<"Day la class SinhVien\n";
    cout<<"Ten:" <<TEN<<endl;
    cout<<"Lop: " <<TUOI<<endl;
    cout<<"MSSV: "<<MSSV<<endl;
       
}

int main()
{
   DoiTuong dt;
   dt.setThongTin("Kiet", 17);
   dt.hienthi();

   SinhVien sv;
   sv.setThongTin("Kiet", 23, 18029271);
   sv.hienthi();
   
   
   return 0;
}