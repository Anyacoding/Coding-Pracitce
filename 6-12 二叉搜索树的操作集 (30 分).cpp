// 6-12 二叉搜索树的操作集 (30 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

Position Find(BinTree BST, ElementType X)
{
    if (BST == NULL) return NULL;
    if (BST->Data == X) return BST;
    if (BST->Data > X)  return Find(BST->Left, X);
    if (BST->Data < X)  return Find(BST->Right, X);

}

Position FindMin(BinTree BST)
{
    if (BST != NULL)
    {
        while (BST->Left)
        {
            BST = BST->Left;
        }
    }
    return BST;
}

Position FindMax(BinTree BST)
{
    if (BST == NULL) return BST;
    else if (BST->Right == NULL) return BST;
    else if (BST->Right != NULL) return FindMax(BST->Right);
}

BinTree Insert(BinTree BST, ElementType X)
{
    BinTree T;

    if (BST == NULL)
    {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    }
    if (BST->Data > X)
        BST->Left = Insert(BST->Left, X);
    if (BST->Data < X)
        BST->Right = Insert(BST->Right, X);

    return BST;

}

BinTree Delete(BinTree BST, ElementType X)
{
    BinTree  temp;

    if (BST == NULL)
    {
        printf("Not Found\n");
    }
    else if (BST->Data > X)
        BST->Left = Delete(BST->Left, X);
    else if (BST->Data < X)
        BST->Right = Delete(BST->Right, X);
    else
    {
        if (BST->Left && BST->Right)
        {
            temp = FindMin(BST->Right);
            BST->Data = temp->Data;
            BST->Right = Delete(BST->Right, temp->Data);
        }
        else if (BST->Left == NULL)
        {
            BST = BST->Right;
        }
        else if (BST->Right == NULL)
        {
            BST = BST->Left;
        }
    }

    return BST;
}