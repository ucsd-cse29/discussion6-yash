#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100  // Maximum number of books in the library

// Book Struct
typedef struct {
    char title[100];
    char author[50];
    int year;
    int available;
} Book;

// Library of Books


int book_count = 0;
int available_books = 0;


int main() {
    // Add books to the library
    add_book("Atomic Habits", "James Clear", 2018);
    add_book("The White Tiger", "Aravind Adiga", 2008);
    add_book("Moneyball", "Michael Lewis", 2003);

    // Display all books in the library
    print_library();

    cleanup_library();

    return 0;
}

