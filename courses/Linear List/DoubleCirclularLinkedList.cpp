#include<iostream>
using namespace std;

typedef struct doubleCircular_linkedlist{
    int element;
    doubleCircular_linkedlist* front;
    doubleCircular_linkedlist* next;
    int size;

    // 头结点 尾结点
    doubleCircular_linkedlist* head;
    doubleCircular_linkedlist* tail;
}dbcll;

// 带有头结点和尾结点的双向循环链表的初始化
void Init_dbcll(dbcll* list)
{
    list->front = list;
    list->next = list;
    list->size = 0;

    list->head = (dbcll*)malloc(sizeof(dbcll));
    list->tail = (dbcll*)malloc(sizeof(dbcll));

    list->head->next = list->tail;
    list->head->front = list->tail;
    list->tail->front = list->head;
    list->tail->next = list->head;
    cout << "list初始化成功" << endl;
}

// 添加元素(头插)
// 这里写的是有头结点且有尾结点的双向循环链表
void Insert(dbcll* list, int key)
{
    // 申请一个新结点
    dbcll* tmp = (dbcll*)malloc(sizeof(dbcll));

    // 如果申请成功
    if (tmp != NULL)
    {
        // 如果是第一次向头结点后面插入元素
        if (list->size == 0)
        {
            tmp->element = key;
            tmp->next = list->head->next;
            tmp->front = list->head;
            list->head->next = tmp;
            list->tail->front = tmp;

            list->size ++;
            cout << "首次头插添加结点成功";
        }
        else
        {
            tmp->element = key;
            tmp->next = list->head->next;
            tmp->front = list->head;

            list->head->next = tmp;

            list->size ++;
            cout << "Normal添加结点成功" << endl;
        }
        
    }
}

void OutputLL(dbcll* list)
{
    if (list->size == 0)
    {
        cout << "链表为空，无需Output" << endl;
    }
    else
    {
        dbcll* tmp = list->head->next;
        while (tmp != list->tail)
        {
            cout << tmp->element << ' ';
            tmp = tmp->next;
        }
        cout << "链表输出完毕" << endl;
    }
    
}


int main()
{
    // 上面已经实现了双向循环链表的一个框架
    // 完成了双向循环链表的初始化
    // 完成了双向循环链表从head开始输出，直到tail结束
    // 完成了双向循环链表的头插
    // 未完成双向循环链表的尾插
    // 未完成双向循环链表的任意位置插入
    // 未完成双向循环链表的删除
}