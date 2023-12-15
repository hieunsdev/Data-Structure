#include<iostream>
#include<string.h>

using namespace std;


class Date {
private:
	int ngay, thang, nam;
public:
	//int ngay, thang, nam;
	void getNgay_thang_nam(int, int, int);
	void display();
	friend void soSanh(Date, Date);
};

void Date::getNgay_thang_nam(int a, int b,int c) {
	this->ngay = a;
	this->thang = b;
	this->nam = c;
}

void Date::display() {
	cout << ngay << "." << thang << "." << nam;
}



void soSanh(Date d, Date moc) {
	if (d.nam == moc.nam) {
		if (d.thang == moc.thang) {
			if (d.ngay == d.ngay) {
				d.display();
				cout << " cung moc thoi gian voi ";
				moc.display();
			}
			else {
				if (d.ngay < moc.ngay) {
					d.display();
					cout << " truoc moc thoi gian ";
					moc.display();
				}
				else{
					d.display();
					cout << " sau moc thoi gian ";
					moc.display();
				}
			}
		}
		else {
			if (d.thang < moc.thang) {
				d.display();
				cout << " truoc moc thoi gian ";
				moc.display();
			}
			else {
				d.display();
				cout << " sau moc thoi gian ";
				moc.display();
			}
		}
	}
	else {
		if (d.nam < moc.nam) {
			d.display();
			cout << " truoc moc thoi gian ";
			moc.display();
		}
		else {
			d.display();
			cout << " sau moc thoi gian ";
			moc.display();
		}
	}
}

int main() {
	Date d1;
	Date mocThoiGian;
	int a, b, c;
	cin >> a >> b >> c;
	d1.getNgay_thang_nam(a, b, c);
	mocThoiGian.getNgay_thang_nam(30, 02, 1999);
	soSanh(d1, mocThoiGian);
	cout << endl;
	return 0;
}