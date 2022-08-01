// 7.25完尝试写一般树的代码失败，转战二叉树的构建代码，失败
// 写的什么勾八代码，这么low还写不对

#include<iostream>
using namespace std;

// 二叉树结点的属性集合
typedef struct BinaryTree{
    int element;
    int size;

    BinaryTree* lchild;
    BinaryTree* rchild;
}BT;

// 初始化
void Init(BT* tree)
{
    if (!tree)
    {
        cout << "未生成二叉树，正在生成一棵二叉树" << endl;
        tree = (BT*)malloc(sizeof(BT));

        cout << "成功生成一棵二叉树" << endl;
    }

    tree->size = 0;
    cout << "初始化成功" << endl;
}

// 创建一棵二叉树
void CreateBinaryTree(BT* tree)
{
    int x;
    cout << "是否添加结点？1：Yes  2：No\n";
    cin >> x;
    if (x == 1)
    {
        int n;
        cin >> n;

        // 结点赋值
        tree->element = n;
        tree->size ++;

        // 右子树，左子树分配空间
        tree->lchild = (BT*)malloc(sizeof(BT));
        tree->rchild = (BT*)malloc(sizeof(BT));

        // 递归构建二叉树2
        CreateBinaryTree(tree->lchild);
        CreateBinaryTree(tree->rchild);
    }
    else
    {
        cout << "二叉树构建完成" << endl;
        return ;
    }
}

// 前序输出二叉树
void preout(BT* tree)
{
    if (!tree)
    {
        cout << "树都没给我传进来，输出个der" << endl;
        return ;
    }
    else
    {
        if (tree->size == 0)
        {
            cout << "树上一个结点都没有，输出个der" << endl;
            return ;
        }
        else
        {
            cout << tree->element << ' ';

            // 递归调用
            preout(tree->lchild);
            preout(tree->rchild);
        }
    }
}

// 中序输出二叉树
void inout(BT* tree)
{
    if (!tree)
    {
        cout << "树都没给我传进来，输出个der" << endl;
        return ;
    }
    else
    {
        if (tree->size == 0)
        {
            cout << "树上一个结点都没有，输出个der" << endl;
            return ;
        }
        else
        {
            // 递归调用
            inout(tree->lchild);

            cout << tree->element << ' ';

            inout(tree->rchild);
        }
    }
}

int main()
{
    BT tree;
    Init(&tree);

    CreateBinaryTree(&tree);
    inout(&tree);
    
    return 0;
}