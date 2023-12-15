#include<iostream>
#include<stdlib.h>
#include<stdint.h>
#include"linkedList.h"

using namespace std;

char myHEX[] = "0123456789ABCDEF";
char myOCT[] = "01234567";

void DECtoBIN(int dec) {
	if (dec == 0) return;
	DECtoBIN(dec / 2);
	cout << dec % 2;
}

void DECtoHEX(int dec) {
	if (dec == 0) return;
	DECtoHEX(dec / 16);
	cout << myHEX[dec % 16];
}

void DECtoOCT(int dec) {
	if (dec == 0) return;
	DECtoHEX(dec / 8);
	cout << myOCT[dec % 7];
}

int BINtoDEC(char* bin) {
	int lengthBIN = 0;
	while (*bin == '1' || *bin == '0') {
		lengthBIN++;
		bin += 1;
	}
	int result = 0;
	bin--;
	for (int i = 0; i < lengthBIN; i++) {
		if (*bin == '1') result += pow(2, i);
		bin--;
	}
	return result;
}

void BINtoHEX(char* bin) {
	int lengthBIN = 0;
	SinglyLinkedList<char> result;
	while (*bin != '\0') {
		lengthBIN++;
		bin += 1;
	}
	char temp[5]; // '\0' in tail too
	bin--; // now pointer bin will be in tail of binary string or LSB (least significant bit (bit 0))
	while (*bin == '1' || *bin == '0') {
		for (int i = 0; i < 4; i++) {
			if (*(bin - 3 + i) == '1') temp[i] = '1';
			else temp[i] = '0';
		}
		bin -= 4;
		result.insertHead(myHEX[BINtoDEC(temp)]);
	}
	result.print();
}

void BINtoOCT(char* bin) {
	int lengthBIN = 0;
	SinglyLinkedList<char> result;
	while (*bin != '\0') {
		lengthBIN++;
		bin += 1;
	}
	char temp[4]; // '\0' in tail too
	bin--; // now pointer bin will be in tail of binary string or LSB (least significant bit (bit 0))
	while (*bin == '1' || *bin == '0') {
		for (int i = 0; i < 3; i++) {
			if (*(bin - 2 + i) == '1') temp[i] = '1';
			else temp[i] = '0';
		}
		bin -= 3;
		result.insertHead(myOCT[BINtoDEC(temp)]);
	}
	result.print();
}

void printString(char* str) {
	while (*str != '\0') {
		cout << *str;
		str++;
	}
}

int main() {
	DECtoBIN(100);
	cout << endl;
	DECtoHEX(100);
	char bin[] = "100011001101000";
	//char temp[5] = "1000";
	cout << endl << BINtoDEC(bin) << endl;
	BINtoHEX(bin);
	cout << endl;
	BINtoOCT(bin);
	//printString(hexResult);
	return 0;
}