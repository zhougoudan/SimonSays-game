#include <stdio.h>
#include "simonLoad.h"
/*
 * purpose:load image from file
 * how it works:
 * how related:*/
void showSimonMove(char *filename){
    FILE *fp = fopen(filename,"r");
    if (fp == NULL){
        printf("filename error, please input correct filename\n");
        return;
    }
    char c;
    c = fgetc(fp);
    while (c != EOF){
        printf("%c",c);
        c = fgetc(fp);
    }
}