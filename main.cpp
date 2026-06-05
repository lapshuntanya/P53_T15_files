#include <iostream>
#include <cstdio>
using namespace std;

int main() {

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




    return 0;
}