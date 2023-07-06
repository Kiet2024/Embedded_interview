#include <iostream>

/*
    Tạo một lớp ngày tháng năm với các thuộc tính ngày, tháng và năm, và
    các phương thức để tính tuổi của người và kiểm tra xem một ngày nhất
    định có phải là ngày nghỉ lễ hay không.
*/

using namespace std;

class NgayThangNam{
    private:
        uint8_t NGAY, THANG;
        int NAM;
    public:
        NgayThangNam(uint8_t ngay, uint8_t thang, int nam);
        void getTuoi();
        void checkNgayLe();
};

NgayThangNam::NgayThangNam(uint8_t ngay, uint8_t thang, int nam){
    NGAY = ngay;
    THANG = thang;
    NAM = nam;
}

void NgayThangNam::getTuoi(){
    cout << "Tuoi: " << 2023 - NAM << endl;
}

void NgayThangNam::checkNgayLe(){
    if ((THANG == 1 && NGAY == 1) || (THANG == 4 && NGAY == 30) || 
        (THANG == 5 && NGAY == 1) || (THANG == 9 && NGAY == 2)) {
        
        cout << "Day la ngay nghi le" << endl;
    }
    else{
        cout << "Day khong la ngay nghi le" << endl;
    }
}



int main()
{

    NgayThangNam NgaySinh(9, 11, 2000), NgayBatKy(2, 9, 2023);
    NgaySinh.getTuoi();
    NgayBatKy.checkNgayLe();

    return 0;
}