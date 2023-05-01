#include <iostream>
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    const unsigned char text[] = "компьютер,мышь,клавиатура.";
    const unsigned char simv[] = "кпстфхцчшщ";
    bool v[256] = { false };
    int i;
    for (i = 0; i < sizeof(text) - 1; ++i) {
        v[text[i]] = true;
    }
    bool has_consonants = false;
    for (i = 0; i < sizeof(simv) - 1; ++i) {
        if (!v[simv[i]]) {
            printf("%c ", simv[i]);
            has_consonants = true;
        }
    }
    if (!has_consonants) {
        printf("В заданной строке присутствуют все согласные буквы.");
    }
    return 0;
}
