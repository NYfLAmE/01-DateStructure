 #include<stdio.h>
 #include<stdlib.h>

 // 构造一个链表

typedef struct NodeList
{
    int element; // 属性集合
    NodeList* next;
}Node;


// 操作集合
// 增删改查

// 添加结点
// 这里的链表是带头结点的链表
// 所以在构建链表的时候要初始化链表的头节点
// 初始化链表
Node* Init_List()
{
    // 想一想，为什么一个结点要初始化成指针的形式？
    // 去掉这个※号行吗？
    // 去掉这个符号之后，就成为了一个Nodelist的实例化对象，这个对象有两个指，一个element，一个指向下一个元素的指针
    // 这个元素可以指向下一个结点，那么上一个结点如何指向这个结点？
    // 难道让上一个结点的next = &node？貌似可以？这个就需要自己去尝试一下了
    // 好好弄清楚为什么要用指针来初始化一个结点？
    // 自己推理一遍：将结点初始化为一个指针之后，这个结点本身就是一个指针，它本身存储的就是一个地址值
    // 不过这个指针有点特殊，它是NodeList类的指针，就说明这个指针可以存两个指
    // 一个element，一个是指向下一个结点的指针
    // 还是没有弄清楚链表里的元素本质上是一个什么东西
    // 可以是任何东西？ 
    Node* head = (Node*)malloc(sizeof(Node)); // 使用malloc给头节点动态分配一个地址
    head->next = NULL; // 一开始只有一个头节点，所以头节点指向的元素为空
    head->element = 0;
    return head;
}

// 增加结点，传入该结点的属性以及在哪一个链表增加结点
void add_node(int key, Node* node)
{
    // 脑海里想一想增加结点的画面，要进行哪一些操作？
    // 肯定是先要增加一个新节点
    Node* tmp = (Node*)malloc(sizeof(Node));

    // 新节点指向要插入的链表的头节点下一个元素，这里为空NULL
    tmp->next = node->next;
    node->next = tmp;
    node->element ++;
    tmp->element = key;
}

// 查询一个结点

int find(int key, Node* node)
{
    Node* tmp = node->next;
    int i = 0;
    while (tmp != NULL)
    {
        // printf("现在tmp->next的值是：%d  ", tmp->element);
        if (tmp->element == key)
        {
            return i;
        }
        i ++;
        // printf("现在i的值是：%d\n", i);
        tmp = tmp->next;
    }

    return -1;
}

// 删除一个结点
void delete_node(int key, Node* node)
{
    if (node->next == NULL)
    {
        printf("传入空链表，无法进行删除，请先初始化一个链表\n");
    }
    else
    {
        int index = find(key, node);
        int i = 0;
        Node* tmp = node; // 删除一个结点，就要找到这个结点的前一个结点，所以tmp初始化为node而非node->next
        while (i < index)
        {
            // 当结束循环的时候，i == index，但是i对应的tmp是要删除的结点的上一个结点
            // 要是想不清楚就多想想
            i ++;
            tmp = tmp->next;
        }

        // 找到了前一个结点就要对结点删除了
        Node* free_node = tmp->next;
        tmp->next = tmp->next->next;
        free(free_node);
        free_node = NULL;
        printf("成功删除结点！\n");
    }
}

int main()
{
    Node* LinkList = Init_List();
    delete_node(2, LinkList);

    int n;
    scanf("%d", &n);
    int x;
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d", &x);
        add_node(x, LinkList);
        // printf("当前链表的元素个数是：%d\n", LinkList->element);
    }

    int q;
    scanf("%d", &q);

    int qq;
    while (q -- )
    {
        scanf("%d", &qq);
        int index = find(qq, LinkList);
        if (index == -1) printf("链表中不存在该元素\n");
        else printf("恭喜你，找到了该元素，该元素是链表中的第%d个结点\n", index + 1);
    }

    return 0;
}