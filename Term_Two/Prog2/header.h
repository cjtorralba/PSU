#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

struct trip_section
{
	trip_section(); ~trip_section();
	bool set_trip(char* name, char* traffic, char* notes, char* landmarks, int length);
	char* name;
	char* traffic;
	char* notes;
	char* landmarks;
	int length;

	trip_section* next;
};

struct node
{
	node* next;
	trip_section* stack;
};

class return_trip
{
	private:
		int top_index;
		const int MAX = 5;
		node* head;
	public:
		return_trip();  ~return_trip();
		bool push(trip_section* node);
		bool pop();
		trip_section* peek();
		bool display();

};



class travel
{
	private:
		trip_section* rear;
	public:
		travel();       ~travel();
		bool copy(trip_section* trip, trip_section* to_copy);
		bool enqueue(trip_section* trip_section);
		bool dequeue();
		trip_section* peek();              bool display();

};



