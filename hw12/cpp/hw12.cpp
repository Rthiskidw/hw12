#include <iostream>
#include "queue.h"
#include "arrayQueue.h"
using namespace std;

int main(int argc, const char * argv[])
{
	cout << "************************************** " << endl;
	cout << "*           Running HW10             * " << endl;
	cout << "*      Programmed by Reed Wilson     * " << endl;
	cout << "*          CS1C T/TH 12:30           * " << endl;
	cout << "************************************** " << endl;
	cout << endl;
	
	
    //testing int queue
	arrayQueue<int> myarrayQInt(10);

	cout << "*****INT QUEUE TEST*****" << endl;
	for(int i = 0; i < 6; i++)
	{
		myarrayQInt.enQueue(i);
	}
	myarrayQInt.printQ();
	
	for(int i = 0; i < 4; i++)
	{
		myarrayQInt.deQueue();
	}
	myarrayQInt.printQ();
	
	for(int i = 0; i < 5; i++)
	{
		myarrayQInt.enQueue( i + 6);
	}
	myarrayQInt.printQ();
	
	for(int i = 0; i < 3; i++)
	{
		myarrayQInt.deQueue();
	}
	myarrayQInt.printQ();
	
	
	arrayQueue<double> myarrayQIntDouble(10);
	//testing double queue
	cout << "\n*****DOUBLE QUEUE TEST*****" << endl;
	for(int i = 0; i < 6; i++)
	{
		myarrayQIntDouble.enQueue(i + .25);
	}
	myarrayQIntDouble.printQ();
	
	for(int i = 0; i < 4; i++)
	{
		myarrayQIntDouble.deQueue();
	}
	myarrayQIntDouble.printQ();
	
	for(int i = 0; i < 5; i++)
	{
		myarrayQIntDouble.enQueue( i + 6.25);
	}
	myarrayQIntDouble.printQ();
	
	for(int i = 0; i < 3; i++)
	{
		myarrayQIntDouble.deQueue();
	}
	myarrayQIntDouble.printQ();
	
	//Adding to a full queue
	arrayQueue<char>myQ(5);
	cout << "\n*****Adding to full queue...*****" << endl;
	myQ.enQueue('a');
	myQ.enQueue('b');
	myQ.enQueue('c');
	myQ.enQueue('d');
	myQ.enQueue('e');
	myQ.enQueue('f');//adding 6th element to array wiht size 5
	
	//testing isEmpty and isFull
	cout << "\n*****Testing isEmpty and isFull*****" << endl;
	//emptying the queue
	myQ.deQueue();
	myQ.deQueue();
	myQ.deQueue();
	myQ.deQueue();
	myQ.deQueue();
	
	if (myQ.isEmptyQueue())
	{
		cout << "QUEUE IS EMPTY!" << endl;
	}else
	{
		cout << "QUEUE NOT EMPTY!" << endl;
	}
	
	//filling the queue
	myQ.enQueue('a');
	myQ.enQueue('b');
	myQ.enQueue('c');
	myQ.enQueue('d');
	myQ.enQueue('e');
	
	if (myQ.isFullQueue())
	{
		cout << "QUEUE IS FULL!" << endl;
	}else
	{
		cout << "QUEUE NOT FULL!" << endl;
	}
	
	//testing front and back methods
	cout << "\n*****Testing front and back methods*****" << endl;
	cout << myQ.front() << " is at the front" << endl;
	cout << myQ.back() << " is at the back" << endl;
	return 0;
}
