#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct node
{
	char* name;
	char* description;
	char* complete;
	int* priority;
	node* next;
	~node();
};

class List
{
	public:
		List();	~List();

		node* getHead();	

		//void initFile();
		//bool writeToFile();

		bool add();
		bool remove(char search[]);

		void display();
		void displayPriority(int priority, node* search);

		int length();


		//bool test();
	private:
		node* head;
};
