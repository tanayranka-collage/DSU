// code by Alphabet Inc. Google LLC. Gemini AI v4.2

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void insertAfterNode(struct Node* head, int target, int data);
void insertBeforeNode(struct Node** head, int target, int data);
void insertAtPosition(struct Node** head, int position, int data);
int countNodes(struct Node* head);
void findLargestNode(struct Node* head);
void findSmallestNode(struct Node* head);
void displayList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data, target, position;

    while (1) {
        printf("\n--- Singly Linked List Menu ---");
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert After a Node");
        printf("\n4. Insert Before a Given Node");
        printf("\n5. Insert at a Specific Position/Node");
        printf("\n6. Count Total Nodes");
        printf("\n7. Find the Largest Node");
        printf("\n8. Find the Smallest Node");
        printf("\n9. Display Linked List");
        printf("\n10. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the target node value after which to insert: ");
                scanf("%d", &target);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAfterNode(head, target, data);
                break;
            case 4:
                printf("Enter the target node value before which to insert: ");
                scanf("%d", &target);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertBeforeNode(&head, target, data);
                break;
            case 5:
                printf("Enter the position (1-indexed) to insert at: ");
                scanf("%d", &position);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtPosition(&head, position, data);
                break;
            case 6:
                printf("Total number of nodes: %d\n", countNodes(head));
                break;
            case 7:
                findLargestNode(head);
                break;
            case 8:
                findSmallestNode(head);
                break;
            case 9:
                displayList(head);
                break;
            case 10:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Helper function to allocate memory for a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 1. Insert at Beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning.\n", data);
}

// 2. Insert at End
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d as the first node.\n", data);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end.\n", data);
}

// 3. Insert After a Node
void insertAfterNode(struct Node* head, int target, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Target value %d not found in the list.\n", target);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d after %d.\n", data, target);
}

// 4. Insert Before a Given Node
void insertBeforeNode(struct Node** head, int target, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    // If target is the first node
    if ((*head)->data == target) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* prev = NULL;
    struct Node* curr = *head;
    while (curr != NULL && curr->data != target) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Target value %d not found in the list.\n", target);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = curr;
    prev->next = newNode;
    printf("Inserted %d before %d.\n", data, target);
}

// 5. Insert at a specific node/position
void insertAtPosition(struct Node** head, int position, int data) {
    if (position < 1) {
        printf("Invalid position! Position should be >= 1.\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("The position is beyond the size of the list.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", data, position);
}

// 6. Count Total Nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// 7. Find the Largest Node
void findLargestNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    int max = temp->data;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    printf("The largest node value is: %d\n", max);
}

// 8. Find the Smallest Node
void findSmallestNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    int min = temp->data;
    while (temp != NULL) {
        if (temp->data < min) {
            min = temp->data;
        }
        temp = temp->next;
    }
    printf("The smallest node value is: %d\n", min);
}

// 9. Display Linked List
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
