#include <math.h>
#include <stdio.h>




Coup lordi_joue();
float ia(int prof, int tmp);
float min(float a, float b);
float max(float a, float b);
float evaluer_echiquier();
int trouve_indice_min(float *T);
void trouve_coups_des(Coup *resultat);
void trouve_coups(Coup *resultat);
void initialise_evaluation(float *T);
void initialise_coups(Coup *T);
int rechercher_pion (int rang);

Coup lordi_joue()										//renvoit le coup choisit par l'ordinateur
{
	int i, indice;
	Coup coups_possibles[10000];							//Tableau contenant pour contenir les coups possibles en fonct des dés
	float evaluations[10000];
	int mange=0;							//Les évaluations de chaque coups

	initialise_evaluation(evaluations);
	initialise_coups(coups_possibles);
	trouve_coups_des(coups_possibles);					//ca y est il est rempli (le reste .coord_1 à 0 car a été initilisé)
    i=0;

	while (coups_possibles[i].coord_1 != -1) 			//On fait tous les coups (venant des des) - convention pour dire que c'est la fin du tableau
	{

            jouer(coups_possibles[i], &mange);

            //evaluations[i]=ia(2,-100);
                         //je retiens son évaluation dans un tableau
            dejouer(coups_possibles[i], &mange);

		i++;											//je passe au coup suivant
	}
   // joueur_actif=1-joueur_actif;

	indice=trouve_indice_min(evaluations);
			//je cherche l'évaluation la plus petite et renvoit le coup correspondant
	return coups_possibles[3];
}


void trouve_coups_des(Coup *resultat)									//renvoit tous les coups possible à partir de 2 valeurs de dés
{
	int nbre_pion=0;									    //numéro du pion (il y en a 15 en tout, de 0 à 14)
	int j=0;
	int pion1=0;
	int pion2;
	int cpt;

	Coup coup_test;

	while (nbre_pion<(15-manges_ia-arriv_ia) && pion1<23)
    {
        pion1=rechercher_pion(pion1);
        nbre_pion=nbre_pion+fabs(echiquier[pion1]);

        coup_test.coord_1=pion1;
		coup_test.deplacement_1=de1; 					//creation du coup où on ne bouge qu'un pion avec les 2 des
		coup_test.coord_2=pion1;
		coup_test.deplacement_2=de2;

		if (verifie_regles(coup_test))
		{
			resultat[j]=coup_test;						//si ce coup convient, on le range dans le tableau
			j++;
		}

		cpt=nbre_pion;
		pion2=pion1+1;

		while (pion2<24 && cpt<(15-manges_ia-arriv_ia))
        {

            pion2=rechercher_pion(pion2);
            cpt=cpt+fabs(echiquier[pion2]);

            coup_test.coord_2=pion2;					//creation du coup : pion1 avec dé1 ET pion 2 avec dé2

			if (verifie_regles(coup_test))
			{
				resultat[j]=coup_test;
				j++;
			}

			coup_test.deplacement_1=de2;				//création du coup : pion1 avec dé2 ET pion 2 avec dé1
			coup_test.deplacement_2=de1;

			if (verifie_regles(coup_test))
			{
				resultat[j]=coup_test;
				j++;
			}
			pion2++;
        }
		pion1++;
    }
}


float ia(int prof, int tmp)											//retourne un évaluation
{
	Coup coups_possibles[10000];							//tableau
    int prof_max=2;
	int i=0;
	float eva;
    int mange=0;                            //Initialisé à moins l'infini car on commence avec un max (joueur maximise) car prof 0 donc pair

	if (prof<prof_max)									//Pour voir 1 coup en avance : prof max = 2
	{

		initialise_coups(coups_possibles);
joueur_actif=1-joueur_actif;
		trouve_coups(coups_possibles);

						//on le rempli (le reste on a .coord_1 qui vaut -1 donc ça sert à rien
		while (coups_possibles[i].coord_1 != -1) 		//convention pour dire que c'est la fin du tableau
		{

			jouer(coups_possibles[i], &mange);
			eva=ia(prof+1, tmp);
										//on retient l'évaluation
			dejouer(coups_possibles[i], &mange);

			if (prof%2==0)
				tmp=max(tmp,eva);
			else
				tmp=min(tmp,eva);						//si impair c'est min c'est l'ia donc on minimise l'éval
            i++;

		}

    return tmp;
											//RESULTAT retourné ICI
	}

	else //prof==prof-max;
		return evaluer_echiquier();						//ira dans eva à chaque fois
}



