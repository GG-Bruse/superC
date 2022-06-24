#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <conio.h>
using namespace std;


char s1[4][25][200];	//�������
char s2[4][45][200];
char s3[4][35][200];
char a_s[4][3][9];

char r1[4][19][200];	//�������
char r1a[4][15][20];

char r2[4][57][200];	//�Ķ����
char r2a[4][2][6];


void read();				//�ļ����
void readfile();			//�ļ���ȡ
void part1();				//�����������
void part2();				//�����������
void part3_1();				//�Ķ��������
void part3_2();				//�Ķ��������
void Part1ting(int a);		//��������ȡ
void Part2reading1(int a);	//��������ȡ
void Part2reading2_1(int a);//�Ķ�����ȡ
void Part2reading2_2(int a);//�Ķ�����ȡ
void option1();
void option2();
void option3();
void option4();
void titleA();				//Ѻ���A
void titleB();				//Ѻ���B
void titleC();				//Ѻ���C
void titleD();				//Ѻ���D

void full_screen()
{
	HWND hwnd = GetForegroundWindow();
	int cx = GetSystemMetrics(SM_CXSCREEN);            /* ��Ļ��� ���� */
	int cy = GetSystemMetrics(SM_CYSCREEN);            /* ��Ļ�߶� ���� */

	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* ��ȡ������Ϣ */
	/* ���ô�����Ϣ ��� ȡ�����������߿� */
	SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE)/* & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER*/);

	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}

int main()
{
	//full_screen();
	system("color 70");
	read();
	readfile();
	srand((unsigned int)time(NULL));//���²���

	while (1)
	{
		cout << "\n\n\n\n\n\n" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x79);
		cout << "\t\t\t===========================================" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||          Ӣ������ר��ѵ��(2.0)        ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t===========================================" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            1.Ӣ���������             ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            2.����ר��                 ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            3.����ר��                 ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            4.�Ķ�ר��                 ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            5.Ѻ���A                  ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            6.Ѻ���B                  ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            7.Ѻ���C                  ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            8.Ѻ���D                  ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            0.�������ݡ��˳�ϵͳ       ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t===========================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
		cout << '\n' << endl;
		cout << "\t\t\t����������ѡ��:";

		string void_XuanXiang;
		char XuanXiang = 'a';
		cin >> void_XuanXiang;
		if (void_XuanXiang[1] == '\0')
		{
			XuanXiang = void_XuanXiang[0];
		}
		else
		{
			XuanXiang = 'a';
		}
		system("cls");
		switch (XuanXiang)
		{
		case '1':option1(); break;
		case '2':option2(); break;
		case '3':option3(); break;
		case '4':option4(); break;
		case '5':titleA(); break;
		case '6':titleB(); break;
		case '7':titleC(); break;
		case '9':titleD(); break;
		case '0':return 0;
		default:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7c);
			cout << "\n\n\n\n\n\t\t\t\t\aû����һѡ��!������ѡ��!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
		}
	}
	return 0;
}


void option1()
{
	int ji = 1;
	while (ji)
	{
		system("cls");
		part1(); part2(); part3_1(); part3_2();
		cout << "\n\n\t\t\t\t��ϲ��������ϣ���!\n" << endl;
		cout << "\n\n\t\t\t�Ƿ���������������������˳���" << endl;

		int ch = 1;
		while (ch)
		{
			int ch1 = _getch();
			int ch2 = _getch();
			int ch3;
			if (ch2 == 224) ch3 = ch1;
			else ch3 = ch2;
			switch (ch3)
			{
			case 77:ch = 0; break;
			case 75:ji = 0; ch = 0; break;
			}
		}
	}
}


