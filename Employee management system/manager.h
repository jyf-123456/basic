#pragma once
#include "worker.h"


class Manager :public Worker
{
public:
	Manager(int Id, string Name, int DeptId);
	void showInfo();
	string getDeptName();
};