#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//ofstream
//ifstream
//fstream
/*写文件*/
void test()
{
	ofstream ofs; 
	ofs.open("test.txt", ios::out);
	ofs << "this gril" << endl;
	ofs << "150" << endl;
	ofs.close();
}
/*读文件*/
void test1()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "file open fail" << endl;
		return;
	}
	/*char buff[1000] = { 0 };
	while (ifs >> buff)
	{
		cout << buff << endl;
	}*/

	/*char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}*/

	string buff;
	while (getline(ifs,buff))
	{
		cout << buff << endl;
	}
}
int main()
{
	test1();
	return 0;
}