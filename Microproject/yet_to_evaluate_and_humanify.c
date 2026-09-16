
//code currently by Anthropic Inc. Claude AI LLM Sonnet 5 basic.

/* ================================================================
   STUDENT DATABASE MANAGEMENT SYSTEM
   ----------------------------------------------------------------
   Language   : C (C99)
   Storage    : Local text file "students.txt"  (NO SQL / NO DB engine)
   In-memory  : Doubly Linked List
   Algorithms : Bubble Sort, Selection Sort, Insertion Sort,
                Binary Search, Linear Search

   MENU OPTIONS
     1. Add Student        -> insert new node at tail of the list
     2. Display All        -> traverse the linked list
     3. Search Student     -> Linear Search  (list, any field)
                               Binary Search (array copy, by Roll No.)
     4. Edit Student       -> linear search + in-place update
     5. Delete Student     -> unlink node from doubly linked list
     6. Sort Students      -> Bubble / Selection / Insertion sort,
                               by Roll No. / Name / Marks
     7. Save & Exit        -> persist list to students.txt

   FILE FORMAT (CSV, one record per line):
       roll,name,age,marks
   NOTE: keep names comma-free, since ',' is the field separator.
   ================================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME  "students.txt"
#define NAME_LEN  50
#define LINE_LEN  200

/* ---------------- Doubly Linked List Node ---------------- */
typedef struct Student {
    int   roll;
    char  name[NAME_LEN];
    int   age;
    float marks;
    struct Student *prev;
    struct Student *next;
} Student;

Student *head = NULL;
Student *tail = NULL;
int totalStudents = 0;

/* ---------------- Function Prototypes ---------------- */
/* Core list / file operations */
Student *createNode(int roll, const char *name, int age, float marks);
void appendNode(Student *node);
void loadFromFile(void);
void saveToFile(void);
void freeList(void);

/* Menu operations */
void addStudent(void);
void displayAll(void);
void editStudent(void);
void deleteStudent(void);

/* Search (Linked List + Array) */
void searchMenu(void);
void linearSearch(void);
void binarySearch(void);

/* Sorting (array-based, then written back into the linked list) */
void sortMenu(void);
void bubbleSort(Student arr[], int n, int field);
void selectionSort(Student arr[], int n, int field);
void insertionSort(Student arr[], int n, int field);
int  compareStudents(Student a, Student b, int field);
void swapStudents(Student *a, Student *b);
void applySortedOrder(Student arr[], int n);

/* Helpers */
int  getMenuChoice(const char *prompt, int min, int max);
void readLine(char *buffer, int size);
void toArray(Student **arr, int *n);

/* ================================================================
   main
   ================================================================ */
int main(void) {
    loadFromFile();

    int choice;
    do {
        printf("\n============================================\n");
        printf("      STUDENT DATABASE MANAGEMENT SYSTEM\n");
        printf("============================================\n");
        printf(" 1. Add Student\n");
        printf(" 2. Display All Students\n");
        printf(" 3. Search Student\n");
        printf(" 4. Edit Student\n");
        printf(" 5. Delete Student\n");
        printf(" 6. Sort Students\n");
        printf(" 7. Save & Exit\n");
        printf("============================================\n");
        choice = getMenuChoice("Enter your choice: ", 1, 7);

        switch (choice) {
            case 1: addStudent();    break;
            case 2: displayAll();    break;
            case 3: searchMenu();    break;
            case 4: editStudent();   break;
            case 5: deleteStudent(); break;
            case 6: sortMenu();      break;
            case 7:
                saveToFile();
                printf("\nData saved to '%s'. Goodbye!\n", FILENAME);
                break;
        }
    } while (choice != 7);

    freeList();
    return 0;
}

/* ================================================================
   Small input helpers
   ================================================================ */

/* Reads a line safely and strips the trailing newline. */
void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') buffer[len - 1] = '\0';
    } else {
        buffer[0] = '\0';
    }
}

