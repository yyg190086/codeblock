#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define true (1U)
#define false (0U)

int IsIPv4(char* queryIP) {
    int count_dot = 0;
    for (int i = 0; i < strlen(queryIP); i++) {
        if (queryIP[i] == '.') {
            count_dot++;
        }
        if (!isdigit(queryIP[i]) && queryIP[i] != '.') {
            return false;
        }
        if (i == 1 && queryIP[i - 1] == '0' && isdigit(queryIP[i])) {
            return false;
        }
        if (i >= 1 && queryIP[i - 1] == '.' && queryIP[i] == '.') {
            return false;
        }
        if (i >= 2 && queryIP[i - 2] == '.' && queryIP[i - 1] == '0' && isdigit(queryIP[i])) {
            return false;
        }
    }
    if (count_dot != 3) return false;
    if (queryIP[strlen(queryIP) - 1] == '.') return false;

    int v4[4] = {0};
    sscanf(queryIP, "%d.%d.%d.%d", &v4[0], &v4[1], &v4[2], &v4[3]);
    for (int i = 0; i < 4; i++) {
        if (v4[i] < 0 || 255 < v4[i]) {
            return false;
        }
    }

    return true;
}

int ishex(char ch) {
    return ('0' <= ch && ch <= '9' ||
            'a' <= ch && ch <= 'f' ||
            'A' <= ch && ch <= 'F');
}

int IsIPv6(char* queryIP) {
    int count_colon = 0;
    int max_symbol = 0;
    for (int i = 0; i < strlen(queryIP); i++) {
        if (queryIP[i] == ':') {
            count_colon++;
            max_symbol = 0;
        } else {
            max_symbol++;
        }
        if (max_symbol > 4) {return false;}
        if (!ishex(queryIP[i]) && queryIP[i] != ':') {
            return false;
        }
        if (i >= 1 && queryIP[i - 1] == ':' && queryIP[i] == ':') {
            return false;
        }
    }
    if (count_colon != 7) return false;
    if (queryIP[strlen(queryIP) - 1] == ':') return false;

    int v6[8] = {0};
    sscanf(queryIP, "%x:%x:%x:%x:%x:%x:%x:%x", &v6[0], &v6[1], &v6[2], &v6[3], &v6[4], &v6[5], &v6[6], &v6[7]);
    for (int i = 0; i < 8; i++) {
        if (0xFFFF < v6[i]) {
            return false;
        }
    }
    return true;
}

char* validIPAddress(char* queryIP) {
    if (IsIPv4(queryIP)) {
        return "IPv4";
    } else if (IsIPv6(queryIP)){
        return "IPv6";
    }
    return "Neither";
}

int main() {
    char queryIP[] = "2001:0db8:85a3:0:0:8A2E:0370:7334";
    printf("%s\n", validIPAddress(queryIP));
}