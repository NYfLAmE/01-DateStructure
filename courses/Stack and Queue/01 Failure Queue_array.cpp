// 有几个问题
// 这是代码是依照图灵机的思路来写的
// 巧妙之处在于让数组下标循环那块
// 第一种思路就是将数组留一个空位
// rear指针指向的是尾部元素的下一个元素，当front==rear的时候，说明队空
// 当（rear+1）%队列长度==front的时候，队满

// 第二种思路就是图灵机的思路
// 如果遇到边界，就重新归位
// 也就是if (下标==数组长度-1) 就回归到0
// 但是这种思路有一个问题
// 就是：队空的时候front和rear指针是相等的，队满的时候两个指针也是相等的
// 所以说，图灵机讲的代码是有漏洞的，虽然能够满足队列的先进先出，栈的后进后出，但是输出有问题
// 无法判断此时是队满还是队空，虽然有一个size变量记录结构的大小，但是治标不治本
// 若一个一个输出结构中的元素，当结构满了的时候，队尾指针和队头指针重合
// 所以，还是要像上面的方法一样，留出一个空位来判断是队空还是队满
// md真的浪费我的时间，以后写代码，图灵机的代码仅仅供参考
// 他的代码成立的前提条件是什么？适用于什么环境，完整性如何？
// 都是自己要去思考的一点，不管谁的代码，首先要有自己的一个思路，带着批判性去看代码
// 不能只是一味的模仿，更重要的是思想，实现的思路是什么
// tmd写一个下午的代码白写了

#include<iostream>
const int MAX = 10;
using namespace std;

typedef struct Queue_array{
    int* element;
    int front;
    int rear;
    int size;
}Qa;

// 初始化数组形式的双端队列
void Init_Dequeue_Array(Qa* dequeue)
{
    dequeue->element = (int*)malloc(sizeof(int) * MAX);
    dequeue->size = 0;

    // 这里的front指向的就是真正的front元素，rear指向的也是真正的rear元素，没有指向下一个元素的意思
    dequeue->front = 0;
    dequeue->rear = 0;
    cout << "Dequeue初始化成功" << endl;
}

void Push_left(Qa* dequeue, int key)
{
    if (dequeue->size == MAX)
    {
        cout << "队满，无法完成Push操作，请确保队列有空闲空间" << endl;
    }
    else
    {
       // push
       if (dequeue->front == 0)
       {
            // 如果front == 0，说明队列需要进行循环了
            dequeue->front = MAX - 1;
            dequeue->element[dequeue->front] = key;
            dequeue->size ++;
            cout << "循环且" << key << "push成功" << endl;
       }
       else
       {
            // 不需要循环，直接push操作即可
            dequeue->element[-- dequeue->front] = key;
            dequeue->size ++;
            cout << key << "push成功" << endl; 
       }

    }
}

void Push_right(Qa* dequeue, int key)
{
    if (dequeue->size == MAX)
    {
        cout << "队满，无法完成Push操作，请确保队列有空闲空间" << endl;
    }
    else
    {
        // 若需要进行循环
        if (dequeue->rear == MAX - 1)
        {
            dequeue->rear = 0;
            dequeue->element[dequeue->rear] = key;
            dequeue->size ++;
            cout << "循环且" << key << "push成功" << endl;
        }
        else
        {
            // 若不需要循环，直接push即可
            dequeue->element[++ dequeue->rear] = key;
            dequeue->size ++;
            cout << key << "push成功" << endl; 
        }
    }
}

void Pop_left(Qa* dequeue, int key)
{
    // 判断栈是否为空
    if (dequeue->size == 0)
    {
        cout << "队空，无法进行Pop_left操作，请确保双端队列非空" << endl;
    }
    else
    {
        if (key != dequeue->element[dequeue->front])
        {
            cout << "key: " << key << " 与当前队头元素不一致，Pop_left失败" << endl;
            return ;
        }
        // 需要循环的情况
        if (dequeue->front == MAX - 1)
        {
            cout << dequeue->element[dequeue->front] << "Pop_left成功" << endl;
            dequeue->front = 0;
            dequeue->size --;
        }
        else
        {
            // 不需要循环，直接进行pop
            cout << dequeue->element[dequeue->front] << "Pop_left成功" << endl;
            dequeue->front ++;
            dequeue->size --;
        }
    }
}

