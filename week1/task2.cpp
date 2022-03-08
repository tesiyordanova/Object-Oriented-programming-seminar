﻿// task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Book {
    char name[64];
    char authorName[64];
    int ISBN;
    char genre[64];
    double price;

    // void createBook(char* _name, char* _authorName, int _ISBN, char* _genre, double _price) {
    //     name = _name;
    //     authorName = _authorName;
    //     ISBN = _ISBN;
    //     genre = _genre;
    //     price = _price;
    // }

    void enterBook() {
        cin.ignore();
        cout << "Enter name: ";
        cin.getline(name, 64);
        cout << "Enter author: ";
        cin.getline(authorName, 64);
        cout << "Enter genre: ";
        cin.getline(genre, 64);
        cout << "Enter ISBN: ";
        cin >> ISBN;
        cout << "Enter price: ";
        cin >> price;
    }

    void print() {
        cout << name << endl;
        cout << authorName << endl;
        cout << ISBN << endl;
        cout << genre << endl;
        cout << price << endl;
    }
};

const int BOOK_CAPACITY = 1000;
struct BookStore {
    int count;
    Book books[BOOK_CAPACITY];
};

void initializeBookstore(BookStore& store) {
    cout << "Book count: ";
    cin >> store.count;

    for (int i = 0; i < store.count; i++) {
        Book b;
        b.enterBook();
        store.books[i] = b;
    }
}

void getAllBooks(BookStore& store) {
    for (int i = 0; i < store.count; i++) {
        store.books[i].print();
        cout << endl;
    }
}

void getAllBooksByGenre(BookStore& store, const char* genre) {
    for (int i = 0; i < store.count; i++) {
        if (genre == store.books[i].genre) {
            cout << "Genre found: ";
            store.books[i].print();
        }
    }
}

void getAllBooksByAuthorName(BookStore& store, const char* authorName) {
    for (int i = 0; i < store.count; i++) {
        if (authorName == store.books[i].authorName) {
            cout << "Author name found: ";
            store.books[i].print();
        }
    }
}

int main()
{
    BookStore store1;
    initializeBookstore(store1);
    getAllBooks(store1);
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
