#include<iostream>
using namespace std;

// 搭建一个链表框架
typedef struct NodeList{
    int element;
    NodeList* next;
}Node;

// 初始化链表
Node* Init_List()
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->element = 0;
    cout << "成功初始化一个链表" << endl;
    return node;
}

// 增加结点
// 头插
void add_node(int key, Node* node)
{
    Node *tmp = (Node*)malloc(sizeof(Node)); // 使用malloc和不适用malloc有什么区别？
    tmp->next = node->next;
    node->next = tmp;
    node->element ++;
    tmp->element = key; // 因为这一行代码，debug用来差不多一个小时
    cout << "成功添加一个结点" << endl;
}

// 删除一个结点
// 删除之前要查询链表中是否有这个结点
int find(int key, Node* node)
{
    if (node->next == NULL)
    {
        return -1;
    }
   
    Node* tmp = node->next;
    int i = 0; // 下标从零开始
    while (tmp != NULL)    
    {
        if (tmp->element == key)
        {
            cout << "已经找到该元素" << endl;
            return i;
        }
        // cout << "i的值：" << i << endl;
        i ++;
        tmp = tmp->next;
    }
    return -1; 
}

// 删除一个结点
void delete_node(int key, Node* node)
{
    if (node->next == NULL) cout << "传入的是一个空链表，无法删除结点，请先初始化一个链表" << endl;
    else
    {
        int i = 0, index = find(key, node);
        cout << "index：" << index;
        if (index != -1)
        {
            Node* tmp = node;
            while (i < index) // i < index的目的就是为了找到 要删除的结点的前一个结点
            {
                i ++;
                tmp = tmp->next;
            }

            // 在C里面，没有垃圾回收机制，所以在删除结点之后我们要手动释放空间，这里先定义一个free node记住原来的结点
            Node* free_node = tmp->next;
            tmp->next = tmp->next->next;
            free(free_node);
            free_node = NULL; // 养成良好习惯，手动释放之后将该节点对应的指针赋值为NULL
            node->element --;
            cout << "成功删除一个结点" << endl;
        }
        else cout << "链表中没有该元素，请输入正确的元素以便修改" << endl;
    }
}

// 修改一个结点
void modify_node(int key, int mode, Node* node)
{
    int index = find(key, node);
    if (index == -1)
    {
        cout << "链表中没有该元素，请输入正确的元素以便修改" << endl;
    }
    else
    {
        int i = 0;
        Node* tmp = node->next;
        while (i < index)
        {
            i ++;
            tmp = tmp->next;
        }
        tmp->element = mode;
        cout << "修改成功" << endl;
    }
}

int main()
{
    Node* node = Init_List();
    delete_node(1, node);

    int n;
    cin >> n;

    int x;
    for (int i = 0; i < n; i ++)
    {
        cin >> x;
        add_node(x, node);
        cout << "当前链表的结点个数(不包含头节点)为：" << node->element << endl;
    }

    int de;
    cout << "请输入要删除的节点数: ";
    cin >> de;
    int dele;
    for (int i = 0; i < de; i ++ )
    {
        cin >> dele;
        delete_node(dele, node);
        cout << "当前链表的结点个数(不包含头节点)为：" << node->element << endl;
    }

    int numsleft = node->element;
    if (numsleft == 0)
    {
        cout << "空链表，请先添加结点，再修改结点" << endl;
        return 0;
    }
    cout << "请输入要修改的结点个数：";
    int mo;
    cin >> mo;
    int modi, key;
    for (int i = 0; i < mo; i ++ )
    {
        cin >> key;
        cin >> modi;
        modify_node(key, modi, node);
    }

    cout << "目前的链表：";
    for (Node* tmp = node->next; tmp != NULL; tmp = tmp->next)
    {
        cout << tmp->element << ' ';
    }

    return 0;
}
