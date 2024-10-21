#include <stdio.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    char id[20];
    char telephone[15];
    float rent;
    float mess;
    int lateDays;
} Student;

int isNumber(const char *str) {
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        str++;
    }
    return 1;
}

void inputStudentDetails(Student *Student) {
    printf("Enter Student name: ");
    scanf(" %[^\n]", Student->name);
    
    do {
        printf("Enter Student ID (numbers only): ");
        scanf(" %s", Student->id);
        if (!isNumber(Student->id)) {
            printf("Error: Student ID must be numbers only.\n");
        }
    } while (!isNumber(Student->id));
    
    do {
        printf("Enter telephone number (numbers only): ");
        scanf(" %s", Student->telephone);
        if (!isNumber(Student->telephone)) {
            printf("Error: Telephone number must be numbers only.\n");
        }
    } while (!isNumber(Student->telephone));
    
    do {
        printf("Enter monthly rent amount: ");
        if (scanf("%f", &Student->rent) != 1 || Student->rent < 0) {
            printf("Error: Monthly rent must be a positive number.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue; // Re-prompt for rent
        }
        break; // Valid input, exit loop
    } while (1); // Infinite loop, will break on valid input

    do {
        printf("Enter Mess charges: ");
        if (scanf("%f", &Student->mess) != 1 || Student->mess < 0) {
            printf("Error: Mess charges must be a positive number.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue; // Re-prompt for Mess
        }
        break; // Valid input, exit loop
    } while (1); // Infinite loop, will break on valid input

    do {
        printf("Enter number of late days: ");
        if (scanf("%d", &Student->lateDays) != 1 || Student->lateDays < 0) {
            printf("Error: Number of late days must be a non-negative integer.\n");
            while (getchar() != '\n'); // Clear invalid input
        }
    } while (Student->lateDays < 0);
}

float calculateTotalBill(Student Student) {
    float lateFee = (Student.lateDays > 0) ? Student.lateDays * 5.0 : 0.0; // Late fee of Rs 5 per day
    return Student.rent + Student.mess + lateFee;
}

void displayBill(Student Student) {
    printf("\n----- Rental Bill -----\n");
    printf("Student ID: %s\n", Student.id);
    printf("Student Name: %s\n", Student.name);
    printf("Telephone No: %s\n", Student.telephone);
    printf("Monthly Rent: Rs %.2f\n", Student.rent);
    printf("Utilities Charges: Rs %.2f\n", Student.mess);
    printf("Late Fees for %d days: Rs %.2f\n", Student.lateDays, Student.lateDays * 5.0);
    printf("Total Amount Due: Rs %.2f\n", calculateTotalBill(Student));
    printf("-----------------------\n");
}

int main() {
    Student STUDENTS[MAX_STUDENTS];
    int StudentCount = 0;
    char choice;

    do {
        if (StudentCount >= MAX_STUDENTS) {
            printf("Maximum Student limit reached.\n");
            break;
        }

        inputStudentDetails(&STUDENTS[StudentCount]);
        displayBill(STUDENTS[StudentCount]);
        StudentCount++;

        printf("Do you want to add another Student? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Property Rental Management System!\n");
    return 0;
}
