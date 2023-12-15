#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

float hamMu(float x, int n) {
	if (x == 1) return 1;
	if (n == 1) return x;
	return pow(x, n) * hamMu(x, n - 1);
}
int giaiThua(int n) {
	if (n == 1) return 1;
	return n * giaiThua(n - 1);
}
int fibonacci(int t) {
	if (t == 1||t == 2) return 1;
	return fibonacci(t - 1) + fibonacci(t - 2);
}
float nghiemPTB2(float a, float b, float c) {
	float delta;
	if (a == 0) {
		if (b == 0) {
			if (c == 0) printf_s("Phuong trinh vo so nghiem !");
			else printf_s("Error......");
		}
		else printf_s("Phuong trinh co nghiem duy nhat x = %.3f", (-c / b));
	}
	else {
		delta = b * b - 4 * a * c;
		if (delta == 0) printf_s("Phuong trinh co nghiem kep x = %.3f", (-b / 2 * a), (-b / 2 * a));
		else {
			if (delta > 0) {
				printf_s("Phuong trinh co 2 nghiem phan biet");
				printf_s("\nx1 = %.3f", (-b + sqrt(delta)) / (2 * a));
				printf_s("\nx2 = %.3f", (-b - sqrt(delta)) / (2 * a));
			}
			else printf_s("Phuong trinh vo nghiem !");
		}
	}
}
float doiNhietDo(float c) {
	printf_s("%.3f *C = %.3f *K", c, c + 273.15);
	printf_s("\n%.3f *C = %.3f *F", c, (0.8 * c + 32));
}
int main() {
	int i;
	float x;
	int n;//applcation 1
	int N;//application 2
	int t;//application 3
	float a, b, c;//application 4
	float nhietDo;//application 5
		printf_s("*************************************");
		printf_s("\nCac de bai:");
		printf_s("\n1.Tim x^n ");
		printf_s("\n2.Tim N!");
		printf_s("\n3.Tim so Fibonacci thu t");
		printf_s("\n4.Tim nghiem phuong trinh bac 2");
		printf_s("\n5.Quy doi do");
		printf_s("\n0.Dung chuong trinh");
		printf_s("\n*************************************");
		do{
		printf_s("\n*_______________________________*");
		printf_s("\nNhap de bai ban muon lam: ");
		scanf_s("%d", &i);
		switch (i) {
		case 0: 
			printf_s("**__Ban da thoat chuong trinh__**");
			return 0;
		case 1:
			printf_s("* ----- Ham x^n ----- *");
			printf_s("\nNhap x:"); scanf_s("%f", &x);
			printf_s("\nNhap n:"); scanf_s("%d", &n);
			printf_s("\nx^n = %.3f", hamMu(x, n));
			break;
		case 2:
			printf_s("* ----- Ham N! ----- *");
			printf_s("\nNhap N: "); scanf_s("%d", &N);
			printf_s("\nN! = %d", (giaiThua(N)));
			break;
		case 3:
			printf_s("* ----- Ham Fibonacci ----- *");
			printf_s("\nNhap so Fibonacci thu: "); scanf_s("%d", &t);
			printf_s("\nFibonacci thu t co gia tri: %d", fibonacci(t));
			break;
		case 4:
			printf_s("* ----- Phuong trinh bac 2 ----- *");
			printf_s("\nPhuong trinh bac 2 : ax^2 + bx + c = 0");
			printf_s("\nNhap a = "); scanf_s("%f", &a);
			printf_s("\nNhap b = "); scanf_s("%f", &b);
			printf_s("\nNhap c = "); scanf_s("%f", &c);
			nghiemPTB2(a, b, c);
			break;
		case 5:
			printf_s("* ----- Doi nhiet do ----- *");
			printf_s("\nNhap so do C muon quy doi: ");
			scanf_s("%f", &nhietDo);
			doiNhietDo(nhietDo);
			break;
		default:
			printf_s("ERROR...Khong co chuc nang nay // ");
			break;
		}
		} while (i!= 0);
	return 0;
}
