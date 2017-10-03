

/* Ramis Solene - Groupe 4*/


#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "jeu_att_and_jeu_def.h"

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

#define COMBI_DECALAGE_X 72.5
#define COMBI_POSITION_X 51
#define COMBI_POSITION_Y 214
#define COMBI_POSBOUT_VALIDE_XG 255
#define COMBI_POSBOUT_VALIDE_XD 365
#define COMBI_POSBOUT_VALIDE_YH 515
#define COMBI_POSBOUT_VALIDE_YB 560
#define COMBI_POSBOUT_YH 342
#define COMBI_POSBOUT_YB 390
#define COMBI_POSBOUT_ROUGE_XG 22
#define COMBI_POSBOUT_ROUGE_XD 70
#define COMBI_POSBOUT_JAUNE_XG 80
#define COMBI_POSBOUT_JAUNE_XD 125
#define COMBI_POSBOUT_BLEU_XG 137
#define COMBI_POSBOUT_BLEU_XD 183			
#define COMBI_POSBOUT_VERT_XG 195
#define COMBI_POSBOUT_VERT_XD 240
#define COMBI_POSBOUT_ORANGE_XG 247
#define COMBI_POSBOUT_ORANGE_XD 295
#define COMBI_POSBOUT_ROSE_XG 302
#define COMBI_POSBOUT_ROSE_XD 351






void Combinaison_Secrete(void) {

	int compteur= 0;
	int choix=0;
	int Combi_secrete[3];
	
	printf("Combinaison secrete\n");

	ChoisirEcran(2);
 	ChargerImage("combinaison.png", 0,0,0,0,TAILLE_ECRAN_X,TAILLE_ECRAN_Y);
	CopierZone(2,0,0,0,TAILLE_ECRAN_X,TAILLE_ECRAN_Y,0,0);



	while(choix==0) {

		if (SourisCliquee()) {
			SourisPosition();

			/* Choix des couleurs */
					
			if((_X>= COMBI_POSBOUT_ROUGE_XG && _X<= COMBI_POSBOUT_ROUGE_XD) && (_Y>= COMBI_POSBOUT_YH && _Y<= COMBI_POSBOUT_YB) && compteur!=4) {	
				Combi_secrete[compteur]= ROUGE;
				ChargerImage("rouge.png", (COMBI_POSITION_X + compteur * COMBI_DECALAGE_X),COMBI_POSITION_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
				compteur++;
			}
			
			
			if((_X>= COMBI_POSBOUT_JAUNE_XG && _X<= COMBI_POSBOUT_JAUNE_XD) && (_Y>= COMBI_POSBOUT_YH && _Y<= COMBI_POSBOUT_YB) && compteur!=4) {	
				Combi_secrete[compteur]= JAUNE;
				ChargerImage("jaune.png", (COMBI_POSITION_X + compteur * COMBI_DECALAGE_X),COMBI_POSITION_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
				compteur++;
			}
			
			if((_X>= COMBI_POSBOUT_BLEU_XG && _X<= COMBI_POSBOUT_BLEU_XD) && (_Y>= COMBI_POSBOUT_YH && _Y<= COMBI_POSBOUT_YB) && compteur!=4) {	
				Combi_secrete[compteur]= BLEU;
				ChargerImage("bleu.png", (COMBI_POSITION_X + compteur * COMBI_DECALAGE_X),COMBI_POSITION_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
				compteur++;
			}
			
			if((_X>= COMBI_POSBOUT_VERT_XG && _X<= COMBI_POSBOUT_VERT_XD) && (_Y>= COMBI_POSBOUT_YH && _Y<= COMBI_POSBOUT_YB) && compteur!=4) {	
				Combi_secrete[compteur]= VERT;
				ChargerImage("vert.png", (COMBI_POSITION_X + compteur * COMBI_DECALAGE_X),COMBI_POSITION_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
				compteur++;
			}

			if((_X>= COMBI_POSBOUT_ORANGE_XG && _X<= COMBI_POSBOUT_ORANGE_XD) && (_Y>= COMBI_POSBOUT_YH && _Y<= COMBI_POSBOUT_YB) && compteur!=4) {	
				Combi_secrete[compteur]= ORANGE;
				ChargerImage("orange.png", (COMBI_POSITION_X + compteur * COMBI_DECALAGE_X),COMBI_POSITION_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
				compteur++;
			}

			if((_X>= COMBI_POSBOUT_ROSE_XG && _X<= COMBI_POSBOUT_ROSE_XD) && (_Y>= COMBI_POSBOUT_YH && _Y<= COMBI_POSBOUT_YB) && compteur!=4) {	
				Combi_secrete[compteur]= ROSE;
				ChargerImage("rose.png", (COMBI_POSITION_X + compteur * COMBI_DECALAGE_X),COMBI_POSITION_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
				compteur++;
			}


			/* Clic Validé */

			if((_X>= COMBI_POSBOUT_VALIDE_XG && _X<= COMBI_POSBOUT_VALIDE_XD) && (_Y>= COMBI_POSBOUT_VALIDE_YH && _Y<= COMBI_POSBOUT_VALIDE_YB) && compteur==4) {
				choix=1;
			}
		}	
		CopierZone(2,0,0,0,TAILLE_ECRAN_X,TAILLE_ECRAN_Y,0,0);
	}

	if(choix==1) {
		Jeu_def(Combi_secrete);
	}
}