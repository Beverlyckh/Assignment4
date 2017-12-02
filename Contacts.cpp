/*
 * Contacts.cpp
 *
 *  Created on: Oct 4, 2017
 *      Author: beverlyackah
 */

#include "Contacts.h"

Contacts::Contacts() {
	// TODO Auto-generated constructor stub

}

Contacts::Contacts( string firstname, string lastname,int infoContact){
	this->firstname = firstname;
	this->lastname = lastname;
	this->infoContact = infoContact;
}

Contacts::Contacts( string firstname, string lastname){
	this->firstname = firstname;
	this->lastname = lastname;
}

Contacts& Contacts::operator=(const Contacts &rhs){
	if( this != &rhs){
		firstname = rhs.firstname;
		lastname = rhs.lastname;
		infoContact = rhs.infoContact;
	}
	return *this;
}

void printContacts(Contacts contact){
	cout<<contact.firstname<<" "<<contact.lastname<<" "<<contact.infoContact<<endl;
}
int Contacts::getNumber(){
	return infoContact;
}
string Contacts::getName(){
	return lastname;
}

string Contacts::getFirstname(){
	return firstname;

}

string Contacts::getLastname(){
	return lastname;
}


bool Contacts::operator > (const Contacts &contact)
{
	if(firstname == contact.firstname){
		return (lastname > contact.lastname);
	}
	return (firstname > contact.firstname);
}
bool Contacts::operator < (const Contacts &contact)
{
	if(firstname == contact.firstname){
		return (lastname < contact.lastname);
	}
	return (firstname < contact.firstname);
}
bool Contacts::operator == (const Contacts &contact){
	return firstname==contact.firstname && lastname==contact.lastname;
}


Contacts::~Contacts() {
	// TODO Auto-generated destructor stub
}

