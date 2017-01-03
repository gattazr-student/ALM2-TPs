##################################################
#        Makefile automatically generated        #
# Brought to you by Jules HABLOT and Rémi GATTAZ #
##################################################

#-------------------------------------------------
#                    VARIABLES
#-------------------------------------------------
CC=e7tgcc
CFLAGS= -Wall
LIBRARIES=
EXECS=main

SRCS_0=main.c affichage_7Segs.c affichage_LEDs.c config_it.c ligneSerie.c
OBJS_0=${SRCS_0:.c=.o} irq.o

#-------------------------------------------------
#                     LINKINGS
#-------------------------------------------------
all: env $(EXECS)

env:
	./check_env.sh

main: $(OBJS_0) rs232.o
	$(CC) $(CFLAGS) -o main $(OBJS_0) rs232.o $(LIBRARIES)

#-------------------------------------------------
#                   DEPENDENCIES
#-------------------------------------------------
irq.o:	irq.s
	${CC} -c $^

main.o: main.c samsung.h evaluator.h rs232.h config_it.h affichage_7Segs.h affichage_LEDs.h ligneSerie.h
config_it.o: config_it.c config_it.h evaluator.h samsung.h
affichage_7Segs.o: affichage_7Segs.c affichage_7Segs.h samsung.h evaluator.h rs232.h config_it.h
affichage_LEDs.o: affichage_LEDs.c affichage_LEDs.h samsung.h evaluator.h rs232.h config_it.h
ligneSerie.o: ligneSerie.c ligneSerie.h samsung.h evaluator.h rs232.h config_it.h

samsung.h:
	ln -fs ${ARM_ENVDIR}/$@ .

evaluator.h:
	ln -fs ${ARM_ENVDIR}/$@ .
#-------------------------------------------------
#                     CLEANING
#-------------------------------------------------
clean_main:
	rm -f main $(OBJS_0)

clean: clean_main