void option2()
{
	int ji = 1;
	while (ji)
	{
		cout << "\n\n\n\n\n\n" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x73);
		cout << "\t\t\t===========================================" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||               ����ר��                ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t===========================================" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            1.��һ��Ԫ����             ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            2.�ڶ���Ԫ����             ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            3.������Ԫ����             ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            4.���ĵ�Ԫ����             ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            5.�������ѵ��             ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            0.������һ��               ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t===========================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
		cout << '\n' << endl;
		cout << "\t\t\t����������ѡ��:";
		string void_XuanXiang;
		char XuanXiang = 'a';
		cin >> void_XuanXiang;
		if (void_XuanXiang[1] == '\0')
		{
			XuanXiang = void_XuanXiang[0];
		}
		else
		{
			XuanXiang = 'a';
		}
		system("cls");
		if (XuanXiang > '0' && XuanXiang < '5')
		{
			int jiji = 1;
			while (jiji)
			{
				Part1ting(XuanXiang - 1 - '0');
				cout << "\n\n\t\t\t\t��ϲ��������ϣ���!\n" << endl;
				cout << "\n\n\t\t\t�Ƿ���������������������˳���" << endl;

				int ch = 1;
				while (ch)
				{
					int ch1 = _getch();
					int ch2 = _getch();
					int ch3;
					if (ch2 == 224) ch3 = ch1;
					else ch3 = ch2;
					switch (ch3)
					{
					case 77:ch = 0; break;
					case 75:jiji = 0; ch = 0; break;
					}
				}
			}
		}
		else if (XuanXiang == '5')
		{
			int jiji = 1;
			while (jiji)
			{
				part1();
				cout << "\n\n\t\t\t\t��ϲ��������ϣ���!\n" << endl;
				cout << "\n\n\t\t\t�Ƿ���������������������˳���" << endl;

				int ch = 1;
				while (ch)
				{
					int ch1 = _getch();
					int ch2 = _getch();
					int ch3;
					if (ch2 == 224) ch3 = ch1;
					else ch3 = ch2;
					switch (ch3)
					{
					case 77:ch = 0; break;
					case 75:jiji = 0; ch = 0; break;
					}
				}
			}
		}
		else if (XuanXiang == '0')
		{
			ji = 0;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7c);
			cout << "\n\n\n\n\n\t\t\t\t\aû����һѡ��!������ѡ��!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
		}
	}
}


void option3()
{
	int ji = 1;
	while (ji)
	{
		cout << "\n\n\n\n\n\n" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x73);
		cout << "\t\t\t===========================================" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||               ����ר��                ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t===========================================" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            1.��һ��Ԫ����             ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            2.�ڶ���Ԫ����             ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            3.������Ԫ����             ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            4.���ĵ�Ԫ����             ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            5.�������ѵ��             ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||            0.������һ��               ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t===========================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
		cout << '\n' << endl;
		cout << "\t\t\t����������ѡ��:";
		string void_XuanXiang;
		char XuanXiang = 'a';
		cin >> void_XuanXiang;
		if (void_XuanXiang[1] == '\0')
		{
			XuanXiang = void_XuanXiang[0];
		}
		else
		{
			XuanXiang = 'a';
		}
		system("cls");
		if (XuanXiang > '0' && XuanXiang < '5')
		{
			int jiji = 1;
			while (jiji)
			{
				Part2reading1(XuanXiang - 1 - '0');
				cout << "\n\n\t\t\t\t��ϲ��������ϣ���!\n" << endl;
				cout << "\n\n\t\t\t�Ƿ���������������������˳���" << endl;

				int ch = 1;
				while (ch)
				{
					int ch1 = _getch();
					int ch2 = _getch();
					int ch3;
					if (ch2 == 224) ch3 = ch1;
					else ch3 = ch2;
					switch (ch3)
					{
					case 77:ch = 0; break;
					case 75:jiji = 0; ch = 0; break;
					}
				}
			}
		}
		else if (XuanXiang == '5')
		{
			int jiji = 1;
			while (jiji)
			{
				part2();
				cout << "\n\n\t\t\t\t��ϲ��������ϣ���!\n" << endl;
				cout << "\n\n\t\t\t�Ƿ���������������������˳���" << endl;

				int ch = 1;
				while (ch)
				{
					int ch1 = _getch();
					int ch2 = _getch();
					int ch3;
					if (ch2 == 224) ch3 = ch1;
					else ch3 = ch2;
					switch (ch3)
					{
					case 77:ch = 0; break;
					case 75:jiji = 0; ch = 0; break;
					}
				}
			}
		}
		else if (XuanXiang == '0')
		{
			ji = 0;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7c);
			cout << "\n\n\n\n\n\t\t\t\t\aû����һѡ��!������ѡ��!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
		}
	}
}


