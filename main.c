#include "main.h"


void menu(KB BC,Premisse BF){
    int menu;
    int quit=0;
    while (quit!=1){
<<<<<<< HEAD
        system("clear");
        printf("SYSTEME EXPERT\\_____________________________________________________\n\n");
        printf("Projet de LO21, realise par TROMBINI Quentin et CAILLIER Paul\n");
        printf("_____________________________________________________________________\n");
        printf("Entrez le numero correspondant a l'action que vous souhaitez effectuer\n\n");
        printf("1> Entrer la base de connaissance\n\n");
        printf("2> Entrer la base de faits et executer le systeme expert\n\n");
        printf("3> Quitter\n\n");
=======
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("Entrez le numéro correspondant à l'action que vous souhaitez effectuer\n\n");
        printf("1 - accéder à la base de connaissance\n\n");
        printf("2 - Entrer une base de faits\n\n" );
        //printf("3 - Executer le système expert\n\n" );
        printf("3 - quitter\n\n");
>>>>>>> 7b6d60a11e15e2a9337c446666b3916591dbffe6
        scanf("%d",&menu);
        switch (menu){
        case 1:
            menuBC(BC,BF);
            break;
        case 2:
            quit = menuBF(BC,BF);
            break;
<<<<<<< HEAD
=======
        //case 3:
        //    moteur(BF,BC);
        //    break;
>>>>>>> 7b6d60a11e15e2a9337c446666b3916591dbffe6
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
