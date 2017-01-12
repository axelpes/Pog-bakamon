#ifndef __ARBRES_H__
#define __ARBRES_H__

#include<stdio.h>
#include <malloc.h>
#include<assert.h>


typedef struct mm {
	int estFeuille;
	char etiq;
	int val;
	struct mm* fg;
	struct mm* fd;
} noeud, *tpa;

typedef struct maillon {
	tpa noeud;
	struct maillon* suiv;
} tliste, *tpl;

tpa cree_feuille(int i);
int est_feuille(tpa n);
tpa cree_noeud(char c, tpa fg, tpa fd);
tpa arbre_fg(tpa n);
tpa arbre_fd(tpa n);
char arbre_etiq(tpa n);
int val_feuille(tpa n);
void parcour_profondeur(tpa n);
void parcour_prefixe(tpa n);
tpl ajoutFile(tpa a, tpl l);
tpa tete_liste(tpl l);
int estVide(tpl l);
void parcour_largeur(tpa n);

#endif
