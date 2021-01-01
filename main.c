#include "base_connaissance.h"
#include "BC.h"
#include "BF.h"
#include <stdio.h>
#include <stdlib.h>

void menu(KB BC,Premisse BF){
    int menu;
    printf("Entrez le numéro correspondant à l'action que vous souhaitez effectuer\n\n");
    printf("1 - accéder à la base de connaissance\n\n");
    printf("2 - Entrer une base de faits\n\n" );
    printf("3 - Executer le système expert\n\n" );
    printf("4 - quitter\n\n");
    scanf("%d",&menu);
    switch (menu){
    case 1:
        menuBC(BC);//////////////////TODO
        break;
    case 2:
        menuBF(BF);//createBF();///////////////////TODO
        break;
    case 3:
        break;
    default:
        break;
    }
}

int main(){
    KB BC=createbasis();
    Premisse BF=(Premisse)malloc(sizeof(ElemPremisse));
    menu(BC,BF);
    return 0;
}


