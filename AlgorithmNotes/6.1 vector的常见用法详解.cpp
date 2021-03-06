/**
*  vector：翻译为向量，理解为“变长数组”
**/
#include <cstdio>
#include <vector>
using namespace std;


//vector的定义
vector<int> name;
vector<double> name;
vector<char> name;
vector<node> name; //node是结构体的类型
vector<vector<int> > name; //如果typename是vetor，>>之间要加空格
vector<typename> ArrayName[arraySize]; //定义vector数组


//vector容器内元素的访问：(1)通过下标访问 (2)通过迭代器访问
//写法一
{
    vector<int> vi;
    //循环完毕后vi中元素为1 2 3 4 5
    for (int i = 1; i <= 5; i++)
        vi.push_back(i); //push_back(i)在vi的末尾添加元素i，即依次添加1 2 3 4 5
    vector<int>::iterator it = vi.begin(); //vi.begin()为取vi的首元素地址，而it指向这个地址
    for (int i = 0; i < 5; i++)
        printf("%d ", *(it + i)); //输出vi[i]
    return 0;
}
//写法二
{
    vector<int> vi;
    for (int i = 1; i <= 5; i++)
        vi.push_back(i);
    //vector的迭代器不支持it < vi.end()写法，因此循环条件只能用it != vi.end()
    for (vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
        printf("%d ", *it);
    return 0;
}


//vector常用函数实例解析
//push_back()
{
    vector<int> vi;
    for (int i = 1; i <= 3; i++)
        vi.push_back(i); //将1、2、3依次插入vi末尾
    //size()函数会给出vi中元素的个数
    for (int i = 0; i < vi.size(); i++)
        printf("%d ", vi[i]);
    return 0;
}
//pop_back()
{
    vector<int> vi;
    for (int i = 1; i <= 3; i++)
        vi.push_back(i); //将1、2、3依次插入vi末尾
    vi.pop_back(); //删除vi的尾元素3
    for (int i = 0; i < vi.size(); i++)
        printf("%d ", vi[i]);
    return 0;
}
//size()
{
    vector<int> vi;
    for (int i = 1; i <= 3; i++)
        vi.push_back(i); //将1、2、3依次插入vi末尾
    printf("%d\n", vi.size());
    return 0;
}
//clear()
{
    vector<int> vi;
    for (int i = 1; i <= 3; i++)
        vi.push_back(i); //将1、2、3依次插入vi末尾
    vi.clear();
    printf("%d\n", vi.size());
    return 0;
}
//insert()
{
    vector<int> vi;
    for (int i = 1; i <= 5; i++)
        vi.push_back(i); //此时为1、2、3、4、5
    vi.insert(vi.begin() + 2, -1); //将-1插入vi[2]的位置
    for (int i = 0; i < vi.size(); i++)
        printf("%d ", vi[i]); //1 2 -1 3 4 5
    return 0;
}
//erase()
//删除单个元素
{
    vector<int> vi;
    for (int i = 5; i <= 9; i++)
        vi.push_back(i); //插入5 6 7 8 9
    vi.erase(vi.begin() + 3); //删除8（因为vi.begin()对应的是vi[0]，所以8不是对应vi.begin()+4）
    for (int i = 0; i < vi.size(); i++)
        printf("%d ", vi[i]); //输出5 6 7 9
    return 0;
}
//删除一个区间内的所有元素
{
    vector<int> vi;
    for (int i = 5; i <= 9; i++)
        vi.push_back(i); //插入5 6 7 8 9
    vi.erase(vi.begin() + 1, bi.begin() + 4); //删除vi[1]、vi[2]、vi[3]
    for (int i = 0; i < vi.size(); i++)
        printf("%d ", vi[i]); //输出5 9
    return 0;
}


//vector的常见用途
// (1) 储存数据
// (2) 用邻接表存储图
