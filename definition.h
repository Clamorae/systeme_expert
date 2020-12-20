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

typedef struct bc{
  Regle head;
  struct bc* next;
}ElemBC;

typedef ElemBC* KB;


Regle* createRule();

void addProp(Regle rule, Proposition str);

void createConclusion(Regle rule);

Bool testProp(Premisse rulePrem, Proposition prop);

Bool isPremisseEmpty(Regle rule);

Premisse deleteProp(Premisse head, Proposition prop);

Bool isNULL(Premisse head);

Premisse PremisseHead(Regle rule);

Proposition RuleConclusion(Regle rule);
