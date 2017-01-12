/*
 *	Affichage de notre Plateau de jeu
 *
 */

#include <stdio.h> 
#include <stdlib.h> 

#define DEFAULT_COLOR "\033[0;m"
#define CYAN     "\033[1;36m"
typedef struct Coordonnees Coordonnees;

struct Coordonnees
{
    int l;
    int c;
};

int T[2][12];
int ggc=0;
int ggn=0;
int mc=0;
int mn=0;
int joueur=0;



int lancer_de()
{
	int resultat;
	srand(time(NULL));
   resultat=rand()%6+1;
       
   return resultat;
}

void initialiser()
{
	int i, j;
	for(i=0;i<2;i++)
		for(j=0;j<12;j++)
		{	
			T[i][j]=0;
		}	
// blanc 
	T[0][11]=2;
	T[0][0]=5;
	T[1][4]=3;
	T[1][6]=5;
		
// noir=cyan
	T[0][4]=-3;
	T[0][6]=-5;
	T[1][0]=-5;
	T[1][11]=-2;
}

Coordonnees ajustement_coord(Coordonnees coord)
{

		coord.l--;
		coord.c=12-coord.c;
		return coord;
}



void modifier_plateau(Coordonnees coord) // ICIIIIIII A FAAAAAIRE !!!!!!
{
	if (joueur==0 )
		T[coord.l][coord.c]--;
	
	else if (joueur==1)
		T[coord.l][coord.c]++;
}


int verif_regles(Coordonnees coord)
{
	int i, cpt=0;

	if (joueur==0)
		if (coord.c == -1 && coord.l == 0) // car ca a été modifié !!
			{
				for(i=0; i<6; i++)
					cpt=cpt+T[coord.l][coord.c];
				if (cpt+ggc==-15)
					return 1;
			}
		else if (T[coord.l][coord.c]<0 || T[coord.l][coord.c]==0 || T[coord.l][coord.c]==1)
			return 1; 
	
	else if (joueur==1)
		if (coord.c == -1 && coord.l == 1) // car ca a été modifié !!
			{
				for(i=0; i<6; i++)
					cpt=cpt+T[coord.l][coord.c];
				if (cpt+ggc==15)
					return 1;
			}
		else if (T[coord.l][coord.c]>0 || T[coord.l][coord.c]==0 || T[coord.l][coord.c]==-1)
			return 1;
	
	return 0;
}




Coordonnees rentrer_coord()
{
	Coordonnees coord;
	do
	{
		printf("Vos coordonnées ? \nLigne : ");
		scanf("%d",&coord.l);
		printf("\nColonne : ");
		scanf("%d", &coord.c);
		printf("\n");
	}while(coord.c<0 || coord.c>12 || coord.l<1 || coord.l>2 || !verif_regles(coord));
	
	return coord;
}

// AFFICHAGE

void affichage()
{	
	int i=0;
	
	printf("   ");
	for(i=12; i>0; i--)
	{
		if (i<10)
			printf("   %d   ", i); 
		else 
			printf("   %d   ", i);
	} 	
	printf("        0\n");
	
	printf("   ");
	for (i=0; i<86; i++)
	{
		printf("*");
	}
	printf("      ********\n");
	
	
	printf(" 1 ");
	for (i=0; i<12; i++)
	{	
		if (i==6)
			printf("|");
		printf("|");
		if (T[0][i]==0)
			printf("      ");
		else if (T[0][i]>0 && T[0][i]<10)
			printf("   %d  ",T[0][i]);
		else if (T[0][i]>=10)
			printf("  %d  ",T[0][i]);
		else if (T[0][i]<0 && T[0][i]>-10)
			printf("   %s%d%s  ", CYAN, -1*(T[0][i]), DEFAULT_COLOR);
		else if (T[0][i]<=-10)
			printf("  %s%d%s  ", CYAN, -1*(T[0][i]), DEFAULT_COLOR);
	}
	
	printf("|      |");
	if (ggn==0)
		printf("      |");
	else 
		printf("   %d  |", ggn);
	printf("\n");
	
	printf("   ");
	for(i=0; i<13; i++)
	{	
		if (i==6)
			printf("|");
		printf("|      ");
	}
	printf("|      |\n");

	printf("   ");
	for (i=0; i<86; i++)
	{
		printf("-");
	}
	
	printf("      --------");
	
	printf("\n");
	printf("   ");
	for(i=0; i<13; i++)
	{	
		if (i==6)
			printf("|");
		printf("|      ");
	}
	printf("|      |\n");
	
	printf(" 2 ");
	for (i=0; i<12; i++)
	{	
		if (i==6)
			printf("|");
		printf("|");
		if (T[1][i]==0)
			printf("      ");
		else if (T[1][i]>0 && T[1][i]<10)
			printf("   %d  ",T[1][i]);
		else if (T[1][i]>=10)
			printf("  %d  ",T[1][i]);
		else if (T[1][i]<0 && T[1][i]>-10)
			printf("   %s%d%s  ", CYAN, -1*(T[1][i]), DEFAULT_COLOR);
		else if (T[1][i]<=-10)
			printf("  %s%d%s  ", CYAN, -1*(T[1][i]), DEFAULT_COLOR);
	}
	
	
	printf("|      |");
	if (ggc==0)
		printf("      |");
	else 
		printf("   %d  |", ggc);
	printf("\n");
	
	printf("   ");
	for (i=0; i<86; i++)
	{
		printf("*");
	}
	
	
	printf("      ********\n");
	printf("Pions manges Noirs : %d\n", mn);
	printf("Pions manges Blancs : %d\n", mc);
	
}



int main (void)
{
	Coordonnees coord;
	
	initialiser();
	affichage();
	printf("\n");
	coord=rentrer_coord();
	coord=ajustement_coord(coord);
	modifier_plateau(coord);
	affichage();
	printf("\n");
	
	
}
