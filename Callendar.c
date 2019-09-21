#include <stdio.h>
#include <stdlib.h>


int main()
{
char usr;  /// THIS IS USED FOR USR INPUT///

int day,month,year;   ///<---- FOR THE DATE ///

int day_of_week; ///<----FUNCTION THAT STORES ZELLER'S RESULTS ///
int day_of_week2;   /// <-----DAY OF THE WEEK ///

int Days_of_month;  ///<---CALCULATES THE DAYS OF EACH MONTH

int Getd; ///<--THIS IS FOR GET-DAY FUNCTION THE RESULTS STORED HERE ARE THE CHECKS///
                ///IN CASE OF INVALID VALUES


///         MENU SECTION        ///////////////////








///     START OF A LOOP     /////////////
do{

         system("cls");///<--------///CLEARS THE SCREEN

         printf("\t\t\t\tmenu\n");
         printf("\t\t\t\t----");
         printf("\n\t\t 1.input date");
         printf("\n\t\t 2.help");
         printf("\n\t\t 3.exit\n");
    /// // // ////////////////////////////


        scanf("%c",&usr); ///<----  asks user to choose option ///
        fflush(stdin);
////////////////////////////////////////////////////////////////////////


///             CHECKS USER INPUT   ////////
        if(usr=='3')    {

                    system("exit");

            }

    else if(usr=='2')    {

                    help();///<---CALLS THE HELP FUNCTION

                    printf("\n\n[?] Choose another option y/n: ");

                  scanf("%c",&usr);
                fflush(stdin);
                        if(usr=='n' || usr=='N')

                                system("exit");



            }


        else if(usr=='1')  {

                    printf("[!] date:");

                    scanf("%d %d %d",&day,&month,&year);

                    fflush(stdin);


                    day_of_week=getDayNumber(day,month,year); ///<-----getDayNumber IS CALLED THUS PRINTING THE RESULT IT RETURNS///

                    day_of_week2=getName(day_of_week);  ///<---DAY_OF_THE_WEEK2 HOLDS THE DAY///



                    Days_of_month=getNumber_Days(month,year); ///<----THIS FUNCTION RETURNS THE NUMBER_DAYS OF EACH MONTH GIVEN


                    Getd=GetDay(day,month,year); ///<---THIS FUNCTION CHECKS THE VALUES OF(DAY,MONTH,YEAR)



                            printf("\n\n[?] Choose another Option y/n:");

                                scanf("%c",&usr);
                                fflush(stdin);

                            if(usr=='n' || usr=='N')

                                    system("exit");


            }



}while(usr == 'y' || usr == 'Y');

///     END OF THE LOOP //////////

////////////////////////////////////////////



 printf("\n\n");

    return 0;
}






///         FUNC THAT CALCULATES THE DAY OF THE DATE    ///
int getDayNumber(int Day,int Month,int Year)
{
    int ZMonth, ZYear, Zeller,number;
    if(Month==1 || Month==2)
    {
        ZMonth = Month+10;
        ZYear = Year-1;
    }
    else
    {
        ZMonth = Month-2;
        ZYear = Year;
    }
    Zeller=((13*ZMonth-1)/5)+((ZYear%100)/4)+((ZYear/100)/4)+Day+ZYear%100-2*(ZYear/100);
   	number=Zeller%7;
   	if (number<0)
   		number+=7;
    return number;




}
///////////////////////////////////////////////
///     GETNAME FUNCTION ASSOCIATES THE NUMBERS FROM GETDAYNUMBER///
///     WITH THE NAMES OF THE DAYS(DAYS OF WEEK)    ////
int getName(int wday)
{

    switch(wday)
        {
            case 0:printf("\nSunday");
            break;

            case 1:printf("\nMonday");
            break;

            case 2:printf("\nTuesday");
            break;

            case 3:printf("\nWednesday");
            break;

            case 4:printf("\nThursday");
            break;

            case 5:printf("\nFriday");
            break;

            case 6:printf("\nSaturday");
            break;
        }

    return wday;
}





