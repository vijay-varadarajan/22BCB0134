#include<stdio.h>
#include<string.h>

struct Book {
    long int num;
    char name[100];
    char author[100];
    long int pages;
} books[1000];

int main(void){
    int choice = 0; static int count = 0; char author_name[100];

    while (1) {
        
        int found = 0;
        printf("MENU\n-------------------------------------\nPRESS 1.TO ADD BOOK DETAILS.\nPRESS 2.TO DISPLAY BOOK DETAILS.\nPRESS 3.TO DISPLAY BOOK OF GIVEN AUTHOR.\nPRESS 4.TO COUNT NUMBER OF BOOKS.\nPRESS 5.TO EXIT.\n-------------------------------------\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                int tmp = 0; char temp, tempname[100];
                printf("How many records do you want to add: "); scanf("%d", &tmp);
                printf("-------------------------------------\n");
                printf("Add details of %d books\n", tmp);
                printf("-------------------------------------\n");
                for (int i = count; i < count + tmp; i++){
                    printf("Enter Book No.: "); scanf("%li", &books[i].num);
                    
                    printf("Enter Book Name.: "); 
                    scanf("%c", &temp);
                    fgets(tempname, 100, stdin);
                    tempname[strcspn(tempname, "\n")] = '\0';
                    strcpy(books[i].name, tempname);

                    printf("Enter Author name: "); 
                    scanf("%c", &temp);
                    fgets(tempname, 100, stdin);
                    tempname[strcspn(tempname, "\n")] = '\0';
                    strcpy(books[i].author, tempname);
                    
                    printf("Enter No. of pages: "); scanf("%li", &books[i].pages);
                    printf("-------------------------------------\n");
                }
                
                count += tmp;
                
                if (count > 1000){
                    printf("Library max. capacity reached\n");
                    return 1;
                }
                break;
            
            case 2:
                for (int i = 0; i < count; i++){
                    printf("Book No.: %li\n", books[i].num); 
                    printf("Book Name.: %s\n", books[i].name); 
                    printf("Author name: %s\n", books[i].author); 
                    printf("No. of pages: %li\n", books[i].pages); 
                }
                break;

            case 3:
                printf("Enter name of author to search for: ");
                scanf("%c", &temp);
                fgets(tempname, 100, stdin);
                tempname[strcspn(tempname, "\n")] = '\0';
                strcpy(author_name, tempname);

                for (int i = 0; i < count; i++){
                    if (strcmp(books[i].author, author_name)){
                        printf("Book No.: %li\n", books[i].num); 
                        printf("Book Name.: %s\n", books[i].name); 
                        printf("No. of pages: %li\n", books[i].pages);
                    }
                    found ++;
                }
                break;

                if (found == 0)
                    printf("No match found");

            case 4:
                printf("No. of books: %d\n", count);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid option. Try again\n");

        } ;
    }
    return 0;
}