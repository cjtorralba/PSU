#include "email.h"

email::email() : title(), subject(NULL), body(NULL), sender(NULL), recipiant(NULL), timeSent(0) {}

email::email(const email & toCopy) : title(toCopy.name, toCopy.date), body(toCopy.body), sender(toCopy.sender), recipiant(toCopy.recipiant), timeSent(toCopy.timeSent) {}



email::email(char* name, char* date, char* subject, char* body, char* sender, char* recipiant, double timeSent) 
	: title(name, date), subject(subject), body(body), sender(sender), recipiant(recipiant), timeSent(timeSent) {}





essay::essay() : title(), body(NULL), dueDate(NULL), wordLength(0) { }


essay::essay(char* name, char* date, char* body, char* dueDate, int wordLength) 
	: title(name, date), body(body), dueDate(dueDate), wordLength(wordLength){ }

essay::essay(const essay & toCopy) : title(toCopy.name, toCopy.date), body(toCopy.body), dueDate(toCopy.dueDate), wordLength(toCopy.wordLength) {}
