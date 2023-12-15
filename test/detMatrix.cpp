/*	
	Bui Tuan Anh
	Hanoi University of Science and Technology
	Calculate detaminant of matrix
	Vietnamese
*/
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

class Matrix {
private:
	short int n;
	float* m;
public:
	Matrix();
	Matrix(short int);
	void inputMatrix();
	void printMatrix();
	void subMatrix(short int, short int, Matrix);
	float detMatrix();
	void inverseMatrix();
};

Matrix::Matrix() {
	this->n = 0;
	this->m = 0;
}

Matrix::Matrix(short int N) {
	this->n = N;
	this->m = new float[n * n];
}

void Matrix::inputMatrix() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Phan tu thu [" << i + 1 << ", " << j + 1 << "] = ";
			cin >> m[i * n + j];
		}
	}
	cout << endl;
}

void Matrix::printMatrix() {
	for (int i = 0;i < n; i++) {
		cout << "[  ";
		for (int j = 0; j < n; j++) {
			cout << left << setw(9) << fixed << setprecision(4) << m[i * n + j];
		}
		cout << left << setw(2) << "]" << endl;
	}
}

void Matrix::subMatrix(short int x, short int y, Matrix a) {
	short int count = 0;
	for (int i = 0; i < n; i++) {
		if (i != y) {
			for (int j = 0; j < n; j++) {
				if (j != x) {
					a.m[count] = m[i * n + j];
					count++;
				}
			}
		}
	}
}

float cofactor(short int x, short int y, float num) {
	return pow(-1, x + y) * num;
}

float Matrix::detMatrix() {
	float fdet = 0;
	if (n == 1) {
		fdet = m[0];
	}
	else if (n == 2) {
		fdet = m[0] * m[3] - m[1] * m[2];
	}
	else if (n > 2) {
		fdet = 0;
		for (short int j = 0; j < n; j++) {
			Matrix a(n - 1);
			subMatrix(j, 0, a);
			fdet += cofactor(j, 0, m[j] * a.detMatrix());
			delete(a.m);
		}
	}
	return fdet;
}

void Matrix::inverseMatrix() {
	Matrix inverse(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Matrix a(n - 1);
			subMatrix(i, j, a);
			inverse.m[i * n + j] = cofactor(i, j, a.detMatrix()) / detMatrix();
			delete(a.m);
		}
	}
	inverse.printMatrix();
}

int main() {
	short int choice;
	short int N;
	cout << "--------------- < Ma tran > ---------------" << endl;
	do {
		cout << "\n1. Tinh det ma tran vuong cap N" << endl << "2. Tinh ma tran nghich dao cua ma tran vuong cap N" << endl << "0. Thoat" << endl;
		cout << "======>> Nhap lua chon: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		default:
			cout << "**Error**: Khong co lua chon nay" << endl << "<> Nhap lai <>" << endl;
			break;
		case 1:
		{
			cout << "Cap cua ma tran vuong (N x N) = ";
			cin >> N;
			Matrix m(N);

			m.inputMatrix();
			m.printMatrix();
			cout << endl;
			cout << ">>>>>>>>>>>>>> Det matrix = " << m.detMatrix() << endl;
			break;
		}
		case 2:
		{
			cout << "Cap cua ma tran vuong (N x N) = ";
			cin >> N;
			Matrix m(N);

			m.inputMatrix();
			m.printMatrix();
			cout << "=> Ma tran nghich dao la: " << endl;
			m.inverseMatrix();
			break;
		}
		}
	} while (choice != 0);
	return 0;
}