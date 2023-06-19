#include <iostream>

/*
    Do mình thiết kế cho người dùng sử dụng nên
    không thể cho người dùng truy cập để thay đổi 
    các giá trị bên trong.
    Tính đóng gói là những Property phải khai báo ở private
    để lấy giá trị hay gán trị phải thông qua Method
*/

class ToanHoc{
    public:
        void nhapABC(); // method
        void getX1X2();
    private:
        int A; // property
        int B;
        int C;
        int X1;
        int X2;
        int getDelta();
};
