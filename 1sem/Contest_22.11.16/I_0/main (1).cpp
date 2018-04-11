#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
	int value, minValue;
	struct Node *prev;
	Node(int value) : value(value), minValue(value), prev(0) { }
};
struct Stack
{
	Node *top;
	int size;
	Stack() : top(0), size(0) { }
};
void push_n(Stack *s, int n)
{
	++s->size;
	if (s->top == 0)
	{
		s->top = new Node(n);
		return;
	}
	Node *newNode = new Node(n);
	newNode->prev = s->top;
	s->top = newNode;
	if (s->top->prev->minValue < s->top->minValue)
		s->top->minValue = s->top->prev->minValue;
}
int pop(Stack *s)
{
	if (s->top == 0)
		return -1;
	--(s->size);
	int answer = s->top->value;
	Node *deleteNode = s->top;
	s->top = s->top->prev;
	delete deleteNode;
	return answer;
}
int back(Stack *s)
{
	if (s->top == 0)
		return -1;
	return s->top->value;
}
int min(Stack *s)
{
	if (s->top == 0)
		return -1;
	return s->top->minValue;
}
int size(Stack *s)
{
	return s->size;
}
void clear(Stack *s)
{
	while (s->top != 0)
	{
		pop(s);
	}
}

int main()
{
	int n;
	cin >> n;
	Stack **s = new Stack*[n];
	for (int i = 0; i < n; ++i)
	{
		s[i] = new Stack ();
	}
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		for (int j = 0; j < x; ++j)
		{
			int y;
			cin >> y;
			push_n(s[i], y);
		}
	}
	if (n == 1)
	{
		clear(s[0]);
		delete s[0];
		delete [] s;
		return 0;
	}
	if (n == 2)
	{
		int k = 0;
		while (s[0]->top != 0 &&  s[0]->top->value == 2)
		{
			push_n(s[1], pop(s[0]));
			++k;
		}
		while (s[1]->top != 0 && s[1]->top->value == 1)
		{
			push_n(s[0], pop(s[1]));
			--k;
		}
		bool flag = true;
		while (s[0]->top != 0)
		{
			if (pop(s[0]) != 1)
			{
				flag = false;
				break;
			}
		}
		while (s[1]->top != 0)
		{
			if (pop(s[1]) != 2)
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			if (k > 0)
			{
				for (int i = 0; i < k; ++i)
				{
					cout << "1 2" << endl;
				}
			}
			else
			{
				for (int i = 0; i < -k; ++i)
				{
					cout << "2 1" << endl;
				}
			}

		}
		else
		{
			cout << "0" << endl;
		}

	}
	else
	{

		for (int i = 1; i < n; ++i)
		{
			while (s[i]->top != 0)
			{
				cout << i + 1 << " 1" << endl;
				push_n(s[0], pop(s[i]));
			}
		}
		while (s[0]->top != 0)
		{
			if (back(s[0]) == 1)
			{
				cout << "1 2" << endl;
				push_n(s[1], pop(s[0]));
			}
			else
			{
				cout << "1 " << back(s[0]) << endl;
				int i = back(s[0]) - 1;
				push_n(s[i], pop(s[0]));
			}
		}
		while (s[1]->top != 0)
		{
			if (back (s[1]) == 1)
			{
				cout << "2 1" << endl;
				push_n(s[0], pop(s[1]));
			}
			else
			{
				cout << "2 3" << endl;
				push_n(s[2], pop(s[1]));
			}
		}
		while (s[2]->top && s[2]->top->value == 2)
		{
			cout << "3 2" << endl;
			push_n(s[1], pop(s[2]));
		}
	}
	for (int i = 0; i < n; ++i)
	{
		clear(s[i]);
		delete (s[i]);
	}
	delete[] s;
	return 0;
}
