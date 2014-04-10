#include <stdio.h>
#include <stdlib.h>
int DaysofMon(int year, int month){
    int days;
    if(month==2){/*February*/
         days=(year%4==0&&year%100!=0)||year%400==0? 29 : 28;/*if leap year February=29, else February=28*/
    }
        else if(month==4||month==6||month==9||month==11){/*little month*/
            days=30;
        }
            else/*big month*/
                days=31;
    return days;
}
int CountDaysBefore(int y){
    int i,Days=0;
    for(i=1753;i<y;i++){
    Days+=(i%4==0&&i%100!=0)||i%400==0 ? 366: 365;
    /*if leap year Days+=366, else Days+=365*/
    }
    return Days;
}
int CountDaysThisYear(int y, int m){
    int j,Days=0;
    for(j=1;j<m;j++){
        if(j==2){
         Days+=(y%4==0&&y%100!=0)||y%400==0 ? 29: 28;
         /*if leap year Days+=29, else Days+=28*/
        }
        else if(j==4||j==6||j==9||j==11){
         Days+=30;/*if little month Days+=30*/
        }
        else
         Days+=31;/*if big month Days+=31*/
        }
    return Days;
}
void PrintCalender( int StartingDay, int NumofDay){
    int i,j;

    printf(" Sun Mon Tue Wed Thu Fri Sat\n");/*print headline*/

    for(i=0;i<=5;i++){/*i=number of row*/

       /*j=date,while colum=1~6*/
       for(j=1+(7*i-StartingDay);j<7+(7*i-StartingDay);j++)
        {
            if(j<=0)
                printf("%4c", ' ');/*(j=date)<=0,print null*/
            else if(j<=NumofDay)
                printf("%4d", j);/*NumofDay>=(j=date)>0,print j*/
            else
                printf("%4c", ' ');/*(j=date)>NumofDay,print null*/
        }
        if(j>NumofDay)
            break;
        printf("%4d\n", j);/*j=date,while colum=7*/
    }
}

void date(int s){
(s==1)?printf("Monday"):
    (s==2)?printf("Tuesday"):
        (s==3)?printf("Wednesday"):
            (s==4)?printf("Thursday"):
                (s==5)?printf("Friday"):
                    (s==6)?printf("Saturday"):printf("Sunday");
}
void Month(int m){
(m==1)?printf("January"):
    (m==2)?printf("February"):
        (m==3)?printf("March"):
            (m==4)?printf("April"):
                (m==5)?printf("May"):
                    (m==6)?printf("June"):
                        (m==7)?printf("July"):
                            (m==8)?printf("August"):
                                (m==9)?printf("September"):
                                    (m==10)?printf("October"):
                                        (m==11)?printf("November"):
                                            (m==12)?printf("December"):printf("Error");
}
int main()
{
    /*Part 1*/

    int StartingDay, NumofDay;

    printf("enter the starting day of week(0 = Sunday, 1 = Monday, etc): ");
    scanf("%d", &StartingDay);/*assign StartingDay*/

    printf("\nenter the number of days in the month:");
    scanf("%d", &NumofDay);/*assign Number of Day this month*/

    PrintCalender(StartingDay, NumofDay);

     /*Part 2*/
    int year, month;

    printf("\nenter the year (1753-2099): ");
    scanf("%d", &year);/*input year*/

    printf("\nenter the month (1-12):");
    scanf("%d", &month);/*input month*/

    printf("\nThe month has %d days", NumofDay=DaysofMon(year, month));/*prints the number of days in that month*/

    StartingDay=(CountDaysBefore(year)+CountDaysThisYear(year, month)+1)%7;/*(count days till this month)/7,=0:Sun*/
    printf("\nThe first day of this month is a ");/*prints the day of the week that starts that month.*/
        date(StartingDay);/*prints starting day of this month */

    printf("\n         ");
        Month(month);/*prints this month*/
            printf(" %d\n", year);/*prints this year*/
     PrintCalender(StartingDay, NumofDay);/*prints calender*/
    return 0;
}
