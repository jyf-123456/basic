#include "boss.h"

Boss::Boss(int Id, string Name, int DeptId)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_DeptId = DeptId;
}
void Boss::showInfo()
{
	cout << "职工编号：" << this->m_Id << '\t';
	cout << "职工姓名：" << this->m_Name << '\t';
	cout << "部门编号：" << this->m_DeptId << '\t';
	cout << "岗位职责：管理公司事务。" << endl;
}
string Boss::getDeptName()
{
	return string("老板");
}