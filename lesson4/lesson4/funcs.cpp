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