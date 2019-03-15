struct Tiedot {
    char nimi[20];
    struct Tiedot *seuraava;
};

struct Tulos {
    char datasetti[20];
    int rivimaara;
    int pitMin;
    int pitMax;
    float pitKA;
    struct Tulos *seuraava;
};
struct Tiedot* lukeminen(char tiedNimi[20]);
void kirjoittaminen(struct Tulos *pAlku2);
/*****************************************************************************/
/* eof */