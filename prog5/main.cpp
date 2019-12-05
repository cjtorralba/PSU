#include "prog5.h"




int main()
{
	char deleteWord[100];
	List list;
	list.test();
	list.test();
	list.test();
	list.test();
	cout << "What one do you want to delete? Please enter the name: ";
	cin.get(deleteWord, 100, '\n');
	cin.ignore(100, '\n');


	list.remove(deleteWord);
	list.display();
	return 0;
}
