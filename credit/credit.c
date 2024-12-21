#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    long cardNum = get_long("Number: ");

    string cardType;
    int validCard = false;
    int currentDigit;

    int sum1 = 0;
    int sum2 = 0;

    char str[20];
    sprintf(str, "%ld", cardNum);

    const int numLength = (strlen(str));

    // For testing purposes:
    // printf("numLength == %i\n", numLength);

    // Recurs through the digits, taking action depending on whether the digitPlace is even or odd
    // Counts first decimal place as place "0"
    for (int digitPlace = 0; digitPlace < numLength; digitPlace++)
    {
        // Return the value of digitPlace
        currentDigit = (cardNum / (long) pow(10, digitPlace)) % 10;
        // If the digitPlace % 2 == 1, then apply logic for multiplying
        if (digitPlace % 2 == 1)
        {
            currentDigit *= 2;

            if (currentDigit > 9)
            {
                // Add first digit
                sum1 += currentDigit % 10;
                // Add second digit
                sum1 += currentDigit / 10;
            }
            else
            {
                sum1 += currentDigit;
            }
        }
        else // if dealing with a digit that should NOT be multiplied?
        {
            sum2 += currentDigit;
        }
    }

    // Now we have all the values! Test the checkSum!
    string result = "INVALID\n";
    // printf("Sum1 = %i\nSum2 = %i\n", sum1, sum2);

    sum1 += sum2;
    // printf("checkSum = %i\n", sum1);
    // If validCard checksum?
    if (sum1 % 10 == 0)
    {
        // Record the first two digits of the card
        int startDigits = cardNum / (pow(10, numLength - 2));

        // Check if AMEX?
        if (numLength == 15)
        {
            if (startDigits == 34 || startDigits == 37)
            {
                result = "AMEX\n";
            }
        }
        // Check if MASTERCARD?
        else if (numLength == 16 && startDigits / 10 == 5)
        {
            if (startDigits % 10 <= 5)
            {
                result = "MASTERCARD\n";
            }
        }
        // Check if VISA?
        else if ((numLength == 13 || numLength == 16) && startDigits / 10 == 4)
        {
            result = "VISA\n";
        }

        // printf("Starting digits: %i\n", startDigits);
    }

    // Finally, print the result!
    printf("%s", result);
}

/*
    How does the following algorithm work?
        currentDigit = (cardNum / (long) pow(10, digitPlace)) % 10;

    The equation divides the user inputted card number, "cardNum" by 10 to the power
    of the the current digit place, "digitPlace". This effectively "erases" all valus
    to the right of the digit place you're looking to return via truncation.

    Next, the remaining value is then reduced modulus 10 in order to return the
    value of the integer at the digitPlace.

    It should be mentioned that "digitPlace" is synonymous to the "i" value
    commonly used in "for" loops. It allows us to individually target
    each place in the decimal value given by the user.
*/