void option4()
{
	int ji = 1;
	while (ji)
	{
		cout << "\n\n\n\n\n\n" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x73);
		cout << "\t\t\t===========================================" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||               �Ķ�ר��                ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t===========================================" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||           1.��һ��Ԫ��һƪ            ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||           2.��һ��Ԫ�ڶ�ƪ            ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||           3.�ڶ���Ԫ��һƪ            ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||           4.�ڶ���Ԫ�ڶ�ƪ            ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||           5.������Ԫ��һƪ            ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||           6.������Ԫ�ڶ�ƪ            ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||           7.���ĵ�Ԫ��һƪ            ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||           8.���ĵ�Ԫ�ڶ�ƪ            ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||           9.����Ķ�ѵ��              ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t||           0.������һ��                ||" << endl;
		cout << "\t\t\t||                                       ||" << endl;
		cout << "\t\t\t===========================================" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
		cout << '\n' << endl;
		cout << "\t\t\t����������ѡ��:";
		string void_XuanXiang;
		char XuanXiang = 'a';
		cin >> void_XuanXiang;
		if (void_XuanXiang[1] == '\0')
		{
			XuanXiang = void_XuanXiang[0];
		}
		else
		{
			XuanXiang = 'a';
		}
		system("cls");
		if (XuanXiang > '0' && XuanXiang < '9')
		{
			int jiji = 1;
			while (jiji)
			{
				if (XuanXiang == '1' || XuanXiang == '3' || XuanXiang == '5' || XuanXiang == '7')
				{
					Part2reading2_1(XuanXiang - '0' - (XuanXiang + 1 - '0') / 2);
				}
				else
				{
					Part2reading2_2(XuanXiang - '0' - 1 - (XuanXiang - '0') / 2);
				}
				cout << "\n\n\t\t\t\t��ϲ��������ϣ���!\n" << endl;
				cout << "\n\n\t\t\t�Ƿ���������������������˳���" << endl;

				int ch = 1;
				while (ch)
				{
					int ch1 = _getch();
					int ch2 = _getch();
					int ch3;
					if (ch2 == 224) ch3 = ch1;
					else ch3 = ch2;
					switch (ch3)
					{
					case 77:ch = 0; break;
					case 75:jiji = 0; ch = 0; break;
					}
				}
			}
		}
		else if (XuanXiang == '9')
		{
			int jiji = 1;
			while (jiji)
			{
				part3_1();
				part3_2();
				cout << "\n\n\t\t\t\t��ϲ��������ϣ���!\n" << endl;
				cout << "\n\n\t\t\t�Ƿ���������������������˳���" << endl;

				int ch = 1;
				while (ch)
				{
					int ch1 = _getch();
					int ch2 = _getch();
					int ch3;
					if (ch2 == 224) ch3 = ch1;
					else ch3 = ch2;
					switch (ch3)
					{
					case 77:ch = 0; break;
					case 75:jiji = 0; ch = 0; break;
					}
				}
			}
		}
		else if (XuanXiang == '0')
		{
			ji = 0;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7c);
			cout << "\n\n\n\n\n\t\t\t\t\aû����һѡ��!������ѡ��!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
		}
	}
}


void read()
{
	ifstream fp("./�����2_2.txt", ios::in);
	if (!fp.is_open())
	{
		cout << "\t\t���ļ�ʧ��!\a\n" << endl;
		fp.close();
		exit(0);
	}
	fp.close();
}


