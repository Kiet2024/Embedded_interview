#include <iostream>
#include <list>

using namespace std;


int main()
{
    list<int> array;
    array.push_back(4);
    array.push_back(8);
    array.push_back(20);
    array.push_back(15);

    // biến auto xem data là giá trị gì để xác định kiểu dữ liệu của nó
    for (auto item : array)
    {
        printf("%d\n",item);
    }
    
}