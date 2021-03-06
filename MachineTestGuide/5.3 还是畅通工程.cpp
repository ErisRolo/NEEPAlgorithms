#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 101

int Tree[N];

//查找代表集合的树的根结点
int findRoot(int x) {
    if (Tree[x] == -1) {
        return x;
    } else {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

//边结构体
struct Edge {
    int a, b; //边两个顶点的编号
    int cost; //该边的权值
    //重载小于号使其可以按照边权从小到大排列
    bool operator < (const Edge &A) const {
        return cost < A.cost;
    }
} edge[6000];

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n != 0) {
        for (int i = 1; i <= n * (n - 1) / 2; i++)
            scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].cost);
        sort(edge + 1, edge + 1 + n * (n - 1) / 2); //按照边权值递增排列所有的边
        for (int i = 1; i <= n; i++)
            Tree[i] = -1; //初始时所有的结点都属于孤立的集合
        int ans = 0; //最小生成树上边权的和初始为0
        //按照边权值递增顺序遍历所有的边
        for (int i = 1; i <= n * (n - 1) / 2; i++) {
            //查找该边两个顶点的集合信息
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b);
            //若它们属于不同集合，则选用该边
            if (a != b) {
                Tree[a] = b; //合并两个集合
                ans += edge[i].cost; //累加该边权值
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
