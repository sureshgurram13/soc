#include "trie.h"
#include <iostream>

Trie::Trie()
{
	root = NULL;
}

// Returns new trie node (initialized to NULLs)
struct TrieNode* Trie::getNode(void)
{
	TrieNode* root = new TrieNode();
	return root;	
}

// If not present, inserts key into trie. If the
// key is prefix of trie node, just marks leaf node
void Trie::insert(struct TrieNode* root, const std::string key)
{
	
	TrieNode* currentNode = root;

	for (auto c : key) {

		if (currentNode->children[c - 'a'] == NULL) {
			TrieNode* newNode = new TrieNode();
			currentNode->children[c - 'a'] = newNode;
		}

		currentNode = currentNode->children[c - 'a'];
	}

	currentNode->isWordEnd = 1;

}

bool Trie::search(struct TrieNode *root, std::string key)
{
	
	TrieNode* currentNode = root;

	for (auto c : key) {

		if (currentNode->children[c - 'a'] == NULL) {
			return false;
		}

		currentNode = currentNode->children[c - 'a'];
	}

	return (currentNode->isWordEnd == true);

}

// Returns 0 if current node has a child
// If all children are NULL, return 1.
bool Trie::isLastNode(struct TrieNode* root)
{
	for(int i=0;i<26;i++){
		if(root->children[i] != NULL){return false;}
	}
	return true;
}

// Recursive function to print auto-suggestions for given
// node.
void Trie::suggestionsRec(struct TrieNode* root,
					std::string currPrefix)
{
	// found a std::string in Trie with the given prefix

    if (root->isWordEnd) {
        std::cout << currPrefix << std::endl;
    }

    for (char c = 'a'; c <= 'z'; c++) {
        TrieNode* nextNode = root->children[c - 'a'];
        if (nextNode != nullptr) {
            suggestionsRec(nextNode, currPrefix + c);
        }
    }

}

// print suggestions for given query prefix.
int Trie::printAutoSuggestions(TrieNode* root, const std::string query)
{

	TrieNode* currentNode = root;

	for(auto c : query){

		if(currentNode->children[c - 'a'] == NULL){return 0;}
		currentNode = currentNode->children[c - 'a'];

	}

    // // If the prefix is present as a word
    // bool isWord = (currentNode->isWordEnd == true);

    // // If the prefix is the last node of the path and no further nodes
    // bool isLast = true;
    // for (int i = 0; i < 26; i++) {
    //     if (currentNode->children[i] != nullptr) {
    //         isLast = false;
    //         break;
    //     }
    // }

    // // If the prefix is present as a word and there are no further nodes
    // if (isWord && isLast) {
    //     std::cout << query << std::endl;
    //     return -1;
    // }

    // // If there are further nodes, print all children
    // if (!isLast) {
    //     suggestionsRec(currentNode, query);
    //     return 1;
    // }

	suggestionsRec(currentNode, query);

    return 1;


}



	// TrieNode* currentNode = root;

	// for(auto c : currPrefix){

	// 	if(currentNode->children[c - 'a'] == NULL){return;}
	// 	currentNode = currentNode->children[c - 'a'];

	// }
