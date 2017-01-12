#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "arbres.h"

tpa cree_feuille(int i) {
	tpa n = (tpa)malloc(sizeof(noeud)); 
	n->estFeuille = 1;
	n->val = i;
	n->fg = (tpa)NULL;
	n->fd = (tpa)NULL;

	return n;
}

int est_feuille(tpa n) {
	return (n->estFeuille == 1);
}

tpa cree_noeud(char c, tpa fg, tpa fd) {
	tpa n = (tpa)malloc(sizeof(noeud)); 
	n->estFeuille = 0; 				// un noeud n'est pas une feuille 
	n->etiq = c;
	n->fg = fg;
	n->fd = fd;

	return n;
}

tpa arbre_fg(tpa n) {
	assert(! n->estFeuille);
	return n->fg;
}

tpa arbre_fd(tpa n) {
	assert(! n->estFeuille);
	return n->fd;
}

char arbre_etiq(tpa n) {
	return n->etiq;
}

int val_feuille(tpa n) {
	return n->val;
}


void parcour_profondeur(tpa n) { // prefixe

	if(! n->estFeuille)
		printf("%c", arbre_etiq(n));
	else {
		printf("%d", val_feuille(n));
	}

	if(! n->estFeuille) {
		printf("[");
		parcour_profondeur(n->fg);
		
		printf(",");
	
		parcour_profondeur(n->fd);
		printf("]");
	}
}

void parcour_prefixe(tpa n) { // prefixe

	if(n->estFeuille){
		printf(" %d ", val_feuille(n));
	}
	else {
		printf("(");
		printf("%c", arbre_etiq(n));
		parcour_prefixe(n->fg);
		parcour_prefixe(n->fd);
		printf(")");
	}
}


/* ______ FONCTIONS LISTE _____________ */

// ajoute un maillon en fin de liste
tpl ajoutFile(tpa a, tpl l) {
	tpl newL;
	tpl n = l;
	newL = (tpl)malloc(sizeof(tliste));
	newL->noeud = a;
	newL->suiv = NULL;

	if(l != NULL) {
		while(l->suiv != NULL) {
			l = l->suiv;
		}
		l->suiv = newL;
	}

	else 
		n = newL;

	return n;
}

tpa tete_liste(tpl l) {
	return l->noeud;
}

int estVide(tpl l) {
	return l == (tpl)NULL;
}


/* ______ FIN FONCTIONS LISTE _____________ */

void parcour_largeur(tpa n) {
	tpl l = (tpl)NULL;
	tpl lTmp = (tpl)NULL;
	tpa p;
	l = ajoutFile(n, l);

	printf("\nParcour en largeur : ");
	while(! estVide(l)) {
		p = tete_liste(l);
		if(! p->estFeuille)
			printf(" %c ", arbre_etiq(p));
		else
			printf(" %d ", val_feuille(p));

		if(! p->estFeuille) {
			ajoutFile(p->fg,l);
			ajoutFile(p->fd,l);
		}

		lTmp = l;
		l = l->suiv;
		free(lTmp);
	}
	printf("\n");
}
