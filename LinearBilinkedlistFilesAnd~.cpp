MyList.h


#include <string>

struct Date {
    int day;
    int month;
    int year;
};

struct FileData {
    std::string catalogname;
    std::string fileName;
    std::string specification;
    Date creationDate;
    int fileSize;

};

class MyList {
public:
    MyList();
    ~MyList();

    void insert(FileData data);
    void removeFilesWithSpecPrefix(const std::string& prefix);
    void printAllFiles();
    void Sort();

private:
    struct Node {
        FileData data;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;
    int size;
};



MyList.cpp


#include <iostream>
#include "MyList.h"

MyList::MyList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}
MyList::~MyList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void MyList::insert(FileData data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void MyList::removeFilesWithSpecPrefix(const std::string& prefix) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.specification.compare(0, 1, prefix) == 0) {
            if ((current->prev) != nullptr)
                current->prev->next = current->next;
            else
                head = current->next;

            if ((current->next) != nullptr)
                current->next->prev = current->prev;
            else
                tail = current->prev;

            Node* temp = current;
            current = current->next;
            delete temp;
            size--;
        }
        else {
            current = current->next;
        }
    }
}

void MyList::printAllFiles() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Имя каталога: " << current->data.catalogname << std::endl;
        std::cout << "Имя файла: " << current->data.fileName << std::endl;
        std::cout << "Расширение: " << current->data.specification << std::endl;
        std::cout << "Дата создания: " << current->data.creationDate.day << "/"
            << current->data.creationDate.month << "/"
            << current->data.creationDate.year << std::endl;
        std::cout << "Размер файла (в байтах): " << current->data.fileSize << std::endl;
        std::cout << std::endl;

        current = current->next;
    }
}

void MyList::Sort() {
    if (size <= 1) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Node* current = head;

        while (current->next != nullptr) {
            if (current->data.fileName == current->next->data.fileName) {
                // Если имена файлов совпадают, сравниваем их расширения
                if (current->data.specification > current->next->data.specification) {
                    FileData temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
            }
            else if (current->data.fileName > current->next->data.fileName) {
                // Если имена файлов отличаются, сравниваем их имена
                FileData temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }

            current = current->next;
        }
    } while (swapped);
}



main.cpp

#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include "MyList.h"

// Функция для разделения строки на подстроки по заданному разделителю
std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        result.push_back(token);
    }

    return result;
}


int main() {
    SetConsoleOutputCP(1251);
    // Создание списка
    MyList fileList;

    // Чтение данных из файла
    std::ifstream inputFile("input.txt");
    std::string line;

    while (std::getline(inputFile, line)) {
        std::vector<std::string> data = splitString(line, '|');

        FileData fileData;
        fileData.catalogname = data[0];
        fileData.fileName = data[1];
        fileData.specification = data[2];
        fileData.creationDate.day = std::stoi(data[3]);
        fileData.creationDate.month = std::stoi(data[4]);
        fileData.creationDate.year = std::stoi(data[5]);
        fileData.fileSize = std::stoi(data[6]);

        fileList.insert(fileData);
    }

    fileList.Sort();
    // Удаление файлов с расширением, начинающейся с "~"
    fileList.removeFilesWithSpecPrefix("~");
    // Вывод списка файлов
    fileList.printAllFiles();

    return 0;
}
