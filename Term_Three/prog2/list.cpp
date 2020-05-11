#include "list.h"


node::node(int arrSize) : next(NULL), arrSize(arrSize)
{
	data = new base*[arrSize];
	for(int i = 0; i < arrSize; ++i)
		data[i] = NULL;
}

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

void node::displayAll()
{
	for(int i = 0; i < arrSize; ++i)
		if(data[i] != NULL)
		{
			data[i]->display();
			cout << endl;
		}
}

int node::getPriority(int position)
{
	return data[position]->getPriority();	
}

bool node::isFull()
{
	return !(data[arrSize-1] == NULL);
	//if the last element in the array is not NULL then the array is full
}

node*& node::goNext()
{
	return next;
}

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



/*
void node::createNewArray()
{
	this->data = new base*[arrSize];

	for(int i = 0; i < arrSize; ++i)
		data[i] = NULL;
}
*/

base*& node::getPosition(int position)
{
	return this->data[position];
}



//chose 5 as size of our arrays just because
list::list() : arrSize(5), head(NULL), tail(NULL) {}

list::~list()
{
	delete head->goNext();

	head = NULL;
	tail = NULL;
}

bool list::deleteBase(char* match)
{
	node* cur;
	bool removed = false;

	if(head)
		for(cur = head; !removed && cur != NULL; cur = cur->goNext())
			removed = cur->deleteBase(match);
}

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

void list::display()
{
	if(head)
	{
		for(node* cur = head; cur != NULL; cur = cur->goNext())
			cur->displayAll();
	}
}

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









