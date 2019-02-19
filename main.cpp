#include <iostream>

#include "ArrayStack.hpp"

int main()
{
    ArrayStack<int> ob(5);

    int size = 5;
    for(int i = 0; i < size; i++)
    {
        ob.push(i);
    }

    int top = ob.top();
    std::cout << top << std::endl;
    std::cout << top << std::endl;
    ob.pop();
    top = ob.top();
    std::cout << top << std::endl;


    return 0;
}
