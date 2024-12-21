#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // vote() takes in a string "name" as entered by the user as a vote.
    // A loop iterates through and compares each value of candidates[] to name, case sensitively.
    // If a match is found, increment candidates[i].votes by 1 and return true.
    // Else, return false. The vote is invalid in this case.

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // This function compares each of the .votes values of the candidates and prints the winner(s).
    // Potentially, the amount of winners could be as high as the candidate_count if every
    // candidate has a tie. So, the string array winners[] accounts for this.
    int most_votes = 0;

    // This first iteration finds the highest amount of votes.
    for (int i = 0; i < candidate_count; i++)
    {
        if (most_votes < candidates[i].votes)
        {
            most_votes = candidates[i].votes;
        }
    }

    // A second iteration then recursively prints each candidate.name with votes == most_votes.
    for (int i = 0; i < candidate_count; i++)
    {
        if (most_votes == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}
