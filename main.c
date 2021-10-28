#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "simonLoad.h"
#include "queue.h"
#include "string.h"
#include <unistd.h>
#include "simonMove.h"
#include "menu.h"
/*
 * purpose:main
 * how it works:
 * how related:*/
int main(int argc , char* argv[]){
//    argv[1] = "command.txt";
//    argc = 2;
    LinkQueue *Q = (LinkQueue *) malloc(sizeof(LinkQueue));
    InitQueue(Q);
    if (argc == 1){
        printf("\033[;31mThe program runs without a command file\033[0m\n");
    }
    if(argc == 2){
        if(!load(argv[1],Q)){
            return 0;
        }
    } else if (argc > 2){
        printf("\033[;31mtoo many arguments\033[0m,please input commandline as follow:\n"
               "\"./Simonsays commands.txt\"\n");
        return 0;
    }
    int flag = true;
    while (flag){
        menu();
        int k;
        fflush(stdin);
        scanf("%d",&k);
        switch (k) {
            case 1:
                giveCommands(Q);
                break;
            case 2:
                if (!loadCommands(Q)){
                    return 0;
                }
                break;
            case 3:
                deleteCommands(Q);
                break;
            case 4:
                display(Q);
                break;
            case 5:
                flag = false;
                break;
        }
    }
    return 0;
}
