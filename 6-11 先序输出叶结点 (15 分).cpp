// 6-11 先序输出叶结点 (15 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

void PreorderPrintLeaves(BinTree BT)
{
    if (BT)
    {
        if (BT->Left == NULL && BT->Right == NULL)
            printf(" %c", BT->Data);
        PreorderPrintLeaves(BT->Left);
        PreorderPrintLeaves(BT->Right);
    }
}