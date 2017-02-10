#include <math.h>
#include <stdio.h>

#define DEFAULT_COLOR "\033[0;m"
#define CYAN "\e[0;31m"

void affichage();

void affichage()
{
	int i=0;
	printf("\n");

//chiffres de la première ligne
	printf("   ");
	for(i=12; i>0; i--)
	{
		if(i==12)
			printf("   %d", i);
		else if(i==6)
			printf("       %d", i);
		else if(i<10 )
			printf("      %d", i);
		else
			printf("     %d", i);
	}
	printf("             0\n"); // A CHANGER

// affichage des *** du haut
	printf("   ");
	for (i=0; i<86; i++)
	{
		printf("*");
	}
	printf("      ********\n");

// affichage première ligne
	printf("   ");
	for (i=11; i>=0; i--)
		{
			printf("|");
			if (i==5)
				printf("|");
			if (echiquier[i]==0)
				printf("      ");
			else if (echiquier[i]>0 && echiquier[i]<10)
				printf("   %d  ",echiquier[i]);
			else if (echiquier[i]>=10)
				printf("  %d  ",echiquier[i]);
			else if (echiquier[i]<0 && echiquier[i]>-10)
				printf("   %s%d%s  ", CYAN, -1*(echiquier[i]), DEFAULT_COLOR);
			else if (echiquier[i]<=-10)
				printf("  %s%d%s  ", CYAN, -1*(echiquier[i]), DEFAULT_COLOR);
		}

// pions gagnés du haut
	printf("|      |");
	if (arriv_joueur==0)
		printf("      |");
	else
		printf("   %d  |", arriv_joueur);
	printf("\n");

//affichage première ligne vide
	printf("   ");
	for(i=0; i<13; i++)
	{
		if (i==6)
			printf("|");
		printf("|      ");
	}
	printf("|      |\n");

// affichage -- du milieu
	printf("   ");
	for (i=0; i<86; i++)
	{
		printf("-");
	}
	printf("      --------");
	printf("\n");

// affichage seconde ligne vide
	printf("   ");
	for(i=0; i<13; i++)
	{
		if (i==6)
			printf("|");
		printf("|      ");
	}
	printf("|      |\n");

// affichage seconde ligne
printf("   ");
for (i=12; i<24; i++)
	{
		if (i==18)
			printf("|");
		printf("|");
		if (echiquier[i]==0)
			printf("      ");
		else if (echiquier[i]>0 && echiquier[i]<10)
			printf("   %d  ",echiquier[i]);
		else if (echiquier[i]>=10)
			printf("  %d  ",echiquier[i]);
		else if (echiquier[i]<0 && echiquier[i]>-10)
			printf("   %s%d%s  ", CYAN, -1*(echiquier[i]), DEFAULT_COLOR);
		else if (echiquier[i]<=-10)
			printf("  %d  ",(echiquier[i]));
	}

// affichage gagnés du bas
	printf("|      |");
	if (arriv_ia==0)
		printf("      |");
	else
		printf("   %d  |", arriv_ia);
	printf("\n");

// affichage *** du bas
	printf("   ");
	for (i=0; i<86; i++)
	{
		printf("*");
	}
	printf("      ********\n");


// chiffres de la seconde ligne
printf("   ");
	for(i=13; i<25; i++)
	{
		if(i==13)
			printf("   %d", i);
		else if(i==19)
			printf("      %d", i);
		else
			printf("     %d", i);
	}
	printf("             0\n"); // A CHANGER
	printf("\n");

// Pions mangés
	printf("Pions manges Noirs : %d\n", manges_joueur);
	printf("Pions manges Blancs : %d\n", manges_ia);

	printf("\n");
}
