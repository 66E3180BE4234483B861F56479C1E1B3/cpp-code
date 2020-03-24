#include <iostream>

#include "seqStack.h"

bool match(const std::string& str)
{
    Stack<char> stack(str.length());
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
            stack.push(str[i]);

        if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
            if (str[i] == '}' && stack.top() != '{' || str[i] == ')' && stack.top() != '('
            || str[i] == ']' && stack.top() != '[')
                return false;

            stack.pop();
        }
    }

    if (!stack.isEmpty())
        return false;

    return true;
}
int main() {
    std::cout << (match("(){{([[]])()") == true ? "true" : "false") << std::endl;

    return 0;
}
