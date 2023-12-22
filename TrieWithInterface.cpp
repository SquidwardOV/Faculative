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
void printTrie(TrieNode* root, string word); // Вывод дерево
void reverseTrie(TrieNode* root, string word);// Замена порядка слов
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

void reverseTrie(TrieNode* root, string word) {
	if (root->isEndOfWord) {
		cout << word << endl;
	}

	for (int i = ALPHABET_SIZE - 1; i >= 0; i--) {
		if ((root->children[i]) != nullptr) {
			char c = i + 'a';
			reverseTrie(root->children[i], word + c);
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
	}
	else {
		currentNode->isEndOfWord = false;
	}

	cout << "Узел успешно удален" << endl;
}

void printTrie(TrieNode* root, string word) {
	if (root->isEndOfWord) {
		cout << word << endl;
	}

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (root->children[i]) {
			char c = i + 'a';
			printTrie(root->children[i], word + c);
		}
	}
}


main

#include <iostream>
#include <string>
#include <windows.h>
#include "tree.h"

using namespace std;

enum Option { ADD = 1, REMOVE, PRINT, REVERSE, EXIT };

Option getOption() {
	int option;
	cout << "Выберите опцию:\n";
	cout << "1. Добавление\n";
	cout << "2. Удаление\n";
	cout << "3. Вывод\n";
	cout << "4. Вывод слов из обратного дерева\n";
	cout << "5. Выход из цикла\n";
	cout << "Ваш выбор: ";
	cin >> option;
	cout << endl;
	return static_cast<Option>(option);
}

int main() {
	SetConsoleOutputCP(1251);

	TrieNode* root = getNode();

	Option option;
	do {
		option = getOption();

		if (option == ADD) {
			string word;
			cout << "Введите слово для добавления: ";
			cin >> word;
			insert(root, word);
		}
		else if (option == REMOVE) {
			string word;
			cout << "Введите слово для удаления: ";
			cin >> word;
			deleteNode(root, word);
		}
		else if (option == PRINT) {
			cout << "Слова из обычного дерева:" << endl;
			printTrie(root, "");
			cout << endl;
		}
		else if (option == REVERSE) {
			cout << "Слова из развернутого дерева:" << endl;
			reverseTrie(root, "");
			cout << endl;
		}

	} while (option != EXIT);

	return 0;
}
