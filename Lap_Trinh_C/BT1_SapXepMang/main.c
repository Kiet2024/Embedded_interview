#include <stdio.h>
#include <stdint.h>

void SortList(uint8_t array[], int size_array){
    uint8_t temp;
    for (int i = 0; i < size_array -1; i++)
    {
        int min_array = i;
        for (int j = i + 1; j < size_array; j++)
        {
            if (array[j] < array[min_array])
            {
                min_array = j;
            }
            
        }
        temp = array[i];
        array[i] = array[min_array];
        array[min_array] = temp;  
    }
}

void DemPhanTu(uint8_t array[], uint8_t size_array){
    int count[10000] ={0};
    for (int i = 0; i < size_array; i++)
    {
        count[array[i]]++;
    }

    for (int i = 0; i < 10000; i++)
    {
        if (count[i] > 0)
        {
            printf("%d xuat hien %d lan\n",i, count[i]);
        }
    } 
}

void XuatMang(uint8_t array[], uint8_t size_array){
    printf("Mang sap xep tang dan: ");
    for (int i = 0; i < size_array ; i++)
    {
        printf("%d ",array[i]);
    }

}


int main()
{
    uint8_t array[] = {1, 3, 5, 3, 4, 7, 4, 9, 6, 2, 8, 7};
    uint8_t size_array ;
    size_array = sizeof(array)/ sizeof(array[0]);

    SortList(array, size_array);
    XuatMang(array,size_array);
    printf("\n");
    DemPhanTu(array,size_array);
    
 
}