#include <stdio.h>

int get_cents(void);
int calculate_coins(int cents);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);

int main(void)
{
    // get the amount
    int cents = get_cents();

    // calculate the number of coins (25, 10, 5, 1)
    int coins = calculate_coins(cents);

    // print the number of coins needed to be dispensed
    printf("%i\n", coins);
}

int get_cents(void)
{
    // amount should be integer greater than or equal to 0
    int cents;
    do
    {
        printf("Change owned: ");
        scanf("%i", &cents);
    } while(cents < 0);
}

int calculate_coins(int cents)
{
    int coins = 0;
    // calculate number of 25c coins
    int quarters = calculate_quarters(cents);

    coins += quarters;
    cents -= quarters * 25;

    // calculate number of 10c coins
    int dimes = calculate_dimes(cents);

    coins += dimes;
    cents -= dimes * 10;

    // calculate number of 5c coins
    int nickels = calculate_nickels(cents);

    coins += nickels;
    cents -= nickels * 5;

    // calculate number of 1c coins
    coins += cents;

    return coins;
}

int calculate_quarters(int cents)
{
    int quarters = cents / 25;
    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = cents / 10;
    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels = cents / 5;
    return nickels;
}