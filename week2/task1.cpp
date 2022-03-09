// task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

struct Student {
    int fn;
    char name[32];
    double grade;
};
void writeStudents(Student students[], std::ofstream& out) {
    for (int i = 0; i < 3; i++)
    {
        out << students[i].fn << '\n';
        out << students[i].name << '\n';
        out << students[i].grade << '\n';
    }

}

void writeStudents(Student students[], const char* path) {
    std::ofstream out;
     out.open(path);
     for (int i = 0; i < 3; i++)
     {
         out << students[i].fn << '\n';
         out << students[i].name << '\n';
         out << students[i].grade << '\n';
     }

     out.close();
}

const int BUFFER_SIZE = 100;
void readStudents(const char* path) {
    std::ifstream in(path);
    if (!in.is_open())
    {
        std::cout << "File is not open!";
        return;
    }

    while (!in.eof())
    {
        char line[BUFFER_SIZE];
        in.getline(line, BUFFER_SIZE);
        std::cout << line <<std::endl;
    }
}

int main()
{
    Student student1;
    student1.fn = 71937;
    student1.grade = 5.50;
    strcpy_s(student1.name, "Ani");

    Student student2;
    student2.fn = 71607;
    student2.grade = 5.70;
    strcpy_s(student2.name, "Bobi");

    Student student3;
    student3.fn = 72937;
    student3.grade = 5.20;
    strcpy_s(student3.name, "Viki");

    Student students[] = { student1, student2, student3 };

    writeStudents(students, "students.txt");
    readStudents("students.txt");
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