void Pop_right(Qa* dequeue, int key)
{
    // 判断队空
    if (dequeue->size == 0)
    {
        cout << "队空，无法进行Pop_right操作，请确保双端队列非空" << endl;
    }
    else
    {
        // 如果当前key与队头元素不一致，pop失败
        if (key != dequeue->element[dequeue->rear])
        {
            cout << "key: " << key << " 与当前队头元素不一致，Pop_right失败" << endl;
            return ;
        }
        // 需要循环的情况
        if (dequeue->rear == 0)
        {
            cout << dequeue->element[dequeue->front] << "Pop_right成功" << endl;
            dequeue->rear = MAX - 1;
            dequeue->size --;
        }
        else
        {
            // 不需要循环，直接进行pop
            cout << dequeue->element[dequeue->rear] << "Pop_right成功" << endl;
            dequeue->rear --;
            dequeue->size --;
        }
    }
}

void OutputStack(Qa dequeue)
{
    int size = dequeue.size;
    for (int i = 0; i < size; i ++)
    {
        if (dequeue.rear == 0)
        {
            cout << dequeue.element[dequeue.rear] << ' ';
            dequeue.rear = MAX - 1;
        }
        else
        {
            cout << dequeue.element[dequeue.rear - i] << ' ';
        }
    }
    cout << "栈输出完毕" << endl;
}

void OutputQueue(Qa dequeue)
{
    int size = dequeue.size;
    for (int i = 0; i < size; i ++)
    {
        if (dequeue.front == MAX - 1)
        {
            cout << dequeue.element[dequeue.front] << ' ';
            dequeue.front = 0;
        }
        else
        {
            cout << dequeue.element[dequeue.front + i] << ' ';
        }
    }
    
    cout << "队列输出成功" << endl;
}
int main()
{
    Qa dequeue;
    Init_Dequeue_Array(&dequeue);

    cout << "请选择要使用的数据结构\n1: 栈  2: 队列" << endl;
    int stackORqueue;
    cin >> stackORqueue;
    if (stackORqueue == 1)
    {
        cout << "是否需要向栈中添加元素？\n1: YES  2: NO" << endl;
        int needpush;
        cin >> needpush;
        if (needpush == 1)
        {
            cout << "请输入需要添加的元素的个数" << endl;
            int n;
            cin >> n;

            cout << "请输入要添加的元素的具体值" << endl;
            int x;
            for (int i = 0; i < n; i ++)
            {
                cin >> x;
                Push_right(&dequeue, x);
            }
        } 

        cout << "是否需要删除栈中的元素？\n1: YES  2:NO" << endl;
        int needpop;
        cin >> needpop;
        if (needpop == 1)
        {
            cout << "请输入需要删除的元素的个数" << endl;
            int n;
            cin >> n;

            cout << "请输入要删除的元素的具体值" << endl;
            int x;
            for (int i = 0; i < n; i ++)
            {
                cin >> x;
                Pop_right(&dequeue, x);
            }
        }

        OutputStack(dequeue); 
    }
    // 选择使用队列
    else
    {
        cout << "是否需要向队列中添加元素？\n1: YES  2: NO" << endl;
        int needpush;
        cin >> needpush;
        if (needpush == 1)
        {
            cout << "请输入需要添加的元素的个数" << endl;
            int n;
            cin >> n;

            cout << "请输入要添加的元素的具体值" << endl;
            int x;
            for (int i = 0; i < n; i ++)
            {
                cin >> x;
                Push_right(&dequeue, x);
            }
        } 

        cout << "是否需要删除队列元素？\n1: YES  2:NO" << endl;
        int needpop;
        cin >> needpop;
        if (needpop == 1)
        {
            cout << "请输入需要删除的元素的个数" << endl;
            int n;
            cin >> n;

            cout << "请输入要删除的元素的具体值" << endl;
            int x;
            for (int i = 0; i < n; i ++)
            {
                cin >> x;
                Pop_left(&dequeue, x);
            }
        }

        OutputQueue(dequeue); 
    }
}