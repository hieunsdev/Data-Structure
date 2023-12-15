/*
	Class of Expression Notation (postfix, prefix, Infix) -- convert and calculate (using Stack)
	Infix: <operand><operator><operand> -- for human readable
	Postfix: <operand><operand><operator> -- good for machine
	Prefix: <operator><operand><operand> -- good for machine
	Tested and run fine---3/11/2022 (Month/Day/Year)
	Template format --- can use like personal libruary
*/

// NOTE: You must make sure your math expression is balanced parentheses
// symbol here stands for valriable like a, b, c, d, ..... in your input
// notation is "sign" like +, -, *, /, %
// Maybe it's wrong about conceptly because I'm not really goot at English

#include"template.h"
#include"queue.h"
#include"stack.h"

using namespace std;

struct symbol { // symbol here stands for variable (a, b, c, d..... ) in your input string
	char value; // symbol
	int number; // the number of this symbol in string
};

struct symbolStr {
	int number; // the number of diffirent symbols in string
	char value[20]; // array to store that symbols
};

class ExpressionNotation {
private:
	StackArray<char> stack;
	string input;
public:
	ExpressionNotation() {
		input = "";
	}
	string setInputInfix(string input_para) {
		input = input_para;
		return input;
	}
	void setInputPrefix(string input_para) {
		input = input_para;
	}
	void setInputPostfix(string input_para) {
		input = input_para;
	}
	void printStack() {
		stack.print();
	}
	string convertIn_Post() { // browse left to right
		int length = input.length();
		QueueLL<char> q; // to store the element of string that be returned
		for (int i = 0; i < length; i++) {
			if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%' || input[i] == '(') {
				stack.push(input[i]);
			}
			else {
				if (input[i] != ')') {
					q.enQueue(input[i]);
					if (stack.getTop() == '(' || stack.getTopIndex() == -1 || // -1 to pass if consider the first element
						stack.getTop() == '+' || stack.getTop() == '-') continue;
					// pass when stack empty, pass +, - and pass ( to wait *, /, % and )
					else {
						q.enQueue(stack.getTop());  // just print * / % 
						stack.pop();
					}
				}
				else {
					while (stack.getTop() != '(') { // when meet ), print all element we pass below
						q.enQueue(stack.getTop());
						stack.pop();
					}
					stack.pop();
				}
			}
		}
		while (stack.getTopIndex() != -1) { //print the others remain in stack
			q.enQueue(stack.getTop());
			stack.pop();
		}
		int length_queue = q.getLength();
		char* result = new char[length_queue];
		for (int i = 0; i < length_queue; i++) {
			result[i] = q.frontQueue()->data; //
			q.deQueue();
		}
		result[length_queue] = NULL;
		return result;
	}
	string convertIn_Pre() { //browse right to left, use stack linked list (just for print reverse when we done browse)
		int length = input.length();
		StackLL<char> s;
		for (int i = length - 1; i >= 0; i--) {
			if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%' || input[i] == ')') {
				stack.push(input[i]);
			}
			else {
				if (input[i] != '(') {
					s.push(input[i]);
					if (stack.getTop() == ')' || stack.getTopIndex() == -1 || // -1 to pass if consider the first element
						stack.getTop() == '+' || stack.getTop() == '-') continue;// pass when stack empty, pass +, - and pass ( to wait *, /, % and )
					else {
						s.push(stack.getTop()); // just print * / % 
						stack.pop();
					}
				}
				else {
					while (stack.getTop() != ')') { // when meet ), print all element we pass below
						s.push(stack.getTop());
						stack.pop();
					}
					stack.pop();
				}
			}
		}
		while (stack.getTopIndex() != -1) { //print the others remain in stack
			s.push(stack.getTop());
			stack.pop();
		}
		int length_stack = s.getLength();
		char* result = new char[length_stack];
		for (int i = 0; i < length_stack; i++) {
			result[i] = s.getTop()->data;
			s.pop();
		}
		result[length_stack] = NULL;
		return result;
	}
	symbolStr countSymbol(string str, int length) { // browse from left to right
		symbol s;
		s.number = 0;
		StackLL<symbol> st;
		for (int i = 0; i < length; i++) {
			if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '%' && str[i] != '(' && str[i] != ')') {
				if (st.getLength() == 0) { // for the first element
					s.value = str[i];
					s.number = 1;
					st.push(s);
					for (int j = i + 1; j < length; j++) {
						if (str[j] == st.getTop()->data.value) {
							st.getTop()->data.number += 1;
							str[j] = '@'; // convert the same symbols to @ for the next meet this symbol
						}
					}
				}
				else if (str[i] != st.getTop()->data.value && str[i] != '@') {
					s.value = str[i];
					s.number = 1;
					st.push(s);
					for (int j = i + 1; j < length; j++) {
						if (str[j] == st.getTop()->data.value) {
							st.getTop()->data.number += 1;
							str[j] = '@';
						}
					}
				}
				else continue;
			}
		}
		int count = 0;
		symbolStr ss;
		int length_stack = st.getLength(); // dont have enough memory to do this 
		ss.number = length_stack; // set the number of diffirent symbols
		cout << "In your string have " << length_stack << " different symbols" << endl;
		for (int i = length_stack - 1; i >= 0; i--) {
			cout << st.getTop()->data.number << " symbol " << st.getTop()->data.value << endl;
			ss.value[i] = st.getTop()->data.value;
			count += st.getTop()->data.number; // just to print
			st.pop();
		}
		cout << "Total: " << count << " symbols. Return the value of How many diffirent symbols. Not this!!" << endl;
		return ss;
	}

	template<typename type>
	type doNotationPost(char notation, type current, type prev) {
		if (notation == '+') return prev + current;
		if (notation == '-') return prev - current;
		if (notation == '*') return prev * current;
		if (notation == '/') return prev / current;
		if (notation == '%') return prev % current;
	}

	template<typename type>
	type doNotationPre(char notation, type current, type prev) {
		if (notation == '+') return prev + current;
		if (notation == '-') return prev - current;
		if (notation == '*') return prev * current;
		if (notation == '/') return prev / current;
		if (notation == '%') return prev % current;
	}

	template<typename type> // if you want your value of symbol is float, int or double .....
	type calculatePostfix(string post, int length) {
		symbolStr ss;
		type result = 0;
		StackLL<type> stack;
		ss = countSymbol(post, length);
		cout << "Set value of expression notation" << endl << "@NOTE: see careful the symbol value***" << endl;
		type* val = new type[ss.number]; // array value of symbol a, b, c, d.....
		for (int i = 0; i < ss.number; i++) {
			cout << "Value of " << ss.value[i] << ": ";
			cin >> val[i]; // here we implicitly that the symbol in ss.value[i] = val[i]
		}
		for (int i = 0; i < length; i++) {
			if (post[i] != '+' && post[i] != '-' && post[i] != '*' && post[i] != '/' && post[i] != '%') {
				for (int j = 0; j < ss.number; j++) {
					if (post[i] == ss.value[j]) stack.push(val[j]); // push the "value of symbol" into stack,(not the symbol)
				}
			}
			else {
				type prevVal, currentVal; // current value at top stack, and previous value
				currentVal = stack.getTop()->data;
				stack.pop();
				prevVal = stack.getTop()->data;
				stack.pop();
				stack.push(doNotationPost(post[i], currentVal, prevVal));
			}
		}
		return stack.getTop()->data;
	}
	template<typename type> // if you want your value of symbol is float, int or double .....
	type calculatePrefix(string post, int length) {
		symbolStr ss;
		type result = 0;
		StackLL<type> stack;
		ss = countSymbol(post, length);
		cout << "Set value of expression notation" << endl << "@NOTE: see careful the symbol value***" << endl;
		type* val = new type[ss.number]; // array value of symbol a, b, c, d.....
		for (int i = 0; i < ss.number; i++) {
			cout << "Value of " << ss.value[i] << ": ";
			cin >> val[i]; // here we implicitly that the symbol in ss.value[i] = val[i]
		}
		for (int i = length-1; i >=0; i--) {
			if (post[i] != '+' && post[i] != '-' && post[i] != '*' && post[i] != '/' && post[i] != '%') {
				for (int j = 0; j < ss.number; j++) {
					if (post[i] == ss.value[j]) stack.push(val[j]); // push the "value of symbol" into stack,(not the symbol)
				}
			}
			else {
				type prevVal, currentVal; // current value at top stack, and previous value
				currentVal = stack.getTop()->data;
				stack.pop();
				prevVal = stack.getTop()->data;
				stack.pop();
				stack.push(doNotationPre(post[i], currentVal, prevVal));
			}
		}
		return stack.getTop()->data;
	}
};