/// FUNCTION THAT Calculates THE DAYS OF THE MONTHS GIVEN
int getNumber_Days(m,Leap_year)
{
    int i;
    int sum=0;
    for(i=1; i<=31; i++)
    {
        if(m==2)    ///<---THATS A SMALL CHECK UP IN CASE OF MONTH BEING FEBRUARY
                    ///IT DECREASES MONTH DOWN TO TWO VALUES(FROM 31 TO 29)
        {
            sum=i-2;
        }


    }

    switch(m)
        {
            case 1:printf("\nJanuary's Days:%d",i-1);
            break;
            case 2:printf("\nFebruary's Days:%d",sum);
            break;
            case 3:printf("\nMarch's Days:%d",i-1);
            break;
            case 4:printf("\nApril's Days:%d",i-2);
            break;
            case 5:printf("\nMay's Days:%d",i-1);
            break;
            case 6:printf("\nJune's Days:%d",i-2);
            break;
            case 7:printf("\nJully's Days:%d",i-1);
            break;
            case 8:printf("\nAugust's Days:%d",i-1);
            break;
            case 9:printf("\nSeptember's Days:%d",i-2);
            break;
            case 10:printf("\nOctober's Days:%d",i-1);
            break;
            case 11:printf("\nNovember's Days:%d",i-2);
            break;
            case 12:printf("\nDecember's Days:%d",i-1);
        }

        leap_year(Leap_year);
    return 1;
}

///-----------------------------------------------///




///----FUNCTION TO DETERMINE LEAP YEAR-------///


int leap_year(int lyear)
{
    if(lyear%4==0 || lyear%400==0)
    {
        printf("\nleap year");
    }

    else if(lyear%4==0 || lyear%100!=0)
    {
        printf("\nNOT Leap");
    }


    return 3;
}


///---------------  END OF LEAP YEAR FUNCTION   --------------------------------///

///--GETDAY FUNCTION CHECKS THE DAY,YEAR,MONTH--///
///---IN CASE OF INVALID VALUES--///

int GetDay(int d,int m,int y)
{
    char usr;


    if(d>31 || d<1)
    {
        printf("\n[!] Invalid Day of Month! Proper Values(1-31)");
        printf("\n\nTry Again");
        exit(1);

    }


    if(m>12 || m<=0)
    {
        printf("\n[!] Invalid Month! Proper Values(1-12)");
        printf("\n\nTry Again");
        exit(1);
    }

    if(y<1600)
    {
        printf("\nInvalid Year! Proper Values(must be greater than 1600)");
        printf("\n\nTry Again");
        exit(1);
    }



    printf("\n\nUse The Console? Y/N:");

    usr=getch();


    if(usr=='y' || usr=='Y')
    {
         system("cls");
         printDate(m,y); ///<---FUNCTION THAT RETURNS MONTH AND YEAR///


    }





    return 11;
}




void printDate(int m,int zyear)
{
    printf("\n\n\n\t\t\t---------------------------------");
    switch(m){


            case 1:printf("\n\n\t\t\t\tJanuary , %d",zyear);
            break;
            case 2:printf("\n\n\t\t\t\tFebruary , %d",zyear);
            break;
            case 3:printf("\n\n\t\t\t\tMarch , %d",zyear);
            break;
            case 4:printf("\n\n\t\t\t\tApril , %d",zyear);
            break;
            case 5:printf("\n\n\t\t\t\tMay , %d",zyear);
            break;
            case 6:printf("\n\n\t\t\t\tJune , %d",zyear);
            break;
            case 7:printf("\n\n\t\t\t\tJuly , %d",zyear);
            break;
            case 8:printf("\n\n\t\t\t\tAugust , %d",zyear);
            break;
            case 9:printf("\n\n\t\t\t\tSeptember , %d",zyear);
            break;
            case 10:printf("\n\n\t\t\t\tOctober , %d",zyear);
            break;
            case 11:printf("\n\n\t\t\t\tNovember , %d",zyear);
            break;
            case 12:printf("\n\n\t\t\t\tDecember , %d",zyear);

    }
     printf("\n\n\t\t\t---------------------------------");



     printMonth(m);

      printf("\n\n\tPress 'n' to Next,Press 'p' to Previous and 'q' to Quit");




      char usr; ///<---THIS IS JUST A QUICK VARIABLE TO PARSE USER_INPUT

      usr=getch();

      if(usr=='n'|| usr=='N')

            increaseM(m);


      if(usr=='p'|| usr=='P')

            decreaseM(m);



      if(usr=='q' || usr=='Q')

      {
          printf("\n\n[?] Are you sure(y/n):");

          usr=getch();
          if(usr=='y' || usr=='Y')
            exit(1);
      }

}


