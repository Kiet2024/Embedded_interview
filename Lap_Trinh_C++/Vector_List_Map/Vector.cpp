#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<int> array;
    array.push_back(4);
    array.push_back(8);
    array.push_back(20);
    array.push_back(15);

    // chèn giá trị vị trí thứ 2
    // array.begin() là vị trí thứ 0
    array.insert(array.begin() + 2,77);
    array.pop_back(); // xóa phần tử cuối cùng của mảng
    // array.size() : trả về kích thước mảng
    
    
    // biến auto xem data là giá trị gì để xác định kiểu dữ liệu của nó
    for (auto item : array)
    {
        printf("%d\n",item);
    }
    
}