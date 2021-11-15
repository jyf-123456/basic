#include "manager.h"

Manager::Manager(int Id, string Name, int DeptId)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_DeptId = DeptId;
}
void Manager::showInfo()
{
	cout << "职工编号：" << this->m_Id << '\t';
	cout << "职工姓名：" << this->m_Name << '\t';
	cout << "部门编号：" << this->m_DeptId << '\t';
	cout << "岗位职责：给员工分配任务。" << endl;
}
string Manager::getDeptName()
{
	return string("经理");
}