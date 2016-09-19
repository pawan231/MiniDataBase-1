# MiniDataBase
Data Storage and Retrieval using B+ Tree Indexing with a touch of mini Database Engine.

## QUERIES SUPPORTED BY SYSTEM
1. SHOW Tables
2. CREATE Tables
3. INSERT INTO Table
4. DISPLAY Table
5. SEARCH INTO Table
6. DROP Table


##SYSTEM DESIGN
The Database System is designed using C++ and C combined features.
It stores the data on physical disk using files.

Features of our system include:

####1. Custom Blocks for each table:
The data is stored in blocks to avoid waste space and easy retrieval. All the separate rows data is stored in different file creating blocks of data. System reads as well as writes data back to files in blocks.

####2. B+ Tree Indexing:
A separate multilevel B+ tree is created for each table. Each node contains maximum of 50 entries. Right now data storage  is based only on primary key, primary key may be INTEGER or VARCHAR. The indexing reduces the overall search complexity of system.

####3. Storing Meta Data of Tables:
 Meta Data of the tables are stored separately which provides quick access to several information like current number of records, table name, etc.
 
####4. B+ Tree Indexed Search:
 For searching a record in file for particular table, B+ tree indexed search is implemented. Search is only based on primary key right now.
 Our System also calculates the time taken by the search algorithm.
 
##DEVELOPMENT:
The whole project project is done on eclipse platform(c/c++ perspective).

It is also tested on linux terminal.

##PROJECT CONTRIBUTORS:
1.[Mandeep Singh](https://github.com/msdeep14) -> mandeepsinghshekhawat95@gmail.com 

2.[Pawan Sheoran](https://github.com/pawan_231)-> psheoran231@gmail.com

~ aka deepvoid
