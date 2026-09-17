#include <stdio.h>

#define CAPACITY 100



void displayMarks(int arr[], int size) {
    if (size == 0) {
        printf("No marks available to display.\n");
        return;
    }
    printf("Student Marks:\n");
    for (int i = 0; i < size; i++) {
        printf("Index %d: %d\n", i, arr[i]);
    }
}

void insertAt(int arr[], int *size, int capacity, int position, int value) {
    if (*size >= capacity) {
        printf("Overflow Error: The marks list is full!\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position! Please enter a position between 0 and %d.\n", *size);
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*size)++;
    printf("Mark added successfully.\n");
}

void deleteAt(int arr[], int *size, int position) {
    if (*size == 0) {
        printf("Underflow Error: No marks available to delete!\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("Invalid position! Please enter a position between 0 and %d.\n", *size - 1);
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Mark deleted successfully.\n");
}

void searchMark(int arr[], int size, int target) {
    int found = 0;
    printf("Searching for mark %d...\n", target);
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Found at index %d\n", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Mark %d not found in the record.\n", target);
    }
}

void updateByIndex(int arr[], int size, int index, int newValue) {
    if (index < 0 || index >= size) {
        printf("Invalid index! Please enter an index between 0 and %d.\n", size - 1);
        return;
    }
    arr[index] = newValue;
    printf("Mark at index %d updated successfully.\n", index);
}



int main() {
    int marks[CAPACITY];
    int size = 0;
    char choice;
    int pos, val, target;

    while (1) {

        printf("       STUDENT MARKS MANAGER        \n");
        printf("====================================\n");
        printf("(a) Add a mark at a chosen position\n");
        printf("(b) Delete a mark at a chosen position\n");
        printf("(c) Search for a mark\n");
        printf("(d) Update a mark by index\n");
        printf("(e) Display all marks\n");
        printf("(f) Exit\n");
        printf("Enter your choice: ");

        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
            case 'A':
                printf("Enter position (0 to %d): ", size);
                scanf("%d", &pos);
                printf("Enter mark value: ");
                scanf("%d", &val);
                insertAt(marks, &size, CAPACITY, pos, val);
                break;

            case 'b':
            case 'B':
                printf("Enter position to delete (0 to %d): ", size > 0 ? size - 1 : 0);
                scanf("%d", &pos);
                deleteAt(marks, &size, pos);
                break;

            case 'c':
            case 'C':
                printf("Enter mark value to search: ");
                scanf("%d", &target);
                searchMark(marks, size, target);
                break;

            case 'd':
            case 'D':
                printf("Enter index to update (0 to %d): ", size > 0 ? size - 1 : 0);
                scanf("%d", &pos);
                printf("Enter new mark value: ");
                scanf("%d", &val);
                updateByIndex(marks, size, pos, val);
                break;

            case 'e':
            case 'E':
                displayMarks(marks, size);
                break;

            case 'f':
            case 'F':
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid option! Please choose a valid menu item.\n");
        }
    }

    return 0;
}
