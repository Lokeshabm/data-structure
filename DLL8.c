#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct Employee
{
struct Employee *llink;
int ssn;
char name[50];
float sal;
struct Employee *rlink; 
};
typedef struct Employee *NODE;
int count = 0; 
NODE first = NULL; 
NODE createNode(); 
void createDll(); 
void insertFront(); 
void insertEnd(); 
void deleteFront(); 
void deleteEnd(); 
void displayDll(); 
int main()
{
int ch;

while (1)
{
printf("\n1.Create Emp DLL \n2.insert Front \n3.Insert End \n4.Delete Front \n5.Delete End \n6.Display DLL \n7.Exit\n Enter Your Choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1:
createDll(); 
break;
case 2:
insertFront(); 
break;
case 3:
insertEnd(); 
break;
case 4:
deleteFront();
break;
case 5:
deleteEnd(); 
break;
case 6:
displayDll();
break;
case 7:
exit(0);
}
}
return 0;
}
NODE createNode()
{
NODE temp;
temp = malloc(sizeof(struct Employee)); 
printf("Enter emp SSN: \t");
scanf("%d", &temp->ssn);
printf("Enter emp Name: \t");
scanf("%s", temp->name);
printf("Enter emp Salary: \t");
scanf("%f", &temp->sal);
temp->llink = NULL; 
temp->rlink = NULL;
count++; 
return temp; 
}
void createDll()
{
int i, n;
NODE temp, cur; 
printf("\n Enter number of Employees:");
scanf("%d", &n);
for (i = 0; i < n; i++)
{
printf("Enter Employee[%d] Details:\n", i + 1);
temp = createNode(); 
if (first == NULL)
{
first = temp;
}
else
{
cur = first; 
while (cur->rlink != NULL) 
{
cur = cur->rlink; 
}
cur->rlink = temp; 
temp->llink = cur; 
}
}
displayDll();
}
void insertFront()
{
NODE temp;
temp = createNode(); 
first->llink = temp;
temp->rlink = first; 
first = temp; 
displayDll();
}
void insertEnd()
{
NODE cur = first;
NODE temp = createNode();
while (cur->rlink != NULL)
{
cur = cur->rlink; 
}
cur->rlink = temp; 
temp->llink = cur; 
count++; 
displayDll();
}
void deleteFront()
{
NODE cur;
cur = first->rlink; 
free(first); 
first = cur; 

first->llink = NULL; 
count--; 
displayDll();
}
void deleteEnd()
{
NODE cur, prev; 
cur = first; 
while (cur->rlink != NULL) 
{
prev = cur; 
cur = cur->rlink; 
free(cur); 
prev->rlink = NULL; 
count--; 
displayDll();
}
}
void displayDll()
{
int count = 0;
NODE cur; 
cur = first; 
if (first == NULL) 
{
printf("\n List is Empty!");
return;
}
printf("\n SSN \t Name \t\t Salary \n");
while (cur != NULL)
{
printf("%d \t %s \t\t %f \n ", cur->ssn, cur->name, cur->sal);
cur = cur->rlink;
count++;
}
printf("\n Total Num of employees:%d\n ", count); 
}