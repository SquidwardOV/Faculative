//list.h
#pragma once

#include <iostream>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
        Node(Node* other) {
            data = other->data;
            next = nullptr;
        }
    };

    Node* head;

public:
    List() : head(nullptr) {}

    ~List() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(Node* node) {
        if (head == nullptr) {
            head = new Node(node);
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Node(node);
        }
    }

    void insert(const T& value, Node* position) {
        if (position == nullptr) {
            if (head == nullptr) {
                Node* newNode = new Node(value);
                newNode->next = head;
                head = newNode;
            }
            else {
                Node* newNode = new Node(value);
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }

        }
        else {
            Node* newNode = new Node(value);
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Удаление элемента по итератору
    void erase(Node* position) {
        if (head == nullptr || position == nullptr || position->next == nullptr) {
            return;
        }

        Node* temp = position->next;
        position->next = temp->next;
        delete temp;
    }

    List* merge(const List& other) {
        List* out = new List();

        Node* temp = other.head;
        Node* mainListtemp = head;
        while (mainListtemp != nullptr) {
            out->insert(mainListtemp);
            mainListtemp = mainListtemp->next;
        }
        while (temp != nullptr) {
            out->insert(temp);
            temp = temp->next;
        }
        return out;
    }

    // Слияние упорядоченных списков
    List* mergeSorted(const List& other) {
        List* out = new List();

        Node* temp = other.head;
        Node* mainListtemp = head;
        while (mainListtemp != nullptr) {
            out->insert(mainListtemp);
            mainListtemp = mainListtemp->next;
        }
        while (temp != nullptr) {
            out->insert(temp);
            temp = temp->next;
        }
        Node* iteratorI = out->head;
        Node* iteratorJ = out->head->next;
        while (iteratorI->next != nullptr) {
            while (iteratorJ != nullptr) {
                if (iteratorI->data > iteratorJ->data) {
                    T date = iteratorI->data;
                    iteratorI->data = iteratorJ->data;
                    iteratorJ->data = date;
                }
                iteratorJ = iteratorJ->next;

            }
            iteratorI = iteratorI->next;
            iteratorJ = iteratorI->next;
        }
        return out;

    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const List<T>& list) {
        Node* temp = list.head;
        while (temp != nullptr) {
            os << temp->data << " ";
            temp = temp->next;
        }
        return os;
    }

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& is, List<T>& list) {
        T value;
        while (is >> value) {
            list.insert(value, nullptr);
        }
        return is;
    }

    // Итераторы
    class Iterator {
    public:
        Node* current;

        Iterator(Node* node) : current(node) {}

        T& operator*() const {
            return current->data;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() const {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }

    void insert(const T& value, Iterator position) {
        if (position.current == nullptr) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* newNode = new Node(value);
            newNode->next = position.current->next;
            position.current->next = newNode;
        }
    }

    // Удаление элемента по итератору
    void erase(Iterator position) {
        if (head == nullptr || position.current == nullptr || position.current->next == nullptr) {
            return;
        }

        Node* temp = position.current->next;
        position.current->next = temp->next;
        delete temp;
    }
};

//main.cpp
#include <iostream>
#include "List.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    List<int> myList;

    // Ввод элементов списка с клавиатуры
    std::cout << "Введите элементы списка (окончание ввода - любой не числовой символ): ";
    std::cin >> myList;

    std::cout << "Список: " << myList << std::endl;

    // Проверка работы итераторов
    std::cout << "Элементы списка с использованием итератора: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Добавление элемента по итератору
    auto it = myList.begin();
    ++it;  // Переходим ко второму элементу
    myList.insert(100, it);
    std::cout << "Список после добавления элемента: " << myList << std::endl;

    // Удаление элемента по итератору
    ++it;  // Переходим к третьему элементу
    myList.erase(it);
    std::cout << "Список после удаления элемента: " << myList << std::endl;

    // Создание второго списка
    List<int> otherList;
    otherList.insert(500, nullptr);
    otherList.insert(600, nullptr);
    otherList.insert(700, nullptr);

    std::cout << "Список 2: " << otherList << std::endl;

    // Слияние двух списков
    std::cout << "Слияние списков: " << *myList.merge(otherList) << std::endl;

    //Упорядоченное слияние двух списков
    std::cout << "Упорядоченное слияние списков: "  << * myList.mergeSorted(otherList) << std::endl;

    return 0;
}
