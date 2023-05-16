#include <iostream>

// Определение структуры узла списка
struct Node {
    int data;
    Node* next;
};

// Функция для создания нового узла
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Функция для вставки элемента в упорядоченный список
Node* insertNode(Node* head, int value) {
    Node* newNode = createNode(value);

    // Если список пуст или вставляемое значение меньше головного элемента,
    // то вставляем новый узел в начало списка
    if (head == nullptr || value < head->data) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;

        // Поиск позиции для вставки нового узла
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }

        // Вставка нового узла
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}

// Функция для отображения списка
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Функция для освобождения памяти, занятой списком
void deleteList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    // Ввод чисел и вставка их в список
    int value;
    char choice;
    do {
        std::cout << "Введите число: ";
        std::cin >> value;

        head = insertNode(head, value);

        std::cout << "Продолжить ввод (y/n)? ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Отображение окончательного списка
    std::cout << "Окончательный список: ";
    displayList(head);

    // Освобождение памяти
    deleteList(head);

    return 0;
}
