#include <stdio.h>
#include <stdint.h>

#define TONG(a,b) a + b
#define HIEU(a,b) a - b
#define NHAN(a,b) a * b
#define CHIA(a,b) a / b

void xuatMang(int arr[], int size_arr) {
    for (int i = 0; i < size_arr; i++)
    {
        printf("%d ",arr[i]);
    }
}

void xoaPhanTuMang (int arr[], int size_arr, int n) {
    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i < size_arr; i++) {
            arr[i] = arr[i+1];
        }
        size_arr--; 
    }

}


int main() 
{
    int sum = 0;
    int array[] = {4,'-', 6, '-', '(', 5, '*', 7, ')', '=', '?'};
    //int array2[10] = {4, 6, 7, 9};
    int size_array, size_array2;
    int counter = 0;
    int count = 11;
    int soluongxoa = 0;
    int temp = 0;

    size_array = sizeof(array) / sizeof(array[0]);
    //size_array2 = sizeof(array2) / sizeof(array2[0]);

    for (int k = 0; k < size_array; k++) {
        //for (int i = 0; i < 3; i++)
        //{
            int i = 0;
            if (array[i+1] == '=' && array[i+2] == '?'){
                    break;
            }
            else if (array[i] != 0 && array[i] != '('){
                if (array[i+1] = '-'){
                    if (array[i+2] != 0){
                        sum = HIEU(array[i],array[i+2]);
                        array[i] = sum;
                        xoaPhanTuMang(array, size_array,2);
                    }
                    else if (array[i+2] == '(' ){
                        int pointer = i + 2;
                        for (int j = pointer + 1; j < size_array; j++)
                        {
                            if (array[j+1] = '*' && (array[j+3] != 0 || array[j+3] ==')'))
                            {
                                sum = NHAN(array[j],array[j+2]);
                                if (array[j + 3] == ')') {
                                    if (array[j+4] == '/' && (array[j+5] != 0) && (array[j+6] =='+' || array[j+6] == '-' || array[j+6] == '='))
                                    {
                                        sum = CHIA(sum,array[j+5]);
                                    }
                                    else if (array[j+4] == '='){
                                        break;
                                    }
                                }
                            }
             
                        }
                        array[i+2] = sum;
                        sum = HIEU(array[i],array[i+2]);
                        array[i] = sum;
                        xoaPhanTuMang(array, size_array,5);
                    }
                }
                 
            }
        //}
    }
        
        
    //xoaPhanTuMang(array2,size_array2);
    printf("\n");
    xuatMang(array, size_array);
    // printf("%d.",temp);
    // printf("\n%d\n",array[2]);
    // printf("%d\n",array[1]);

    return 0;
}