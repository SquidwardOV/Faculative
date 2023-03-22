#include <iostream>
using namespace std;

struct student {
    string name;
    int noomer;
    int funcanaliz;
    int chismet;
    int economica;
};

void inputData(student* mas, int n) {
    for (int i = 0; i < n; i++)
        cin >> mas[i].name >> mas[i].noomer >> mas[i].funcanaliz >> mas[i].chismet >> mas[i].economica;
}

void bestlesson(student* mas, int n) {
    double sumfunc = 0.0, sumchis = 0.0, sumec = 0.0, srfunc, srchis, srec, max;
    for (int i = 0; i < n; i++) {
        sumfunc += mas[i].funcanaliz;
        sumchis += mas[i].chismet;
        sumec += mas[i].economica;
    }
    srfunc = sumfunc / n;
    srchis = sumchis / n;
    srec = sumec / n;
    if (srfunc > srchis && srfunc > srec) max = srfunc;
    else if (srchis > srfunc && srchis > srec) max = srchis;
    else max = srec;
    if (max == srfunc) {
        cout << "Лучше сдали функциональный анализ ";
    }
    else if (max == srchis) {
        cout << "Лучше сдали численные методы ";
    }
    else if (max == srec) {
        cout << "Лучше сдали экономику ";
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cin >> n;
    student* mas = new student[n];
    inputData(mas, n);
    bestlesson(mas, n);
    delete[] mas; // Освобождение динамической памяти
    return 0;
}
