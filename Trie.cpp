tree.h

#pragma once
#include <iostream>
#include <string>
#include <windows.h>

#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode* getNode();

void insert(TrieNode* root, string key); //Вставка ключа 
void printTrie(TrieNode* root, string prefix); // Вывод дерево
void reverseTrie(TrieNode* root, string prefix);// Замена порядка слов
void deleteNode(TrieNode* root, string key);


tree.cpp

#include "tree.h"

TrieNode* getNode() {
    TrieNode* node = new TrieNode;

    node->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }

    return node;
}

void insert(TrieNode* root, string key) {
    TrieNode* currentNode = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';

        if (!currentNode->children[index]) {
            currentNode->children[index] = getNode();
        }

        currentNode = currentNode->children[index];
    }

    currentNode->isEndOfWord = true;
}

void reverseTrie(TrieNode* root, string prefix) {
    if (root->isEndOfWord) {
        cout << prefix << endl;
    }

    for (int i = ALPHABET_SIZE - 1; i >= 0; i--) {
        if ((root->children[i])!=nullptr) {
            char c = i + 'a';
            reverseTrie(root->children[i], prefix + c);
        }
    }
}

void deleteNode(TrieNode* root, string key) {
    TrieNode* currentNode = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';

        if (!currentNode->children[index]) {
            cout << "Узел не найден" << endl;
            return;
        }

        currentNode = currentNode->children[index];
    }

    if (!currentNode->isEndOfWord) {
        cout << "Узел не найден" << endl;
        return;
    } else {
        currentNode->isEndOfWord = false;
    }

    cout << "Узел успешно удален" << endl;
}

void printTrie(TrieNode* root, string prefix) {
    if (root->isEndOfWord) {
        cout << prefix << endl;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            char c = i + 'a';
            printTrie(root->children[i], prefix + c);
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

    // Вставляем элементы в trie дерево
    insert(root, "hello");
    insert(root, “world");
    insert(root, "hi");
    insert(root, “tree”);
    insert(root, "hey");

    cout << "Слова из обычного дерева:" << endl;
    printTrie(root, "");

    cout << endl;

    cout << "Слова из развернутого дерева:" << endl;
    reverseTrie(root, "");

    cout << endl;

    // Удаление узла
    deleteNode(root, "world");

    cout << endl;

    cout << "Слова из обычного дерева после удаления узла:" << endl;
    printTrie(root, "");

    return 0;
}
