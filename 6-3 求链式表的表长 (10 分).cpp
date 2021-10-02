
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

int Length(List L)
{
    int len = 0;
    
    while (L != NULL)
    {
        len++;
        L = L->Next;

    }
    return len;
}