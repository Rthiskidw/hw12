#ifndef arrayQeue_h
#define arrayQeue_h
#include "queue.h"
#include <iostream>
/*----------------------------------------------------------------
       ***************** arrayQueue Class *******************
	This derived class implements the Queue using an array
	and ovverrides all of the ABC's pure virtual functions.
	This class is templetad as well and allows us to use
	to make a queue for any data type that we want.
*----------------------------------------------------------------*/

template<typename T>
class arrayQueue : public Queue<T>
{
public:
	/*________________________________________________________________
		bool isEmptyQueue() const;
	_________________________________________________________________
		POST-CONDITIONS:
		returns a bool telling us if queue is empty
	_________________________________________________________________*/
	bool isEmptyQueue() const;
	
	/*________________________________________________________________
		bool isFullQueue() const;
	_________________________________________________________________
		POST-CONDITIONS:
		returns a bool telling us if queue is full
	_________________________________________________________________*/
	bool isFullQueue() const;
	
	/*________________________________________________________________
		void emptyQueue();
	_________________________________________________________________
		POST-CONDITIONS:
		the queue is emptied and font/back are reset to zero
	_________________________________________________________________*/
	void emptyQueue();
	
	/*________________________________________________________________
		T front() const;
	_________________________________________________________________
		POST-CONDITIONS:
		returns a T type of the element at the front fo the queue
	_________________________________________________________________*/
	T front() const;
	
	/*________________________________________________________________
		T back() const;
	_________________________________________________________________
		POST-CONDITIONS:
		returns a T type of the element at the back of the queue
	_________________________________________________________________*/
	T back() const;
	
	/*________________________________________________________________
		void enQueue(const T& queueElement);
	_________________________________________________________________
		PRE-CONDITIONS:
		a queue without this added element
	 
		POST-CONDITIONS:
		a queue with this new element appended to the back
	_________________________________________________________________*/
	void enQueue(const T& queueElement);
	
	/*________________________________________________________________
		void deQueue() ;
	_________________________________________________________________
		PRE-CONDITIONS:
		a queue with the front element still there
	 
		POST-CONDITIONS:
		a queue with this front element taken off
	_________________________________________________________________*/
	void deQueue() ;
	
	/*________________________________________________________________
		void printQ();
	_________________________________________________________________
		POST-CONDITIONS:
		prints out the contents of the queue from the front to back
	_________________________________________________________________*/
	void printQ();
	
	/*________________________________________________________________
		int getSize();
	_________________________________________________________________
		POST-CONDITIONS:
		returns the size of the queue
	_________________________________________________________________*/
	int getSize();
	
	/*________________________________________________________________
		arrayQueue(int size);
	_________________________________________________________________
		POST-CONDITIONS:
		creates an arrayQueue object with a max size that is given
	_________________________________________________________________*/
	arrayQueue(int size);//alternate constructor
	
	/*________________________________________________________________
		~arrayQueue(){delete qArray;}
	_________________________________________________________________
		POST-CONDITIONS:
		deallocated the memory for the qArray
	_________________________________________________________________*/
	~arrayQueue(){delete qArray;}//destructor
	
	/*________________________________________________________________
		arrayQueue(const arrayQueue & otherArray);
	_________________________________________________________________
		POST-CONDITIONS:
		creates a copy of another arrayQueue object including the
		pointed to data (the array)
	_________________________________________________________________*/
	arrayQueue(const arrayQueue & otherArray);//copy constructor
	
	/*________________________________________________________________
		void operator=(const arrayQueue &otherArray);
	_________________________________________________________________
		POST-CONDITIONS:
		assigns the contents of the other array to the object on the
		left hand side. Using same methods as above copy constructor.
	_________________________________________________________________*/
	void operator=(const arrayQueue &otherArray);//overloaded assignment oeprator
private:
	int maxSize; //the max size of the queue
	int qsize;   //the current size of queue
	int qfront;  //the index of the front
	int qback;   //the index of the back
	T* qArray;   //the T type pointer that points to array
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
