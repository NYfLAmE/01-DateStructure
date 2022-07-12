#include<iostream>

#define Error -1
#define OK 1
#define True 1
#define False -1
const int MAX = 10;
using namespace std;

// 描述线性表的顺序存储结构（顺序表）需要三个属性：
// 存储空间的起始位置，也就是数组的存储位置 ——起始位置*begin
// 存储空间的最大容量，也就是数组的长度 ——最大容量MAX
// 顺序结构的线性表（顺序表）的当前长度 ——当前长度present Length

// 定义一个顺序表
// 用数组来存储线性表
typedef struct{
    int element[MAX];
    int presnLength;
}SqList;

// 初始化顺序表，不是真正意义的初始化，真正的初始化已经在定义结构体变量的时候已经进行了初始化
// 这里的初始化时对顺序表的length进行初始化
void Init_SqList(SqList *L)  // ———————————Get it right;
{
    L->presnLength = 0;
    cout << "顺序表初始化成功" << endl;
}

void SqList_Empty(SqList L) // ———————————Get it right;
{
    if (L.presnLength == 0) cout << "顺序表为空" << endl;
    else cout << "顺序表非空" << endl;
}

void clear_SqList(SqList *L) // ———————————Get it right;
{
    L->presnLength = 0;
    cout << "顺序表重置成功" << endl;
}

void list_length(SqList L) // ———————————Get it right;
{
    cout << "当前顺序表的长度length：" << L.presnLength << endl;
}

// 获取元素
// 不需要改变结构体内部的数据，直接传入结构体本身即可，不需要传入指针
int GetElem(SqList L, int i)
{
    // 如果i不合法或者传入了一个空的顺序表，返回Error
    if (i < 1 || i > L.presnLength || L.presnLength == 0)
    {
        cout << "传入的数据非法，无法GetElem，请确保数据的合法性" << endl;
        return Error;
    }
    
    // 传入参数正常，直接返回该位置的元素
    return L.element[i - 1];
}

int LocateElem(SqList L, int key)
{
    if (L.presnLength == 0)
    {
        cout << "顺序表为空，无法Locate" << endl;
        return 0;
    }
    for (int i = 0; i < L.presnLength; i ++ ) 
    {
        if (L.element[i] == key) return i + 1;
    }
    return 0;
}
// 插入元素
// 需要改变结构体内部的数据，传入指针
// 首先判断要插入的位置是否合理
// 然后判断当前线性表的容量是否满足插入
// 后面的元素后移
// 插入该元素
// 顺序表长度+1
int ListInsert(SqList *L, int i, int insrt) // ———————————Get it right;
{
    // 插入的位置不合法
    if (i < 1 || i > L->presnLength + 1) return Error;

    // 顺序表的最大容量不允许
    if (L->presnLength == MAX) return Error;

    // 什么情况下，添加元素需要将后面的元素后移？
    // 当插入的位置不在表尾的时候
    if (i < L->presnLength - 1)
    {
        // 后移操作
        for (int k = L->presnLength; k > i - 1; k --)
        {
            L->element[k] = L->element[k - 1];
        }
    }

    // 赋值，顺序表长度更新，返回OK
    L->element[i - 1] = insrt;
    L->presnLength ++;
    cout << "成功插入元素" << endl;
    return OK;
}

// 删除元素
// 首先是判断参数
// 如果传入的是一个空顺序表，返回error 
// 如果要删除的元素的下标不合法，返回error
int ListDelete(SqList *L, int i) // ———————————Get it right;
{
    if (L->presnLength == 0)
    {
        printf("传入空顺序表，无法删除元素，请先创建一个顺序表\n");
        return Error;
    }
    if (i < 1 || i > L->presnLength)
    {
        printf("传入的i不合法，请确保传入的参数的正确性\n");
        return Error;
    }
    
    // 删除元素
    // 什么情况下需要将后面的元素前移？
    // 当删除的元素不在表尾的时候，需要将后面的元素前移
    if (i < L->presnLength - 1)
    {
        // 因为是用后面的元素覆盖前面元素的值，所以升序遍历
        for (int k = i - 1; k < L->presnLength - 1; k ++)
        {
            L->element[k] = L->element[k + 1];
        }
    }

    // 这里的删除不是真正的删除并释放该处的内存
    L->presnLength --;
    cout << "成功删除元素" << endl;
}