void trouve_coups(Coup *resultat)
{
	int nbre_pion;									    //numéro du pion (il y en a 15 en tout, de 0 à 14)
	int j=0;
	int pion1;
	int pion2;
	int cpt;
	int k;
	int de_1, de_2;
	Coup coup_test;

	Couple_des combinaisons_possibles[21];

	combinaisons_possibles[0].de1 = 1;
	combinaisons_possibles[0].de2 = 1;
	combinaisons_possibles[1].de1 = 2;
	combinaisons_possibles[1].de2 = 2;
	combinaisons_possibles[2].de1 = 3;
	combinaisons_possibles[2].de2 = 3;
	combinaisons_possibles[3].de1 = 4;
	combinaisons_possibles[3].de2 = 4;
	combinaisons_possibles[4].de1 = 5;
	combinaisons_possibles[4].de2 = 5;
	combinaisons_possibles[5].de1 = 6;
	combinaisons_possibles[5].de2 = 6;
	combinaisons_possibles[6].de1 = 1;
	combinaisons_possibles[6].de2 = 2;
	combinaisons_possibles[7].de1 = 1;
	combinaisons_possibles[7].de2 = 3;
	combinaisons_possibles[8].de1 = 1;
	combinaisons_possibles[8].de2 = 4;
	combinaisons_possibles[9].de1 = 1;
	combinaisons_possibles[9].de2 = 5;
	combinaisons_possibles[10].de1 = 1;
	combinaisons_possibles[10].de2 = 6;
	combinaisons_possibles[11].de1 = 2;
	combinaisons_possibles[11].de2 = 3;
	combinaisons_possibles[12].de1 = 2;
	combinaisons_possibles[12].de2 = 4;
	combinaisons_possibles[13].de1 = 2;
	combinaisons_possibles[13].de2 = 5;
	combinaisons_possibles[14].de1 = 2;
	combinaisons_possibles[14].de2 = 6;
	combinaisons_possibles[15].de1 = 3;
	combinaisons_possibles[15].de2 = 4;
	combinaisons_possibles[16].de1 = 3;
	combinaisons_possibles[16].de2 = 5;
	combinaisons_possibles[17].de1 = 3;
	combinaisons_possibles[17].de2 = 6;
	combinaisons_possibles[18].de1 = 4;
	combinaisons_possibles[18].de2 = 5;
	combinaisons_possibles[19].de1 = 4;
	combinaisons_possibles[19].de2 = 6;
	combinaisons_possibles[20].de1 = 5;
	combinaisons_possibles[20].de2 = 6;

					//tableau qui sera renvoyé
					//Notamment, on met .coord_1 à 0 pour les 10000 coups (convention)

	for (k=0; k<21; k++)
	{
	    nbre_pion=0;
	    pion1=0;

		de_1=combinaisons_possibles[k].de1;
		de_2=combinaisons_possibles[k].de2;


        if (joueur_actif==0)
        {

			while (nbre_pion<(15-manges_ia-arriv_ia) && pion1<23)
            {
                pion1=rechercher_pion(pion1);

                nbre_pion=nbre_pion+fabs(echiquier[pion1]);

                coup_test.coord_1=pion1;
                coup_test.deplacement_1=de_1; 					//creation du coup où on ne bouge qu'un pion avec les 2 des
                coup_test.coord_2=pion1;
                coup_test.deplacement_2=de_2;

                if (verifie_regles(coup_test))
                {
                    resultat[j]=coup_test;						//si ce coup convient, on le range dans le tableau
                    j++;
                }

                cpt=nbre_pion;
                pion2=pion1+1;

                while (pion2<24 && cpt<(15-manges_ia-arriv_ia))
                {

                    pion2=rechercher_pion(pion2);
                    cpt=cpt+fabs(echiquier[pion2]);

                    coup_test.coord_2=pion2;					//creation du coup : pion1 avec dé1 ET pion 2 avec dé2

                    if (verifie_regles(coup_test))
                    {
                        resultat[j]=coup_test;
                        j++;
                    }

                    coup_test.deplacement_1=de_2;				//création du coup : pion1 avec dé2 ET pion 2 avec dé1
                    coup_test.deplacement_2=de_1;

                    if (verifie_regles(coup_test))
                    {
                        resultat[j]=coup_test;
                        j++;
                    }
                    pion2++;
                }
                pion1++;
            }
		}

		else// c'est le joueur
		{
			pion1=24;
			while (nbre_pion<(15-manges_joueur-arriv_joueur) && pion1>0)
		    {
		        pion1=rechercher_pion(pion1);
                nbre_pion=nbre_pion+fabs(echiquier[pion1]);

		        coup_test.coord_1=pion1;
				coup_test.deplacement_1=de_1; 					//creation du coup où on ne bouge qu'un pion avec les 2 des
				coup_test.coord_2=pion1;
				coup_test.deplacement_2=de_2;

				if (verifie_regles(coup_test))
				{
					resultat[j]=coup_test;						//si ce coup convient, on le range dans le tableau
					j++;
				}

				cpt=nbre_pion;
				pion2=pion1-1;

				while (pion2>-1 && cpt<(15-manges_joueur-arriv_joueur))
		        {
		            pion2=rechercher_pion(pion2);
		            cpt=cpt+fabs(echiquier[pion2]);

		            coup_test.coord_2=pion2;					//creation du coup : pion1 avec dé1 ET pion 2 avec dé2

					if (verifie_regles(coup_test))
					{
						resultat[j]=coup_test;
						j++;
					}

					coup_test.deplacement_1=de_2;				//création du coup : pion1 avec dé2 ET pion 2 avec dé1
					coup_test.deplacement_2=de_1;

					if (verifie_regles(coup_test))
					{
						resultat[j]=coup_test;
						j++;
					}
					pion2--;
		        }
				pion1--;
		    }
		}
	}
}


