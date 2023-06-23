#include <iostream>
#include <string>
#include <stdio.h>

/*
    Tạo một lớp người với các thuộc tính tên, tuổi và địa chỉ, và các
    phương thức để in thông tin của người đó và tính tuổi của người đó.
*/

using namespace std;

class Nguoi{
    private:
        string Ten;
        int namSinh;
        string diaChi;
    public:
        Nguoi(string ten, int namsinh, string diachi);
        void getThongTin();
        int tinhTuoi();
        
};

Nguoi::Nguoi(string ten, int namsinh, string diachi){
    Ten = ten;
    namSinh = namsinh;
    diaChi = diachi;
}

int Nguoi::tinhTuoi(){
    return (2023 - namSinh);
}

void Nguoi::getThongTin(){
    cout << "Ten: " << Ten << endl;
    cout << "Nam sinh: " << namSinh << endl;
    cout << "Tuoi: " << tinhTuoi() << endl;
    cout << "Dia chi: " << diaChi << endl;

}


int main()
{
    Nguoi thongtin1("Kiet", 2000, "Cu Chi, Tp.Ho Chi Minh");
    thongtin1.getThongTin();

    return 0;
}