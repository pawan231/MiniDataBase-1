#include "declaration.h"

void drop(){
	char *tab;
	char *temp;
	char *temp1;
	temp1=(char*)malloc(sizeof(char)*MAX_NAME);
	temp=(char*)malloc(sizeof(char)*MAX_NAME);
	tab=(char*)malloc(sizeof(char)*MAX_NAME);
	cout<<"enter table name to delete::\n";
	cin>>tab;
	strcpy(temp1,tab);
	int check=search_table(tab);
	if(check==0) printf("%s doesn't exist\n\n",tab);
	else if(check==1){
		sprintf(temp, "rm -R ./table/%s", tab);
		system(temp);
		sprintf(temp, "grep -v \"%s\" ./table/table_list > ./table/temp ; mv ./table/temp ./table/table_list", tab);
        system(temp);
        printf("%s deleted\n\n",temp1);
	}
	//free(tab);
	//free(temp);
}
