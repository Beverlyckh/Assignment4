/*
 * BinarySearchTree.h
 *
 *  Created on: Oct 30, 2017
 *      Author: fatma.serce
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <iostream>
#include <stack>
using namespace std;

template <class T>
struct node{
	T data;
	node<T>* left;
	node<T>* right;
};

template <class T>
class BinarySearchTree{
private:
	node<T>* root;
	void inOrderT(node<T>*);
	void preOrderT(node<T>*);
	void postOrderT(node<T>*);
	void destroy(node<T>*);
	int treeHeight(node<T>*);
	int max(int, int);
	int treeNodeCount(node<T>*);
	int treeLeaveCount(node<T>*);
	void treeInsert(node<T>*&, T&);
	bool treeSearch(node<T>*, T&);
	node<T>* findMax(node<T>*);
	void deletenode(node<T>*&, T&);
	int findContact(node<T>* p,string firstname,string lastname);
	void printFilteredContacts(node<T>* p,string& firstname, string lastname);
public:
	BinarySearchTree();
	void inOrder(){inOrderT(root);}
	void preOrder(){preOrderT(root);}
	void postOrder(){postOrderT(root);}
	int height(){return treeHeight(root);}
	int nodeCount(){return treeNodeCount(root);}
	int leaveCount(){return treeLeaveCount(root);}
	void insert(T& item){treeInsert(root, item);}
	bool search(T& item){return treeSearch(root,item);}
	//	void insert(T&); //non-recursive function call
	node<T>* findMax(){return findMax(root);}
	void deletenode(T& item){deletenode(root, item);}
	int getContact(string firstname, string lastname);
	void filter(string firstname, string lastname);
	~BinarySearchTree(){destroy(root);}

};

template <class T>
BinarySearchTree<T>::BinarySearchTree(){
	root = NULL;
}

template <class T>
int BinarySearchTree<T>::getContact(string firstname, string lastname){

	return findContact(root,firstname, lastname);

}


template <class T>
int BinarySearchTree<T>::findContact(node<T>* p,string firstname, string lastname){

	if(p == NULL)
		return -1;
	else if(firstname == p->data.getFirstname() && lastname == p->data.getLastname()){
		return p->data.getNumber();
	}
	else if(lastname <  p->data.getLastname())
		return findContact(p->left, firstname,lastname);
	else if(lastname  >p->data.getName())
		return findContact(p->right, firstname,lastname);
	return -1;
}

template <class T>
void BinarySearchTree<T>::inOrderT(node<T>* p){
	if(p!=NULL){
		inOrderT(p->left);
		cout<<p->data;
		inOrderT(p->right);
	}
}


template <class T>
void  BinarySearchTree<T>::filter(string firstname, string lastname){
	if(getContact(firstname, lastname) != -1){
		printFilteredContacts(root , firstname, lastname);
	}
}


template <class T>
void  BinarySearchTree<T>::printFilteredContacts(node<T>* p,string& firstname, string lastname){


//	if(p != NULL && p->data.getLastname() < lastname){
//		printFilteredContacts(p->left,firstname, lastname);
//	}
//	if(p != NULL)
//	  cout<<p->data<<endl;
//		printFilteredContacts(p->right,firstname, lastname);
	if(p == NULL){
		return;
	}
    node<T>* cp = root;
    stack <node<T>*> st ;
	for(;;){
		while(cp ){
			st.push(cp);
			cp= cp->left;
		}
		if(st.empty()){
			break;
		}
		cp = st.top();
		st.pop();
		if(cp->data.getLastname() < lastname)
			cout<<cp->data<<" ";;
		cp = cp->right;
	}



	return ;
}


//inorder traversal without recursion
//template <class T>
//void BinarySearchTree<T>::inOrderT(node<T>* p){
//	stack< node<T>* > s;
//	while(p!= NULL || !s.isEmpty())
//	if(p!= NULL){
//		s.push(p);
//		p = p->left;
//	}else{
//		p = s.pop();
//		cout<<p->data:
//		p = p->right;
//	}
//}

template <class T>
void BinarySearchTree<T>::preOrderT(node<T>* p){
	if(p!=NULL){
		cout<<p->data;
		preOrderT(p->left);
		preOrderT(p->right);
	}
}

template <class T>
void BinarySearchTree<T>::postOrderT(node<T>* p){
	if(p!=NULL){
		postOrderT(p->left);
		postOrderT(p->right);
		cout<<p->data;
	}
}
template <class T>
int BinarySearchTree<T>::max(int x, int y){
	if (x>y)
		return x;
	return y;
}

template <class T>
int BinarySearchTree<T>::treeHeight(node<T>* p){
	if(p!=NULL){
		return 1 + max(height(p->left, p->right));
	}
	return 0;
}

template <class T>
int BinarySearchTree<T>::treeNodeCount(node<T>* p){
	if(p==NULL)
		return 0;
	else
		return 1 + treeNodeCount(p->left) + treeNodeCount(p->right);
}
template <class T>
int BinarySearchTree<T>::treeLeaveCount(node<T>* p){
	if(p==NULL)
		return 0;
	else if(p->left==NULL && p->right==NULL)
		return 1;
	else
		return treeLeaveCount(p->left) + treeLeaveCount(p->right);
}
template <class T>
void BinarySearchTree<T>::destroy(node<T>* p){
	if(p!= NULL){
		destroy(p->left);
		destroy(p->right);
		delete p;
		p= NULL;
	}
}
//non recursive insert function
//template <class T>
//void BinarySearchTree<T>::insert(T& item){
//	node<T>* newnode = new node<T>();
//	newnode->data = item;
//	newnode->left = newnode->right = NULL;
//	if(root == NULL){
//		root = newnode;
//	}
//	else{
//		node<T>* p = root;
//		node<T>* q;
//		while(p!=NULL){
//			q = p;
//			if(item==p->data){
//				cout<<p->data;
//				cout<<"error"<<endl;
//				return;
//			}
//			else if (item<p->data)
//				p = p->left;
//			else
//				p = p->right;
//		}
//		if(item<q->data)
//			q->left = newnode;
//		else
//			q->right = newnode;
//	}
//
//}
template <class T>
void BinarySearchTree<T>::treeInsert(node<T>*& p, T& item){
	if(p == NULL){
		p = new node<T>;
		p->data = item;
		p->left = p->right = NULL;
	}
	else if(item<p->data){
		treeInsert(p->left, item);
	}else{
		treeInsert(p->right, item);
	}

}

template <class T>
bool BinarySearchTree<T>::treeSearch(node<T>* p, T& item){
	if(p == NULL)
		return false;
	else if(item<p->data)
		return treeSearch(p->left, item);
	else if(item>p->data)
		return treeSearch(p->right, item);
	return true;
}

template <class T>
node<T>* BinarySearchTree<T>::findMax(node<T>* p){
	if (p==NULL)
		return NULL;
	else if(p->right == NULL)
		return p;
	else
		return findMax(p->right);
}

template <class T>
void BinarySearchTree<T>::deletenode(node<T>*& p, T& item){
	//item not found, do nothing
	if(p == NULL)
		return;
	else if (item<p->data)	//item is on the left subtree
		deletenode(p->left, item);
	else if (item>p->data)	//item is on the right subtree
		deletenode(p->right, item);
	else{//item is equal to data,  it is found
		if(p->left!= NULL && p->right != NULL){	//if it is with two children
			p->data = findMax(p->left)->data;
			deletenode(p->left, p->data);
		}else{
			node<T>* old = p;
			if(p->left != NULL)
				p = p->left;
			else
				p = p->right;

			delete old;
		}
	}
}



#endif /* BINARYSEARCHTREE_H_ */
