#include"stdio.h"

int main() {
    
    long f1,f2;
    int i;
    f1 = f2 = 1;
    for (i = 1; i <= 25; i++) {
        printf("%12ld %12ld",f1, f2);
        if(i % 2 == 0) printf("\n");/*控制输出，每行四个*/
        f1 = f1 + f2;/*前两个月加起来赋值给第三个月*/
        f2 = f1 + f2;/*前两个月加起来赋值给第三个月*/
    }
    return 0;
}
