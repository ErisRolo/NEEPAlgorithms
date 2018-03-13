#include <stdio.h>

int main() {
    int n;
    int buf[100]; //定义我们将要使用的变量n，并用buf[100]来保存将要排序的数字
    while(scanf("%d", &n) != EOF) { //输入n，并实现多组数据的输入
        for(int i = 0; i < n; i++) {
            scanf("%d", &buf[i]); //输入待排序数字
        }
        //冒泡排序主体
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n - 1 - i; j++) {
                if(buf[j] > buf[j + 1]) {
                    int tmp = buf[j];
                    buf[j] = buf[j + 1];
                    buf[j + 1] = tmp;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            printf("%d ", buf[i]); //输出完成排序后的数字，注意题目输出要求在每个数字后都添加一个空格
        }
        printf("\n");
    }
    return 0;
}
