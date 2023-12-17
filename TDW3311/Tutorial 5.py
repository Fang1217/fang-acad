'''Lab 5: Web Scraping, Relational Database'''

'''
Helper Methods:
'''
def sqlQueryAll(cmd):
    cursor.execute(cmd)
    records = cursor.fetchall()
    for row in records:
        print(row)

def sqlQuery(cmd):
    cursor.execute(cmd)
    conn.commit()
    
def pdSqlQuery(cmd):
    df = pd.read_sql(cmd, conn)
    print(df) 
    
'''Part 1'''

'''Q1: Extract HTML information'''
from bs4 import BeautifulSoup
  
# Open a local html file saved in the same location
html_file = open("books.html", "r")
  
# Read the file
contents = html_file.read()
  
soup = BeautifulSoup(contents, 'html.parser')

# Use the find_all method of BeautifulSoup to access the div tags of specific class
book_list = soup.find_all('div', class_ = 'book_info')

for book in book_list:
    print(book.get_text())


'''Q2: Only extract title'''
# Use the find_all method of BeautifulSoup to access the h2 tags of specific class
book_list = soup.find_all('h2')

for book in book_list:
    print(book.get_text())


'''Part 2'''
#1. Connect to database
import sqlite3
conn = sqlite3.connect("company.db")

#2. create cursor to interact w/ database
cursor = conn.cursor()

#3. create table Job.
cmd = """CREATE TABLE Job (
    Job_Code CHAR(3) PRIMARY KEY NOT NULL,
    Job_Description VARCHAR(15), 
    Job_Chg_Hour DECIMAN(6,2), 
    Job_Last_Update DATE
    );
"""
cursor.execute(cmd)

#4. insert record into table Job
cmd = """INSERT INTO Job VALUES(
    '500',
    'Programmer',
    '35.75',
    '2009-11-09'
    );
"""
cursor.execute(cmd)

#5. save changes to database
conn.commit()

#6. insert more records
cmd = """
INSERT INTO JOB VALUES 
('501', 'Systems Analyst', 96.75,  '2009-11-09'),
('502', 'Database Designer', 125.00, '2010-03-24'),
('503', 'Electrical Engineer', 84.50, '2009-11-09'),
('504', 'Mechanical Engineer', 67.90, '2009-11-09'),
('505', 'Civil Engineer', 55.78, '2009-11-09'),
('506', 'Clerical Support', 26.87, '2009-11-09'),
('507', 'DSS Analyst', 45.95, '2009-11-09'),
('508', 'Applications Designer', 48.10, '2010-03-24'),
('509', 'Bio Technician', 34.55, '2009-11-09'),
('510', 'General Support', 18.36, '2009-11-09');
"""
cursor.execute(cmd)
conn.commit()

#7. query records from Job
cursor.execute("SELECT * FROM Job")
jobs = cursor.fetchall()

for row in jobs:
    print(row)
    
#8, 9 create table Employee
cursor.execute(""" CREATE TABLE EMPLOYEE ( 
    EMP_NUM CHAR(3) PRIMARY KEY, 
    EMP_LNAME VARCHAR(15) NOT NULL, 
    EMP_FNAME VARCHAR(15) NOT NULL, 
    EMP_INITIAL CHAR(1), 
    EMP_HIREDATE DATE, 
    EMP_YEARS INTEGER,
    JOB_CODE CHAR(3), 
    FOREIGN KEY (JOB_CODE) REFERENCES JOB(JOB_CODE) 
        ON DELETE RESTRICT ON UPDATE CASCADE);""")

cursor.execute("""INSERT INTO Employee VALUES 
    ('101','News','John','G','2000-11-08',8,'502'),
    ('102','Senior','David','H','1989-07-12',19,'501'),
    ('103','Arbough','June','E','1996-12-01',12,'503'),
    ('104','Ramoras','Anne','K','1987-12-01',21,'501'),
    ('105','Johnson','Alice','K','1993-11-15',16,'502'),
    ('106','Smithfield','William',' ','2004-02-01',4,'500'),
    ('107','Alonzo','Maria','D','1993-06-22',15,'500'),
    ('108','Washington','Ralph','B','1991-10-10',17,'501'),
    ('109','Smith','Larry','W','1997-07-18',11,'501'),
    ('110','Olenko','Gerald','A','1995-12-11',13,'505'),
    ('111','Wabash','Geoff','B','1991-04-04',17,'506'),
    ('112','Smithson','Darlene','M','1994-10-23',14,'507'),
    ('113','Joenbrood','Delbert','K','1996-11-15',12,'508'),
    ('114','Jones','Annelise','','1993-08-20',15,'508'),
    ('115','Bawangi','Travis','B','1992-01-25',17,'501'),
    ('116','Pratt','Gerald','L','1997-03-05',12,'510'),
    ('117','Williamson','Angie','H','1996-06-19',12,'509'),
    ('118','Frommer','James','J','2005-01-04',4,'510');
""")

