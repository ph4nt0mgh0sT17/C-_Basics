#include <iostream>

using namespace std;

int StackSize = 10;

struct Stack
{
	int Head;
	int *Content = new int[StackSize];
};

void Init(Stack &stack)
{
	stack.Head = 0;
}

void StackResize(Stack& stack)
{
	StackSize++;
	int *newStack = new int[StackSize];

	for (int i = 0; i < (StackSize - 1); i++)
	{
		newStack[i] = stack.Content[i];
	}

	stack.Content = newStack;
}
void Push(Stack &stack, int number)
{
	if (stack.Head < StackSize)
	{

		stack.Content[stack.Head] = number;
		stack.Head++;

		if (stack.Head == StackSize)
		{
			StackResize(stack);
		}
	}

	else
	{
		cout << "Stack is full." << endl;
	}
}

int Pop(Stack &stack)
{
	if (stack.Head > 0)
	{
		stack.Head--;
		return stack.Content[stack.Head];
	}

	else
	{
		cout << "Stack is empty. " << endl;
		return -1;
	}
}

int QueueSize = 10;

struct Queue
{
	int Head;
	int Tail;
	int *Content = new int[QueueSize];
};

void Init(Queue &q)
{
	q.Head = 0;
	q.Tail = 0;
}

bool IsEmpty(Queue &q)
{
	return q.Head == q.Tail;
}

void QueueResize(Queue& queue)
{
	QueueSize++;
	int *newQueue = new int[QueueSize];

	for (int i = 0; i < (QueueSize - 1); i++)
	{
		newQueue[i] = queue.Content[i];
	}



	queue.Content = newQueue;
}

void Enqueue(Queue &q, int number)
{
	if (q.Tail < QueueSize)
	{
		q.Content[q.Tail] = number;
		q.Tail++;

		if (q.Tail == QueueSize)
		{
			QueueResize(q);
		}
	}

	else
	{
		cout << "Queue is full." << endl;
	}
}

int Dequeue(Queue &q)
{
	if (!IsEmpty(q))
	{
		int number = q.Content[q.Head];
		q.Content[q.Head] = 0;
		q.Head++;

		return number;
	}

	else
	{
		cout << "Queue is empty. " << endl;
		return -1;
	}
}



int main()
{
	cout << "Stack:" << endl;
	Stack stack;

	Init(stack);

	for (int i = 0; i < 50; i++)
	{
		Push(stack, i);
	}

	for (int i = 0; i < StackSize-1; i++)
	{
		cout << Pop(stack) << endl;
	}

	cout << endl << endl;

	cout << "Queue:" << endl;
	Queue queue;

	Init(queue);

	for (int i = 0; i < 50; i++)
	{
		Enqueue(queue, i);
	}

	for (int i = 0; i < QueueSize - 1; i++)
	{
		cout << Dequeue(queue) << endl;
	}
	system("pause");

	return 0;
}
