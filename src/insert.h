#include "declaration.h"
//#include "file_handler.h"
//#include "BPtree.h"

int search_table(char tab_name[]){
	//check if new table already exists in table list or not
	//cout<<"inside search1\n";
	//char name[MAX_NAME +1];
		//FILE *fp=fopen("./table/table_list","r+");
		//string temp=tab_name;
		/*
		while(fscanf(fp,"%s",name)!=EOF){
			if(strcmp(tab_name,name)==0){
				cout<<tab_name<<" TABLE EXISTS\n";
				return 1;
			}
		}*/
		//use grep to search table_name string inside table_list
		// -F -> --fixed-strings ;intepret pattern as a list of fixed strings
		// -x -> --line-regexp ;select only those matches that exactly match the whole line
		// -q -> quite, --silent ;write anything to standard output, exit immediately with zero status if any match is found
		char str[MAX_NAME+1];
		strcpy(str,"grep -Fxq ");
		strcat(str,tab_name);
		strcat(str," ./table/table_list");
		int x = system(str);
		if(x==0)return 1;
		else return 0;
	return 0;
}

void insert_command(char tname[],void *data[],int len,int total,void *data1[]){
	table *temp;
	//cout<<"inside insert command\n";
	int ret;
	BPtree obj(tname);
	//open meta data
	FILE *fp=open_file(tname,const_cast<char*>("r"));
	//if(fp!=NULL) cout<<"nunn\n";
	temp=(table*)malloc(sizeof(table));
	fread(temp,sizeof(table),1,fp);
	//cout<<temp->rec_count<<"\n";

	//insert into table and write to btree file nodes
	ret=obj.insert_record(*((int *)data[0]),temp->rec_count);
	if(ret==2){
		cout<<"key already exists\n";
		cout<<"exiting...\n";
		return ;
	}

	//if no error occurred during insertion of key
	//write the data to file;
	//update the meta data;
	fp=open_file(tname,const_cast<char*>("w+"));
	int file_num=temp->rec_count;
	temp->rec_count=temp->rec_count+1;
	temp->data_size=total;
	fwrite(temp,sizeof(table),1,fp);
	fclose(fp);

	//update the particular entry of inserted data to file;
	char *str;
	str=(char *)malloc(sizeof(char)*MAX_PATH);
	sprintf(str,"table/%s/file%d.dat",tname,file_num);
	//cout<<str<<endl;
	FILE *fpr=fopen(str,"w+");
    int x;
	char y[MAX_NAME];
	for(int j=0;j<temp->count;j++){
		if(temp->col[j].type==INT){
			 x = *(int *)data[j];
			 //x=10;
			fwrite(&x,sizeof(int),1,fpr);
		}
		else if(temp->col[j].type==VARCHAR){

			strcpy(y,(char *)data[j]);
			//cout<<y;
			fwrite(y,sizeof(char)*MAX_NAME,1,fpr);
		}
	}


	//fwrite(data,total,1,fpr);
	fclose(fpr);
	/*
	fp=fopen(str,"r");
	int c;
	char d[MAX_NAME];
	for(int j=0;j<temp->count;j++){
		if(temp->col[j].type==INT){
			fread(&c,1,sizeof(int),fpr);
			cout<<c<<"\t";
		}
		else if(temp->col[j].type==VARCHAR){
			fread(d,1,sizeof(char)*MAX_NAME,fpr);
			cout<<d<<"\t";
		}
	}
	*/
	/*char *str;
	str=(char*)malloc(sizeof(char)*MAX_PATH);
	sprintf(str,"table/%s/file%d.dat",tname,temp->rec_count);
	ofstream outfile(str,ofstream::out|ofstream::binary);

	for(int i=0;i<temp->count;i++)
	{



		if(temp->col[i].type==INT)
		{
			int x=*(int *)data[i];
			outfile.write((char *)(&x),sizeof(x));
		}
		else if(temp->col[i].type==VARCHAR)
		{
			outfile.write((char*)(data[i]),sizeof(char)*len);
		}
	}
	outfile.close();
	char *str1;
	int id1;
	char name[10];
	str1=(char *)malloc(sizeof(char)*MAX_PATH);
	for(int i=0;i<temp->count+1;i++)
	{
		sprintf(str1,"table/%s/file%d.dat",tname,i);
		cout<<"file name "<<str1<<endl;
		ifstream infile(str1,ifstream::in | ifstream::binary);
		infile>>id1>>name;
		cout<<id1<<" "<<name<<endl;
		infile.close();

	}




	fpr=fopen(str,"r");

	//cout<<*(int *)data1[0]<<" ";
	fread(data1,temp->count,sizeof(data),fpr);
	for(int i=0;i<temp->count;i++)
	{

			if(temp->col[i].type==INT)
			{
				cout<<*(int *)data1[i]<<" ";
							}
			else if(temp->col[i].type==VARCHAR)
			{
				cout<<(char *)data1[i]<<" ";
			}
	}
    cout<<endl;
	//fclose(fp);*/
	//fclose(fpr);
	free(str);
	free(temp);

}


