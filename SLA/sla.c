/* ================================================================
   GODOWN INVENTORY MANAGEMENT SYSTEM  (compact version)
   Language   : C (C99)
   Storage    : text file "inventory.txt"  (no SQL / no database)
   In-memory  : Doubly Linked List
   Algorithms : Bubble / Selection / Insertion Sort,
                Linear Search, Binary Search
   File format (CSV): id,name,godown,quantity,price
   Build      : gcc -std=c99 -Wall -Wextra godown_inventory.c -o inventory
   ================================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILENAME "inventory.txt"
#define LEN 50

typedef struct Product {
    int   id;
    char  name[LEN];
    char  godown[LEN];
    int   qty;
    float price;
    struct Product *prev, *next;
} Product;

Product *head = NULL, *tail = NULL;
int total = 0;

void saveToFile(void);

/* ---------------- Input helpers ---------------- */

void readLine(char *buf, int size) {
    if (!fgets(buf, size, stdin)) {          /* input closed: save and quit */
        saveToFile();
        exit(0);
    }
    size_t n = strcspn(buf, "\n");
    if (buf[n] == '\n') buf[n] = '\0';
    else { int c; while ((c = getchar()) != '\n' && c != EOF) {} }
}

int getInt(const char *prompt, int min, int max) {
    char buf[64], *end;
    while (1) {
        printf("%s", prompt);
        readLine(buf, sizeof buf);
        long v = strtol(buf, &end, 10);
        if (end != buf && *end == '\0' && v >= min && v <= max) return (int)v;
        printf("  Enter a whole number between %d and %d.\n", min, max);
    }
}

float getFloat(const char *prompt) {
    char buf[64], *end;
    while (1) {
        printf("%s", prompt);
        readLine(buf, sizeof buf);
        double v = strtod(buf, &end);
        if (end != buf && *end == '\0' && v >= 0 && v < 1e9) return (float)v;
        printf("  Enter a valid non-negative number.\n");
    }
}

/* Non-empty text; commas become spaces because ',' is the file separator. */
void readText(const char *prompt, char *out) {
    char buf[100];
    while (1) {
        printf("%s", prompt);
        readLine(buf, sizeof buf);
        for (char *p = buf; *p; p++) if (*p == ',') *p = ' ';
        if (buf[strspn(buf, " ")]) {
            strncpy(out, buf, LEN - 1);
            out[LEN - 1] = '\0';
            return;
        }
        printf("  This field cannot be empty.\n");
    }
}

/* ---------------- Doubly Linked List ---------------- */

Product *createNode(int id, const char *name, const char *godown, int qty, float price) {
    Product *n = malloc(sizeof(Product));
    if (!n) { printf("Out of memory!\n"); exit(1); }
    n->id = id; n->qty = qty; n->price = price;
    snprintf(n->name, LEN, "%s", name);
    snprintf(n->godown, LEN, "%s", godown);
    n->prev = n->next = NULL;
    return n;
}

void appendNode(Product *n) {                /* insert at tail */
    if (!head) head = tail = n;
    else { tail->next = n; n->prev = tail; tail = n; }
    total++;
}

Product *findById(int id) {                  /* linear traversal */
    Product *c = head;
    while (c && c->id != id) c = c->next;
    return c;
}

void freeList(void) {
    while (head) { Product *t = head; head = head->next; free(t); }
    tail = NULL;
    total = 0;
}

/* ---------------- File storage ---------------- */

void loadFromFile(void) {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) return;
    char line[200], name[LEN], godown[LEN];
    int id, qty;
    float price;
    while (fgets(line, sizeof line, fp))
        if (sscanf(line, "%d,%49[^,],%49[^,],%d,%f", &id, name, godown, &qty, &price) == 5
            && id > 0 && qty >= 0 && !findById(id))
            appendNode(createNode(id, name, godown, qty, price));
    fclose(fp);
    printf("Loaded %d product(s) from '%s'.\n", total, FILENAME);
}

void saveToFile(void) {
    FILE *fp = fopen(FILENAME, "w");
    if (!fp) { printf("Error: cannot write '%s'!\n", FILENAME); return; }
    for (Product *c = head; c; c = c->next)
        fprintf(fp, "%d,%s,%s,%d,%.2f\n", c->id, c->name, c->godown, c->qty, c->price);
    fclose(fp);
}

/* ---------------- Display ---------------- */

void printHeader(void) {
    printf("\n%-6s %-24s %-16s %8s %10s\n", "ID", "Product", "Godown", "Qty", "Price");
    printf("------------------------------------------------------------------\n");
}