void readfile()
{
	ifstream fp("./�����2_2.txt", ios::in);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			fp.getline(s1[i][j], sizeof(s1[0][0]) / sizeof(s1[0][0][0]));
		}
		fp.getline(a_s[i][0], sizeof(a_s[0][0]) / sizeof(a_s[0][0][0]));
		for (int j = 0; j < 45; ++j)
		{
			fp.getline(s2[i][j], sizeof(s2[0][0]) / sizeof(s2[0][0][0]));
		}
		fp.getline(a_s[i][1], sizeof(a_s[0][0]) / sizeof(a_s[0][0][0]));
		for (int j = 0; j < 35; ++j)
		{
			fp.getline(s3[i][j], sizeof(s3[0][0]) / sizeof(s3[0][0][0]));
		}
		fp.getline(a_s[i][2], sizeof(a_s[0][0]) / sizeof(a_s[0][0][0]));
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			fp.getline(r1[i][j], sizeof(r1[0][0]) / sizeof(r1[0][0][0]));
		}
		for (int j = 0; j < 15; ++j)
		{
			fp.getline(r1a[i][j], sizeof(r1a[0][0]) / sizeof(r1a[0][0][0]));
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 57; ++j)
		{
			fp.getline(r2[i][j], sizeof(r2[0][0]) / sizeof(r2[0][0][0]));
		}
		for (int j = 0; j < 2; ++j)
		{
			fp.getline(r2a[i][j], sizeof(r2a[0][0]) / sizeof(r2a[0][0][0]));
		}
	}
	fp.close();
}


void part1()
{
	int x, a = 1;
	static int y1 = 4, y2 = 4, y3 = 4;
	while (a)
	{
		x = rand() % 4;
		if (x == y1 || x == y2 || x == y3) continue;
		else y3 = y2, y2 = y1, y1 = x, a = 0;
		switch (x)
		{
		case 0:Part1ting(0); break;
		case 1:Part1ting(1); break;
		case 2:Part1ting(2); break;
		case 3:Part1ting(3); break;
		}
	}
}


void part2()
{
	int x, a = 1;
	static int y1 = 4, y2 = 4, y3 = 4;
	while (a)
	{
		x = rand() % 4;
		if (x == y1 || x == y2 || x == y3) continue;
		else y3 = y2, y2 = y1, y1 = x, a = 0;
		switch (x)
		{
		case 0:Part2reading1(0); break;
		case 1:Part2reading1(1); break;
		case 2:Part2reading1(2); break;
		case 3:Part2reading1(3); break;
		}
	}
}


void part3_1()
{
	int x, a = 1;
	static int y1 = 4, y2 = 4, y3 = 4;
	while (a)
	{
		x = rand() % 4;
		if (x == y1 || x == y2 || x == y3) continue;
		else y3 = y2, y2 = y1, y1 = x, a = 0;
		switch (x)
		{
		case 0:Part2reading2_1(0); break;
		case 1:Part2reading2_1(1); break;
		case 2:Part2reading2_1(2); break;
		case 3:Part2reading2_1(3); break;
		}
	}
}


void part3_2()
{
	int x, a = 1;
	static int y1 = 4, y2 = 4, y3 = 4;
	while (a)
	{
		x = rand() % 4;
		if (x == y1 || x == y2 || x == y3) continue;
		else y3 = y2, y2 = y1, y1 = x, a = 0;
		switch (x)
		{
		case 0:Part2reading2_2(0); break;
		case 1:Part2reading2_2(1); break;
		case 2:Part2reading2_2(2); break;
		case 3:Part2reading2_2(3); break;
		}
	}
}


