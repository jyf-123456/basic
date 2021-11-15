#include "worker.h"
#include "employee.h"

Employee::Employee(int Id, string Name, int DeptId)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_DeptId = DeptId;
}
void Employee::showInfo()
{
	cout << "职工编号：" << this->m_Id << '\t';
	cout << "职工姓名：" << this->m_Name << '\t';
	cout << "部门编号：" << this->m_DeptId << '\t';
	cout << "岗位职责：完成经理交给的任务。" << endl;
}
string Employee::getDeptName()
{
	return string("员工");
}