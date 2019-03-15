#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ali1.h"
#include "ali2.h"

struct Tiedot* lukeminen(char tiedNimi[20]) {
    struct Tiedot *pAlku = NULL, *ptr, *ptrUusi;
    char muisti[20];
    int rivimaara = 0;
    FILE *tiedosto;
    printf("Luetaan tiedosto '%s'.\n", tiedNimi);
    /*Avataan tiedosto*/
    if ((tiedosto = fopen(tiedNimi, "r")) == NULL) {
        /*Virheenkäsittely, jos tiedoston avaaminen epäonnistuu*/
        perror("Tiedoston avaaminen epäonnistui.\n");
        exit(1);
    }
    /*Luetaan tiedostoa*/
    while(fgets(muisti,20,tiedosto) != NULL) {
        muisti[strlen(muisti)-1] = '\0';
        if ((ptrUusi = (struct Tiedot*)malloc(sizeof(struct Tiedot))) == NULL) {
            /*Virheenkäsittely, jos muistinvaraus epäonnistuu*/
            perror("Muistin varaus epäonnistui.\n");
            exit(1);
        }
        /*Luettujen tietojen laittaminen linkitettyyn listaan*/
        strcpy(ptrUusi->nimi,muisti);
        ptrUusi->seuraava = NULL;
        /*Tutkitaan onko linkitetyssä listassa jo ensimmäistä alkiota*/
        if (pAlku == NULL) {
            /*Laitetaan arvo ensimmäiseksi jos lista on tyhjä*/
            pAlku = ptrUusi;
        }
        else {
            /*Mennään listan viimeiseen alkioon ja laitetaan uusi arvo seuraavaan tyhjään kohta*/
            ptr = pAlku;
            while (ptr->seuraava != NULL) {
                ptr = ptr->seuraava;
            }
            ptr->seuraava = ptrUusi;
        }
        rivimaara++;
    }
    /*Suljetaan tiedosto ja palautetaan pAlku*/
    fclose(tiedosto);
    printf("Tiedosto '%s' luettu, %d nimiriviä.\n", tiedNimi, rivimaara);
    return(pAlku);
}

void kirjoittaminen(struct Tulos *pAlku2) {
    char tiedNimi[20];
    struct Tulos *ptr2;
    ptr2 = pAlku2;
    FILE *tiedosto;
    /*Kysytään käyttäjältä tallennettavan tiedoston nimi*/
    printf("Anna tallennettavan tulostiedoston nimi: ");
    scanf("%s", tiedNimi);
    /*Tiedoston avaamisen virheenkäsittely*/
    if ((tiedosto = fopen(tiedNimi, "w")) == NULL ) {
        printf("Tiedoston avaaminen epäonnistui.\n");
        exit(1);
    }
    /*Kirjoitetaan linkitetyn listan tiedot tiedostoon*/
    fprintf(tiedosto, "Datasetti Nimiä PitMin PitMax PitKA\n");
    while (ptr2 != NULL) {
        fprintf(tiedosto, "%-9s ", ptr2->datasetti);
        fprintf(tiedosto, "%5d ", ptr2->rivimaara);
        fprintf(tiedosto, "%6d ", ptr2->pitMin);
        fprintf(tiedosto, "%6d ", ptr2->pitMax);
        fprintf(tiedosto, "%5.1f\n", ptr2->pitKA);
        ptr2 = ptr2->seuraava;
    }
    /*Annetaan käyttäjälle tieto onnistuneesta tallennuksesta ja suljetaan tiedosto*/
	printf("Tiedosto tallennettu.\n");
    fclose(tiedosto);
}
/*****************************************************************************/
/* eof */