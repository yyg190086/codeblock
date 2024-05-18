#include<stdio.h>
#include<string.h>

void reverse(char *s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
    return;
}

char* reverseWords(char* s) {
    int len = strlen(s);
    int fast = 0, slow = 0;

    while (s[fast] == ' ') {
        fast++;
    }

    while (fast < len - 1) {
        if (s[fast] == ' ' && s[fast + 1] == ' ') {
            fast++;
        } else {
            s[slow++] = s[fast++];
        }
    }

    if (s[fast] == ' ') {
        s[slow] == '\0';
    } else {
        s[slow++] = s[fast];
        s[slow] = '\0';
    }

    reverse(s, 0, slow - 1);
    
    for (int i = 0; i < slow; i++) {
        int j = i;
        while (j < slow && s[j] != ' ') {
            j++;
        }
        reverse(s, i, j - 1);
        i = j;
    }
    return s;
}

int main() {
    char *words = "  hello world  ";
    printf("%s\n", reverseWords(words));
}