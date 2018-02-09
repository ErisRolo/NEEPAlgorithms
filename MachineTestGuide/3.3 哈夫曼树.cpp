#include <queue>
#include <stdio.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > Q;  //建立一个小顶堆

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        while (Q.empty() == false)
            Q.pop(); //清空堆中元素
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            Q.push(x); //将权值放入堆中
        }
        int ans = 0;
        while (Q.size() > 1) {
            //取出堆中两个最小元素，它们为同一个结点的左右儿子，且该双亲结点的权值为它们的和
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();
            ans += a + b; //该父亲结点必为非叶子结点，固累加其权值
            Q.push(a + b); //将该双亲结点的权值放回堆中
        }
        printf("%d\n", ans); //输出答案
    }
    return 0;
}
