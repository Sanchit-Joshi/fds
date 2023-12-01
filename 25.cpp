#include <iostream>
#include <stack>
#include <algorithm>

// Function to print the original string followed by the reversed string using a stack
void printOriginalAndReversedString(const std::string& str) {
    std::stack<char> charStack;
    
    // Push each character of the string onto the stack
    for (char c : str) {
        charStack.push(c);
    }
    
    std::cout << "Original String: " << str << std::endl;
    std::cout << "Reversed String: ";
    
    // Pop and print each character from the stack
    while (!charStack.empty()) {
        std::cout << charStack.top();
        charStack.pop();
    }
    
    std::cout << std::endl;
}

// Function to check whether a given string is a palindrome or not
bool isPalindrome(const std::string& str) {
    std::string reversedStr = str;
    
    // Reverse the string using the reverse function from the algorithm library
    std::reverse(reversedStr.begin(), reversedStr.end());
    
    // Compare the original string with the reversed string
    if (str == reversedStr) {
        return true;
    } else {
        return false;
    }
}

int main() {
    std::string inputString;
    
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);
    
    printOriginalAndReversedString(inputString);
    
    if (isPalindrome(inputString)) {
        std::cout << "The string is a palindrome." << std::endl;
    } else {
        std::cout << "The string is not a palindrome." << std::endl;
    }
    
    return 0;
}
