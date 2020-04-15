#define RANGE_NAME 64
#define RANGE_EMP 1024

struct person {
	char name[RANGE_NAME], last_name[RANGE_NAME];
	int id, salary;
};

int open_file(char *file_name) {
	if (fopen(file_name, "r") == NULL)
		return -1;
	return 0;
}

int ID_cpmpare (const void *a, const void *b)
{
        struct person *c = (struct person*) a;
        struct person *d = (struct person*) b;
        return c->id - d->id;
}

int read_string(char *address) {
	if (scanf("%s", address) == 0)
		return -1;
	return 0;
}

int read_int(int *address) {
	if (scanf("%d", address) == 0)
		return -1;
	return 0;
}

int read_float(float *address) {
	if (scanf("%f", address) == 0)
		return -1;
	return 0;
}

void close_file(FILE *file_name) {
	fclose(file_name);
}

void Key_tostring(struct person employee[RANGE_NAME], int key){
	printf("------------------------------------------\n");
	printf("Name                       Salary    ID \n");
    printf("%-10s %-10s %10d %10d\n", employee[key].name, employee[key].last_name, employee[key].salary, employee[key].id);
    printf("------------------------------------------\n");
}


int binary_search(const int arr[],int l, int r, int x){
    if(r >=l ){
        int mid = l + (r - l)/2;
        // Find the mid_element and judge
        if(arr[mid] == x)
            return mid;
        if(arr[mid] > x)// if smaller, find 1 to mid-1
            return binary_search(arr,l,mid-1,x);
        // if bigger, find mid+1 to r
        return binary_search(arr, mid+1 , r , x);
    }
    return -1;
}

int Last_name(struct person employee[RANGE_NAME],int n_empy,char last_name[]){
    for(int i =0; i<n_empy;i++){
        if(strcmp(employee[i].last_name,last_name)==0){
            return i;
        }
    }
    return -1;
}
