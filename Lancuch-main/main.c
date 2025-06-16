#include <stdio.h>

void male_litery(char *ciag)
{
    while (*ciag)
    {
        if ('A' <= *ciag && *ciag <= 'Z')
        {
            *ciag += ('a' - 'A');
        }
        ciag++;
    }
}

void wielkie_litery(char *ciag)
{
    while (*ciag)
    {
        if ('a' <= *ciag && *ciag <= 'z')
        {
            *ciag -= ('a' - 'A');
        }
        ciag++;
    }
}

int dlugosc_teksu(char*ciag)
{
    int i;
    while(*ciag)
    {
        i++;
        ciag++;
    }
    return i;
}

int main() {

    char ciag[] = "wrEhWuy35Y?><$12";
    printf("%s\n", ciag);

    male_litery(ciag);
    printf("%s\n", ciag);

    wielkie_litery(ciag);
    printf("%s\n", ciag);

    printf("text is %d letters long\n", dlugosc_teksu(ciag));

    return 0;
}