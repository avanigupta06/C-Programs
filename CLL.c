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
    struct Employee *next;
};

// Function prototypes
void createSCLL(int N);
void displaySCLL();
void countNodes();
void insertEnd();
void deleteEnd();
void insertFront();
void deleteFront();

// Global variables
struct Employee *head = NULL;

int main() {
    int choice, N;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Create SCLL\n");
        printf("2. Display SCLL\n");
        printf("3. Count Nodes\n");
        printf("4. Insert at End\n");
        printf("5. Delete at End\n");
        printf("6. Insert at Front\n");
        printf("7. Delete at Front\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of employees: ");
                scanf("%d", &N);
                createSCLL(N);
                break;

            case 2:
                displaySCLL();
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
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (1);

    return 0;
}

void createSCLL(int N) {
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
            head = newEmployee;
            newEmployee->next = head;
        } else {
            struct Employee *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newEmployee;
            newEmployee->next = head;
        }
    }

    printf("SCLL created successfully.\n");
}

void displaySCLL() {
    if (head == NULL) {
        printf("SCLL is empty.\n");
        return;
    }

    struct Employee *current = head;

    printf("\n--- SCLL Status ---\n");
    do {
        printf("SSN: %d, Name: %s, Dept: %s, Designation: %s, Salary: %.2f, Phone: %ld\n",
               current->SSN, current->Name, current->Dept, current->Designation, current->Sal, current->PhNo);
        current = current->next;
    } while (current != head);
}

void countNodes() {
    if (head == NULL) {
        printf("SCLL is empty.\n");
        return;
    }

    int count = 0;
    struct Employee *current = head;

    do {
        count++;
        current = current->next;
    } while (current != head);

    printf("Number of nodes in SCLL: %d\n", count);
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
        head = newEmployee;
        newEmployee->next = head;
    } else {
        struct Employee *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newEmployee;
        newEmployee->next = head;
    }

    printf("Node inserted at the end successfully.\n");
}

void deleteEnd() {
    if (head == NULL) {
        printf("SCLL is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Employee *current = head, *prev = NULL;

    while (current->next != head) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        free(current);
        head = NULL;
    } else {
        prev->next = head;
        free(current);
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

    newEmployee->next = head;

    struct Employee *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newEmployee;

    head = newEmployee;

    printf("Node inserted at the front successfully.\n");
}

void deleteFront() {
    if (head == NULL) {
        printf("SCLL is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Employee *temp = head, *last = NULL;

    while (temp->next != head) {
        last = temp;
        temp = temp->next;
    }

    if (temp == head) {
        free(temp);
        head = NULL;
    } else {
        last->next = head;
        free(temp);
    }

    printf("Node deleted from the front successfully.\n");
}
