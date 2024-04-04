#include <stdio.h>
#include <stdlib.h>

// Employee structure
struct Employee {
    int SSN;
    char Name[50];
    char Dept[20];
    char Designation[20];
    float Sal;
    long PhNo;
    struct Employee *prev;
    struct Employee *next;
};

// Function prototypes
void createDLL(int N);
void displayDLL();
void countNodes();
void insertEnd();
void deleteEnd();
void insertFront();
void deleteFront();
void useAsDeque();

// Global variables
struct Employee *head = NULL;
struct Employee *tail = NULL;

int main() {
    int choice, N;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Create DLL\n");
        printf("2. Display DLL\n");
        printf("3. Count Nodes\n");
        printf("4. Insert at End\n");
        printf("5. Delete at End\n");
        printf("6. Insert at Front\n");
        printf("7. Delete at Front\n");
        printf("8. Use as Double Ended Queue\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of employees: ");
                scanf("%d", &N);
                createDLL(N);
                break;

            case 2:
                displayDLL();
                break;

            case 3:
                countNodes();
                break;

            case 4:
                insertEnd();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                insertFront();
                break;

            case 7:
                deleteFront();
                break;

            case 8:
                useAsDeque();
                break;

            case 9:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (1);

    return 0;
}

void createDLL(int N) {
    for (int i = 0; i < N; i++) {
        struct Employee *newEmployee = (struct Employee *)malloc(sizeof(struct Employee));

        printf("\nEnter Employee Data:\n");
        printf("SSN: ");
        scanf("%d", &newEmployee->SSN);
        printf("Name: ");
        scanf("%s", newEmployee->Name);
        printf("Dept: ");
        scanf("%s", newEmployee->Dept);
        printf("Designation: ");
        scanf("%s", newEmployee->Designation);
        printf("Salary: ");
        scanf("%f", &newEmployee->Sal);
        printf("Phone Number: ");
        scanf("%ld", &newEmployee->PhNo);

        newEmployee->next = NULL;

        if (head == NULL) {
            head = tail = newEmployee;
            newEmployee->prev = NULL;
        } else {
            tail->next = newEmployee;
            newEmployee->prev = tail;
            tail = newEmployee;
        }
    }

    printf("DLL created successfully.\n");
}

void displayDLL() {
    if (head == NULL) {
        printf("DLL is empty.\n");
        return;
    }

    struct Employee *current = head;

    printf("\n--- DLL Status ---\n");
    while (current != NULL) {
        printf("SSN: %d, Name: %s, Dept: %s, Designation: %s, Salary: %.2f, Phone: %ld\n",
               current->SSN, current->Name, current->Dept, current->Designation, current->Sal, current->PhNo);
        current = current->next;
    }
}

void countNodes() {
    int count = 0;
    struct Employee *current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    printf("Number of nodes in DLL: %d\n", count);
}

void insertEnd() {
    struct Employee *newEmployee = (struct Employee *)malloc(sizeof(struct Employee));

    printf("Enter Employee Data:\n");
    printf("SSN: ");
    scanf("%d", &newEmployee->SSN);
    printf("Name: ");
    scanf("%s", newEmployee->Name);
    printf("Dept: ");
    scanf("%s", newEmployee->Dept);
    printf("Designation: ");
    scanf("%s", newEmployee->Designation);
    printf("Salary: ");
    scanf("%f", &newEmployee->Sal);
    printf("Phone Number: ");
    scanf("%ld", &newEmployee->PhNo);

    newEmployee->next = NULL;

    if (head == NULL) {
        head = tail = newEmployee;
        newEmployee->prev = NULL;
        newEmployee->next=NULL;
    } else {
        tail->next = newEmployee;
        newEmployee->prev = tail;
        newEmployee->next = NULL;
        tail = newEmployee;
    }

    printf("Node inserted at the end successfully.\n");
}

void deleteEnd() {
    if (head == NULL) {
        printf("DLL is empty. Cannot delete from an empty list.\n");
        return;
    }

    if (head == tail) {
        free(head);
        head = tail = NULL;
    } else {
        struct Employee *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }

    printf("Node deleted from the end successfully.\n");
}

void insertFront() {
    struct Employee *newEmployee = (struct Employee *)malloc(sizeof(struct Employee));

    printf("Enter Employee Data:\n");
    printf("SSN: ");
    scanf("%d", &newEmployee->SSN);
    printf("Name: ");
    scanf("%s", newEmployee->Name);
    printf("Dept: ");
    scanf("%s", newEmployee->Dept);
    printf("Designation: ");
    scanf("%s", newEmployee->Designation);
    printf("Salary: ");
    scanf("%f", &newEmployee->Sal);
    printf("Phone Number: ");
    scanf("%ld", &newEmployee->PhNo);

    newEmployee->prev = NULL;

    if (head == NULL) {
        head = tail = newEmployee;
        newEmployee->next = NULL;
        newEmployee->prev = NULL;
    } else {
        newEmployee->next = head;
        head->prev = newEmployee;
        newEmployee->prev=NULL;
        head = newEmployee;
    }

    printf("Node inserted at the front successfully.\n");
}

void deleteFront() {
    if (head == NULL) {
        printf("DLL is empty. Cannot delete from an empty list.\n");
        return;
    }

    if (head == tail) {
        free(head);
        head = tail = NULL;
    } else {
        struct Employee *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }

    printf("Node deleted from the front successfully.\n");
}

void useAsDeque() {
    int choice;

    do {
        printf("\n--- Double Ended Queue Menu ---\n");
        printf("1. Insert at Rear\n");
        printf("2. Delete from Front\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertEnd();
                break;

            case 2:
                deleteFront();
                break;

            case 3:
                printf("Exiting Double Ended Queue menu.\n");
                return;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (1);
}
