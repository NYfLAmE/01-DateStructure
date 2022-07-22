// 用链表实现一个循环队列？
// 用链表实现的队列不存在循环队列
// 循环队列就是为了解决线性表队列的空间不足或者空间利用不充分的问题
// 链表几乎不存在空间不足的问题

// 截至目前，还差一个用链表实现的队列，一个双向循环链表，一个双端队列
// 其实只需要实现后面两个就行了，用链表实现一个双端队列，实现一个双向循环队列
// 注意，队列和栈本质上还是一个线性表

// 7.22还差链表实现的队列，链表实现的双端队列
// 先用链表实现一个队列

#include<iostream>
using namespace std;

// 队列和栈都是特殊的线性表
// 若用链表实现，那就是特殊的链表
// 为了增删元素方便，习惯上添加头结点或者尾结点

// 链表实现的单向队列就是一端插入，一端输出
// 栈就是同端插入，同端输出
// 所以直接用链表实现一个双端队列即可
// 直接单向链表就行，不需要更复杂的链表

// 若栈和队列的添加元素方法统一(在队尾添加元素)
// 写代码的时候发现尾结点需要一个指向前一个元素的指针
// 所以单向链表行不通，改用双向链表

// 若栈添加元素的位置是队头，队列添加元素的位置是队尾
// 队列的尾结点还是需要一个指向前一个元素的指针
// 所以改用链表
typedef struct Linked_Dequeue{
    // 头结点，尾结点
    // 默认头结点在左，尾结点在右
    Linked_Dequeue* head;
    Linked_Dequeue* tail;

    // 数据集合
    int element;
    int size;

    // 双向链表，两个指针
    Linked_Dequeue* next;
    Linked_Dequeue* front;
}LKD;

// 双端队列初始化
void Init_Dequeue(LKD* dequeue)
{
    dequeue->head = (LKD*)malloc(sizeof(LKD));
    dequeue->tail = (LKD*)malloc(sizeof(LKD));

    dequeue->size = 0;

    // head,tail结点处理
    dequeue->tail->next = NULL;
    dequeue->tail->front = dequeue->head;
    dequeue->head->next = dequeue->tail;
    cout << "双端队列初始化完成" << endl;
}

// 栈添加元素，队列添加元素，方式统一从队尾添加元素
void Insert(LKD* dequeue, int key)
{
    LKD* tmp = (LKD*)malloc(sizeof(LKD));
    tmp->element = key;
    tmp->next = dequeue->tail;
    tmp->front = dequeue->tail->front;

    // 特别注意下面这两行代码，刚开始忽略了这两行代码导致运行结果不符预期
    // 玩的就是指针，最保险的方法就是在纸上画画
    dequeue->tail->front->next = tmp;
    dequeue->tail->front = tmp;
    dequeue->size ++;

    cout << key <<  " insert成功" << endl;
}

// 弹栈
void Stack_Pop(LKD* dequeue)
{
    if (dequeue->size == 0)
    {
        cout << "栈空，弹栈失败" << endl;
        return ;
    }
    else
    {
        int key = dequeue->tail->front->element;
        LKD* tmp = dequeue->tail->front;
        dequeue->tail->front = tmp->front;
        tmp->front->next = dequeue->tail;

        free(tmp);
        tmp = NULL;

        dequeue->size --;
        cout << key << " 弹栈成功" << endl;
    }
}

// 出队
void Queue_Pop(LKD* dequeue)
{
    if (dequeue->size == 0)
    {
        cout << "队满，出队失败" << endl;
        return ;
    }
    else
    {
        int key = dequeue->head->next->element;
        LKD* tmp = dequeue->head->next;

        dequeue->head->next = tmp->next;
        tmp->next->front = dequeue->head;

        free(tmp);
        tmp = NULL;

        dequeue->size --;
        cout << key << "出队成功" << endl;
    }
}

// 输出栈
void Stack_Output(LKD dequeue)
{
    if (dequeue.size == 0)
    {
        cout << "栈空，无需输出" << endl;
        return ;
    }
    else
    {
        LKD* tmp = dequeue.tail->front;
        while (tmp != dequeue.head)
        {
            cout << tmp->element << ' ';
            tmp = tmp->front;
        }

        cout << "栈输出完毕" << endl;
    }
}

// 输出队列
void Queue_Output(LKD dequeue)
{
    if (dequeue.size == 0)
    {
        cout << "队空，无需输出" << endl;
        return ;
    }
    else
    {
        LKD* tmp = dequeue.head->next;
        while (tmp != dequeue.tail)
        {
            cout << tmp->element << ' ';
            tmp = tmp->next;
        }

        cout << "队输出完毕" << endl;
    }
}
int main()
{
    // 7.22下午2两点，完成链表形式的双端队列
    // 完成增删功能
    // 完成输出栈和队列的功能
}
