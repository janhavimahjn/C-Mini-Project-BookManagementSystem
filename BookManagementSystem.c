#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100

struct Book {
    int id;
    char name[100];
    char author[100];
    char category[50];
    float price;
    float rating;
};

void addBook(struct Book books[], int *bookCount);
void removeBook(struct Book books[], int *bookCount, int id);
void searchBookByID(struct Book books[], int bookCount, int id);
void searchBookByName(struct Book books[], int bookCount, char name[]);
void showBooksByAuthor(struct Book books[], int bookCount, char author[]);
void showBooksByCategory(struct Book books[], int bookCount, char category[]);
void updateBook(struct Book books[], int bookCount, int id, float price, float rating);
void displaySortedBooks(struct Book books[], int bookCount);
void displayAllBooks(struct Book books[], int bookCount);

int main() {
    struct Book books[MAX_BOOKS];
    int bookCount = 0;
    int choice, id;
    char name[100], author[100], category[50];
    float price, rating;

    while (1) {
        printf("\nBook Management System\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Search Book by ID\n");
        printf("4. Search Book by Name\n");
        printf("5. Show Books by Author\n");
        printf("6. Show Books by Category\n");
        printf("7. Update Book Data\n");
        printf("8. Display Sorted Books (by price and rating)\n");
        printf("9. Display All Books\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addBook(books, &bookCount);
                break;
            case 2: 
                printf("Enter Book ID to remove: ");
                scanf("%d", &id);
                removeBook(books, &bookCount, id);
                break;
            case 3: 
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                searchBookByID(books, bookCount, id);
                break;
            case 4: 
                printf("Enter Book Name to search: ");
                getchar();  
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = 0;  
                searchBookByName(books, bookCount, name);
                break;
            case 5: 
                printf("Enter Author Name: ");
                getchar();
                fgets(author, 100, stdin);
                author[strcspn(author, "\n")] = 0;
                showBooksByAuthor(books, bookCount, author);
                break;
            case 6:
                printf("Enter Category: ");
                getchar();
                fgets(category, 50, stdin);
                category[strcspn(category, "\n")] = 0;
                showBooksByCategory(books, bookCount, category);
                break;
            case 7: 
                printf("Enter Book ID to update: ");
                scanf("%d", &id);
                printf("Enter new price: ");
                scanf("%f", &price);
                printf("Enter new rating: ");
                scanf("%f", &rating);
                updateBook(books, bookCount, id, price, rating);
                break;
            case 8: 
                displaySortedBooks(books, bookCount);
                break;
            case 9:
                displayAllBooks(books, bookCount);
                break;
            case 0: 
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void addBook(struct Book books[], int *bookCount) {
    struct Book newBook;
    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);
    printf("Enter Book Name: ");
    getchar(); 
    fgets(newBook.name, 100, stdin);
    newBook.name[strcspn(newBook.name, "\n")] = 0;  
    printf("Enter Author Name: ");
    fgets(newBook.author, 100, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;
    printf("Enter Category: ");
    fgets(newBook.category, 50, stdin);
    newBook.category[strcspn(newBook.category, "\n")] = 0;
    printf("Enter Price: ");
    scanf("%f", &newBook.price);
    printf("Enter Rating: ");
    scanf("%f", &newBook.rating);

    books[*bookCount] = newBook;
    (*bookCount)++;
    printf("Book added successfully!\n");
}

void removeBook(struct Book books[], int *bookCount, int id) {
    int found = 0;
    for (int i = 0; i < *bookCount; i++) {
        if (books[i].id == id) {
            for (int j = i; j < *bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            (*bookCount)--;
            found = 1;
            printf("Book removed successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

void searchBookByID(struct Book books[], int bookCount, int id) {
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            printf("Book ID: %d\n", books[i].id);
            printf("Book Name: %s\n", books[i].name);
            printf("Author: %s\n", books[i].author);
            printf("Category: %s\n", books[i].category);
            printf("Price: %.2f\n", books[i].price);
            printf("Rating: %.2f\n", books[i].rating);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

void searchBookByName(struct Book books[], int bookCount, char name[]) {
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].name, name) == 0) {
            printf("Book ID: %d\n", books[i].id);
            printf("Book Name: %s\n", books[i].name);
            printf("Author: %s\n", books[i].author);
            printf("Category: %s\n", books[i].category);
            printf("Price: %.2f\n", books[i].price);
            printf("Rating: %.2f\n", books[i].rating);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

void showBooksByAuthor(struct Book books[], int bookCount, char author[]) {
    int found = 0;
    printf("Books by %s:\n", author);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].author, author) == 0) {
            printf("Book ID: %d, Name: %s, Category: %s, Price: %.2f, Rating: %.2f\n",
                   books[i].id, books[i].name, books[i].category, books[i].price, books[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found by this author.\n");
    }
}

void showBooksByCategory(struct Book books[], int bookCount, char category[]) {
    int found = 0;
    printf("Books in Category %s:\n", category);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].category, category) == 0) {
            printf("Book ID: %d, Name: %s, Author: %s, Price: %.2f, Rating: %.2f\n",
                   books[i].id, books[i].name, books[i].author, books[i].price, books[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found in this category.\n");
    }
}

void updateBook(struct Book books[], int bookCount, int id, float price, float rating) {
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            books[i].price = price;
            books[i].rating = rating;
            printf("Book updated successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

void displaySortedBooks(struct Book books[], int bookCount) {
    struct Book temp;
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = i + 1; j < bookCount; j++) {
            if (books[i].price > books[j].price || 
               (books[i].price == books[j].price && books[i].rating < books[j].rating)) {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Books sorted by price and rating:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book ID: %d, Name: %s, Author: %s, Category: %s, Price: %.2f, Rating: %.2f\n",
               books[i].id, books[i].name, books[i].author, books[i].category, books[i].price, books[i].rating);
    }
}

void displayAllBooks(struct Book books[], int bookCount) {
    if (bookCount == 0) {
        printf("No books available in the database.\n");
        return;
    }
    printf("All Books in Database:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book ID: %d, Name: %s, Author: %s, Category: %s, Price: %.2f, Rating: %.2f\n",
               books[i].id, books[i].name, books[i].author, books[i].category, books[i].price, books[i].rating);
    }
}

