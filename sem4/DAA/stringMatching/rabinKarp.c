// implementation of rabin karp algorithm for string matching
// take ascii values of each character and concatenate

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define d 256 // number of characters in the input alphabet

void rabinKarpStringMatching(char *text, char *pattern, int prime)
{
    int M = strlen(pattern);
    int N = strlen(text);
    char asciiPattern[M * 4 + 1];
    char asciiText[N * 4 + 1];
    asciiPattern[0] = '\0';
    asciiText[0] = '\0';

    for (int i = 0; i < M; i++){
        char tempPattern[4]; 
        sprintf(tempPattern, "%d", (int)pattern[i]);
        strcat(asciiPattern, tempPattern);
    }
    
    for (int i = 0; i < N; i++){
        char tempText[4];
        sprintf(tempText, "%d", (int)text[i]);
        strcat(asciiText, tempText);
    }

    long long int asciPattern = atoll(asciiPattern);

    printf("Pattern: %lld\n", asciPattern);
    int value = asciPattern % prime;
    printf("Pattern modulus prime: %d\n", value);

    int P = strlen(asciiPattern);
    int Q = strlen(asciiText);
    int modArray[Q - P + 1];
    int index = -1;
    int spuriousHits = 0;
    int SpuriousIndex[Q - P + 1];

    for(int i = 0; i < Q - P + 1; i++){
        char tempText[M * 4 + 1];
        tempText[0] = '\0';
        for(int j = 0; j < P; j++){
            char temp;
            temp = asciiText[i + j];
            strncat(tempText, &temp, 1);
        }
        modArray[i] = atoll(tempText) % prime;

        if (modArray[i] == value){
            if (index == -1){
                index = i;
            } else {
                spuriousHits++;
                SpuriousIndex[spuriousHits] = i;
            }
        }
    }

    printf("Mod Array: ");
    for(int i = 0; i < Q - P + 1; i++){
        printf("%d ", modArray[i]);
    }

    if (index != -1){
        printf("\nPattern found at index: %d\n", index);
        if (spuriousHits > 0){
            printf("Spurious hits at index: ");
            for(int i = 1; i <= spuriousHits; i++){
                printf("%d ", SpuriousIndex[i]);
            }
        }
    } else {
        printf("\nPattern not found\n");
    }

}

int main()
{
    // get user input for text and pattern
    char text[100], pattern[100];
    int q;
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);
    printf("Enter the value of q: ");
    scanf("%d", &q);

    rabinKarpStringMatching(text, pattern, q);
    return 0;
}