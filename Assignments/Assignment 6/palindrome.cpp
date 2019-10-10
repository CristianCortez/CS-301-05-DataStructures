/*
Authors:
Paulo Chu za8684
Cristian Cortez if2482
Kevin Nguyen ta8783
CS-301-05 Data Structures
Program 6
*/

#include <string>
#include <iostream>

using namespace std;

void isPalindrome(int begin, int end, string s) {
	if (begin >= end) {
		cout << "The string " << s << " is a palindrome.\n" << endl;
	}
	else if (s[begin] != s[end]){
		cout << "The string " << s << " is not a palindrome.\n" << endl;
	}
	else {
		return isPalindrome(++begin, --end, s);
	}
}

int main() {
	string input;
	int length;
	cout << "Enter a string to test: ";
	getline(cin, input);
	cout << "\n";
	length = input.length();
	isPalindrome(0, length - 1, input);
	cin >> input;
}
