
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

ElementType FindKth(List L, int K)
{
    int len = 0;
    while (L != NULL)
    {
        len++;
        if (len == K)
        {
            return L->Data;
        }
        L = L->Next;
    }
    return ERROR;
}