//
//  Test Program for Basic Int Stack Class
//
#include <iostream>   // for I/O facilities
#include "basic_int_stack.h" //  basic_int_stack declarations
using namespace std;

int main (int argc, char * const argv[]) {
    
	cout << "Ben Jae" << endl;
	cout << "bjae" << endl;
	cout << "301048319" << endl;

	Basic_int_stack s1;
	int input = 0;
	int sum = 0;

	cin >> input;
	while (input >= 0) {
		s1.push(input);
		sum += input;
		cin >> input;

	}

	cout << endl;
	cout << "length: " << s1.size() << endl;
	cout << "sum: " << sum << endl;

	while (!s1.empty()) {
		cout << s1.pop() << endl;
	}



    return 0;
}
