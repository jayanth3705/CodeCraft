#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_STUDENTS 100
int i;
typedef struct {
    char title[50];
    char author[50];
    int Issued;
} Book;

typedef struct {
    char studentName[50];
    char department[50];
    char borrowedBook[50];
} Student;

Book library[MAX_BOOKS];
Student students[MAX_STUDENTS];
int bookCount = 0;
int studentCount = 0;

// Function to add a book to the library
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full, cannot add more books.\n");
        return;
    }

    char title[50];
    char author[50];

    printf("Enter book title: ");
    scanf(" %[^\n]s", title);

    printf("Enter book author: ");
    scanf(" %[^\n]s", author);

    // Prevent adding duplicate books
    for ( i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0 && strcmp(library[i].author, author) == 0) {
            printf("This book already exists in the library.\n");
            return;
        }
    }

    strcpy(library[bookCount].title, title);
    strcpy(library[bookCount].author, author);
    library[bookCount].Issued = 0;  // Mark as not issued
    bookCount++;
    printf("Book added successfully.\n");
}

// Function to search for a book by title or author
void searchBook() {
    char keyword[50];
    printf("Enter a keyword to search (title or author): ");
    scanf(" %[^\n]s", keyword);

    printf("\nSearch Results:\n");
    for ( i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, keyword) != NULL || strstr(library[i].author, keyword) != NULL) {
            printf("Title: %s, Author: %s, Status: %s\n", library[i].title, library[i].author, 
                   library[i].Issued ? "Issued" : "Available");
        }
    }
}

// Function to issue a book
void issueBook() {
    char title[50];
    printf("Enter book title to issue: ");
    scanf(" %[^\n]s", title);

    for ( i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            if (library[i].Issued) {
                printf("Book is already issued.\n");
                return;
            }
            library[i].Issued = 1;  // Mark as issued

            // Enter student details
            printf("Enter student name: ");
            scanf(" %[^\n]s", students[studentCount].studentName);
            printf("Enter department: ");
            scanf(" %[^\n]s", students[studentCount].department);
            strcpy(students[studentCount].borrowedBook, library[i].title);
            studentCount++;
            printf("Book issued successfully.\n");
            return;
        }
    }
    printf("Book not found in the library.\n");
}

// Function to return a book
void returnBook() {
    char title[50];
    printf("Enter book title to return: ");
    scanf(" %[^\n]s", title);

    for ( i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            if (!library[i].Issued) {
                printf("Book was not issued.\n");
                return;
            }
            library[i].Issued = 0;  // Mark as not issued
            printf("Book returned successfully.\n");
            return;
        }
    }
    printf("Book not found in the library.\n");
}

// Function to display all books
void displayBooks() {
    printf("\nBooks in Library:\n");
    for ( i = 0; i < bookCount; i++) {
        printf("Title: %s, Author: %s, Status: %s\n", library[i].title, library[i].author, 
               library[i].Issued ? "Issued" : "Available");
    }
}

// Function to register a new student
void registerStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot register more students.\n");
        return;
    }

    printf("Enter student name: ");
    scanf(" %[^\n]s", students[studentCount].studentName);
    printf("Enter department: ");
    scanf(" %[^\n]s", students[studentCount].department);

    studentCount++;
    printf("Student registered successfully.\n");
}

// Main function
int main() {
    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Issue Book\n");
        printf("3. Return Book\n");
        printf("4. Display Books\n");
        printf("5. Search Book\n");
        printf("6. Register Student\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                issueBook();
                break;
            case 3:
                returnBook();
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                searchBook();
                break;
            case 6:
                registerStudent();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

