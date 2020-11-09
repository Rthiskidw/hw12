
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
	arrayQueue(const arrayQueue & otherArray);//copy constructor
	void operator=(const arrayQueue &otherArray);//overloaded assignment oeprator
private:
	int maxSize;
	int qsize;
	int qfront;
	int qback;
	T* qArray;
};

template <typename T>
arrayQueue<T>::arrayQueue(const arrayQueue &otherArray)//copy constructor
{
	maxSize = otherArray.maxSize;
	qfront  =  otherArray.qfront;
	qback  =  otherArray.qback;
	qArray = new T[otherArray.maxSize]; //creating array of same size
	
	//fills new copy of array
	if (qback < qfront)//special case when back as wrapped arround ahead of front
	{
		for (int i = qfront; i < maxSize; i++)
		{
			qArray[i] = otherArray.qArray[i];
		}
		for (int i = 0; i <= qback; i++)
		{
			qArray[i] = otherArray.qArray[i];
		}
	}
	else
	{
		for (int i = qfront; i <= qback; i++)
		{
			qArray[i] = otherArray.qArray[i];
		}
	}
}

template <typename T>
void arrayQueue<T>:: operator=(const arrayQueue &otherArray)//copy constructor
{
	maxSize = otherArray.maxSize;
	qfront  =  otherArray.qfront;
	qback   =  otherArray.qback;
	delete  []qArray;
	qArray = new T[otherArray.maxSize]; //creating array of same size
	
	//fills new copy of array
	if (qback < qfront)//special case when back as wrapped arround ahead of front
	{
		for (int i = qfront; i < maxSize; i++)
		{
			qArray[i] = otherArray.qArray[i];
		}
		for (int i = 0; i <= qback; i++)
		{
			qArray[i] = otherArray.qArray[i];
		}
	}
	else
	{
		for (int i = qfront; i <= qback; i++)
		{
			qArray[i] = otherArray.qArray[i];
		}
	}
	
}

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
	qArray = new T[size]{0};
	maxSize = size;
	qsize = 0;
	qfront = 0;
	qback = maxSize - 1;
}
#endif /* arrayQeue_h */