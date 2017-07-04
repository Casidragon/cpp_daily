/*五个囚犯先后从100颗绿豆中抓绿豆。抓得最多和最少的人将被处死，不能交流，
可以摸出剩下绿豆的数量，谁的存活几率最大？

提示：1、他们都是很聪明的人；2、他们的原则是先求保命，再去多杀人；
3、100颗不必都分完，但要保证每人至少抓一颗；4、若有重复的情况，则也算最大和最小，一并处死。*/

//穷举
#include<iostream>
#include<ostream>
#include<fstream>
using namespace std;

class person
{
	int dou;
public:
	person(int a)
		:dou(a) {}
	void print()
	{
		cout << dou << '\t';
	}
	int getnum()
	{
		return dou;
	}
};

class Jum
{
public:
	person a, b, c, d, e;
public:
	Jum(int a1, int a2, int a3, int a4, int a5)
		:a(a1), b(a2), c(a3), d(a4), e(a5) {  }
	void print()
	{
		a.print();
		b.print();
		c.print();
		d.print();
		e.print();
		cout << endl;
	}
	friend ofstream &operator << (ofstream &t, Jum& m)
	{
		t << m.a.getnum() << '\t' << m.b.getnum() << '\t' << m.c.getnum() << '\t' << m.d.getnum() << '\t' << m.e.getnum() << endl;
		return t;
	}
	void judge()
	{

	}
};

int main()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	for (a = 1; a <= 96; a++)
	{
		for (b = 1; b <= 100 - a - 3; b++)
		{
			for (c = 1; c <= 100 - a - b - 2; c++)
			{
				for (d = 1; d <= 100 - a - b - c - 1; d++)
				{
					for (e = 1; e <= 100 - a - b - c - d; e++)
					{
						Jum s(a, b, c, d, e);
						s.print();
						ofstream k("a.txt", ios::out | ios::app);
						k << s;
						k.close();
					}
				}
			}
		}
	}
	return 0;
}