#include <stdio.h>
#include <string.h>

// constuct structure for a player
struct Player {
    char name[50];
    float bat_avg;
    float bowl_avg;
};

int main(void)
{
    int n; float bat_total = 0.0, bowl_total = 0.0; char temp, tmpname[50];
    printf("Enter number of players: "); scanf("%d", &n); // get number of player
    if (n < 0)
    {
        printf("Invalid input! Please provide a positive integer.");
        return 1;
    }

    struct Player players[n]; // array of players structure for n players

    printf("\n");
    for (int i = 0; i < n; i++) // get details and store it in players array
    {
        printf("\nEnter details for player %d: ", i + 1);

        printf("\nName: ");
        scanf("%c", &temp);
	    fgets(tmpname,50,stdin);
        tmpname[strcspn(tmpname, "\n")] = '\0';
        strcpy(players[i].name, tmpname);

        printf("Batting average: ");
        scanf("%f", &players[i].bat_avg);
        bat_total += players[i].bat_avg; // increment batting total

        printf("Bowling average: ");
        scanf("%f", &players[i].bowl_avg);
        bowl_total += players[i].bowl_avg; // increment bowling total
    }

    // print obtained details
    printf("Player name Batting average Bowling average\n -----------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\b\t%.2f\t%.2f\n", players[i].name, players[i].bat_avg, players[i].bowl_avg);
    }

    // display totals and averages
    printf("\nTotal players: %d", n);
    printf("\nTeam batting average: %.2f", bat_total / n);
    printf("\nTeam bowling average: %.2f", bowl_total / n);
}
