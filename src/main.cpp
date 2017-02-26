//============================================================================
// Name        : myDB.cpp
// Author      : mandeep singh,pawan sheoran
// Version     :
// Copyright   : Your copyright notice
// Description : mini database engine
//============================================================================

#include "declaration.h"
#include "BPtree.h"
#include "create.h"
#include "insert.h"
#include "display.h"
#include "search.h"
#include "drop.h"

using namespace std;

void help(){
	printf("\n\n\nWELCOME TO THE myDB\n\n"
			"myDB is a simple database design engine in which you can implement basic queries.\n\nQUERIES SUPPORTED ARE::"
			"\n1.create a new table\n2.insert data into existing table\n3.drop table\n4.search in the table\n\n"
			"1.For creating table \na>enter the table name\nb>enter no. of columns\nc>enter col name,datatype(1.INT\t2.VARCHAR"
			") and maximum size for it.\n"
			"\n2.For inserting data into table\na>enter table name\nb>it will display how many details to be filled\nc>"
			"enter all the details\nd>your data is inserted into the table\n\n"
			"3.For deleting table just enter the table name\n\n"
			"4.For search into table \na>you can search for a particular table if it exists or not\nb>"
			"b>You can search for a particular entry if it exists in the table or not\n"
			"c>For particular entry searching , search is based on primary key, so enter col[0] value of table to search\n\n"
			"---------------------------------------------------------------------------------------------------"
			"\n\t\t\tdesigned by:: \n\n\t\t\tMANDEEP SINGH\n\t\t\tPAWAN SHEORAN\n\n"
			"---------------------------------------------------------------------------------------------------");
}

//take input string from user
void input(){
	//vector<pair<string,int> > query;
	//query.pb(make_pair("create table",1));

	int c=0;;
	printf("\n select the query to implement\n");
	printf("\n1.show all tables in database\n2.create table\n3.insert into table\n4.drop table\n5.describe table\n6.search table or search inside table\n7.help\n8.quit\n\n");
	scanf("%d",&c);
	while(c<9 && c>0){
		switch(c){
			case 1:
				show_tables();
				break;
			case 2:
				create();
				break;
			case 3:
				insert();
				break;
			case 4:
				drop();
				break;
			case 5:
				display();
				break;
			case 6:
				search();
				break;
			case 8:
				printf("\nexiting...\n");
				printf("\n\t\t good bye!!!\n\n");
				exit(0);
				break;
			case 7:
				help();
				break;
			default:
				printf("\nplease choose a correct option\n");
				break;
		}
	    //system("clear");
		printf("\nselect the query to implement\n");
		printf("\n1.show all tables in database\n2.create table\n3.insert into table\n4.drop table\n5.describe table\n6.search table or search inside table\n7.help\n8.quit\n\n");
		scanf("%d",&c);
	}
}

//starting the system
void start_system(){
	system("clear");
	printf("\n\t\t\tWELCOME\n\n");
	printf("\t\tWelcome to myDB monitor \n\n");
	//cout<<"\t\tType h for help and q for quit\n\n";
	input();
}


int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	start_system();
	return 0;
}
