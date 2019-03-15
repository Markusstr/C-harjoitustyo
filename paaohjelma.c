#include <stdio.h>
#include "ali1.h"
#include "ali2.h"
#include "ali3.h"

int main(void) {
    int valinta;
    struct Tiedot *pAlku1 = NULL;
    struct Tulos *pAlku2 = NULL;
	char tiedNimi[20];
    printf("\nTämä ohjelma tutkii nimitietoja sisältäviä tiedostoja.\n");
    while (1) {
        /*Tulostetaan käyttäjälle valikko*/
        printf("\nValitse haluamasi toiminto alla olevasta valikosta:\n");
        printf("1) Lue nimitiedosto\n2) Tulosta listassa olevat tiedot\n3) Analysoi tiedot\n4) Tulosta kaikki tulostiedot\n5) Tallenna kaikki tulostiedot tiedostoon\n6) Tyhjennä tuloslista\n0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &valinta);
        /*Tutkitaan minkä toiminnon käyttäjä valitsee*/
        if (valinta == 1) { /*Lue nimitiedosto*/
			printf("Anna luettavan tiedoston nimi: ");
    		scanf("%s", tiedNimi);
            if (pAlku1 != NULL) {
				printf("Poistetaan aiemmat tiedot ja luetaan uudet.\n");
                muistinVapautus(pAlku1,NULL);
            }
            pAlku1 = lukeminen(tiedNimi);
        }
        else if (valinta == 2) { /*Tulosta listassa olevat tiedot*/
            tulosta(pAlku1);
        }
        else if (valinta == 3) { /*Analysoi tiedot*/
            pAlku2 = analysointi(pAlku1,pAlku2);
        }
        else if (valinta == 4) { /*Tulosta kaikki tulostiedot*/
            tulostaTulos(pAlku2);
        }
        else if (valinta == 5) { /*Tallenna kaikki tulostiedot tiedostoon*/
            kirjoittaminen(pAlku2);
        }
        else if (valinta == 6) { /*Tyhjennä tuloslista*/
            muistinVapautus(NULL,pAlku2);
            pAlku2 = NULL;
            printf("Tuloslista tyhjennetty.\n");
        }
        else if (valinta == 0) { /*Lopeta*/
            muistinVapautus(pAlku1,pAlku2);
            printf("Kiitos ohjelman käytöstä.\n");
            break;
        }
        else { /*Tuntematon valinta*/
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
    }
}

/*****************************************************************************/
/* eof */