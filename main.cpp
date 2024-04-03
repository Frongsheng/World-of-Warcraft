#include<iostream>
#include<string>
#include<algorithm>
#include"headquarter.h"
#include"warrior.h"
#include<cstdio>
using namespace std;

int initlife[warriorNum];//每种士兵的初始生命值

void test01()
{
	int n;//数据组数
	int	M;//生命元
	cin >> n >> M;
	int Min = M + 1;

	for (int i = 0; i < 5; i++)
	{
		cin >> initlife[i];//传入初始生命值
		Min = min(Min, initlife[i]);//找出最小生命值，用于判断是否还能生成武士
	}

	int indexJudge = 2,redIndex = 0, blueIndex = 0;//用以判断是否停止循环
	Headquarter red(r, M), blue(b, M); //声明两个司令部对象

	cout << "Case:" <<n<<endl;

	for (int time = 0;time<50; time++)
	{
		if (indexJudge <= 0)
		{
			break;
		}
		if (blue.getleftValue() < Min)
		{
			if (blueIndex == 0)
			{
				blueIndex = 1;
				indexJudge -= 1;
				blue.reportStop(time);
			}
			else
				continue;

		}
		if (red.getleftValue() < Min)
		{
			if (redIndex == 0)
			{
				redIndex = 1;
				indexJudge -= 1;
				red.reportStop(time);
			}
			else
				continue;
		}
		red.makeWarriors(time);
		blue.makeWarriors(time);
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}