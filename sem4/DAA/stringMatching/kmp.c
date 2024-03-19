#include <stdio.h>
#include <string.h>

void findLPS(char* pattern, int M, int* lps);
void KMP(char* pattern, char* txt);


int main()
{
    char txt[100];
    printf("Enter the text: ");
    scanf("%s", txt);

    char pattern[50];
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    KMP(pattern, txt);
    return 0;
}
 

void KMP(char* pattern, char* txt)
{
    int M = strlen(pattern);
    int N = strlen(txt);
    int found = 0;

    int lps[M];

    findLPS(pattern, M, lps);
    printf("Pattern found at: \n");
 
    int i = 0, j = 0;
    while ((N - i) >= (M - j)) {
        if (pattern[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            printf("Index %d\n", i - j);
            found = 1;
            j = lps[j - 1];
        }
 
        else if (i < N && pattern[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    if (!found) {
        printf("Pattern not found.\n");
    }
}
 

void findLPS(char* pattern, int M, int* lps)
{
    int len = 0;
 
    lps[0] = 0;
 
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 
