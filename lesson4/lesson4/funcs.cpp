#include "funcs.h"

void analiz(string S, int& check, int& zap, int& tire, int& vv)
{
	for (int i = 0; i < S.length() - 1; i++) // ��� ������
	{
		if ((S[i] == ',') || (S[i] == '-'))
		{
			check += 1;
			if (S[i] == ',')
			{
				zap += 1;
			}
			if (S[i] == '-')
			{
				tire += 1;
			}
			if ((S[i] == ',') && (S[i + 1] == '-'))
			{
				vv += 1;
			}
		}
	}
}

void vivod(string filename, int check, int zap, int tire, int vv)
{
	ofstream rez(filename);

	rez << "���-�� \",\" � \"-\" ���������� ";
	rez << check;
	rez << "\n���-�� \",\" ���������� ";
	rez << zap;
	rez << "\n���-�� \"-\" ���������� ";
	rez << tire;
	rez << "\n���-�� ����, ��� ��� ������� \",\", � ����� \"-\" ���������� ";
	rez << vv;
	rez.close();
}

bool input_cf()
{
	string buff("");

	while (true)
	{
		cout << "�������� ��� ����� ������. 0 - �������, 1 - ����\n";
		cin >> buff;

		if (buff != "0" && buff != "1")
		{
			system("cls");
			cout << "�������� ������� ������, ���������� �����...\n";
			continue;
		}
		break;
	}

	return stoi(buff);
}

bool output_cf()
{
	string buff("");

	while (true)
	{
		cout << "�������� ��� ������ ������. 0 - �������, 1 - ����\n";
		cin >> buff;

		if (buff != "0" && buff != "1")
		{
			system("cls");
			cout << "�������� ������� ������, ���������� �����...\n";
			continue;
		}
		break;
	}

	return stoi(buff);
}

int cin_natural(string name)
{
	bool check;
	string buff = "";

	while (true)
	{
		check = false;
		cout << "������� ���������� " << name << ": ";
		cin >> buff;

		for (int i = 0; i < buff.length(); i++)
		{
			if (buff[i] < 48 || buff[i] > 57 || buff == "0")
			{
				system("cls");
				cout << buff << " - �� �������� ����������� ������\n";
				check = true;
				break;
			}
		}
		if (check) continue;

		return stoi(buff);
	}
}

float cin_float(string name)
{
	string buff = "";
	float f;

	while (true)
	{
		if (name.length() > 0)
		{
			cout << "������� ���������� " << name << ": ";
		}
		cin >> buff;

		try
		{
			f = stof(buff);
		}
		catch (invalid_argument e)
		{
			system("cls");
			cout << "������� �������� �� �������� �������������� ������\n";
			continue;
		}
		return f;
	}
}
