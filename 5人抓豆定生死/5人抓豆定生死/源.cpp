/*五个囚犯先后从100颗绿豆中抓绿豆。抓得最多和最少的人将被处死，不能交流，
可以摸出剩下绿豆的数量，谁的存活几率最大？

提示：1、他们都是很聪明的人；2、他们的原则是先求保命，再去多杀人；
3、100颗不必都分完，但要保证每人至少抓一颗；4、若有重复的情况，则也算最大和最小，一并处死。*/

//穷举
#include<iostream>
#include<ostream>
#include<fstream>
#include<string>
using namespace std;

class person
{
	int dou;
public:
	person(int a = 0)
		:dou(a) {}
	void print()
	{
		cout << dou << '\t';
	}
	int getnum()
	{
		return dou;
	}
	operator int()
	{
		return dou;
	}
};

class Jum
{
	person a, b, c, d, e;
	static int Dead1, Dead2, Dead3, Dead4, Dead5;
	static int RunTimes;
public:
	Jum(int a1 = 0, int a2 = 0, int a3 = 0, int a4 = 0, int a5 = 0)
		:a(a1),b(a2),c(a3),d(a4),e(a5){}
	int GetRunTimes()
	{
		return RunTimes;
	}
	friend ostream &operator << (ostream &t, Jum& m)
	{
		t << m.a.getnum() << '\t' << m.b.getnum() << '\t' << m.c.getnum() << '\t' << m.d.getnum() << '\t' << m.e.getnum() << endl;
		return t;
	}
	void output(string FileName)
	{
		ofstream k(FileName, ios::out | ios::app);
		k << *this;
		k.close();
	}
	void judge_a(int num_a)
	{
		a = num_a;
		int max = a, min = a;
		if (a >= 1 && a <= 20)
		{
			b = c = d = e = a;
			RunTimes++;
			cout << *this;
			this->output("a.txt");
		}
		if (a > 20 && a <= 93)//94,95,06
		{
			for (int i = Min((int)((100 - a) / 4) + 1, 97 - a); i <= a - 1 && i <= 97 - a; i++)
			{
				for (int j = Min((int)(100 - a - i) / 3 + 1, 98 - i - a); j <= (int)(a + i) / 2 && j <= 98 - i - a; j++)
				{
					for (int k = Min((int)(100 - a - i - j) / 2 + 1, 99 - i - a - j); k <= (int)(a + i + j) / 3 && k <= 99 - i - a - j; k++)
					{
						b = i;
						c = j;
						d = k;
						e = 100 - a - b - c - d;
						RunTimes++;
						cout << *this;
						this->output("a.txt");
					}
				}
			}
		}
	}
};

int Min(int a, int b)
{
	if (a > b)return b;
	else return a;
}

//int Jum::Dead1 = Jum::Dead2 = Jum::Dead3 = Jum::Dead4 = Jum::Dead5 = 0;
int Jum::RunTimes = 0;


int main()
{
	int a = 0;
	Jum test;
	for (a = 1; a <= 96; a++)
	{
		test.judge_a(a);
	}
	cout << test.GetRunTimes() << endl;
	return 0;
}