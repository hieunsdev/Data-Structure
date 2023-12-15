/*
	Check balanced parentheses..... NOT DONE YET
*/
#include<iostream>
#include<string>

using namespace std;

// using stack to check what if the text, (<operand><operator><operand>) is balanced parentheses
// travel from left to right of text, if (, {, [, < put it into stack and check 
// if meet closing euivalent parentheses --> 

struct symbol {
	char parentheses;
	int position;
};

int top_stack = -1;
symbol s[500];

void push(char value, int pos) {
	top_stack++;
	s[top_stack].parentheses = value;
	s[top_stack].position = pos;
} // position of this value in string

void pop() {
	top_stack -= 1;
}

char top() {
	return s[top_stack].parentheses;
}

void balanced(string str, int size) { // size of string argument
	int count1 = 0, // ()
		count2 = 0, // {}
		count3 = 0, // []
		count4 = 0; // <>
	for (int i = 0; i < size; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[' || str[i] == '<') {
			push(str[i], i);
		}
		else continue;
	}
	while (top_stack != -1) {
		if (top() == '(') {
			for (int i = s[top_stack].position + 1; i < size; i++) {
				if (str[i] == '}' || str[i] == ']' || str[i] == '>') {
					count1 += 1;
					break;
				}
				else if (str[i] == ')') {
					str[i] = '0'; // to make sure have one or more balanced parentheses inside a balanced parentheses
					break;
				}
				else if (i = size - 1 && str[i] != ')') { // when travel to the last and no '>' => unbalanced
					count4 += 1;
					break;
				}
				else continue;
			}
			top_stack -= 1; // equivalent pop()
		}
		if (top() == '{') {
			for (int i = s[top_stack].position + 1; i < size; i++) {
				if (str[i] == ')' || str[i] == ']' || str[i] == '>') {
					count2 += 1;
					break;
				}
				else if (str[i] == '}') {
					str[i] = '0';
					break;
				}
				else if (i = size - 1 && str[i] != '}') { // when travel to the last and no '>' => unbalanced
					count4 += 1;
					break;
				}
				else continue;
			}
			top_stack -= 1;
		}
		if (top() == '[') {
			for (int i = s[top_stack].position + 1; i < size; i++) {
				if (str[i] == '}' || str[i] == ')' || str[i] == '>') {
					count3 += 1;
					break;
				}
				else if (str[i] == ']') {
					str[i] = '0';
					break;
				}
				else if (i = size - 1 && str[i] != ']') { // when travel to the last and no '>' => unbalanced
					count4 += 1;
					break;
				}
				else continue;
			}
			top_stack -= 1;
		}
		if (top() == '<') {
			for (int i = s[top_stack].position + 1; i < size; i++) {
				if (str[i] == '}' || str[i] == ']' || str[i] == ')') {
					count4 += 1;
					break;
				}
				else if (str[i] == '>') {
					str[i] = '0';
					break;
				}
				else if (i = size - 1 && str[i] != '>') { // when travel to the last and no '>' => unbalanced
					count4 += 1;
					break;
				}
				else continue;
			}
			top_stack -= 1;
		}
	}
	cout << "Your string lack of "
		<< endl << count1 << " )"
		<< endl << count2 << " }"
		<< endl << count3 << " ]"
		<< endl << count4 << " >" << " to be balanced parentheses";
}


int main() {
	string str;
	cout << "Your string: ";
	getline(cin, str);
	balanced(str, str.length());
	return 0;
}