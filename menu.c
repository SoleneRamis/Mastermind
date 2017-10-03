

/* Ramis Solene - Groupe 4*/


#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "jeu_att_and_jeu_def.h"
#include "combinaison_secrete.h"

#define ROUGE 0
#define JAUNE 1
#define BLEU 2
#define VERT 3
#define ORANGE 4
#define ROSE 5

#define TAILLE_ECRAN_X 372
#define TAILLE_ECRAN_Y 566
#define TAILLE_BOUT_X 48
#define TAILLE_BOUT_Y 49

#define MENU_POSBOUT_XG 57
#define MENU_POSBOUT_XD 312
#define MENU_POSBOUT_ATT_YH 201
#define MENU_POSBOUT_ATT_YB 300
#define MENU_POSBOUT_DEF_YH 320
#define MENU_POSBOUT_DEF_YB 400
#define MENU_POSBOUT_QUI_YH 420
#define MENU_POSBOUT_QUI_YB 500



void Menu(void) {
	
	int choix=0;

	InitialiserGraphique();
	CreerFenetre(100,10,TAILLE_ECRAN_X,TAILLE_ECRAN_Y);
	ChargerImage("menu.png", 0,0,0,0,TAILLE_ECRAN_X,TAILLE_ECRAN_Y);


	printf("Menu\n");

	while (choix==0) {

		if (SourisCliquee()) {
			SourisPosition();

			if((_X>= MENU_POSBOUT_XG && _X<= MENU_POSBOUT_XD) && (_Y>= MENU_POSBOUT_ATT_YH && _Y<= MENU_POSBOUT_ATT_YB))
			{	
				choix=1;
				
			}

			if((_X>= MENU_POSBOUT_XG && _X<= MENU_POSBOUT_XD) && (_Y>= MENU_POSBOUT_DEF_YH && _Y<= MENU_POSBOUT_DEF_YB))
			{	
				choix=2;	
			}

			if((_X>= MENU_POSBOUT_XG && _X<= MENU_POSBOUT_XD) && (_Y>= MENU_POSBOUT_QUI_YH && _Y<= MENU_POSBOUT_QUI_YB))
			{	
				printf("Le jeu à été quitté\n");
				exit(0);
			}
		}
	}

	if(choix==1)	
		Jeu_att();
	if(choix==2)
		Combinaison_Secrete();
}