void Part1ting(int a)
{
	int y[3] = { 6,6,6 };
	char ca[3][9], cr[3][9];

	cout << "\n\n\n\n" << endl;
	for (int ti = 0; ti < 4; ++ti)
	{
		if (ti == 0)
		{
			for (int i = 0; i < 4; ++i)
			{
				cout << '\t' << s1[a][i] << endl;
			}
		}
		else if (ti == 1)
		{
			cout << '\t' << s1[a][8] << endl;
		}
		else if (ti == 2)
		{
			cout << '\t' << s1[a][13] << endl;
			cout << '\t' << s1[a][14] << endl;
			cout << '\t' << s1[a][15] << endl;
		}
		else if (ti == 3)
		{
			cout << '\t' << s1[a][20] << endl;
		}
		for (int i = 0; i < 4; ++i)		//ѭ���ĴΣ��������ѡ��
		{
			int z = 0;
			int x = rand() % 4;
			for (int j = 0; j < i; ++j)//��һ��û�м�¼�����ݣ�ֱ������
				if (x == y[j])//���¼�µ����ݶԱȣ���ֹ�ظ�����
					z = 1;
			if (z)
			{
				i--;
				continue;//�����ظ�ֱ������
			}
			else
			{
				for (int j = 0; j < 2; ++j)//��¼��ÿһ��ѭ����������
				{
					y[2 - j] = y[1 - j];
				}
				y[0] = x;
			}
			if (x == a_s[a][0][ti] - 65)
			{
				ca[0][ti] = i + 65;
			}
			switch (ti)
			{
			case 0:s1[a][x + 4][8] = char(i + 65); cout << '\t' << s1[a][x + 4] << endl; break;
			case 1:s1[a][x + 9][8] = char(i + 65); cout << '\t' << s1[a][x + 9] << endl; break;
			case 2:s1[a][x + 16][8] = char(i + 65); cout << '\t' << s1[a][x + 16] << endl; break;
			case 3:s1[a][x + 21][8] = char(i + 65); cout << '\t' << s1[a][x + 21] << endl; break;
			}
		}
	}

	cout << "\n\t��������ȷ��:";
	cin >> cr[0];
	ca[0][4] = '\0';//���ַ���Ϊ�ַ��������бȽ�
	if (strcmp(cr[0], ca[0]) == 0)
	{
		cout << "\n\n\n\t\t\t\t��ϲ��!�ش���ȷ!\n\n" << endl;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7c);
		cout << "\n\n\n\t\t\t\t�ش����!!!!!!\n\n\n\n\n\t\t\t\t��ȷ��:" << ca[0] << "\a" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
		Sleep(1 * 1000);
		cout << "\n\n\n\n\t\t\t�鿴����밴�¡���������һ��!\n" << endl;

		int ch = 1;
		while (ch)
		{
			int ch1 = _getch();
			int ch2 = _getch();
			int ch3;
			if (ch2 == 224) ch3 = ch1;
			else ch3 = ch2;
			switch (ch3)
			{
			case 80:ch = 0; break;
			}
		}
	}


	for (int ti = 0; ti < 8; ++ti)
	{
		if (ti == 0)
		{
			for (int i = 0; i < 4; ++i)
			{
				cout << '\t' << s2[a][i] << endl;
			}
		}
		else if (ti < 4)
		{
			cout << '\t' << s2[a][8 + 5 * (ti - 1)] << endl;
		}
		else if (ti == 4)
		{
			cout << '\t' << s2[a][23] << endl;
			cout << '\t' << s2[a][24] << endl;
			cout << '\t' << s2[a][25] << endl;
		}
		else
		{
			cout << '\t' << s2[a][10 + 5 * (ti - 1)] << endl;
		}
		for (int i = 0; i < 4; ++i)
		{
			int z = 0;
			int x = rand() % 4;
			for (int j = 0; j < i; ++j)//��һ��û�м�¼�����ݣ�ֱ������
				if (x == y[j])//���¼�µ����ݶԱȣ���ֹ�ظ�����
					z = 1;
			if (z)
			{
				i--;
				continue;//�����ظ�ֱ������
			}
			else
			{
				for (int j = 0; j < 2; ++j)//��¼��ÿһ��ѭ����������
				{
					y[2 - j] = y[1 - j];
				}
				y[0] = x;
			}
			if (x == a_s[a][1][ti] - 65)
			{
				ca[1][ti] = i + 65;
			}
			if (ti < 4)
			{
				s2[a][x + (4 + 5 * ti)][8] = char(i + 65);
				cout << '\t' << s2[a][x + (4 + 5 * ti)] << endl;
			}
			else
			{
				s2[a][x + (6 + 5 * ti)][8] = char(i + 65);
				cout << '\t' << s2[a][x + (6 + 5 * ti)] << endl;
			}
		}
	}

	cout << "\n\t��������ȷ��:";
	cin >> cr[1];
	ca[1][8] = '\0';//���ַ���Ϊ�ַ��������бȽ�
	if (strcmp(cr[1], ca[1]) == 0)
	{
		cout << "\n\n\n\t\t\t\t��ϲ��!�ش���ȷ!\n\n" << endl;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7c);
		cout << "\n\n\n\t\t\t\t�ش����!!!!!!\n\n\n\n\n\t\t\t\t��ȷ��:" << ca[1] << "\a" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
		Sleep(1 * 1000);
		cout << "\n\n\n\n\t\t\t�鿴����밴�¡���������һ��!\n" << endl;

		int ch = 1;
		while (ch)
		{
			int ch1 = _getch();
			int ch2 = _getch();
			int ch3;
			if (ch2 == 224) ch3 = ch1;
			else ch3 = ch2;
			switch (ch3)
			{
			case 80:ch = 0; break;
			}
		}
	}


	for (int ti = 0; ti < 6; ++ti)
	{
		if (ti == 0)
		{
			for (int i = 0; i < 4; ++i)
			{
				cout << '\t' << s3[a][i] << endl;
			}
		}
		else if (ti < 3)
		{
			cout << '\t' << s3[a][8 + 5 * (ti - 1)] << endl;
		}
		else if (ti == 3)
		{
			cout << '\t' << s3[a][18] << endl;
			cout << '\t' << s3[a][19] << endl;
			cout << '\t' << s3[a][20] << endl;
		}
		else
		{
			cout << '\t' << s3[a][10 + 5 * (ti - 1)] << endl;
		}
		for (int i = 0; i < 4; ++i)
		{
			int z = 0;
			int x = rand() % 4;
			for (int j = 0; j < i; ++j)//��һ��û�м�¼�����ݣ�ֱ������
				if (x == y[j])//���¼�µ����ݶԱȣ���ֹ�ظ�����
					z = 1;
			if (z)
			{
				i--;
				continue;//�����ظ�ֱ������
			}
			else
			{
				for (int j = 0; j < 2; ++j)//��¼��ÿһ��ѭ����������
				{
					y[2 - j] = y[1 - j];
				}
				y[0] = x;
			}
			if (x == a_s[a][2][ti] - 65)
			{
				ca[2][ti] = i + 65;
			}
			if (ti < 3)
			{
				s3[a][x + (4 + 5 * ti)][8] = char(i + 65);
				cout << '\t' << s3[a][x + (4 + 5 * ti)] << endl;
			}
			else
			{
				s3[a][x + (6 + 5 * ti)][8] = char(i + 65);
				cout << '\t' << s3[a][x + (6 + 5 * ti)] << endl;
			}
		}
	}

	cout << "\n\t��������ȷ��:";
	cin >> cr[2];
	ca[2][6] = '\0';//���ַ���Ϊ�ַ��������бȽ�
	if (strcmp(cr[2], ca[2]) == 0)
	{
		cout << "\n\n\n\t\t\t\t��ϲ��!�ش���ȷ!\n\n" << endl;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7c);
		cout << "\n\n\n\t\t\t\t�ش����!!!!!!\n\n\n\n\n\t\t\t\t��ȷ��:" << ca[2] << "\a" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
		Sleep(1 * 1000);
		cout << "\n\n\n\n\t\t\t�鿴����밴�¡���������һ��!\n" << endl;

		int ch = 1;
		while (ch)
		{
			int ch1 = _getch();
			int ch2 = _getch();
			int ch3;
			if (ch2 == 224) ch3 = ch1;
			else ch3 = ch2;
			switch (ch3)
			{
			case 80:ch = 0; break;
			}
		}
	}
}


