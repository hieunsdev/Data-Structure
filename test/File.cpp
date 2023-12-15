/*
	Just some note about manipulate with file txt
	Vietnamese. Just assignment in class
*/
//#include<iostream>
//#include<fstream>
//#include<string>
//
//using namespace std;
//
//int main() {
//	//Dang co ban: 
//
//	//ios::out    mở file(ghi đè nếu file đã tồn tại)
//	//ios::in     truy cập vào file để đọc
//	//ios::app    ghi tiếp vào cuối nếu chạy lần 2 hoặc file đó đã tồn tại
//	//ios::trunc  nếu file đã tồn tại, nội dung trc đó sẽ bị cắt
//
//		//Ghi file 
//	fstream f;
//	f.open("test.txt", ios::out);
//
//	string dataIn = "Name: Bui Tuan Anh\n" // co the thay string bang kieu du lieu khac 
//		"\nAge: twenty one."
//		"\nJob: Student.";
//
//	f << dataIn;
//	f.close();
//
//	//Doc file
//	f.open("test.txt", ios::in);
//
//	string dataOut;
//	string line;
//	while (!f.eof())
//	{
//		getline(f, line);
//		dataOut += line;
//	}
//
//	f.close();
//	cout << dataOut;
//	return 0;
//}

#include<iostream>

using namespace std;

struct sHCN {
	float dai, rong;
};

float dienTich(sHCN s) {
	return s.dai * s.rong;
}

class cHCN {
private:
	float dai, rong;
public:
	cHCN();
	cHCN(float, float);
	~cHCN();
	void setDai(float);
	void setRong(float);
	float dienTich();
};

cHCN::cHCN() {
	this->dai = 0;
	this->rong = 0;
}

cHCN::cHCN(float x, float y) {
	this->dai = x;
	this->rong = y;
}

void cHCN::setDai(float x) {
	this->dai = x;
}


void cHCN::setRong(float y) {
	this->rong = y;
}

float cHCN::dienTich() {
	return dai * rong;
}

int main() {
	sHCN a[18];
	for (int i = 0; i < 18; i++) {
		cout << "Nhap chieu dai HCN " << i + 1 << " : ";
		cin >> a[i].dai;
		cout << "Nhap chieu rong HCN " << i + 1 << " : ";
		cin >> a[i].rong;
	}
	float Tarea = 0;
	for (int i = 0; i < 18; i++) {
		Tarea += dienTich(a[i]);
	}
	cout << "Tong dien tich 18 HCN: " << Tarea;
	return 0;
}