#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // This program uses the Coleman-Liau index to compute reading level:
    // 0.0588 * L - 0.296 * S - 15.8
    // where L = average # letters / 100 words
    // and S = average # sentences / 100 words

    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // I've chosen to use floats here rather than doubles to save space since
    // this equation doesn't require the precision of doubles to give an estimate of reading level.
    float L = letters / (float) words * 100;
    float S = sentences / (float) words * 100;

    float readingLevel = (0.0588 * L) - (0.296 * S) - 15.8;

    // Finally, we can output. Rounding to nearest whole num...
    readingLevel = round(readingLevel);
    if (readingLevel < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (readingLevel >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int) readingLevel);
    }
}

// Returns # of letters
int count_letters(string text)
{
    int textLength = strlen(text);
    int letterCount = 0;

    for (int i = 0; i < textLength; i++)
    {
        if (isalpha(text[i]))
        {
            letterCount++;
        }
    }
    return letterCount;
}

// Returns # of words
int count_words(string text)
{
    int textLength = strlen(text);
    int wordCount = 0;

    for (int i = 0; i < textLength; i++)
    {
        // 32 is the ASCII value for spaces
        if (text[i] == 32)
        {
            wordCount++;
        }
        else if (i == textLength - 1 && isalpha(text[i - 1]))
        {
            // If end of text and the second to final character is a letter,
            // excluding texts w/ no content from being counted towards the word count
            wordCount++;
        }
    }

    return wordCount;
}

// Returns # of sentences
int count_sentences(string text)
{
    int textLength = strlen(text);
    int sentenceCount = 0;

    for (int i = 0; i < textLength; i++)
    {
        // ASCII codes
        //  33 == "!"
        //  46 == "."
        //  63 == "?"
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            // Here we check to make sure the previous character was a letter, since all sentences
            // must include at least one letter. Excludes texts such as "  ." from being counted
            // toward sentenceCount.
            if (isalpha(text[i - 1]))
            {
                sentenceCount++;
            }
        }
    }
    return sentenceCount;
}
