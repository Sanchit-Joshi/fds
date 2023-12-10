
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;
    
    for (char c : infix) // for loop to traverse the infix expression
     {
        if (isalnum(c)) {  //alnum() checks if the character is alphanumeric
            postfix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop '(' from the stack
        }
        else if (isOperator(c)) {
            while (!s.empty() && getPrecedence(c) <= getPrecedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix) {
    stack<int> s;
    
    for (char c : postfix) {
        if(c == ' ') continue;
        else if (isdigit(c)) {
            s.push(c - '0');
        }
        else if (isOperator(c)) {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();
            
            switch (c) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    s.push(operand1 / operand2);
                    break;
            }
        }
    }
    
    return s.top();
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin>>infix;
    
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    
    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;
    
    return 0;
}



