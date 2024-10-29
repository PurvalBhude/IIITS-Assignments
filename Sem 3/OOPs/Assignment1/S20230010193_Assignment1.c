#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    char name[20];
    char employeeID[4];
    float salary;
    int allowance;
};

int main()
{
    struct employee *data = (struct employee *)malloc(10 * sizeof(struct employee));
    int created = 0;
    int input;

    while (1)
    {
        printf("===========================================================\n");
        printf("What operation do you want to perform?\n");
        printf("===========================================================\n");
        printf("1. Create employee\n");
        printf("2. Search using employee ID\n");
        printf("3. Calculate salary (basic + (basic * allowance percentage))\n");
        printf("4. List employees\n");
        printf("Press 0 to exit\n");
        printf("============================================================\n");
        printf("Enter selection: ");
        scanf("%d", &input);
        printf("============================================================\n");

        if (input == 1)
        {
            if (created < 10)
            {
                printf("Enter name: ");
                scanf("%s", data[created].name);
                printf("Enter employeeID: ");
                scanf("%s", data[created].employeeID);
                printf("Enter basic salary: ");
                scanf("%f", &(data[created].salary));
                printf("Enter allowance percentage: ");
                scanf("%d", &(data[created].allowance));
                created++;
            }
            else
            {
                printf("Maximum number of employees reached.\n");
            }
        }
        else if (input == 2)
        {
            printf("Enter employee ID to search: ");
            char id[4];
            scanf("%s", id);
            int found = 0;
            for (int j = 0; j < created; j++)
            {
                if (strcmp(data[j].employeeID, id) == 0)
                {
                    printf("Employee details\n");
                    printf("Name: %s\n", data[j].name);
                    printf("Employee ID: %s\n", data[j].employeeID);
                    printf("Basic salary: %.2f\n", data[j].salary);
                    printf("Allowance percentage: %d\n", data[j].allowance);
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                printf("No such employee ID found\n");
            }
        }
        else if (input == 3)
        {
            printf("Calculating salary\n");
            for (int i = 0; i < created; i++)
            {
                double total = data[i].salary + (data[i].salary * data[i].allowance) / 100;
                printf("\nEmployee ID: %s\n", data[i].employeeID);
                printf("Total salary: %.2f\n", total);
            }
        }
        else if (input == 4)
        {
            printf("List of all employees\n");
            for (int i = 0; i < created; i++)
            {
                printf("\nEmployee %d\n", i + 1);
                printf("Name: %s\n", data[i].name);
                printf("Employee ID: %s\n", data[i].employeeID);
                printf("Basic salary: %.2f\n", data[i].salary);
                printf("Allowance percentage: %d\n", data[i].allowance);
            }
        }
        else if (input == 0)
        {
            break;
        }
        else
        {
            printf("Invalid selection. Please try again.\n");
        }
    }

    free(data);
    return 0;
}