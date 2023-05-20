#include <stdio.h>
#include <stdint.h>

struct typeDate
{
    uint16_t arr1[7];
    uint64_t arr4[5];
    uint32_t arr2[1];
    uint8_t arr3[10];
   


};

int main ()
{
    printf("Size: %lu", sizeof(struct typeDate));
    return 0;
}
