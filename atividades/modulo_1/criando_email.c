#include <stdio.h>
#include <ctype.h>

int main(void) {
    char s[201];
    if (!fgets(s, sizeof(s), stdin)) return 0;

    int len = 0;
    while (s[len] != '\0') len++;
    if (len > 0 && s[len-1] == '\n') {
        s[len-1] = '\0';
        len--;
    }

    int i = 0;
    while (s[i] == ' ') i++;
    while (s[i] != '\0' && s[i] != ' ') {
        putchar(tolower((unsigned char)s[i]));
        i++;
    }

    putchar('.');

    int j = len - 1;
    while (j >= 0 && s[j] == ' ') j--; 
    int end_last = j;
    while (j >= 0 && s[j] != ' ') j--;
    int start_last = j + 1;

    for (i = start_last; i <= end_last; i++) putchar(tolower((unsigned char)s[i]));

    printf("@unb.br\n");
    return 0;
}
