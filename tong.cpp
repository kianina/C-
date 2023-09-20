//工作日志
// 1.封装一个函数来显示菜单
// 2.退出功能
// 3.添加联系人
// 4.删除联系人
// 5.显示联系人 
// 6.查找联系人
// 7.修改联系人
// 8.清空联系人
//



#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
/*菜单界面函数*/
void showMenu() {
	cout << "************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl;
}


struct person {
	string name;
	int age;
	int sex;
	string sellphone;
	string address;
};

struct tongxun {
	struct person lainxiarray[MAX];/*存放人员的数组*/
	int size;/*人员个数*/
};

/*添加联系人*/
void addperson(tongxun* abs) {
	if (abs->size == MAX) {
		cout << "通讯录已满" << endl;
		return;
	}
	else {
		string m_name;
		cout << "请输入姓名" << endl;
		cin >> m_name;
		abs->lainxiarray[abs->size].name = m_name;
		int m_age;
		cout << "请输入年龄" << endl;
		cin >> m_age;
		abs->lainxiarray[abs->size].age = m_age;
		int m_sex;
		cout << "请输入性别" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		while (true) {
			cin >> m_sex;
			if (m_sex == 1 || m_sex == 2) {
				abs->lainxiarray[abs->size].sex = m_sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		string m_sellphone;
		cout << "请输入电话" << endl;
		cin >> m_sellphone;
		abs->lainxiarray[abs->size].sellphone = m_sellphone;
		string m_address;
		cout << "请输入地址" << endl;
		cin >> m_address;
		abs->lainxiarray[abs->size].address = m_address;
		abs->size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");//清屏操作
	}
}

/*显示所有联系人的函数*/
void xiansiPerson(tongxun * arr) {
	int i = 0;
	if (arr->size == 0) {
		cout << "当前通讯录为空" << endl;
	}
	else {
		for (int i = 0; i < arr->size; i++) {
			cout << arr->lainxiarray[i].name << endl;
			cout << arr->lainxiarray[i].age << endl;
			cout << arr->lainxiarray[i].sex << endl;
			cout << arr->lainxiarray[i].sellphone << endl;
			cout << arr->lainxiarray[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}

/*检测联系人是否存在函数*/
int isEisit(tongxun* arr, string m_name) {
	for (int i = 0; i < arr->size; i++) {
		if (arr->lainxiarray[i].name == m_name) {
			return i;
		}			
	}
	return -1;
}

/*删除联系人函数*/
void deletePerson(tongxun* arr, string m_name) {
	int l;
	l = isEisit(arr, m_name);
	if (l != -1) {
		for (l; l < arr->size; l++) {
			arr->lainxiarray[l] = arr->lainxiarray[l + 1];
		}
		arr->size--;
		cout << "删除成功" << endl;
	}
	else
		cout << "查无此人" << endl;
	system("pause");
	system("cls");
}
/*查找联系人函数*/
void lianxiReserch(tongxun* arr) {
	cout << "请输入联系人的姓名" << endl;
	string name;
	cin >> name;
	int l = isEisit(arr, name);
	if (l == -1) {
		cout << "查无此人" << endl;
	}
	else {
		cout << arr->lainxiarray[l].name << endl;
		cout << arr->lainxiarray[l].age << endl;
		cout << arr->lainxiarray[l].sex << endl;
		cout << arr->lainxiarray[l].sellphone << endl;
		cout << arr->lainxiarray[l].address << endl;	
	}
	system("pause");
	system("cls");
}

/*修改联系人函数*/
void lianxiChange(tongxun* arr) {
	cout << "请输入要修改联系人的姓名" << endl;
	string name;
	cin >> name;
	int l = isEisit(arr, name);
	if (l == -1) {
		cout << "没有该联系人" << endl;
	}
	else {
		cout << "请输入要修改的姓名" << endl;
		string m_name;
		cin >> m_name;
		arr->lainxiarray[l].name = m_name;
		cout << "请输入要修改的年龄" << endl;
	    int m_age;
		cin >> m_age;
		arr->lainxiarray[l].age = m_age;
		cout << "请输入要修改的性别" << endl;
		int m_sex;
		cin >> m_sex;
		arr->lainxiarray[l].sex = m_sex;
		cout << "请输入要修改的电话" << endl;
		string m_sellphone;
		cin >> m_sellphone;
		arr->lainxiarray[l].sellphone = m_sellphone;
		cout << "请输入要修改的地址" << endl;
		string m_address;
		cin >> m_address;
		arr->lainxiarray[l].address = m_address;
		cout << "已成功修改联系人" << endl;
	}
	system("pause");
	system("cls");
}

/*清空联系人*/
void clearPerson(tongxun* arr) {
	arr->size == 0;
	cout << "已清空通讯录" << endl;
	system("pause");
	system("cls");
}

int main() {
	tongxun add;
	add.size = 0;	
	int seclet = 0;//用户选择菜单的变量	
	while (true) {
		/*菜单显示*/
		string t_name;
		showMenu();
		cin >> seclet;
		switch (seclet)
		{
		case 1:
			addperson(&add);
			break;
		case 2:
			xiansiPerson(&add);
			break;
		case 3:
			cout << "请输入删除联系人的姓名" << endl;			
			cin >> t_name;
			deletePerson(&add, t_name);
			/*if (isEisit(&add, t_name) != -1) {

			} 
			else {
				cout << "查找联系人不存在" << endl;
			}*/
			
			break;
		case 4:
			lianxiReserch(&add);
			break;
		case 5:
			lianxiChange(&add);
			break;
		case 6:
			clearPerson(&add);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
