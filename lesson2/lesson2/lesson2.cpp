﻿#include "funcs.h"
#include "constants.h"
// 1 1 1 1 2 3 1 5
bool lower_arr(int* S, int N, int& index_S)
{
	bool check = false;
	index_S = 0;

	for (int i = 0; i < N - 1; i++)
	{
		if (S[i] > S[i + 1])
		{
			check = false;// неубывающий
			break;
		}
		if (S[i] < S[i + 1])
		{
			check = true;// невозрастающий
			break;
		}
	}

	for (int i = 0; i < N - 1; i++)//вычисление индекса (m+1) 
	{
		if (check)
		{
			if (S[i] > S[i + 1])
			{
				index_S = i + 1;
				break;
			}
		}
		else
		{
			if (S[i] < S[i + 1])
			{
				index_S = i + 1;
				break;
			}
		}
	}

	return check;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	while (true)
	{
		ifstream file("data.txt");
		ofstream rez("solution.txt");
		bool low_more;
		int N{ 0 };
		int mpo{ 0 }; // m plus one

		int inp_cf = input_cf();
		int out_cf = output_cf();

		int S[NM];

		if (!inp_cf) // ввод с консоли
		{
			N = cin_natural();

			for (int i = 0; i < N; i++) // запись массива
			{
				cout << "Введите элемент номер №" << i + 1 << ": " << endl;
				cin >> S[i];
			}
		}
		else
		{
			file >> N;

			for (int i = 0; i < N; i++)
			{
				file >> S[i];
			}
		}

		//анализ
		low_more = lower_arr(S, N, mpo);
		if (mpo == 0) mpo = N;

		if (!out_cf)
		{
			cout << "Подмассив имеет вид: \n";

			for (int i = 0; i < mpo; i++)
			{
				cout << S[i] << " "; // выводим элементы массива
			}
		}

		else
		{
			rez << "Подмассив имеет вид: \n";

			for (int i = 0; i < mpo; i++)
			{
				rez << S[i] << " "; // выводим элементы массива
			}
		}

		if (!out_cf)
		{
			string buff("");

			while (true)
			{
				cout << "\nПовторить программу? 0 - нет, 1 - да\n";
				cin >> buff;

				if (buff != "0" && buff != "1")
				{
					system("cls");
					cout << "Неверные вводные данные, попробуйте снова...\n";
					continue;
				}
				break;
			}
			if (buff == "1")
			{
				system("cls");
				continue;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}

		return 0;
	}
}