#include "header.h"

/*
 * little messy but it works and with no memory leaks
 * code by christian torralba
 */


//function for copying a new node preferably from main to make it a little easier
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


//display function part of meal struct to make it easier to display meals from main and in other 
//display functions
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

//Meal deconstructor
meal::~meal()
{
	delete [] mealName;
	delete [] name;
	delete [] review;

	mealName = NULL;
	name = NULL;
	review = NULL;
}




//Node deconstructor, recursivly calls destructor on itself
node::~node()
{
	delete next;
	delete my_meal;
}





//----------------------------------------------HashTable functions--------------------------------



//Hashtable contructor, i chose size of 101, initializes all element node* to NULL
table::table(int size)
{
	int i;
	hash_table_size = size;

	hash_table = new node*[hash_table_size];
	for(i = 0; i < hash_table_size; ++i)
		hash_table[i] = NULL;
}

//hashtable deconstructor, calls the node destructor on each element then deletes array of pointers
table::~table()
{
	int i;
	for(i = 0; i < hash_table_size; ++i)
		delete hash_table[i];
	delete [] hash_table;
}




//hash function, takes an array of characters and adds up all their ascii values, then mods it by table size (101)
int table::hash_function(char* key) const
{
	int i;
	int total;

	for(i = 0; i < strlen(key); ++i)
		total += key[i];
	if((total % hash_table_size) < 0)
		return (total % hash_table_size) * -1;
	return total % hash_table_size;
}



//adds a meal to the hash table, in case of collision it creates a linear linked list of the meals with same hashfunction values
bool table::add(char* key_value, meal * to_add)
{
	int key = hash_function(key_value);	//position in hash_table
	node* temp;	//temp pointer



	if(hash_table[key])	//checking to see the the element already has a node (collision)
	{
		temp = hash_table[key];

		hash_table[key] = new node;
		hash_table[key]->my_meal = new meal;
		(*hash_table[key]->my_meal).copy(to_add);
		hash_table[key]->next = temp;
		return true;
	}
	else			//in the case of no collision we just create a new node
	{
		hash_table[key] = new node;
		hash_table[key]->my_meal = new meal;
		(*hash_table[key]->my_meal).copy(to_add);

		hash_table[key]->next = NULL;
		return true;
	}
	return false;
}



//displays the first meal with a matching name, this does not adjust for collision, did not have time
//also returns the position in the hashtable, idk why
bool table::display(char* meal_name)
{
	int key = hash_function(meal_name);

	if(hash_table[key] != NULL)
	{
		(*hash_table[key]->my_meal).display();
		return true;
	}
	return false;
}




//this function was just for me so I could see everything in the table, returns the total number of nodes in the table
int table::displayAll()
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
				(*temp->my_meal).display();
				cout << endl << endl;
				temp = temp->next;
			}while(temp != NULL);
		}
	}
	return numNode;
}




//this function removes a meal by the meal name
//returns the position that was deleted
int table::remove(char* meal_name)
{

	node* cur;
	node* prev;
	int i;
	int removed;

	for(i = 0; i < hash_table_size; ++i)
	{
		if(hash_table[i] != NULL)
		{
			cur = hash_table[i];
			prev = cur;
		

			//this is a very sketch way of going about the table
			while(cur != NULL)
			{
				if(cur == hash_table[i] && strcmp(meal_name, cur->my_meal->mealName) == 0)	//special case for if there is only one
				{
					hash_table[i] = cur->next;
					removed = hash_function(cur->my_meal->mealName);
					delete cur;
					cur = NULL;
				}
				else
				{
					cur = cur->next;
					if(strcmp(meal_name, cur->my_meal->mealName) == 0)
					{
						prev->next = cur->next;
						removed = hash_function(cur->my_meal->mealName);
						delete cur;
						cur = NULL;
					}
					else
						prev = cur;
				}
			}
		}
	}
	return removed;
}




//removes all meals by establishment name
//returning number of establishments deleted
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
			cur = hash_table[i];
			prev = cur;

			while(cur != NULL)
			{

				//special case if its the first node in the list
				if(cur == hash_table[i] && strcmp(hash_table[i]->my_meal->name, name) == 0)
				{
					if(cur->next == NULL)
						hash_table[i] = NULL;
					else
						hash_table[i] = cur->next;

					delete cur;
					cur = hash_table[i];
					++deleted;
				}
				else
				{

					cur = cur->next;
					if(cur && strcmp(cur->my_meal->name, name) == 0)
					{
						if(cur->next = NULL)
							prev->next = NULL;
						else
							prev->next = cur->next;
						delete cur;
						++deleted;
						cur = hash_table[i];
					}
					else
						prev = cur;
				}
			}
		}
	}
	return deleted;

}


//returns the address of the desired meal based off meal name
//checks to see if its null first
//if it doesnt exist it returns null
meal* table::retrieve(char* meal_name)
{
	int key = hash_function(meal_name);

	if(hash_table[key] != NULL)
		return hash_table[key]->my_meal;
	else 
		return NULL;	
}
