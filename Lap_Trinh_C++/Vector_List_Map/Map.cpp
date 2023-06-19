#include <iostream>
#include <map>
#include <string>

using namespace std;


int main()
{
    // map<string, int> SinhVien;

    // SinhVien["ID"] = 101;
    // SinhVien["LOP"] = 7;
    // SinhVien["TUOI"] = 15;

    map<string, string> SinhVien;

    SinhVien["TEN"] = "KIET" ;
    SinhVien["TUOI"] = "7";
    SinhVien["LOP"] = "15";

    for (auto item :  SinhVien)
    {
        //printf("Key : %s, value: %d\n", item.first.c_str(), item.second);
        cout<<"Key :"<<item.first<<","<<"Value: "<<item.second<<endl;
    }
    
}