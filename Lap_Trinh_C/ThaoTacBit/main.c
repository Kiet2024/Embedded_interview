#include <stdio.h>
#include <stdint.h>

uint8_t PORTA = 0b00000000;
uint8_t PORTB = 0b11111111;
uint8_t PORTC = 0b10101011;

void readByte(uint8_t byte){
    uint8_t temp = 0b10000000; 
    printf("0b");
    for (int i = 0; i < 8; i++)
    {
        printf("%d",(byte & temp)?1:0); 
        byte = byte << 1; 
    }
    printf("\n");
}

typedef enum{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}s_pins;

typedef enum{
    LOW,
    HIGH
}s_status;


void pinHigh(s_pins pin){
    PORTA = PORTA | (0b10000000 >> pin);
}

void pinLow(s_pins pin){
    PORTB = PORTB & ~(0b10000000 >> pin);
}

void digitalWrite(s_pins pin, s_status status){
    if (status == 1){
        PORTC = PORTC | (0b10000000 >> pin);
    }
    else{
        PORTC = PORTC & ~(0b10000000 >> pin);
    }
}

int main()
{
    readByte(PORTC); // PORTC = 0b10101011
    digitalWrite(PIN3,HIGH);
    digitalWrite(PIN7,LOW);
    readByte(PORTC);

    // readByte(PORTA); //PORTA = 0b00000000
    // pinHigh(PIN4);
    // readByte(PORTA);

    // readByte(PORTB); //PORTB = 0b11111111
    // pinLow(PIN6);
    // readByte(PORTB);

    return 0;
}