// 顺序输出顺序表元素
void ListTraverse(SqList L) // ———————————Get it right;
{
    cout << "调用ListTraverse函数，输出顺序表中的数据：" << endl;
    for (int i = 0; i < L.presnLength; i ++ ) cout << L.element[i] << ' ';
    cout << endl << "数据输出完毕" << endl;
}


// 将所有在b表中，不在a表中的元素，合并到a表中

void Union_List(SqList *La, SqList Lb)
{
    int lengtha = La->presnLength, lengthb = Lb.presnLength;
    for (int i = 0; i < lengthb; i ++ )
    {
        int x = GetElem(Lb, i + 1);
        if (!LocateElem(*La, x))
        {
            ListInsert(La, ++ lengtha, x);
            cout << "merge成功" << endl;
        }
        else
        {
            cout << "该元素在La顺序表中存在，不需要merge" << endl;
        }
    }
}

int main()
{
    printf("是否需要初始化一个顺序表？\n1：初始化  2：退出程序\n");
    int x;
    cin >> x;
    if (x == 2) return 0;
    else
    {
        SqList L;
        Init_SqList(&L);

        cout << "请输入要插入的元素个数：" << endl;
        int n;
        cin >> n;
        cout << "请输入所有要插入的元素的值：" << endl;
        for (int i = 0; i < n; i ++)
        {
            int num;
            cin >> num;
            ListInsert(&L, i + 1, num); 
        }

        cout << "是否需要查询顺序表的数据？" << endl;
        cout << "1：是  2：不需要" << endl;
        int Qop;
        cin >> Qop;
        if (Qop == 2) ;
        else 
        {
            cout << "请输入要查询的元素的个数：" << endl;
            int Qs;
            cin >> Qs;
            cout << "请输入要查询的元素的下标" << endl;
            while (Qs --)
            {
                int Qi;
                cin >> Qi;
                cout << GetElem(L, Qi) << endl;
            }
        }

        cout << "是否需要调用Locate函数定位元素在顺序表中的位置？" << endl;
        cout << "1：是  2：不需要" << endl;
        int Loc;
        cin >> Loc;
        if (Loc == 2) ;
        else
        {
            cout << "请输入要定位的元素的个数：" << endl;
            int Locs;
            cin >> Locs;

            cout << "请输入需要Locate的元素：" << endl;
            while (Locs --)
            {
                int LocsInt;
                cin >> LocsInt;
                cout << LocsInt << "在顺序表中的下标为：" << LocateElem(L, LocsInt) << endl;
            }
        }

        cout << "现在进行Union函数的测试——————————————————————" << endl;
        cout << "正在初始化一个顺序表" << endl;
        SqList Lb;
        Init_SqList(&Lb);

        cout << "请输入要在顺序表Lb中插入的元素的个数：" << endl;
        int Lbn;
        cin >> Lbn;

        cout << "请输入具体元素的值：" << endl;
        for (int i = 0; i < Lbn; i ++)
        {
            int LbInt;
            cin >> LbInt;
            ListInsert(&Lb, i + 1, LbInt);
        }

        cout << "调用Union函数之前La的数据：" << endl;
        ListTraverse(L);
        cout << "正在调用Union函数，将Lb merge到 La" << endl;
        Union_List(&L, Lb);
        cout << "调用完Union函数之后La的数据：" << endl;
        ListTraverse(L);

        // ListTraverse(L); // 为什么放在else作用域里，函数就能访问到L
    }

    // ListTraverse(L); // 放到else域外面为什么就不能访问？
    return 0;
}






