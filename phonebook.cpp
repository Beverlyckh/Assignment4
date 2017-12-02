//============================================================================
// Name        : Assignment 1 - Phonebook Application Program
// Author      : Beverly Ackah
// Version     : November 2017
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
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
BinarySearchTree<Contacts> bs;

//expand array capacity
void expandArray(){
	capacity *= 2;
	Contacts* resize_arr = new Contacts[capacity];
	for(int i = 0; i<size; i++)
		resize_arr[i] = contactData[i];
	contactData = resize_arr;
	delete [] resize_arr;
}

//load data function
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
	int i =0;
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
	cout << "*** My PHONEBOOK APPLICATION ***" << endl;
	loadData("phonebook.txt");
	char operation=' ';

	do{
		cout << "Please choose an operation:" << endl;
		cout << " A(Add) | | L(Load) |S(Search) | P(Print) | F(Filter) | Q(Quit): " << endl;
		cin>>operation;
		switch(operation){

//Add a new contact
		case 'A' : case 'a':{
			string firstname, lastname;
			int number;
			cout<<"Enter a first and last name"<<endl;
			cin>>firstname;
			cin>>lastname;
			cout<<"Enter a number"<<endl;
			cin>>number;
			cin.clear();
			Contacts contact(firstname,lastname,number);
			bs.insert(contact);
			//cout<<"Contact successfully added!"<<endl;

			size +=1;
			break;
		}
//Load data
		case 'L': case 'l' :{
			string filename;
			int number;
			bool found = false;
			cout<<"Enter a filename"<<endl;
			cin.ignore();
			getline(cin, filename);
			loadData(filename);
			break;
		}
//Search for a contact
		case 'S': case 's':{
			string firstname;
			string lastname;
			int number;
			bool found = false;

			cout<<"Enter a first and last name"<<endl;
			cin.ignore();
			cin>>firstname;
			cin>>lastname;
			clock_t begin = clock();
			number = bs.getContact(firstname,lastname);
			clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

			if( number != -1){
				cout<<"Phone: "<<number<<endl;
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
			bool found = false;
			cout<<"Enter a first and last name"<<endl;
			cin.ignore();
			cin>>firstname;
			cin>>lastname;
			bs.filter(firstname, lastname);
			break;
		}
		default:break;
		}

//Leave the system
	} while(operation != 'Q' && operation!='q');

	cout<<"Bye!"<<endl;


	return 0;
}