conn.commit()

#10. retrieve all records
cursor.execute("SELECT * FROM Employee")
emp = cursor.fetchall()
print(emp)

#11. retreive first result of the query with EMP_NUM = 118
cursor.execute("SELECT * FROM EMPLOYEE WHERE EMP_NUM = '118';")
emp = cursor.fetchone()
print(emp)


#12. Update the EMP_YEARS of the employee whose EMP_NUM is 118 to 5 years.
cursor.execute("UPDATE EMPLOYEE SET EMP_YEARS = 5 WHERE EMP_NUM = '118'")
conn.commit()

# print the updated record
cursor.execute("SELECT * FROM EMPLOYEE WHERE EMP_NUM = '118';")
updated_emp = cursor.fetchone()
print(updated_emp)


#13. delete with WHERE
cursor.execute("DELETE FROM EMPLOYEE WHERE EMP_NUM = '118'")
conn.commit()

# check if record has been deleted
cursor.execute("SELECT * FROM EMPLOYEE WHERE EMP_NUM = '118';")
emp_result = cursor.fetchone()
print(emp_result)


#14. retrieve specific columns
cmd = "SELECT EMP_NUM, EMP_LNAME, EMP_FNAME FROM EMPLOYEE"
sqlQueryAll(cmd)

#15. retrieve data from more than one table (Join)
sql1 = """
SELECT * FROM EMPLOYEE
INNER JOIN JOB ON JOB.JOB_CODE = EMPLOYEE.JOB_CODE
"""
sqlQueryAll(sql1)

#16. 
sql2 = """SELECT EMP_LNAME, EMP_FNAME, JOB_DESCRIPTION from EMPLOYEE
    JOIN JOB USING (JOB_CODE)
    WHERE EMP_YEARS >= 15;
"""
sqlQueryAll(sql2)
    
#17. 
sql3 = """SELECT EMP_LNAME, EMP_FNAME, JOB_DESCRIPTION from EMPLOYEE
    JOIN JOB USING (JOB_CODE)
    WHERE JOB_DESCRIPTION = "Systems Analyst"
    ORDER BY EMP_LNAME ASC;
"""
sqlQueryAll(sql3)

#18. 
import pandas as pd
sql4 = """SELECT EMP_NUM, EMP_LNAME, EMP_FNAME FROM EMPLOYEE
"""
pdSqlQuery(sql4)

#19.s
sql5 = """SELECT JOB_CODE, JOB_DESCRIPTION, COUNT(JOB_CODE) AS EMP_NUM FROM EMPLOYEE
    JOIN JOB USING (JOB_CODE)
    GROUP BY JOB_CODE;
"""
pdSqlQuery(sql5)


'''Task 2'''
cursor.execute("""
CREATE TABLE 'PROJECT'
( PROJ_NUM CHAR(3) PRIMARY KEY,
 PROJ_NAME VARCHAR(15) NOT NULL,
 PROJ_VALUE DOUBLE,
 PROJ_BALANCE DOUBLE,
 EMP_NUM CHAR(3),
 FOREIGN KEY (EMP_NUM) REFERENCES EMPLOYEE(EMP_NUM) ON DELETE RESTRICT ON UPDATE CASCADE
    );""")

cursor.execute("""
    INSERT INTO PROJECT VALUES 
    ('15','Evergreen',1453500.00,1002350.00,'103'),
    ('18','Amber Wave',3500500.00,2110346.00,'108'),
    ('22','Rolling Tide',805000.00,500345.20,'102'),
    ('25','Star flight',2650500.00,2309880.00,'107');
    """)

#2. Save changes
conn.commit()

#3. Retrieve all records
sqlQueryAll("SELECT * FROM PROJECT")

#4. 
cmd = """SELECT PROJ_NAME, PROJ_VALUE, EMP_FNAME, EMP_LNAME
    FROM PROJECT
    JOIN EMPLOYEE USING (EMP_NUM)"""
df = pd.read_sql(cmd, conn)
print(df) 

#5. 
cmd = """SELECT JOB_CODE, JOB_DESCRIPTION, SUM(PROJ_VALUE) FROM PROJECT
    JOIN EMPLOYEE USING (EMP_NUM)
    JOIN JOB USING (JOB_CODE)
    GROUP BY JOB_CODE"""
pdSqlQuery(cmd)

#6. 
conn.close()