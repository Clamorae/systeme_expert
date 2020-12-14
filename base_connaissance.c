#include "definition.h"

KB createbasis(){
    KB newel=(KB)malloc(sizeof(ElemBC));
    return newel;
}

void addRule(Regle rule,KB base){
   if (base==NULL){
       base->head=rule;
       base->next=NULL;
   }
   else{
       while (base->next=NULL){
           base=base->next;
       }
       ElemBC *newel= malloc(sizeof(ElemBC));
       newel->head=rule;
       base->next=newel;
   }   
}

Regle firstRule(KB base){
    return base->head;
}