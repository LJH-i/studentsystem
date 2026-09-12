#include"student.h"
#include"studentrepository.h"
#include"studentservice.h"
#include"menu.h"

int main() {
	service svc("student.txt");
	menu m(svc);
	m.run();
	
	system("pause");
	return 0;
}

//该项目由git管理