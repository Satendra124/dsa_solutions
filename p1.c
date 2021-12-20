#include <stdio.h>



struct Employee
{
    char name[30];
    int age;
    int salary;
    char position[1000];
};

void printData(struct Employee employeeData[],int no){
    for (int i = 0; i < no; i++)
    {
        printf("Name of Employee %d: %s",i+1,employeeData[i].name);
        printf("\n");
        printf("Age of Employee %d: %d",i+1,employeeData[i].age);
        printf("\n");
        printf("Salary of Employee %d: %d",i+1,employeeData[i].salary);
        printf("\n");
        printf("Position of Employee %d: %s",i+1,employeeData[i].position);
        printf("\n");
    }
    
}

int main()
{
    int n;
    printf("Number of Employee: ");
    scanf("%d",&n);
    printf("\n");
    struct Employee employeeData[n];
    for (int i = 0; i < n; i++)
    {
        struct Employee employee;
        printf("Name of Employee %d: ",i+1);
        scanf("%s",employee.name);
        printf("\n");
        printf("Age of Employee %d: ",i+1);
        scanf("%d",&employee.age);
        printf("\n");
        printf("Salary of Employee %d: ",i+1);
        scanf("%d",&employee.salary);
        printf("\n");
        printf("Position of Employee %d: ",i+1);
        scanf("%s",employee.position);
        printf("\n");
        employeeData[i] = employee;
    }
    printData(employeeData,n);
    while (1)
    {
        int input;
        printf("1:Change Employee Data\n 2:EXIT \n");
        scanf("%d",&input);
        printf("\n");
        if(input==2) break;
        else if(input==1){
            printf("ID of Employee: ");
            int id;
            scanf("%d",&id);
            printf("\n");
            printf("Name of Employee %d: ",id);
            scanf("%s",employeeData[id-1].name);
            printf("\n");
            printf("Age of Employee %d: ",id);
            scanf("%d",&employeeData[id-1].age);
            printf("\n");
            printf("Salary of Employee %d: ",id);
            scanf("%d",&employeeData[id-1].salary);
            printf("\n");
            printf("Position of Employee %d: ",id);
            scanf("%s",employeeData[id-1].position);
            printf("\n");
            printData(employeeData,n);

        }else{
            printf("INVALID!\n");
        }
    }
    

}