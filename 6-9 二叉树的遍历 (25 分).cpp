

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

void InorderTraversal(BinTree BT)
{
    if (BT)
    {
        
        InorderTraversal(BT->Left);
        printf(" %c", BT->Data);
        InorderTraversal(BT->Right);
    }
}

void PreorderTraversal(BinTree BT)
{
    if (BT)
    {   
        printf(" %c", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

void PostorderTraversal(BinTree BT)
{
    if (BT)
    {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf(" %c", BT->Data);
    }
}

void LevelorderTraversal(BinTree BT)
{
    BinTree T;
    if (BT == NULL)
        return;
    BinTree duilie[9999];
    int head=0, tail=0;
    duilie[++tail] = BT;
    while (head != tail)
    {
        T = duilie[++head];
        printf(" %c", T->Data);
        if (T->Left)
            duilie[++tail] = T->Left;
        if (T->Right)
            duilie[++tail] = T->Right;
    }

}