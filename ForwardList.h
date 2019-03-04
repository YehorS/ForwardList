#pragma once

template <typename T>
class ForwardList
{
public:

	ForwardList();
	~ForwardList();
	void pop_front();
	void push_front(T data);
	void insert(T data, int index);
	void remove(int index);
	void Clear();
	int GetSize();
	bool empty();

private:

	template <typename T>
	class Node {

	public:

		Node *pNext;
		T data;
		Node(T data = T(), Node *pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T> *head;
};

template <typename T>
ForwardList<T>::ForwardList()
{
	int Size = 0;
	head = nullptr;
}

template <typename T>
ForwardList<T>::~ForwardList()
{
	Clear();
}

template<typename T>
inline void ForwardList<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void ForwardList<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}


template<typename T>
inline void ForwardList<T>::insert(T data, int index)
{
	if (index == 0) {
		push_front(data);
	}
	else {
		Node<T> *temp = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->pNext;
		}

		temp->pNext = new Node<T>(data, temp->pNext);
		Size++;
	}
}

template<typename T>
inline void ForwardList<T>::remove(int index)
{
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T> *temp = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->pNext;
		}
		Node<T> *del = temp->pNext;
		temp->pNext = del->pNext;
		delete del;
		Size--;
	}
}

template<typename T>
inline void ForwardList<T>::Clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
int ForwardList<T>::GetSize()
{
	return Size;
}

template<typename T>
inline bool ForwardList<T>::empty()
{
	return Size == 0;
}