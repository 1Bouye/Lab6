#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the structure for the book
typedef struct {
    char title[50];
    float price;
    int pages;
    char author[50];
    int year;
    char publisher[50];
    char city[50];
} Book;

// Function to read books data from a tab-separated file
int readBooksFromFile(const char *filename, Book books[], int maxBooks) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }

    int count = 0;
    while (count < maxBooks && 
           fscanf(file, "%49[^\t]\t%f\t%d\t%49[^\t]\t%d\t%49[^\t]\t%49[^\n]\n",
                  books[count].title, &books[count].price, &books[count].pages, 
                  books[count].author, &books[count].year, 
                  books[count].publisher, books[count].city) == 7) {
        count++;
    }

    fclose(file);
    return count;
}

// Function to find cities publishing books by a specific author
void findCitiesByAuthor(Book books[], int count, const char *author, const char *outputFile) {
    FILE *file = fopen(outputFile, "w");
    if (!file) {
        printf("Error: Could not open output file %s\n", outputFile);
        return;
    }

    fprintf(file, "Cities publishing only books by author: %s\n", author);
    printf("Cities publishing only books by author: %s\n", author);

    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].author, author) == 0) {
            fprintf(file, "%s\n", books[i].city);
            printf("%s\n", books[i].city);
        }
    }

    fclose(file);
}

// Main function
int main() {
    const char *inputFile = "books_data.txt";
    const char *outputFile = "output.txt";

    Book books[100];
    int bookCount = readBooksFromFile(inputFile, books, 100);

    if (bookCount == 0) {
        printf("No books data found in the file.\n");
        return 1;
    }

    printf("Books data successfully read from the file.\n");

    // Find and write cities publishing books by a specific author
    char targetAuthor[50];
    printf("Enter the author's name to search for cities: ");
    scanf("%49s", targetAuthor);

    findCitiesByAuthor(books, bookCount, targetAuthor, outputFile);

    printf("Results have been written to the file: %s\n", outputFile);

    return 0;
}
