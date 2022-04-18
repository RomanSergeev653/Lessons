#include "funcs.h"
#include <limits>

int main()
{
	setlocale(LC_ALL, "Rus");
	ifstream file("data.txt");
	
	string S = "";
	string stroka = "";
	char ch = 0;
	int check = 0;
	int zap = 0;
	int tire = 0;
	int vv = 0;
	ofstream rez;

	string filename("solution.txt");

	bool cf = input_cf();

	cout << "Введите название фаила для вывода: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, S);
	if (S == "")
	{

	}
	else
	{
		if (S.find(".txt") == -1)
		{
			S.append(".txt");
		}
		filename = S;
	}

	if (cf)// file input
	{
		while (!file.eof())
		{
			ch = file.get(); // из файла берем символ и в конец S засовываем
			S.push_back(ch);
		}

		analiz(S, check, zap, tire, vv);
	}
	else// console input
	{
		cout << "Введите строку элементов: \n";
		cin.ignore();
		getline(cin, S);

		analiz(S, check, zap, tire, vv);
	}

	vivod(filename, check, zap, tire, vv);
}