#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ali1.h"
#include "ali2.h"

struct Tulos* analysointi(struct Tiedot *pAlku1, struct Tulos *pAlku2) {
    struct Tiedot *ptr1;
    struct Tulos *ptr2, *ptrUusi;
    int rivimaara = 0, pituusMin = 1000, pituusMax = 0;
    float pituusKA = 0;
    char tiedNimi[20];
    if (pAlku1 == NULL) {
        printf("Ei analysoitavaa, lue ensin nimitiedosto.\n");
        exit(1);
    }
    ptr1 = pAlku1;
    /*Käydään läpi ensimmäistä linkitettyä listaa ja lasketaan
    lyhyin ja pisin alkio sekä keskiarvo*/
    while (ptr1 != NULL) {
        if (strlen(ptr1->nimi) < pituusMin) {
            pituusMin = strlen(ptr1->nimi);
        }
        if (strlen(ptr1->nimi) > pituusMax) {
            pituusMax = strlen(ptr1->nimi);
        }
        pituusKA += strlen(ptr1->nimi);
        ptr1 = ptr1->seuraava;
        rivimaara++;
    }
    pituusKA /= rivimaara;
    /*Varataan muisti toiselle linkitetylle listalle*/
    if ((ptrUusi = (struct Tulos*)malloc(sizeof(struct Tulos))) == NULL) {
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    /*Kopioidaan ensimmäisestä linkitetystä listasta tiedot tuloslistaan*/
    printf("Anna analysoitavalle datasetille nimi: ");
    scanf("%s", tiedNimi);
    printf("Analysoidaan listassa olevat tiedot.\n");
    /*Kopioidaan tiedot toisesta linkitetystä listasta tuloslistaan*/
    strcpy(ptrUusi->datasetti,tiedNimi);
    ptrUusi->rivimaara = rivimaara;
    ptrUusi->pitKA = pituusKA;
    ptrUusi->pitMin = pituusMin;
    ptrUusi->pitMax = pituusMax;
    ptrUusi->seuraava = NULL;
    /*Tutkitaan onko linkitetyssä listassa jo ensimmäistä alkiota*/
    if (pAlku2 == NULL) {
        /*Laitetaan arvo ensimmäiseksi jos lista on tyhjä*/
        pAlku2 = ptrUusi;
    }
    else {
        /*Mennään listan viimeiseen alkioon ja laitetaan uusi arvo seuraavaan tyhjään kohtaan*/
        ptr2 = pAlku2;
        while (ptr2->seuraava != NULL) {
            ptr2 = ptr2->seuraava;
        }
        ptr2->seuraava = ptrUusi;
    }
    /*Tulostetaan käyttäjälle tiedot*/
    printf("Datasetti Nimiä PitMin PitMax PitKA\n");
    printf("%-9s %5d %6d %6d %5.1f\n", tiedNimi, rivimaara, pituusMin, pituusMax, pituusKA);
    return(pAlku2);
}

void muistinVapautus(struct Tiedot *pAlku1, struct Tulos *pAlku2) {
    /*Tällä aliohjelmalla voi tyhjentää jommankumman tai molemmat listat yhtäaikaa
    Muistin vapauksen voi tehdä ainoastaan toiselle listalla laittamalla toiseksi parametriksi NULL,
    jolloin myös pointerin arvoksi tulee NULL ja while lauseke ei toteudu kertaakaan*/
    struct Tiedot *ptr1;
    struct Tulos *ptr2;
    ptr1 = pAlku1;
    ptr2 = pAlku2;
    while (ptr1 != NULL) {
        pAlku1 = ptr1->seuraava;
        free(ptr1);
        ptr1 = pAlku1;
    }
    while (ptr2 != NULL) {
        pAlku2 = ptr2->seuraava;
        free(ptr2);
        ptr2 = pAlku2;
    }
}

/*****************************************************************************/
/* eof */