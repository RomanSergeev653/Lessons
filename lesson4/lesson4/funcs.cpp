#include "funcs.h"

void analiz(string S, int& check, int& zap, int& tire, int& vv)
{
	for (int i = 0; i < S.length() - 1; i++) // сам анализ
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

	rez << "Кол-во \",\" и \"-\" получилось ";
	rez << check;
	rez << "\nКол-во \",\" получилось ";
	rez << zap;
	rez << "\nКол-во \"-\" получилось ";
	rez << tire;
	rez << "\nКол-во мест, где идёт сначала \",\", а потом \"-\" получилось ";
	rez << vv;
	rez.close();
}