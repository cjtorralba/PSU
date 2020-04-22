#include "node.h"




int main()
{

	table LLL;
	char name[50];
	char date[50];
	char desc[50];
	double time;

	cin.get(name, 100, '\n');	cin.ignore(100, '\n');
	cin.get(date, 100, '\n');	cin.ignore(100, '\n');
	cin.get(desc, 100, '\n');	cin.ignore(100, '\n');

	cin >> time;	cin.ignore(100, '\n');

	video* vid = new video(name, date, desc, time);


	node* toAdd = new node();

	toAdd->addVideo(*vid);

	LLL.addNode(*toAdd);

	delete toAdd;
	delete vid;

	return 0;

}
