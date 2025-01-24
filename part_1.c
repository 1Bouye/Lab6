/*

I.	После ввода массива структур программа ищет в нем следующую информацию (все данные в полученном массиве должны быть различны):

    28.	Названия всех городов, выпускающих только книги заданного автора.

*/



#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Define the structure for a Book
typedef struct {
    char title[100];        // Title of the book
    float price;            // Price of the book
    int pages;              // Number of pages
    char author[100];       // Author of the book
    int year;               // Year of publication
    char publisher[100];    // Publisher's name
    char city[100];         // City of publication
} Book;

// Function to input books using fgets
void inputBooks(Book books[], int *count) {
    printf("Enter the number of books: ");
    scanf("%d", count);
    getchar(); // Consume the newline character left by scanf

    for (int i = 0; i < *count; i++) {
        printf("\nBook %d:\n", i + 1);

        printf("Enter title: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = '\0'; // Remove the newline character

        printf("Enter price: ");
        scanf("%f", &books[i].price);
        getchar(); // Consume the newline character left by scanf

        printf("Enter number of pages: ");
        scanf("%d", &books[i].pages);
        getchar(); // Consume the newline character left by scanf

        printf("Enter author: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0'; // Remove the newline character

        printf("Enter year of publication: ");
        scanf("%d", &books[i].year);
        getchar(); // Consume the newline character left by scanf

        printf("Enter publisher: ");
        fgets(books[i].publisher, sizeof(books[i].publisher), stdin);
        books[i].publisher[strcspn(books[i].publisher, "\n")] = '\0'; // Remove the newline character

        printf("Enter city: ");
        fgets(books[i].city, sizeof(books[i].city), stdin);
        books[i].city[strcspn(books[i].city, "\n")] = '\0'; // Remove the newline character
    }
}

// Function to find cities publishing only books by a specific author
void findCitiesByAuthor(Book books[], int count, const char *author) {
    printf("\nCities publishing only books by %s:\n", author);

    for (int i = 0; i < count; i++) {
        int isExclusive = 1; // Assume the city is exclusive for the author
        for (int j = 0; j < count; j++) {
            if (i != j && strcmp(books[i].city, books[j].city) == 0 && strcmp(books[j].author, author) != 0) {
                isExclusive = 0;
                break;
            }
        }

        if (isExclusive) {
            printf("- %s\n", books[i].city);
        }
    }
}

// Main function for manual input and search
int main() {
    Book books[MAX_BOOKS];
    int count;

    inputBooks(books, &count);

    char author[100];
    printf("\nEnter author to search for: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = '\0'; // Remove the newline character

    findCitiesByAuthor(books, count, author);

    // Wait for user input before closing the window
    printf("\nPress Enter to exit...");
    getchar();

    return 0;
}