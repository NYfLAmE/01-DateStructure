// 自己先用数组实现一个双端队列
// 截至目前，还差一个用链表实现的队列，一个双向循环链表，一个双端队列

// 7.20.2022晚上九点多开始写数组形式的双端队列，耗时差不多一个小时
// 第二天十点多开始完善代码，十一点代码完善完毕
// 至此，数组形式的双端队列完成
#include<iostream>
using namespace std;

const int SIZE = 10;

typedef struct{
    int element[SIZE];
    int left;
    int right;
    int size;
}SQ_Dequeue;

// 初始化双端队列
// 初始栈
// R表示栈顶到右端
void Init_Stack_R(SQ_Dequeue* dequeue)
{
    // 栈顶指针指向-1表示栈空
    dequeue->right = -1;

    // 栈的大小
    dequeue->size = 0;
}

// L方法初始栈
void Init_Stack_L(SQ_Dequeue* dequeue)
{
    // 栈顶指针指向-1表示栈空
    dequeue->left = SIZE;

    // 栈的大小
    dequeue->size = 0;
}

// R栈添加元素
void Stack_Push_R(SQ_Dequeue* dequeue, int key)
{
    if (dequeue->size == SIZE) 
    {
        cout << "栈满，无法Push_R元素" << endl;
        return ;
    }
    else
    {
        dequeue->element[++ dequeue->right] = key;
        dequeue->size ++;
        cout << key << "Push_R成功" << endl;
    }
}

// L栈添加元素
void Stack_Push_L(SQ_Dequeue* dequeue, int key)
{
    if (dequeue->size == SIZE) 
    {
        cout << "栈满，无法Push_L元素" << endl;
        return ;
    }
    else
    {
        dequeue->element[-- dequeue->left] = key;
        dequeue->size ++;
        cout << key << "Push_L成功" << endl;
    }
}

// R栈弹栈
void Stack_Pop_R(SQ_Dequeue* dequeue)
{
    if (dequeue->size == 0)
    {
        cout << "栈空，无法进行Pop_R操作" << endl;
        return ;
    }
    else
    {
        dequeue->right --;
        dequeue->size --;
        cout << "Pop_R弹栈成功" << endl;
    }
}

// L栈弹栈
void Stack_Pop_L(SQ_Dequeue* dequeue)
{
    if (dequeue->size == 0)
    {
        cout << "栈空，无法进行Pop_L操作" << endl;
        return ;
    }
    else
    {
        dequeue->left ++;
        dequeue->size --;
        cout << "Pop_L弹栈成功" << endl;
    }
}

// 双端队列内部实现一个循环队列
// 为了防止队空队满时都是队头以及队尾指针重合
// rear指针指向的时队尾元素的下一个空位
// 留一个空位来区分队空以及队满
// 这里只进行一种类型的循环队列的实现：默认队尾在右端，右端进，左端队头出，当然如果发生循环了就不一样了
void Init_Queue(SQ_Dequeue* dequeue)
{
    // right指针在除了一开始的时候，其它情况下都是队尾元素的下一个空位的指针
    // 当队空的时候，队头指针left == 队尾指针right
    dequeue->left = 0;
    dequeue->right = 0;
    dequeue->size = 0;
}

void Queue_Push(SQ_Dequeue* dequeue, int key)
{
    // if (dequeue->size == SIZE - 1) 循环队列判断队满不能很单纯的认为用size记录即可。为什么不能？不如敲个代码试试
    // 循环队列有独特的判断队满的方式
    if ((dequeue->right + 1) % SIZE == dequeue->left)
    {
        // 因为要留出一个空位来判断队空队满，所以队列的容量减一
        cout << "队满，无法进行Push操作" << endl;
        return ;
    }
    else
    {
        dequeue->element[dequeue->right] = key;

        // 注意这里的SIZE不需要变为SIZE减一
        // 是在数组里边存数据，所以下标也一定时数组本来的下标，留一个空格，空格的下标也属于数组下标的范围内
        // 所以%数组的大小即可
        dequeue->right = (dequeue->right + 1) % SIZE; 
        dequeue->size ++;
        cout << key << "入队成功" << endl;
        cout << "此时队尾right == " << dequeue->right << endl;;
    }
}

