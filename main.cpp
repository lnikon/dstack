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

    isBalanced = (pars.empty());
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
    std::cout << std::boolalpha << "\ntest pattern: " << testPattern1 << ": " << tp1 << "\n";

    std::string testPattern2 = "{([()])";
    bool tp2 = checkBalance(testPattern2);
    std::cout << std::boolalpha << "\ntest pattern: " << testPattern2 << ": " << tp2 << "\n";

    std::string testPattern3 = "{(()])}";
    bool tp3 = checkBalance(testPattern3);
    std::cout << std::boolalpha << "\ntest pattern: " << testPattern3 << ": " << tp3 << "\n";


    std::string testPattern4 = "(}";
    bool tp4 = checkBalance(testPattern4);
    std::cout << std::boolalpha << "\ntest pattern: " << testPattern4 << ": " << tp4 << "\n";

    std::string testPattern5 = "{}";
    bool tp5 = checkBalance(testPattern5);
    std::cout << std::boolalpha << "\ntest pattern: " << testPattern5 << ": " << tp5 << "\n";

    std::string testPattern6 = "{{}{}{}}";
    bool tp6 = checkBalance(testPattern6);
    std::cout << std::boolalpha << "\ntest pattern: " << testPattern6 << ": " << tp6 << "\n";

    std::string testPattern7 = "{{{}}{()}}";
    bool tp7 = checkBalance(testPattern7);
    std::cout << std::boolalpha << "\ntest pattern: " << testPattern7 << ": " << tp7 << "\n";

    return 0;
}
