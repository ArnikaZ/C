#include <stdio.h>
#include <string.h>

#define MAX_KONTAKTOW 100

struct Contact {
    char imie[50];
    char nazwisko[50];
    char numer_telefonu[15];
};

// Funkcja dodająca nowy kontakt do książki adresowej
void dodajKontakt(struct Contact *ksiazka_adresowa, int *liczba_kontaktow, char imie[], char nazwisko[], char numer_telefonu[]) {
    if (*liczba_kontaktow < MAX_KONTAKTOW) {
        strcpy(ksiazka_adresowa[*liczba_kontaktow].imie, imie);
        strcpy(ksiazka_adresowa[*liczba_kontaktow].nazwisko, nazwisko);
        strcpy(ksiazka_adresowa[*liczba_kontaktow].numer_telefonu, numer_telefonu);
        (*liczba_kontaktow)++;
        printf("Kontakt dodany pomyslnie.\n");
    } else {
        printf("Ksiazka adresowa pelna.\n");
    }
}

// Funkcja wyszukująca kontakt po nazwisku
void wyszukajKontaktPoNazwisku(struct Contact *ksiazka_adresowa, int liczba_kontaktow, char nazwisko[]) {
    int znaleziono = 0;
    for (int i = 0; i < liczba_kontaktow; i++) {
        if (strcmp(ksiazka_adresowa[i].nazwisko, nazwisko) == 0) {
            printf("Znaleziono kontakt:\n");
            printf("Imie: %s\n", ksiazka_adresowa[i].imie);
            printf("Nazwisko: %s\n", ksiazka_adresowa[i].nazwisko);
            printf("Numer telefonu: %s\n", ksiazka_adresowa[i].numer_telefonu);
            znaleziono = 1;
        }
    }
    if (!znaleziono) {
        printf("Nie znaleziono kontaktu o podanym nazwisku.\n");
    }
}

// Funkcja usuwająca kontakt po nazwisku
void usunKontaktPoNazwisku(struct Contact *ksiazka_adresowa, int *liczba_kontaktow, char nazwisko[]) {
    int znaleziono = 0;
    for (int i = 0; i < *liczba_kontaktow; i++) {
        if (strcmp(ksiazka_adresowa[i].nazwisko, nazwisko) == 0) {
            for (int j = i; j < *liczba_kontaktow - 1; j++) {
                ksiazka_adresowa[j] = ksiazka_adresowa[j + 1];
            }
            (*liczba_kontaktow)--;
            znaleziono = 1;
            printf("Kontakt usuniety pomyslnie.\n");
            break;
        }
    }
    if (!znaleziono) {
        printf("Nie znaleziono kontaktu o podanym nazwisku.\n");
    }
}

// Funkcja wypisująca wszystkie kontakty w książce adresowej
void wypiszWszystkieKontakty(struct Contact *ksiazka_adresowa, int liczba_kontaktow) {
    printf("Lista kontaktow:\n");
    for (int i = 0; i < liczba_kontaktow; i++) {
        printf("%d. Imie: %s, Nazwisko: %s, Numer telefonu: %s\n", i + 1, ksiazka_adresowa[i].imie, ksiazka_adresowa[i].nazwisko, ksiazka_adresowa[i].numer_telefonu);
    }
}

int main() {
    struct Contact ksiazka_adresowa[MAX_KONTAKTOW]={{"Jan", "Kowalski", "123 456 789"},
                                                    {"Anna", "Nowak", "999 888 777"},
                                                    {"Marek", "Dabrowski", "234 567 890"}};
    int liczba_kontaktow = 3;
    char opcja;
    char imie[50], nazwisko[50], numer_telefonu[20];

    do {
        printf("\nMenu:\n");
        printf("1. Dodaj kontakt\n");
        printf("2. Znajdz kontakt po nazwisku\n");
        printf("3. Usun kontakt po nazwisku\n");
        printf("4. Wyswietl wszystkie kontakty\n");
        printf("5. Wyjscie\n");
        printf("Wybierz opcje: ");
        scanf(" %c", &opcja);

        switch (opcja) {
            case '1':
                printf("Podaj imie: ");
                scanf("%s", imie);
                printf("Podaj nazwisko: ");
                scanf("%s", nazwisko);
                printf("Podaj numer telefonu: ");
                scanf("%s", numer_telefonu);
                dodajKontakt(ksiazka_adresowa, &liczba_kontaktow, imie, nazwisko, numer_telefonu);
                break;
            case '2':
                printf("Podaj nazwisko: ");
                scanf("%s", nazwisko);
                wyszukajKontaktPoNazwisku(ksiazka_adresowa, liczba_kontaktow, nazwisko);
                break;
            case '3':
                printf("Podaj nazwisko: ");
                scanf("%s", nazwisko);
                usunKontaktPoNazwisku(ksiazka_adresowa, &liczba_kontaktow, nazwisko);
                break;
            case '4':
                wypiszWszystkieKontakty(ksiazka_adresowa, liczba_kontaktow);
                break;
            case '5':
                printf("Wyjscie z programu.\n");
                break;
            default:
                printf("Niepoprawna opcja. Wybierz ponownie.\n");
        }
    } while (opcja != '5');

    return 0;
}
