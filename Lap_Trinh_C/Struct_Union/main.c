#include <stdio.h>
#include <stdint.h>

typedef struct
{
    // size struct = tổng các member + bộ nhớ đệm(nếu có)
    uint16_t arr1[7];
    uint64_t arr4[5];
    uint32_t arr2[1];
    uint8_t arr3[10];

}data_struct;

typedef union
{
    /*size union = size member lớn nhất
      union là bộ nhớ dùng chung nên khi thay đổi member này sẽ ảnh hưởng đến
      member khác
    */
    uint8_t test1[6];
    uint8_t test2[2];

}data_union;
 
int main ()
{
    printf("Size struct: %lu\n", sizeof(data_struct));
    printf("Size union: %lu\n", sizeof(data_union));

    data_union data;

    for (int i = 0; i < 6; i++)
    {
        data.test1[i] = i; // 0 1 2 3 4 5
    }
    
    for (int i = 0; i < 3 ; i++)
    {
        data.test2[i] = 2*i; // 0 2 4 
    }
    
    for (int i = 0; i < 6; i++)
    {
        printf("%d ",data.test1[i]);
    }
    return 0;
}
