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

KB deleteRule(KB BC,int numb){
    if (BC==NULL){
        printf("La base de connaissance est vide\n\n");
        return BC;
    }else if(numb==1){
        KB save;
        save=BC->next;
        Premisse delete;
        while (BC->head->premisse != NULL){
            delete=BC->head->premisse;
            BC->head->premisse=BC->head->premisse->next;
            free(delete);
        }
        free(BC->head->conclusion);
        free(BC->head);
        free(BC);
        return save;
    }else{
        KB save;
        for(int i=1;i=numb;i++){
            save=BC;
            BC=BC->next;
        }
        Premisse delete;
        while (BC->head->premisse != NULL){
            printf("test\n");
            delete=BC->head->premisse;
            BC->head->premisse=BC->head->premisse->next;
            free(delete);
        }
        free(BC->head->conclusion);
        free(BC->head);
        save->next=BC->next;
        free(BC);
        return save;
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
   printf("Va manger tes mort et ecris une super conclusion trop cool\n");
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
          BC=deleteRule(BC,in);
          break;
          case 3:
          quit = 1;
          default:
          return 0;
          break;
        }
    }
}
