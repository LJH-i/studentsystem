#pragma once
#include"student.h"
#include<vector>
#include<memory>
#include<map>

class repository {
private:
	string filename;

public:
	repository(const string& fn) :filename(fn) {};

	void save(const map<string,shared_ptr<student>>& students);

	map<string,shared_ptr<student>> load();
};