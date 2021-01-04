#include "BF.h"

void addBF(KB BC,Premisse* BF){
int menu;
char strbuffer[255];
   do{
       system("clear");
       printf("Entrez une proposition\n");
       getchar();
       fgets(strbuffer,255,stdin);
       strtok(strbuffer,"\n");//fgets(strbuffer,255,stdin);
       addProp(BF,strbuffer);
       printf("Que souhaitez vous faire?\n\n");
       printf("1> Entrez une nouvelle proposition\n");
       printf("2> Retour au menu\n");
       scanf("%d",&menu);
   } while (menu!=2);
}

void afficheBF(KB BC,Premisse BF){
    if(BF){
      printf("La base de fait contient:\n");
      Proposition prop;
      prop=BF->proposition;
      printf("%s",prop);
      if (BF->next!=NULL){
          do{
              BF=BF->next;
              prop=BF->proposition;
              printf(" - ");
              printf("%s",prop);
          } while (BF->next!=NULL);
      }
      printf("\n\n");
    }else{
      printf("La base de fait est vide\n\n");

    }
}

int menuBF(KB BC,Premisse BF){
  int quit = 0;
  while(quit != 1){
    system("clear");
    printf("BASE DE FAITS\\_____________________________________________________\n\n");
    afficheBF(BC,BF);
    printf("____________________________________________________________________\n");
    int wait;
    printf("Entrez le numero correspondant a l'action que vous souhaitez effectuer\n\n");
    printf("1> Ajouter une proposition a la base de fait\n\n" );
    printf("2> Supprimer une proposition\n\n");
    printf("3> Executer le systeme expert\n\n");
    printf("4> retourner au menu precedent\n\n");
    scanf("%d",&wait);
    switch (wait){
      case 1:
          addBF(BC,&BF);
          break;
      case 2:
          Cleanup: ;
          char strbuffer[255];
          printf("Entrez la proposition que vous souhaitez supprimer\n");
          getchar();
          fgets(strbuffer,255,stdin);
          strtok(strbuffer,"\n");
          BF=deleteProp(BF,strbuffer);
          break;
      case 3:
          moteur(BF,BC);
          return 1;
          break;
      case 4:
      default:
          quit = 1;
          break;
    }
  }
  return 0;
}
