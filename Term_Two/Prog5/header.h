#include <iostream>
#include <cstring>
#include <cctype>




/* code by christian torralba for cs163
 * this is supposed to be a lay out of classes and pre requisites
 * uses the graph ADT
 */


using namespace std;


struct vertex
{
	struct myClass* currentClass;	//pointer to class object

	struct node* head;		//head of adjacency list
	struct node* tail;		//tail of adjacency list
};

struct node
{
	int adjacent;	//position in the index of the adjacent class
	node* next;	//next pointer for LLL
	~node();	//node desturcotor
};

struct myClass
{
	char* name;	//name of class
	void copy(myClass* to_copy);	//copies classes 
};

class graph
{

	public:
		graph(int size = 10);	~graph();	//constructor and destructor
		bool insertVertex(myClass* to_insert);		//inserts a vertex
		bool insertEdge(char* name, char* connect);	//inserts an edge with the name and the naem of the class you wish to connect to
//		bool display(void);
		int test(int i);
		bool traverse(char* name);	//traverses based off name you give it
		int findLocation(char* key);	//finds location of given class

	private:
		vertex* list;	//list of verticies
		int list_size;
};
