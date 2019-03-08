
#include <string>
#include <iostream>


using namespace std;

int* getMinDistances(char* str, char charC)
{
	int len = strlen(str);
	int* result = new int[len];
	for(int i=0; i<len; i++)
	{
		result[i] = 0;
	}
	int lastCIndex = -1;
	int prePos = 0;
	int curDis = 0;
	for(int i=0; i<len; i++)
	{
		if(str[i] == charC) // 遇到charC，计算前面字符距离
		{
			// 需要往前计算位置
			if(lastCIndex >= 0)
			{
				prePos = (lastCIndex + i) / 2;
			}
			else
			{
				prePos = lastCIndex;
			}


			int tmpDis = 0;
			for(int j=i; j>prePos; j=j-1)
			{
				result[j] = tmpDis;
				tmpDis ++;
			}
			lastCIndex = i;
			curDis = 0;
		}
		else if(lastCIndex > -1) //计算charC后面字符距离
		{
			curDis ++;
			result[i] = curDis;
		}
	}
	return result;
}


int main(int argc, char** argv)
{
	char str[] = "joycastleisnotacastle";
	char charC = 't';
	int* p = getMinDistances(str, charC);
	int len = strlen(str);
	for(int i=0;i<len;i++)
	{
		cout << p[i] <<", ";
	}
	cout << endl;
	delete p;
	return 0;
}