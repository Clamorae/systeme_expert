#include"base_connaissance.h"

KB createbasis(){
    KB newel=(KB)malloc(sizeof(ElemBC));
    return newel;
}

void addruletoBC(KB base){
   Regle* rule=createRule();
   if (base->head==NULL){
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
   char strbuffer[255];
   do{
       printf("Entrez une proposition\n");
       scanf("%s",strbuffer);//fgets(strbuffer,255,stdin);
       addProp(rule, strbuffer);
       printf("Que souhaitez vous faire avec cette nouvelle régle?\n\n");
       printf("1 - Entrez une nouvelle proposition\n");
       printf("2 - Entrez une conclusion et retourner au menu principal\n");
       scanf("%d",&menu);
   } while (menu!=2);
   createConclusion(rule);
   printf("Va manger tes mort et ecris une super conclusion trop cool\n");
   scanf("%s",strbuffer);
   strcpy(rule->conclusion,strbuffer);
}

Regle* firstRule(KB base){
    return base->head;
}
