#include<iostream>
#include<string>
#include<algorithm>
#include"headquarter.h"
#include"warrior.h"
#include<cstdio>
using namespace std;

int initlife[warriorNum];//ÿ��ʿ���ĳ�ʼ����ֵ

void test01()
{
	int n;//��������
	int	M;//����Ԫ
	cin >> n >> M;
	int Min = M + 1;

	for (int i = 0; i < 5; i++)
	{
		cin >> initlife[i];//�����ʼ����ֵ
		Min = min(Min, initlife[i]);//�ҳ���С����ֵ�������ж��Ƿ���������ʿ
	}

	int indexJudge = 2,redIndex = 0, blueIndex = 0;//�����ж��Ƿ�ֹͣѭ��
	Headquarter red(r, M), blue(b, M); //��������˾�����

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