#include "BF.h"

void addBF(Premisse BF){
int menu;
char strbuffer[255];
   do{
       printf("Entrez une proposition\n");
       scanf("%s",strbuffer);//fgets(strbuffer,255,stdin);
       if (BF->proposition==NULL){
           BF->proposition=strbuffer;
       }else{
           while (BF->next!=NULL){
               BF=BF->next;
           }
           Premisse newel=(Premisse)malloc(sizeof(ElemPremisse));
           newel->proposition=strbuffer;
           BF->next=newel;
       }
       printf("Que souhaitez vous faire?\n\n");
       printf("1 - Entrez une nouvelle proposition\n");
       printf("2 - retour au menu\n");
       scanf("%d",&menu);
   } while (menu!=2);
    menuBF(BF);
}

void afficheBF(Premisse BF){
    if (BF->proposition==NULL){
        printf("il n'y a pas encore de base de  fait\n");
    }else{
        Proposition prop;
        prop=BF->proposition;
        puts(prop);
        if (BF->next!=NULL){
            do{
                BF=BF->next;
                prop=BF->proposition;
                puts(prop);
            } while (BF->next!=NULL);
        } 
    }
    menuBF(BF);
}

Premisse menuBF(Premisse BF){
    int menu;
    printf("Entrez le numéro correspondant à l'action que vous souhaitez effectuer\n\n");
    printf("1 - Afficher la base de fait\n\n");
    printf("2 - Ajouter une proposition à la base de fait\n\n" );
    //printf("3 - Ajouter une proposition à une régle\n\n");
    printf("4 - Supprimer une proposition\n\n");
    //printf("5 - Supprimer la proposition d'une régle\n\n");
    printf("6 - Quitter\n\n");
    scanf("%d",&menu);
    switch (menu){
    case 1:
        afficheBF(BF);
        break;
    case 2:
        addBF(BF);
        break;
    case 4:
        char strbuffer[255];
        printf("Entrez la proposition que vous souhaitez supprimer\n");
        scanf("%s",strbuffer);//fgets(strbuffer,255,stdin);
        BF=deleteProp(BF,strbuffer);
        break;
    default:
        return 0;
        break;
    }
}