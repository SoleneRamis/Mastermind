

/* Ramis Solene - Groupe 4*/


#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include "affichage_perdu_gagne.h"

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

#define JEU_POSGRILLE_X 33
#define JEU_POSGRILLE_Y 515

/* JA : jeu attaquant, JD : jeu defenseur, XD : coordonnée x position coté droite, XG : coordonnée x position coté gauche, 
   YH : coordonnée y position haute, YB : coordonnée y position basse */

#define JA_DECALAGE_X 52.2
#define JA_DECALAGE_Y 48
#define JA_POSBOUT_ROUGE_YH 73
#define JA_POSBOUT_ROUGE_YB 118
#define JA_POSBOUT_JAUNE_YH 137
#define JA_POSBOUT_JAUNE_YB 183
#define JA_POSBOUT_BLEU_YH 203
#define JA_POSBOUT_BLEU_YB 249
#define JA_POSBOUT_VERT_YH 269
#define JA_POSBOUT_VERT_YB 314
#define JA_POSBOUT_ORANGE_YH 334
#define JA_POSBOUT_ORANGE_YB 381
#define JA_POSBOUT_ROSE_YH 402
#define JA_POSBOUT_ROSE_YB 447
#define JA_POSBOUT_VALIDE_XG 311
#define JA_POSBOUT_VALIDE_XD 360
#define JA_POSBOUT_VALIDE_YH 470
#define JA_POSBOUT_VALIDE_YB 556
#define JA_POSBOUT_XG 314
#define JA_POSBOUT_XD 361

#define JD_POSBOUT_X 35
#define JD_POSBOUT_Y 12
#define JD_DECALAGE_X 49.5

#define COMP_X 238
#define COMP_Y 531
#define COMP_DECALAGE_X 16.2
#define COMP_DECALAGE_Y 47.5
#define COMP_TAILLE_PIECE 14.5




