#include <stdio.h>
#include <algorithm>
using namespace std;

//定义排序规则
bool cmp(int x, int y) {
    return x > y;
}

int main() {
    int n;
    int buf[100];
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &buf[i]);
        }
        sort(buf, buf + n, cmp); //使用快排库函数的该重载形式，表明将要使用自己定义的排列规则
        for(int i = 0; i < n; i++) {
            printf("%d ", buf[i]);
        }
        printf("\n");
    }
    return 0;
}
