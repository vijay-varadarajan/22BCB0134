#include <stdio.h>

int sol (char *s, char* t) {
    if (s == NULL || t == NULL) {
        return -1;
    }

    int count = 0;
    int total = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        total++;
    }

    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] > t[i]) {
            char temp = s[i];
            s[i] = t[i];
            t[i] = temp;

            count++;
        }
    }
    
    if (count > total / 2){
        count = total - count;
    }

    return count;
}

int main() {
    char s[] = "91919";
    char t[] = "19191";
    int count = sol(s, t);
    printf("%d\n", count);
    return 0;
}

