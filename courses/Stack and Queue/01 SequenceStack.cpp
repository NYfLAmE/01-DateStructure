// Get It Done on 7.18.2022
// 用顺序表实现栈：数组实现栈

#include<iostream>
#define MAX 10
using namespace std;


// 顺序栈

// 数据结构 = 数据集合 + 操作集合
// 栈的数据结合
// 栈底在哪，栈顶在哪
typedef struct SequenceStack{
    int element[MAX];
    int top;
    int flag; // 标记栈是否已经初始化
}SqStack;

// 栈的初始化
void Init_SqStack(SqStack* stack)
{
    stack->top = -1;
    stack->flag = 1;
    cout << "顺序栈初始化成功" << endl;
}

// 入栈操作
void Stack_Push(SqStack* stack, int key)
{
    if (stack->top + 1 != MAX)
    {
        stack->element[++ stack->top] = key;
        cout << key << "入栈成功" << endl;
    }
    else 
    {
        cout << "栈满，Push失败" << endl;
    }
}

// 弹栈操作
// 顺序栈里的弹栈不是真正的弹栈，只是栈顶下标的“弹栈”
void  Stack_Pop(SqStack* stack, int key)
{
    // 首先判断传过来的参数是否正确
    if (stack->flag != 1)
    {
        cout << "栈未进行初始化，无法进行Pop Up操作，请先对栈进行初始化" << endl;
        return ;
    }
    if (stack->top == -1)
    {
        cout << "栈空，无法进行Pop Up操作，请先构造一个非空栈" << endl;
    }
    else
    {
        if (stack->element[stack->top] == key)
        {
            stack->top --;
            cout << key << "弹栈成功" << endl;
        }
        else
        {
            cout << "传入的栈顶元素与当前栈顶元素不一致，无法进行Pop Up操作，请确保参数的合法性" << endl;
        }
    }
}

// 将栈输出
void OutputStack(SqStack stack)
{
    while (stack.top != -1)
    {
        cout << stack.element[stack.top --] << ' ';
    }
    
    cout << "栈输出成功" << endl;
}

int main()
{
    SqStack stack;

    Stack_Pop(&stack, 1);
    Init_SqStack(&stack);
    Stack_Pop(&stack, 1);

    cout << "输入要入栈的元素个数" << endl;
    int n;
    cin >> n;

    cout << "输入入栈的元素的具体值" << endl;
    int x;
    for (int i = 0; i < n; i ++) 
    {
        cin >> x;
        Stack_Push(&stack, x);
    }

    OutputStack(stack);
    return 0;
}