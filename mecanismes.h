#include <math.h>
#include <stdio.h>


int verifie_regles(Coup coup_test);
void jouer(Coup coup, int * mange);
void dejouer(Coup coup, int * mange);
void initialiser_echiquier();
void lancer_de();
int ajustement_coord(int coord);
int rentrer_coord();



int oh=0;

int verifie_regles(Coup coup_test)
{
	if(joueur_actif==0)								//l'ordinateur
	{
		if (coup_test.coord_1 == coup_test.coord_2) 	//on bouge le même pion avec les deux dés
		{
			if ((coup_test.coord_1+coup_test.deplacement_1+coup_test.deplacement_2)>23)
				return 0;
			if(echiquier[coup_test.coord_1+coup_test.deplacement_1+coup_test.deplacement_2]>1)
				return 0;
		}
		else
        {
			if ((coup_test.coord_1+coup_test.deplacement_1>23) || (coup_test.coord_2+coup_test.deplacement_2>23))
				return 0;
			if(echiquier[coup_test.coord_1+coup_test.deplacement_1]>1 || echiquier[coup_test.coord_2+coup_test.deplacement_2]>1)
				return 0;
        }

			return 1;
	}

	else
	{
		if (coup_test.coord_1 == coup_test.coord_2) 	//on bouge le même pion avec les deux dés
		{
			if ((coup_test.coord_1-coup_test.deplacement_1-coup_test.deplacement_2)<0)
				return 0;
			if (echiquier[coup_test.coord_1-coup_test.deplacement_1-coup_test.deplacement_2]<-1)
				return 0;
		}
		else
        {
			if ((coup_test.coord_1-coup_test.deplacement_1<0) || (coup_test.coord_2-coup_test.deplacement_2<0))
				return 0;
			if(echiquier[coup_test.coord_1-coup_test.deplacement_1]<-1 || echiquier[coup_test.coord_2-coup_test.deplacement_2]<-1)
				return 0;
        }

			return 1;
	}
}


void jouer(Coup coup, int *mange)
{

	if (joueur_actif==0)
	{
		if (coup.coord_1==coup.coord_2)
		{
		    if (echiquier[coup.coord_1+coup.deplacement_1+coup.deplacement_2]=1) // on peut le manger !!!
            {
                echiquier[coup.coord_1]++;
                echiquier[coup.coord_1+coup.deplacement_1+coup.deplacement_2]--;
                echiquier[coup.coord_1+coup.deplacement_1+coup.deplacement_2]--;
                manges_joueur++;
                *mange=1;


            }
            else
            {
                echiquier[coup.coord_1]++;
                echiquier[coup.coord_1+coup.deplacement_1+coup.deplacement_2]--;
            }
		}
		else
		{
		    if (echiquier[coup.coord_1+coup.deplacement_1]==1)
            {
                echiquier[coup.coord_1]++;
                echiquier[coup.coord_1+coup.deplacement_1]--;
                echiquier[coup.coord_1+coup.deplacement_1]--;
                manges_joueur++;
                echiquier[coup.coord_2]++;
                echiquier[coup.coord_2+coup.deplacement_2]--;
                *mange=1;

            }
            else if (echiquier[coup.coord_2+coup.deplacement_2]==1)
            {
                echiquier[coup.coord_1]++;
                echiquier[coup.coord_1+coup.deplacement_1]--;
                echiquier[coup.coord_2]++;
                echiquier[coup.coord_2+coup.deplacement_2]--;
                echiquier[coup.coord_2+coup.deplacement_2]--;
                manges_joueur++;
                *mange=1;

            }
            else
            {
                echiquier[coup.coord_1]++;
                echiquier[coup.coord_1+coup.deplacement_1]--;
                echiquier[coup.coord_2]++;
                echiquier[coup.coord_2+coup.deplacement_2]--;
            }
		}
	}

	else// joueur!!
	{
		if (coup.coord_1==coup.coord_2)
		{
		    if (echiquier[coup.coord_1-coup.deplacement_1-coup.deplacement_2]=-1) // on peut le manger !!!
            {
                echiquier[coup.coord_1]--;
                echiquier[coup.coord_1-coup.deplacement_1-coup.deplacement_2]++;
                echiquier[coup.coord_1-coup.deplacement_1-coup.deplacement_2]++;
                manges_ia++;
                *mange=1;

            }
            else
            {
                echiquier[coup.coord_1]--;
                echiquier[coup.coord_1-coup.deplacement_1-coup.deplacement_2]++;
            }
		}
		else
		{
		    if (echiquier[coup.coord_1-coup.deplacement_1]==-1)
            {
                echiquier[coup.coord_1]--;
                echiquier[coup.coord_1-coup.deplacement_1]++;
                echiquier[coup.coord_1-coup.deplacement_1]++;
                manges_ia++;
                echiquier[coup.coord_2]--;
                echiquier[coup.coord_2-coup.deplacement_2]++;
                *mange=1;

            }

            else if (echiquier[coup.coord_2-coup.deplacement_2]==-1)
            {
                echiquier[coup.coord_1]--;
                echiquier[coup.coord_1-coup.deplacement_1]++;
                echiquier[coup.coord_2]--;
                echiquier[coup.coord_2-coup.deplacement_2]++;
                echiquier[coup.coord_2-coup.deplacement_2]++;
                manges_ia++;
                *mange=1;

            }
            else
            {
                echiquier[coup.coord_1]--;
                echiquier[coup.coord_1-coup.deplacement_1]++;
                echiquier[coup.coord_2]--;
                echiquier[coup.coord_2-coup.deplacement_2]++;
            }

		}
	}
}