void Part2reading1(int a)
{
	int y[14];
	char ca[11], cr[11];
	for (int i = 0; i < 14; ++i)
	{
		y[i] = 100;
	}
	cout << "\n\n\n\n" << endl;
	cout << '\t' << r1[a][0] << endl;
	cout << '\t' << r1[a][1] << endl;
	cout << '\n' << endl;
	if (a == 0 || a == 3)
	{
		for (int i = 2; i < 19; ++i)
		{
			cout << r1[a][i] << endl;
		}
	}
	else if (a == 1)
	{
		for (int i = 2; i < 18; ++i)
		{
			cout << r1[a][i] << endl;
		}
	}
	else
	{
		for (int i = 2; i < 12; ++i)
		{
			cout << r1[a][i] << endl;
		}
	}
	cout << "\n    -----------------------------------------------------------------------------------------\n    ";
	for (int i = 0; i < 15; ++i)
	{
		int z = 0;
		int x = rand() % 15;
		for (int j = 0; j < i; ++j)//��һ��û�м�¼�����ݣ�ֱ������
			if (x == y[j])//���¼�µ����ݶԱȣ���ֹ�ظ�����
				z = 1;
		if (z)
		{
			i--;
			continue;//�����ظ�ֱ������
		}
		else
		{
			for (int j = 0; j < 13; ++j)//��¼��ÿһ��ѭ����������
			{
				y[13 - j] = y[12 - j];
			}
			y[0] = x;
		}
		if (x < 10)
		{
			ca[x] = i + 65;//�󶨴������˳��
		}
		if (i % 4 != 3)
		{
			cout << '|' << char(i + 65) << setw(20) << left << r1a[a][x];
		}
		else
		{
			cout << '|' << char(i + 65) << setw(20) << left << r1a[a][x] << "|\n    ";
		}
	}
	cout << "\n    -----------------------------------------------------------------------------------------" << endl;
	cout << "\n\t��������ȷ��:";

	ca[10] = '\0';//���ַ���Ϊ�ַ��������бȽ�

	cin >> cr;
	if (strcmp(cr, ca) == 0)
	{
		cout << "\n\n\n\t\t\t\t��ϲ��!�ش���ȷ!\n\n" << endl;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7c);
		cout << "\n\n\n\t\t\t\t�ش����!!!!!!\n\n\n\n\n\t\t\t\t��ȷ��:" << ca << "\a" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
		Sleep(1 * 1000);
		cout << "\n\n\n\n\t\t\t�鿴����밴�¡���������һ��!\n" << endl;

		int ch = 1;
		while (ch)
		{
			int ch1 = _getch();
			int ch2 = _getch();
			int ch3;
			if (ch2 == 224) ch3 = ch1;
			else ch3 = ch2;
			switch (ch3)
			{
			case 80:ch = 0; break;
			}
		}
	}
}


