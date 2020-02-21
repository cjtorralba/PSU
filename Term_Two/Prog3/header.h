#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;


struct meal
{
	char* name;	//name of venue
	int price;	//approximate price
	int rating;	//rating 1-10
	char* review;	//review
	bool type;	//true = cart    false = resturant
	bool copy(meal* to_add);
	void display();
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
		int remove(meal& to_remove);
		int removeAll(char* name);
		int retrieve(char* key_word);
		int display();	//displays and returns number of nodes;

		int hash_function(char* key) const;

	private:
		node** hash_table;
		int hash_table_size;





};


