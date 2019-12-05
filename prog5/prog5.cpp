#include "prog5.h"
node::~node()
{
	delete []name;
	delete []description;
	delete []complete;
	delete priority;
	delete next;
	name = NULL;
	description = NULL;
	complete = NULL;
	priority = NULL;
}

List::List()
{
	head = NULL;
}
List::~List()
{
	delete head;
}



/*
List::~List()
{
	node* cur = head;
	node* prev;
		while(cur->next != NULL)
		{
			prev = cur;
			cur = cur->next;
			if(cur->next == NULL)
			{
				delete cur;
				prev->next = NULL;
				if(head != NULL)
					cur = head;
			}

		}
	if(head->next == NULL)
		delete head;
	
}
*/
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
			<< "\nPriority: " << *(cur->priority) << endl;
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

void List::displayPriority(int intSearch, node* search)
{
	if(search->next != NULL)
		displayPriority(intSearch, search->next);	
	if(*(search->priority) == intSearch)
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

	else if(head->next == NULL && strcmp(head->name, search) == 0)
	{
		delete [] head->name;
		delete [] head->description;
		delete [] head->complete;
		delete  head->priority;

		head = NULL;
		cout << "Your list is now empty..." << endl;

		return true;
	}
	else
	{
		while(cur->next != NULL)
		{
			prev = cur;
			cur = cur->next;
			if(strcmp(cur->name, search) == 0)
			{
				prev->next = cur->next;
				delete [] cur->name;
				delete [] cur->description;
				delete [] cur->complete;
				delete cur->priority;

				return true;
			}
		}
	}
	cout << "Nothing matches criteria for deletion..." << endl;
	return false;
}	





//Adds and sorts
/*
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

   head->name = new char[strlen(tempName)+1];
   head->description = new char[strlen(tempDescription)+1];
   head->complete = new char[strlen(tempComplete)+1];

   strcpy(head->name, tempName);
   strcpy(head->description, tempDescription);
   strcpy(head->complete, tempComplete);

   head->next = NULL;
   return true;
   }
   else{
   node* temp;
   node* cur;	
   node* prev;

   temp = new node;


   cout << "\nPriority <0-10>: ";
   cin >> temp->priority;
   cin.ignore(100, '\n');

   temp->name = new char[strlen(tempName)+1];
   temp->description = new char[strlen(tempDescription)+1];
   temp->complete = new char[strlen(tempComplete)+1];

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
	while(cur->next != NULL)
	{
		prev = cur;
		cur = cur->next;
		if(strcmp(temp->name, prev->name) == 0)
		{
			temp->next = cur->next;
			prev->next = temp;
			temp = NULL;
			return true;
		}
		else if(strcmp(temp->name, cur->name) < 0 && 
				strcmp(temp->name, prev->name) >= 0)
		{
			prev->next = temp;
			temp->next = cur;
			temp = NULL;
			return true;
		}
		else if(strcmp(temp->name, cur->name) >= 0 && 
				cur->next == NULL)
		{
			cur->next = temp;
			temp->next = NULL;
			temp = NULL;
			return true;
		}

	}
}
}
return false;
}
*/

bool List::test()
{
	char tempName[200];
	char tempDescription[200];
	char tempComplete[100];
	int tempPriority;	


	cout << "Name of item: ";
	cin.get(tempName, 200, '\n');
	cin.ignore(200, '\n');


	cout << "\nDescription of the task: ";
	cin.get(tempDescription, 200, '\n');
	cin.ignore(200, '\n');


	cout << "\nDate you want this task completed by: ";
	cin.get(tempComplete, 100, '\n');
	cin.ignore(100, '\n');


	cout << "\nPriority <0-10>: ";
	cin >> tempPriority;
	cin.ignore(100, '\n');


	if(head == NULL)
	{
		head = new node;


		head->name = new char[strlen(tempName)+1];
		head->description = new char[strlen(tempDescription)+1];
		head->complete = new char[strlen(tempComplete)+1];
		head->priority = new int;

		strcpy(head->name, tempName);
		strcpy(head->description, tempDescription);
		strcpy(head->complete, tempComplete);
		*(head->priority) = tempPriority;

		head->next = NULL;
		return true;
	}
	else
	{
		node* cur;
		node* prev;

		if(head != NULL && head->next == NULL)
		{
			if(strcmp(tempName, head->name) >= 0)
			{
				head->next = new node;
				cur = head->next;
				cur->next = NULL;


				cur->name = new char[strlen(tempName)+1];
				cur->description = new char[strlen(tempDescription)+1];
				cur->complete = new char[strlen(tempComplete)+1];
				cur->priority = new int;

				strcpy(cur->name, tempName);
				strcpy(cur->description, tempDescription);
				strcpy(cur->complete, tempComplete);
				*(cur->priority) = tempPriority;

				return true;
			}
			else
			{
				head->next = new node;

				cur = head;
				head = head->next;
				head->next = cur;
				cur->next = NULL;

				head->name = new char[strlen(tempName)+1];
				head->description = new char[strlen(tempDescription)+1];
				head->complete = new char[strlen(tempComplete)+1];
				head->priority = new int;

				strcpy(head->name, tempName);
				strcpy(head->description, tempDescription);
				strcpy(head->complete, tempComplete);
				*(head->priority) = tempPriority;


				return true;
			}

		}

		cur = head;
		while(cur->next != NULL)
		{
			prev = cur;
			cur = cur->next;

			if(strcmp(tempName, prev->name) >= 0 && 
					strcmp(tempName, cur->name) <= 0)
			{
				prev->next = new node;
				prev = prev->next;
				prev->next = cur;


				prev->name = new char[strlen(tempName)+1];
				prev->description = new char[strlen(tempDescription)+1];
				prev->complete = new char[strlen(tempComplete)+1];
				prev->priority = new int;


				strcpy(prev->name, tempName);
				strcpy(prev->description, tempDescription);
				strcpy(prev->complete, tempComplete);
				*(prev->priority) = tempPriority;

				return true;
			}
			else if(strcmp(tempName, prev->name) <= 0 && prev == head)
			{
				head = new node;
				head->next = prev;


				head->name = new char[strlen(tempName)+1];
				head->description = new char[strlen(tempDescription)+1];
				head->complete = new char[strlen(tempComplete)+1];
				head->priority = new int;

				strcpy(head->name, tempName);
				strcpy(head->description, tempDescription);
				strcpy(head->complete, tempComplete);
				*(head->priority) = tempPriority;

				return true;
			}


			if(cur->next == NULL && strcmp(tempName, cur->name) >= 0)
			{
				cur->next = new node;
				cur = cur->next;
				cur->next = NULL;


				cur->name = new char[strlen(tempName)+1];
				cur->description = new char[strlen(tempDescription)+1];
				cur->complete = new char[strlen(tempComplete)+1];
				cur->priority = new int;

				strcpy(cur->name, tempName);
				strcpy(cur->description, tempDescription);
				strcpy(cur->complete, tempComplete);
				*(cur->priority) = tempPriority;

				return true;
			}
		}
	}
}	















