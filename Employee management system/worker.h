#pragma once
#include <iostream>
#include <string>
using namespace std;

//创建职工抽象基类Worker

class Worker {
public:
	int m_Id;//职工编号
	string m_Name;//职工姓名
	int m_DeptId;//职工所在部门编号
	
	virtual void showInfo() = 0;//显示该职工信息
	virtual string getDeptName() = 0;//显示该职工岗位名称
};
