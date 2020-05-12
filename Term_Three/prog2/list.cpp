#include "list.h"

//node class constructor taking the arrsize as an argument
node::node(int arrSize) : next(NULL), arrSize(arrSize)
{
	data = new base*[arrSize];
	for(int i = 0; i < arrSize; ++i)
		data[i] = NULL;
}

//noed class desturctos
node::~node()
{
	delete next;

	int i;
	for(i = 0; i < arrSize; ++i)
	{
		if(data[i])
		{
			delete data[i];
			data[i] = NULL;
		}
	}
}


//function for deleting a base class pointer using a name to match
bool node::deleteBase(char* match)
{
	int i;
	bool removed = false;

	for(i = 0; !removed && i < arrSize; ++i)
	{
		if(data[i] && strcmp(match, data[i]->getName()) == 0)
		{
			delete data[i];
			data[i] = NULL;
			removed = true;
		}
	}
	return removed;
}


//returns first matching base class pointer of the matching name
base* node::getNodeByName(char* name)
{
	bool found = false;
	base* temp = NULL;
	int i;

	for(i = 0; !found && i < arrSize; ++i)
	{
		if(data[i] && strcmp(name, data[i]->getName()) == 0)
		{
			found = true;
			temp = data[i];
		}
	}
	return temp;
}


//displays all elements in the array
void node::displayAll()
{
	for(int i = 0; i < arrSize; ++i)
		if(data[i] != NULL)
		{
			data[i]->display();
			cout << endl;
		}
}


//returns the priority of the element in given position
int node::getPriority(int position)
{
	return data[position]->getPriority();	
}


//returns if the last element is null in the list
bool node::isFull()
{
	return !(data[arrSize-1] == NULL);
	//if the last element in the array is not NULL then the array is full
}

//returns next pointer
node*& node::goNext()
{
	return next;
}


//adds a swim class
void node::addSwim(swim* toAdd)
{
	int i;
	bool inserted = false;
	for(i = 0; !inserted && i < arrSize; ++i)
	{
		if(data[i] == NULL)
		{
			data[i] = new swim(*toAdd);
			inserted = true;
		}
	}
}

//adds a work class
void node::addWork(work* toAdd)
{
	int i;
	bool inserted = false;

	for(i = 0; !inserted && i < arrSize; ++i)
	{
		if(data[i] == NULL)
		{
			data[i] = new work(*toAdd);
			inserted = true;
		}
	}
}

//adds a hiking class1
void node::addHike(hike* toAdd)
{
	int i;
	bool inserted = false;
	for(i = 0; !inserted && i < arrSize; ++i)
	{
		if(data[i] == NULL)
		{
			data[i] = new hike(*toAdd);
			inserted = true;
		}
	}
}


//returns the poitners at n position in the array
base*& node::getPosition(int position)
{
	return this->data[position];
}



//chose 5 as size of our arrays just because
list::list() : arrSize(5), head(NULL), tail(NULL) {}


//list detructor
list::~list()
{
	if(head)
		delete head;
	head = NULL;
	tail = NULL;

}


//function to delete a base class pointer form the LLL
bool list::deleteBase(char* match)
{
	node* cur;
	bool removed = false;

	if(head)
		for(cur = head; !removed && cur != NULL; cur = cur->goNext())
			removed = cur->deleteBase(match);
}


//returns first matching base pointer with name
base* list::getNodeByName(char* name)
{
	bool found = false;
	node* cur;
	base* toReturn = NULL;

	if(!head)
		return NULL;
	else
	{
		for(cur = head; !found && cur != NULL; cur = cur->goNext())
		{
			toReturn = cur->getNodeByName(name);
			if(toReturn != NULL)
				found = true;
		}
	}

	return toReturn;
}


//displays all nodes
void list::display()
{
	if(head)
	{
		for(node* cur = head; cur != NULL; cur = cur->goNext())
			cur->displayAll();
	}
}


//adds a swim object
void list::addSwim(swim* toAdd)
{

	if(!head)	//head is null so there is no data anywhere
	{
		head = new node(arrSize);
		head->addSwim(toAdd);
	}

	else if(head->isFull())
	{
		node* temp = head;
		head = new node(arrSize);

		head->goNext() = temp;

		head->addSwim(toAdd);

	}
	else
		head->addSwim(toAdd);


}


//adds a hike object
void list::addHike(hike* toAdd)
{

	if(!head)	//head is null so there is no data anywhere
	{
		head = new node(arrSize);
		head->addHike(toAdd);
	}

	else if(head->isFull())
	{
		node* temp = head;
		head = new node(arrSize);

		head->goNext() = temp;

		head->addHike(toAdd);

	}
	else
		head->addHike(toAdd);



}


//adds a work object
void list::addWork(work* toAdd)
{
	if(!head)	//head is null so there is no data anywhere
	{
		head = new node(arrSize);
		head->addWork(toAdd);
	}

	else if(head->isFull())
	{
		node* temp = head;
		head = new node(arrSize);

		head->goNext() = temp;

		head->addWork(toAdd);

	}
	else
		head->addWork(toAdd);
}


