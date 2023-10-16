Stack.h

  class Stack {

public:
    Stack();
    Stack(int* arr, int size);
    ~Stack();
    void push(int value);
    void pop();
    bool isEmpty();
    void print();
    int peek();

private:
    int* array;  // Динамический массив для хранения элементов стека
    int capacity;  // Размер выделенной памяти для динамического массива
    int top;  // Индекс вершины стека

private:
    void resize();
};


Stack.cpp

#include "stack.h"
#include <iostream>

Stack::Stack() {
    capacity = 1;  // Используем емкость по умолчанию равную 1
    array = new int[capacity];
    top = -1;  // Инициализируем вершину стека значением -1 (пустой стек)
}

Stack::Stack(int* arr, int size) {
    capacity = size;  // Используем переданный размер массива
    array = new int[capacity];
    top = -1;  // Инициализируем вершину стека значением -1 (пустой стек)

    for (int i = 0; i < size; ++i) {
        push(arr[i]);
    }
}

Stack::~Stack() {
    delete[] array;  // Освобождаем память, выделенную для динамического массива
}

void Stack::push(int elem) { //Добавление элемента
    if (top == capacity - 1) {
        resize();  // Увеличиваем емкость стека, если достигли максимального размера
    }
    array[++top] = elem;  // Увеличиваем вершину и добавляем элемент в массив
    std::cout << "Добавлен элемент: " << elem << std::endl;
}

void Stack::pop() { //Удаление элемента
    if (isEmpty()) {
        std::cout << "Стек пуст!" << std::endl;
    }
    else {
        int elem = array[top--];  // Удаляем элемент из массива и уменьшаем вершину
        std::cout << "Удален элемент: " << elem << std::endl;
    }
}

bool Stack::isEmpty() { //Проверка на пустоту
    return (top == -1);  // Если вершина равна -1, значит стек пуст
}

void Stack::print() {
    if (isEmpty()) {
        std::cout << "Стек пуст!" << std::endl;
    }
    else {
        std::cout << "Элементы стека: ";
        for (int i = top; i >= 0; --i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
}

int Stack::peek() { //указатель на вершину
    if (isEmpty()) {
        std::cout << "Стек пуст!" << std::endl;
    }
    else {
        return array[top];  // Возвращаем элемент на вершине стека
    }
}

void Stack::resize() { //довыделение памяти
    capacity *= 2;  // Увеличиваем емкость

    int* newArray = new int[capacity];  // Создаем новый динамический массив

    for (int i = 0; i <= top; ++i) {
        newArray[i] = array[i];  // Копируем элементы из старого массива в новый
    }

    delete[] array;  // Удаляем старый массив

    array = newArray;  // Переназначаем указатель на новый массив
}


main.cpp

  #include <iostream>
#include <Windows.h>
#include "stack.h"

int main() {
    SetConsoleOutputCP(1251);
    int arr[] = { 5, 10, 15, 20, 25 };
    int size = sizeof(arr) / sizeof(arr[0]);

    Stack stack(arr, size);

    stack.print();
    std::cout << "Вершина стека: " << stack.peek() << std::endl;

    stack.pop();
    stack.pop();

    stack.print();
    std::cout << "Вершина стека: " << stack.peek() << std::endl;

    return 0;
}
