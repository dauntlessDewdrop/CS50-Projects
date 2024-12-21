#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Saves a string value "name" from the user
    string name = get_string("What is your name? ");

    // Prints "name" in format "hello, [name]" along with appending to a new line
    printf("hello, %s\n", name);
}