void Jeu_att(void) {


	int Proposition_couleurs[4];
	int compteur_x= 0;
	int compteur_y= 0;
	int choix=0;
	int compt_x=0, nb_coup=0;
	int Combi_secrete_alea_nouv[4];
	int Proposition_couleurs_nouv[4];
	int i= 0,j= 0;
	int Combi_secrete_alea[4];
	int bien_place, mal_place;
	printf("Jeu Attaquant\n");
	srand((unsigned int) time(NULL));
	ChoisirEcran(1);
	ChargerImage("jeuatt.png", 0,0,0,0,TAILLE_ECRAN_X,TAILLE_ECRAN_Y);
	


	for (i = 0; i < 4; ++i) {
		Combi_secrete_alea[i]= rand()%(6-0)-0;
	}

	while(choix==0) {

		if (SourisCliquee()) {
			SourisPosition();

			/* Choix des couleurs */
					
			if((_X>= JA_POSBOUT_XG && _X<= JA_POSBOUT_XD) && (_Y>= JA_POSBOUT_ROUGE_YH && _Y<= JA_POSBOUT_ROUGE_YB) && compteur_x!=4 && compteur_y!=10) {	
				Proposition_couleurs[compteur_x]= ROUGE;
				ChargerImage("rouge.png", (JEU_POSGRILLE_X + compteur_x * JA_DECALAGE_X),(JEU_POSGRILLE_Y - compteur_y * JA_DECALAGE_Y),0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
				compteur_x++;
			}
			
			
			if((_X>= JA_POSBOUT_XG && _X<= JA_POSBOUT_XD) && (_Y>= JA_POSBOUT_JAUNE_YH && _Y<= JA_POSBOUT_JAUNE_YB) && compteur_x!=4 && compteur_y!=10) {	
				Proposition_couleurs[compteur_x]= JAUNE;
				ChargerImage("jaune.png", (JEU_POSGRILLE_X + compteur_x * JA_DECALAGE_X),(JEU_POSGRILLE_Y - compteur_y * JA_DECALAGE_Y),0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
				compteur_x++;
			}
			
			if((_X>= JA_POSBOUT_XG && _X<= JA_POSBOUT_XD) && (_Y>= JA_POSBOUT_BLEU_YH && _Y<= JA_POSBOUT_BLEU_YB) && compteur_x!=4 && compteur_y!=10) {	
				Proposition_couleurs[compteur_x]= BLEU;
				ChargerImage("bleu.png", (JEU_POSGRILLE_X + compteur_x * JA_DECALAGE_X),(JEU_POSGRILLE_Y - compteur_y * JA_DECALAGE_Y),0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
				compteur_x++;
			}
			
			if((_X>= JA_POSBOUT_XG && _X<= JA_POSBOUT_XD) && (_Y>= JA_POSBOUT_VERT_YH && _Y<= JA_POSBOUT_VERT_YB) && compteur_x!=4 && compteur_y!=10) {	
				Proposition_couleurs[compteur_x]= VERT;
				ChargerImage("vert.png", (JEU_POSGRILLE_X + compteur_x * JA_DECALAGE_X),(JEU_POSGRILLE_Y - compteur_y * JA_DECALAGE_Y),0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
				compteur_x++;
			}

			if((_X>= JA_POSBOUT_XG && _X<= JA_POSBOUT_XD) && (_Y>= JA_POSBOUT_ORANGE_YH && _Y<= JA_POSBOUT_ORANGE_YB) && compteur_x!=4 && compteur_y!=10) {	
				Proposition_couleurs[compteur_x]= ORANGE;
				ChargerImage("orange.png", (JEU_POSGRILLE_X + compteur_x * JA_DECALAGE_X),(JEU_POSGRILLE_Y - compteur_y * JA_DECALAGE_Y),0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
				compteur_x++;
			}

			if((_X>= JA_POSBOUT_XG && _X<= JA_POSBOUT_XD) && (_Y>= JA_POSBOUT_ROSE_YH && _Y<= JA_POSBOUT_ROSE_YB) && compteur_x!=4 && compteur_y!=10) {	
				Proposition_couleurs[compteur_x]= ROSE;
				ChargerImage("rose.png", (JEU_POSGRILLE_X + compteur_x * JA_DECALAGE_X),(JEU_POSGRILLE_Y - compteur_y * JA_DECALAGE_Y),0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
				compteur_x++;
			}



			/* Clic Validé */

			if((_X>= JA_POSBOUT_VALIDE_XG && _X<= JA_POSBOUT_VALIDE_XD) && (_Y>= JA_POSBOUT_VALIDE_YH && _Y<= JA_POSBOUT_VALIDE_YB) && compteur_x==4 && nb_coup<10) {
				
				/* Décalage des lignes et colonnes */
				nb_coup ++;
				printf("coup %d\n",nb_coup );
				compteur_x= 0;
				compteur_y+= 1;

				/* Perdu */
				if(compteur_y==10) {
				choix=-1;
				break;
				}

				/* Gagne */
				if(compteur_y==10) {
				choix=1;
				break;
				}

			/* Comparaison */

			
							
				for(i=0; i<4; i++) {
					Combi_secrete_alea_nouv[i] =  Combi_secrete_alea[i];
					Proposition_couleurs_nouv[i] = Proposition_couleurs[i];
				}

				for(i=0; i<4; i++) {
					if(Combi_secrete_alea_nouv[i]==Proposition_couleurs[i]) {
						compt_x++;
						bien_place++;

						ChoisirCouleurDessin(CouleurParNom("black"));
						RemplirArc(COMP_X+(compt_x-1)*COMP_DECALAGE_X,COMP_Y-(nb_coup-1)*COMP_DECALAGE_Y,COMP_TAILLE_PIECE,COMP_TAILLE_PIECE,360,360);

						Combi_secrete_alea_nouv[i]=10;
						Proposition_couleurs_nouv[i]=11;
					}
				}

				for(i=0; i<4; i++) {
					for(j=0; j<4; j++) {
						if( Combi_secrete_alea_nouv[i]==Proposition_couleurs_nouv[j]) {
							compt_x++;
							mal_place++;

							ChoisirCouleurDessin(CouleurParNom("red"));
							RemplirArc(COMP_X+(compt_x-1)*COMP_DECALAGE_X,COMP_Y-(nb_coup-1)*COMP_DECALAGE_Y,COMP_TAILLE_PIECE,COMP_TAILLE_PIECE,360,360);

							Combi_secrete_alea_nouv[i]=12;
							Proposition_couleurs_nouv[i]=13;
						}

					}
				}
				compt_x= 0; 
			

			}




		}

		CopierZone(1,0,0,0,TAILLE_ECRAN_X,TAILLE_ECRAN_Y,0,0);
	}
	if(choix==-1)
		Perdu(Combi_secrete_alea);
	if(choix==1)
		Gagne(Combi_secrete_alea);
	
}




void Jeu_def(int Combi_secrete[]) {


	int compteur= 0;
	int i= 0,j= 0;
	int nb_coup= 0;
	int Proposition_couleurs[4];
	int Proposition_couleurs_nouv[4];
	int Combi_secrete_nouv[4];
	int compteur_x= 0;
	int compteur_y= 0;
	int choix= 0;
	int bien_place,mal_place;
	int compt_x= 0;
	printf("Jeu defenseur\n");

	ChoisirEcran(3);
	srand((unsigned int) time(NULL));
	CopierZone(3,0,0,0,TAILLE_ECRAN_X,TAILLE_ECRAN_Y,0,0);
	ChargerImage("jeudef.png", 0,0,0,0,TAILLE_ECRAN_X,TAILLE_ECRAN_Y);
	
	

	/* affichage de la combinaison secrete */

	for (compteur=0; compteur<4; compteur++) {

		if (Combi_secrete[compteur]==ROUGE) {
			ChargerImage("rouge.png", JD_POSBOUT_X + compteur * JD_DECALAGE_X,JD_POSBOUT_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
		if (Combi_secrete[compteur]==JAUNE) {
			ChargerImage("jaune.png", JD_POSBOUT_X + compteur * JD_DECALAGE_X,JD_POSBOUT_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
		if (Combi_secrete[compteur]==BLEU) {
			ChargerImage("bleu.png", JD_POSBOUT_X + compteur * JD_DECALAGE_X,JD_POSBOUT_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
		if (Combi_secrete[compteur]==VERT) {
			ChargerImage("vert.png", JD_POSBOUT_X + compteur * JD_DECALAGE_X,JD_POSBOUT_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
		if (Combi_secrete[compteur]==ORANGE) {
			ChargerImage("orange.png", JD_POSBOUT_X + compteur * JD_DECALAGE_X,JD_POSBOUT_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
		if (Combi_secrete[compteur]==ROSE) {
			ChargerImage("rose.png", JD_POSBOUT_X + compteur * JD_DECALAGE_X,JD_POSBOUT_Y,0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
		}
	}


	/* Code IA */

	while(1) {

		/* Clic validé pour choisir les couleurs aléatoirement */

		if (SourisCliquee()) {
			SourisPosition();

			if((_X>= JA_POSBOUT_VALIDE_XG && _X<= JA_POSBOUT_VALIDE_XD) && (_Y>= JA_POSBOUT_VALIDE_YH && _Y<= JA_POSBOUT_VALIDE_YB) && compteur_y<10) {
				
				nb_coup ++;

				for (i = 0; i < 4; ++i) {
					Proposition_couleurs[i]= rand()%(6-0)-0;
				}
							
					for ( compteur_x = 0; compteur_x < 4; compteur_x++) {
					
						if(Proposition_couleurs[compteur_x]== ROUGE) {	
							ChargerImage("rouge.png", (JEU_POSGRILLE_X + compteur_x * JA_DECALAGE_X),(JEU_POSGRILLE_Y - compteur_y * JA_DECALAGE_Y),0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
						}

						if(Proposition_couleurs[compteur_x]== JAUNE) {	
							ChargerImage("jaune.png", (JEU_POSGRILLE_X + compteur_x * JA_DECALAGE_X),(JEU_POSGRILLE_Y - compteur_y * JA_DECALAGE_Y),0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
						}
						
						if(Proposition_couleurs[compteur_x]== BLEU) {	
							ChargerImage("bleu.png", (JEU_POSGRILLE_X + compteur_x * JA_DECALAGE_X),(JEU_POSGRILLE_Y - compteur_y * JA_DECALAGE_Y),0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
						}
						
						if(Proposition_couleurs[compteur_x]== VERT) {
							ChargerImage("vert.png", (JEU_POSGRILLE_X + compteur_x * JA_DECALAGE_X),(JEU_POSGRILLE_Y - compteur_y * JA_DECALAGE_Y),0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
						}

						if(Proposition_couleurs[compteur_x]== ORANGE) {	
							ChargerImage("orange.png", (JEU_POSGRILLE_X + compteur_x * JA_DECALAGE_X),(JEU_POSGRILLE_Y - compteur_y * JA_DECALAGE_Y),0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
						}

						if(Proposition_couleurs[compteur_x]== ROSE) {	
							ChargerImage("rose.png", (JEU_POSGRILLE_X + compteur_x * JA_DECALAGE_X),(JEU_POSGRILLE_Y - compteur_y * JA_DECALAGE_Y),0,0,TAILLE_BOUT_X,TAILLE_BOUT_Y);
						}
					}


						if (compteur_x==4 && nb_coup<10) {

							/* Comparaison */
							for(i=0; i<4; i++) {
								Combi_secrete_nouv[i] = Combi_secrete[i];
								Proposition_couleurs_nouv[i] = Proposition_couleurs[i];
							}

							for(i=0; i<4; i++) {
								if(Combi_secrete_nouv[i]==Proposition_couleurs[i]) {
									compt_x++;
									bien_place++;

									ChoisirCouleurDessin(CouleurParNom("black"));
									RemplirArc(COMP_X+(compt_x-1)*COMP_DECALAGE_X,COMP_Y-(nb_coup-1)*COMP_DECALAGE_Y,COMP_TAILLE_PIECE,COMP_TAILLE_PIECE,360,360);

									Combi_secrete_nouv[i]=10;
									Proposition_couleurs_nouv[i]=11;
								}
							}

							for(i=0; i<4; i++) {
								for(j=0; j<4; j++) {
									if(Combi_secrete_nouv[i]==Proposition_couleurs_nouv[j]) {
										compt_x++;
										mal_place++;

										ChoisirCouleurDessin(CouleurParNom("red"));
										RemplirArc(COMP_X+(compt_x-1)*COMP_DECALAGE_X,COMP_Y-(nb_coup-1)*COMP_DECALAGE_Y,COMP_TAILLE_PIECE,COMP_TAILLE_PIECE,360,360);

										Combi_secrete_nouv[i]=12;
										Proposition_couleurs_nouv[i]=13;
									}

								}
							}
							compt_x= 0; 


							
						}

						if (compteur_x==4) {


							/* Décalage des lignes et colonnes */
							compteur_x= 0;
							compteur_y++;
						}

							/* Perdu */
							if(compteur_y==10) {
							choix= -1;
							break;
							}

							/* Gagne */
							if(compteur_y==10) {
							choix=1;
							break;
							}
			}
		}
		CopierZone(3,0,0,0,TAILLE_ECRAN_X,TAILLE_ECRAN_Y,0,0);
	}
	if(choix==-1) {
		Perdu(Combi_secrete);
	}
	if(choix==1) {
		Gagne(Combi_secrete);
	}
	
}
