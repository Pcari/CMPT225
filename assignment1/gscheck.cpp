// Assignment 1

#include "char_stack.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

//checks if two arguments are pair
bool isPair(char left, char right) {
	if (left == '(' && right == ')') 
		return true;
	else if (left == '{' && right == '}')
		return true;
	else if (left == '[' && right == ']')
		return true;
	return false;
}

int main (int argc, char * const argv[]) {

	char_stack stack;
	string input;
	int line =1;
	char c;
	int i = 0;
	char left;
	char inputLine[300];



	

	c = getchar();
	while (c != EOF) {
		inputLine[i] = c; //saving each line in an array

		if (c == '\n') {
			line++;
			i = 0;
			memset(inputLine, 0, sizeof(inputLine[0])); //reset for new lines
		}
		//push opening symbols onto stack
		if (c == '(' || c == '[' || c == '{') {
			stack.push(c);
	
		}
		else if (c == ')' || c == ']' || c == '}') {
		
			if (stack.empty()) { 
				cout << "Error on line " << line << ": Too many " << c << endl;
				
				for (int j = 0; j <= i; j++) {
					cout << inputLine[j];
				}
				cout << endl;
				for (int j = 0; j <= i; j++) { //print tab or space depending on input
					if (inputLine[j] == '\t') {
						cout << '\t';	
					} else {
						cout << " ";
					}

				}
				c = getchar();	// print rest of the line			
				while (c != '\n') {
					cout << c;
					c = getchar();
				}
				cout << endl;
				return 1;
			}
			left = stack.pop();
			if (!isPair(left, c)) {
				cout << "Error on line " << line << ": Read " << c
				<< ", expected ";
				if (left == '(')
					cout << ")";
				else if (left == '{')
					cout << "}";
				else if (left == '[')
					cout << "]";

				cout << endl;

				for (int j = 0; j <= i; j++) {
					
					cout << inputLine[j];
				
				}
				cout << endl;				
				for (int j = 0; j <= i; j++) {					
					if (inputLine[j] == '\t') {
						cout << '\t';	
					} else {
						cout << " ";
					}
				}
				c = getchar();
				while (c != '\n') {
					cout << c;
					c = getchar();
				}
				cout << endl;			
				return 1;
			}

		}
		i++;
		c = getchar();

	}
	
	while (!stack.empty()) {
		c = stack.pop();
		cout << "Error at end of file: Too many " << c << endl;
	}
	return 1; 


	cout << "No Errors Found" << endl;
	return 0;
}

