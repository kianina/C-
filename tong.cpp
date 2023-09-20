//������־
// 1.��װһ����������ʾ�˵�
// 2.�˳�����
// 3.�����ϵ��
// 4.ɾ����ϵ��
// 5.��ʾ��ϵ�� 
// 6.������ϵ��
// 7.�޸���ϵ��
// 8.�����ϵ��
//



#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
/*�˵����溯��*/
void showMenu() {
	cout << "************************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
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
	struct person lainxiarray[MAX];/*�����Ա������*/
	int size;/*��Ա����*/
};

/*�����ϵ��*/
void addperson(tongxun* abs) {
	if (abs->size == MAX) {
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else {
		string m_name;
		cout << "����������" << endl;
		cin >> m_name;
		abs->lainxiarray[abs->size].name = m_name;
		int m_age;
		cout << "����������" << endl;
		cin >> m_age;
		abs->lainxiarray[abs->size].age = m_age;
		int m_sex;
		cout << "�������Ա�" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
		while (true) {
			cin >> m_sex;
			if (m_sex == 1 || m_sex == 2) {
				abs->lainxiarray[abs->size].sex = m_sex;
				break;
			}
			cout << "������������������" << endl;
		}
		string m_sellphone;
		cout << "������绰" << endl;
		cin >> m_sellphone;
		abs->lainxiarray[abs->size].sellphone = m_sellphone;
		string m_address;
		cout << "�������ַ" << endl;
		cin >> m_address;
		abs->lainxiarray[abs->size].address = m_address;
		abs->size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");//��������
	}
}

/*��ʾ������ϵ�˵ĺ���*/
void xiansiPerson(tongxun * arr) {
	int i = 0;
	if (arr->size == 0) {
		cout << "��ǰͨѶ¼Ϊ��" << endl;
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

/*�����ϵ���Ƿ���ں���*/
int isEisit(tongxun* arr, string m_name) {
	for (int i = 0; i < arr->size; i++) {
		if (arr->lainxiarray[i].name == m_name) {
			return i;
		}			
	}
	return -1;
}

/*ɾ����ϵ�˺���*/
void deletePerson(tongxun* arr, string m_name) {
	int l;
	l = isEisit(arr, m_name);
	if (l != -1) {
		for (l; l < arr->size; l++) {
			arr->lainxiarray[l] = arr->lainxiarray[l + 1];
		}
		arr->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
		cout << "���޴���" << endl;
	system("pause");
	system("cls");
}
/*������ϵ�˺���*/
void lianxiReserch(tongxun* arr) {
	cout << "��������ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int l = isEisit(arr, name);
	if (l == -1) {
		cout << "���޴���" << endl;
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

/*�޸���ϵ�˺���*/
void lianxiChange(tongxun* arr) {
	cout << "������Ҫ�޸���ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int l = isEisit(arr, name);
	if (l == -1) {
		cout << "û�и���ϵ��" << endl;
	}
	else {
		cout << "������Ҫ�޸ĵ�����" << endl;
		string m_name;
		cin >> m_name;
		arr->lainxiarray[l].name = m_name;
		cout << "������Ҫ�޸ĵ�����" << endl;
	    int m_age;
		cin >> m_age;
		arr->lainxiarray[l].age = m_age;
		cout << "������Ҫ�޸ĵ��Ա�" << endl;
		int m_sex;
		cin >> m_sex;
		arr->lainxiarray[l].sex = m_sex;
		cout << "������Ҫ�޸ĵĵ绰" << endl;
		string m_sellphone;
		cin >> m_sellphone;
		arr->lainxiarray[l].sellphone = m_sellphone;
		cout << "������Ҫ�޸ĵĵ�ַ" << endl;
		string m_address;
		cin >> m_address;
		arr->lainxiarray[l].address = m_address;
		cout << "�ѳɹ��޸���ϵ��" << endl;
	}
	system("pause");
	system("cls");
}

/*�����ϵ��*/
void clearPerson(tongxun* arr) {
	arr->size == 0;
	cout << "�����ͨѶ¼" << endl;
	system("pause");
	system("cls");
}

int main() {
	tongxun add;
	add.size = 0;	
	int seclet = 0;//�û�ѡ��˵��ı���	
	while (true) {
		/*�˵���ʾ*/
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
			cout << "������ɾ����ϵ�˵�����" << endl;			
			cin >> t_name;
			deletePerson(&add, t_name);
			/*if (isEisit(&add, t_name) != -1) {

			} 
			else {
				cout << "������ϵ�˲�����" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
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
