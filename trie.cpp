#include<iostream>
#include"trie.h"
#include<vector>
#include<string>

using namespace std;

Node::Node(char letter) {
	c = letter;
	isWord = false;
	children = new Node*[26];
	for (int i = 0; i < 26; i++) {
		children[i] = nullptr;
	}
}

trie::trie() {
	root = new Node('\0');
	size = 0;
}



void trie::insert(string w) {
	Node* current = root;
	int counter = 0;
	insert_h(w, current);
}

void trie::insert_h(string w, Node* n) {

	if (0 == w.length()) {
		if (n->isWord == false) {
			cout << "success" << endl;
			n->isWord = true;
			size++;
		}
		else {
			cout << "failure" << endl;
		}

	}
	else {
		char c = w.at(0);
		int index = c - 'a';

		if (c >= 97 && c<= 122) {
			if (n->children[index] == nullptr) {
				n->children[index] = new Node(c);
			}
			n = n->children[index];
			insert_h(w.substr(1, w.length() - 1), n);
		}
		else {
			throw illegal_exception();
		}
		
	}


}



void trie::erase(string w) {
	 erase_h(root, w, 0);
}

void trie::erase_h(Node* &n, string w, int index) {
	int pos = w[index] - 'a';
	if (n->children[pos] == nullptr && index!= w.length() && (w[index]>=97 && w[index]<=122)) {
		cout << "failure" << endl;
	} 
	if (n->isWord && index == w.length()) {
		size--;
		cout << "success" << endl;

		if (isempty(n)) {
			delete n;
			n = nullptr;
		}
		else {
			n->isWord = false;
		}
		return;
	}
	else {
		if (w[index] >= 97 && w[index] <= 122) {
			if (n->children[pos] != nullptr) {
				erase_h(n->children[pos], w, index + 1);
				
					if ( !n->isWord && isempty(n)&& n!=root) {
						delete n;
						n = nullptr;
					}
					return;
			}
		}
		else {
			if (index==w.length()) {
				cout << "failure" << endl;
			}
			else {
				throw illegal_exception();
			}
		}
	}
}




bool trie::isempty(Node* n) {
	for (int i = 0; i < 26; i++) {
		if (n->children[i] != nullptr) {
			return false;
		}
		
	}
	return true;
}



void trie::search(string w) {
	Node* curr = root;
	search_h(w, curr,w);
}

void trie::search_h(string w, Node* n, string temp) {

	if (0 == w.length()) {
		if (n != nullptr && n->isWord) {
			cout << "found " << temp << endl;
		}
		else {
			cout << "not found" << endl;
		}
	}
	else {
		char c = w.at(0);
		int index = c - 'a';
		if (c >= 97 && c <= 122) {
			if (n->children[index] == nullptr) {
				n->isWord = false;
				cout << "not found" << endl;
			}
			else {
				search_h(w.substr(1, w.length() - 1), n->children[index], temp);
			}
		}
		else {
			throw illegal_exception();
		}
	}
}



void trie::print() {
	Node* current = root;
	string word = "";
	print_h(current, word);
	if (size > 0) {
		cout << endl;
	}
	firstword = 0;

}

void trie::print_h(Node* n, string word) {

	if (n->isWord) {
		if (firstword == 0) {
			cout << word;
			firstword = 1;
		}
		else {
			cout << " " << word;
		}

	}
	for (int i = 0; i < 26; i++) {
		if (n->children[i] != nullptr) {
			
			print_h(n->children[i], word + static_cast<char> (i + 'a'));
		}
	}


}


void trie::autocomplete(string prefix) {
	Node* current = root;
	autocomplete_h(current, prefix, 0);
	

}

void trie::autocomplete_h(Node* n, string prefix, int index) {
	if (empty_h()) {
		cout << "";
		return;
	}
	int pos = prefix[index] - 'a';

	if (index == prefix.length()) {
		print_h(n, prefix);
		if (firstword == 1) {
			cout << endl;
		}
		firstword = 0;
	}
	else {
			if (n->children[pos] != nullptr) {
				autocomplete_h(n->children[pos], prefix, index + 1);
			}
			else {
				cout << "";
			}
	}
}



void trie::empty() {

	if (size == 0) {
		cout << "empty 1" << endl;
	}
	else {
		cout << "empty 0" << endl;
	}

}

bool trie::empty_h() {
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}


void trie::clear() {
	clear_h(root);
	size = 0;
	cout << "success" << endl;
}

void trie::clear_h(Node* n) {
	
	if (n->isWord) {
		return;
	}else{
		for (int i = 0; i < 26; i++) {
			if (n->children[i] != nullptr) {
				clear_h(n->children[i]);
				delete(n->children[i]);
				n->children[i]= nullptr;
			}
		}
	}
}



int trie::Size() {
	cout << "number of words is " << size << endl;
	return size;
}





