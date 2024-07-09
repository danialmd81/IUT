/*

 FirstName:Danial

 LastName:Mobini

 StudentNumber: 40130023

*/

enum level
{
    junior,
    midlevel,
    senior
};

typedef struct employee
{
    char name[20];
    char fname[30];
    char mcode[11];
    char birthda[11];
    int salary;
    int hour;
    enum level level;
    int bonus;
    int finalsalry;

} employee;