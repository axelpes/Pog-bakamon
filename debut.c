#include <math.h>
#include <stdio.h>

#include "debut.h"
#include "affichage.h"
#include "mecanismes.h"
#include "ia.h"

int joueur_actif=0;
int echiquier [24];
int arriv_ia=0;
int arriv_joueur=0;
int manges_ia=0;
int manges_joueur=0;
int de1, de2;


int main (void)
{
	initialiser_echiquier();
	affichage();
	Coup mon_coup;
	int compteur;
	int i;
	int mange=0;
	int rentre;
	printf("Vous etes le joueur 2\n");

	while (arriv_ia!=15 && arriv_joueur!=15)
    {
        joueur_actif=1-joueur_actif;
        printf("Au tour du joueur %d", joueur_actif+1);             //0 = 1 et 1 = 2
        lancer_de();
        printf("Apres le lance de des... De1 = %d et De2 = %d \n", de1, de2);

        if (joueur_actif==0)
        {
            compteur=0;
            for (i=18; i<=23; i++) // correspond aux 6 dernières cases pour l'ia
                if (echiquier[i]<0)
                    compteur=compteur+fabs(echiquier[i]);

            if (compteur!=15)
            {
                if (manges_ia>0)
                {   // pour l'instant on peut perdre un coup, malheureusement.
                    remise_en_jeu(); //peut ne rien faire
                }
                else
                {
                    mon_coup=lordi_joue();
                    jouer(mon_coup, &mange);
                }
            }
            else //les pions sont prets a etre sortis
            {
                // A FAIRE
            }
        }

        else //joueur actif =1;
        {
            printf("STP, ne mange personne, ne te fais pas manger, joue seulement les coups que tu as le droit, et ne sort pas tes pions.\n");
            printf("\nEntrez no pion a bouger : ");
            scanf("%d", &rentre);
            mon_coup.coord_1=ajustement_coord(rentre);
            printf("\nEntrez son deplacement : ");
            scanf("%d", &rentre);
            mon_coup.deplacement_1=rentre;
            printf("\nEntrez no pion a bouger : ");
            scanf("%d", &rentre);
            mon_coup.coord_2=ajustement_coord(rentre);
            printf("\nEntrez son deplacement : ");
            scanf("%d", &rentre);
            mon_coup.deplacement_2=rentre;
            printf("\n");

            jouer(mon_coup, &mange);
        }
        affichage();
    }
}


