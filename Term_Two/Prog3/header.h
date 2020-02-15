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
		int add(char* key_value, const meal*& to_add);
		int remove(meal& to_remove);
		int removeAll(char* name);
		int retrieve(char* key_word);

		int hash_function(char* key) const;

	private:
		node** hash_table;
		int hash_table_size;





};


