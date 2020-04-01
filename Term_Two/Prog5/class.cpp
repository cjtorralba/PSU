#include "header.h"



//so we can copy classes easily
void myClass::copy(myClass* toCopy)
{
	name = new char[strlen(toCopy->name) + 1];
	strcpy(name, toCopy->name);
}



//destructor for node
node::~node()
{
	delete next;
}


//constructor for graph, sets everything to nULL
graph::graph(int size)
{
	int i;

	list_size = size;
	list = new vertex[list_size];

	for(i = 0; i < list_size; ++i)
	{
		list[i].currentClass = NULL;
		list[i].head = NULL;
		list[i].tail = NULL;
	}
}


//destructor for graph
graph::~graph()
{
	for(int i = 0; i < list_size; ++i)
	{
		if(list[i].currentClass)
		{
			delete [] list[i].currentClass->name;

			if(list[i].head)
				delete list[i].head;
		}
	}
	delete [] list;

}



//finds the location of a class based off the class name
int graph::findLocation(char* key)
{
	int position = -1;
	int count;
	bool found = false;

	for(count = 0; count < list_size; ++count)
	{
		if(list[count].currentClass && strcmp(key, list[count].currentClass->name) == 0)
			position = count;
	}		
	return position;
}





//traverses through the adjacency list
bool graph::traverse(char* name)
{

	int current = findLocation(name);
	vertex* currentVert = &list[current];

	node* cur = currentVert->head;


	if(!cur)
	{
		cout << "Last class in this path is " << list[current].currentClass->name << endl;
		return false;
	}
	else
	{
		cout << "In else rn " << endl;
			do
			{
				cout << "You can take " << list[cur->adjacent].currentClass->name << " after " << name << endl;
				traverse(list[cur->adjacent].currentClass->name);
				cur = cur->next;
			}while(cur != NULL);
			
	}
	return true;
}





/*

   for(int i = 0; i < list_size; ++i)
   {
   if(list[i].currentClass  && (strcmp(name, list[i].currentClass->name) == 0))
   {
   cout << list[i].currentClass->name << " " << endl;
   cout << "After this you can take ";
   node* cur = list[
   while(cur->next != NULL)
   {
   connected = true;
   cout << "Calling traverse on " << cur->adjacent->currentClass->name << endl;
   if(cur->adjacent->currentClass)
   traverse(cur->adjacent->currentClass->name);
   cur = cur->next;
   }

   }


   }

   return true;
   }

*/



//inserts a vertex of users choice
bool graph::insertVertex(myClass* to_insert)
{
	bool inserted = false;
	int count = 0;

	while(!inserted && (count < list_size))
	{
		if(!list[count].currentClass)
		{
			inserted = true;
			list[count].currentClass = new myClass;
			list[count].currentClass->copy(to_insert);
			list[count].head = NULL;

		}
		++count;
	}
	return inserted;
}

/*
   int graph::test(int i)
   {



   node* cur;
   for(int j = 0; j < list_size; ++j)
   {
   cout << list[j].currentClass->name << " at position " << j << endl;
   cur = list[j].head;
   while(cur != NULL)
   {
   cout << cur->adjacent->currentClass->name << endl;
   cur = cur->next;
   }

   }

   node* cur;
   k
   for(cur = list[i].head; cur != NULL; cur = cur->next)
   cout << cur->adjacent->currentClass->name << endl;
   if(!cur)
   cout << "WHY is this happenening" << endl;
   return i;

*/


//inserts an edge between two vertecies
bool graph::insertEdge(char* name, char* connect)
{
	int current = findLocation(name);
	int attach = findLocation(connect);

	if(current == -1 || attach == -1)
		return false;
	else
	{
		if(!list[current].head)
		{
			cout << "head is NULL" << endl;	
			list[current].head = new node;
			list[current].head->next = NULL;
			list[current].head->adjacent = attach;




			cout << "Attached " << list[current].currentClass->name << " to " << list[attach].currentClass->name << endl;
			return true;
		}
		else
		{
			list[current].tail = new node;
			list[current].tail->next = NULL;
			list[current].tail->adjacent = attach;
			list[current].tail = list[current].tail->next;

			cout << "Attached " << list[current].currentClass->name << " to " << list[attach].currentClass->name << endl;
			return true;
		}
	}






	/*

	   for(i = 0; i < list_size; ++i)
	   {
	   if(list[i].currentClass && strcmp(name, list[i].currentClass->name) == 0)
	   {
	   if(!list[i].head)
	   {
	   list[i].head = new node;
	   list[i].head->next = NULL;

	   cur = list[i].head;
	   }
	   else
	   {
	   cur = list[i].head;
	   while(cur != NULL)
	   cur = cur->next;

	   cur = new node;
	   cur->next = NULL;
	   }	

	   for(j = 0; j < list_size; ++j)
	   {
	   if(list[j].currentClass && strcmp(connect, list[j].currentClass->name) == 0)
	   {
	   cout << "connecting to " << list[j].currentClass->name << endl;
	   cur->adjacent = &list[j];
	   connected = true;
	   }
	   }
	   }
	   }
	   return connected;
	   */
}

/*
   bool graph::display()
   {
   bool full = false;
   myClass* cur;
   int i;

   for(i = 0; i < list_size; ++i)
   {
   if(list[i].currentClass)
   {
   full = true;

   cout << "Class: " << list[i].currentClass->name << endl;
   cout << "Pre Reqs: " << endl;

   cur = list[i].currentClass->head;

   while(cur->next != NULL)
   {
   cout << "\tClass: " << cur->name << endl;
   cur = cur->next;
   }

   }
   }
   return full;

   }
   */








