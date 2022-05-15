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
		//написать функцию
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

		while (N != 0)
		{
			N->show();

			N = N->next;
		}
	}

	void reset()
	{
		//написать функцию
	}
};

int main()
{

}