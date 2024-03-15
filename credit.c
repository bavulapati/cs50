#include <stdio.h>
#include <stdbool.h>

long long int get_number(void);
bool is_valid_card(long long int card_number);
int get_start(long long int number);
int count_digits(long long int number);
void print_brand(int start, int count);
int sum_digits(int n);

int main(void)
{
    // get credit card number
    long long int number = get_number();

    // validate the card number
    bool is_valid = is_valid_card(number); 

    // print the card provider or it's validity
    if (is_valid)
    {
        int start = get_start(number);
        int count = count_digits(number);

        print_brand(start, count);
    } else
    {
        printf("INVALID\n");
    }

}

long long int get_number(void)
{
    long long int number;
    do
    {
        printf("Number: ");
        scanf("%lli", &number);
    } while(number < 1);

    return number;
}

/*
Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
Add the sum to the sum of the digits that weren’t multiplied by 2.
If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
That’s kind of confusing, so let’s try an example with David’s Visa: 4003600000000014.

For the sake of discussion, let’s first underline every other digit, starting with the number’s second-to-last digit:

4003600000000014

Okay, let’s multiply each of the underlined digits by 2:

1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

That gives us:

2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

Now let’s add those products’ digits (i.e., not the products themselves) together:

2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):

13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

Yup, the last digit in that sum (20) is a 0, so David’s card is legit!
*/
bool is_valid_card(long long int card_number)
{
    int sum = 0;
    long long int n = card_number;

    for (int i = 0; card_number > 0; i++)
    {
        int tmp = card_number % 10;
        if (i % 2 != 0)
        {
            sum += sum_digits(tmp * 2);
        } else 
        {
            sum += tmp;
        } 
        card_number = card_number / 10;
    }
    
    return (sum % 10 == 0);
}

int get_start(long long int number)
{
    while (number > 100)
    {
        number /= 10;
    }
    
    return number;
}

int count_digits(long long int n)
{
    int count = 0;

    while(n > 0)
    {
        count++;
        n = n / 10;
    }

    return count;
}

int sum_digits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

/*
All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4.
*/
void print_brand(int start, int count)
{
    if (start / 10 == 4 && (count == 13 || count == 16))
    {
        printf("VISA\n");
    } else if ((start == 34 || start == 37) && (count == 15))
    {
        printf("AMEX\n");
    } else if (start > 50 && start < 56 && count == 16)
    {
        printf("MASTERCARD\n");
    } else
    {
        printf("NONE\n");
    }
}