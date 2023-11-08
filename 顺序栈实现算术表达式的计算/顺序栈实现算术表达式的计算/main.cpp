
#include <iostream>
#include "stack.hpp"
#include <string>

using namespace std;

int getPriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

string infixToPostfix(string infix) {
    stack<char> opStack;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isdigit(ch) || isalpha(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            opStack.push_back(ch);
        }
        else if (ch == ')') {
            while (!opStack.isempty() && opStack.gettop() != '(') {
                postfix += opStack.gettop();
                opStack.pop();
            }
            if (!opStack.isempty() && opStack.gettop() == '(') {
                opStack.pop();
            }
        }
        else {
            while (!opStack.isempty() && getPriority(opStack.gettop()) >= getPriority(ch)) {
                postfix += opStack.gettop();
                opStack.pop();
            }
            opStack.push_back(ch);
        }
    }

    while (!opStack.isempty()) {
        postfix += opStack.gettop();
        opStack.pop();
    }

    return postfix;
}
int calculate(int a, int b, char op)
{
    if (op == '+')
    {
        return a + b;
    }
    if (op == '-')
    {
        return a - b;
    }
    if (op == '*')
    {
        return a*b;
    }
    if (op == '/'&& b!=0)
    {
        return a / b;
    }
    return 0;
}
int cl_post(string post)
{
    stack<int> num;
    for (int i = 0; i < post.length(); i++)
    {
        char ch=post[i];
        if (isdigit(ch))
        {
            num.push_back(ch-'0');
        }
        else
        {
            int a = num.pop();
            int b = num.pop();
            int c=calculate(a, b, ch);
            num.push_back(c);

        }
    }
    return num.gettop();
}

int main() {
    string infix;
    cin >> infix;
    string postfix = infixToPostfix(infix);
    int result = cl_post(postfix);
    cout << result << endl;
    return 0;
}