void dejouer(Coup coup, int * mange)
{
	if (joueur_actif==0)
	{
		if (coup.coord_1==coup.coord_2)
		{
		    if (echiquier[coup.coord_1+coup.deplacement_1+coup.deplacement_2]==-1 &&*mange )
            {
                echiquier[coup.coord_1]--;
                echiquier[coup.coord_1+coup.deplacement_1+coup.deplacement_2]++;
                echiquier[coup.coord_1+coup.deplacement_1+coup.deplacement_2]++;
                manges_joueur--;
            }
            else
            {
                echiquier[coup.coord_1]--;
                echiquier[coup.coord_1+coup.deplacement_1+coup.deplacement_2]++;
            }
		}
		else
		{
			if (echiquier[coup.coord_1+coup.deplacement_1]==-1 && *mange )
			{
			    echiquier[coup.coord_1]--;
                echiquier[coup.coord_1+coup.deplacement_1]++;
                echiquier[coup.coord_1+coup.deplacement_1]++;
                echiquier[coup.coord_2]--;
                echiquier[coup.coord_2+coup.deplacement_2]++;
                manges_joueur--;
			}
			else if (echiquier[coup.coord_2+coup.deplacement_2]==-1 && *mange)
            {
                echiquier[coup.coord_1]--;
                echiquier[coup.coord_1+coup.deplacement_1]++;
                echiquier[coup.coord_2]--;
                echiquier[coup.coord_2+coup.deplacement_2]++;
                echiquier[coup.coord_2+coup.deplacement_2]++;
                manges_joueur--;
            }
            else
            {
                echiquier[coup.coord_1]--;
                echiquier[coup.coord_1+coup.deplacement_1]++;
                echiquier[coup.coord_2]--;
                echiquier[coup.coord_2+coup.deplacement_2]++;
            }
		}
	}

	else // joueur
	{
		if (coup.coord_1==coup.coord_2)
		{
		    if (echiquier[coup.coord_1-coup.deplacement_1-coup.deplacement_2]=1 &&*mange  ) // on peut le manger !!!
            {
                echiquier[coup.coord_1]++;
                echiquier[coup.coord_1-coup.deplacement_1-coup.deplacement_2]--;
                echiquier[coup.coord_1-coup.deplacement_1-coup.deplacement_2]--;
                manges_ia--;
            }
            else
            {
			echiquier[coup.coord_1]++;
			echiquier[coup.coord_1-coup.deplacement_1-coup.deplacement_2]--;
            }
		}
		else
		{
		    if (echiquier[coup.coord_1-coup.deplacement_1]==1 && *mange )
            {
                echiquier[coup.coord_1]++;
                echiquier[coup.coord_1-coup.deplacement_1]--;
                echiquier[coup.coord_1-coup.deplacement_1]--;
                manges_ia--;
                echiquier[coup.coord_2]++;
                echiquier[coup.coord_2-coup.deplacement_2]--;
            }
            else if (echiquier[coup.coord_2-coup.deplacement_2]==1 && *mange )
            {
                echiquier[coup.coord_1]++;
                echiquier[coup.coord_1-coup.deplacement_1]--;
                echiquier[coup.coord_2]++;
                echiquier[coup.coord_2-coup.deplacement_2]--;
                echiquier[coup.coord_2-coup.deplacement_2]--;
                manges_ia--;
            }
            else
            {
                echiquier[coup.coord_1]++;
                echiquier[coup.coord_1-coup.deplacement_1]--;
                echiquier[coup.coord_2]++;
                echiquier[coup.coord_2-coup.deplacement_2]--;
            }

		}
	}
}

void initialiser_echiquier()
{
	int i;
	for(i=0;i<24;i++)
		echiquier[i]=0;
// blanc
	echiquier[5]=5;
	echiquier[7]=3;
	echiquier[12]=5;
	echiquier[23]=2;

// noir = cyan = machine
	echiquier[0]=-2;
	echiquier[11]=-5;
	echiquier[16]=-3;
	echiquier[18]=-5;
}

void lancer_de()
{
	srand(time(NULL));
    de1=rand()%6+1;

    srand(time(NULL)+1);
    de2=rand()%6+1;
}

int ajustement_coord(int coord) //necessaire car le tableau commence à 0
{
    if(coord>0 && coord<25)
        coord--;
    return coord;
}


int rentrer_coord()
{
	int coord;
	do
	{
		printf("Entrez une coord: \n");
		scanf("%d",&coord);
    coord=ajustement_coord(coord);
	}while(coord<0 || coord>24);

	return coord;
}

void remise_en_jeu()
{
    Coup mon_coup;
    int de_restant;
    if (joueur_actif==0)
    {
        mon_coup.coord_1=0;
        mon_coup.coord_2=0;
        mon_coup.deplacement_1=de1;
        mon_coup.deplacement_2=de2;

        if (verifie_regles(mon_coup)&& echiquier[de1+de2-1]!=1)
        {
            echiquier[de1+de2-1];
            manges_ia--;
            de_restant=0;
        }

        else
        {
            mon_coup.deplacement_2=0;
            if (verifie_regles(mon_coup)&& echiquier[de1-1]!=1)
            {
                echiquier[de1-1]--;
                manges_ia--;
                de_restant=de2;
            }

            else
            {
                mon_coup.deplacement_1=de2;
                if (verifie_regles(mon_coup)&& echiquier[de2-1]!=1)
                {
                    echiquier[de2-1]--;
                    manges_ia--;
                    de_restant=de1;
                }
                de_restant=-1;              // cad on a pas pu!!
            }
        }
    }

    else // le joueur
    {

    }

}
