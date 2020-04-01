#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;


struct meal
{
	char* mealName; //name of meal
	char* name;	//name of venue
	int price;	//approximate price
	int rating;	//rating 1-10
	char* review;	//review
	bool type;	//true = cart    false = resturant



	bool copy(meal* to_add);	//copys meals so its easier to add them
	void display();		//displays a meal
	~meal();		//meal destructor
};

struct node
{
	meal* my_meal;		//each node has a meal pointer
	node* next;		//each node also has a next pointer
	~node();		//node destructor
};



class table
{
	public:
		table(int size = 101);	~table();	//constructor and destructor
		bool add(char* key_value, meal* to_add);	//function for adding meals
		int remove(char* meal_name);		//function for removing meals by mealname
		int removeAll(char* name);		//function that removes all meals of certain establishment
		meal* retrieve(char* key_word);		//retrieves meal of desired meal name
		bool display(char* meal_name);	//displays and returns number of nodes;
		int displayAll();		//displays all meals in the whole table

		int hash_function(char* key) const;	//hash function for creating hash key

	private:
		node** hash_table;		//hash table itself, array of pointers to pointers
		int hash_table_size;		//size of hash table (101)





};


