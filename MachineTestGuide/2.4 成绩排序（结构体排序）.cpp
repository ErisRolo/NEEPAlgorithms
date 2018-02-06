#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct E {
    char name[101];
    int age;
    int score;
} buf[1000];

//实现比较规则
bool cmp(E a, E b) {
    if(a.score != b.score)
        return a.score < b.score; //若分数不相同则分数低者在前
    int tmp = strcmp(a.name, b.name); //strcmp()函数比较两个字符串的大小，s1<s2返回负值，s1=s2返回零，s1>s2返回正值
    if(tmp != 0)
        return tmp < 0; //若分数相同则名字字典序小者在前
    else
        return a.age < b.age; //若名字也相同则年龄小者在前
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%s%d%d", buf[i].name, &buf[i].age, &buf[i].score);
        }
        sort(buf, buf + n, cmp); //利用自己定义的规则对数组进行排序
        for(int i = 0; i < n; i++) {
            printf("%s %d %d\n", buf[i].name, buf[i].age, buf[i].score);
        }
    }
    return 0;
}
