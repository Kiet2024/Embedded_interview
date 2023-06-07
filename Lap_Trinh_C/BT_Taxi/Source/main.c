#include <stdio.h>
#include "constant.h"
#include "taxi_fee.h"

int main()
{
    float journey;
    printf("Nhap so km: ");
    scanf("%f", &journey);
 
    printf("Gia tien taxi la: %.3f VND",taxi_Fee(journey));
    
    return 0;
}