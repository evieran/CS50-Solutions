#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;

    // Iterate over each character in the input word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Convert the character to uppercase (if it's a letter)
        char letter = toupper(word[i]);

        // Check if the character is an alphabetic letter
        if (isalpha(letter))
        {
            // Calculate the score of this letter
            // Substract 'A' from lettet to get index (0 for A/A, 1 for B/b),
            score += POINTS[letter - 'A'];
        }
    }

    return score;
}