void Queue_Pop(SQ_Dequeue* dequeue)
{
    // 如果队头指针等于队尾指针，那么队空
    if (dequeue->left == dequeue->right)
    {
        cout << "队空，无法进行出队Pop操作" << endl;
        return ;
    }
    else
    {
        dequeue->left = (dequeue->left + 1) % SIZE;
        dequeue->size --;
    }
}

void OutputStack_L(SQ_Dequeue dequeue)
{
    if (dequeue.size == 0)
    {
        cout << "栈空，无需输出栈元素" << endl;
        return ;
    }
    else
    {
        while (dequeue.left != SIZE)
        {
            cout << dequeue.element[dequeue.left ++] << ' ';
            dequeue.size --;
        }
        cout << "OutputStack_L栈输出完毕" << endl;
    }
}


// R方式输出栈元素
void OutputStack_R(SQ_Dequeue dequeue)
{
    if (dequeue.size == 0)
    {
        cout << "栈空，无需进行R输出" << endl;
        return ;
    }
    else
    {
        while (dequeue.right != -1)
        {
            cout << dequeue.element[dequeue.right --] << ' ';
            dequeue.size --;
        }

        cout << "OutputStack_R栈输出完毕" << endl;
    }
}

void OutputQueue(SQ_Dequeue dequeue)
{
    if (dequeue.size == 0)
    {
        cout << "队空，无需输出元素" << endl;
        return ;
    }
    else
    {
        while (dequeue.left != dequeue.right)
        {
            cout << dequeue.element[dequeue.left] << ' ';
            dequeue.left = (dequeue.left + 1) % SIZE;
        }
        cout << "队列输出完毕" << endl;
    }
}

int main()
{
    cout << "请选择要使用的数据结构\n1: 栈  2: 队列" << endl;
    
    int soq;
    cin >> soq;
    if (soq == 1)
    {
        cout << "请选择初始化栈的方式\n1: L方式  2: R方式" << endl;
        int ways; // 这里只是伪数据，还需要完善
        cin >> ways;
        if (ways == 1)
        {
            SQ_Dequeue stack;
            Init_Stack_L(&stack);

            cout << "请输入需要添加的元素个数" << endl;
            int n;
            cin >> n;

            cout << "请输入元素的具体值" << endl;
            int x;
            for (int i = 0; i < n; i ++)
            {
                cin >> x;
                Stack_Push_L(&stack, x);
            }

            OutputStack_L(stack);

            cout << "是否需要删除元素？1: YES  2: NO" << endl;
            int needrm;
            cin >> needrm;
            if (needrm == 1)
            {
                cout << "请输入要出栈的元素的个数" << endl;
                int n;
                cin >> n;
    
                for (int i = 0; i < n; i ++)
                {
                    Stack_Pop_L(&stack);
                }
            }

            OutputStack_L(stack);
        }
        else
        {
            SQ_Dequeue stack;
            Init_Stack_R(&stack);

            cout << "请输入需要添加的元素个数" << endl;
            int n;
            cin >> n;

            cout << "请输入元素的具体值" << endl;
            int x;
            for (int i = 0; i < n; i ++)
            {
                cin >> x;
                Stack_Push_R(&stack, x);
            }

            OutputStack_R(stack);

            cout << "是否需要删除元素？1: YES  2: NO" << endl;
            int needrm;
            cin >> needrm;
            if (needrm == 1)
            {
                cout << "请输入要出栈的元素的个数" << endl;
                int n;
                cin >> n;
    
                for (int i = 0; i < n; i ++)
                {
                    Stack_Pop_R(&stack);
                }
            }

            OutputStack_R(stack);
        }
        
    }
    // 使用队列结构
    else
    {
        SQ_Dequeue queue;
        Init_Queue(&queue);

        cout << "请输入需要入队的元素个数" << endl;
        int n;
        cin >> n;

        cout << "请输入元素的具体值" << endl;
        int x;
        for (int i = 0; i < n; i ++)
        {
            cin >> x;
            Queue_Push(&queue, x);
        }

        OutputQueue(queue);

        cout << "是否需要删除元素？1: YES  2: NO" << endl;
        int needrm;
        cin >> needrm;
        if (needrm == 1)
        {
            cout << "请输入要出队的元素的个数" << endl;
            int n;
            cin >> n;
 
            cout << queue.size << endl;
            for (int i = 0; i < n; i ++)
            {
                Queue_Pop(&queue);
            }
        }

        OutputQueue(queue);
    }

    return 0;
}

    

    