void printRow(const Product *p) {
    printf("%-6d %-24.24s %-16.16s %8d %10.2f\n", p->id, p->name, p->godown, p->qty, p->price);
}

void displayAll(void) {
    if (!head) { printf("\nInventory is empty.\n"); return; }
    printHeader();
    for (Product *c = head; c; c = c->next) printRow(c);
    printf("------------------------------------------------------------------\n");
    printf("Total products: %d\n", total);
}

/* ---------------- Add / Edit / Delete / Stock ---------------- */

void addProduct(void) {
    char name[LEN], godown[LEN];
    printf("\n--- Add Product ---\n");
    int id = getInt("Product ID: ", 1, 999999999);
    if (findById(id)) { printf("A product with ID %d already exists!\n", id); return; }
    readText("Name: ", name);
    readText("Godown: ", godown);
    int qty = getInt("Quantity: ", 0, 1000000000);
    float price = getFloat("Unit price: ");
    appendNode(createNode(id, name, godown, qty, price));
    saveToFile();
    printf("Product added.\n");
}

void editProduct(void) {
    printf("\n--- Edit Product ---\n");
    Product *p = findById(getInt("Product ID: ", 1, 999999999));
    if (!p) { printf("Product not found.\n"); return; }
    printHeader(); printRow(p);
    printf("Enter the new details:\n");
    readText("Name: ", p->name);
    readText("Godown: ", p->godown);
    p->qty = getInt("Quantity: ", 0, 1000000000);
    p->price = getFloat("Unit price: ");
    saveToFile();
    printf("Product updated.\n");
}

void deleteProduct(void) {
    printf("\n--- Delete Product ---\n");
    Product *c = findById(getInt("Product ID: ", 1, 999999999));
    if (!c) { printf("Product not found.\n"); return; }
    if (c->prev) c->prev->next = c->next; else head = c->next;   /* head case */
    if (c->next) c->next->prev = c->prev; else tail = c->prev;   /* tail case */
    free(c);
    total--;
    saveToFile();
    printf("Product deleted.\n");
}

void stockInOut(void) {
    printf("\n--- Stock In / Stock Out ---\n");
    Product *p = findById(getInt("Product ID: ", 1, 999999999));
    if (!p) { printf("Product not found.\n"); return; }
    printHeader(); printRow(p);
    int in = getInt("\n1. Stock In (received)\n2. Stock Out (dispatched)\nChoice: ", 1, 2) == 1;
    int amt = getInt("Quantity: ", 1, 1000000000);
    if (in) {
        if ((long long)p->qty + amt > 1000000000LL) { printf("Quantity too large.\n"); return; }
        p->qty += amt;
    } else {
        if (amt > p->qty) { printf("Only %d unit(s) in stock!\n", p->qty); return; }
        p->qty -= amt;
    }
    saveToFile();
    printf("Stock updated. New quantity: %d\n", p->qty);
}

/* ---------------- Sorting (array copy, written back to the list) ---------------- */

int icmp(const char *a, const char *b) {     /* case-insensitive strcmp */
    while (*a && tolower((unsigned char)*a) == tolower((unsigned char)*b)) a++, b++;
    return tolower((unsigned char)*a) - tolower((unsigned char)*b);
}

int icontains(const char *h, const char *n) { /* case-insensitive strstr */
    for (; *h; h++) {
        const char *a = h, *b = n;
        while (*b && tolower((unsigned char)*a) == tolower((unsigned char)*b)) a++, b++;
        if (!*b) return 1;
    }
    return !*n;
}

/* field: 1 = ID, 2 = Name, 3 = Godown, 4 = Quantity, 5 = Price */
int cmp(const Product *a, const Product *b, int field) {
    switch (field) {
        case 1:  return a->id - b->id;
        case 2:  return icmp(a->name, b->name);
        case 3:  return icmp(a->godown, b->godown);
        case 4:  return a->qty - b->qty;
        default: return (a->price > b->price) - (a->price < b->price);
    }
}

void swap(Product *a, Product *b) { Product t = *a; *a = *b; *b = t; }

void bubbleSort(Product a[], int n, int f) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
            if (cmp(&a[j], &a[j + 1], f) > 0) { swap(&a[j], &a[j + 1]); swapped = 1; }
        if (!swapped) break;
    }
}

void selectionSort(Product a[], int n, int f) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++)
            if (cmp(&a[j], &a[m], f) < 0) m = j;
        if (m != i) swap(&a[i], &a[m]);
    }
}

