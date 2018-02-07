#include <stdio.h>

//定义宏判断是否是闰年，方便计算每月天数
#define ISYEAP(x) x%100!=0 && x%4==0 || x%400==0? 1:0

//预存每月的天数，注意二月配合宏定义作特殊处理
int dayOfMonth[13][2] = {
    0, 0,
    31, 31,
    28, 29,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31,
    31, 31,
    30, 30,
    31, 31,
    30, 30,
    31, 31
};

//日期类，方便日期的推移
struct Date {
    int Day;
    int Month;
    int Year;
    //计算下一天的日期
    void nextDay() {
        Day++;
        //若日数超过了当月最大日数
        if (Day > dayOfMonth[Month][ISYEAP(Year)]) {
            Day = 1;
            Month++; //进入下一月
            //月数超过12
            if (Month > 12) {
                Month = 1;
                Year++; //进入下一年
            }
        }
    }
};

int buf[5001][13][32]; //保存预处理的天数
//求绝对值
int Abs(int x) {
    return x < 0 ? -x : x;
}

int main() {
    Date tmp;
    int cnt = 0; //天数计数
    //初始化日期类对象为0年1月1日
    tmp.Day = 1;
    tmp.Month = 1;
    tmp.Year = 0;
    //日期不超过5000年
    while (tmp.Year != 5001) {
        buf[tmp.Year][tmp.Month][tmp.Day] = cnt; //将该日与0年1月1日的天数差保存起来
        tmp.nextDay(); //计算下一天日期
        cnt++; //计数器累加，每经过一天计数器即+1，代表与原点日期的间隔又增加一天
    }
    int d1, m1, y1;
    int d2, m2, y2;
    //读入要计算的两个日期
    while (scanf("%4d%2d%2d", &y1, &m1, &d1) != EOF) {
        scanf("%4d%2d%2d", &y2, &m2, &d2);
        printf("%d\n", Abs(buf[y2][m2][d2] - buf[y1][m1][d1]) + 1); //用预处理的数据计算两日期差值，注意需对其求绝对值
    }
}
