// 顺序栈

#include<iostream>
#include<map>
using namespace std;

const int N = 100;

typedef struct{
    char element[N];
    int top;
}Stack;

void Init_Stack(Stack *S)
{
    S->top = 0;
    cout << "初始化成功" << endl;
}

void Stack_add(Stack* S, char x)
{
    S->element[++ S->top] = x;
    cout << x << "入栈成功" << endl;
}

// 弹出栈顶元素并返回栈顶元素
char Pop_Get(Stack* S)
{
    if (S->top == 0)
    {
        cout << "S.top == 0 Pop_Get函数出错" << endl;
        return '?';
    }
    else
    {
        cout << S->element[S->top] << "Pop_Get弹栈成功" << endl;
        return S->element[S->top --];
    } 
    
}

// 取得栈顶元素(不需要修改，直接传参即可)
char Get_Top(Stack S)
{
    if (S.top == 0)
    {
        cout << "S.top == 0 Get_Top函数出错" << endl;
        return '?';
    }
    else return S.element[S.top];
}

int Get_TopNumber(Stack S)
{
    return S.top;
}

// 弹出栈顶元素不返回该元素
void Pop(Stack *S)
{
    if (S->top == 0) cout << "栈空，无法进行弹栈操作，请确保传入的栈的合法性" << endl;
    else
    {
        S->top --;
        cout << "Pop弹栈成功" << endl;
    }
}
int main()
{
    // 设计运算符的优先级
    // 代数越高，优先级越高(基于中缀转后缀时符号入栈的逻辑来设定的优先级代数)
    map<char, int> priority;
    priority['+'] = 1, priority['-'] = 1, priority['*'] = 2, priority['/'] = 2;

    // 只要遇到右括号栈顶符号就依次出栈  右括号不会入栈 
    // 解决了括号入栈的问题，还需要解决出现右括号的时候何时停止弹栈的问题
    priority['('] = 3, priority[')'] = 0;

    Stack suffixSymbol;
    Init_Stack(&suffixSymbol);
    
    string infix, suffix;
    cin >> infix;

    // i是infix的下标，k是suffix的下标，infix和suffix的长度不一样，所以用两个变量来标记状态
    for (int i = 0, k = 0; i < infix.length(); i ++)
    {
        char x = infix[i];
        // 从左向右遍历中缀表达式是，只要遇到数字就输出到后缀表达式
        // 遇到数字直接输出到后缀表达式，无需进行其它操作
        if (x >= '0' && x <= '9') suffix[k ++] = x, cout << x << "成功输出到后缀表达式中" << endl;
        // 否则如果遇到了运算符
        else
        {
            // 当前符号优先级高于栈顶元素的情况
            if (suffixSymbol.top == 0 || priority[x] > priority[Get_Top(suffixSymbol)])
            {
                // 如果符号栈为空，或者当前符号的优先级高于栈顶符号
                // 符号入栈
                Stack_add(&suffixSymbol, x);
            }
            // 当前符号优先级不高于栈顶元素的情况 || 需要弹栈的情况
            else
            {
                // 不满足入栈的条件就出栈
                // 出栈之后是否需要输出到后缀表达式：只有括号出栈之后不输出，其它的都要输出
                // 对括号的情况要进行特判，何时停止弹栈？

                // 第一个if是对括号的特判
                char tmpSymbol; // 定义一个中间变量，存储要弹出的栈顶符号
                if (x == ')')
                {
                    while (Get_Top(suffixSymbol) != '(' && Get_TopNumber(suffixSymbol) != 0)
                    {
                        tmpSymbol = Pop_Get(&suffixSymbol); // 弹栈并取得栈顶元素
                        suffix[k ++] = tmpSymbol, cout << tmpSymbol << "成功输出到后缀表达式中" << endl;
                    }

                    // 将左括号弹出，但不需要输出到后缀表达式中
                    Pop(&suffixSymbol);
                }
                // 接着就是普通情况
                else
                {
                    while (priority[x] <= priority[Get_Top(suffixSymbol)] && Get_TopNumber(suffixSymbol))
                    {
                        tmpSymbol = Pop_Get(&suffixSymbol);
                        suffix[k ++] = tmpSymbol, cout << tmpSymbol << "成功输出到后缀表达式中" << endl; 
                    }
                }
            }
        }
    }

    for (int i = 0; i < suffix.length(); i ++ ) cout << suffix[i];
    // 处理栈中剩余的符号，出栈并输出
    char xx;
    while (Get_TopNumber(suffixSymbol))
    {
        xx = Pop_Get(&suffixSymbol);
        suffix += xx, cout << xx << "成功输出到后缀表达式中" << endl;
    }

    for (int i = 0; i < suffix.length(); i ++ ) cout << suffix[i];
    return 0; 
}