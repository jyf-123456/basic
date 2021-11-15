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
	//system("pause");// Worker基类的多态特性的测试代码

	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		//展示菜单
		wm.Show_Menu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:       //退出系统
			wm.ExitSystem();
			break;
		case 1:      //添加职工
			wm.Add_Emp();
			break;
		case 2:      //显示职工
			wm.Show_Emp();
			break;
		case 3:     //删除职工
			wm.Del_Emp();
			break;
		case 4:  //修改职工
			wm.Mod_Emp();
			break;
		case 5:     //查找职工
			break;
		case 6:     //排序职工
			break;
		case 7:     //清空文件
			break;
		default:
			system("cls");//刷新一下屏幕
			cout << "选择的功能不存在！请重新选择：" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}