#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;


struct vertex
{
	struct myClass* currentClass;

	struct node* head;	
	struct node* tail;
};

struct node
{
	int adjacent;
	node* next;
};

struct myClass
{
	char* name;
//	myClass* next;	// this is the list of required classes for any given class
	void copy(myClass* to_copy);
};

class graph
{

	public:
		graph(int size = 10);	//~graph();
		bool insertVertex(myClass* to_insert);
		bool insertEdge(char* name, char* connect);
//		bool display(void);
		int test(int i);
		bool traverse(char* name);
		int findLocation(char* key);

	private:
		vertex* list;
		int list_size;


};
