#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct term {
 int row;
 int col;
 int value;
};
struct term sparse[MAX],trans[MAX];
int size; // Total num of values..
void create();
void transpose();
void display(int values,struct term matrix[]);
int main() {
 int choice;
 while(1) {
 printf("\nMenu:\n");
 printf("1. Create Sparse Matrix\n");
 printf("2. Transpose of Sparse Matrix\n");
 // printf(". Display Sparse Matrix\n");
 printf("3. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 create();
 break;
 case 2:
 transpose();
 break;
 case 3:
 exit(0);
 }
 }
 return 0;
}
void create() {
 int matrix[10][10];
 int i,rows,cols,values; // Starting index from 1 since 0 is used formatrix dimensions
 printf("\nEnter number of Rows,Columns and number of Values :");
 scanf("%d%d%d",&rows,&cols,&values);
 sparse[0].row = rows;
 sparse[0].col = cols;
 sparse[0].value = values; // Initially no non-zero elements
 for(i=1;i<=values;i++)
 {
 printf("\n Enter row,col and value:");
 scanf("%d%d%d",&sparse[i].row,&sparse[i].col,&sparse[i].value);
 }
 display(values,sparse);
}
void transpose() {
 int i,values;
 // trans[0].row = sparse[0].col;
 // trans[0].col = sparse[0].row;
 // trans[0].value = sparse[0].value;
 values=sparse[0].value;
 for(i=0;i<=sparse[0].value;i++)
 {
 trans[i].row=sparse[i].col;
 trans[i].col=sparse[i].row;
 trans[i].value=sparse[i].value;
 }
 display(values,trans);
}
void display(int values,struct term a[]) {
 int i;
 printf("\n\t Row\tColumn\tValue\n");
 for (i = 0; i <= values; i++) {
 printf("a[%d]: %d\t%d\t%d\n",i, a[i].row, a[i].col, a[i].value);
 }
} 