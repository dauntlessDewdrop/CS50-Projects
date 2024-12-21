#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // pointList assumes alphabetical order to assign point values - A = pointList[0], while Z =
    // pointList[25]
    int pointList[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                         1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    string answers[2];
    answers[0] = get_string("Player 1: ");
    answers[1] = get_string("Player 2: ");

    int points[2] = {0, 0};

    // 2 here is the size of the points array, AKA # of players
    for (int x = 0; x < 2; x++)
    {
        int length = strlen(answers[x]);
        for (int i = 0; i < length; i++)
        {
            answers[x][i] = tolower(answers[x][i]);
            int valOfChar = answers[x][i] - 97;
            if (valOfChar < 0 || valOfChar > 25)
            {
                // "Continue" here skips the incrementation of the player points if
                // the char value is not a letter (e.g. "!", ">", "%", etc.)
                continue;
            }

            points[x] += pointList[valOfChar];
        }
    }

    // If statement finally checks who won based on recorded points.
    if (points[0] > points[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (points[1] > points[0])
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
