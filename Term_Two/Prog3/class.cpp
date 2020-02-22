#include "header.h"
/*
table(int size = 101);	//~table();
		add(meal*& meal);
		remove(meal*& meal);
		removeAll(char* name);
		retrieve(char* key_word);

		int hash_function(char* key) const;
*/

/*
meal::meal(char* myname, char* myreview, int myprice, int myrating, bool mytype)
{
	name = new char[strlen(myname) + 1];
	review = new char[strlen(myreview) + 1];

	strcpy(name, myname);
	strcpy(review, myreview);
	rating = myrating;
	price = myprice;
	type = mytype;
}
*/





bool meal::copy(meal* to_add)
{
	this->mealName = new char[strlen(to_add->mealName) + 1];
	this->name = new char[strlen(to_add->name) + 1];
	this->review = new char[strlen(to_add->review) + 1];



	//Copying everything into new node, this is used
	//to make inserting into the hash table easier
	strcpy(mealName, to_add->mealName);
	strcpy(name, to_add->name);
	strcpy(review, to_add->review);
	rating = to_add->rating;
	price = to_add->price;
	type = to_add->type;

	return true;
}

void meal::display()
{
	cout << "Meal name: " << mealName << endl;
	cout << "Name: " << name << endl
		<< "Review: " << review << endl
		<< "Rating <1-10>: " << rating << endl
		<< "Approximate Price Per Meal: " << price << "$" << endl;
	if(type)
		cout << "Type: Food Cart" << endl;
	else
		cout << "Type: Restuarant" << endl;
}


table::table(int size)
{
	int i;
	hash_table_size = size;

	hash_table = new node*[hash_table_size];
	for(i = 0; i < hash_table_size; ++i)
		hash_table[i] = NULL;
}
int table::hash_function(char* key) const
{
	int i;
	int total;
	for(i = 0; i < strlen(key); ++i)
		total += key[i];
}




bool table::add(char* key_value, meal *& to_add)
{
	int key = hash_function(key_value);	//position in hash_table
	node* temp;	//temp pointer



	if(hash_table[key])
	{
		temp = hash_table[key];

		hash_table[key] = new node;
		hash_table[key]->my_meal.copy(to_add);
		hash_table[key]->next = temp;
		return true;
	}
	else
	{
		hash_table[key] = new node;
		hash_table[key]->my_meal.copy(to_add);
		hash_table[key]->next = NULL;
		return true;
	}
	return false;
}


//returns amount of total nodes in entire hash_table
int table::display()
{
	int numNode = 0;
	node* temp;
	int i;

	for(i = 0; i < hash_table_size; ++i)
	{
		if(hash_table[i] != NULL)
		{
			cout << "Chain #" << i << ":" << endl;
		
			temp = hash_table[i];

			do
			{
				++numNode;
				cout << numNode << endl;
				temp->my_meal.display();
				temp = temp->next;
			}while(temp != NULL);
		}
	}
	return numNode;
}

int table::remove(char* meal_name)
{

	node* cur;
	node* prev;
	int i;

	for(i = 0; i < hash_table_size; ++i)
	{
		if(hash_table[i] != NULL)
		{
			cur = hash_table[i];
			prev = cur;

			while(cur != NULL)
			{
				if(cur == hash_table[i] && strcmp(meal_name, cur->my_meal.mealName) == 0)
				{
					hash_table[i] = cur->next;
					delete cur;
					cur = NULL;
				}
				else
				{
					cur = cur->next;
					if(strcmp(meal_name, cur->my_meal.mealName) == 0)
					{
						prev->next = cur->next;
						delete cur;
						cur = NULL;



					}
					else
						prev = cur;
				}
			}
		}
	}
}



//returns number of meals deleted
int table::removeAll(char* name)
{
	node* cur;
	node* prev;
	int i;
	int deleted = 0;

	for(i = 0; i < hash_table_size; ++i)
	{
		if(hash_table[i] != NULL)
		{
			//special case if its the first node in the list
			if(strcmp(hash_table[i]->my_meal.name, name) == 0)
			{
				node* cur = hash_table[i];
				hash_table[i] = cur->next;
				delete cur;
				++deleted;
			}
			else
			{
				cur = hash_table[i];
				prev = cur;
				while(cur != NULL)
				{

					if(strcmp(cur->my_meal.name, name) == 0)
					{
						cur = cur->next;
						delete cur;
					}	




				}
			}

		}




	}

}

meal* table::retrieve(char* key_word)
{
	return &hash_table[hash_function(key_word)]->my_meal;
}
