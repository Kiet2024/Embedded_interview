#include <iostream>

namespace ConOngA{
    int A = 10;
    int B = 10;
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
}

namespace ConOngB{
    int A = 20;
}
/*
    Chỉ được sử dụng khi chỉ có 1 namespace và các biến trong namespace này 
    không trùng với namspace khác.
*/
using namespace ConOngA;  
//using namespace ConOngB; // do nó trùng biến A nên khi gọi A nó sẽ không biết lấy namspace nào
int main()
{
    printf("A = %d\n",A);
    printf("A = %d\n",ConOngB::A);
}
