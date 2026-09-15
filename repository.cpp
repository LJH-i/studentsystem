#include"studentrepository.h"
#include<fstream>

void repository::save(const map<string,shared_ptr<student>>& students) {
	ofstream outfile(filename);
	if (!outfile.is_open()) {
		cerr << "文件无法打开" << endl;
		return ;
	}
	else {
		for (const auto& s : students) {
			outfile << s.second->getname() << " " << s.second->getid() << " " << s.second->getscore();
			outfile << endl;
		}
	}
	outfile.close();
}

map<string,shared_ptr<student>>  repository::load() {
	map<string,shared_ptr<student>> result;
	ifstream infile(filename);
	if (!infile.is_open()) {
		cerr << "文件无法读取" << endl;
		return result;
	}
	else {
		string name;
		string id;
		double score;
		while (infile >> name>> id >> score) {
			result[id]=(make_shared<student>(name, id, score));
		}
	}
	infile.close();
	return result;
}
