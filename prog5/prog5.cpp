#include "prog5.h"
node::~node()
{
	delete []name;
	delete []description;
	delete []complete;
	delete next;

}

List::List()
{
	head = NULL;
}
List::~List()
{
	delete head;
}

void List::display()
{
	node* cur;
	if(head == NULL)
		cerr << "No List..." << endl;
	for(cur = head; cur != NULL; cur = cur->next)
	{	
		cout << "Name: " << cur->name
			<<"\nDecription: " << cur->description
			<<"\nDate to be completed by: " << cur->complete
			<< "\nPriority: " << cur->priority << endl;
	}

}
node* List::getHead()
{
	if(head ==  NULL)
	{
		return NULL;
		cerr << "Empty List..." << endl;
	}
	return head;
}

void List::displayPriority(int priority, node* search)
{
	if(search->next != NULL)
		displayPriority(priority, search->next);	
	if(search->priority == priority)
	{
		cout << "Name: " << search->name
			<< "\nDescription: " << search->description
			<< "\nPriority: " << search->priority
			<< "\nDate to be completed: " << search->complete
			<< endl;
	}
}
bool List::remove(char search[])
{
	node* cur = head;
	node* prev;


	if(head == NULL)
	{
		cerr << "Empty List..." << endl;
		return false;
	}

	if(head->next == NULL && strcmp(head->name, search) == 0)
	{
		delete head;
		head = NULL;
		cout << "Your list is now empty..." << endl;
		return true;
	}

	while(cur->next != NULL)
	{
		prev = cur;
		cur = cur->next;
		if(strcmp(cur->name, search) == 0)
		{
			prev->next = cur->next;
			delete cur;
			return true;
		}
	}
	cout << "Nothing matches criteria for deletion..." << endl;
}	





//Adds and sorts
bool List::add()
{
	char tempName[200];
	char tempDescription[200];
	char tempComplete[100];
		
	cout << "Name of item: ";
	cin.get(tempName, 200, '\n');
	cin.ignore(200, '\n');

	cout << "\nDescription of the task: ";
	cin.get(tempDescription, 200, '\n');
	cin.ignore(200, '\n');

	cout << "\nDate you want this task completed by: ";
	cin.get(tempComplete, 100, '\n');
	cin.ignore(100, '\n');


	if(head == NULL)
	{
		head = new node;

		cout << "\nPriority <0-10>: ";
		cin >> head->priority;
		cin.ignore(100, '\n');

		head->name = new char[strlen(tempName)];
		head->description = new char[strlen(tempDescription)];
		head->complete = new char[strlen(tempComplete)];

		strcpy(head->name, tempName);
		strcpy(head->description, tempDescription);
		strcpy(head->complete, tempComplete);

		head->next = NULL;
		return true;
	}


	else{
		node* temp = new node;
		node* cur;	
		node* prev;

		cout << "\nPriority <0-10>: ";
		cin >> temp->priority;
		cin.ignore(100, '\n');

		//	cout << "Finished inputs" << endl;
		temp->name = new char[strlen(tempName)];
		temp->description = new char[strlen(tempDescription)];
		temp->complete = new char[strlen(tempComplete)];

		strcpy(temp->name, tempName);
		strcpy(temp->description, tempDescription);
		strcpy(temp->complete, tempComplete);



		//really sketch way of sorting i guess, but if it works it works so -_-
		if(head->next ==  NULL)
		{
			cur = head;
			if(strcmp(temp->name, head->name) > 0)
			{
				head->next = temp;
				temp->next = NULL;
				return true;
			}
			else
			{
				head = temp;
				head->next = cur;
				cur->next = NULL;
				return true;
			}
		}


		else
		{
			cur = head;
			prev = cur;
			while(strcmp(temp->name, cur->name) >= 0 && cur->next != NULL)
			{
				prev = cur;
				cur = cur->next;
				if(strcmp(temp->name, cur->name) == 0)
				{
					temp->next = cur->next;
					cur->next = temp;
					return true;
				}
				else if(strcmp(temp->name, cur->name) < 0 && 
						strcmp(temp->name, prev->name) >= 0)
				{
					prev->next = temp;
					temp->next = cur;
					return true;
				}
				else if(strcmp(temp->name, cur->name) >= 0 && 
						cur->next == NULL)
				{
					cur->next = temp;
					temp->next = NULL;
					return true;
				}

			}
		}
	}
	return false;
}


