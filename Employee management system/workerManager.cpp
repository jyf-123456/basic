#include "workerManager.h"

WorkerManager::WorkerManager(){
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = 1;
		ifs.close();
		return;
	}
	
	//���ļ�����
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = 1;
		cout << "�ļ�Ϊ��" << endl;
		ifs.close();
		return;
	}
	//���ļ������Ҳ�Ϊ�գ���ְ����Ϣ��
	
	int num = this->get_Empnum();
	cout << "����ְ��������" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray=new Worker*[num];  //�������ļ������ݷ����ڴ�ռ�
	this->init_Emp();  //��ʼ������
}
WorkerManager::~WorkerManager() {

}

void WorkerManager::Show_Menu() {
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::Add_Emp()
{
	cout << "����������ְ�������� " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//�����¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];//

		//��ԭ�ռ������ݴ�ŵ��¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;


			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;


			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1: //��ͨԱ��
				worker = new Employee(id, name, 1);
				break;
			case 2: //����
				worker = new Manager(id, name, 2);
				break;
			case 3:  //�ϰ�
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�,�ͷ�����ռ�ʱҪ��һ��[]
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��ָ������¿��ٵĶ�̬�����׵�ַ
		this->m_EmpArray = newSpace;

		//�����µĸ���
		this->m_EmpNum = newSize;

		//�����ļ��Ƿ�Ϊ�ձ�־
		this->m_FileIsEmpty = false;

		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
	}
	else
	{
		cout << "��������" << endl;
	}

	this->save();
	
	system("pause");
	system("cls");
}

void WorkerManager::save()  //���û���������һ�����棬����ʹ��д�ļ��Ĳ��������ݱ��������Ǵ������ļ���
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
		cout << "�ļ������ڻ���Ϊ�գ�" << endl;
		return;
	}
	cout << "����ְ������Ϣ��" << endl;
	for (int i = 0; i < this->m_EmpNum; i++) {
		this->m_EmpArray[i]->showInfo();
	}
	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp() {
	int id;
	cout << "��������Ҫɾ��Ա���ı�ţ�";
	cin >> id;
	
	/*if (this->IsExist(id) == -1) {
		cout << "�������Ա����Ŷ�Ӧ��Ա�������ڣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = this->IsExist(id); i < this->m_EmpNum-1; i++) {
		this->m_EmpArray[i] = this->m_EmpArray[i + 1];
	}
	this->m_EmpNum--;
	this->save();
	cout << "ɾ����ְԱ���ɹ���" << endl;*/

	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//��ְ�����ɾ��
		cout << "��������Ҫɾ����ְ���ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)  //˵��index��λ��������Ҫɾ��
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save(); //ɾ��������ͬ�����ļ���
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
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
	cout << "���˳�ϵͳ����ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}