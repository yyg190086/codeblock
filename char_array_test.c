#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {

    char** strArr = (char**)malloc(3 * sizeof(char*));  // 动态创建指针数组
    for (int i = 0; i < 3; i++) {
        strArr[i] = (char*)malloc(20 * sizeof(char));
    }
    char* source = "hello world !";
    int i = 0, offset = 0;

    while (offset < strlen(source) && sscanf(source + offset, "%s", strArr[i]) == 1) {
        offset += strlen(strArr[i]) + 1;
        i++;
    }
    char s[30];
    sprintf(s, "%s %s %s", strArr[0], strArr[1], strArr[2]);
    printf("%s", s);


    for (int i = 0; i < 3; i++) {
        free(strArr[i]);
    }
    free(strArr);
    return 0;
}




