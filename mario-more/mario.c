#include <cs50.h>
#include <stdio.h>

void lAlignPyra(int height);
void rAlignPyra(int height);
void doublePyra(int height);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // lAlignPyra(height);
    // rAlignPyra(height);

    doublePyra(height);
}

// Prints a left-aligned pyramid with "#" characters
void lAlignPyra(int height)
{
    int row;
    // A nested loop uses "row" to keep track of the row to print to while
    // using "height" to configure the height of the pyramid.
    for (row = 1; row < height + 1; row++)
    {
        for (int i = 0; i < row; i++)
            printf("#");
        printf("\n");
    }
}

// Prints a right-aligned pyramid with "#" characters
void rAlignPyra(int height)
{
    int row;
    // The first "for" cycles through the rows to print to
    for (row = 1; row < height + 1; row++)
    {
        // Next, the second "for" loop prints spaces...
        for (int i = 0; i < height - row; i++)
            printf(" ");
        // ... While the third loop prints the "#" character
        for (int i = 0; i < row; i++)
            printf("#");
        printf("\n");
    }
}

// Prints a right aligned pyramid followed by a left aligned pyramid.
void doublePyra(int height)
{
    int row;
    // The first "for" cycles through the rows to print to
    for (row = 1; row < height + 1; row++)
    {
        // The first two "for" loops handle the right-aligned pyramid
        for (int i = 0; i < height - row; i++)
            printf(" ");
        for (int i = 0; i < row; i++)
            printf("#");
        printf("  ");

        // This loop handles the left aligned pyramid
        for (int i = 0; i < row; i++)
            printf("#");
        printf("\n");
    }
}
