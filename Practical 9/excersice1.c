//code by tanay ranka sycse b 8
#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtBeginning(struct Node** head, int data);
void deleteAtBeginning(struct Node** head);
void insertAtEnd(struct Node** head, int data);
void insertAfterNode(struct Node* head, int targetValue, int data);
void insertBeforeNode(struct Node** head, int targetValue, int data);
void insertAtSpecificPosition(struct Node** head, int position, int data);
void deleteNodeByValue(struct Node** head, int targetValue);
void displayList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data, target, position;

    while (1) {
        printf("\n--- Linked List Operations Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Delete from Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert After a Node\n");
        printf("5. Insert Before a Given Node\n");
        printf("6. Insert at a Specific Node (Position)\n");
        printf("7. Delete Node by Value\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                displayList(head);
                break;
            case 2:
                deleteAtBeginning(&head);
                displayList(head);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                displayList(head);
                break;
            case 4:
                printf("Enter the node value after which to insert: ");
                scanf("%d", &target);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAfterNode(head, target, data);
                displayList(head);
                break;
            case 5:
                printf("Enter the node value before which to insert: ");
                scanf("%d", &target);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertBeforeNode(&head, target, data);
                displayList(head);
                break;
            case 6:
                printf("Enter the 1-based position to insert at: ");
                scanf("%d", &position);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtSpecificPosition(&head, position, data);
                displayList(head);
                break;
            case 7:
                printf("Enter the node value to delete: ");
                scanf("%d", &target);
                deleteNodeByValue(&head, target);
                displayList(head);
                break;
            case 8:
                displayList(head);
                break;
            case 9:
                printf("Exiting program.\n");
                // Free memory before exiting
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }
    return 0;
}

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
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
}

// 1b. Delete from Beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Node deleted from the beginning.\n");
}

// 2. Insert at End
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 3. Insert After a node
void insertAfterNode(struct Node* head, int targetValue, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != targetValue) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Target node with value %d not found.\n", targetValue);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// 4. Insert Before a Given Node
void insertBeforeNode(struct Node** head, int targetValue, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    // If target is the first node
    if ((*head)->data == targetValue) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* prev = NULL;
    struct Node* curr = *head;
    while (curr != NULL && curr->data != targetValue) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Target node with value %d not found.\n", targetValue);
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = curr;
    prev->next = newNode;
}

// 5. Insert at a specific node (position)
void insertAtSpecificPosition(struct Node** head, int position, int data) {
    if (position < 1) {
        printf("Invalid position. Position must be >= 1.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// 6. Delete Node by Value
void deleteNodeByValue(struct Node** head, int targetValue) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    
    // If head node itself holds the target value
    if (temp->data == targetValue) {
        *head = temp->next;
        free(temp);
        printf("Node with value %d deleted.\n", targetValue);
        return;
    }

    struct Node* prev = NULL;
    while (temp != NULL && temp->data != targetValue) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", targetValue);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", targetValue);
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Current List: [Empty]\n");
        return;
    }
    struct Node* temp = head;
    printf("Current List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
