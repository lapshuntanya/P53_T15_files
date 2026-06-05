#include <iostream>
#include <cstdio>
using namespace std;
void task0() {
    FILE* file = nullptr;

    //1 - Відкриття файлу
    //fopen_s(&file, "test.html", "w"); //VS
    file = fopen("test.txt", "w"); //CLion, Online

    if (file == nullptr)
        cout << "Error: not opened!!!" << endl;
    else {
        char name[100] = "Tetiana";
        int age = 35;

        //fprintf(file, "<h1> Hello,  %s. </h1> <p>I nam %d years old. </p>", name, age);
        fprintf(file, "<h1> Hello,  %s. </h1>", name);
        fprintf(file, "<p>I nam %d years old. </p>",age);

        fclose(file);
        cout << "Saved!\n";
    }
}

void task5() {
//5.Дано файл (task5.txt), елементами якого є числа (10 чисел). Надрукувати:
// а) перший елемент;
//     б) третій елемент;
//     в) п-й елемент;

    FILE *file = nullptr;
    //fopen_s(&file, "task5.txt", "r"); //VS
    file = fopen("task5.txt", "r"); //CLion, Online

    if (file == nullptr) {
        cout << "Error: not opened!\n";
    }else {
        //1 спосіб = ЗНАЄМО скільки чисел
        int buf = 0;
        for (int i =0 ; i < 10; i++) {
           // fscanf_s(file, "%d", &buf); //VS
            fscanf(file, "%d", &buf); //CLion, Online
            cout << buf << " ";
        }
        cout << endl;
        //Після першого прочитання курсор знаходиться в кінці
        //Переміщуємо курсор на початок файлу
        fseek(file, 0, SEEK_SET); //на 0 байт початку файла, SEEK_SET - константа початку файла

        //2 спосіб = НЕ ЗНАЄМО скільки чисел
        while (!feof(file)) {// поки НЕ кінець файлу
            // fscanf_s(file, "%d", &buf); //VS
            fscanf(file, "%d", &buf); //CLion, Online
            cout << buf << " ";
        }

        fclose(file);
    }

}

int main() {

    task5();




    return 0;
}