#pragma once
#include <iostream>
#include <string>
using namespace std;

//����ְ���������Worker

class Worker {
public:
	int m_Id;//ְ�����
	string m_Name;//ְ������
	int m_DeptId;//ְ�����ڲ��ű��
	
	virtual void showInfo() = 0;//��ʾ��ְ����Ϣ
	virtual string getDeptName() = 0;//��ʾ��ְ����λ����
};
