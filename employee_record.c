#include <stdio.h>
#include <string.h>

#define MAX_EMP 200
#define NAME_LEN 50
#define DEPT_LEN 30
#define DB_FILE "employees.dat"

typedef struct {
    int id;
    char name[NAME_LEN];
    char department[DEPT_LEN];
    int age;
    float salary;
} Employee;

/* ---- Prototypes ---- */
void loadFromFile(Employee emp[], int *n);
void saveToFile(Employee emp[], int n);
void addEmployee(Employee emp[], int *n);
void listEmployees(const Employee emp[], int n);
int  findIndexById(const Employee emp[], int n, int id);
void searchEmployee(const Employee emp[], int n);
void updateEmployee(Employee emp[], int n);
void deleteEmployee(Employee emp[], int *n);

/* helper to read a line with spaces */
void readLine(const char *prompt, char *buf, int size);
int  readInt(const char *prompt);
float readFloat(const char *prompt);

int main(void) {
    Employee emp[MAX_EMP];
    int n = 0;
    int choice;

    loadFromFile(emp, &n);  // try to restore previous records

    do {
        printf("\n===== Employee Record Maintenance =====\n");
        printf("1. Add Employee\n");
        printf("2. List All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Save to File\n");
        printf("7. Load from File\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { // handle non-numeric input
            while (getchar() != '\n');   // clear buffer
            choice = 0;
        }

        switch (choice) {
            case 1: addEmployee(emp, &n); break;
            case 2: listEmployees(emp, n); break;
            case 3: searchEmployee(emp, n); break;
            case 4: updateEmployee(emp, n); break;
            case 5: deleteEmployee(emp, &n); break;
            case 6: saveToFile(emp, n); break;
            case 7: loadFromFile(emp, &n); break;
            case 8: printf("Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 8);

    return 0;
}

/* ---------------- Implementations ---------------- */

void readLine(const char *prompt, char *buf, int size) {
    printf("%s", prompt);
    while (getchar() != '\n'); // clear any leftover newline from previous scanf
    if (fgets(buf, size, stdin)) {
        size_t len = strlen(buf);
        if (len && buf[len-1] == '\n') buf[len-1] = '\0';
    } else {
        buf[0] = '\0';
    }
}

int readInt(const char *prompt) {
    int x;
    printf("%s", prompt);
    while (scanf("%d", &x) != 1) {
        while (getchar() != '\n');
        printf("Invalid input. %s", prompt);
    }
    return x;
}

float readFloat(const char *prompt) {
    float x;
    printf("%s", prompt);
    while (scanf("%f", &x) != 1) {
        while (getchar() != '\n');
        printf("Invalid input. %s", prompt);
    }
    return x;
}

int findIndexById(const Employee emp[], int n, int id) {
    for (int i = 0; i < n; i++)
        if (emp[i].id == id) return i;
    return -1;
}

void addEmployee(Employee emp[], int *n) {
    if (*n >= MAX_EMP) {
        printf("Database full. Cannot add more employees.\n");
        return;
    }

    int id = readInt("Enter Employee ID: ");
    if (findIndexById(emp, *n, id) != -1) {
        printf("ID already exists. Use Update instead.\n");
        return;
    }

    emp[*n].id = id;

    readLine("Enter Name: ", emp[*n].name, NAME_LEN);
    printf("Enter Age: ");
    while (scanf("%d", &emp[*n].age) != 1 || emp[*n].age <= 0) {
        while (getchar() != '\n');
        printf("Invalid age. Enter Age: ");
    }

    while (getchar() != '\n'); // clear newline before next line input
    readLine("Enter Department: ", emp[*n].department, DEPT_LEN);

    emp[*n].salary = readFloat("Enter Salary: ");

    (*n)++;
    printf("Employee added successfully.\n");
}

void listEmployees(const Employee emp[], int n) {
    if (n == 0) {
        printf("No records to display.\n");
        return;
    }
    printf("\n%-6s %-20s %-12s %-6s %-10s\n", "ID", "Name", "Department", "Age", "Salary");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-6d %-20s %-12s %-6d %-10.2f\n",
               emp[i].id, emp[i].name, emp[i].department, emp[i].age, emp[i].salary);
    }
}

void searchEmployee(const Employee emp[], int n) {
    if (n == 0) { printf("No records.\n"); return; }
    int id = readInt("Enter ID to search: ");
    int idx = findIndexById(emp, n, id);
    if (idx == -1) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }
    printf("Record found:\n");
    printf("ID: %d\nName: %s\nDepartment: %s\nAge: %d\nSalary: %.2f\n",
           emp[idx].id, emp[idx].name, emp[idx].department, emp[idx].age, emp[idx].salary);
}

void updateEmployee(Employee emp[], int n) {
    if (n == 0) { printf("No records.\n"); return; }
    int id = readInt("Enter ID to update: ");
    int idx = findIndexById(emp, n, id);
    if (idx == -1) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }

    int choice;
    printf("\nUpdate Options for ID %d:\n", id);
    printf("1. Name\n2. Department\n3. Age\n4. Salary\n5. Update All\nEnter choice: ");
    if (scanf("%d", &choice) != 1) { while (getchar() != '\n'); choice = 0; }

    switch (choice) {
        case 1:
            readLine("New Name: ", emp[idx].name, NAME_LEN);
            break;
        case 2:
            readLine("New Department: ", emp[idx].department, DEPT_LEN);
            break;
        case 3:
            emp[idx].age = readInt("New Age: ");
            break;
        case 4:
            emp[idx].salary = readFloat("New Salary: ");
            break;
        case 5:
            readLine("New Name: ", emp[idx].name, NAME_LEN);
            emp[idx].age = readInt("New Age: ");
            while (getchar() != '\n');
            readLine("New Department: ", emp[idx].department, DEPT_LEN);
            emp[idx].salary = readFloat("New Salary: ");
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }
    printf("Record updated.\n");
}

void deleteEmployee(Employee emp[], int *n) {
    if (*n == 0) { printf("No records.\n"); return; }
    int id = readInt("Enter ID to delete: ");
    int idx = findIndexById(emp, *n, id);
    if (idx == -1) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }
    for (int i = idx; i < *n - 1; i++) emp[i] = emp[i + 1];
    (*n)--;
    printf("Record deleted.\n");
}

void saveToFile(Employee emp[], int n) {
    FILE *fp = fopen(DB_FILE, "wb");
    if (!fp) { printf("Could not open file for writing.\n"); return; }
    fwrite(&n, sizeof(int), 1, fp);
    fwrite(emp, sizeof(Employee), n, fp);
    fclose(fp);
    printf("Saved %d record(s) to \"%s\".\n", n, DB_FILE);
}

void loadFromFile(Employee emp[], int *n) {
    FILE *fp = fopen(DB_FILE, "rb");
    if (!fp) { 
        *n = 0; 
        return; 
    }
    int count = 0;
    if (fread(&count, sizeof(int), 1, fp) != 1) { fclose(fp); *n = 0; return; }
    if (count < 0 || count > MAX_EMP) { fclose(fp); *n = 0; return; }
    size_t readItems = fread(emp, sizeof(Employee), count, fp);
    fclose(fp);
    if ((int)readItems != count) { *n = 0; return; }
    *n = count;
    printf("Loaded %d record(s) from \"%s\".\n", *n, DB_FILE);
}
