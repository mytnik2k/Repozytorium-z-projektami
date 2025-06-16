#include <stdio.h>

int polaczTekst(char *source1, char *source2, char *destination) {

    sprintf(destination, "%s%s", source1, source2);

    return 0;
}

int main() {
    char str1[] = "Ala";
    char str2[] = " ma kota.";
    char str3[80]= "";

    polaczTekst(str1, str2, str3);
    printf("Poleczenie tekst: %s\n", str3);

    return 0;
}


