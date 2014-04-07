#include <stdio.h>
#include <stdlib.h>

int main()
{
    int StartingDay, NumofDay;

    printf("enter the starting day of week(0 = Sunday, 1 = Monday, etc): ");
    scanf("%d", &StartingDay);/*assign StartingDay*/

    printf("\nenter the number of days in the month:");
    scanf("%d", &NumofDay);/*assign Number of Day this month*/

    int i,j;
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");/*print headline*/
    for(i=0;i<=5;i++){/*i=number of row*/
       /*j=date,while colum=1~6*/
       for(j=1+(7*i-StartingDay);j<7+(7*i-StartingDay);j++){
            if(j<=0)
                printf("%4c", 0);/*(j=date)<=0,print null*/
            else if(j<=NumofDay)
                printf("%4d", j);/*NumofDay>=(j=date)>0,print j*/
            else
                return 0;/*NumofDay<(j=date),end of main*/
        }

    printf("%4d\n", j);/*j=date,while colum=7*/
    }
    return 0;
}
