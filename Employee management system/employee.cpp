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
	cout << "ְ����ţ�" << this->m_Id << '\t';
	cout << "ְ��������" << this->m_Name << '\t';
	cout << "���ű�ţ�" << this->m_DeptId << '\t';
	cout << "��λְ����ɾ�����������" << endl;
}
string Employee::getDeptName()
{
	return string("Ա��");
}