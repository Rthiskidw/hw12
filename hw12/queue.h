#ifndef qeue_h
#define qeue_h
/*----------------------------------------------------------------
       ***************** Queue Class *******************
	This is an abstract base class  with all pure virtual functions
	This is a templated class and this uses the type name T. This
	ABC allows us to create derived classes that we can build queues
	with. In this homework I derived a class that implements the
	queue using an array. The power of templeting is in the way
	we can implement our queue using which ever method
	we want and still derive from the same ABC.
*----------------------------------------------------------------*/
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
