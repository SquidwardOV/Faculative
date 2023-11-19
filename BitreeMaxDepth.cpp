Tree.h

#pragma once

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
public:
    BinaryTree(); // Конструктор
    ~BinaryTree(); // Деструктор

    // Функции для работы с деревом
    int findMaxDepth();
    void insert(int value);
    void remove(int value);
    struct Trunk
    {
        Trunk* prev;
        std::string str;

        Trunk(Trunk* prev, std::string str)
        {
            this->prev = prev;
            this->str = str;
        }
    };

    // Вспомогательная функция для печати ветвей бинарного дерева
    void showTrunks(Trunk* p)
    {
        if (p == nullptr) {
            return;
        }

        showTrunks(p->prev);
        std::cout << p->str;
    }

    void printTree(Node* root, Trunk* prev, bool isLeft)
    {
        if (root == nullptr) {
            return;
        }

        std::string prev_str = "    ";
        Trunk* trunk = new Trunk(prev, prev_str);

        printTree(root->right, trunk, true);

        if (!prev) {
            trunk->str = "---";
        }
        else if (isLeft)
        {
            trunk->str = ".---";
            prev_str = "   |";
        }
        else {
            trunk->str = "`---";
            prev->str = prev_str;
        }

        showTrunks(trunk);

        std::cout << " " << root->data << std::endl;
        if (prev) {
            prev->str = prev_str;
        }
        trunk->str = "   |";

        printTree(root->left, trunk, false);
    }
    void Print() {
        printTree(root, nullptr, false);
    }

private:
    // Вспомогательные функции
    void deleteTree(Node* root);
    int findMaxDepth(Node* root);
    Node* insert(Node* root, int value);
    Node* remove(Node* root, int value);
    Node* findMin(Node* root);


    // Корень дерева
    Node* root;
};

Tree.cpp

#include "Tree.h"
#include <iostream>

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    // Вызываем функцию удаления всех узлов дерева, начиная с корня
    deleteTree(root);
}

int BinaryTree::findMaxDepth() {
    return findMaxDepth(root);
}

void BinaryTree::insert(int value) {
    root = insert(root, value);
}

void BinaryTree::remove(int value) {
    root = remove(root, value);
}

int BinaryTree::findMaxDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = findMaxDepth(root->left);
    int rightDepth = findMaxDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

Node* BinaryTree::insert(Node* root, int value) {
    // Если дерево пусто, создаем новый узел с заданным значением
    if (root == nullptr) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    // Рекурсивно вставляем элемент в правое поддерево, если значение больше текущего узла
    if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // Или в левое поддерево, если значение меньше или равно текущему узлу
    else {
        root->left = insert(root->left, value);
    }

    return root;
}

Node* BinaryTree::remove(Node* root, int value) {
    // Если дерево пусто, ничего не делаем
    if (root == nullptr) {
        return nullptr;
    }

    // Рекурсивно ищем узел для удаления в правом поддереве, если значение больше текущего узла
    if (value > root->data) {
        root->right = remove(root->right, value);
    }
    // Или в левом поддереве, если значение меньше текущего узла
    else if (value < root->data) {
        root->left = remove(root->left, value);
    }
    // Найден узел для удаления
    else {
        // Узел с одним или без детей
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Узел с двумя детьми, находим минимальное значение в правом поддереве
        Node* temp = findMin(root->right);

        // Копируем значение минимального узла в текущий узел
        root->data = temp->data;

        // Рекурсивно удаляем минимальный узел из правого поддерева
        root->right = remove(root->right, temp->data);
    }

    return root;
}

Node* BinaryTree::findMin(Node* root) {
    // Идем влево до самого конца дерева, так как минимальный элемент всегда будет самым левым
    while (root != nullptr && root->left != nullptr) {
        root = root->left;
    }

    return root;
}
struct Trunk {
    Trunk* prev;
    std::string str;

    Trunk(Trunk* prev, std::string str) : prev(prev), str(str) {}
};


void BinaryTree::deleteTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    // Рекурсивно удаляем все узлы в левом и правом поддеревьях
    deleteTree(root->left);
    deleteTree(root->right);

    // Удаляем текущий узел
    delete root;
}


main.cpp

#include "Tree.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    // Создаем объект бинарного дерева
    BinaryTree tree;

    // Добавляем элементы в дерево
    tree.insert(1);
    tree.insert(2);
    tree.insert(6);
    tree.insert(4);
    tree.insert(3);
    tree.insert(5);
    tree.insert(6);
    tree.insert(4);

    tree.Print();
    std::cout << std::endl;
    tree.remove(4);
    tree.Print();
    // Находим максимальную глубину дерева
    int depth = tree.findMaxDepth();
    cout << "Максимальная глубина дерева: " << depth << endl;
    system("pause");
}
