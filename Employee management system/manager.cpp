#include "manager.h"

Manager::Manager(int Id, string Name, int DeptId)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_DeptId = DeptId;
}
void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id << '\t';
	cout << "ְ��������" << this->m_Name << '\t';
	cout << "���ű�ţ�" << this->m_DeptId << '\t';
	cout << "��λְ�𣺸�Ա����������" << endl;
}
string Manager::getDeptName()
{
	return string("����");
}