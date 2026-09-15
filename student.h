//feature-test上的改动
#pragma once
#include<string>
#include<iostream>
using namespace std;

class student {
private:
	string name;
	string id;
	double score;

public:
	student() : name(""), id(0), score(0.0) {};
	student(string n, string i, double s) :name(n), id(i), score(s) {};

	string getname() const {
		return name;
	}
	string getid() const {
		return id;
	}
	double getscore() const {
		return score;
	}

	void setname( string& n) {
				name = n;
	}

	void setid(string & i) {
				id=i;
	}
	void setscore(double& s) {
		score = s;
	}

	void print() const {
		cout << "姓名:" << name << " " << "学号:" << id << " " << "成绩:" << score << endl;
	}
};

