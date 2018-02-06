#include<stdio.h>

int main() {
    int a, b;
    //注意scanf函数有返回值，成功完成输入并赋值则返回1
    //题目明确要求输入数据会有多组，则使用该循环测试条件来完成对输入是否结束的判断
    while(scanf("%d %d", &a, &b) != EOF) {
        printf("%d\n", a + b);
    }
    return 0;
}
