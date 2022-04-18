#include "funcs.h"

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

	bool cf = 0;
	cout << "Ввод с файла(0) или с консоли(1): ";
	while (true)//console or file
	{
		cin >> S;
		if (S.length() != 1)
		{
			system("cls");
			cout << "Неправильный ввод, повторите снова... \nВвод с файла(0) или с консоли(1): ";
			continue;
		}
		if (S[0] == '0')
		{
			cf = 0;
			break;
		}
		if (S[0] == '1')
		{
			cf = 1;
			break;
		}

		system("cls");
		cout << "Неправильный ввод, повторите снова... \nВвод с файла(0) или с консоли(1): ";
	}

	cout << "Введите название фаила для вывода: ";
	cin >> S;
	if (S.find(".txt") == -1)
	{
		S.append(".txt");
	}
	rez.open(S);
	if (!rez.is_open())
	{
		system("cls");
		cout << "Фаил не найден, поэтому будет использоваться фаил по умолчанию... \n";
	}
	else
	{
		filename = S;
		rez.close();
	}
	S.clear();

	if (!cf)// file input
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
		getline(cin, S);

		analiz(S, check, zap, tire, vv);
	}

	vivod(filename, check, zap, tire, vv);
}