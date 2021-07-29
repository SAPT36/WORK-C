#include <stdio.h>
#include <math.h>  

int main(void)
{
    double principal; // starting principal
    double rate; // annual interest rate
    unsigned int year;

    printf("please enter principal,year and rate\n");

    scanf("%lf", &principal);
    scanf("%u", &year);
    scanf("%lf", &rate);
    // output table column heads
    printf("%4s%21s\n", "Year", "Amount on deposit");
    // calculate amount on deposit for each of ten years
    if ( year != -1) {

        // calculate new amount for specified year
        double amount = principal * pow(1.0 + rate, year);
        // output one table row
        printf("%4u%21.2lf\n", year, amount);

    }
}


