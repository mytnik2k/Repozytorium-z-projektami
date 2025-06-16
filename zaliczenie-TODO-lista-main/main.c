#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ZADAN 100
#define DLUGOSC_TEKSTU 100
#define PLIK "zadania.txt"

typedef struct {
    char opis[DLUGOSC_TEKSTU];
    int wykonane;
} Zadanie;

Zadanie listaZadan[MAX_ZADAN];
int liczbaZadan = 0;

void zapiszDoPliku() {
    FILE *plik = fopen(PLIK, "w");
    if (plik == NULL) {
        printf("Blad przy zapisie do pliku!\n");
        return;
    }

    for (int i = 0; i < liczbaZadan; i++) {
        fprintf(plik, "%d|%s\n", listaZadan[i].wykonane, listaZadan[i].opis);
    }

    fclose(plik);
}

void wczytajZPliku() {
    FILE *plik = fopen(PLIK, "r");
    if (plik == NULL) return;

    char linia[DLUGOSC_TEKSTU + 10];
    while (fgets(linia, sizeof(linia), plik)) {
        char *sep = strchr(linia, '|');
        if (sep) {
            *sep = '\0';
            listaZadan[liczbaZadan].wykonane = atoi(linia);
            strncpy(listaZadan[liczbaZadan].opis, sep + 1, DLUGOSC_TEKSTU);
            listaZadan[liczbaZadan].opis[strcspn(listaZadan[liczbaZadan].opis, "\n")] = '\0';
            liczbaZadan++;
        }
    }

    fclose(plik);
}

void pokazListe() {
    printf("\n===== LISTA ZADAN =====\n");
    if (liczbaZadan == 0) {
        printf("Brak zadan.\n");
    } else {
        for (int i = 0; i < liczbaZadan; i++) {
            printf("%d. [%s] %s\n", i + 1,
                   listaZadan[i].wykonane ? "X" : " ", listaZadan[i].opis);
        }
    }
}

void dodajZadanie() {
    if (liczbaZadan >= MAX_ZADAN) return;
    getchar(); // czyszczenie bufora
    printf("Opis zadania: ");
    fgets(listaZadan[liczbaZadan].opis, DLUGOSC_TEKSTU, stdin);
    listaZadan[liczbaZadan].opis[strcspn(listaZadan[liczbaZadan].opis, "\n")] = '\0';
    listaZadan[liczbaZadan].wykonane = 0;
    liczbaZadan++;
    zapiszDoPliku();
}

void usunZadanie() {
    int index;
    printf("Nr zadania do usuniecia: ");
    scanf("%d", &index);
    if (index < 1 || index > liczbaZadan) return;

    for (int i = index - 1; i < liczbaZadan - 1; i++) {
        listaZadan[i] = listaZadan[i + 1];
    }
    liczbaZadan--;
    zapiszDoPliku();
}

void zmienStatus() {
    int index;
    printf("Nr zadania do zmiany statusu: ");
    scanf("%d", &index);
    if (index < 1 || index > liczbaZadan) return;

    listaZadan[index - 1].wykonane = !listaZadan[index - 1].wykonane;
    zapiszDoPliku();
}

int main() {
    int wybor;
    wczytajZPliku();

    do {
        printf("\n1. Pokaz zadania\n2. Dodaj zadanie\n3. Usun zadanie\n4. Zmien status\n5. Wyjscie\nWybierz: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1: pokazListe(); break;
            case 2: dodajZadanie(); break;
            case 3: usunZadanie(); break;
            case 4: zmienStatus(); break;
            case 5: printf("Do widzenia!\n"); break;
            default: printf("Nieprawidlowy wybor.\n");
        }

    } while (wybor != 5);

    return 0;
}
