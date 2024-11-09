#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100  // Maximum number of books in the library

// Book Struct
struct Book {
    char title[100];
    char author[50];
    int year;
    int available; // 1 if available and -1 if not
};

typedef struct Book Book;

// Library of Books
// Book ** library == Book* library[MAX_BOOKS]
// Book* library[MAX_BOOKS];
// [p1, p2, p3, p4.....]
Book* library = NULL;
Book library[MAX_BOOKS];

int book_count = 0;
int available_books = 0;

void add_book(const char* title, const char* author, int year) {

    library = realloc(library, (book_count+1) * sizeof(Book)); // if library is NULL, this is malloc(sizeof(Book))
    if (library == NULL) {
        printf("Error in mallocing");
        return;
    }

    strncpy(library[book_count].title, title, 100);
    strncpy(library[book_count].author, author, 50);
    (*(library+book_count)).year = year;
    library[book_count].available = 1;
    // library --> first book in group
    // library + 1 --> points to the NEXT BOOK and NOT the next byte!!!! (pointer arithmetic!)
    // library[0] == *(library + 0) == *library
    // library[1] == *(library + 1)
    book_count++;
    available_books++;
    return;
}

void print_library() {
    for (int i = 0; i < book_count; i++) {

        // b->title ==> b is a pointer to a struct
        // b.title ==> b is the struct
        printf("Book #%d\n", i+1);
        printf("    Title: %s\n", library[i].title);
        printf("    Author: %s\n", (library + i)->author);
        printf("    Year: %d\n", (*(library + i)).year);
        printf("\n");
    }
}

int main() {
    // Add books to the library
    add_book("Atomic Habits", "James Clear", 2018);
    add_book("The White Tiger", "Aravind Adiga", 2008);
    add_book("Moneyball", "Michael Lewis", 2003);

    // Display all books in the library
    print_library();

    // cleanup_library();
    free(library);

    return 0;
}

