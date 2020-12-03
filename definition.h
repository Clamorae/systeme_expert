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
