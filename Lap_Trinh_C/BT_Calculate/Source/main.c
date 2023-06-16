#include <stdio.h>
#include <stdint.h>

int SUM(int input_1, int input_2) {
    return input_1 + input_2;
}

int SUB(int input_1, int input_2) {
    return input_1 - input_2;
}

int MUL(int input_1, int input_2) {
    return input_1 * input_2;
}

int DIV(int input_1, int input_2) {
    return (float)input_1 / input_2;
}

typedef enum{
    NUMBER,
    OPERATOR,
}TypeMath;

typedef struct{
    TypeMath key;
    union 
    {
        uint16_t number;
        char operator; 
    }value;
}typeMaths;

void stringToDec( char input[], typeMaths output[]) {
    uint16_t number = 0;
    uint8_t i = 0;

    while (*input != '\0')
    {
        if (*input >= '0' && *input <= '9') {
            uint8_t temp = *input - '0';
            number = 10 * number + temp;
            input++;
            continue;
        }
        else if (*input == '+' || *input == '-' ||
                *input == '*' || *input == '/' ){
            output[i].key = OPERATOR;
            output[i].value.operator = *input;
            i++;
            input++;
            continue;

        }
        else{
            if(number != 0) {
                output[i].key = NUMBER;
                output[i].value.number = number;
                number = 0;
                i++;
            }
        }
        input++;
        
    }
    output[i].key = NUMBER;
    output[i].value.number = number;
}

int main ()
{
    char input[] = "10 + 8 - 614 + 7 - 532 * 2";
    typeMaths output[20];
    stringToDec(input, output);
    int sum = 0;

    for (int i = 0; i < 20; i++){
        if (output[i].value.operator == '*'){
            sum = MUL(output[i + 1].value.number, output[i -1].value.number);
            output[i-1].key = NUMBER;
            output[i-1].value.number = sum;
            output[i+1].value.number = 0;
            output[i].value.operator = 0;
            sum = 0;
        }

    }

    
    for (int i = 0; i < 20; i++){
        if (output[i].value.operator == '+'){
            sum = sum + SUM(output[i + 1].value.number, output[i -1].value.number);
            output[i+1].key = NUMBER;
            output[i+1].value.number = sum;
            output[i-1].value.number = 0;
            output[i].value.operator = 0;
            
        }
        else{
            sum = sum + SUB(output[i + 1].value.number, output[i -1].value.number);
            output[i+1].key = NUMBER;
            output[i+1].value.number = sum;
            output[i].value.operator = 0;
        }

    }

    for (int i = 0; i < 20; i++)
    {
        if (output[i].key == NUMBER)
        {
            printf("\nNUMBER %d",output[i].value.number);
        }
        else if (output[i].key == OPERATOR){
            printf("\nOPERATION %c",output[i].value.operator);
        }
        
    }
    

    printf("\n%d",sum);
    return 0;
}