#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <locale> // добавлено для работы с русским языком

using namespace std;

bool isletter(string str) {
    string alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    for (int i = 0; i < str.length(); i++) {
        bool found = false;
        for (int j = 0; j < alphabet.length(); j++) {
            if (tolower(str[i]) == tolower(alphabet[j])) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string str, s;
    setlocale(LC_ALL, "ru"); // добавлено для работы с русским языком
    cout << "Введите текст: ";
    getline(cin, s); // использована функция getline для считывания всей строки
    stringstream ss(s);
    bool last_is_letter = false;
    while (getline(ss, str, ' ')){
        if (!isletter(str)) {
            cout << str << endl;
            last_is_letter = false;
        }
        else {
            last_is_letter = true;
        }
    }
    return last_is_letter; // возвращается true, если последнее слово было буквенным, иначе false
}
