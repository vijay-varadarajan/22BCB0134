// naive approach to string matching

#include <stdio.h>
#include <string.h>

void naiveStringMatching(char *text, char *pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);

    int found = 0;
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
        {
            printf("Pattern found starts from index %d [%d to %d]\n", i, i, i+m-1);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Pattern not found.\n");
    }

    return;
}

int main()
{
    // get user input for text and pattern
    char text[100], pattern[100];

    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    naiveStringMatching(text, pattern);
    return 0;
}