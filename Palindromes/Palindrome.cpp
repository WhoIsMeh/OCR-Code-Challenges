#include <iostream>

int main()
{
    std::string input;
    std::cout << "Please enter a word to verify if it is a palindrome.";
    std::cin >> input;
    std::cout << input << (input == std::string(input.rbegin(), input.rend()) ? " is": " is not") << " a palindrome";
}
