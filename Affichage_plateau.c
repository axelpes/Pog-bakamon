/*
 *	Affichage de notre Plateau de jeu
 *
 */

#include <stdio.h> 
void affichage(int T)
{
	int i;
	for(i=0, i<37, i++)
		printf("_");
	printf("\n");

	for(i=13, i>1, i--){
		printf("|");
		
		if(T[1,i]!=0)
			printf("%d %c", T[1,i], T[0,i]);
		else
			printf("   ");
	}

	printf("|    |");
	

	
	printf("\n");
}
	
	
int main(void){
	int T[][]; 
	for(i)
		for(j)
			T[i][j] = 0;
	affichage(T);

}
