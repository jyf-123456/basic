#include "boss.h"

Boss::Boss(int Id, string Name, int DeptId)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_DeptId = DeptId;
}
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id << '\t';
	cout << "ְ��������" << this->m_Name << '\t';
	cout << "���ű�ţ�" << this->m_DeptId << '\t';
	cout << "��λְ�𣺹���˾����" << endl;
}
string Boss::getDeptName()
{
	return string("�ϰ�");
}