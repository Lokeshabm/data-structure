#include <stdio.h>
#include<stdlib.h>
int main()
{
 int *p, n, ele, ch, i, pos; // p is pointer to create a dynamic array
 printf("Enter number of elements to create an Array:\t");
 scanf("%d", &n);
 p = malloc(n * sizeof(int)); // use malloc to create a Dynamic array
 printf("Dynamic Array Created.\n");
 printf("Enter %d elements\n ", n);
 for (i = 0; i < n; i++) // Read n the elements to array
 {
 scanf("%d", &p[i]);
 }
 while (1)
 {
 printf("\n 1.Insert\n 2.delete\n 3.display \n 4.Exit\n Enter your
choice:\t");
 scanf("%d", &ch);
 switch (ch)
 {
 case 1:
 printf("\n Enter element & Pos(0 to %d) to insert:\t", n - 1);
 scanf("%d%d", &ele, &pos);
 realloc(p, (n+1) * sizeof(int)); // increase the size of array by 1
 n = n + 1; // update new size
 for (i = n - 1; i >= pos; i--) // Start moving all the elements to the next positions
 {
 p[i] = p[i - 1];
 }
 p[pos] = ele; // insert the new element at specied position
 break;
 case 2:
 printf("Enter Position(0 to %d) to delete:\t", n - 1);
 scanf("%d", &pos);
 for (i = pos + 1; i < n; i++) // delete the position element by moving

 {
 p[i - 1] = p[i];
 }
 n = n - 1; // Update the count total elements
 break;
 case 3:
 printf("\n Array Elements Are:\n");
 for (i = 0; i < n; i++)
 {
 printf("%d\t", p[i]);
 }
 break;
 case 4:
 exit(0);
 }
 }
 return 0;
} 
