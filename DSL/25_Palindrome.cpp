#include<iostream>
#include<string>
using namespace std;


template <typename T, int MAX_SIZE>
class Stack {
private:
    T data[MAX_SIZE];
    int topIndex;

public:
    Stack(){
        topIndex = -1;
    }// constructor

    void push(const T& value) {
        if (topIndex == MAX_SIZE - 1) {
            throw runtime_error("Stack is full");
        }

        data[++topIndex] = value;
    }

    void pop() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }

        --topIndex;
    }

    T& top() {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }

        return data[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

string modifystring(const string& str) {
    string result;
    for (char c : str) {
        if (isalnum(c)) {
            result += tolower(c);
        }
    }
    return result;
}

bool isPalindrome(const string& str) {
    Stack<char, 200> stack;

    for (int i = 0; i < str.length(); ++i) {
        stack.push(str[i]);
    }

    int i = 0;
    while (!stack.isEmpty()) {
        if (stack.top() != str[i]) {
            return false;
        }
        stack.pop();
        i++;
    }

    return true;
}
int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string processedStr = modifystring(str);
    cout<<processedStr<<endl;

    if (isPalindrome(processedStr)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
