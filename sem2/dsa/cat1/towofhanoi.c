#include <stdio.h>

void ToH(int n, char a, char b, char c);

int main(void)
{
    ToH(3, 'A', 'B', 'C');
}

void ToH(int n, char a, char b, char c)
{
    if (n > 0)
    {
        ToH((n - 1), a, c, b);
        printf("Move disk %d from %c to %c\n", n, a, c);
        ToH((n - 1), b, a, c);
    }
}


/* 
    A L G O R I T H M
n = 1: move 1 disk from A to C

n = 2: move 2 disks from A to C using B 
               - move 1 disk from A to B
               - move 1 disk from A to C
               - move 1 disk from B to C

n = 3: move 2 disks from A to B using C
              - move 1 disk from A to B
              - move 1 disk from A to C   
              - move 1 disk from B to C
        move 1 disk from A to C
        move 2 disks from B to C using A
              - move 1 disk from B to A
              - move 1 disk from B to C
              - move 1 disk from A to C
 
n = n:
        move (n-1) disks from A to B using C
        move 1 disk from A to C
        move (n-1) disk from B to C using A
*/


