#include "notifikaattori.h"

int main() {
    Notifikaattori n;
    Seuraaja s1("Matti");
    Seuraaja s2("Teppo");
    Seuraaja s3("Maija");
    n.lisaa(&s1);
    n.lisaa(&s2);
    n.lisaa(&s3);
    n.tulosta();
    n.postita("Hei kaikki!");
    n.poista(&s2);
    n.tulosta();
    n.postita("Hei hei Teppo!");
    return 0;
}
