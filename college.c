#include <stdio.h>
#include <string.h>

/* ---------- STRUCTURE ---------- */
struct student {
    char fname[20];
    char lname[20];
    int roll;
    float cgpa;
    char course[20];
};

/* ---------- GLOBAL ---------- */
struct student s[100];
int count = 0;

/* ---------- FUNCTION PROTOTYPES ---------- */
void menu();
void addStudent();
void findByRoll();
void findByName();
void findByCourse();
void countStudents();
void deleteStudent();
void updateStudent();
void saveToFile();
void loadFromFile();

/* ---------- UI LINE ---------- */
void line() {
    printf("\n====================================\n");
}

/* ---------- MENU ---------- */
void menu() {
    line();
    printf("   COLLEGE MANAGEMENT SYSTEM\n");
    line();
    printf("1. Add Student\n");
    printf("2. Find Student by Roll No\n");
    printf("3. Find Student by First Name\n");
    printf("4. Find Students by Course\n");
    printf("5. Count Students\n");
    printf("6. Delete Student\n");
    printf("7. Update Student\n");
    printf("0. Exit\n");
    line();
}

/* ---------- FILE LOAD ---------- */
void loadFromFile() {
    FILE *fp = fopen("students.dat", "rb");
    if (fp != NULL) {
        fread(&count, sizeof(int), 1, fp);
        fread(s, sizeof(struct student), count, fp);
        fclose(fp);
    }
}

/* ---------- FILE SAVE ---------- */
void saveToFile() {
    FILE *fp = fopen("students.dat", "wb");
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(s, sizeof(struct student), count, fp);
    fclose(fp);
}

/* ---------- ADD ---------- */
void addStudent() {
    int roll, i;

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    for(i = 0; i < count; i++) {
        if(s[i].roll == roll) {
            printf("Roll number already exists!\n");
            return;
        }
    }

    s[count].roll = roll;

    printf("First Name: ");
    scanf("%s", s[count].fname);

    printf("Last Name: ");
    scanf("%s", s[count].lname);

    printf("CGPA: ");
    scanf("%f", &s[count].cgpa);

    printf("Course: ");
    scanf("%s", s[count].course);

    count++;
    saveToFile();

    printf("Student Added Successfully!\n");
}

/* ---------- FIND BY ROLL ---------- */
void findByRoll() {
    int roll, i;
    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    for(i = 0; i < count; i++) {
        if(s[i].roll == roll) {
            line();
            printf("Roll  : %d\n", s[i].roll);
            printf("Name  : %s %s\n", s[i].fname, s[i].lname);
            printf("CGPA  : %.2f\n", s[i].cgpa);
            printf("Course: %s\n", s[i].course);
            line();
            return;
        }
    }
    printf("Student not found!\n");
}

/* ---------- FIND BY NAME ---------- */
void findByName() {
    char name[20];
    int i, found = 0;

    printf("Enter First Name: ");
    scanf("%s", name);

    for(i = 0; i < count; i++) {
        if(strcmp(s[i].fname, name) == 0) {
            printf("Roll:%d | %s %s | %.2f | %s\n",
                   s[i].roll, s[i].fname, s[i].lname,
                   s[i].cgpa, s[i].course);
            found = 1;
        }
    }
    if(!found)
        printf("No student found!\n");
}

/* ---------- FIND BY COURSE ---------- */
void findByCourse() {
    char course[20];
    int i, found = 0;

    printf("Enter Course Name: ");
    scanf("%s", course);

    for(i = 0; i < count; i++) {
        if(strcmp(s[i].course, course) == 0) {
            printf("Roll:%d | %s %s | %.2f\n",
                   s[i].roll, s[i].fname, s[i].lname, s[i].cgpa);
            found = 1;
        }
    }
    if(!found)
        printf("No student in this course!\n");
}

/* ---------- COUNT ---------- */
void countStudents() {
    printf("Total Students = %d\n", count);
}

/* ---------- DELETE ---------- */
void deleteStudent() {
    int roll, i;

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);

    for(i = 0; i < count; i++) {
        if(s[i].roll == roll) {
            s[i] = s[count - 1];
            count--;
            saveToFile();
            printf("Student Deleted Successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

/* ---------- UPDATE ---------- */
void updateStudent() {
    int roll, i, choice;

    printf("Enter Roll Number to Update: ");
    scanf("%d", &roll);

    for(i = 0; i < count; i++) {
        if(s[i].roll == roll) {

            printf("1. First Name\n2. Last Name\n3. CGPA\n4. Course\n");
            printf("Choice: ");
            scanf("%d", &choice);

            switch(choice) {
                case 1: scanf("%s", s[i].fname); break;
                case 2: scanf("%s", s[i].lname); break;
                case 3: scanf("%f", &s[i].cgpa); break;
                case 4: scanf("%s", s[i].course); break;
                default: printf("Invalid choice!\n"); return;
            }

            saveToFile();
            printf("Student Updated Successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

/* ---------- MAIN ---------- */
int main() {
    int choice;
    loadFromFile();

    while(1) {
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: findByRoll(); break;
            case 3: findByName(); break;
            case 4: findByCourse(); break;
            case 5: countStudents(); break;
            case 6: deleteStudent(); break;
            case 7: updateStudent(); break;
            case 0: 
                printf("Thank You!\n");
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
}
