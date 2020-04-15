# CS402_SP_LAB1_Muhao-Chen
A database of employee, finished by C program.
##### File Name #####
Employee Information Management System
##### Designer #####
cs402_SP_LAB1_Muhao Chen
##### Path #####
C,VScode,mingw64
##### Introduction #####
I use 4 functions to manage the Employee Information. It can read(using readfile.h) the txt file and store into the struct-person. Then, we can get the detail by "circulate" the list. we can get the information of id by binary search(we have ordered the info by qsort_function). Then, we can search the person by last name. Besides, we can add a employee by scanf(using readfile.h), and the new one also be sorted by qsort_function.
##### Operate #####
# 1.Prepare a file(.txt)on the path of the C program:
Example:
"165417 Cathryn Danner 72000
273225 Matt Meeden 69000
633976 Martine Marshall 99000
471163 Robert Dufour 91000"
# 2.Operate with VScode:
VScode -- F5
# 3.Input the path of File
./employee_system.exe "file name".txt
# 4.Enter 1 to 5
*************************
DB of Employee:
*************************
[1]Show DataBase
[2]Look_up by ID
[3]Look_up by Last Name
[4]Add an Employee's info 
[5]Quit
*************************
Enter Your Option:
##### Function #####
Show DataBase
------------------------------------------
Name                       Salary    ID
------------------------------------------
Cathryn    Danner          72000     165417
Matt       Meeden          69000     273225
Robert     Dufour          91000     471163
Dylan      Steinberg       84000     485913
Mike       Griffin         72000     499959
Daniel     McNamee         71000     547935
Peter      Olsen           82000     553997
Martine    Marshall        99000     633976
Jean       Jones           94000     702234
Dana       Parrish         87000     784372
Ann        Coddington      82000     786785
Melissa    Dufour         114000     849387
Heather    James           98000     935460
Russ       Vorobiev       109000     970016
------------------------------------------
Look_up by ID
*************************
Enter Your Option:
2
enter a 6-digit employee id: 
499959
------------------------------------------
Name                       Salary    ID
Mike       Griffin         72000     499959
------------------------------------------
*************************
Look_up by Last Name
*************************
Enter Your Option:
3
enter employee's last_name: 
Dufour
------------------------------------------
Name                       Salary    ID
Robert     Dufour          91000     471163
------------------------------------------
*************************
Add an Employee's info 
*************************
Enter Your Option:
4
enter employee's first name: 
CHEN
enter employee's last name: 
MUHAO
enter employee's ID: 
333
enter employee's salary: 
40000
Confirm the info of this employee 
choose(1foryes/0forno)
1
------------------------------------------
Name                       Salary    ID
------------------------------------------
CHEN       MUHAO           40000        333
