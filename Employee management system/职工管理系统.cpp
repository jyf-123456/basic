#include <iostream>
#include "workerManager.h"

using namespace std;

//void test()
//{
//	Worker* worker = new Employee(68, "gdd", 5013);
//	worker->showInfo();
//	delete worker;
//	
//	worker = new Manager(69, "wdd", 2134);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(70, "jgg", 3273);
//	worker->showInfo();
//	delete worker;
//}
int main()
{
	//test();
	//system("pause");// Worker����Ķ�̬���ԵĲ��Դ���

	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		//չʾ�˵�
		wm.Show_Menu();
		cout << "����������ѡ��:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:       //�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1:      //���ְ��
			wm.Add_Emp();
			break;
		case 2:      //��ʾְ��
			wm.Show_Emp();
			break;
		case 3:     //ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4:  //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5:     //����ְ��
			break;
		case 6:     //����ְ��
			break;
		case 7:     //����ļ�
			break;
		default:
			system("cls");//ˢ��һ����Ļ
			cout << "ѡ��Ĺ��ܲ����ڣ�������ѡ��" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}