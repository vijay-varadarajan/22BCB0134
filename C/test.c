#include <stdio.h>
int main()
{
int num1;
int num2;
int cal;
int a;
    printf("enter the number 1:");
    scanf("%d", &num1);
    printf("enter the number 2:");
    scanf("%d",&num2);
    printf("for addition enter 1\nfor subtraction enter 2\nfor multiplication enter 3\nfor division enter 4\nfor quotient enter 5\n");
     printf("enter the number of calculation:");
    scanf("%d",&cal);
if (cal==1)
 {
 a=num1+num2;
 printf("the addition value is %d",a);
 }
 else if(cal==2)
{
a=num1-num2;
printf("the subtration value is %d",a);
}
else if (cal==3)
{
a=num1*num2;
printf("the multiplication value is %d",a);
}
else if (cal==4)
{
a=num1/num2;
printf("the division value is %d",a);
}
else if (cal==5)
{
a=num1%num2;
printf("the quotient value is %d",a);
}
 else
   {
     printf("Invalid");
 }
}