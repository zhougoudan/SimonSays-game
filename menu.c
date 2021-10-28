#include "menu.h"
#include <unistd.h>
#define GameMode 1
/*
 * purpose:show the menu
 * how it works:
 * how related:*/
void menu() {
    printf("\nthe following is your command that you can choose\n"
           "enter 1 - 5 to choose your command\n"
           "1: Give Simon a command \n"
           "2: Load commands from a file \n"
           "3: Delete commands \n"
           "4: Play Simon Says \n"
           "5: Exit the application \n\n");
}
/*
 * purpose:load commands from file
 * how it works:if there is a command without "Simon says" or "Simon didn't say",function will return false
 * how related:LinkQueue ElemType,EnQueue()*/
bool load(char *filename, LinkQueue *Q){
    FILE *fp = fopen(filename,"r");
    if (fp == NULL){
        printf("\033[;31mfile don`t exist\033[0m, please input the correct filename\n");
        return false;
    }
    char CmdLine[40];
    while(fscanf(fp,"%[^\n]%*c\n",CmdLine)!=EOF)
    {
        char *a = "Simon says";
        char *b = "Simon didn't say";
        if (strstr(CmdLine,a) != NULL || strstr(CmdLine,b) != NULL){
            ElemType e;
            strcpy(e.command,CmdLine);
            fucPointer(&e);
            EnQueue(Q,e);
        } else{
            printf("\033[;31m\"%s\" format error \033[0m\nMake sure the command prefix is \"Simon says\""
                   "or \"Simon didn't say\"\n",CmdLine);
            return false;
        }
    }
    return true;
}
/*
 * purpose:give a command
 * how it works:
 * how related:LinkQueue ElemType,EnQueue()*/
void giveCommands(LinkQueue *Q){
    printf("input your command\n");
    char a[40];
    fflush(stdin);
    scanf("%[^\n]s" , a );
    ElemType e;
    strcpy(e.command,a);
    fucPointer(&e);
    EnQueue(Q,e);
    printf("\033[;32madd a command successful\033[0m\n");
}
/*
 * purpose:load commands
 * how it works:
 * how related:LinkQueue ElemType,load(),EnQueue()*/
bool loadCommands(LinkQueue *Q){
    printf("please input command file name\n");
    char filename[40];
    scanf("%s",filename);
    if (load(filename,Q)){
        printf("\033[;32mload file successful!\033[0m\n");
        return true;
    } else{
        printf("\033[;33mload file fail!\033[0m\n");
        return false;
    }

}
/*
 * purpose:delete commands
 * how it works:
 * how related:LinkQueue ElemType,DeQueue()*/
void deleteCommands(LinkQueue *Q){
    printf("Please input the number of commands you want to delete");
    int a;
    scanf("%d",&a);
    ElemType e;
    for (int i = 0; i < a; ++i) {
        DeQueue(Q,&e);
    }
    printf("\033[;32mdelete %d commands successful!\033[0m\n",a);
}
/*
 * purpose:Make each function pointer in the queue point to the corresponding function
 * how it works:Using conditional compilation and if else
 * how related:LinkQueue ElemType*/
void fucPointer(ElemType *e){
#if (GameMode == 1)
    if(strstr(e->command,"Simon says") != NULL){
        if (strstr(e->command,"right hand up") != NULL){
            e->p = rightHand;
        } else if (strstr(e->command,"left hand up") != NULL){
            e->p = leftHand;
        } else if (strstr(e->command,"hands on head") != NULL){
            e->p = head;
        } else if (strstr(e->command,"dance") != NULL){
            e->p = dance;
        } else{
            e->p = shrug;
        }
    } else if(strstr(e->command,"Simon didn't say") != NULL){
        e->p = stand;
    } else{
        e->p = shake;
    }
#else
    if (strstr(e->command,"right hand up") != NULL){
            e->p = rightHand;
        } else if (strstr(e->command,"left hand up") != NULL){
            e->p = leftHand;
        } else if (strstr(e->command,"hands on head") != NULL){
            e->p = head;
        } else if (strstr(e->command,"dance") != NULL){
            e->p = dance;
        } else{
            e->p = shrug;
        }
#endif
}
/*
 * purpose:display all commands in queue
 * how it works:Use the while loop to get each command and use the function pointer to do the corresponding action
 * how related:LinkQueue ElemType,DeQueue()*/
void display(LinkQueue *Q){
    FILE *fp = fopen("log.txt","a");
    while (!Empty(Q)){
        ElemType e;
        DeQueue(Q,&e);
        printf("%s\n\n\n",e.command);
        fprintf(fp,"%s",e.command);
        (*(e.p))();
        sleep(2);
        printf("\033[2J\n") ;
    }
    fclose(fp);
}