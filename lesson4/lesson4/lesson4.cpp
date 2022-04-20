#include "funcs.h"
#include <limits>

int main()
{
	setlocale(LC_ALL, "Rus");
	ifstream file("data.txt");
	char ch = 0;
	ofstream rez;

	lesson U;

	U.input_cf();
	U.output_cf();


	if (U.cf_1)
	{
		cout << "Введите название фаила для вывода: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, U.S);
		if (U.S == "")
		{

		}
		else
		{
			if (U.S.find(".txt") == -1)
			{
				U.S.append(".txt");
			}
			U.filename = U.S;
		}

	}
	
	if (U.cf)// file input
	{
		while (!file.eof())
		{
			ch = file.get(); // из файла берем символ и в конец S засовываем
			U.S.push_back(ch);
		}

		U.analiz();
	}
	else// console input
	{
		cout << "Введите строку элементов: \n";
		cin.ignore();
		getline(cin, U.S);

		U.analiz();
	}

	U.vivod();
}