#include<iostream>
#include<string>
#include"trie.h"
#include"Node.h"
using namespace std;
int main();
int main() {

        trie t;
        string cmd;
        


        while (cmd!="exit") {
            cin >> cmd;
            if (cmd == "i") {
                string word;
                cin >> word;
                    try {
                        t.insert(word);
                    }
                    catch (illegal_exception) {
                        cout << "illegal argument" << endl;
                    }
            }

            else if (cmd == "e") {
                string word;
                cin >> word;
                try {
                    t.erase(word);
                }
                catch (illegal_exception) {
                    cout << "illegal argument" << endl;
                }
                

            }
            else if (cmd == "s") {

                string word;
                cin >> word;

                try {
                    t.search(word);
                }
                catch (illegal_exception) {
                    cout << "illegal argument" << endl;
                }
                
            }
            else if (cmd == "print") {
                t.print();
            }
            else if (cmd == "autocomplete") {
                string input;
                getline(cin, input);
                int pos = input.find('*');
                string word = input.substr(1, pos-1);

                t.autocomplete(word);

            }
            else if (cmd == "empty") {
                t.empty();

            }
            else if (cmd == "clear") {
                t.clear();

            }
            else if (cmd == "size") {
                t.Size();
            }
            else if (cmd == "exit") {
                break;
            }
        }
	

	return 0;
}