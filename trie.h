#pragma once
#include<iostream>
#include"Node.h"


using namespace std;
class trie {

private:
	int size;
	Node* root;
	int firstword = 0;

public:

	trie();
	void insert(string w);
	void insert_h(string w, Node* n);
	void erase(string w);
	void erase_h(Node* &n, string w, int index);
	bool isempty(Node* n);
	void search(string w);
	void search_h(string w, Node* n, string temp);
	void print();
	void print_h(Node* n, string word);
	void autocomplete(string prefix);
	void autocomplete_h(Node* n, string p, int index);
	void empty();
	bool empty_h();
	void clear();
	void clear_h(Node* n);
	int Size();

};

class illegal_exception {

};

