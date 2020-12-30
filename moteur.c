#include <stdio.h>
#include <stdlib.h>
#include "moteur.h"

void moteur(Premisse BF, KB BC){
    if (BF->proposition==NULL){
        printf("La base de fait est vide\n");
    }else if (BC->head==NULL){
        printf("La base de connaissance est vide\n");
    }else{
        int buffer;
        Premisse end=BF;
        while (end->next!=NULL){
            end=end->next;
        }
        
        do{
            do{
                buffer=testProp(BC->head->premisse,BF->proposition);
                if (buffer==1){
                    BC->head->premisse=deleteProp(BC->head->premisse,BF->proposition);
                    if (BC->head->premisse==NULL){
                        Premisse newel=(Premisse)malloc(sizeof(ElemPremisse));
                        newel->proposition=BC->head->conclusion;
                        end->next=newel;
                        end=newel;
                        puts(end->proposition);
                        printf("\n");
                    }
                }
                BC=BC->next;
            }while (BC!=NULL);
            BF=BF->next;
        } while (BF!=NULL);
        
    }
    
    

}