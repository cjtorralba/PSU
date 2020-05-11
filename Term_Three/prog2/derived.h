#include "base.h"

class swim : public base
{
	public:
		swim();		~swim();
		swim(const swim & toCopy);
		swim(int length, int priority, bool group, char* name, char* location, char* swimsuit, bool member, bool hasHotTub);

		void display();

		void startExercise();





	private:
		char* swimSuit;
		bool member;
		bool hasHotTub;
		bool exercise;




};
class hike : public base
{
	public:
		hike();		~hike();
		hike(const hike & toCopy);
		hike(int length, int priority, bool group, char* name, char* location, bool overNight, char* season, char* weather);

		void display();

		bool rockClimb();


	private:
		bool overNight;
		char* season;
		char* weather;
		bool climbShoes;
		



};



class work : public base
{
	public:
		work();		~work();
		work(const work& toCopy);
		work(int length, int priority, bool group, char* name, char* location, char* position, int pay, bool partTime);

		void display();

		void planLunch();



	private:
		char* position;
		double pay;
		bool partTime;
		char* lunch;


};
