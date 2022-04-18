#include "funcs.h"

float Gorner(int N, float x, float* A)
{
	float* G = new float [N];
	G[0] = A[0];
	
	for (int i = 1; i < N; i++)
	{
		G[i] = (G[i - 1] * x) + A[i];
	}

	return G[N - 1];
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	float x;
	float* A;
	//cf - console or file
	bool in_cf = input_cf();
	bool out_cf = output_cf();

	ifstream file; 
	if (in_cf) file.open("data.txt");

	// получение N и x
	if (in_cf)
	{
		file >> N >> x;
	}
	else
	{
		N = cin_natural("N");
		x = cin_float("x");
	}
	
	A = new float[N];// получение массива А
	if (in_cf)
	{
		for (int i = 0; i < N; i++)
		{
			file >> A[i];
		}
		file.close();
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			A[i] = cin_float();
		}
	}

	//вывод
	if (out_cf)
	{
		ofstream OutF("solution.txt");
		OutF << Gorner(N, x, A);
		OutF.close();
	}
	else
	{
		cout << Gorner(N, x, A);
	}

	delete[] A;
	return 0;
}