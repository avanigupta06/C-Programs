#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char USN[20];
    char Name[50];
    char Branch[30];
    int Sem;
    long long int PhNo;
    struct Student* next;
};

struct Student* head = NULL;

struct Student* createStudent(char USN[], char Name[], char Branch[], int Sem, long long int PhNo) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    strcpy(newStudent->USN, USN);
    strcpy(newStudent->Name, Name);
    strcpy(newStudent->Branch, Branch);
    newStudent->Sem = Sem;
    newStudent->PhNo = PhNo;
    newStudent->next = NULL;
    return newStudent;
}

void insertAtFront(char USN[], char Name[], char Branch[], int Sem, long long int PhNo) {
    struct Student* newStudent = createStudent(USN, Name, Branch, Sem, PhNo);
    newStudent->next = head;
    head = newStudent;
}

void displayAndCount() {
    struct Student* current = head;
    int count = 0;
    printf("\n--- Student Linked List ---\n");
    while (current != NULL) {
        printf("USN: %s\n", current->USN);
        printf("Name: %s\n", current->Name);
        printf("Branch: %s\n", current->Branch);
        printf("Semester: %d\n", current->Sem);
        printf("Phone Number: %lld\n", current->PhNo);
        printf("-----------------------------\n");
        current = current->next;
        count++;
    }
    printf("Total number of students: %d\n", count);
}

void insertAtEnd(char USN[], char Name[], char Branch[], int Sem, long long int PhNo) {
    struct Student* newStudent = createStudent(USN, Name, Branch, Sem, PhNo);
    if (head == NULL) {
        head = newStudent;
        return;
    }
    struct Student* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newStudent;
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted the student at the end.\n");
        return;
    }
    
    struct Student* current = head;
    struct Student* prev = NULL;
    
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    
    prev->next = NULL;
    free(current);
    printf("Deleted the student at the end.\n");
}


void deleteAtFront() {
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    struct Student* temp = head;
    head = head->next;
    free(temp);
    printf("Deleted the first student from the list.\n");
}


int main() {
    int choice;
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Create a Student (Front Insertion)\n");
        printf("2. Display Students and Count\n");
        printf("3. Insert Student at Front\n");
        printf("4. Insert Student at End\n");
        printf("5. Delete Student at Front\n");
        printf("6. Delete Student at End\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char USN[20], Name[50], Branch[30];
                int Sem;
                long long int PhNo;
                printf("Enter USN: ");
                scanf("%s", USN);
                printf("Enter Name: ");
                scanf(" %s", Name);
                printf("Enter Branch: ");
                scanf(" %s", Branch);
                printf("Enter Semester: ");
                scanf("%d", &Sem);
                printf("Enter Phone Number: ");
                scanf("%lld", &PhNo);
                insertAtFront(USN, Name, Branch, Sem, PhNo);
                printf("Student inserted at the front.\n");
                break;
            }
            case 2:
                displayAndCount();
                break;
            case 3:{
            char USN[20], Name[50], Branch[30];
                int Sem;
                long long int PhNo;
                printf("Enter USN: ");
                scanf("%s", USN);
                printf("Enter Name: ");
                scanf(" %s", Name);
                printf("Enter Branch: ");
                scanf(" %s", Branch);
                printf("Enter Semester: ");
                scanf("%d", &Sem);
                printf("Enter Phone Number: ");
                scanf("%lld", &PhNo);
                insertAtFront(USN, Name, Branch, Sem, PhNo);
                printf("Student inserted at the front.\n");
                break;
            }
            case 4: {
                char USN[20], Name[50], Branch[30];
                int Sem;
                long long int PhNo;
                printf("Enter USN: ");
                scanf("%s", USN);
                printf("Enter Name: ");
                scanf(" %s", Name);
                printf("Enter Branch: ");
                scanf(" %s", Branch);
                printf("Enter Semester: ");
                scanf("%d", &Sem);
                printf("Enter Phone Number: ");
                scanf("%lld", &PhNo);
                insertAtEnd(USN, Name, Branch, Sem, PhNo);
                printf("Student inserted at the end.\n");
                break;
            }
            case 5:
                deleteAtFront();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
