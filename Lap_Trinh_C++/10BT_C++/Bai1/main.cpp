#include <iostream>

/*
    Tạo một lớp điểm trong hệ tọa độ 2D và viết các phương thức để tính
    khoảng cách giữa hai điểm, tính diện tích của tam giác được tạo bởi ba
    điểm.
*/

using namespace std;

class Diem {
    private:
        int ToaDoX;
        int ToaDoY;
    public:
        int setToaDo(int X, int Y);
        void getToaDo();
}

int Diem::getToaDo(int X, int Y){
    ToaDoX = X;
    ToaDoY = Y;
}

typedef enum{
    KhoangCach,
    DienTich
}TypePhepToan;

int main()
{

}