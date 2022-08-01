// // 孩子表示法、

// #include<iostream>
// #define Max 20
// using namespace std;

// // 孩子表示法：讲清楚当前结点的孩子有哪一些
// // 数据集合
// typedef struct TreeNode{
//     // 结点的数据信息
//     int element;

//     // 结点的孩子链表头指针
//     TreeNode* next;
// }Node;

// // 当前树的结点个数
// int sizet;
// // 当前树的最大容量
// int Maxsize;

// Node* tree[Max];
// // 操作集合
// // 初始化
// void Init(int key)
// {
//     // 首先要插入一个根结点
//     // 这里要重点理解一下，上面的Node* tree[Max]的效果是什么
//     // 弄清楚为什么在这里需要malloc动态分配一个空间给新结点
//     Node* new_node = (Node*)malloc(sizeof(Node));
//     new_node->element = key;
//     new_node->next = NULL;

//     tree[sizet] = new_node;

//     Maxsize = Max;
//     sizet ++; 

//     cout << "结点" << key << "Init初始化完成" << endl;
// }

// // 一般结点的插入
// // 首先要找父结点是否存在
// int findparent(int p)
// {
//     for (int i = 0; i < sizet; i ++)
//     {
//         if (p == tree[i]->element)
//         {
//             return i;
//         }
//     }

//     return -1;
// }

// // 一般结点的插入
// // key是新结点的值，p是要插入的父结点的值
// void Insert(int key, int p)
// {
//     int parent = findparent(p);
//     if (parent == -1)
//     {
//         cout << "当前状态下，树中没有该结点，insert失败" << endl;

//         // 下面两行代码是在听懂课之前自己的思路：先把所有的结点放在数组中，处理了双亲结点但是没有处理孩子结点(当前节点)
//         // cout << "正在构建这个父结点" << endl;
//         // Init(p);

//         return ;
//     }
//     else
//     {
//         // 下面是修改后的代码
//         // 因为是从上到下依次构建这一颗树，所以
//         // 若数组中有指定的父亲结点就可以插入：先把这个双亲结点的孩子结点(当前结点)放在数组中
//         // 为什么是把当前孩子结点放进数组中：因为是从上到下依次构造这一颗树
//         // 若数组中没有该指定的父亲节点就直接return插入失败

//         if (sizet == Maxsize)
//         {
//             cout << "树满，无法进行Insert" << endl;
//             return ;
//         }

//         Init(key); 
//         // 这里需要加深理解
//         // 为什么要malloc动态分配一个空间？和上面的问题是一样的
//         // 重点是要搞清楚Node* tree[Max]的效果是啥，它会在定义指针变量的时候给指针变量分配空间吗？\

//         // 建立新结点
//         // 和单链表的头插是一样的
//         Node* new_node = (Node*)malloc(sizeof(Node));
//         new_node->element = key;
//         new_node->next = tree[parent]->next;
//         tree[parent]->next = new_node;

//         // 更新树的结点数
//         cout << "Insert成功" << endl;
//     }

//     // parent = findparent(key);
//     // if (parent == -1)
//     // {
//     //     cout << "正在新建结点并存放在表头" << endl;
//     //     Init(key);
//     // }
// }

// // 貌似图灵机写的孩子表示法有缺陷
// // 每一次构建一棵树的时候，图灵机的代码只会判断传入的p结点是否存在，忽略了判断key结点是否在表头中存在
// // 对于叶子结点，由于它没有子节点，所以并不会进行Insert操作，自然不会在表头中存放根结点的数据
// // 这就是我认为的缺陷
// // 虽说能够保证有孩子的结点存放在表头中，但是对于没有子结点的结点，就不会在表头中出现该结点的数据
// // 但是却能通过其它结点的孩子链表找到这个结点

// // 是否是自己对孩子表示法理解的错误，表头数组一定要把所有的结点都存起来吗？
// // 对于没有孩子的结点，若不存放在表头中，也可以通过其父结点的链表访问到它
// // 根据孩子表示法的定义，貌似又没有必要将叶子节点存放在表头？

// int main()
// {
//     int n;
//     cin >> n;

//     Init(1);
//     int x, p;
//     for (int i = 0; i < n; i ++)
//     {
//         cin >> x >> p;
//         Insert(x, p);
//     }

//     for (int i = 0; i < sizet; i ++)
//     {
//         cout << "ParentNode: " << tree[i]->element << endl;

//         // 遍历孩子链表输出孩子
//         Node* tmp = tree[i]->next;
//         while (tmp)
//         {
//             cout << "ChildNode: " << tmp->element << "  ";
//             tmp = tmp->next;
//         }

//         cout << endl << endl;
//     }

//     return 0;
// }


#include<iostream>
using namespace std;

int main()
{
    cout << "hello world" << endl;
    return 0;
}