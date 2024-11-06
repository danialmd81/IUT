/*

 FirstName:Danial

 LastName:Mobini

 StudentNumber: 40130023

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

int main()
{
    int enter;
    while (1)
    {
        printf("1.Add a New Employee\n");
        printf("2.Delete An Employee\n");
        printf("3.Display Employee's Information\n");
        printf("4.Change The Employee's Salary\n");
        printf("5.Change The Employee's Level\n");
        printf("6.Display Information Of All Employees\n");
        scanf("%d", &enter);
        system("cls");
        if (enter == 1)
        {
            int e1;
            printf("Where Do You Want To Add a New Employee?\n");
            printf("1.Front\n");
            printf("2.Back\n");
            scanf("%d", &e1);
            system("cls");
            if (e1 == 1)
            {
                employee data;
                printf("Name:");
                scanf("%s", data.name);
                printf("Last Name:");
                scanf("%s", data.fname);
                printf("ID Code:");
                scanf("%s", data.mcode);
                printf("Birth Date:");
                scanf("%s", data.birthda);
                printf("Salary:");
                scanf("%d", &data.salary);
                printf("Hour:");
                scanf("%d", &data.hour);
                char level[20];
                printf("Level:");
                scanf("%s", level);
                if (strcmp(level, "junior") == 0)
                    data.level = 0;
                if (strcmp(level, "midlevel") == 0)
                    data.level = 1;
                if (strcmp(level, "senior") == 0)
                    data.level = 2;
                printf("Bonus:");
                scanf("%d", &data.bonus);
                data.finalsalry = data.salary * data.hour * data.bonus;
                push_front(data);
            }
            if (e1 == 2)
            {
                employee data;
                printf("Name:");
                scanf("%s", data.name);
                printf("Last Name:");
                scanf("%s", data.fname);
                printf("ID Code:");
                scanf("%s", data.mcode);
                printf("Birth Date:");
                scanf("%s", data.birthda);
                printf("Salary:");
                scanf("%d", &data.salary);
                printf("Hour:");
                scanf("%d", &data.hour);
                char level[20];
                printf("Level:");
                scanf("%s", level);
                if (strcmp(level, "junior") == 0)
                    data.level = 0;
                if (strcmp(level, "midlevel") == 0)
                    data.level = 1;
                if (strcmp(level, "senior") == 0)
                    data.level = 2;
                printf("Bonus:");
                scanf("%d", &data.bonus);
                data.finalsalry = data.salary * data.hour * data.bonus;
                push_back(data);
            }
        }

        else if (enter == 2)
        {
            char mcode[11];
            printf("ID Code:");
            scanf("%s", mcode);
            delet(mcode);
        }

        else if (enter == 3)
        {
            char mcode[11];
            printf("ID Code:");
            scanf("%s", mcode);
            display(mcode);
        }

        else if (enter == 4)
        {
            char mcode[11];
            int newsalary;
            printf("ID Code:");
            scanf("%s", mcode);
            printf("New Salary");
            scanf("%d", &newsalary);
            changesalary(mcode, newsalary);
        }

        else if (enter == 5)
        {
            char mcode[11];
            char level[20];
            printf("ID Code:");
            scanf("%s", mcode);
            printf("Level:");
            scanf("%s", level);
            if (strcmp(level, "junior") == 0)
                changelevel(mcode, 0);
            if (strcmp(level, "midlevel") == 0)
                changelevel(mcode, 1);
            if (strcmp(level, "senior") == 0)
                changelevel(mcode, 2);
        }
        else if (enter == 6)
        {
            print();
        }
        system("pause");
        system("cls");
    }
}