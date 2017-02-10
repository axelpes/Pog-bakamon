#include <math.h>
#include <stdio.h>


extern int joueur_actif;
extern int echiquier [24];
extern int arriv_ia, arriv_joueur;
extern int manges_ia, manges_joueur;
extern int de1, de2;

typedef struct Coups
{
    int coord_1, deplacement_1;
    int coord_2, deplacement_2;
}Coup;

typedef struct Couple_de
{
	int de1;
	int de2;
}Couple_des;






