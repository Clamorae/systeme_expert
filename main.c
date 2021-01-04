#include "main.h"


void menu(KB BC,Premisse BF){
    int menu;
    int quit=0;
    while (quit!=1){
        system("clear");
        printf("SYSTEME EXPERT\\_____________________________________________________\n\n");
        printf("Projet de LO21, realise par TROMBINI Quentin et CAILLIER Paul\n");
        printf("_____________________________________________________________________\n");
        printf("Entrez le numero correspondant a l'action que vous souhaitez effectuer\n\n");
        printf("1> Entrer la base de connaissance\n\n");
        printf("2> Entrer la base de faits et executer le systeme expert\n\n");
        printf("3> Quitter\n\n");
        scanf("%d",&menu);
        switch (menu){
        case 1:
            menuBC(BC,BF);
            break;
        case 2:
            quit = menuBF(BC,BF);
            break;
        case 3:
            quit=1;
        default:
            break;
        }
    }
}

int main(){
    KB BC=createbasis();
    Premisse BF;
    menu(BC,BF);
    return 0;
}
