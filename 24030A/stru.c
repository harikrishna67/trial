#include<stdio.h>
struct student
{
    int roll;
    char name[100];
    float marks;
};
int main()

{

    struct student s;

    printf("Enter student roll number: ");
    scanf("%d", &s.roll);

    printf("Enter student name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter student marks: ");
    scanf("%f", &s.marks);

    printf("\n--- Student Information ---\n");
    printf("Roll Number: %d\n", s.roll);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);

}