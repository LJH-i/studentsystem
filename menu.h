#pragma once
#include"studentservice.h"

class menu {
private:
	service& svc;

public:
	menu(service& s) :svc(s) {};

	void run();
	void showmainmenu();
	void handleadd();
	void handledelete();
	void handleupdate();
	void handlesort();
	void handlefind();
	void handleshowall();

	double getvalidscore();

};