#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validate_email(char* email) {

    int len = strlen(email);
    
    // Check if email contains exactly one @ character
    int at_count = 0;
    for(int i = 0; i < strlen(email); i++) {
        if(!isalnum(email[i]) && email[i] != '-' && email[i] != '.' && email[i] != '@')
            return 0; 
        if(email[i] == '@')
            at_count++;
    }
    if(at_count != 1)
        return 0;

    // Get the part of email address before @ and after @
    char* username = strtok(email, "@");
    char* at_ptr = strtok(NULL, "@");
    
    // Check length of the part of email address before @ and after @
    if(strlen(username) < 1 || strlen(username) > 64)
        return 0;
    if(strlen(at_ptr) < 1 || strlen(at_ptr) > 255)
        return 0;

    // get the domain of the email address (last four characters)
    char* domain = email + len - 4;

    // Check if domain has a valid top-level domain
    char* valid_domains[] = {".com", ".org", ".net", ".edu"};
    int valid_domain = 0;
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(valid_domains[i], domain) == 0)
        {
            valid_domain =  1;
            break;
        }
    }
    return valid_domain; // returns 1 if domain is valid else returns 0

}

int main(void) 
{
    char email[321];
    printf("Enter your email address: ");
    scanf("%s", email);
    if(validate_email(email) == 1)
        printf("\nLogin successful\n");
    else
        printf("\nInvalid email address\n");
    return 0;
}
