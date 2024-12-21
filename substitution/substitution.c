#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check that there are exactly 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check that there are exactly 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // hasLetter is an array of booleans containing... 26 values! One for each letter.
    // Tracks whether or not the key entered already contains the character corresponding
    // to the boolean array index. Every value is set to "0" or "false" by default.
    bool hasLetter[26];
    for (int i = 0; i < 26; i++)
    {
        hasLetter[i] = false;
    }

    int finalKey[26];
    for (int i = 0; i < 26; i++)
    {
        // Convert to uppercase, just in case!
        argv[1][i] = toupper(argv[1][i]);

        // Check that all 26 characters are alphabetical
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetical characters.\n");
            return 1;
        }

        // Check that all 26 characters do not repeat...
        // finalKey is also assigned for later computations
        finalKey[i] = argv[1][i];
        if (hasLetter[finalKey[i] - 65])
        {
            printf("Key must not contain duplicate characters.\n");
            return 1;
        }
        else
        {
            hasLetter[finalKey[i] - 65] = true;
        }
    }

    // Finally, we may prompt the user for info after ensuring the
    // key has been entered correctly.
    string plaintext = get_string("plaintext: ");
    string ciphertext = plaintext;
    int textLength = strlen(plaintext);

    for (int i = 0; i < textLength; i++)
    {
        if (isalpha(plaintext[i]))
        {
            // Here is where we individually convert each char using finalKey and the plaintext.
            // If statement checks if lowercase or not
            if (islower(plaintext[i]))
            {
                ciphertext[i] = finalKey[plaintext[i] - 97];
                ciphertext[i] = tolower(ciphertext[i]);
            }
            else
            {
                ciphertext[i] = finalKey[plaintext[i] - 65];
            }
        }
    }

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
