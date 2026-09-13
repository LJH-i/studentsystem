//这是在feature-test分支上的改动
//master分支上的改动
//这是从另一台电脑上进行的修改
#include<string>
#include"menu.h"
#include"studentservice.h"
#include"student.h"
#include"studentrepository.h"

void menu::showmainmenu() {
	cout << "1.添加学生" << endl << "2.查找学生" << endl << "3.删除学生" << endl << "4.按成绩排序" << endl << "5.显示全部学生" << endl << "6.修改学生信息" << endl << "7.保存并退出" <<endl;
	cout << "请输入操作对应的数字" << endl;
}

void menu::run() {
	int choice;
	while (true) {
		showmainmenu();
		cin >> choice;
		cin.ignore(10000, '\n');

		switch (choice) {
		case 1:handleadd(); break;
		case 2:handlefind(); break;
		case 3:handledelete(); break;
		case 4:handlesort(); break;
		case 5:handleshowall(); break;
		case 6:handleupdate(); break;
		case 7:svc.saveall(); return;
		default:cout << "请重新输入" << endl;
		}
	}
}

void menu::handleadd() {
	string name;
	string id;
	double score;
	cout << "请输入姓名" << endl;
	getline(cin, name);
	cout << "请输入学号" << endl;
	getline(cin, id);
	score = getvalidscore();
	if (svc.addstudent(student(name, id, score))) {
		cout << "添加成功" << endl;
	}
	else {
		cout << "添加失败" << endl;
	}
}

void menu::handlefind() {
	string id;
	cout << "请输入学号" << endl;
	getline(cin, id);

	shared_ptr<student> result = svc.findbyid(id);

	if (result == nullptr) {
		cout << "未找到" << endl;
	}
	else {
		cout << "找到了" << endl;
		result->print();
	}
}

void menu::handledelete() {
	string id;
	cout << "请输入学号" << endl;
	getline(cin, id);

	if (svc.deletestudent(id)) {
		cout << "已删除" << endl;
	}
	else {
		cout << "删除失败" << endl;
	}
}

void menu::handlesort() {
	auto all = svc.sortbyscore();
	cout << "排序后的结果:" << endl;
	for(const auto&a:all){
		a->print();
		cout << endl;
	}
}

void menu::handleupdate() {
	string id;
	string name;
	double score;
	while (true) {
		cout << "请输入要对其进行更改的学号" << endl;
		getline(cin, id);
		auto find = svc.findbyid(id);
		if (find) {
			cout << "请输入新的姓名" << endl;
			getline(cin, name);
			score = getvalidscore();
			svc.updatestudent(name, id, score);
			break;
		}
		else {
			cout << "未找到该学号，请重新输入" << endl;
		}
	}
	auto updated = svc.findbyid(id);
	if (updated) {
		cout << "修改后的信息如下：" << endl;
		updated->print();
	}
}

void menu::handleshowall() {
	auto all = svc.getall();
	for (const auto& s : all) {
		s->print();
		cout << endl;
	}
}

double menu::getvalidscore() {
	double score;
		while (true) {
			cout << "请输入成绩" << endl;
			if (cin >> score && score >= 0 && score <= 100) {
				cin.ignore(10000, '\n');
				return score;
			}
			else {
				cout << "输入无效，请重新输入" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}

		}

}