#include <stdio.h>

extern int count; 
extern void dem();
int main ()
{
    printf("count: %d\n",count);
    dem();
    dem();

    return 0;
    
}