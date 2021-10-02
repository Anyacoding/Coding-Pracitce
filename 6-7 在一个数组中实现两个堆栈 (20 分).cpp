

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

Stack CreateStack(int MaxSize)
{   
    Stack p;
    p = (Stack)malloc(sizeof(struct SNode));
    p->Data = (int*)malloc(sizeof(int) * MaxSize);
    p->Top1 = -1;
    p->Top2 = MaxSize;
    p->MaxSize = MaxSize;
    return p;
}

bool Push(Stack S, ElementType X, int Tag)
{
    int i, j;

    if ((S->Top2 - S->Top1) == 1)
    {
        printf("Stack Full\n");
        return false;
    }
    if (Tag == 1)
    {
        (S->Top1)++;
        *(S->Data + S->Top1) = X;
        return true;
    }
    if (Tag == 2)
    {
        (S->Top2)--;
        *(S->Data + S->Top2) = X;
        return true;
    }
}

ElementType Pop(Stack S, int Tag)
{
    int n;
    
    
    if (Tag == 1)
    {
        if (S->Top1 == -1)
        {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
        n = *(S->Data + S->Top1);
        (S->Top1)--;
        return n;
    }
    
    if (Tag == 2)
    {
        if (S->Top2 == S->MaxSize)
        {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
        n = *(S->Data + S->Top2);
        (S->Top2)++;
        return n;
    }
    
        
    
}