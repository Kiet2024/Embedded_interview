#include <iostream>

/*
     Những tính toán phức tạp để có thể giải ra được bài toán,... sẽ nằm ở phần private(bên trong)
      Còn cái đơn giản như nhập và xuất dữ liệu ở public( phía người dùng hay bên ngoài).Để người dùng không thể
     truy cập vào các chương trình tính toán phức tạp bên trong.

*/
class ToanHoc{
    public:
        void nhapABC();
        void getX1X2();
    private:
        int getDelta();
};
