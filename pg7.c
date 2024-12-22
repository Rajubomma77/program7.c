#include <stdio.h>
#include <stdlib.h>

struct Student {
    char USN[15];
    char Name[30];
    char Programme[20];
    int Sem;
    long long int PhNo;
    struct Student* next;
};

struct Student* createNode() {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    scanf("%s", newNode->USN);
    scanf("%s", newNode->Name);
    scanf("%s", newNode->Programme);
    scanf("%d", &newNode->Sem);
    scanf("%lld", &newNode->PhNo);
    newNode->next = NULL;
    return newNode;
}

void insertFront(struct Student** head) {
    struct Student* newNode = createNode();
    newNode->next = *head;
    *head = newNode;
}

void displayStatus(struct Student* head) {
    if (head == NULL) {
        return;
    }
    struct Student* current = head;
    int count = 0;
    while (current != NULL) {
        printf("USN: %s, Name: %s, Programme: %s, Sem: %d, Phone: %lld\n",
            current->USN, current->Name, current->Programme, current->Sem, current->PhNo);
        current = current->next;
        count++;
    }
    printf("Total number of nodes: %d\n", count);
}

void insertEnd(struct Student** head) {
    struct Student* newNode = createNode();
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Student* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteFront(struct Student** head) {
    if (*head == NULL) {
        return;
    }
    struct Student* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteEnd(struct Student** head) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Student* current = *head;
    struct Student* prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    free(current);
    prev->next = NULL;
}

void freeList(struct Student** head) {
    struct Student* current = *head;
    struct Student* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    struct Student* head = NULL;
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Display Status\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Front (Demonstration of stack)\n");
        printf("5. Delete from End\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            insertFront(&head);
            break;
        case 2:
            displayStatus(head);
            break;
        case 3:
            insertEnd(&head);
            break;
        case 4:
            deleteFront(&head);
            break;
        case 5:
            deleteEnd(&head);
            break;
        case 6:
            freeList(&head);
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 6);
    return 0;
}
