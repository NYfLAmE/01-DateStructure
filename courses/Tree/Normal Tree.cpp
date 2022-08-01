// 一般树的表示
// 孩子兄弟表示法
// 每一个结点(最开始的设定)有两个指针域，一个指向自己的长子(最左边的孩子)一个指向自己的右兄弟
// 因为，一个结点的最左边的孩子如果有，就只能唯一，一个结点的右兄弟也是如此，有就唯一，没有就没有
// 所有，用链表加链表的方式来实现一棵树

// -----------------------------------------------------------------------
/*  7.25完写代码的时候卡壳，不知道怎么去存储一棵树，不知道怎么去表示树中结点的孩子，兄弟，父亲是谁
    写不出来，转战去写一个构造二叉树的代码，听完课之后再来写一般树的代码
*/
// 属性集合
// 数据信息，指针域
typedef struct TreeNode{
    int element;
    TreeNode* lchild;
    TreeNode* rsibling;

    // 加一个双亲域吧
    TreeNode* parent;

    // 树的结点数
    int size;
}TN;

// 初始化
void Init_Tree(TN* tree)
{
    if (!tree)
    {
        cout << "目前未生成一棵树，正在生成一棵树" << endl;
        tree = (TN*)malloc(sizeof(TN));
        cout << "成功生成一棵树" << endl;
    }
    
    // 初始化
    tree->size = 0;
    cout << "初始化完成" << endl;
}

// 向树中添加一个结点
void Insert(TN* tree, int key, int i)
{
    if (!tree)
    {
        cout << "树未生成，请先生成一棵树" << endl;
        return ;
    }
    else
    {

    }
}
#include<iostream>
using namespace std;

int main()
{
    
}