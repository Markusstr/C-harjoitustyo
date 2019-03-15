Harjoitustyo: paaohjelma.o ali1.o ali2.o ali3.o
	gcc paaohjelma.o ali1.o ali2.o ali3.o -o HT
paaohjelma.o: paaohjelma.c ali1.h ali2.h ali3.h
	gcc paaohjelma.c -c -Wall -std=c99
ali1.o: ali1.c ali1.h ali2.h
	gcc ali1.c -c -Wall -std=c99
ali2.o: ali2.c ali1.h ali2.h
	gcc ali2.c -c -Wall -std=c99
ali3.o: ali3.c ali1.h ali2.h
	gcc ali3.c -c -Wall -std=c99
