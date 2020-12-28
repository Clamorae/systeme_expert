#include "base_connaissance.h"
#include "definition.h"
#include <stdio.h>
#include <stdlib.h>

KB createbasis(){
    KB newel=(KB)malloc(sizeof(ElemBC));
    return newel;
}

void addRule(KB base){
   Regle* rule=createRule();
   if (base==NULL){
       base->head=rule;
       base->next=NULL;
   }
   else{
       while (base->next!=NULL){
           base=base->next;
       }
       ElemBC *newel= malloc(sizeof(ElemBC));
       newel->head=rule;
       base->next=newel;
   }
   int menu;
   char* strbuffer;
   do{
       printf("Entrez une proposition\n");
       gets(strbuffer);
       addProp(rule, strbuffer);
       printf("Que souhaitez vous faire avec cette nouvelle régle?\n\n");
       printf("1 - Entrez une nouvelle proposition\n");
       printf("2 - Entrez une conclusion et retourner au menu principal\n");
       scanf("%d",&menu);
   } while (menu!=2);
   
}

Regle* firstRule(KB base){
    return base->head;
}
