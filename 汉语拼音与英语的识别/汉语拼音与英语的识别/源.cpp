#include<iostream>
#include<string.h>
using namespace std;
bool chinese(char* &);
int shengmu(char* a);
bool yunmu(char*, int);

void main()
{
	char *input = new char[1000];
	cin.getline(input, 1000);
	int flag = 0;
	int i = 0;
	for (i = 0; i < 5; i++)                //�ж�5��
	{
		if (i == 0)
		{
			flag += chinese(input);
		}
		else
		{
			int k = 0;
			while (input[k] != '\x20')
			{
				k++;
				if (k > 1000) break;
			}
			if (k > 1000) break;
			for (int i = 0; k < 1000; k++, i++)
			{
				input[i] = input[k + 1];
			}
			flag += chinese(input);
		}
	}

	if (flag == i)
	{
		cout << "You input Chinese" << endl;
	}
	else
	{
		cout << "You input English" << endl;
	}

	system("pause");

	if (input)
	{
		delete[]input;
	}

}

bool chinese(char* &input)
{
	char* temp = new char[20];
	/******************************************************************************************/
	/************************************get single word***************************************/
	int i = 0;
	int k = 0;
	while (input[i] != '\0' && input[i] != '\x20')
	{
		temp[k] = input[i];
		k++; i++;
	}
	temp[k] = '\0';
	/**************************************get shengmu*****************************************/
	//char* shengmu1 = new char[strlen(temp) + 1];
	int shengmuNum = shengmu(temp);

	int flag = yunmu(temp, shengmuNum);

	if (temp)
	{
		delete[]temp;
		temp = 0;
	}

	if (flag == 1)
	{
		return true;
	}
	return false;
}

int shengmu(char* a)              //��ȡ��ĸ����
{
	char sheet[] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','w','x','y','z' };
	int i = 0;
	for (i = 0; i < sizeof(sheet); i++)
	{
		if (a[0] == sheet[i])
		{
			if (sheet[i] == 'c' || sheet[i] == 'z' || sheet[i] == 's')
			{
				if (a[1] == 'h')
				{
					return 2;
				}
				else return 1;
			}
			return 1;
		}
	}
	return 0;
}

bool yunmu(char *input, int a)                  //�ж��Ƿ�����ĸ
{
	int flag = 0;
	switch (input[a])
	{
	case 'a':
	{
		if (input[a + 1] == '\0' || input[a + 1] == '\x20')
		{
			flag = 1;
			break;
		}
		if (input[a + 1] == 'i' || input[a + 1] == 'o' || input[a + 1] == 'n')
		{
			if (input[a + 2] == '\0' || input[a + 2] == '\x20')
			{
				flag = 1;
				break;
			}
			if (input[a + 2] == 'g' && (input[a + 3] == '\0' || input[a + 3] == '\x20'))
			{
				flag = 1;
				break;
			}
		}
		break;
	}
	case 'o':
	{
		if (input[a + 1] == '\0' || input[a + 1] == '\x20')
		{
			flag = 1;
			break;
		}
		if (input[a + 1] == 'u' || input[a + 1] == 'n')
		{
			if (input[a + 2] == '\0' || input[a + 2] == '\x20')
			{
				flag = 1;
				break;
			}
			if (input[a + 2] == 'g' && (input[a + 3] == '\0' || input[a + 3] == '\x20'))
			{
				flag = 1;
				break;
			}
		}
		break;
	}
	case 'e':
	{
		if (input[a + 1] == '\0' || input[a + 1] == '\x20')
		{
			flag = 1;
			break;
		}
		if (input[a + 1] == 'i' || input[a + 1] == 'r' || input[a + 1] == 'n')
		{
			if (input[a + 2] == '\0' || input[a + 2] == '\x20')
			{
				flag = 1;
				break;
			}
			if (input[a + 2] == 'g' && (input[a + 3] == '\0' || input[a + 3] == '\x20'))
			{
				flag = 1;
				break;
			}
		}
		break;
	}
	case 'i':
	{
		if (input[a + 1] == '\0' || input[a + 1] == '\x20')
		{
			flag = 1;
			break;
		}
		if (input[a + 1] == 'u' || input[a + 1] == 'e' || input[a + 1] == 'n')
		{
			if (input[a + 2] == '\0' || input[a + 2] == '\x20')
			{
				flag = 1;
				break;
			}
			if (input[a + 2] == 'g' && (input[a + 3] == '\0' || input[a + 3] == '\x20'))
			{
				flag = 1;
				break;
			}
		}
		if (input[a + 1] == ('a'))
		{
			if (input[a + 2] == '\0' || input[a + 2] == '\x20')
			{
				flag = 1;
			}
			if (input[a + 2] == 'n' && input[a + 3] == 'g' && (input[a + 4] == '\0' || input[a + 4] == '\x20'))
			{
				flag = 1;
			}
			if (input[a + 2] == 'o' && (input[a + 3] == '\0' || input[a + 3] == '\x20'))
			{
				flag = 1;
			}
		}
		if (input[a + 1] == 'o'&&input[a + 2] == 'n'&&input[a + 3] == 'g' && (input[a + 4] == '\0' || input[a + 4] == '\x20'))
		{
			flag = 1;
		}
		break;
	}
	case 'u':
	{
		if (input[a + 1] == '\0' || input[a + 1] == '\x20')
		{
			flag = 1;
			break;
		}
		if (input[a + 1] == 'i' || input[a + 1] == 'n')
		{
			if (input[a + 2] == '\0' || input[a + 2] == '\x20')
			{
				flag = 1;
				break;
			}
		}
		if (input[a + 1] == 'a')
		{
			if ((input[a + 2] == '\0' || input[a + 2] == '\x20') || (input[a + 2] == 'n' && (input[a + 3] == '\0' || input[a + 3] == '\x20')) || (input[a + 2] == 'n'&&input[a + 3] == 'g' && (input[a + 4]) == '\0' || input[a + 4] == '\x20'))
			{
				flag = 1;
			}
		}
		if (input[a + 1] == 'o'&&input[a + 2] == '\0' || input[a + 2] == '\x20')
		{
			flag = 1;
		}
		break;
	}
	case 'v':
	{
		if (input[a + 1] == '\0' || input[a + 1] == '\x20')
		{
			flag = 1;
			break;
		}
		if (input[a + 1] == 'e' || input[a + 1] == 'n')
		{
			if (input[a + 2] == '\0' || input[a + 2] == '\x20')
			{
				flag = 1;
				break;
			}
		}
		break;
	}
	default:
		break;
	}
	return flag;
}