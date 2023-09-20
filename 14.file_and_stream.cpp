#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;



/*
1-文件的输入输出
2-文件的读写
3-判断文件是否被打开
4-向文件中追加内容
5-操作元
6-流作为函数的实参
7-eof成员函数判断是否为最后一个字符
*/


struct PersonInfo{
    string name;
    vector<string> phones;
};


// 1.文件的输入和输出
void file_io()
{
    char data[100];
    
    // 以写模式打开文件
    ofstream outfile;
    outfile.open("afile.dat");

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    // 向文件写入用户输入的数据
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    // 再次向文件写入用户输入的数据
    outfile << data << endl;
    // 关闭打开的文件
    outfile.close();

    // 以读模式打开文件
    ifstream infile;
    infile.open("afile.dat", ios::in);
    
    cout << "Reading from the file" << endl;
    infile >> data;
    // 在屏幕上写入数据
    cout << data << endl;
    // 再次从文件读取数据，并显示它
    infile >> data;
    cout << data << endl;
    // 关闭打开的文件
    infile.close();
}

// 2.读写文件
void file_ios()
{
    ifstream inStream;
    ofstream outStream;
    inStream.open("afile.dat");
    outStream.open("outfile.dat");

    char first, second, thrid;
    // 将文件中的内容以char类型读出
    inStream>>first>>second>>thrid; 
    cout<<first<<" "<<second<<" "<<thrid<<endl; 

    // 以流的方式写文件
    outStream<<"the sum of the first 3\n"
             <<"numbers in infile.dat\n"
             <<"is"<<(first+second+thrid)<<endl;

    inStream.close();
    outStream.close();
}

// 3.查看IO是open是否成功被调用
void io_func1()
{
    ifstream inStream;
    ofstream outStream;

    // 判断文件是否被打开
    inStream.open("infile.dat");
    if(inStream.fail()) //成功打开文件是fail方法会返回flase
    {
        cout<<"open infile.dat is fail"<<endl;
        exit(1);        //直接退出程序
    }
    outStream.open("outfile.dat");
    if(outStream.fail())
    {
        cout<<"open outfile.dat is fail"<<endl;
        exit(1);
    }

    char first,second,thrid;
    inStream>>first>>second>>thrid; //将文件中的内容以char类型读出
    cout<<first<<" "<<second<<" "<<thrid<<endl; //将从文件中读出的内容输出到命令行
    outStream<<"the sum of the first 3\n"
             <<"numbers in infile.dat\n"
             <<"is"<<(first+second+thrid)<<endl;
    inStream.close();
    outStream.close();
}

// 4.向已经存在的文件中追加内容
void io_func2()
{
    ofstream outStream;
    outStream.open("outfile.dat",ios::app);  //app追加内容
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

// 5.操作元
void io_func3()
{
    // stew进行空格
    cout<<"hello"<<setw(4)<<10<<setw(6)<<20<<setw(8)<<30;
}

// 6.流作为函数的实参
void makeNeat(ifstream& messyFile, ofstream& neatFile, int number, int fieldWidth)
{
    neatFile.setf(ios::fixed);
    neatFile.setf(ios::showpoint); //显示小数点
    neatFile.setf(ios::showpos); //显示+
    neatFile.precision(number);//格式化输出
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

// 7.eof成员函数判断是否为最后一个字符
void io_func5()
{
    ifstream inStream;
    inStream.open("outfile.dat");
    char next;
    inStream.get(next);    //读取单个字符
    while(!inStream.eof()) //用来判断是否读到最后一个字符
    {
        cout.put(next);     //输出单个字符
        inStream.get(next);
    }
}

// 8.read()和write()

int main()
{
    io_func3();
    return 0;
}