// Get It Done on 10.57am.7.19.2022

// 单向队列
// 普通的单向队列局限性太强，干脆写个单向循环队列
// 单向循环队列，重难点是如何判断队空和队满
// 栈和队列只是操作数据的一种方式，本质上是一个特殊的线性表

// 栈：FILO先进后出，后进先出，限制在栈顶进行元素操作
// 队列：FIFO先进先出后进后出 队尾进，队头出
#include<iostream>
using namespace std;

const int MAX = 10 + 1; // +1就是为了给队列流出一个空位来区分队空队满的情况

// 队列只能从队尾加入元素，队头删除元素
// rear尾指针指向队尾元素的下一个位置，front队头指针指向队头元素的位置

// 7.18晚上打算写循环队列，未遂，7.19早上接着写
// 同用数组实现的栈类似，数组实现的队列不需要构造两个结构体

typedef struct OneWay_Circular_Queue{
    int element[MAX];
    int front;
    int rear; 
}OWCQ;

// 初始化循环队列
void Init_Queue(OWCQ* queue)
{
    queue->front = 0;
    queue->rear = 0;
    cout << "循环队列初始化成功" << endl;
}

// 队尾入队
// 这里的rear不是指向队尾元素的指针，而是指向队尾元素的下一个元素的指针
void Queue_Push(OWCQ* queue, int key)
{
    // 队满
    if ((queue->rear + 1) % MAX == queue->front)
    {
        cout << "队满，无法Push元素，请确保队列空间有空余" << endl;
    }
    else
    {
        // 入队
        // 队尾的下一个空位入队
        queue->element[queue->rear] = key;

        // 更新rear指针
        queue->rear = (queue->rear + 1) % MAX;

        cout << key << "入队成功" << endl;
    }
}

void Queue_Pop(OWCQ* queue, int key)
{
    // 判断参数是否合法

    // 怎么判断一个队列是否已经进行了Init初始化操作？
    // if (queue->flag == 0) 
    // {
    //     cout << "队列未初始化，请先初始化队列" << endl;
    //     return ;
    // }

    // 判断是否队空
    if (queue->rear == queue->front)
    {
        cout << "队空，无法在队头进行Pop操作，请确认队列非空" << endl;
    }
    else
    {
        // key是否合法
        if (key != queue->element[queue->front])
        {
            cout << "要删除的队头: " << queue->element[queue->front] << "与key: " << key << "不一致";
            cout << "请确保传入的key与队头一致" << endl;
        }
        else
        {
            // 出队
            queue->front = (queue->front + 1) % MAX;
            cout << key << "Pop成功" << endl;
        }
    }
}

void OutputQueue(OWCQ queue)
{
    if (queue.front == queue.rear)
    {
        cout << "队空，无元素输出" << endl;
        return ;
    }
    else
    {
        while (queue.front != queue.rear)
        {
            cout << queue.element[queue.front] << ' ';
            queue.front = (queue.front + 1) % MAX;
        }
        cout << "队列元素输出完毕" << endl;
    }
}
int main()
{
    OWCQ queue;

    Init_Queue(&queue);
    Queue_Pop(&queue, 1);

    cout << "是否需要向队列中添加元素?\n1: YES  2: NO" << endl;

    int npush;
    cin >> npush;
    if (npush == 1)
    {
        cout << "请输入要入队的元素个数" << endl;
        int n;
        cin >> n;

        cout << "请输入要入队的元素的具体值" << endl;
        int x;
        for (int i = 0; i < n; i ++)
        {
            cin >> x;
            Queue_Push(&queue, x);
        }
    }

    cout << "是否需要将队中的元素出队?\n1: YES  2: NO" << endl;

    int npop;
    cin >> npop;
    if (npop == 1)
    {
        cout << "请输入要出队的元素个数" << endl;
        int n;
        cin >> n;

        cout << "请输入要出队的元素的具体值" << endl;
        int x;
        for (int i = 0; i < n; i ++)
        {
            cin >> x;
            Queue_Pop(&queue, x);
        }
    }

    OutputQueue(queue);
    return 0;
}
