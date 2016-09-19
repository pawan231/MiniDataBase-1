#include "declaration.h"
#include "file_handler.h"

int record_size(table *temp){
	int size=0;
	temp->prefix[0]=0;
	for(int i=0;i<temp->count;i++){
		switch(temp->col[i].type){
		case INT:
			temp->prefix[i+1]=sizeof(int)+temp->prefix[i];
			size+=sizeof(int);
			break;
		case VARCHAR:
			temp->prefix[i+1]=sizeof(char)*(MAX_VARCHAR +1) +temp->prefix[i];
			size+=sizeof(char)*(MAX_VARCHAR +1);
			break;
		}
	}
	return size;
}
table * create_table(char name[],int count){
	table *temp=new table();
	temp->fp=NULL;
	temp->blockbuf=NULL;
	strcpy(temp->name,name);
	temp->name[strlen(name)]='\0';
	temp->count=count;
	temp->rec_count=0;
	temp->data_size=0;

	//enter the data
	cout<<"enter column name,data type(1.int 2.varchar) and max size\n";
	for(int i=0;i<count;i++){
		cin>>temp->col[i].col_name>>temp->col[i].type>>temp->col[i].size;
	}


	return temp;
}

void create(){
	char name[20];
	int count;
	cout<<"enter table name\n";
	cin>>name;

	//check if table name tab_name already exists in the table_list file;
	//if not exists then create new;
	cout<<"enter no. of columns\n";
	cin>>count;


	//check if new table already exists in table list or not
	FILE *fp=fopen("./table/table_list","r+");
	if(fp==NULL) cout<<"hello";
	char tab_name[20];
	while(fscanf(fp,"%s",tab_name)!=EOF){
		if(strcmp(tab_name,name)==0){
			cout<<"error\ntable name already exists\n";
			return;
		}
	}
	fseek(fp,0,SEEK_END);
	fprintf(fp,"%s\n",name);
	//BPtree temp_bp(name);
	fclose(fp);

	//enter table details if not exist


	table *temp;
	temp=create_table(name,count);
	//calculate the size of the block
		temp->size=record_size(temp);
		if(temp!=NULL){
		setup_files(temp,1);
		fclose(temp->fp);
		temp->blockbuf = malloc(temp->BLOCKSIZE);
        fp  = open_file(temp->name, 2, const_cast<char*>("w"));
        fwrite(temp->blockbuf, 1, temp->BLOCKSIZE, fp);
        fclose(fp);
        write_struct(temp);
        free(temp->blockbuf);
		free(temp);
			        //return 0;
	}
		else
		 {
		      printf("create_table inside CREATE function returned NULL\n");
		       // return 1;
		 }

}
