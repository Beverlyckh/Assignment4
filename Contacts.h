/*
 * Contacts.h
 *
 *  Created on: Oct 4, 2017
 *      Author: beverlyackah
 */

#ifndef CONTACTS_H_
#define CONTACTS_H_
#include <iostream>
#include <sstream>
using namespace std;

class Contacts {
private:
	int infoContact;
	string firstname;
	string lastname;
public:
	Contacts();
	Contacts( string firstname, string lastname,int infoContact);
	Contacts( string firstname, string lastname);
	string getName();
	string getFirstname();
	string getLastname();
	int getNumber();
	friend void printContacts(Contacts contact);
	Contacts& operator=(const Contacts &rhs);
	friend ostream& operator<<(ostream &out, const Contacts &contact){          //this function will allow the use of cout directly
		out<<"Contact: "<<contact.firstname<<" "<<contact.lastname<<" ,tel : "<<contact.infoContact<<endl;
		return out;
	}
	bool operator < (const Contacts &contact);
	bool operator > (const Contacts &contact);
	bool operator == (const Contacts &contact);
	virtual ~Contacts();
};



#endif /* CONTACTS_H_ */
