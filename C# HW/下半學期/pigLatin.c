#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void pigLatin(const char*);

int isVowel(char c) {
    char* vowels = "AEIOUaeiou";
    for (int i = 0; i < 10; i++) {
        if (c == vowels[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    const char* words[4][5] = {
        {"the", "a", "one", "some", "any"},
        {"boy", "girl", "dog", "town", "car"},
        {"drove", "jumped", "ran", "walked", "skipped"},
        {"to", "from", "over", "under", "on"}
    };
    char sentence[20][35] = { 0 };
    srand(time(0));
    for (int i = 0; i < 20; i++) {

        for (int j = 0; j <= 5; j++) {

            strcat(sentence[i], words[j % 4][rand() % 5]);
            if (j != 5) {
                strcat(sentence[i], " ");
            }
        }
        strcat(sentence[i], ".");
        sentence[i][0] = toupper(sentence[i][0]);
        printf("%s ", sentence[i]);
    }

    puts("");
    getchar();

    char sentence2[20][40] = { '\0' };

    for (int i = 0; i < 20; i++) {
        strcpy(sentence2[i], sentence[i]);
        int n = 1;
        for (int j = 0; j < strlen(sentence[i]) - 1; j++) {
            if (isVowel(sentence[i][j])) {
                strcpy(sentence2[i] + j + n++, sentence[i] + j);
                j = strchr(sentence[i] + j, ' ') - sentence[i];
            }
        }
        printf("%s ", sentence2[i]);
    }

    puts("");
    getchar();

    for (int i = 0; i < 20; i++) {
        pigLatin(sentence2[i]);
    }
    return 0;
}

void pigLatin(const char* str) {

    char out[8];

    int now2 = 0;
    char temp = tolower(str[0]);
    for (int now = 1; str[now] != '.'; now++) {
        if (str[now] == ' ') {
            out[now2] = '\0';
            printf("%s%cay ", out, temp);
            now2 = 0;
        }
        else if (str[now - 1] == ' ') {
            temp = str[now];
        }
        else {
            out[now2++] = str[now];
        }
    }

    out[now2] = '\0';
    printf("%s%cay. ", out, temp);
}

