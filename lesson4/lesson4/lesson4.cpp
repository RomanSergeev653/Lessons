#include "funcs.h"
#include <limits>

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Rus");
	ifstream file;

	string S = "";
	string stroka = "";
	char ch = 0;
	int check = 0;
	int zap = 0;
	int tire = 0;
	int vv = 0;
	ofstream rez;

	string filename("solution.txt");
	string filename2("data.txt");

	bool cf = input_cf();
	bool cf_1 = output_cf();

	if (cf)
	{
		while (true)
		{
			cout << "Введите название фаила для ввода: ";
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
				filename2 = S;
			}

			file.open(filename2);
			if (file.is_open()) break;
			else
			{
				system("cls");
				cout << "Файл не существует, попробуйте заново\n";
				S.clear();
			}
		}
	}
	S.clear();

	if (cf_1)
	{
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

	if (cf_1) f_vivod(filename, check, zap, tire, vv);
	else c_vivod(check, zap, tire, vv);

	if (!cf_1)
	{
		string buff("");

		while (true)
		{
			cout << "Повторить программу? 0 - нет, 1 - да\n";
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
			return main();
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
}