/* Repeats a prompt until the user enters an integer within [min, max]. */
int getMenuChoice(const char *prompt, int min, int max) {
    char buffer[100];
    int choice;
    while (1) {
        printf("%s", prompt);
        readLine(buffer, sizeof(buffer));
        if (sscanf(buffer, "%d", &choice) == 1 && choice >= min && choice <= max) {
            return choice;
        }
        printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
    }
}

/* ================================================================
   Doubly Linked List: node creation / insertion / freeing
   ================================================================ */

Student *createNode(int roll, const char *name, int age, float marks) {
    Student *newNode = (Student *)malloc(sizeof(Student));
    if (!newNode) {
        printf("Fatal: memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->roll = roll;
    strncpy(newNode->name, name, NAME_LEN - 1);
    newNode->name[NAME_LEN - 1] = '\0';
    newNode->age = age;
    newNode->marks = marks;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/* Inserts a node at the tail of the doubly linked list. */
void appendNode(Student *node) {
    if (head == NULL) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    totalStudents++;
}

void freeList(void) {
    Student *cur = head;
    while (cur) {
        Student *temp = cur;
        cur = cur->next;
        free(temp);
    }
    head = tail = NULL;
    totalStudents = 0;
}

/* ================================================================
   File persistence  (plain text file, no SQL / database engine)
   ================================================================ */

void loadFromFile(void) {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        /* First run - file will be created on the first save. */
        return;
    }

    char line[LINE_LEN];
    while (fgets(line, sizeof(line), fp)) {
        int roll, age;
        float marks;
        char name[NAME_LEN];

        char *token = strtok(line, ",");
        if (!token) continue;
        roll = atoi(token);

        token = strtok(NULL, ",");
        if (!token) continue;
        strncpy(name, token, NAME_LEN - 1);
        name[NAME_LEN - 1] = '\0';

        token = strtok(NULL, ",");
        if (!token) continue;
        age = atoi(token);

        token = strtok(NULL, ",\n");
        if (!token) continue;
        marks = (float)atof(token);

        appendNode(createNode(roll, name, age, marks));
    }
    fclose(fp);
    printf("Loaded %d record(s) from '%s'.\n", totalStudents, FILENAME);
}

/* Overwrites the file with the current state of the linked list. */
void saveToFile(void) {
    FILE *fp = fopen(FILENAME, "w");
    if (!fp) {
        printf("Error: could not open '%s' for saving!\n", FILENAME);
        return;
    }
    Student *cur = head;
    while (cur) {
        fprintf(fp, "%d,%s,%d,%.2f\n", cur->roll, cur->name, cur->age, cur->marks);
        cur = cur->next;
    }
    fclose(fp);
}

/* ================================================================
   Add / Display / Edit / Delete   (core CRUD on the linked list)
   ================================================================ */

void addStudent(void) {
    char buffer[100], name[NAME_LEN];
    int roll, age;
    float marks;

    printf("\n--- Add New Student ---\n");

    printf("Enter Roll Number: ");
    readLine(buffer, sizeof(buffer));
    roll = atoi(buffer);

    /* Linear traversal of the linked list to reject duplicate roll numbers. */
    for (Student *cur = head; cur; cur = cur->next) {
        if (cur->roll == roll) {
            printf("Error: a student with Roll Number %d already exists!\n", roll);
            return;
        }
    }

    printf("Enter Name (no commas): ");
    readLine(name, sizeof(name));

    printf("Enter Age: ");
    readLine(buffer, sizeof(buffer));
    age = atoi(buffer);

    printf("Enter Marks: ");
    readLine(buffer, sizeof(buffer));
    marks = (float)atof(buffer);

    appendNode(createNode(roll, name, age, marks));
    saveToFile();

    printf("Student record added successfully!\n");
}

void displayAll(void) {
    if (!head) {
        printf("\nNo records found. Database is empty.\n");
        return;
    }

    printf("\n%-8s %-25s %-6s %-8s\n", "Roll", "Name", "Age", "Marks");
    printf("--------------------------------------------------\n");
    for (Student *cur = head; cur; cur = cur->next) {
        printf("%-8d %-25s %-6d %-8.2f\n", cur->roll, cur->name, cur->age, cur->marks);
    }
    printf("--------------------------------------------------\n");
    printf("Total Students: %d\n", totalStudents);
}

void editStudent(void) {
    if (!head) {
        printf("\nNo records to edit. Database is empty.\n");
        return;
    }

    char buffer[100];
    printf("\n--- Edit Student ---\n");
    printf("Enter Roll Number to edit: ");
    readLine(buffer, sizeof(buffer));
    int roll = atoi(buffer);

    Student *cur = head;
    while (cur && cur->roll != roll) cur = cur->next;

    if (!cur) {
        printf("Student with Roll Number %d not found.\n", roll);
        return;
    }

    printf("Current -> Name: %s | Age: %d | Marks: %.2f\n", cur->name, cur->age, cur->marks);

    printf("New Name (blank = keep unchanged): ");
    readLine(buffer, sizeof(buffer));
    if (strlen(buffer) > 0) {
        strncpy(cur->name, buffer, NAME_LEN - 1);
        cur->name[NAME_LEN - 1] = '\0';
    }

    printf("New Age (0 = keep unchanged): ");
    readLine(buffer, sizeof(buffer));
    int age = atoi(buffer);
    if (age != 0) cur->age = age;

    printf("New Marks (-1 = keep unchanged): ");
    readLine(buffer, sizeof(buffer));
    float marks = (float)atof(buffer);
    if (marks != -1) cur->marks = marks;

    saveToFile();
    printf("Student record updated successfully!\n");
}

/* Demonstrates doubly linked list deletion: unlink a node using
   both its prev and next pointers, handling head/tail edge cases. */
void deleteStudent(void) {
    if (!head) {
        printf("\nNo records to delete. Database is empty.\n");
        return;
    }

    char buffer[100];
    printf("\n--- Delete Student ---\n");
    printf("Enter Roll Number to delete: ");
    readLine(buffer, sizeof(buffer));
    int roll = atoi(buffer);

    Student *cur = head;
    while (cur && cur->roll != roll) cur = cur->next;

    if (!cur) {
        printf("Student with Roll Number %d not found.\n", roll);
        return;
    }

    if (cur->prev) cur->prev->next = cur->next;
    else head = cur->next;              /* deleting the head node */

    if (cur->next) cur->next->prev = cur->prev;
    else tail = cur->prev;              /* deleting the tail node */

    free(cur);
    totalStudents--;
    saveToFile();

    printf("Student record deleted successfully!\n");
}

/* ================================================================
   Search:  Linear Search (on the list) + Binary Search (on an array)
   ================================================================ */

void searchMenu(void) {
    if (!head) {
        printf("\nNo records found. Database is empty.\n");
        return;
    }

    printf("\n--- Search Student ---\n");
    printf("1. Linear Search (by Roll Number or Name)\n");
    printf("2. Binary Search (by Roll Number)\n");
    int choice = getMenuChoice("Enter your choice: ", 1, 2);

    if (choice == 1) linearSearch();
    else binarySearch();
}

void linearSearch(void) {
    char buffer[100];
    printf("\nSearch by:\n1. Roll Number\n2. Name\n");
    int mode = getMenuChoice("Enter your choice: ", 1, 2);

    printf("Enter search value: ");
    readLine(buffer, sizeof(buffer));

    int comparisons = 0;
    Student *found = NULL;

    for (Student *cur = head; cur; cur = cur->next) {
        comparisons++;
        if (mode == 1) {
            if (cur->roll == atoi(buffer)) { found = cur; break; }
        } else {
            if (strcmp(cur->name, buffer) == 0) { found = cur; break; }
        }
    }

    if (found) {
        printf("\nRecord found in %d comparison(s):\n", comparisons);
        printf("Roll: %d | Name: %s | Age: %d | Marks: %.2f\n",
               found->roll, found->name, found->age, found->marks);
    } else {
        printf("\nNo matching record found (checked %d record(s)).\n", comparisons);
    }
}

/* Binary Search needs random access on SORTED data, which a linked
   list cannot give in O(1). So we snapshot the list into an array,
   sort a temporary copy by Roll Number, and binary-search that copy.
   The stored linked list / file order is left untouched. */
void binarySearch(void) {
    int n;
    Student *arr;
    toArray(&arr, &n);

    insertionSort(arr, n, 1); /* field 1 = Roll Number, ascending */

    char buffer[100];
    printf("\n(Using a temporary sorted copy for Binary Search;\n");
    printf(" your stored record order is unaffected.)\n");
    printf("Enter Roll Number to search: ");
    readLine(buffer, sizeof(buffer));
    int key = atoi(buffer);

    int low = 0, high = n - 1, comparisons = 0, foundIndex = -1;
    while (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2;
        if (arr[mid].roll == key) { foundIndex = mid; break; }
        else if (arr[mid].roll < key) low = mid + 1;
        else high = mid - 1;
    }

    if (foundIndex != -1) {
        printf("\nRecord found in %d comparison(s) using Binary Search:\n", comparisons);
        printf("Roll: %d | Name: %s | Age: %d | Marks: %.2f\n",
               arr[foundIndex].roll, arr[foundIndex].name,
               arr[foundIndex].age, arr[foundIndex].marks);
    } else {
        printf("\nNo student found with Roll Number %d (%d comparison(s)).\n", key, comparisons);
    }

    free(arr);
}

/* ================================================================
   Sorting: Bubble / Selection / Insertion Sort on an array snapshot,
   then the new order is written back into the linked list nodes.
   ================================================================ */

/* field: 1 = Roll Number, 2 = Name, 3 = Marks */
int compareStudents(Student a, Student b, int field) {
    if (field == 1) return a.roll - b.roll;
    if (field == 2) return strcmp(a.name, b.name);
    return (a.marks > b.marks) - (a.marks < b.marks);
}

void swapStudents(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Student arr[], int n, int field) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (compareStudents(arr[j], arr[j + 1], field) > 0) {
                swapStudents(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) break; /* already sorted, stop early */
    }
}

void selectionSort(Student arr[], int n, int field) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (compareStudents(arr[j], arr[minIdx], field) < 0) {
                minIdx = j;
            }
        }
        if (minIdx != i) swapStudents(&arr[i], &arr[minIdx]);
    }
}