void Part2reading2_1(int a)
{
	int y[3] = { 6,6,6 };
	char ca[6], cr[6];

	cout << "\n\n\n\n" << endl;
	for (int ti = 0; ti < 5; ++ti)
	{
		if (ti == 0)
		{
			for (int i = 0; i < 6; ++i)
			{
				cout << '\t' << r2[a][i] << endl;
			}
		}
		else
		{
			cout << '\t' << r2[a][10 + 5 * (ti - 1)] << endl;
		}
		for (int i = 0; i < 4; ++i)
		{
			int z = 0;
			int x = rand() % 4;
			for (int j = 0; j < i; ++j)//��һ��û�м�¼�����ݣ�ֱ������
				if (x == y[j])//���¼�µ����ݶԱȣ���ֹ�ظ�����
					z = 1;
			if (z)
			{
				i--;
				continue;//�����ظ�ֱ������
			}
			else
			{
				for (int j = 0; j < 2; ++j)//��¼��ÿһ��ѭ����������
				{
					y[2 - j] = y[1 - j];
				}
				y[0] = x;
			}
			if (x == r2a[a][0][ti] - 65)
			{
				ca[ti] = i + 65;
			}
			r2[a][x + (6 + 5 * ti)][8] = char(i + 65);
			cout << '\t' << r2[a][x + (6 + 5 * ti)] << endl;
		}
	}

	cout << "\n\t��������ȷ��:";
	cin >> cr;
	ca[5] = '\0';//���ַ���Ϊ�ַ��������бȽ�
	if (strcmp(cr, ca) == 0)
	{
		cout << "\n\n\n\t\t\t\t��ϲ��!�ش���ȷ!\n\n" << endl;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7c);
		cout << "\n\n\n\t\t\t\t�ش����!!!!!!\n\n\n\n\n\t\t\t\t��ȷ��:" << ca << "\a" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
		Sleep(1 * 1000);
		cout << "\n\n\n\n\t\t\t�鿴����밴�¡���������һ��!\n" << endl;

		int ch = 1;
		while (ch)
		{
			int ch1 = _getch();
			int ch2 = _getch();
			int ch3;
			if (ch2 == 224) ch3 = ch1;
			else ch3 = ch2;
			switch (ch3)
			{
			case 80:ch = 0; break;
			}
		}
	}
}


