#include <iostream>
#include <iomanip>
#include <string>

#include "ArrayStack.hpp"

bool checkBalance(const std::string& str)
{
    const size_t length = str.size();
    ArrayStack<char> pars(length);
    
    size_t currPos = 0;
    bool isBalanced = true;
    char mismatchedPar = ' ';
    for(size_t i = 0; i < length; i++)
    {
        currPos++;
        if(str[i] == '{' || str[i] == '(' || str[i] == '[') {
            pars.push(str[i]);
        } else if(str[i] == '}') {
            isBalanced = (pars.top() == '{');

            if(!isBalanced) {
                mismatchedPar = str[i];
                break;
            } 

            pars.pop();
        } else if(str[i] == ')') {
            isBalanced = (pars.top() == '(');

            if(!isBalanced) {
                mismatchedPar = str[i];
                break;
            } 

            pars.pop();
        } else if(str[i] == ']') {
            isBalanced = (pars.top() == '[');

            if(!isBalanced) {
                mismatchedPar = str[i];
                break;
            } 
            
            pars.pop();
        }
    }

    if(!isBalanced) {
        std::cout << "Mismatched pars at position: " << currPos << "\n";
        std::cout << "Stack top is: " << pars.top() << " ... " 
                  << "Mismatched par is: " << mismatchedPar << "\n";
    }

    isBalanced = (currPos == length);
    if(!isBalanced) {
        mismatchedPar = pars.top();
        std::cout << "Error: stack isn't empty. Top is: " << mismatchedPar << "\n";
    }

    return isBalanced;
}

int main()
{
    std::string testPattern1 = "{([()])}";
    bool tp1 = checkBalance(testPattern1);
    std::cout << std::boolalpha << "test pattern: " << testPattern1 << ": " << tp1 << "\n";

    std::string testPattern2 = "{([()])";
    bool tp2 = checkBalance(testPattern2);
    std::cout << std::boolalpha << "test pattern: " << testPattern2 << ": " << tp2 << "\n";

    std::string testPattern3 = "{(()])}";
    bool tp3 = checkBalance(testPattern3);
    std::cout << std::boolalpha << "test pattern: " << testPattern3 << ": " << tp3 << "\n";

    return 0;
}
