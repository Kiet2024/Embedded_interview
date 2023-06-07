#include "taxi_fee.h"
#include "constant.h"

float taxi_Fee (const float journey) {
    float taxi_Fee = 0 ;
    if (journey < JOURNEY_1) {
        taxi_Fee = PRICE_1;
    }
    else if (journey >= JOURNEY_1 && journey <= JOURNEY_2) {
        taxi_Fee = PRICE_1 + (journey - 1)*PRICE_2;
    }
    else {
        taxi_Fee = PRICE_1 + (journey - (journey - 30) - 1)*PRICE_2 + (journey-30)*PRICE_3;
    }

    return taxi_Fee;
}