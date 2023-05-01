#include <iostream>
#include <stdio.h>
#include <locale.h>

bool is_vowel(char c) {
    // Определяем является ли символ гласной буквой
    const char vowels[] = "аеёиоуыэюя";
    for (int i = 0; i < sizeof(vowels) - 1; ++i) {
        if (c == vowels[i]) {
            return true;
        }
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    const unsigned char text[] = "компьютер, мышь, клавиатура.";
    bool v[256] = { true };
    for (int i = 0; i < sizeof(text) - 1; ++i) {
        // Если символ является буквой и это не начало слова
        if (isalpha(text[i]) && !isspace(text[i - 1])) {
            // Изменяем значение гласной буквы на true
            v[tolower(text[i])] = true;
        } else {
            // Для начала нового слова сбрасываем все флаги гласных букв
            for (int j = 0; j < sizeof(v) / sizeof(v[0]); ++j) {
                v[j] = true;
            }
        }
    }
    // Выводим гласные буквы, которые встречаются в каждом слове
    for (int i = 0; i < sizeof(v) / sizeof(v[0]); ++i) {
        if (is_vowel(i) && v[i]) {
            printf("%c ", i);
        }
    }
    return 0;
}
