#pragma once //防止头文件重复包含
#include  <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define FILENAME "empFile.txt"

using namespace std;

class WorkerManager   //创建一个抽象的管理类​ 管理类负责的内容如下：1.与用户的沟通菜单界面 2.对职工增删改查的操作 3.与文件的读写交互
{
public:
	WorkerManager();

	void Show_Menu();

	void Add_Emp();

	void save();

	int get_Empnum();

	void init_Emp();

	void Show_Emp();

	void Del_Emp();

	void Mod_Emp();

	void Find_Emp();

	int IsExist(int id);

	void ExitSystem();

	~WorkerManager();

	int m_EmpNum;//当前职工数量
	
	Worker** m_EmpArray;//指向 存储当前职工信息的 Worker*类型数组 首地址 的指针

	bool m_FileIsEmpty;//文件是否为空的标志
};
