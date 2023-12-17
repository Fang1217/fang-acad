'''Lab 4: Introduction to Data Wrangling'''

#Part 1

import pandas as pd
import numpy as np

'''Task 1: Pandas and Numpy'''

#create two lists
emp_name_list = ["Alice", "Bob", "Cathy"]
emp_height_list = [168, 170, 155]

#create series from lists
emp_name_series = pd.Series(emp_name_list, name="Employee_Name")
emp_height_series = pd.Series(emp_height_list, name="Employee_Height")

print("\nPrint Series")
print(emp_height_series, "\n")
print(emp_height_series)

print("\nAccess a particular element using index")
print(emp_name_series[1])
print(emp_height_series[1])


'''Task 2: Pandas Dataframe'''

#create a dictionary
emp_profile = {"Name": emp_name_series, "Height": emp_height_series}

#create a dataframe from dictionary
emp_df = pd.DataFrame(emp_profile)

print("\nPrint dataframe")
print(emp_df)

print("\nSelect a column")
print(emp_df['Name'])

print("\nSelect multiple columns")
print(emp_df[['Name', 'Height']])

print("\nSelect a row")
print(emp_df.iloc[2])

print("\nSelect multiple rows")
print(emp_df.iloc[[1,2]])

print("\nOther examples")
print(emp_df["Name"][0])
print(emp_df["Height"][1])

'''Task 3: Explicit Indexing'''
# create a dataframe from dictionary
emp_df = pd.DataFrame(emp_profile)
new_index = pd.Index(['1001', '1002', '1003'])
emp_df = emp_df.set_index(new_index)

print("\nPrint dataframe")
print(emp_df)

'''Task 4: NumPy vs Py List'''

import time

size_vec = 2000000
t1 = time.time()
X = range(size_vec)
Y = range(size_vec)
Z = [X[i]+Y[i] for i in range(len(X))]
list_time = time.time()-t1

t2 = time.time()
X2 = np.arange(size_vec)
Y2 = np.arange(size_vec)
Z2 = X2+Y2
list_time2 = time.time()-t2

print(list_time, list_time2)
#0.9827098846435547s,  0.008023500442504883s

'''Task 5: NumPy Array within Specified Range'''
#for loop- like, incl excl step

array1 = np.arange(5, 20, 5)
print(array1)

array2 = np.arange(11, 17, 2)
for i in range(len(array2)): #array length
    array2[i] += 5
print(array2)

'''Task 6: 1D NumPy array'''
array3 = np.array([30, 22, 18, 10, 20])
print("1D Array: ", array3)
print("The mean is %.2f and standard deviation is %.2f" % (array3.mean(), array3.std()))

'''Task 7: ID NumPy Array and User Input'''
size = int(input("Please enter the total number of array elements: "))

array4 = np.empty(5, int)
for i in range(size):
    array4[i] = int(input("Enter an element: "))
print(array4)


'''Task 8: 2D NumPy Array'''
array5 = np.array([[1,2,3],[4,5,6]])
print("2D array:\n", array5)

'''Task 9: 2D NumPy Array and User Input'''
array6 = np.empty((3,5), int)

for i in range(array6.shape[0]):
    for j in range(array6.shape[1]):
        print("Enter an element for row %d column %d: " % (i, j))
        array6[i][j] = int(input())
print(array6)

array6 = np.array([[3, 8, 2, 9, 2], [7, 5, 8, 9, 9], [6, 4, 3, 2, 7]])
print("Mean:", (array6.mean(axis=1)))

'''Task 10: Read XML'''
import pandas as pd

student_df = pd.read_xml('Datasets/student.xml')
print(student_df)

'''Task 11: Read JSON'''
import pandas as pd

df = pd.read_json('https://api.covid19india.org/state_district_wise.json')

active_case = df['Andaman and Nicobar Islands']['districtData']['South Andaman']['active']
print("Active cases in South Andaman:", active_case)

'''Task 12: Read CSV'''
df = pd.read_csv('Datasets/Melaka_Tengah.csv')
print(df)

'''Task 13: Read Data using read_table()'''
df = pd.read_table(
    "https://archive.ics.uci.edu/ml/machine-learning-databases/breast-cancer-wisconsin/breast-cancer-wisconsin.data", 
    ",")
df.head()