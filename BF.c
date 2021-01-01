#include "BF.h"

void addBF(KB BC,Premisse BF){
int menu;
char strbuffer[255];
   do{
       printf("Entrez une proposition\n");
       scanf("%s",strbuffer);//fgets(strbuffer,255,stdin);
       addProp(&BF,strbuffer);
       printf("Que souhaitez vous faire?\n\n");
       printf("1 - Entrez une nouvelle proposition\n");
       printf("2 - retour au menu\n");
       scanf("%d",&menu);
   } while (menu!=2);
    menuBF(BC,BF);
}

void afficheBF(KB BC,Premisse BF){
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
    menuBF(BC,BF);
}

Premisse menuBF(KB BC,Premisse BF){
    afficheBF(BC,BF);
    int wait;
    printf("Entrez le numéro correspondant à l'action que vous souhaitez effectuer\n\n");
    printf("1 - Ajouter une proposition à la base de fait\n\n" );
    //printf("3 - Ajouter une proposition à une régle\n\n");
    printf("2 - Supprimer une proposition\n\n");
    printf("3 - Executer le système expert\n\n");
    printf("4 - Quitter\n\n");
    scanf("%d",&wait);
    switch (wait){
    case 1:
        addBF(BC,BF);
        break;
    case 2:
        Cleanup: ;
        char strbuffer[255];
        printf("Entrez la proposition que vous souhaitez supprimer\n");
        scanf("%s",strbuffer);//fgets(strbuffer,255,stdin);
        BF=deleteProp(BF,strbuffer);
        break;
    case 3:
        moteur(BC,BF);
    case 4:
        menu(BC,BF);
    default:
        return 0;
        break;
    }
}
