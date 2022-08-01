// #include<iostream>
// using namespace std;

// const int Max = 100;

// // 结点数据
// typedef struct TreeNode{
//     int element;
//     int parent;
// }Node;

// typedef struct parentTree{
//     Node nodes[Max];
//     int size;
//     int Maxsize;
// }PTree;

// // 初始化
// void Init(PTree* tree)
// {
//     tree->nodes[0].parent = -1;
//     tree->Maxsize = Max;
//     tree->size = 0;
//     cout << "初始化完成" << endl;
// }

// // 查找父结点
// int findparent(PTree* tree, int indexv)
// {
//     for (int i = 0; i < tree->size; i ++)
//     {
//         if (tree->nodes[i].element == indexv) 
//         {
//             return i;
//         }
//     }

//     return -1;
// }

// // 添加子节点
// void Insert(PTree* tree, int indexv, int key)
// {
//     if (tree->size == Max) 
//     {
//         cout << "树满，Insert失败" << endl;
//         return ;
//     }
//     else
//     {
//         int parent = findparent(tree, indexv);
//         if (parent == -1)
//         {
//             cout << "树中没有" << indexv << "这个结点，Insert失败，请确保输入数据的合法性" << endl;
//             return ;
//         }
//         else
//         {
//             tree->nodes[tree->size].element = key;
//             tree->nodes[tree->size].parent = parent;

//             tree->size ++;
//             cout << key << "Insert成功" << endl;
//         }
//     }
// }


// int main()
// {
//     int n;
//     cin >> n;

//     int x, p;

//     PTree tree;
//     Init(&tree);

//     cout << tree.size << endl;
//     for (int i = 0; i < n; i ++)
//     {
//         cin >> x >> p;
//         if (tree.size == 0)
//         {
//             tree.nodes[i].element = x;
//             tree.size ++;
//         }
//         else
//         {
//             Insert(&tree, p, x);
//         }

//         cout << tree.size << endl;
//     }

//     for (int i = 0; i < tree.size; i ++)
//     {
//         cout << tree.nodes[i].element << "  " << tree.nodes[i].parent << endl;
//     }

//     return 0;
// }


// 尝试十分钟之内实现树的双亲法表示，成功了
// #include<iostream>
// using namespace std;

// const int Max = 100;

// typedef struct TreeNode{
//     int element;
//     int parent;

// }Node;

// Node nodes[Max];
// int sizex = 0;
// int Maxsize = Max;

// // 初始化
// void Init()
// {
//     nodes[0].parent = -1;
// }

// // 找父亲
// int findparent(int p)
// {
//     for (int i = 0; i < sizex; i ++)
//     {
//         if (nodes[i].element == p) return i;
//     }

//     return -1;
// }
// // 插入结点
// void insert(int key, int p)
// {
//     int parent = findparent(p);
//     if (parent == -1)
//     {
//         cout << "不存在该父结点，insert失败" << endl;
//         return ;
//     }
//     else
//     {
//         nodes[sizex].element = key;
//         nodes[sizex].parent = parent;
//         sizex ++;
//         cout << "insert成功" << endl;
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;

//     int x, p;
//     for (int i = 0; i < n; i ++)
//     {
//         cin >> x >> p;
//         if (sizex == 0)
//         {
//             nodes[i].element = x;
//             nodes[i].parent = -1;
//             sizex ++;
//         }
//         else
//         {
//             insert(x, p);
//         }
//     }

//     for (int i = 0; i < sizex; i ++)
//     {
//         cout << nodes[i].element << " " << nodes[i].parent << endl;
//     }

//     return 0;
// }



// 7.27  手写双亲表示法，复习一遍
// 7.27下午写代码耗时15min，调试测试耗时5分钟，总共耗时20分钟
// #include<iostream>
// using namespace std;

// const int Max = 100;

// typedef struct TreeNode{
//     int element;
//     int parent;
// }Node;

// Node tree[Max];

// int sizeoftree;
// int Maxsize = Max;
// // 初始化
// // 考虑到根结点的特殊性，这里将插入根结点和初始化分开，分别设置两个函数
// void Init()
// {
//     sizeoftree = 0;
//     cout << "初始化完成" << endl;
// }

// // 插入根结点
// void InsertRoot(int key)
// {
//     tree[0].element = key;
//     tree[0].parent = -1;
//     sizeoftree ++;
//     cout << "根结点插入成功" << endl;
// }

// // 找父亲
// int findp(int key)
// {
//     for (int i = 0; i < sizeoftree; i ++)
//     {
//         if (tree[i].element == key)
//         return i;
//     }

//     return -1;
// }

// // 插入一般结点
// void InsertNode(int key, int p)
// {
//     int parent = findp(p);
//     if (parent == -1)
//     {
//         cout << "树种没有该结点，Insert失败" << endl;
//         return ;
//     }
//     else
//     {
//         tree[sizeoftree].element = key;
//         tree[sizeoftree].parent = parent;
//         sizeoftree ++;
//         cout << "Insert成功" << endl;
//     }
// }

// // 输出树
// void OutputTree()
// {
//     for (int i = 0; i < sizeoftree; i ++)
//     {
//         // 当前结点的值  当前结点的双亲  当前结点的双亲的值
//         cout << tree[i].element << "    " << tree[i].parent << "    " << tree[tree[i].parent].element << endl;;
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;

//     int x;
//     for (int i = 0; i < n; i ++)
//     {
//         cin >> x;
//         if (sizeoftree == 0)
//         {
//             InsertRoot(x);
//         }
//         else
//         {
//             int p;
//             cin >> p;
//             InsertNode(x, p);
//         }
//     }

//     OutputTree();
//     return 0;
// }