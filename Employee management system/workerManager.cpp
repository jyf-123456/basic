#include "workerManager.h"

WorkerManager::WorkerManager(){
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = 1;
		ifs.close();
		return;
	}
	
	//若文件存在
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = 1;
		cout << "文件为空" << endl;
		ifs.close();
		return;
	}
	//若文件存在且不为空（有职工信息）
	
	int num = this->get_Empnum();
	cout << "现有职工人数：" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray=new Worker*[num];  //给读出文件的数据分配内存空间
	this->init_Emp();  //初始化数组
}
WorkerManager::~WorkerManager() {

}

void WorkerManager::Show_Menu() {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::Add_Emp()
{
	cout << "请输入增加职工数量： " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];//

		//将原空间下内容存放到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;


			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;


			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1: //普通员工
				worker = new Employee(id, name, 1);
				break;
			case 2: //经理
				worker = new Manager(id, name, 2);
				break;
			case 3:  //老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间,释放数组空间时要加一个[]
		delete[] this->m_EmpArray;

		//更改新空间的指向，指向的是新开辟的动态数组首地址
		this->m_EmpArray = newSpace;

		//更新新的个数
		this->m_EmpNum = newSize;

		//更新文件是否为空标志
		this->m_FileIsEmpty = false;

		//提示信息
		cout << "成功添加" << addNum << "名新职工！" << endl;
	}
	else
	{
		cout << "输入有误" << endl;
	}

	this->save();
	
	system("pause");
	system("cls");
}

void WorkerManager::save()  //将用户的输入做一个保存，我们使用写文件的操作将数据保存在我们创建的文件里
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int WorkerManager::get_Empnum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int deptid;
	int num = 0;

	while(ifs >> id && ifs >> name && ifs >> deptid) {
		num++;
	}
	ifs.close();
	this->m_EmpNum = num;
	return num;
}

void WorkerManager::init_Emp() {
	int id;
	string name;
	int deptid;

	int index = 0;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	while (ifs >> id && ifs >> name && ifs >> deptid) {
		Worker* worker = NULL;
		if (deptid == 1)
			worker = new Employee(id, name, deptid);
		if (deptid == 2)
			worker = new Manager(id, name, deptid);
		if (deptid == 3)
			worker = new Boss(id, name, deptid);
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::Show_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或者为空！" << endl;
		return;
	}
	cout << "所有职工的信息：" << endl;
	for (int i = 0; i < this->m_EmpNum; i++) {
		this->m_EmpArray[i]->showInfo();
	}
	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp() {
	int id;
	cout << "请输入需要删除员工的编号：";
	cin >> id;
	
	/*if (this->IsExist(id) == -1) {
		cout << "您输入的员工编号对应的员工不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = this->IsExist(id); i < this->m_EmpNum-1; i++) {
		this->m_EmpArray[i] = this->m_EmpArray[i + 1];
	}
	this->m_EmpNum--;
	this->save();
	cout << "删除离职员工成功！" << endl;*/

	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按职工编号删除
		cout << "请输入想要删除的职工号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)  //说明index上位置数据需要删除
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save(); //删除后数据同步到文件中
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Mod_Emp() {

}

int WorkerManager::IsExist(int id) {
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			index = i;
			break;
		}
	}
	return index;
}

void  WorkerManager::ExitSystem() {
	cout << "已退出系统，欢迎下次使用" << endl;
	system("pause");
	exit(0);
}