#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ali1.h"
#include "ali2.h"

void tulosta(struct Tiedot *pAlku1) {
    /*Tulostetaan linkitetyn listan sisältö käyttäjälle*/
    printf("Linkitetyn listan sisältö:\n");
    struct Tiedot *ptr;
    ptr = pAlku1;
    while (ptr != NULL) {
        printf("%s\n", ptr->nimi);
        ptr = ptr->seuraava;
    }
}

void tulostaTulos(struct Tulos *pAlku2) {
    /*Tulostetaan tuloslistan sisältö käyttäjälle*/
    struct Tulos *ptr2;
    ptr2 = pAlku2;
    if (ptr2 == NULL) {
        printf("Tuloslista on tyhjä.\n");
    }
    else {
        printf("Datasetti Nimiä PitMin PitMax PitKA\n");
    }
    while (ptr2 != NULL) {
        printf("%-9s ", ptr2->datasetti);
        printf("%5d ", ptr2->rivimaara);
        printf("%6d ", ptr2->pitMin);
        printf("%6d ", ptr2->pitMax);
        printf("%5.1f\n", ptr2->pitKA);
        ptr2 = ptr2->seuraava;
    }   
}
/*****************************************************************************/
/* eof */