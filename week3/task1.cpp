// task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <fstream>

struct Student {
    int facNum; // -> 4 bytes
    char name[64]; // -> 64 bytes
};

void writeStudents(const Student students[], const char* path) {
    std::ofstream out(path, std::ios::binary);

    if (!out) {
        std::cout << "Cannot open file" << std::endl;
        return;
    }

    for (int i = 0; i < 3; i++) {
        out.write((char*)&students[i], sizeof(Student));
    }

    out.close();
}

int main() {
    Student students[3];
    students[0].facNum = 71935;
    strcpy(students[0].name, "Mitko");
    students[1].facNum = 70461;
    strcpy(students[1].name, "Atanas");
    students[2].facNum = 72005;
    strcpy(students[2].name, "Ivo");

    writeStudents(students, "students.bin");
} 

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
