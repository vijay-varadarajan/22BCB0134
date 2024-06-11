#include <stdio.h>
#include <string.h>

#define d 256

void removeSpaces(char str[])
{
    int count = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] != ' ')
            str[count++] = str[i];
    }
    str[count] = '\0';
}

void search(char pattern[], char text[], int q)
{
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;

    // Initialize variables
    int p = 0;
    int t = 0;
    int h = 1;
    
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    
    for (i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            for (j = 0; j < M; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == M){
                printf("The given pattern is present in the String \n");
                return ;
            }
        }

        if (i < N - M)
        {
            t = (d * (t - text[i] * h) + text[i + M]) % q;

            if (t < 0)
                t = (t + q);
        }
    }

    if (i > N - M)
        printf("The given pattern is not present in the String\n");
}


int main()
{
    char text[1000], pattern[100];
    int q = 101;

    printf("Enter the text: ");
    scanf("%[^\n]s", text);
    getchar();

    printf("Enter the pattern to search: ");
    scanf("%[^\n]s", pattern);
    getchar();

    removeSpaces(text);
    removeSpaces(pattern);

    search(pattern, text, q);
    return 0;
}

