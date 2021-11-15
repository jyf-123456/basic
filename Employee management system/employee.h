#pragma once
#include "worker.h"

class Employee : public Worker {
public:
	Employee(int Id,string Name,int DeptId);
	void showInfo();
	string getDeptName();
};