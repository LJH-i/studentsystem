#include"studentservice.h"
#include<vector>
#include<string>
#include<memory>
#include<algorithm>

bool service::addstudent(const student& s) {
		if (students.find(s.getid()) != students.end()) {
			return false;
		}
		students[s.getid()]=make_shared<student>(s);
		return true;	
}

shared_ptr<student> service::findbyid(string& id) {
	auto it = students.find(id);
		if (it !=students.end()) {
			return it->second;
		}
	return nullptr;
}

bool service::deletestudent(string& id) {
	return students.erase(id) > 0;
}

vector<shared_ptr<student>> service::sortbyscore() {
	vector<shared_ptr<student>> result;
	for (const auto& pair : students) {
		result.push_back(pair.second);
	}
	sort(result.begin(), result.end(), [](const auto& a, const auto& b) {
		return a->getscore() > b->getscore();
	});
	return result;
}

void service::updatestudent(string& name, string& id, double score) {
	auto s = students.find(id);
	if (s != students.end()) {
		s->second->setname(name);
		s->second->setscore(score);
	}
}

void service::saveall() {
	repo.save(students);
}

vector<shared_ptr<student>> service::getall() const {
	vector<shared_ptr<student>> result;
	for (const auto& a : students) {
		result.push_back(a.second);
	}
	return result;
}

service::service(const string& filename)
	: repo(filename), students(repo.load()) {
}
