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

int Min(int a, int b)
{
	if (a > b)return b;
	else return a;
}

class person
{
	int dou;
public:
	person(int a = 0)
		:dou(a) {}
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
	void judge_b()
	{
		int max = a, min = a;
		int array_Jum[5] = { a,b,c,d,e };
		for (int i = 1; i < 5; i++)
		{
			if (array_Jum[i] > max) max = array_Jum[i];
			if (array_Jum[i] < min) min = array_Jum[i];
		}
		for (int i = 0; i < 5; i++)
		{
			if (max == array_Jum[i] || min == array_Jum[i])
			{
				switch (i)
				{
				case 0:Dead1++; break;
				case 1:Dead2++; break;
				case 2:Dead3++; break;
				case 3:Dead4++; break;
				case 4:Dead5++; break;
				default:
					break;
				}
			}
		}
	}
	void judge_a(int num_a, string FileName)
	{
		a = num_a;
		if (a >= 1 && a <= 20)
		{
			b = c = d = e = a;
			RunTimes++;
			cout << *this;
			this->output(FileName);
			this->judge_b();
		}
		if (a > 20 && a <= 33)
		{
			for (int i = Min((int)((100 - a) / 4) + 1, 97 - a); i <= a - 1 && i <= 97 - a; i++)
			{
				if (98 - a - i > (int)((a + i) / 2))
				{
					for (int j = Min((int)(100 - a - i) / 3 + 1, 98 - i - a); j <= (int)((a + i) / 2) && j <= 98 - i - a; j++)
					{
						for (int k = Min((int)(100 - a - i - j) / 2 + 1, 99 - i - a - j); k <= (int)((a + i + j) / 3) && k <= 99 - i - a - j; k++)
						{
							b = i;
							c = j;
							d = k;
							e = 100 - a - b - c - d;
							RunTimes++;
							cout << *this;
							this->output(FileName);
							this->judge_b();
						}
					}
				}
				else
					{
						d = e = 1;
						b = i;
						c = 98 - a - i;
						RunTimes++;
						cout << *this;
						this->output(FileName);
						this->judge_b();
					}
			}
		}
		if (a > 33 && a <= 48)
		{
			for (int i = (int)(196 - 3 * a) / 3 + 1; i < a; i++)
			{
				b = i;
				c = 98 - a - b;
				d = e = 1;
				RunTimes++;
				cout << *this;
				this->output(FileName);
				this->judge_b();
			}
		}
		if (a >= 49 && a <= 96)
		{
			b = 97 - a;
			c = d = e = 1;
			RunTimes++;
			cout << *this;
			this->output(FileName);
			this->judge_b();
		}
	}
	void PrintProbability(string FileName)
	{
		cout << "第一个人死亡的概率：" << (double) ((double)Dead1 / RunTimes) * 100 << "%" << '\n';
		cout << "第二个人死亡的概率：" << (double) ((double)Dead2 / RunTimes) * 100 << "%" << '\n';
		cout << "第三个人死亡的概率：" << (double) ((double)Dead3 / RunTimes) * 100 << "%" << '\n';
		cout << "第四个人死亡的概率：" << (double) ((double)Dead4 / RunTimes) * 100 << "%" << '\n';
		cout << "第五个人死亡的概率：" << (double) ((double)Dead5 / RunTimes) * 100 << "%" << endl;
		ofstream k(FileName, ios::out | ios::app);
		k << "第一个人死亡的概率：" << (double) ((double)Dead1 / RunTimes) * 100 << "%" << '\n';
		k << "第二个人死亡的概率：" << (double) ((double)Dead2 / RunTimes) * 100 << "%" << '\n';
		k << "第三个人死亡的概率：" << (double) ((double)Dead3 / RunTimes) * 100 << "%" << '\n';
		k << "第四个人死亡的概率：" << (double) ((double)Dead4 / RunTimes) * 100 << "%" << '\n';
		k << "第五个人死亡的概率：" << (double) ((double)Dead5 / RunTimes) * 100 << "%" << endl;
		k.close();

	}
};


int Jum::Dead1 = 0;
int Jum::Dead2 = 0;
int Jum::Dead3 = 0;
int Jum::Dead4 = 0;
int Jum::Dead5 = 0;
int Jum::RunTimes = 0;


int main()
{
	int a = 0;
	Jum test;
	string FileName = "a.txt";
	for (a = 1; a <= 96; a++)
	{
		test.judge_a(a, FileName);
	}
	test.PrintProbability(FileName);
	cout << test.GetRunTimes() << endl;
	return 0;
}

/*具体的判断可以采取打分制度*/