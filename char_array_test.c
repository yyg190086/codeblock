#include <stdio.h>
#include <stdlib.h>



int main() {

    char** strArr = (char**)malloc(3 * sizeof(char*));  // 动态创建指针数组
    strArr[0] = "hello";
    strArr[1] = "world";
    strArr[2] = "!";
    char s[30];
    sprintf(s, "%s %s %s", strArr[0], strArr[1], strArr[2]);
    printf("%s", s);
    free (strArr);

    return 0;


}




