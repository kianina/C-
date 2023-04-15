#include<iostream>
#include<string>
using namespace std;

template<class T>
/*≈≈–ÚÀ„∑®*/
void mySort(T* arr, int len)
{
	int temp;
	for (int i = 0; i < len; i++) {
		int max = arr[i];
		for (int j = i+1; j < len ; j++) {
			if (arr[j] > max) {
				
				temp = max;
				max = arr[j];
				arr[j] = temp;
			}
		}
		arr[i] = max;
	}
}
void print(char*arr,int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
}
void printi(int* arr, int len)
{
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
}
void test() {
	char carr[] = "fahgage";
	int num = sizeof(carr) / sizeof(char);
	mySort(carr, num);
	print(carr, num);
}
void test1()
{
	int iarr[10] = { 1,5,6,9,3,0,3,7,2 };
	int num = sizeof(iarr) / sizeof(int);
	mySort(iarr, num);
	printi(iarr, num);
}
int main() {
	test();
	return 0;
}