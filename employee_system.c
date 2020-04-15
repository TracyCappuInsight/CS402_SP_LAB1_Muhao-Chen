#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Input your file name(.txt) ..\n");
		return 0;
	}
	char *file_name = argv[1], name[RANGE_NAME], last_name[RANGE_NAME];
	struct person employee[RANGE_EMP];
	int option, employ_id, key, salary, confirm;
	int n_emp = 0, list[RANGE_EMP];
	if (open_file(file_name) == -1) {
		printf("error reading file\n");
		return -1;
	}
	FILE *fp = fopen(file_name, "r");
	while (!feof(fp)) {
		fscanf(fp, "%d %s %s %d\n", &employee[n_emp].id, &employee[n_emp].name, &employee[n_emp].last_name, &employee[n_emp].salary);
		list[n_emp] = employee[n_emp].id;
		n_emp++;
	}
	qsort(employee,n_emp,sizeof(struct person),ID_cpmpare);
	fclose(fp);
	while (1) {
		printf("*************************\n");
		printf("DB of Employee:\n");
		printf("*************************\n");
		printf("[1]Show DataBase\n");
		printf("[2]Look_up by ID\n");
		printf("[3]Look_up by Last Name \n");
		printf("[4]Add an Employee's info \n");
		printf("[5]Quit\n");
		printf("*************************\n");
		printf("Enter Your Option: \n");
		scanf("%d", &option);
		if (option == 1) {
			printf("------------------------------------------\n");
			printf("Name                       Salary    ID \n");
			printf("------------------------------------------\n");
			for (int i = 0; i < n_emp; i++) {
				printf("%-10s %-10s %10d %10d\n", employee[i].name, employee[i].last_name, employee[i].salary, employee[i].id);
			}
			printf("------------------------------------------\n");
		}
		else if (option == 2) {
            printf("enter a 6-digit employee id: \n");
            read_int(&employ_id);
            key = binary_search(list, 0 , n_emp, employ_id);
            if(key == -1){
                printf("employee with id %d not found \n",employ_id);
            }
            else {
                Key_tostring(employee,key);
			}
		}
		else if (option == 3) {
            printf("enter employee's last_name: \n");
            read_string(&last_name);
            key = Last_name(employee,n_emp,last_name);
            if(key == -1){
                printf("employee with name %s not found \n",last_name);
            }
            else{
                Key_tostring(employee,key);
			}
		}
		else if (option == 4) {
            printf("enter employee's first name: \n");
            read_string(&name);
            printf("enter employee's last name: \n");
            read_string(&last_name);
			printf("enter employee's ID: \n");
			read_int(&employ_id);
            printf("enter employee's salary: \n");
            read_int(&salary);
            printf("Confirm the info of this employee \n");
            printf("choose(1foryes/0forno)\n");
            scanf("%d\n",&confirm);
            if(confirm == 1){
                if((salary>=30000)&&(salary<=150000)){
					strcpy(employee[n_emp].name,name);
					strcpy(employee[n_emp].last_name,last_name);
					employee[n_emp].id = employ_id;
					employee[n_emp].salary = salary;
                    n_emp++;
					qsort(employee,n_emp,sizeof(struct person),ID_cpmpare);
                }
                else{
                    printf("Error: false salary!");
                }
            }
            else{
                printf("Sorry, you cancel this ADD_action.");
            }
		}
		else if (option == 5) {
			printf("Finshed! \n");
			break;
		}
		else {
			printf("Sorry,illegal input! Please Try again. \n");
			continue;
		}
	}
}
