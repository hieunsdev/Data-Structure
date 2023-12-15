#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct point {
	float math;
	float physic;
	float chemistry;
	float english;
};

struct nameOfFwb {
	string* name;
	int number_of_fwb;
};

class iStudent {
public:
	virtual void ranking() {
		cout << "Have'nt match ranking to Student yet !!" << endl;
	}
	virtual void justTest() {
		cout << "Test of virtual metods iStudent" << endl;
	}
};

class Student :public iStudent {
private:
	string name;
	string _class;
	string school;
	int age;
	point p;
	nameOfFwb fwb;
public:
	Student() {
		name = "default";
		_class = "default";
		school = "default";
		age = -1;
		p.math = -1;
		p.chemistry = -1;
		p.english = -1;
		p.physic = -1;
	}
	Student(string name_para, string _class_para, string school_para, int age_para) {
		name = name_para;
		_class = _class_para;
		school = school_para;
		age = age_para;
	}
	void setName() {
		cout << "Name: ";
		getline(cin, name);
	}
	void setClass() {
		cout << "Class: ";
		getline(cin, _class);
	}
	void setSchool() {
		cout << "School: ";
		getline(cin, school);
	}
	void setAge() {
		cout << "Age: ";
		cin >> age;
		cin.ignore();
	}
	void setPoint() {
		cout << "-----Point of Student" << endl;
		cout << "Math: "; cin >> p.math;
		cout << "Physic: "; cin >> p.physic;
		cout << "Chemistry: "; cin >> p.chemistry;
		cout << "English: "; cin >> p.english;
	}
	void setAll() {
		cin.ignore();
		setName();
		setAge();
		setClass();
		setSchool();
		setPoint();
	}
	void setFwb() {
		cout << "Number of fwb that you have: ";
		cin >> fwb.number_of_fwb;
		int number = fwb.number_of_fwb;
		fwb.name = new string[number];
		for (int i = 0; i < number; i++) {
			cout << "Name of fwb " << i + 1 << ": ";
			cin.ignore();
			getline(cin, fwb.name[i]);
		}
	}
	float average() {
		return ((p.math + p.physic + p.chemistry + p.english) / 4);
	}
	void studentCV() {
		cout << left << setw(25) << name << setw(7) << age << setw(15) << _class << setw(15) << school << setprecision(3) // format number 0.00
			<< setw(7) << p.math << setw(7) << p.physic << setw(7) << p.chemistry << setw(7) << p.english << endl;
	}
	void listFwb() {
		cout << "List FWB of " << name << ": " << endl;
		for (int i = 0; i < fwb.number_of_fwb; i++) {
			cout << fwb.name[i] << endl;
		}
	}
	friend void studentListCV(Student* s, int size) {
		cout << endl << "___________List Student Infor__________" << endl;
		cout << left << setw(25) << "--Full Name--" << setw(7) << "Age" << setw(15) << "--Class--" << setw(15) << "--School--"
			<< setw(7) << "M" << setw(7) << "P" << setw(7) << "C" << setw(7) << "E" << setw(7) << "Aver" << endl;
		for (int i = 0; i < size; i++) {
			s[i].studentCV();
		}
	}
	friend void setAllList(Student* s, int size) {
		for (int i = 0; i < size; i++) {
			cout << "________Set infor for student " << i + 1 << "________" << endl;
			s[i].setAll();
			cout << endl;
		}

	}

	// abstract iStudent
	void ranking() {
		if (average() <= 3) cout << "Weak" << endl;
		if (average() > 3 && average() <= 6) cout << "Medium" << endl;
		if (average() > 6 && average() < 8) cout << "Good" << endl;
		if (average() >= 8) cout << "Excellent" << endl;
	}
	//void justTest() {
	//	cout << "Test from Student method" << endl;
	//}
};

class UStudent :public Student {
private:
	string lab;
public:
	UStudent() :Student() {
		lab = "default";
	}
	UStudent(string name_para, string _class_para, string school_para, int age_para, string lab_para)
		:Student(name_para, _class_para, school_para, age_para) {
		lab = lab_para;
	}
	void ranking() {
		cout << "Ranking of uversity" << endl;
		if (average() > 3) cout << "Pass !!" << endl;
		else cout << "Stay !!" << endl;
	}
	void setLab() {
		cout << "Which lab do you join?  ";
		getline(cin, lab);
	}
	void ranking() {
		cout << "From the fucking method of UStudent" << endl;
	}
};

int main() {
	Student s1;
	//Student s2 = Student("Nguyen Thi Mai", "HVBC", "NTQD", 22);
	//s1.setAll();
	//s1.studentCV();
	//s2.studentCV();
	//s2.justTest();
	s1.setFwb();
	s1.studentCV();
	s1.listFwb();

	// array of Student list 
	//int number;
	//cout << "The number of student: ";
	//cin >> number;
	//Student* s = new Student[number];
	//setAllList(s, number);
	//studentListCV(s, number);
	//delete[] s;

	// reference																
	UStudent us1;
	Student* s1 = &us1;
	//s1.ranking(); and us1.ranking(); are both not working, ranking is virtual func from iStudent
	return 0;
}