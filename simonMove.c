#include "simonMove.h"
#include "simonLoad.h"
#include <unistd.h>
#include "stdio.h"
/*
 * purpose:dance
 * how it works:
 * how related:*/
void dance(){
    showSimonMove("dance1");
    sleep(1);
    printf("\033[2J\n") ;
    printf("dancing.....\n");
    showSimonMove("simon");
    sleep(1);
    printf("\033[2J\n") ;
    printf("dancing.....\n");
    showSimonMove("dance2");
    sleep(1);
    printf("\033[2J\n") ;
    showSimonMove("simon");
}
/*
 * purpose:shake
 * how it works:
 * how related:*/
void shake(){
    showSimonMove("shake1");
    sleep(1);
    printf("\033[2J\n") ;
    showSimonMove("simon");
    sleep(1);
    printf("\033[2J\n") ;
    showSimonMove("shake2");
    sleep(1);
    printf("\033[2J\n") ;
    showSimonMove("simon");
}
/*
 * purpose:shrug
 * how it works:
 * how related:*/
void shrug(){
    showSimonMove("shrug");
    sleep(4);
    printf("\033[2J\n") ;
    showSimonMove("simon");
    sleep(2);
}
/*
 * purpose:hand on head
 * how it works:
 * how related:*/
void head(){
    showSimonMove("head");
    sleep(4);
    printf("\033[2J\n") ;
    showSimonMove("simon");
    sleep(2);
}
/*
 * purpose:left hand up
 * how it works:
 * how related:*/
void leftHand(){
    showSimonMove("leftHand");
    sleep(4);
    printf("\033[2J\n") ;
    showSimonMove("simon");
    sleep(2);
}
/*
 * purpose:right hand up
 * how it works:
 * how related:*/
void rightHand(){
    showSimonMove("rightHand");
    sleep(4);
    printf("\033[2J\n") ;
    showSimonMove("simon");
    sleep(2);
}
/*
 * purpose:stand
 * how it works:
 * how related:*/
void stand(){
    showSimonMove("simon");
    sleep(4);
}