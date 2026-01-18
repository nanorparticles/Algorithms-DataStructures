#include "palindrome.h"
#include <iostream>

bool Palindrome::is_palindrome(const int number){	
		int original = number;  
		int reversed = 0; 

		while(original > 0){
			int digit = original % 10; 
			reversed = reversed*10 + digit; 
			original  /= 10; 
		} 
		return number == reversed; 
	} 

int main() {
    Palindrome palindrome_checker;
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number; 
    if (palindrome_checker.is_palindrome(number)) {
        std::cout << number << " is a palindrome." << std::endl;
    } else {
        std::cout << number << " is not a palindrome." << std::endl;
    }
    return 0;
}