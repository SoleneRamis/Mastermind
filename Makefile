# Variables

CC = gcc

CFLAGS = -Wall -ansi -pedantic -g

EXE = mastermind

OFILES = affichage_perdu_gagne.o  \
         main.o   \
         jeu_att_and_jeu_def.o    \
         menu.o 	\
         combinaison_secrete.o    \

# But 

but : ${EXE}

# Règles

affichage_perdu_gagne.o : affichage_perdu_gagne.h 
jeu_att_and_jeu_def.o : jeu_att_and_jeu_def.h   
menu.o : menu.h
combinaison_secrete.o : combinaison_secrete.h  


# Commandes

mastermind : $(OFILES)
	$(CC) $(CFLAGS) -o mastermind $(OFILES) -lgraph

# Nettoyage

clean :
	-rm -f $(OFILES) mastermind

.PHONY : but clean