void insertionSort(Product a[], int n, int f) {
    for (int i = 1; i < n; i++) {
        Product key = a[i];
        int j = i - 1;
        while (j >= 0 && cmp(&a[j], &key, f) > 0) { a[j + 1] = a[j]; j--; }
        a[j + 1] = key;
    }
}

Product *toArray(void) {                     /* snapshot of the list */
    Product *a = malloc(sizeof(Product) * (total ? total : 1));
    if (!a) { printf("Out of memory!\n"); exit(1); }
    int i = 0;
    for (Product *c = head; c; c = c->next) a[i++] = *c;
    return a;
}

void sortMenu(void) {
    if (total < 2) { printf("\nNot enough products to sort.\n"); return; }
    printf("\n--- Sort Products (ascending) ---\n");
    int f = getInt("Sort by:\n1. ID\n2. Name\n3. Godown\n4. Quantity\n5. Price\nChoice: ", 1, 5);
    int algo = getInt("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\nChoice: ", 1, 3);

    Product *a = toArray();
    if (algo == 1) bubbleSort(a, total, f);
    else if (algo == 2) selectionSort(a, total, f);
    else insertionSort(a, total, f);

    int i = 0;                               /* write sorted data back, keep links */
    for (Product *c = head; c; c = c->next, i++) {
        Product *p = c->prev, *n = c->next;
        *c = a[i];
        c->prev = p; c->next = n;
    }
    free(a);
    saveToFile();
    printf("Sorted successfully!\n");
    displayAll();
}

/* ---------------- Searching ---------------- */

/* Linear search walks the list node by node. */
void linearSearch(void) {
    int byId = getInt("\n1. By ID\n2. By Name (partial match)\nChoice: ", 1, 2) == 1;
    int id = 0, found = 0, steps = 0;
    char key[100];
    if (byId) id = getInt("Enter ID: ", 1, 999999999);
    else { printf("Enter name: "); readLine(key, sizeof key); }

    for (Product *c = head; c; c = c->next) {
        steps++;
        if (byId ? c->id == id : icontains(c->name, key)) {
            if (!found++) printHeader();
            printRow(c);
            if (byId) break;
        }
    }
    if (found) printf("\n%d match(es) in %d step(s) (Linear Search).\n", found, steps);
    else       printf("\nNo match found (%d step(s)).\n", steps);
}

/* Binary search needs sorted random-access data, so it runs on a
   temporary array copy sorted by ID (the stored order is untouched). */
void binarySearch(void) {
    Product *a = toArray();
    insertionSort(a, total, 1);
    int key = getInt("Enter ID: ", 1, 999999999);
    int lo = 0, hi = total - 1, steps = 0, pos = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        steps++;
        if (a[mid].id == key) { pos = mid; break; }
        if (a[mid].id < key) lo = mid + 1; else hi = mid - 1;
    }
    if (pos >= 0) { printHeader(); printRow(&a[pos]); printf("\nFound in %d step(s) (Binary Search).\n", steps); }
    else printf("\nNo product with ID %d (%d step(s)).\n", key, steps);
    free(a);
}

void searchMenu(void) {
    if (!head) { printf("\nInventory is empty.\n"); return; }
    printf("\n--- Search Product ---\n");
    if (getInt("1. Linear Search\n2. Binary Search (by ID)\nChoice: ", 1, 2) == 1) linearSearch();
    else binarySearch();
}

/* ---------------- main ---------------- */

int main(void) {
    loadFromFile();
    int choice;
    do {
        printf("\n==========================================\n"
               "   GODOWN INVENTORY MANAGEMENT SYSTEM\n"
               "==========================================\n"
               " 1. Add Product\n 2. Display All\n 3. Search Product\n"
               " 4. Edit Product\n 5. Delete Product\n 6. Stock In / Out\n"
               " 7. Sort Products\n 8. Save & Exit\n"
               "==========================================\n");
        choice = getInt("Enter your choice: ", 1, 8);
        switch (choice) {
            case 1: addProduct();    break;
            case 2: displayAll();    break;
            case 3: searchMenu();    break;
            case 4: editProduct();   break;
            case 5: deleteProduct(); break;
            case 6: stockInOut();    break;
            case 7: sortMenu();      break;
            case 8: saveToFile(); printf("\nSaved to '%s'. Goodbye!\n", FILENAME); break;
        }
    } while (choice != 8);
    freeList();
    return 0;
}
