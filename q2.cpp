
#include <string>
#include <iostream>

using namespace std;

struct Point
{
	int x;
	int y;
};

int getMaxPointsInLine(Point points[], int pointNum) 
{
	if(pointNum <= 2)
	{
		return pointNum;
	}
	int maxNum = 0;
	for(int i=0; i<pointNum-1; i++)
	{
		bool isSame = false; //是否与之前某个点重合，重合的点不用再计算
		for(int j=0; j<i; j++)
		{
			if(points[j].x == points[i].x && points[j].y == points[i].y)
			{
				isSame = true;
				break;
			}
		}
		if(isSame)
		{
			break;
		}

		int extraSamPointNum = 0; //与当前点i重合的点数量
		int curMaxlinePointNum = 1; //当前点i开始的最大线上点数。初始为自身一个点大小
		for(int j=i+1; j<pointNum; j++)
		{

			if(points[j].x == points[i].x && points[j].y == points[i].y)
			{
				extraSamPointNum ++;
			}
			else
			{
				int linePointNum = 2; //ij连线上点数
				for(int k = j+1; k<pointNum; k++)
				{
					if(points[k].x == points[i].x && points[k].y == points[i].y) //k与点i重合
					{
						
					}
					else if(points[k].x == points[j].x && points[k].y == points[j].y) //k与点j重合
					{
						linePointNum ++;
					}
					else if((points[k].x -points[i].x) * (points[j].y -points[i].y) == (points[j].x -points[i].x) * (points[k].y -points[i].y)) //k与i,j在同一条直线上
					{
						linePointNum ++;
					}
				}
				if(linePointNum > curMaxlinePointNum)
				{
					curMaxlinePointNum = linePointNum;
				}
			}
		}
		curMaxlinePointNum += extraSamPointNum; //加上与点i重合的点的数量
		if(curMaxlinePointNum > maxNum)
		{
			maxNum = curMaxlinePointNum;
		}
	}
	return maxNum;
}



int main(int argc, char** argv)
{
	Point inputArr[6] = {{1, 1}, {1, 1}, {2, 2}, {2, 2}, {3, 3}, {5, 3}};
	cout << getMaxPointsInLine(inputArr, 6) << endl;

	Point inputArr2[3] = {{1, 1}, {1, 1}, {1, 1}};
	cout << getMaxPointsInLine(inputArr2, 3) << endl;

	return 0;
}
