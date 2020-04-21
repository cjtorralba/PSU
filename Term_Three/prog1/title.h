#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;




class title
{
	public:
		title(char* name, char* date);
		title(const title & title);
		title();	//~title();
		

		void display();
		void changeTitle(char* name, char* date);
		void changeTitle(const title & toChange);
		void setTitleName(char* name);
		void setTitleDate(char* date);
		
	protected:
		char* date;


		char* name;
};





class video : public title
{

	public:
		video();	//~video();
		video(char* name, char* date, char* description, double length);
		video(const video & toCopy);

		void display();
		void changeVideo(double length, char* description);
		void changeVideo(const video & toChange);


	protected:
		char* description;
		double length;
};

class liveStream : public video
{
	public:
		liveStream();	//~liveStream();
		liveStream(char* name, char* date, char* description, double length, char* instructor, char* topic);
//		liveStream(const title & title, char* date, char* instructor, double length, char* topic);


		void changeStream(const liveStream & toChange);
		void display();



	protected:
		char* instructor;
		char* topic;

};

