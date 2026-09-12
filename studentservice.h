#pragma once
#include<vector>
#include<string>
#include<memory>
#include<map>
#include"studentrepository.h"

class service {
private:
	repository repo;
	map<string,shared_ptr<student>> students;

public:
	service(const string& filename);

	bool addstudent(const student& s);
	shared_ptr<student> findbyid(string& id);
	bool deletestudent(string& id);
	vector<shared_ptr<student>> sortbyscore();
	void updatestudent(string& name, string& id, double score);
	void saveall();
	vector<shared_ptr<student>> getall() const;

};