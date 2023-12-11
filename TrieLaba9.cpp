.h

#pragma once
#include <iostream>
#include <string>
#include <windows.h>

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode* getNode();
void insert(TrieNode* root, std::string key);
void buildReverseTrie(TrieNode* root, TrieNode* reverseRoot);
void displayReverseWords(TrieNode* root, std::string word);
void displayWords(TrieNode* root, std::string word);

tree.cpp

#include "tree.h"

TrieNode* getNode() {
    TrieNode* node = new TrieNode;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    node->isEndOfWord = false;
    return node;
}

void insert(TrieNode* root, std::string key) {
    TrieNode* currentNode = root;
    int length = key.length();
    for (int i = length - 1; i >= 0; i--) {
        int index = key[i] - 'a';
        if (!currentNode->children[index]) {
            currentNode->children[index] = getNode();
        }
        currentNode = currentNode->children[index];
    }
    currentNode->isEndOfWord = true;
}

void buildReverseTrie(TrieNode* root, TrieNode* reverseRoot) {
    if (root->isEndOfWord) {
        reverseRoot->isEndOfWord = true;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            if (!reverseRoot->children[i]) {
                reverseRoot->children[i] = getNode();
            }
            buildReverseTrie(root->children[i], reverseRoot->children[i]);
        }
    }
}

void displayReverseWords(TrieNode* root, std::string word) {
    if (root == nullptr) {
        return;
    }

    if (root->isEndOfWord) {
        std::cout << word << std::endl;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != nullptr) {
            displayReverseWords(root->children[i], word + char('a' + i));
        }
    }
}
void displayWords(TrieNode* root, std::string word) {
    if (root == nullptr) {
        return;
    }

    if (root->isEndOfWord) {
        std::reverse(word.begin(), word.end());
        std::cout << word << std::endl;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != nullptr) {
            displayWords(root->children[i], word + char('a' + i));
        }
    }
}

main.cpp

#include <iostream>
#include <string>
#include <windows.h>
#include "tree.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    TrieNode* root = getNode();

    // Вставляем слова в Trie-дерево
    insert(root, "banana");
    insert(root, "apple");
    insert(root, "date");
    insert(root, "cherry");

    // Выводим слова в прямом порядке
    std::cout << "Слова в прямом порядке:\n";
    displayWords(root, "");

    TrieNode* reverseRoot = getNode();

    // Строим обратное Trie-дерево
    buildReverseTrie(root, reverseRoot);

    // Выводим слова в обратном порядке
    std::cout << "Слова в обратном порядке:\n";
    displayReverseWords(reverseRoot, "");

    return 0;
}
