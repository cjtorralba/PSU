#include "header.h"








//This is also for ease and displays any given meal
void meal::display()
{
	cout << "Meal name: " << name << endl
		<< "Establishment name: " << storeName << endl
		<< "Review: " << review << endl
		<< "Rating <1-10>: " << rating << endl
		<< "Approximate Price: " << price << "$" << endl
		<< "Type: ";
	if(type)
		cout << "Food cart" << endl;
	else
		cout << "Retaurant" << endl;
}


//This is purely to make things look easier, copies a meal passed in to the current meal
void meal::copy(meal* to_add)
{
	this->name = new char[strlen(to_add->name) + 1];
	this->storeName = new char[strlen(to_add->name) + 1];
	this->review = new char[strlen(to_add->review) + 1];
	
	strcpy(this->name, to_add->name);
	strcpy(this->storeName, to_add->storeName);
	strcpy(this->review, to_add->review);
	this->price = to_add->price;
	this->rating = to_add->rating;
	this->type = to_add->type;
}








//constructor for tree class, setting root to NULL as usual
tree::tree()
{
	root = NULL;
}

//Wrapper function for add function, returns boolean on if it was added or not
bool tree::add(meal* toAdd)
{
	return add(toAdd, root);
}




//Adds a node and returns whether it was succesfull or not 
bool tree::add(meal* toAdd, node*& root)
{

	if(!root)
	{
		root =  new node;
		root->myMeal.copy(toAdd);
		root->left = NULL;
		root->right = NULL;
		return true;
	}
	else
	{
		if(strcmp(root->myMeal.name, toAdd->name) < 0)
			add(toAdd, root->left);
		else
			add(toAdd, root->right);
	}
	return false;
}



int tree::displayMatch(char* mealName)
{
	return displayMatch(mealName, root);
}

//Counts and displays the number of retaurants with matching meal names
//returns the amount of matching meals
int tree::displayMatch(char* mealName, node* root)
{
	int sum = 0;

	if(!root)
		return 0;
	else
	{
		if(strcmp(mealName, root->myMeal.name) == 0)
		{
			root->myMeal.display();
			++sum;
		}
	}

	displayMatch(mealName, root->left);
	displayMatch(mealName, root->right);

	return sum;
}


//Wrapper function for our display fucntion returning the number of nodes in the tree
int tree::display()
{
	return display(root);
}





//displays entire tree and returns the number of nodes in the tree
int tree::display(node* root)
{
	int sum = 0;

	if(!root)
		return 0;
	else
	{
		root->myMeal.display();
		cout << endl;
	}

	sum = display(root->left) + 1;
	sum = display(root->right) + 1;

	return sum;
}












