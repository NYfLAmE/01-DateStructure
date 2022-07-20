// 2022.7.18下午三点开始写，用时一个小时
// Get It Done on 7.18.2022

#include<iostream>
using namespace std;

// 数据结构：属性集合+操作集合
// 为什么要这么设计两个typedef，这里一定要弄清楚
// 一个栈，栈所带有的属性(栈顶，栈的大小)
// 怎么存储这么一个栈？这里用到的是链表
// 链表结点的next指针指向的是栈顶的下一个元素，也就是进行完弹栈操作之后的栈顶

// 一个栈和栈中的元素所带有的属性是不一样的
// 所以，这里构造两个类型的struct，一个LStkTop存放栈中的元素(包含了栈顶)，一个LStk表示一个栈
// 框架
typedef struct LinkedStackTop{
    // 属性集合：这里设置一个element来存放栈的数据
    int element;

    // 因为是用链表来实现一个栈，所以一个栈里面的元素要有下一个元素的指针
    // 这里的next其实指档期那栈顶元素的next，也就是当前栈顶元素出栈之后的栈顶元素
    LinkedStackTop* next;
}LStkTop;

typedef struct LinkedStack{
    // 栈顶指针
    LStkTop* top;

    // 栈底特有的属性：记录当前栈的大小
    int count;
}LStk;

// 操作集合
// 初始化一个链栈
void Init_LinkedStack(LStk* stack)
{
    // 当前栈大小为0
    stack->count = 0;

    cout << "请选择初始化栈的方式" << endl << "1: 需要虚拟头结点  2: 不需要虚拟头结点";
    cout << "    " << "(当前只支持方式2)" << endl;
    int op;
    cin >> op;
    if (op == 1)
    {
        // 方式一：当栈为空的时候，初始化一个虚拟栈顶元素，这个虚拟栈顶元素不存放数据，只是用来指向首元结点，类似于链表的头结点
        // 给当前栈顶分配内存空间，这里其实用到了链表种的头结点？
        stack->top = (LStkTop*)malloc(sizeof(LStkTop*));
        // 因为栈为空，所以将头结点的next指针指向NULL
        //stack->top->next = NULL;
    }
    else
    {
        // 方法二，不用头结点，直接初始化栈顶为NULL
        // 其实栈为空的时候，也可以将“栈顶元素”指向空
        stack->top = NULL;
    }

}

// 入栈操作
void Stack_Push(LStk* stack, int key)
{  
    // 新建一个结点，即向栈中压入一个元素
    LStkTop* new_LStkTop = (LStkTop*)malloc(sizeof(LStkTop));

    // key值赋予新结点
    new_LStkTop->element = key;
    
    // 新的栈顶的next指针指向原来的栈顶元素
    new_LStkTop->next = stack->top;
    
    // 更新栈的栈顶
    stack->top = new_LStkTop;
    stack->count ++;

    cout << key << "入栈成功" << endl;

}

// 弹栈操作
void Stack_Pop(LStk* stack, int key)
{
    if (stack->top == NULL)
    {
        cout << "栈空，请先将元素压栈再进行Pop Up操作" << endl;
    }
    else
    {
        if (key != stack->top->element)
        {
            cout << "传入的key值不等于当前栈顶元素，无法进行Pop Up操作，请确认传入参数的合法性" << endl;
        }
        else
        {
            // 弹栈
            // 更新栈顶元素
            LStkTop* Otop = stack->top;
            stack->top = stack->top->next;
            stack->count --;

            // 释放空间
            free(Otop);
            Otop = NULL;
            cout << key << "成功从栈顶弹出" << endl;
        }
    }
}

// 依次输出栈顶元素
void OutputStack(LStk stack)
{
    while (stack.top) 
    {
        cout << stack.top->element << ' ';
        stack.top = stack.top->next;
    } 

    cout << "栈输出完毕" << endl;
}


int main()
{
    LStk stack;
    Init_LinkedStack(&stack);

    Stack_Pop(&stack, 1);

    int op;
    cout << "是否需要向栈中压入元素？" << endl;
    cout << "1: YES  2: NO" << endl;
    cin >> op;
    if (op == 1)
    {
        int n;
        cout << "请输入要压入栈的元素个数" << endl;
        cin >> n;

        int value;
        cout << "请输入元素的具体值" << endl;
        for (int i = 0; i < n; i ++) 
        {
            cin >> value;
            Stack_Push(&stack, value);
        }
    }

    OutputStack(stack);

    cout << "是否需要弹栈？" << endl;
    cout << "1: YES  2: NO" << endl;
    cin >> op;
    if (op == 1)
    {
        int n;
        cout << "请输入要弹出的栈顶的个数" << endl;
        cin >> n;

        int value;
        cout << "请输入栈顶的具体值" << endl;
        for (int i = 0; i < n; i ++) 
        {
            cin >> value;
            Stack_Pop(&stack, value);
        }
    }

    OutputStack(stack);
    
    return 0;
}