#ifdef _WIN32
#include <windows.h>
#endif
#include"student.h"
#include"studentrepository.h"
#include"studentservice.h"
#include"menu.h"
#include<fstream>

int main() {
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
#endif

	ofstream test("test_encoding.txt");
	test << "测试中文" << endl;
	test.close();

	service svc("student.txt");
	menu m(svc);
	m.run();
	
	system("pause");
	return 0;
}


