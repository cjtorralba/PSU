#include "header.h"





//=======================struct stuff===============================

trip_section::trip_section()
{
	next = NULL;
	name = NULL;
	traffic = NULL;
	notes = NULL;
	landmarks = NULL;
	length = 0;
}


trip_section::~trip_section()
{
	cout << "start trip destructor" << endl;
	delete [] name;
	delete [] traffic;
	delete [] notes;
	delete [] landmarks;
	next = NULL;

	name = NULL;
	traffic = NULL;
	notes = NULL;
	landmarks = NULL;
	cout << " Finish trip destructor" << endl;
}

bool trip_section::set_trip(char* nameAdd, char* trafficAdd, char* notesAdd, char* landmarksAdd, int lengthAdd)
{
	if(this->name != NULL)
	{
		delete [] name;
		delete [] traffic;
		delete [] notes;
		delete [] landmarks;

		name = NULL;
		traffic = NULL;
		notes = NULL;
		landmarks = NULL;
	}


	name = new char[strlen(nameAdd) + 1];
	traffic = new char[strlen(trafficAdd) + 1];
	notes = new char[strlen(notesAdd) + 1];
	landmarks = new char[strlen(landmarksAdd) + 1];

	strcpy(name, nameAdd);
	strcpy(traffic, trafficAdd);
	strcpy(notes, notesAdd);
	strcpy(landmarks, landmarksAdd);
	length = lengthAdd;


	return true;	
}

//===========================End of struct stuff=========================




//===================================circular linked list stuff==========================
travel::travel()
{
	rear = NULL;
}


travel::~travel()
{
	trip_section* cur;
	trip_section* prev;

	if(rear)
	{
		if(rear->next == rear)
		{
			rear->next = NULL;
			delete rear;
			
		}


		else if(rear->next != rear)
		{
			cout << "in travel destructor" << endl;
			cur = rear->next;
			rear->next = NULL;
			while(cur->next != NULL)
			{
				prev = cur;
				cur = cur->next;
				delete prev;
				prev->next = NULL;
			}
			delete rear;
			cout << "out this travel destructor" << endl;
		}
		cout << "out travel destructor" << endl;
	}
}



bool travel::display()
{
	trip_section* temp;

	if(!rear)
		return NULL;
	else
	{
		temp = rear;
		do
		{
			temp = temp->next;
			cout << "Name: " << temp->name << endl;
		}while(temp != rear);
		return true;
	}
	return false;
}



trip_section* travel::peek()
{
	if(!rear)
		return NULL;
	else
		return rear->next;
	return NULL;
}


bool travel::dequeue()
{
	trip_section* cur;

	if(!rear)
		return false;
	else
	{
		if(rear->next == rear)
		{
			delete rear;
			rear = NULL;
			return true;
		}
		else
		{
			for(cur = rear->next; cur->next != rear; cur = cur->next);
			cur->next = rear->next;
			delete rear;
			rear = cur;
			return true;
		}
	}
	return false;
}





bool travel::enqueue(trip_section* trip)
{
	cout << "in enqueue" << endl;

	trip_section* temp;
	
	if(rear == NULL)
	{
		rear = new trip_section;
		rear->next = rear;

		rear->name = new char[strlen(trip->name) + 1];
		rear->traffic = new char[strlen(trip->traffic) + 1];
		rear->notes = new char[strlen(trip->notes) + 1];
		rear->landmarks = new char[strlen(trip->landmarks) + 1];

		strcpy(rear->name, trip->name);
		strcpy(rear->traffic, trip->traffic);
		strcpy(rear->notes, trip->notes);
		strcpy(rear->landmarks, trip->landmarks);
		rear->length = trip->length;
		cout << "out enqueue" << endl;
		cout << "rear->next:" << rear->next->name << endl;

		return true;
	}
	else
	{
		temp = rear->next;
		rear->next = new trip_section;
		rear = rear->next;
		rear->next = temp;

		rear->name = new char[strlen(trip->name) + 1];
		rear->traffic = new char[strlen(trip->traffic) + 1];
		rear->notes = new char[strlen(trip->notes) + 1];
		rear->landmarks = new char[strlen(trip->landmarks) + 1];

		strcpy(rear->name, trip->name);
		strcpy(rear->traffic, trip->traffic);
		strcpy(rear->notes, trip->notes);
		strcpy(rear->landmarks, trip->landmarks);
		rear->length = trip->length;

		return true;
	}
	return false;
}