void Part2reading2_2(int a)
{
	int y[3] = { 6,6,6 };
	char ca[6], cr[6];

	cout << "\n\n\n\n" << endl;
	for (int ti = 0; ti < 5; ++ti)
	{
		if (ti == 0)
		{
			for (int i = 0; i < 3; ++i)
			{
				cout << '\t' << r2[a][i + 30] << endl;
			}
		}
		else
		{
			cout << '\t' << r2[a][37 + 5 * (ti - 1)] << endl;
		}
		for (int i = 0; i < 4; ++i)
		{
			int z = 0;
			int x = rand() % 4;
			for (int j = 0; j < i; ++j)//��һ��û�м�¼�����ݣ�ֱ������
				if (x == y[j])//���¼�µ����ݶԱȣ���ֹ�ظ�����
					z = 1;
			if (z)
			{
				i--;
				continue;//�����ظ�ֱ������
			}
			else
			{
				for (int j = 0; j < 2; ++j)//��¼��ÿһ��ѭ����������
				{
					y[2 - j] = y[1 - j];
				}
				y[0] = x;
			}
			if (x == r2a[a][1][ti] - 65)
			{
				ca[ti] = i + 65;
			}
			r2[a][x + (3 + 5 * ti) + 30][8] = char(i + 65);
			cout << '\t' << r2[a][x + (3 + 5 * ti) + 30] << endl;
		}
	}

	cout << "\n\t��������ȷ��:";
	cin >> cr;
	ca[5] = '\0';//���ַ���Ϊ�ַ��������бȽ�
	if (strcmp(cr, ca) == 0)
	{
		cout << "\n\n\n\t\t\t\t��ϲ��!�ش���ȷ!\n\n" << endl;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7c);
		cout << "\n\n\n\t\t\t\t�ش����!!!!!!\n\n\n\n\n\t\t\t\t��ȷ��:" << ca << "\a" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
		Sleep(1 * 1000);
		cout << "\n\n\n\n\t\t\t�鿴����밴�¡���������һ��!\n" << endl;

		int ch = 1;
		while (ch)
		{
			int ch1 = _getch();
			int ch2 = _getch();
			int ch3;
			if (ch2 == 224) ch3 = ch1;
			else ch3 = ch2;
			switch (ch3)
			{
			case 80:ch = 0; break;
			}
		}
	}
}


void titleA()
{
	cout << "\n\n\n\n\t\t\t\t\t��δ����!!!" << endl;
	cout << "\n\n\t\t\t\t\t�����ڴ�!!!" << endl;
	cout << "\n\n\t\t\t\t\tQQ��372207098" << endl;
}


void titleB()
{
	cout << "\n\n\n\n\t\t\t\t\t��δ����!!!" << endl;
	cout << "\n\n\t\t\t\t\t�����ڴ�!!!" << endl;
	cout << "\n\n\t\t\t\t\tQQ��372207098" << endl;
}


void titleC()
{
	cout << "\n\n\n\n\t\t\t\t\t��δ����!!!" << endl;
	cout << "\n\n\t\t\t\t\t�����ڴ�!!!" << endl;
	cout << "\n\n\t\t\t\t\tQQ��372207098" << endl;
}


void titleD()
{
	cout << "\n\n\n\n\t\t\t\t\t��δ����!!!" << endl;
	cout << "\n\n\t\t\t\t\t�����ڴ�!!!" << endl;
	cout << "\n\n\t\t\t\t\tQQ��372207098" << endl;
}