void insert(){
	char *tab;
	tab=(char*)malloc(sizeof(char)*MAX_PATH+1);
	cout<<"enter table name: ";
	cin>>tab;
	int check=search_table(tab);
	if(check==0){
		printf("Table %s not exists\n",tab);
		return ;
	}

	else{
		cout<<"Table exists enter data\n\n";
		char dir[100];
		strcpy(dir,"./table/");
		strcat(dir,tab);
		strcat(dir,"/met");
		//cout<<dir<<endl;
     	table inp1;
		int count;
		FILE *fp = open_file(tab, const_cast<char*>("r"));
		int i=0;
		while(fread(&inp1,sizeof(table),1,fp)){
			printf("\n------------------------------------\n");
			cout<<"\ninsert the following details ::\n";
			printf("\n------------------------------------\n");
			//cout<<inp1.count<<"\n";
			count=inp1.count;
			for(i=0;i<inp1.count;i++){
				cout<<inp1.col[i].col_name<<"("<<inp1.col[i].type<<"),size:"<<inp1.col[i].size;
				cout<<"\t";
			}
		}
		printf("\n------------------------------------\n");
		//enter data;
		int x;
		char var[MAX_NAME+1];
		//open file .rec and write data to it
		void * data[MAX_ATTR];
		void *data1[MAX_ATTR];
		//int col[MAX_ATTR];
		//col_details inp;
		//int y=&x;

		//input data for the table of desired datatype 1.int 2.varchar;
		int size=0;
		int total=0;
		for(int i=0;i<count;i++){
			//cout<<(char *)data[1]<<endl;
		if(inp1.col[i].type==INT){
			data[i] =(int*) malloc(sizeof(int));
			data1[i] =(int*) malloc(sizeof(int));
			total+=sizeof(int);
			//col[i]=1;
			//cout<<"above *X\n";
			int flag=1;
			while(flag){
			cin>>(x);
			//check the digit count of entered no.
			int temp=x;
			int digit=0;
			while(temp){
				temp=temp/10;
				digit++;
			}
			if(digit>inp1.col[i].size){
				cout<<"error\nEntered no. has greater size than specified\n";
			}
			else flag=0;
			}
			*((int*)data[i])=x;
			//cout<<"interger input\n";
			size++;
		}
		else if(inp1.col[i].type==VARCHAR){
			//cout<<"inside varchar\n";
			data[i] = malloc(sizeof(char) * (MAX_NAME + 1));
			data1[i] = malloc(sizeof(char) * (MAX_NAME + 1));
			int flag=1;
			while(flag){
			cin>>var;
			//col[i]=2;
			total+=sizeof(char) * (MAX_NAME + 1);
			if(strlen(var)>(unsigned int)inp1.col[i].size){
				cout<<"error\nEntered size of string is greater than specified \n";
			}
			else flag=0;
			}
			strcpy((char*)(data[i]),var);
			//cout<<(char *)data[1]<<endl;
			size++;
		}
	}
		/*
		//cout<<"hello mandeep1\n";
		//cout<<(char*)(data[1])<<" ";
		//check if data is inserted
		for(int i=0;i<size;i++){
			if(inp1.col[i].type==1){
				cout<<*((int*)(data[i]))<<" ";
				cout<<"int\n";
			}
			else if(inp1.col[i].type==2){
				cout<<(char*)(data[i])<<" ";
				cout<<"char\n";
			}
		}
		*/
		insert_command(tab,data,strlen(var),total,data1);
	}
	free(tab);
}
