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

	this->name = new char[strlen(to_add->name) + 1];
	this->review = new char[strlen(to_add->review) + 1];



	//Copying everything into new node, this is used
	//to make inserting into the hash table easier
	strcpy(name, to_add->name);
	strcpy(review, to_add->review);
	rating = to_add->rating;
	price = to_add->price;
	type = to_add->type;


	return true;
}

void meal::display()
{
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
	int key = hash_function(key_value);
	node* temp;

//	(*to_add).display();


	if(hash_table[key])
	{
		temp = hash_table[key];

		hash_table[key] = new node;
		hash_table[key]->my_meal.copy(to_add);
		hash_table[key]->next = temp;
		cout << "Finished add" << endl;
		return true;
	}
	else
	{
		hash_table[key] = new node;
		hash_table[key]->my_meal.copy(to_add);
		hash_table[key]->next = NULL;
		return true;
		cout << "Finished add" << endl;
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

int table::remove(meal & to_remove)
{


}

int table::removeAll(char* name)
{

}

int table::retrieve(char* key_word)
{


}
