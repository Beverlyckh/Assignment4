//============================================================================
// Name        : Assignment 4 - Phonebook Application Program
// Author      : Beverly Ackah
// Version     : November 2017
// Copyright   : Your copyright notice
// Description : Phonebook App using binary search!
//============================================================================

#include <iostream>
#include "contacts.h"
#include "BinarySearchTree.h"
#include <fstream>
#include <ctime>

using namespace std;

int size = 0;
int capacity = 300;

Contacts* contactData ;
BinarySearchTree<Contacts> bs; //creation of binary search tree

void expandArray(){
	capacity *= 2;
	Contacts* resize_arr = new Contacts[capacity];
	for(int i = 0; i<size; i++)
		resize_arr[i] = contactData[i];
	contactData = resize_arr;
	delete [] resize_arr;
}

void loadData(string data){
	ifstream input;
	ifstream linein;
	string contactDetails[3];
	input.open(data);

	if(!input.is_open()){
		return ;
	}
	string line, first, last;
	int number;

	while(input){

		getline(input,line, ' ');

		if(input && line != ""){

			first = line;
			getline(input,line, ' ');
			last = line;
			getline(input,line);
			number = stoi(line);
			Contacts newContact(first,last,number);
			if(size == capacity){
				expandArray();
			}
			bs.insert(newContact);
			size++;
			line="";
		}

	}
}

int main() {
	contactData = new Contacts[capacity];
	cout << "*** MY PHONEBOOK APPLICATION ***" << endl;
	loadData("phonebook.txt");
	char operation=' ';

	do{
		cout << "Please choose an operation:" << endl;
		cout << " A(Add) | | L(Load) |S(Search) | P(Print) | F(Filter) | Q(Quit): " << endl;
		cin>>operation;
		operation = tolower(operation);
		switch(operation){
		//Add a new contact
		case 'A' : case 'a':{
			string firstname, lastname;
			int number;
			cout<<"Enter a first and last name"<<endl; //user first and last name
			cin>>firstname;
			cin>>lastname;
			cout<<"Enter a number"<<endl;
			cin>>number; //user number
			cin.clear();
			Contacts contact(firstname,lastname,number);
			bs.insert(contact); //insertion in bst
			size +=1;
			break;
		}
		//Load data into bst from a file
		case 'L': case 'l':{
			string filename;
			cout<<"Enter a filename"<<endl;
			cin.ignore();
			getline(cin, filename);
			loadData(filename);
			break;
		}
		//Search for a contact from file
		case 'S': case 's':{
			string firstname;
			string lastname;
			cout<<"Enter a first and last name"<<endl;
			cin.ignore();
			cin>>firstname;
			cin>>lastname;

			//The clock function is implemented to calculate the duration of the search!
			clock_t begin = clock();
			Contacts contact(firstname,lastname);
			Contacts* contact1 = bs.inOrder(contact);
			clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;


			//If Bst isn't empty, get the contacts
			if( contact1 != NULL){
				cout<<"Phone: "<<contact1->getNumber()<<endl;
				cout<<" Time taken : "<<elapsed_secs<<endl;
			}
			else{
				cout<<"Contact was not found in the system"<<endl;
			}
			break;
		}
		//Print contact info
		case 'P': case 'p' :{
			bs.inOrder();
			cout<<size<<" contacts..."<<endl;
			break;
		}

		//Filter
		case 'F': case 'f':{
			string firstname;
			string lastname;
			int number;
			cout<<"Enter a first and last name"<<endl;
			cin.ignore();
			cin>>firstname;
			cin>>lastname;
			Contacts contact(firstname,lastname);
			number = bs.filter(contact);
			if( number != -1){
				cout<<number<<" Contacts..."<<endl;

			}
			break;
		}

		default:break;
		}

		//Leave the system
	} while(operation != 'Q' && operation!='q');
	cout<<"Bye!"<<endl;
	return 0;
}
