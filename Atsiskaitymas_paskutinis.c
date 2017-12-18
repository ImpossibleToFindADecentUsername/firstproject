#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR 1000



//***************STUDENT STRUCT**************************

    struct mok {
        char name[20];
        int bioGrade;
        int mathGrade;
        int proGrade;
    } Mokinys[10];

//*******************INFO ABOUT STUDENTS || READING\WRITING TO\FROM FILE(StudentInfo.txt)*********************

int mokInfo() {

    FILE *f = fopen("StudentInfo.txt", "a");
    if(f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    char str [MAXCHAR];
    int *ip;
    int i, j, a=1, b, c=0;
    ip = &j;

    while(a==1) {
        printf("Hey there! How many students you would like to add?\n");
        scanf("%d", &j);
        system("cls");
        for(i=1;i<j+1;i++) {
            printf("What is your name?\n");
            scanf("%s", &Mokinys[i].name);
            system("cls");
            printf("What is your Biology grade?\n");
            scanf("%d", &Mokinys[i].bioGrade);
            system("cls");
            printf("What is your Math grade?\n");
            scanf("%d", &Mokinys[i].mathGrade);
            system("cls");
            printf("What is your Programming grade?\n");
            scanf("%d", &Mokinys[i].proGrade);
            system("cls");
            fprintf(f,"|| Name of the student: %s || Biology grade: %d || Math grade: %d || Programming grade: %d ||\n", Mokinys[i].name, Mokinys[i].bioGrade, Mokinys[i].mathGrade, Mokinys[i].proGrade);
        }
        fclose(f);

        printf("Would You like to retry?\n1 - Yes\n2 - No\n\n");
        scanf("%d",&a);
        system("cls");
    }

    f = fopen("StudentInfo.txt", "r");
            if(f == NULL)
            {
            printf("Error opening file!\n");
            exit(1);
            }

    printf("Would You like to see the whole list of students?\n1 - Yes\n2 - No\n\n");
    scanf("%d",&b);

    switch(b) {
        case 1:
            system("cls");
            while(fgets(str,MAXCHAR, f) != NULL)
            printf("%s\n", str);
            fclose(f);
            break;
        case 2: break;
}


}

//****************FORMULA FOR AVERAGE**************************

int average(int a, int b, int c) {
    int v;
    v = (a + b + c)/3;
    return v;
}

//****************USER INTERFACE/MAIN MENU******************


int UI() {
    int i, choice, k = 1;
    int *ip;

    system("pause");
    system("cls");
    printf("What is your ID number?\n\n");
    for(i=1; i<ip ; i++) {
        printf("%d - %s.   ", i, Mokinys[i].name);
    }
    printf("\n");
    scanf("\n%d", &i);
    system("cls");

    printf("Hello, %s!\n", Mokinys[i].name);
    while(k==1){
    printf("\nWhat would you like to do?(Choose options by pressing corresponding numbers.)\n**************************************\n1 - to see your biology result\n2 - to see math result.\n3 - to see programming result.\n4 - to know the average of all.\n\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1: printf("\nYour biology grade is %d\n", Mokinys[i].bioGrade);
                break;
        case 2: printf("\nYour math grade is %d\n", Mokinys[i].mathGrade);
                break;
        case 3: printf("\nYour programming grade is %d\n", Mokinys[i].proGrade);
                break;
        case 4: printf("\nYour average grade is:%d\n",average(Mokinys[i].bioGrade,Mokinys[i].mathGrade,Mokinys[i].proGrade));
                break;
        default: printf("\n<<<Incorrect choice>>>\n");
    }
        printf("\nWould You like to continue?\n 1 - Yes.\n 2 - No.\n\n");
        scanf("%d", &k);
     switch(k) {
        case 1: k = 1;
            break;
        case 2: k = 5;
            break;
        default: printf("<<<WRONG CHOICE>>>");
     }
        system("cls");
    }
}

//**********************MAIN***********************

int main() {

    mokInfo();
    UI();
}

