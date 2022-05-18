#include <iostream>
#include <string>

using namespace std;

class Node
{
private:
	string FIO;
	string Work_position;
	string Adress;

public:
	Node* next;
	Node* prev;

	Node(string FIO = "", string Work_position = "", string Adress = "")
	{
		this->FIO = FIO;
		this->Work_position = Work_position;
		this->Adress = Adress;

		this->next = 0;
		this->prev = 0;
	}

	string get_FIO()
	{
		return FIO;
	}
	string get_Work_position()
	{
		return Work_position;
	}
	string get_Adress()
	{
		return Adress;
	}

	void show()
	{
		cout << FIO << " " << Work_position << " " << Adress << endl;
	}

	void reset()
	{
		FIO = "";
		Work_position = "";
		Adress = "";
	}
};

class List
{
private:
	Node* first;
	Node* last;

	Node** push(Node** A, int count, Node* new_element)
	{
		Node** B = new Node * [count + 1];//массив на один элемнт больше

		for (size_t i = 0; i < count; i++)//копируем старый массив
		{
			B[i] = A[i];
		}
		B[count - 1] = new_element;//добавляем в конец новый элемент

		return B;//возвращаем новый массив
	}

	void push_node(Node* N)
	{
		if (is_empty())
		{
			first = N;
			last = N;
		}
		else
		{
			last->next = N;
			N->prev = last;
			last = N;
		}
	}

	void insert_node(Node* N, int Number)
	{
		Node* C = first;

		if (Number == 0)// для начала 
		{
			N->next = first;
			first->prev = N;
			first = N;
			return;
		}

		for (size_t i = 0; i < Number; i++)
		{
			if (C == 0)
			{
				cout << "Индекс " << Number << " не существует";
				break;
			}
			if (i + 1 == Number)
			{
				if (C == last)//для конца
				{
					return push_node(N);
				}

				N->next = C->next;
				C->next->prev = N;
				N->prev = C;
				C->next = N;
			}

			C = C->next;
		}
	}

public:
	List()
	{
		first = 0;
		last = 0;
	}

	bool is_empty()
	{
		return first == 0;
	}

	void push_back(string FIO, string Work_position, string Adress)
	{
		Node* N = new Node(FIO, Work_position, Adress);
		
		if (is_empty())
		{
			first = N;
			last = N;
		}
		else
		{
			last->next = N;
			N->prev = last;
			last = N;
		}
	}

	Node** find_Work_position(string W)
	{
		Node* N = first;
		Node** Arr = 0;
		int count = 0;

		while (N != 0)
		{
			if (N->get_Work_position() == W)
			{
				Arr = push(Arr, count, N);
				count++;
			}

			N = N->next;
		}

		return Arr;
	}

	Node** find_FIO(string W)
	{
		Node* N = first;
		Node** Arr = 0;
		int count = 0;

		while (N != 0)
		{
			if (N->get_FIO() == W)
			{
				Arr = push(Arr, count, N);
				count++;
			}

			N = N->next;
		}

		return Arr;
	}

	Node** find_Adress(string W)
	{
		Node* N = first;
		Node** Arr = 0;
		int count = 0;

		while (N != 0)
		{
			if (N->get_Adress() == W)
			{
				Arr = push(Arr, count, N);
				count++;
			}

			N = N->next;
		}

		return Arr;
	}

	void show()
	{
		Node* N = first;
		int i = 1;

		while (N != 0)
		{
			cout << i << ")";
			N->show();

			N = N->next;
			i++;
		}
		cout << endl;
	}

	void rshow()
	{
		Node* N = last;
		int i = 1;

		while (N != 0)
		{
			cout << i << ")";
			N->show();

			N = N->prev;
			i++;
		}
		cout << endl;
	}

	void reset()
	{
		Node* N = first;

		while (N != 0)
		{
			N->reset();

			N = N->next;
		}
	}

	void insert(int Number, string FIO, string Work_position, string Adress)
	{
		Node* N = new Node(FIO, Work_position, Adress);
		Node* C = first;

		if (Number == 0)// для начала 
		{
			N->next = first;
			first->prev = N;
			first = N;
			return;
		}

		for (size_t i = 0; i < Number; i++)
		{
			if (C == 0)
			{
				cout << "Индекс " << Number << " не существует";
				break;
			}

			if (i + 1 == Number)
			{
				if (C == last)//для конца
				{
					return push_node(N);
				}

				N->next = C->next;
				C->next->prev = N;
				N->prev = C;
				C->next = N;
			}

			C = C->next;
		}
	}

	Node* pop(int Number)//Учитывать начало и конец списка
	{
		Node* C = first;

		if (Number == 0)
		{
			first->next->prev = 0;
			first = first->next;

			C->next = 0;
			return C;
			
		}

		for (size_t i = 0; i < Number; i++)
		{
			if (C == 0)
			{
				cout << "Индекс " << Number << " не существует";
				break;
			}
			if (i + 1 == Number)
			{
				if (C == last)
				{
					C->prev->next = 0;
					last = C->prev;
					C->prev = 0;

					return C;
				}

				C->prev->next = C->next;
				C->next->prev = C->prev;

				C->next = 0;
				C->prev = 0;

				return C;
			}

			C = C->next;
		}
	}

	void Swap_el(int N1, int N2)
	{// 1 2  4 5  7 8 9 10
		if (N1 > N2) swap(N1, N2);

		Node* Ptr2 = pop(N2-1);
		Node* Ptr1 = pop(N1-1);

		insert_node(Ptr2, N1 - 1);
		insert_node(Ptr1, N2 - 1);
	}

	void Sort_Work_position()
	{
		Node* C = first;
		Node* C2 = first->next;

		for (size_t i = 0; C != last; i++)
		{
			for (size_t j = 0;C2 != 0 ; j++)
			{
				if (C->get_Work_position() < C2->get_Work_position())
				{
					Swap_el(i, j);
				}
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	List A;
	Node* B;

	A.push_back("Roma", "CEO", "BBBBB");
	A.push_back("Vanya", "Director", "BBBBB");
	A.push_back("Anna", "Worker", "BBBBB");
	A.push_back("Roma", "AAAAA", "BBBBB");

	A.Swap_el(1, 3);
	A.show();
}