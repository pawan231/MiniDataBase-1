# MiniDataBase
Data Storage and Retrieval using B+ Tree Indexing with a touch of mini Database Engine.

## QUERIES SUPPORTED BY SYSTEM
1. SHOW Tables
2. CREATE Tables
3. INSERT INTO Table
4. DISPLAY Table
5. SEARCH INTO Table
6. DROP Table


## SYSTEM DESIGN
The Database System is designed using C++ and C combined features.
It stores the data on physical disk using files.

Features of system include:

#### 1. Custom Blocks for each table:
The data is stored in blocks.  

Benefits of blocking:

1. Blocking reduces the overhead and speeds up the handling of the data-stream. 

2. Blocking reduces the amount of external storage required for the data. 

All the separate row data of a particular table is stored in different file creating blocks of data. System reads as well as writes data back to files in blocks.

More description about blocks [here](https://en.wikipedia.org/wiki/Block_(data_storage))

#### 2. B+ Tree Indexing:
A separate multilevel B+ tree is created for each table. Each node contains maximum of 50 entries. Right now data storage  is based only on primary key, primary key can be INTEGER or VARCHAR.

#### 3. Storing Meta Data of Tables:
 Meta Data of the tables are stored separately which provides quick access to several information like current number of records, table name, etc.
 
#### 4. B+ Tree Indexed Search:
 For searching a record in file for particular table, B+ tree indexed search is implemented. Search is only based on primary  key right now.
 
 Advantages of B+ Tree Indexing:
 
 1. Since all records are stored only in the leaf node and are sorted sequential linked list, searching is becomes very easy.
 2. As the number of record increases/decreases, B+ tree structure grows/shrinks. There is no restriction on B+ tree size.
 3. Since it is a balance tree structure, any insert/ delete/ update does not affect the performance.
 4. Since we have all the data stored in the leaf nodes and more branching of internal nodes makes height of the tree shorter. This reduces disk I/O. Hence it works well in secondary storage devices.
 
System also calculates the time taken by the search algorithm.
 
## DEVELOPMENT:
The whole project is done on eclipse platform(C/C++ perspective).

It is also tested on linux terminal.

For execution:
 You can simple build and run on eclipse platform or 
 
 on terminal by executing following commands:
 
 g++ main.cpp
 
 ./a.out
 
## REFERENCES:
 Database Management Systems CHAPTER 9 [link here](https://drive.google.com/file/d/0B_UNhB7shKrMa2RTUFFaNkdjQWM/view?pli=1)
 
 Author: Raghu Ramakrishnan

 [stackoverflow](www.stackoverflow.com)
 
 

## PROJECT CONTRIBUTORS:
1.[Mandeep Singh](https://github.com/msdeep14) -> mandeepsinghshekhawat95@gmail.com ;; [msdeep14](http://msdeep14.github.io/)

2.[Pawan Sheoran](https://github.com/pawan231)-> psheoran231@gmail.com


