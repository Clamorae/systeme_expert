#include "BC.h"

void afficheBC(KB BC){
    int i = 1;
    while (BC!=NULL){
        printf("%d>",i);
        Premisse prem=PremisseHead(BC->head);
        Proposition conc=RuleConclusion(BC->head);
        while (prem!=NULL){
            printf(" %s -",prem->proposition);
            prem = prem->next;
        }
        printf("> ");
        puts(conc);
        printf("\n");
        BC=BC->next;
        i++;
    }
}

int deleteRule(KB* BC, int i){
  if((*BC)->head == NULL){
    printf("yeet\n");
    return -1;
  }
  int j = 1;
  KB toDelete = *BC;
  KB toConnect = *BC;
  while(j != i){
    if(toDelete->next == NULL){
      printf("Hors dimension\n");
      return -1;
    }else{
      toConnect = toDelete;
      toDelete = toDelete->next;
    }
    j++;
  }

  Premisse premToDel = toDelete->head->premisse;
  Proposition propToDel = toDelete->head->conclusion;

  if(toDelete == toConnect){
    (*BC)=(*BC)->next;
  }else if(toDelete->next != NULL){//millieu de liste
    toConnect->next = toConnect->next->next;
  }else{
    toConnect->next = NULL;
  }

  if ((*BC) == NULL){
    (*BC)= createbasis();
  }
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
       addProp(&(rule->premisse), strbuffer);
       printf("Que souhaitez vous faire avec cette nouvelle régle?\n\n");
       printf("1 - Entrez une nouvelle proposition\n");
       printf("2 - Entrez une conclusion et retourner au menu principal\n");
       scanf("%d",&menu);
   } while (menu!=2);
   createConclusion(rule);
   printf("Entrez une conclusion\n");
   scanf("%s",strbuffer);
   strcpy(rule->conclusion,strbuffer);
}

KB menuBC(KB BC, Premisse BF){
    int wait;
    int quit = 0;
    while(quit != 1){
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      if((BC->head) == NULL){
        printf("Il n'y as acutellement aucune règle dans la base de connaissances\n");
      }else{
        printf("La base de connaissance est:\n\n");
        afficheBC(BC);
      }

      printf("Entrez le numéro correspondant à l'action que vous souhaitez effectuer\n\n");
      printf("1 - Ajouter une règle à la base de connaissance\n\n" );
      //printf("3 - Ajouter une proposition à une régle\n\n");
      printf("2 - Supprimer une régle\n\n");
      //printf("5 - Supprimer la proposition d'une régle\n\n");
      printf("3 - Quitter\n\n");
      scanf("%d",&wait);
      int in;
      switch (wait){
        case 1:
          addruletoBC(BC);
          break;
          case 2:
          printf("Entrez le numéro de la règle à supprimer\n");
          scanf("%d",&in);
          deleteRule(&BC,in);
          break;
          case 3:
          quit = 1;
          default:
          return 0;
          break;
        }
    }
}
