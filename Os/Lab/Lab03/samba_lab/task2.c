#include<stdio.h>
struct OS_Class
{
	char OS_type[20];
	int no_of_PC;
};

struct student
{
	char rollno[20];
	int semester;
	struct OS_Class os;
};

int main()
{
	struct student s;
	printf("Enter the rollno of student: ");
	scanf("%s", s.rollno);
	printf("Enter the semester of student: ");
	scanf("%d", &s.semester);
	printf("Enter the OS type of student: ");
	scanf("%s", s.os.OS_type);
	printf("Enter the no of PC of student: ");
	scanf("%d", &s.os.no_of_PC);
	printf("Rollno of student: %s \n", s.rollno);
	printf("Semester of student: %d \n", s.semester);
	printf("OS type of student: %s \n", s.os.OS_type);
	printf("No of PC of student: %d \n", s.os.no_of_PC);
	return 0;
}
