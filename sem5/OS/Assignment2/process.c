#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <stdbool.h>
#include <sys/wait.h>

int main() {
    while(true) {
        if (fork() == 0){
            printf("Child performed %d\n", getpid());
            return 0;
        } else {
            printf("Im parent %d\n", getpid());
            sleep(5);
        }
    }
}
