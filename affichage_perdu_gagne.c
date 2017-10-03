

/* Ramis Solene - Groupe 4*/


#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

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


#define PERDU_GAGNE_DECALAGE_X 66
#define PERDU_GAGNE_POS_X 51
#define PERDU_GAGNE_POS_Y 252
#define PERDU_GAGNE_POSBOUT_QUIT_XG 243
#define PERDU_GAGNE_POSBOUT_QUIT_XD 400
#define PERDU_GAGNE_POSBOUT_YH 511
#define PERDU_GAGNE_POSBOUT_YB 560



void Perdu(int Tab[]) {

	int compteur= 0;
	int choix= 0;

	printf("Perdu !\n");

	ChoisirEcran(4);
	CopierZone(4,0,0,0,TAILLE_ECRAN_X,TAILLE_ECRAN_Y,0,0);
	ChargerImage("perdu.png", 0,0,0,0,TAILLE_ECRAN_X,TAILLE_ECRAN_Y);



	
	/* affichage de la combinaison secrete */

	for (compteur=0; compteur<4; compteur++) {

		if (Tab[compteur]==ROUGE) {
			ChargerImage("rouge.png", PERDU_GAGNE_POS_X + compteur * PERDU_GAGNE_DECALAGE_X,PERDU_GAGNE_POS_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
		if (Tab[compteur]==JAUNE) {
			ChargerImage("jaune.png", PERDU_GAGNE_POS_X + compteur * PERDU_GAGNE_DECALAGE_X,PERDU_GAGNE_POS_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
		if (Tab[compteur]==BLEU) {
			ChargerImage("bleu.png", PERDU_GAGNE_POS_X + compteur * PERDU_GAGNE_DECALAGE_X,PERDU_GAGNE_POS_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
		if (Tab[compteur]==VERT) {
			ChargerImage("vert.png", PERDU_GAGNE_POS_X + compteur * PERDU_GAGNE_DECALAGE_X,PERDU_GAGNE_POS_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
		if (Tab[compteur]==ORANGE) {
			ChargerImage("orange.png", PERDU_GAGNE_POS_X + compteur * PERDU_GAGNE_DECALAGE_X,PERDU_GAGNE_POS_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
		if (Tab[compteur]==ROSE) {
			ChargerImage("rose.png", PERDU_GAGNE_POS_X + compteur * PERDU_GAGNE_DECALAGE_X,PERDU_GAGNE_POS_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
	}

	while(choix==0) {

		if (SourisCliquee()) {
			SourisPosition();


			if((_X>= PERDU_GAGNE_POSBOUT_QUIT_XG && _X<= PERDU_GAGNE_POSBOUT_QUIT_XD) && (_Y>= PERDU_GAGNE_POSBOUT_YH && _Y<= PERDU_GAGNE_POSBOUT_YB)) {	
				printf("Le jeu à été quitté\n");
				choix=1;
				exit(0);
			}
		}
		CopierZone(4,0,0,0,TAILLE_ECRAN_X,TAILLE_ECRAN_Y,0,0);
	}
}







void Gagne(int Tab[]) {

	int compteur= 0;
	int choix= 0;

	printf("Gagne ! !\n");

	ChoisirEcran(5);
	CopierZone(5,0,0,0,TAILLE_ECRAN_X,TAILLE_ECRAN_Y,0,0);
	ChargerImage("gagne.png", 0,0,0,0,TAILLE_ECRAN_X,TAILLE_ECRAN_Y);



	/* affichage de la combinaison secrete */

	for (compteur=0; compteur<4; compteur++) {

		if (Tab[compteur]==ROUGE) {
			ChargerImage("rouge.png", PERDU_GAGNE_POS_X + compteur * PERDU_GAGNE_DECALAGE_X,PERDU_GAGNE_POS_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
		if (Tab[compteur]==JAUNE) {
			ChargerImage("jaune.png", PERDU_GAGNE_POS_X + compteur * PERDU_GAGNE_DECALAGE_X,PERDU_GAGNE_POS_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
		if (Tab[compteur]==BLEU) {
			ChargerImage("bleu.png", PERDU_GAGNE_POS_X + compteur * PERDU_GAGNE_DECALAGE_X,PERDU_GAGNE_POS_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
		if (Tab[compteur]==VERT) {
			ChargerImage("vert.png", PERDU_GAGNE_POS_X + compteur * PERDU_GAGNE_DECALAGE_X,PERDU_GAGNE_POS_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
		if (Tab[compteur]==ORANGE) {
			ChargerImage("orange.png", PERDU_GAGNE_POS_X + compteur * PERDU_GAGNE_DECALAGE_X,PERDU_GAGNE_POS_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
		if (Tab[compteur]==ROSE) {
			ChargerImage("rose.png", PERDU_GAGNE_POS_X + compteur * PERDU_GAGNE_DECALAGE_X,PERDU_GAGNE_POS_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
	}


	while(choix==0) {

		if (SourisCliquee()) {
			SourisPosition();

			if((_X>= PERDU_GAGNE_POSBOUT_QUIT_XG && _X<= PERDU_GAGNE_POSBOUT_QUIT_XD) && (_Y>= PERDU_GAGNE_POSBOUT_YH && _Y<= PERDU_GAGNE_POSBOUT_YB)) {	
				printf("Le jeu à été quitté\n");
				exit(0);
			}
		}
		CopierZone(5,0,0,0,TAILLE_ECRAN_X,TAILLE_ECRAN_Y,0,0);
	}
}
