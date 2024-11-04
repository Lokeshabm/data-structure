#include <stdio.h>
#include<stdlib.h>
#define MAX 6
int stack[MAX], ele, num, top = -1;
void push(int);
int pop();
void stakstatus();
void display();
int main()
{
int ch;
while (1)
{
printf("\n1.Push \n2.Pop \n3.Stack Status \n4.Display\n 5.Exit \n Enter Your choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1:
printf("\n Enter element to Push: ");
scanf("%d", &ele);
push(ele);
break;
case 2:
ele = pop();
printf("\n Popped element from stack: %d", ele);
break;
case 3:
stakstatus();
break;
case 4:
display();
break;
case 5:
exit(0);
}
}
}
void push(int ele)
{
if (top == MAX - 1) 
{
printf("\n Stack is Overflow...\n");
}
else
{
stack[++top] = ele;
}
}
int pop()
{
if (top == -1)
{
printf("\n Stack is underflow! \n");
}
else
{
return stack[top--]; 
}
}
void stakstatus()
{
if (top == MAX - 1) 
{
printf("Stack is Full!");
}
display();
}
void display()
{
int i;
if (top == -1)
{
printf("Stack is empty!\n");
}
else
{
printf("Stack eles are \n");
for (i = top; i >= 0; i--)
{
printf("%d \n", stack[i]);
}
}
}