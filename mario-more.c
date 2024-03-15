#include <stdio.h>

int get_height(void);
void print_pyramid(int height);
void print_left_row(int row, int height);
void print_right_row(int row, int height);
void print_gaps(int n);
void print_bricks(int n);


int main(void)
{
    // get height of pyramid
    int height = get_height();

    // print pyramid
    print_pyramid(height);
}

int get_height(void)
{
    // the height should be between 1 and 8, inclusive.
    int n;
    do
    {
        printf("Enter height of the pyramid: ");
        scanf("%i", &n);
    } while(n < 1 || n > 8);
    return n;
}

void print_pyramid(int height)
{
    //print height rows
    for (int i = 1; i <= height; i++)
    {
        print_left_row(i, height);
        printf("  ");
        print_right_row(i, height);
        printf("\n");
    }
}

void print_left_row(int row, int height)
{
    print_gaps(height - row);
    print_bricks(row);
}

void print_right_row(int row, int height)
{
    print_bricks(row);
    print_gaps(height - row);
}

void print_gaps(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void print_bricks(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}