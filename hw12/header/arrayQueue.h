
#ifndef arrayQeue_h
#define arrayQeue_h
#include "queue.h"
#include <iostream>


template<typename T>
class arrayQueue : public Queue<T>
{
public:
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void emptyQueue();
	T front() const;
	T back() const;
	void enQueue(const T& queueElement);
	void deQueue() ;
	void printQ();
	int getSize();
	arrayQueue(int size);
	~arrayQueue(){delete qArray;}
private:
	int maxSize;
	int qsize;
	int qfront;
	int qback;
	T* qArray;
};
template <typename T>
void arrayQueue<T>:: printQ()
{
	if (qback < qfront)
	{
		for (int i = qfront; i < maxSize; i++)
		{
			std:: cout << qArray[i] << " ";
		}
		for (int i = 0; i <= qback; i++)
		{
			std:: cout << qArray[i] << " ";
		}
			
	}
	else
	{
		for (int i = qfront; i <= qback; i++)
		{
			std:: cout << qArray[i] << " ";
		}
	}
	std::cout << std::endl;
	
}

template <typename T>
int arrayQueue<T>:: getSize()
{
	return qsize;
}

template <typename T>
bool arrayQueue<T>::isEmptyQueue() const
{
	return (qsize == 0);
}

template <typename T>
bool arrayQueue<T>::isFullQueue() const
{
	return (qsize == maxSize);
}

template <typename T>
void arrayQueue<T>::emptyQueue()
{
	qsize = 0;
	qfront = 0;
	qback = maxSize - 1;;
}

template <typename T>
T arrayQueue<T>::front() const
{
	return qArray[qfront];
}

template <typename T>
T arrayQueue<T>::back() const
{
	return qArray[qback];
}

template <typename T>
void arrayQueue<T>::enQueue(const T& queueElement)
{
	if(!isFullQueue())
	{
		
	    qback = (qback + 1) % maxSize;
		qArray[qback] = queueElement;
		std::cout << "EQUEUEING..." << queueElement << std::endl;
		++qsize;
	}
	else
	{
		std::cout << "Cannot add... QUEUE IS FULL!" << std::endl;
	}
}

template <typename T>
void arrayQueue<T>::deQueue()
{
	if(!isEmptyQueue())
	{
		std::cout << "DEQUEUEING..." << front() << std::endl;
		qfront = (qfront + 1) % maxSize;
		--qsize;
		
	}
	else
	{
		std::cout << "Cannot add... QUEUE IS FULL!" << std::endl;
	}
}

template <typename T>
arrayQueue<T>::arrayQueue(int size)
{
	qArray = new T[size];
	maxSize = size;
	qsize = 0;
	qfront = 0;
	qback = maxSize - 1;
}
#endif /* arrayQeue_h */
