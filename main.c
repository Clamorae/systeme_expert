#include "base_connaissance.h"
#include "BC.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    KB BC=createbasis();
    Premisse BF=(Premisse)malloc(sizeof(ElemPremisse));
    int menu;
    printf("Entrez le numéro correspondant à l'action que vous souhaitez effectuer\n\n");
    printf("1 - accéder à la base de connaissance\n\n");
    printf("2 - Entrer une base de faits et executer le système expert" );
    printf("3 - quitter\n\n");
    scanf("%d",&menu);
    switch (menu){
    case 1:
        menuBC(BC);//////////////////TODO
        break;
    case 2:
        menuBF(BF);//createBF();///////////////////TODO
        break;
    case 3:
        return 0;
        break;
    default:
        return 0;
        break;
    }
}