/// /////////////////////////////////////////////////////////////////


void printMonth(int m)
{
    int i;


    printf("\n\t\t\tS");
    gotoxy(4);
    printf("M");
    gotoxy(4);
    printf("T");
    gotoxy(4);
    printf("W");        ///<---AYTO EINAI GIA TIS MERES
                            /// SE GRAMATA///
    gotoxy(4);
    printf("T");
    gotoxy(4);
    printf("F");
    gotoxy(4);
    printf("S\n");






    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)   ///<--- AYTO EINAI GIA TIS MERES AKERAIOI///
    {

        gotoxy(32);
         for(i=1; i<=31; i++)
             {


                if(i<=31)
                {
                    printf(" ");
                    printf(" ");

                }



                if(i<=9)

                    printf("%d",0);





            printf("%d",i);
            gotoxy(1);

                    if(i==5)
                    {
                        printf("\n");
                        gotoxy(22);

                    }

                    if(i==12)
                    {
                        printf("\n");
                        gotoxy(22);
                    }



                    if(i==19)
                    {
                       printf("\n");
                        gotoxy(22);
                    }


                    if(i==26)
                    {
                        printf("\n");
                        gotoxy(22);
                    }


             }

    }


    else if(m==4 || m==6 || m==9 || m==11)
    {
        gotoxy(32);
        for(i=1; i<=30; i++)
         {


            if(i<=30)
            {
                printf(" ");
                printf(" ");

            }



            if(i<=9)

                printf("%d",0);





            printf("%d",i);
            gotoxy(1);

                if(i==5)
                {
                    printf("\n");
                    gotoxy(22);

                }

                if(i==12)
                {
                    printf("\n");
                    gotoxy(22);
                }



                if(i==19)
                {
                   printf("\n");
                    gotoxy(22);
                }


                if(i==26)
                {
                    printf("\n");
                    gotoxy(22);
                }


         }

    }



else
    {
        gotoxy(32);
        for(i=1; i<=29; i++)
         {


            if(i<=29)
            {
                printf(" ");
                printf(" ");

            }


            if(i<=9)

                printf("%d",0);


            printf("%d",i);
            gotoxy(1);

                if(i==5)
                {
                    printf("\n");
                    gotoxy(22);

                }

                if(i==12)
                {
                    printf("\n");
                    gotoxy(22);
                }



                if(i==19)
                {
                   printf("\n");
                    gotoxy(22);
                }


                if(i==26)
                {
                    printf("\n");
                    gotoxy(22);
                }


    }

}




}

///                        INCREASE FUNCTION       //////////////////////////////////


void increaseM(int m,int zyear)
{
    if(m==12)   ///<---CHECKS IF MONTH IS DECEMBER
     {
        m=1;    /// IF M=12 THEN M=1 AND THE YEAR INCREASES PLUS 1
        zyear++;
     }

    else
        m++;

    system("cls");
   printDate(m,zyear);
}


///         END OF INCREASE MONTH FUNCTION  ////////////////////////////



///             DECREASE FUNCTION           ////////////////////////////



void decreaseM(int m,int zyear)
{
    if(m==1)   ///<---CHECKS IF MONTH IS JANUARY
     {
        m=12;    /// IF IT IS THEN M=12 AND YEAR-1
        zyear--;
     }

    else
        m--;

    system("cls");
   printDate(m,zyear);
}








///             END OF DECREASE FUNCTION    ////////////////////////////


///                         HELP FUNCTION           /////////////////////////////////
void help()
{
    printf("This App is Open source so feel free to edit or modify however you want\n");
    printf("\n\t\t\t\tUsage");
    printf("\n\nto use the diary just press 1 and follow on screen instructions");


}





void gotoxy(int x)///<---THIS IS A CUSTOM MADE GOTOXY(NOT THE REAL ONE)
{
    int i;


    for(i=0; i<x; i++)
        printf(" ");

}


