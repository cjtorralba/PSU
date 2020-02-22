#include "header.h"

int main()
{
table myTable;







meal meal1;
meal1.mealName = "chicken";
meal1.name = "name";
meal1.review = "review";
meal1.rating = 5;
meal1.price = 6;
meal1.type = true;

meal* pmeal;
pmeal = &meal1;







myTable.add(pmeal->name, pmeal);

meal1.mealName = "soup";


myTable.add(pmeal->name, pmeal);



int total = myTable.display();

cout << "Total number of nodes in table: " << total << endl;

cout << "Deleting chicken =====================================================" << endl;

myTable.remove("chicken");


myTable.display();


return 0;
}
