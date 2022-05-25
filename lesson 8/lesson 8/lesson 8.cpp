#include "funcs.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	system("chcp 65001");
	system("cls");

	List A;
	A.load_List("data.txt");

	int switch_on;
	bool T = true;

	while (T)
	{
		cout << "1) Добавить новый элемент\n";
		cout << "2) Печать в прямом порядке\n";
		cout << "3) Печать в обратном порядке\n";
		cout << "4) Поиск\n";
		cout << "5) Сортировка\n";
		cout << "6) Изменение\n";
		cout << "7) Удаление\n";
		cout << "8) Сброс\n";
		cout << "9) Выход\n";

		cin >> switch_on;//cin_int
		switch (switch_on)
		{
		case 1:
		{
			int number;
			string FIO;
			string Work_position;
			string Adress;

			cout << "Number: ";
			cin >> number;
			cin.ignore();
			cout << "FIO: ";
			getline(cin, FIO);
			cout << "Work position: ";
			getline(cin, Work_position);
			cout << "Adress: ";
			getline(cin, Adress);
			cout << endl;

			A.insert(number - 1, FIO, Work_position, Adress);
			A.show();
			break;
		}
		case 2:
		{
			cout << "Печать в прямом порядке\n";
			A.show();
			break;
		}
		case 3:
		{
			cout << "Печать в обратном порядке\n";
			A.rshow();
			break;
		}
		case 4:
		{
			cout << "1) Именам\n2) Должности\n3) Адресам\n";
			int S;
			cin >> S;
			cin.ignore();
			switch (S)
			{
			case 1:
			{
				string W;
				cout << "Введите имя для поиска: ";
				getline(cin, W);
				cout << A.find_FIO(W) << endl;

				break;
			}
			case 2:
			{
				string W;
				cout << "Введите должность для поиска: ";
				getline(cin, W);
				cout << A.find_Work_position(W) << endl;

				break;
			}
			case 3:
			{
				string W;
				cout << "Введите адрес для поиска: ";
				getline(cin, W);
				cout << A.find_Adress(W) << endl;

				break;
			}
			default:
				break;
			}

			break;
		}
		case 5:
		{
			cout << "1) Именам\n2) Должности\n3) Адресам\n";
			int S;
			cin >> S;
			switch (S)
			{
			case 1:
			{
				A.Sort_FIO();
				A.show();

				break;
			}
			case 2:
			{
				A.Sort_Work_position();
				A.show();

				break;
			}
			case 3:
			{
				A.Sort_Adress();
				A.show();

				break;
			}
			default:
				break;
			}

			break;
		}
		case 6:
		{
			int Number;
			string FIO;
			string Work_position;
			string Adress;

			cout << "Введите номер изменяемого элемента\n";
			cin >> Number;

			cin.ignore();
			cout << "FIO: ";
			getline(cin, FIO);
			cout << "Work position: ";
			getline(cin, Work_position);
			cout << "Adress: ";
			getline(cin, Adress);

			A.Change(Number - 1, FIO, Work_position, Adress);
			A.show();
			break;
		}
		case 7:
		{
			int number;
			cout << "Введите номер для удаления: ";
			cin >> number;
			A.pop(number - 1);
			A.show();

			break;
		}
		case 8:
		{
			A.reset();
			A.show();

			break;
		}
		case 9:
		{
			A.Save("data.txt");
			T = 0;
		}
		default:
			break;
		}
	}

	return 0;
}