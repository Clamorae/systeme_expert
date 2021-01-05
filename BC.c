#include "BC.h"

KB createbasis(){
  KB newel=(KB)malloc(sizeof(ElemBC));
  FILE* fp = fopen("BC.sav","r");
  char buffer[255];
  if(fp==NULL ||!(fgets(buffer,255,fp))){

    return newel;

  }else{

    KB save = newel; // Nouvelle BC
    KB oldnewel = newel;
    Proposition nConc = NULL;
    Premisse nPremisse = NULL;
    int keep = 1;

    do{

      Regle* nRule = createRule();
      nPremisse = NULL;

      do{
        strtok(buffer,"\n");
        addProp(&nPremisse,buffer);
        fgets(buffer,255,fp);

      }while(strcmp(buffer,"conk:\n")!=0);

      strtok(buffer,"\n");
      createConclusion(nRule);
      fgets(buffer,255,fp);
      strtok(buffer,"\n");
      strcpy(nRule->conclusion,buffer);

      nRule->premisse = nPremisse;
      newel->head = nRule;
      oldnewel = newel;

      if(fgets(buffer,255,fp)){
        newel->next = malloc(sizeof(ElemBC));
        newel = newel->next;
      }else{
        keep = 0;
      }
    }while(keep);
    return save;
  }
}

Regle* firstRule(KB base){
    return base->head;
}

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
    return -1;
  }
  int j = 1;
  KB toDelete = *BC;
  KB toConnect = *BC;
  while(j != i){
    if(toDelete->next == NULL){
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
    (*BC)= malloc(sizeof(ElemBC));
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
       system("clear");
       printf("Entrez une proposition:\n");
       getchar();
       fgets(strbuffer,255,stdin);
       strtok(strbuffer,"\n");
       addProp(&(rule->premisse), strbuffer);
       system("clear");
       printf("Que souhaitez vous faire avec cette nouvelle regle?\n\n");
       printf("1> Entrer une nouvelle proposition\n");
       printf("2> Entrer une conclusion et retourner au menu principal\n");
       scanf("%d",&menu);
   } while (menu!=2);
   createConclusion(rule);
   printf("Entrez une conclusion:\n");
   getchar();
   fgets(strbuffer,255,stdin);
   strtok(strbuffer,"\n");
   strcpy(rule->conclusion,strbuffer);
}

KB menuBC(KB BC, Premisse BF){
    int wait;
    int quit = 0;
    while(quit != 1){
      system("clear");
      printf("BASE DE CONNAISSANCE\\_____________________________________________________\n\n");
      if((BC->head) == NULL){
        printf("Il n'y as acutellement aucune regle dans la base de connaissances\n\n");
      }else{
        printf("La base de connaissance est:\n\n");
        afficheBC(BC);
      }
      printf("___________________________________________________________________________\n");
      printf("Entrez le numero correspondant a l'action que vous souhaitez effectuer\n\n");
      printf("1> Ajouter une regle a la base de connaissance\n\n" );
      printf("2> Supprimer une regle\n\n");
      printf("3> Retour au menu precedent\n\n");
      scanf("%d",&wait);
      int in;
      switch (wait){
        case 1:
          addruletoBC(BC);
          saveBCtoFile(BC);
          break;
          case 2:
          printf("Entrez le numero de la regle a supprimer\n");
          scanf("%d",&in);
          deleteRule(&BC,in);
          saveBCtoFile(BC);
          break;
          case 3:
          quit = 1;
          default:
          return 0;
          break;
        }
    }
}

int saveBCtoFile(KB BC){
  FILE *fp = fopen("BC.sav","w+");
  KB rule = BC;
  Premisse premisse;
  while(rule != NULL){
    premisse = rule->head->premisse;
    while(premisse != NULL){
      fputs(premisse->proposition,fp);
      fputs("\n",fp);
      premisse = premisse->next;
    }
    fputs("conk:\n",fp);
    fputs(rule->head->conclusion,fp);
    fputs("\n",fp);
    rule = rule->next;
  }
  fclose(fp);
}