//=========================================End of circular linked list stuff============================











//=======================================Start of stack stuff=========================================


return_trip::return_trip()
{
	top_index = 0;
	head = NULL;
}

return_trip::~return_trip()
{
	node* temp;
	if(head)
	{
		cout << "in stack destructor" << endl;
		while(head->next != NULL)
		{
			temp = head;
			head = head->next;

			delete [] temp->stack;
			temp->next = NULL;
		}
			delete [] head->stack;
			head = NULL;
		cout << "out stack destructo" << endl;
	}
}

bool return_trip::display()
{
	int temp_index = top_index;
	node* cur;

	if(!head)
		return false;
	else
	{
		for(cur = head; cur != NULL; cur = cur->next)
		{
			while(temp_index != 0)
			{
				--temp_index;
				cout << cur->stack[temp_index].name << endl;
			}		
			temp_index = MAX;
		}
		return true;
	}
	return false;
}






trip_section* return_trip::peek()
{
	if(!head)
		return NULL;
	else
		return &head->stack[top_index-1];
}

bool return_trip::pop()
{
	node* temp;
	if(!head)
		return false;
	else
	{
		if(head->next == NULL && top_index == 0)
		{
			top_index = 0;
			delete head;
			head = NULL;
			return true;
		}
		else if(top_index == 1)
		{
			top_index = MAX;
			temp = head;
			head = head->next;
			delete temp;
			return true;
		}
		else
		{
			--top_index;
			return true;
		}

	}
	return false;
}



bool return_trip::push(trip_section* trip)
{
	cout << "in push" << endl;
	node* temp;

	if(!head)
	{
		head = new node;
		head->next = NULL;

		head->stack = new trip_section[MAX];

		head->stack[top_index].name = new char[strlen(trip->name) + 1];
		head->stack[top_index].traffic = new char[strlen(trip->traffic) + 1];
		head->stack[top_index].notes = new char[strlen(trip->notes) + 1];
		head->stack[top_index].landmarks = new char[strlen(trip->landmarks) + 1];

		strcpy(head->stack[top_index].name, trip->name);
		strcpy(head->stack[top_index].traffic, trip->traffic);
		strcpy(head->stack[top_index].notes, trip->notes);
		strcpy(head->stack[top_index].landmarks, trip->landmarks);
		head->stack[top_index].length = trip->length;

		++top_index;
		return true;
	}		
	else
	{
		if(top_index >= MAX)
		{
			top_index = 0;
			temp = head;
			head = new node;

			head->next = temp;	

			head->stack = new trip_section[MAX];

			head->stack[top_index].name = new char[strlen(trip->name) + 1];
			head->stack[top_index].traffic = new char[strlen(trip->traffic) + 1];
			head->stack[top_index].notes = new char[strlen(trip->notes) + 1];
			head->stack[top_index].landmarks = new char[strlen(trip->landmarks) + 1];

			strcpy(head->stack[top_index].name, trip->name);
			strcpy(head->stack[top_index].traffic, trip->traffic);
			strcpy(head->stack[top_index].notes, trip->notes);
			strcpy(head->stack[top_index].landmarks, trip->landmarks);
			head->stack[top_index].length = trip->length;

			++top_index;
			return true;
		}
		else
		{

			head->stack[top_index].name = new char[strlen(trip->name) + 1];
			head->stack[top_index].traffic = new char[strlen(trip->traffic) + 1];
			head->stack[top_index].notes = new char[strlen(trip->notes) + 1];
			head->stack[top_index].landmarks = new char[strlen(trip->landmarks) + 1];

			strcpy(head->stack[top_index].name, trip->name);
			strcpy(head->stack[top_index].traffic, trip->traffic);
			strcpy(head->stack[top_index].notes, trip->notes);
			strcpy(head->stack[top_index].landmarks, trip->landmarks);
			head->stack[top_index].length = trip->length;

			++top_index;
			return true;

		}

	}
	return false;
}




//===============================================End of stack stuff=====================================
