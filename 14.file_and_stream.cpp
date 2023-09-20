#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;



/*
1-�ļ����������
2-�ļ��Ķ�д
3-�ж��ļ��Ƿ񱻴�
4-���ļ���׷������
5-����Ԫ
6-����Ϊ������ʵ��
7-eof��Ա�����ж��Ƿ�Ϊ���һ���ַ�
*/


struct PersonInfo{
    string name;
    vector<string> phones;
};


// 1.�ļ�����������
void file_io()
{
    char data[100];
    
    // ��дģʽ���ļ�
    ofstream outfile;
    outfile.open("afile.dat");

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    // ���ļ�д���û����������
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    // �ٴ����ļ�д���û����������
    outfile << data << endl;
    // �رմ򿪵��ļ�
    outfile.close();

    // �Զ�ģʽ���ļ�
    ifstream infile;
    infile.open("afile.dat", ios::in);
    
    cout << "Reading from the file" << endl;
    infile >> data;
    // ����Ļ��д������
    cout << data << endl;
    // �ٴδ��ļ���ȡ���ݣ�����ʾ��
    infile >> data;
    cout << data << endl;
    // �رմ򿪵��ļ�
    infile.close();
}

// 2.��д�ļ�
void file_ios()
{
    ifstream inStream;
    ofstream outStream;
    inStream.open("afile.dat");
    outStream.open("outfile.dat");

    char first, second, thrid;
    // ���ļ��е�������char���Ͷ���
    inStream>>first>>second>>thrid; 
    cout<<first<<" "<<second<<" "<<thrid<<endl; 

    // �����ķ�ʽд�ļ�
    outStream<<"the sum of the first 3\n"
             <<"numbers in infile.dat\n"
             <<"is"<<(first+second+thrid)<<endl;

    inStream.close();
    outStream.close();
}

// 3.�鿴IO��open�Ƿ�ɹ�������
void io_func1()
{
    ifstream inStream;
    ofstream outStream;

    // �ж��ļ��Ƿ񱻴�
    inStream.open("infile.dat");
    if(inStream.fail()) //�ɹ����ļ���fail�����᷵��flase
    {
        cout<<"open infile.dat is fail"<<endl;
        exit(1);        //ֱ���˳�����
    }
    outStream.open("outfile.dat");
    if(outStream.fail())
    {
        cout<<"open outfile.dat is fail"<<endl;
        exit(1);
    }

    char first,second,thrid;
    inStream>>first>>second>>thrid; //���ļ��е�������char���Ͷ���
    cout<<first<<" "<<second<<" "<<thrid<<endl; //�����ļ��ж��������������������
    outStream<<"the sum of the first 3\n"
             <<"numbers in infile.dat\n"
             <<"is"<<(first+second+thrid)<<endl;
    inStream.close();
    outStream.close();
}

// 4.���Ѿ����ڵ��ļ���׷������
void io_func2()
{
    ofstream outStream;
    outStream.open("outfile.dat",ios::app);  //app׷������
    if(outStream.fail())
    {
        cout<<"open outfile is fail"<<endl;
        exit(1);
    }
    outStream<<"this is a pig\n"
             <<"this is a dog\n"
             <<"05961095616"<<endl;
    outStream.close();
}

// 5.����Ԫ
void io_func3()
{
    // stew���пո�
    cout<<"hello"<<setw(4)<<10<<setw(6)<<20<<setw(8)<<30;
}

// 6.����Ϊ������ʵ��
void makeNeat(ifstream& messyFile, ofstream& neatFile, int number, int fieldWidth)
{
    neatFile.setf(ios::fixed);
    neatFile.setf(ios::showpoint); //��ʾС����
    neatFile.setf(ios::showpos); //��ʾ+
    neatFile.precision(number);//��ʽ�����
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout.precision(number);
    double next;
    while(messyFile>>next)
    {
        cout<<setw(fieldWidth)<<next<<endl;
        neatFile<<setw(fieldWidth)<<next<<endl;
    }
}
void io_func4()
{
    ifstream fin;
    ofstream fout;
    fin.open("rawdata.dat");
    if(fin.fail())
    {
        cout<<"open rawdata.dat is fail\n";
        exit(1);
    }
    fout.open("neat.dat");
    if(fout.fail())
    {
        cout<<"open neat.dat is fail\n";
        exit(1);
    }
    makeNeat(fin,fout,5,12);
    fin.close();
    fout.close();
    cout<<"end of program"<<endl;
}

// 7.eof��Ա�����ж��Ƿ�Ϊ���һ���ַ�
void io_func5()
{
    ifstream inStream;
    inStream.open("outfile.dat");
    char next;
    inStream.get(next);    //��ȡ�����ַ�
    while(!inStream.eof()) //�����ж��Ƿ�������һ���ַ�
    {
        cout.put(next);     //��������ַ�
        inStream.get(next);
    }
}

// 8.read()��write()

int main()
{
    io_func3();
    return 0;
}