void initialise_evaluation(float *T)
{
    int i;
	for (i=0; i<10000; i++)
		T[i]=200;										//comme on prendra le min du tableau, l'évaluation sera surement entre 0 et 10 par ex donc c'est bon
}


void initialise_coups(Coup *T)
{
    int i;
	for (i=0; i<10000; i++)
		T[i].coord_1=-1;									//initialisation minimale, on fera le test seulement sur cette composante de la structure
}

int trouve_indice_min(float *T)
{
    int i, valmin, rangmin;

    valmin=T[0];
    rangmin=0;
    i=0;
    while (i<10000 && T[i]!=200)
    {
        if(T[i]<valmin)
        {
            valmin=T[i];
            rangmin=i;
        }
        i++;
    }
    return rangmin;
}


float min(float a, float b)
{
	if (a<=b)
		return a;
	else
		return b;
}

float max(float a, float b)
{
	if (a>=b)
		return a;
	else
		return b;
}


int rechercher_pion (int rang) // en ayant fait le test qu'il existe !!
{
	if (joueur_actif==0)
	{
		while (echiquier[rang]>=0)
			rang++;
	}
	else
	{
		while (echiquier[rang]<=0)
			rang--;
	}
	return rang;

}

float evaluer_echiquier()							//plus l'ia avance, moins l'éval est bonne donc
{
	int i=0;										//moyenne des rangs
	float res=0;
	float res2=0;
	int nb_pions=0;

    //moyennne rang ia
    i=0;
    while (i<24 && nb_pions <16)
    {
        if(echiquier[i]<0)
        {
            res=res+(i)*fabs(echiquier[i]);

            nb_pions = nb_pions+fabs(echiquier[i]);

        }
        i++;
    }
    res=res/15;
    res=((res+1)*100)/24;

    i=0;
    nb_pions=0;
    while (i<24 && nb_pions <16)
    {
        if(echiquier[i]>0)
        {
            res2=res2+(i)*fabs(echiquier[i]);

            nb_pions = nb_pions+fabs(echiquier[i]);

        }
        i++;
    }
    res2=res2/15;
    res2=((24-res2)*100)/24;

    return res2-res;
}
