#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseWords(char* s) {
    int len = strlen(s);
    //char** word = (char**)malloc(1000 * sizeof(char*));
    char word[1000][30];
    int i = 0;
    int offset = 0;
    int fast = 0, slow = 0;
    while(s[fast] == ' ') {
        fast++;
    }
    
    while(fast < len - 1) {
        if (s[fast] == ' ' && s[fast + 1] == ' ') {
            fast++;
        } else {
            s[slow++] = s[fast++];
        }
    }

    if (s[fast] == ' ') {
        s[slow] = '\0';
    } else {
        s[slow++] = s[fast];
        s[slow] = '\0';
    } 

    while(slow <= len - 1) {
        s[++slow] = '\0';
    }

    while(sscanf(s + offset, "%s", word[i]) == 1) {
        offset += strlen(word[i]) + 1;
        i++;
    }
    i--;
    memset(s, '\0', len);
    for (int j = i; j >= 0; j--) {
        if (j != i) {
            strcat(s, " ");
        }
        strcat(s, word[j]);
    }
    //free(word);
    return s;
}

int main() {
    char words[] = "  the sky  is blue  ";
    char *reversed_words = reverseWords(words);
    printf("%s\n", reversed_words);
}