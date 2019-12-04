#include "prog5.h"




int main()
{
	char deleteWord[100];
	List list;
	list.add();
	list.add();
	//list.displayPriority(1, list.getHead());
	list.add();
	

	cout << "What one do you want to delete? Please enter the name: ";
	cin.get(deleteWord, 100, '\n');
	cin.ignore(100, '\n');
	cout << endl;


	list.remove(deleteWord);
	list.display();
	cout << "Deleting list..." << endl;
	list.~List();
	list.display();
	return 0;
}
