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
};

struct node
{
	meal my_meal;
	node* next;
};


class table
{
	public:
		table(int size = 101);	//~table();
		bool add(char* key_value, meal*& to_add);
		int remove(char* meal_name);
		int removeAll(char* name);
		meal* retrieve(char* key_word);
		int display();	//displays and returns number of nodes;

		int hash_function(char* key) const;

	private:
		node** hash_table;
		int hash_table_size;





};


