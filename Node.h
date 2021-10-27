#pragma once
#include<iostream>
#include<string>
using namespace std;

class Node {
private:
	char c;
	bool isWord;
	Node** children;

public:
	friend class trie;
	Node(char letter);
	





};



