#include "main.h"

void menu(KB BC,Premisse BF){
    int menu;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Entrez le numéro correspondant à l'action que vous souhaitez effectuer\n\n");
    printf("1 - accéder à la base de connaissance\n\n");
    printf("2 - Entrer une base de faits\n\n" );
    printf("3 - Executer le système expert\n\n" );
    printf("4 - quitter\n\n");
    scanf("%d",&menu);
    switch (menu){
    case 1:
        menuBC(BC,BF);//////////////////TODO
        break;
    case 2:
        menuBF(BC,BF);//createBF();///////////////////TODO
        break;
    case 3:
        //moteur(BC,BF);
        break;
    default:
        break;
    }
}

int main(){
    KB BC=createbasis();
    Premisse BF;
    menu(BC,BF);
    return 0;
}
