/**
* 问题：求n!中有多少个质因子p
**/

//时间复杂度为O(nlogn)的算法
int cal(int n, int p) {
    int ans = 0;
    //遍历2-n
    for (int i = 2; i <= n; i++) {
        int temp = i;
        //只要temp还是p的倍数
        while (temp % p == 0) {
            ans++; //p的个数加1
            temp /= p; //temp除以p
        }
    }
    return ans;
}

//时间复杂度为O(logn)的算法
int cal(int n, int p) {
    int ans = 0;
    while (n) {
        ans += n / p; //累加n/p^k
        n /= p; //相当于分母多乘一个p
    }
    return ans;
}

//递归版本
int cal(int n, int p) {
    if (n < p)
        return 0; //n<p时1-n中不可能有质因子p
    return n / p + cal(n / p, p); //返回n/p加上(n/p)!中质因子p的个数
}
