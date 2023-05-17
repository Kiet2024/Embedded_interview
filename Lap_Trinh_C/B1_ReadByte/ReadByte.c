#include <stdio.h>
#include <stdint.h>

void readByte(uint8_t byte){
    uint8_t temp = 0b10000000;
    printf("0b");
    for (int i = 0; i < 8; i++)
    {
        printf("%d",(byte & temp)?1:0);
        byte = byte << 1; 
    }
}

int main()
{
    uint8_t test = 0b10010011;
    readByte(test);
    return 0;
}