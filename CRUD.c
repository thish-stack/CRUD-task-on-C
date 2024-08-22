#include <stdio.h>

#define MAX_SIZE 100

void show(int arr[], int size);
int insert(int arr[], int size);
void update(int arr[], int size);
int del(int arr[], int size);

void Menu() {
    printf("\nMenu:\n");
    printf("1. Add\n");
    printf("2. Edit\n");
    printf("3. Delete\n");
    printf("4. Show\n");
    printf("5. Exit\n");
}

int insert(int arr[], int size) {
    if (size >= MAX_SIZE) {
        printf("Array is full. Cannot add more elements.\n");
        return size;
    }
    printf("Enter the element to add: ");
    scanf("%d", &arr[size]);
    size++;
    show(arr, size);
    return size;
}

void update(int arr[], int size) {
    int index, newValue;
    if (size == 0) {
        printf("Array is empty. Nothing to edit.\n");
        return;
    }
    printf("Enter the index of the element to edit (0 to %d): ", size - 1);
    scanf("%d", &index);
    if (index < 0 || index >= size) {
        printf("Invalid index. Please try again.\n");
        return;
    }
    printf("Enter the new value to update: ");
    scanf("%d", &newValue);

    if (arr[index] == newValue) {
        printf("Alert! Same element is being replaced.\n");
    }
    arr[index] = newValue;
    show(arr, size);
}

int del(int arr[], int size) {  // Updated function name
    int index;
    if (size == 0) {
        printf("Array is empty!\n");
        return size;
    }
    printf("Enter the index of the element to delete (0 to %d): ", size - 1);
    scanf("%d", &index);
    if (index < 0 || index >= size) {
        printf("Invalid index.\n");
        return size;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    show(arr, size);
    return size;
}

void show(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Current elements in the array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;
    char yn;

    while (1) {
        Menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                size = insert(arr, size);
                break;
            case 2:
                update(arr, size);
                break;
            case 3:
                size = del(arr, size);  // Updated function call
                break;
            case 4:
                show(arr, size);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("Do you want to continue (y/n)?: ");
        scanf(" %c", &yn);
        if (yn != 'y' && yn != 'Y') {
            break; 
        }
    }

    return 0;
}
