#include "declaration.h"

FILE *open_file(char t_name[], int option, char perm[]){

    FILE *fp;
    struct stat st = {0};
    char *name = (char *)malloc(sizeof(char) * (2 * MAX_NAME + 15));
       strcpy(name, "./table/");

    if (stat(name, &st) == -1)
        mkdir(name, 0775);

    strcat(name, t_name);
    strcat(name, "/");

    if (stat(name, &st) == -1)
        mkdir(name, 0775);

    switch(option){
        // met
        case 1:
        	strcat(name, "met");
        	//printf("Opening file: %s %d %s %d\n", name, option, perm, is_temp);
        	fp = fopen(name, perm);
        	break;

        // ret
        case 2:
        	strcat(name, "rec");
        	//cout<<name<<"  rec\n";
        	//printf("Opening file: %s %d %s %d\n", name, option, perm, is_temp);
        	fp = fopen(name, perm);
        	break;

        //printf("Open file called with wrong option\n");

    }
    if (!fp)
    {
       // printf("Error in opening file: %s %d %s %d\n", name, option, perm, is_temp);
    }
    free(name);
    return fp;
}
void setup_files(struct table *t_ptr, int is_new)
{
    //printf("Inside setup_files\n");
    FILE *fp, *fpt;

    if (is_new)
        fp = open_file(t_ptr->name, 2, const_cast<char*>("w+"));
    else
        fp = open_file(t_ptr->name, 2, const_cast<char*>("r+"));

    if (!t_ptr->is_temp){
        if (is_new)
            fpt = open_file(t_ptr->name, 1, const_cast<char*>("w+"));
        else
            fpt = open_file(t_ptr->name, 1, const_cast<char*>("r+"));

        if (!fpt){
            printf("Error opening met file\n");
        }
        else
            fclose(fpt);
    }
    if (!fp){
        printf("Error opening rec file\n");
    }
    t_ptr->fp = fp;
    //printf("Done in setup_files\n");
}


int write_struct(struct table *t_ptr)
{
    FILE *fp = open_file(t_ptr->name, 1, const_cast<char*>("w"));
    fwrite(t_ptr, sizeof(struct table), 1, fp);
    fclose(fp);
    //printf("Struct updated\n");
    return 0;
}
