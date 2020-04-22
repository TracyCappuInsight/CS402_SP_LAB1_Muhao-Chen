#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Input your file name(.txt) ..\n");
		return 0;
	}
	char *file_name = argv[1], name[RANGE_NAME], last_name[RANGE_NAME];//file_name get
	struct person employee[RANGE_EMP];//creat a struct_person and limit the space_Range_emp
	int option, employ_id, key, salary, confirm;//define the keys
	int n_emp = 0, list[RANGE_EMP];
	if (open_file(file_name) == -1) {//open the file
		printf("error reading file\n");
		return -1;
	}
	FILE *fp = fopen(file_name, "r");
	while (!feof(fp)) {//circulate the content and give to the list
		fscanf(fp, "%d %s %s %d\n", &employee[n_emp].id, &employee[n_emp].name, &employee[n_emp].last_name, &employee[n_emp].salary);
		list[n_emp] = employee[n_emp].id;
		n_emp++;
	}
	qsort(employee,n_emp,sizeof(struct person),ID_cpmpare);//set the order:small to big
	fclose(fp);
	while (1) {//print the info of options
		printf("*************************\n");
		printf("DB of Employee:\n");
		printf("*************************\n");
		printf("[1]Show DataBase\n");
		printf("[2]Look_up by ID\n");
		printf("[3]Look_up by Last Name \n");
		printf("[4]Add an Employee's info \n");
		printf("[5]Quit\n");
		printf("[6]Remove a Employee\n");
		printf("[7]Update a Employee\n");
		printf("[8]Show some toppest-salary employees\n");
		printf("[9]Look_up all employees by Last Name\n");
		printf("*************************\n");
		printf("Enter Your Option: \n");
		scanf("%d", &option);
		if (option == 1) {
			printf("------------------------------------------\n");
			printf("Name                       Salary    ID \n");
			printf("------------------------------------------\n");
			for (int i = 0; i < n_emp; i++) {//circulate the list for every employee
				printf("%-10s %-10s %10d %10d\n", employee[i].name, employee[i].last_name, employee[i].salary, employee[i].id);
			}
			printf("------------------------------------------\n");
		}
		else if (option == 2) {
            printf("enter a 6-digit employee id: \n");
            read_int(&employ_id);
			int list1[RANGE_EMP];
			for(int i = 0; i <n_emp; i++){
				list1[i] = employee[i].id;
			}
            key = binary_search(list1, 0 , n_emp, employ_id);//binary search to the key,o(n/2)
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
            key = Last_name(employee,n_emp,last_name);//search one by one to the key
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
                if((salary>=30000)&&(salary<=150000)){//judge the right content and put it into the struct
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
		else if (option == 6) {
			printf("enter employee's ID: \n");
            read_int(&employ_id);
			qsort(employee,n_emp,sizeof(struct person),ID_cpmpare);//set the order:small to big
			int list1[RANGE_EMP];
			for(int i = 0; i <n_emp; i++){
				list1[i] = employee[i].id;
			}
			key = binary_search(list1, 0 , n_emp, employ_id);//binary search to the key,o(n/2)
			if(key == -1){
                printf("employee with id %d not found \n",employ_id);
            }
            else {
                Key_tostring(employee,key);
				printf("Are you sure to delete this employee(1foryes/0forno): \n");
				scanf("%d\n",&confirm);
				if(confirm == 1){
					for (int i = 0; i < n_emp-1; i++){
							if (i >= key){
								employee[i] = employee[i + 1];
							}
					}
					n_emp--;
				}
			}
		}

		else if (option == 7) {
			printf("Enter the employee id:\n");
			read_int(&employ_id);
			qsort(employee,n_emp,sizeof(struct person),ID_cpmpare);//set the order:small to big
			int list1[RANGE_EMP];
			for(int i = 0; i <n_emp; i++){
				list1[i] = employee[i].id;
			}			
			key = binary_search(list1,0,n_emp,employ_id);//Find the key,by Id
			if(key == -1){
				printf("employee with id %d not found \n",employ_id);
			}
			else{
				Key_tostring(employee,key);
				printf("enter employee's first name: \n");
				read_string(&name);
				printf("enter employee's last name: \n");
				read_string(&last_name);
				printf("enter employee's ID: \n");
				read_int(&employ_id);
				printf("enter employee's salary: \n");
				read_int(&salary);
				printf("Confirm the info of this employee \n");
				printf("%s %s,salary: %d , id : %d \n",name,last_name,salary,employ_id);
				printf("Are you sure to update: choose(1foryes/0forno):\n");
				scanf("%d\n",&confirm);
			}
			if(confirm ==1){
					strcpy(employee[key].name,name);
					strcpy(employee[key].last_name,last_name);
					employee[key].id = employ_id;
					employee[key].salary = salary;
					qsort(employee,n_emp,sizeof(struct person),ID_cpmpare);//set the order:small to big
					printf("Have updated!\n");
					Key_tostring(employee,key);
			}
		}
		else if (option == 8) {
			printf("How many topest salary do you want to know? \n");
			int M;
			read_int(&M);
			//create a new structure to store the data
			struct person temp[RANGE_EMP];
			struct person Top_employee[RANGE_EMP];
			int temp_0 = n_emp;
			//create a new structure of previous value
			for(int i = 0; i<n_emp;i++){
					strcpy(temp[i].name,employee[i].name);
					strcpy(temp[i].last_name,employee[i].last_name);
					temp[i].id = employee[i].id;
					temp[i].salary = employee[i].salary;
			}
			//Find the toppest M and store
			for(int i = 0; i<M; i++){
				// get the number/index of the toppest salary
				int Toppest = Top_salary_num(temp,temp_0);
				strcpy(Top_employee[i].name,temp[Toppest].name);
				strcpy(Top_employee[i].last_name,temp[Toppest].last_name);
				Top_employee[i].id = temp[Toppest].id;
				Top_employee[i].salary = temp[Toppest].salary;
				//delet the toppest and find second topperst
				delet_(Toppest,temp,temp_0);
				temp_0--;
			}
			for (int i = 0; i < M; i++) {//circulate the list for employee
				printf("%-10s %-10s %10d %10d\n", Top_employee[i].name, Top_employee[i].last_name, Top_employee[i].salary, Top_employee[i].id);
			}
		}
		else if (option == 9) {
			printf("Enter the Last name of the employee:\n");
			read_string(last_name);
			int found = Last_name(employee,n_emp,last_name);
			if(found == -1){
				printf("Sorry, could not find!\n");
			}
			else{
			printf("------------------------------------------\n");
			printf("Name                       Salary    ID \n");
			printf("------------------------------------------\n");
			for (int i = 0; i < n_emp; i++) {//circulate the list for every employee
				if(strcasecmp(employee[i].last_name,last_name)==0){
				printf("%-10s %-10s %10d %10d\n", employee[i].name, employee[i].last_name, employee[i].salary, employee[i].id);}
			}
			printf("------------------------------------------\n");
			}
		}

		else {
			printf("Sorry,illegal input! Please Try again. \n");
			continue;
		}
	}
}
