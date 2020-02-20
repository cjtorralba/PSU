//Written by christian torralb cs162 katie casamentos class
//this program is meant to be a to-do list for winter break
//you can add remove and search for things to do
//
//This program makes use of linear linked lists and recursive functions.
//it also sorts each node that is added into the lit based off name.



#include "prog5.h"
#include "stdlib.h"
void commands()
{
	cout << "\n The way you use this program is like this: " 
		<<"\nTo add somehting you want to do, simply type \"add\"" << endl
		<< "To remove a something on the list type, \"remove\" followed " 
		<< "by the name of the item you wish to remove, like this, \"remove sledding\"" << endl
		<< "To see all the things you want to do, type \"display\", you can also do " 
		<< "\"display 6\" to see all the items with a priority of 6, this can be any number 1-10" << endl
		<< "Finally, if you wish to exit, just type \"exit\"" << endl 
		<< "If you want to see these again type \"help\" " << endl;

}
void seperate(char* word, char*  first, int*  second)
{
	cout << "in seperator" << endl;
	char tempFirst[40], tempLast[40];
	int space = -1;
	int size = strlen(word);
	int count = 0;
	for(int i = 0; i < size; ++i)
	{
		if(isspace(word[i]))
		{
			space = i;
			++i;
		}
		if(space > 0)
		{
			tempLast[count] = word[i];
			++count;
		}
		if(space == -1)	
		{
			tempFirst[i] = word[i];	
		}

	}
	char* secondTemp;
	first = new char[strlen(tempFirst)+1];
	secondTemp = new char[strlen(tempLast)+1];

	strcpy(first, tempFirst);
	strcpy(secondTemp, tempLast);


	int num = atoi(secondTemp);
	second = new int(num);

//	cout << "First: " << first << endl;
//	cout << "Last: " << second << endl;

}

int main()
{

	bool exit = false;
	char input[40];
	char* first;
	int* second;
	List list;


	cout << "Welcome to the TO-DO list!" << endl;
	cout << "\n Winter break is long and there is plenty to do "
		<< "\nso why not write it down!" << endl;

	commands();


	while(!exit)
	{
		cin.get(input, 40, '\n');
		cin.ignore(100, '\n');

		cout << input << endl;


		if(strcmp(input, "help") == 0)
			commands();
		else if(strcmp(input, "exit") == 0)
			exit = true;
		else if(strcmp(input, "add") == 0)
			list.add();
		else if(strcmp(input, "display"))
				{
				seperate(input, first, second);
				}
				cout << first << endl;
				cout << second << endl;

	}





	return 0;
}
