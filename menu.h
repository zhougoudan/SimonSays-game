#ifndef SIMON_MENU_H
#define SIMON_MENU_H
#include "queue.h"
#include "string.h"
#include "simonMove.h"
void menu();
bool load(char *filename, LinkQueue *Q);
bool loadCommands(LinkQueue *Q);
void giveCommands(LinkQueue *Q);
void deleteCommands(LinkQueue *Q);
void fucPointer(ElemType *e);
void display(LinkQueue *Q);
#endif //SIMON_MENU_H
