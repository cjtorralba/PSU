#include "derived.h"




class node
{
	public:
		node(int arrSize);		//~node();
		node(const node& toCopy);

		void createNewArray();
		int getPriority(int position);

		base*& getPosition(int position);

		bool isFull();

		node*& goNext();

		void displayAll();

		base* getNodeByName(char* name);

		void addSwim(swim* toAdd);
		void addWork(work* toAdd);
		void addHike(hike* toAdd);

		bool deleteBase(char* match);


	private:
		int arrSize;

		base** data;
		node* next;
};

class list
{

	public:
		list();		~list();
		int getArrSize();

		void display();

		void addSwim(swim* toAdd);
		void addWork(work* toAdd);
		void addHike(hike* toAdd);

		base* getNodeByName(char* name);

		bool deleteBase(char* match);



	private:

		int arrSize;
		node* head;
		node* tail;
};
