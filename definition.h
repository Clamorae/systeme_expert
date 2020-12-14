#include <string.h>

typedef enum {
  false = 0,
  true = 1
} Bool;

typedef char* Proposition;

typedef struct elP{
  Proposition proposition;
  struct elP* next;
}ElemPremisse;

typedef ElemPremisse* Premisse;

typedef struct rl{
  Premisse premisse;
  Proposition conclusion;
}Regle;


/* part2*/
typedef struct bc{
  Regle head;
  struct bc* next;
}ElemBC;

typedef ElemBC* KB;