#include "title.h"
#include "email.h"


class node 
{
	public:
		display();
		node();
		node(const node&);
		node(title & toAdd);



	protected:
		class title* data;
		node* left;
		node* right;


}
