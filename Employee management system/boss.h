#pragma once
#include "worker.h"

class Boss :public Worker {
public:
	Boss(int Id, string Name, int DeptId);
	void showInfo();
	string getDeptName();
};