void insertionSort(Student arr[], int n, int field) {
    for (int i = 1; i < n; i++) {
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && compareStudents(arr[j], key, field) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* Copies the linked list's data into a freshly malloc'd array. */
void toArray(Student **arr, int *n) {
    *n = totalStudents;
    *arr = (Student *)malloc(sizeof(Student) * (*n > 0 ? *n : 1));
    int i = 0;
    for (Student *cur = head; cur; cur = cur->next, i++) {
        (*arr)[i] = *cur; /* value copy of roll/name/age/marks */
    }
}

/* Writes the sorted array's data back into the existing list nodes,
   in order, so the list itself ends up sorted (node identities and
   pointers are unchanged - only the data each node holds is updated). */
void applySortedOrder(Student arr[], int n) {
    Student *cur = head;
    int i = 0;
    while (cur && i < n) {
        cur->roll = arr[i].roll;
        strncpy(cur->name, arr[i].name, NAME_LEN - 1);
        cur->name[NAME_LEN - 1] = '\0';
        cur->age = arr[i].age;
        cur->marks = arr[i].marks;
        cur = cur->next;
        i++;
    }
}

void sortMenu(void) {
    if (!head || totalStudents < 2) {
        printf("\nNot enough records to sort.\n");
        return;
    }

    printf("\n--- Sort Students ---\n");
    printf("Sort by field:\n1. Roll Number\n2. Name\n3. Marks\n");
    int field = getMenuChoice("Enter your choice: ", 1, 3);

    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n");
    int algo = getMenuChoice("Enter your choice: ", 1, 3);

    int n;
    Student *arr;
    toArray(&arr, &n);

    switch (algo) {
        case 1: bubbleSort(arr, n, field);    break;
        case 2: selectionSort(arr, n, field); break;
        case 3: insertionSort(arr, n, field); break;
    }

    applySortedOrder(arr, n);
    free(arr);
    saveToFile();

    printf("\nStudents sorted successfully!\n");
    displayAll();
}
