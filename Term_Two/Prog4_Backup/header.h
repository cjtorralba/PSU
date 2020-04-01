#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

struct meal
{
	char* name;
	char* storeName;
	char* review;
	int price;
	int rating;
	bool type;

	void display(void);
	void copy(meal* to_add);
};

struct node
{
	meal myMeal;
	node* left;
	node* right;
};


class tree
{
	public:
		tree();		//~tree();
		int display(node* root);
		int display();


		int displayMatch(char* mealName);
		int displayMatch(char*mealName, node* root);

		bool add(meal* toAdd);
		bool add(meal* toAdd, node*& root);

		bool remove(node* toRemove);
		bool remove(node* toRemove, node*& root);

		bool search(char* name);




	private:
		node* root;
};
