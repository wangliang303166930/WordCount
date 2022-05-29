#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(int argc, char* argv[])
{
	//文件打开
	fstream fin;
	fin.open(argv[2]);
	int counter = 0;//计数器
	//统计字符个数
	if (argv[1][1] == 'c')
	{
		char ch;
		while (fin && fin.get(ch))
		{
			//cout << ch;
			counter++;
		}
		cout << "字符数：" << counter << endl;

	}
	//统计单词数
	else
	{
		char ch;
		char side;//最后一位临界判断
		int flagAlph = 0;
		int flagChar = 0;
		//读字符和字母两种状态，
		while (fin && fin.get(ch))
		{
			side = ch;
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			{
				flagAlph++;
				flagChar = 0;
			}
			else
			{
				flagChar++;
			}
			//一遇到字母，就开始检测，检测其他字符就停止
			if (flagAlph != 0 && flagChar != 0)//检测到其他字符
			{
				counter++;
				flagAlph = 0;
			}
		}
		//临界条件，最后一位是字母
		if ((side >= 'a' && side <= 'z') || (side >= 'A' && side <= 'Z'))
		{
			counter++;
		}
		cout << "单词数：" << counter << endl;
	}
	fin.close();
	return 0;
}