int main() {
	ExpressionNotation en1;
	string convert_result;
	string input;
	//************test convert Infix to Postfix
	//input = en1.setInputInfix("(a+((a*c-e*d)+f)-b*c)-d"); //tested -- correct
	//input = en1.setInputInfix("(a+(b-(c*d+e)))+f-b*c"); //tested -- corrently
	//input = en1.setInputInfix("a+b*c+d/e-f"); //tested -- corrently
	//input = en1.setInputInfix("a+b+c-d+e-f+a+b"); //tested -- corrently
	//input = en1.setInputInfix("a+b+c-d+e-f*c+a+b"); //tested -- corrently
	//input = en1.setInputInfix("a+b*c-d"); //tested -- corrently
	//input = en1.setInputInfix("a+b*c"); //tested -- corrently
	//convert_result = en1.convertIn_Post(); //---> correctly

	//************test convert Infix to Prefix
	input = en1.setInputInfix("(a+((b*c-e*d)+f)-b*c)-d"); //tested -- correct
	//input = en1.setInputInfix("(a+(b-(c*d+e)))+f-b*c"); //tested -- corrently
	//input = en1.setInputInfix("a+b*c+d/e-f"); //tested -- corrently
	//input = en1.setInputInfix("a+b+c-d+e-f+a+b"); //tested -- corrently
	//input = en1.setInputInfix("a+b+c-d+e-f*c+a+b"); //tested -- corrently
	//input = en1.setInputInfix("a+b*c-d"); //tested -- corrently
	//input = en1.setInputInfix("a*b+c*d-e"); //tested -- corrently
	convert_result = en1.convertIn_Pre(); //---> correctly

	cout << input << endl;
	en1.countSymbol(input, input.length());
	cout << endl << "After convert:" << endl;
	cout << convert_result << endl;
	int length = convert_result.length();
	cout << length << endl;
	//int result = en1.calculatePostfix<int>(convert_result, length);
	int result = en1.calculatePrefix<int>(convert_result, length);
	cout << result;
	return 0;
}