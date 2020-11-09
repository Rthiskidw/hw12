#ifndef qeue_h
#define qeue_h

template <typename T>
class Queue
{
public:
	virtual bool isEmptyQueue() const = 0;
	virtual bool isFullQueue() const = 0;
	virtual void emptyQueue() = 0;
	virtual T front() const = 0;
	virtual T back() const = 0;
	virtual void enQueue(const T& queueElement) = 0;
	virtual void deQueue() = 0;
	virtual void printQ() = 0;
	virtual int getSize() = 0;
	
//no private data members because this is an ABC
};
	

#endif /* qeueClass_h */
