#include <iostream>
#include <cstring>
using namespace std;

struct node
{
	char* name;
	char* description;
	char* complete;
	int priority;
	node* next;
	~node();
};

class List
{
	public:
		List();	~List();

		bool add();
		bool remove(char search[]);

		node* getHead();	
		void display();
		void displayPriority(int priority, node* search);
		int length();
		bool release();
	private:
		node* head;
};
