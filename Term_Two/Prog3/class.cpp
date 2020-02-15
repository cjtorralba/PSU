#include "header.h"
/*
table(int size = 101);	//~table();
		add(meal*& meal);
		remove(meal*& meal);
		removeAll(char* name);
		retrieve(char* key_word);

		int hash_function(char* key) const;
*/
table::table(int size)
{
	int i;
	hash_table_size = size;

	hash_table = new node*[hash_table_size];
	for(i = 0; i < hash_table_size; ++i)
		hash_table[i] = 0;
}
int table::hash_function(char* key) const
{
	int i;
	int total;
	for(i = 0; i < strlen(key); ++i)
		total += key[i];
}
int table::add(char* key_value, const meal *& to_add)
{
	int key = hash_function(key_value);





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
