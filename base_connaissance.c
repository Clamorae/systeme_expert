#include"base_connaissance.h"

KB createbasis(){
    KB newel=(KB)malloc(sizeof(ElemBC));
    return newel;
}

Regle* firstRule(KB base){
    return base->head;
}
