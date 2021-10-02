
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

List MakeEmpty()
{
    List head;
    head = (List)malloc(sizeof(struct LNode));
    head->Next = NULL;
    return head;

}

Position Find(List L, ElementType X)
{
    while (L != NULL)
    {
        if (L->Data == X)
        {
            return L;
        }
        L = L->Next;
    }
    return ERROR;
}

bool Insert(List L, ElementType X, Position P)
{
    List head=L->Next, q, p;
    
    if (head == P)
    {
        p = (List)malloc(sizeof(struct LNode));
        p->Data = X;
        p->Next = head;
        L->Next = p;
        return true;
    }
    while (head != NULL)
    {
        if (P == head->Next)
        {
            p = (List)malloc(sizeof(struct LNode));
            p->Data = X;
            p->Next = head->Next;
            head->Next = p;
            return true;
        }
        head = head->Next;
    }
    printf("Wrong Position for Insertion\n");
    return false;
}

bool Delete(List L, Position P)
{
    List head = L->Next;
    
    if (head == P)
    {
        L->Next = P->Next;
        return true;
    }

    while (head != NULL)
    {
        if (head->Next == P)
        {
            head->Next = P->Next;
            return true;
        }
        head = head->Next;
    }

    printf("Wrong Position for Deletion\n");
    return false;
}