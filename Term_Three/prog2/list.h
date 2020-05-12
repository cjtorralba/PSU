#include "derived.h"




class node
{
	public:
		//constructor and copy constructor
		node(int arrSize);		~node();
		node(const node& toCopy);


		int getPriority(int position);	//returns the priority of the position at a certain index

		base*& getPosition(int position);	//return the address of a base class pointer at a certain index

		bool isFull();	//returns true if the array is full

		node*& goNext();	//returns the next pointer

		void displayAll();	//displays all nodes in a array

		base* getNodeByName(char* name);	//retrurns the first matching base class pointer by matching the name

		//functions for adding the children
		void addSwim(swim* toAdd);
		void addWork(work* toAdd);
		void addHike(hike* toAdd);

		//function to delete a base
		bool deleteBase(char* match);


	private:
		int arrSize;	//size of eadch array

		base** data;	//the array of base class pointers in all its glory
		node* next;	//next pointer
};

//list class
class list
{

	public:
		//constructor an destructor
		list();		~list();

		//returns th array size
		int getArrSize();

		//displayus all contents in all nodes
		void display();

		//functions to add children to the nodes
		void addSwim(swim* toAdd);
		void addWork(work* toAdd);
		void addHike(hike* toAdd);

		//returns the first matching base class by strmp name
		base* getNodeByName(char* name);

		//calls the node::deleteBase fucntions and deltes the first base with a matching name
		bool deleteBase(char* match);

	private:
		int arrSize;	//size of the array in each node

		node* head;	//head and tail pointers
		node* tail;
};
