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
