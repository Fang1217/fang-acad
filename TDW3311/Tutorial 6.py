# %% [markdown]
# # Lab 06 - Data Wrangling Skill: Part I
# Four main concepts are covered in this lab: 
# 1. missing data;
# 2. outliers; 
# 3. skill in transformation: sub-setting & reshaping; 
# 4. date and time. 

# %%
import pandas as pd
import numpy as np

#since the original data has no header, we just add in using data.columns
data = pd.read_csv('Datasets/breast-cancer-wisconsin.data', sep=",", header=None)
data.columns=[
    "ID",
    "Clump_Thickness",
    "Uniformity_CellSize",
    "Uniformity_CellShape",
    "Marginal_Adhesion",
    "Single_Epithelial",
    "Bare_Nuclei",
    "Bland_Chromatin", 
    "Normal_Nucleoli", 
    "Mitoses",
    "Classes"
]
print (data.head()) #display the first few rows of data
data.describe()

# %% [markdown]
# ### 6.1 Identify the Missing Data
# 
# In the real world, data scientist will explore the data to define any missing data. Sometimes missing data may contain some weird characters, sometimes it is blank, or null. In the data description, we know that the missing data for breast cancer is recorded as "?". If you try to search and explore the missing values, you find nothing. 

# %%
print(data.isnull().sum()) #returns 0.

# %% [markdown]
# Convert the missing data from “?” to “NaN”. Which attribute is having missing data? 

# %%
#replace the missing data
#observe that the missing data is contains in Bare_Nuclei
data = data.replace('?',np.NaN)

print('\nNumber of instances = %d' % (data.shape[0]))
print('Number of attributes = %d' % (data.shape[1]))

print('Number of missing values:')
for col in data.columns:
    print('\t%s: %d' % (col,data[col].isna().sum()))

# %% [markdown]
# ### 6.2 Handling Missing Data
# Two types of handling missing data:
# 1. Fill up using median; or
# 2. Impute by using linear interpolation.

# %%
#Filling up missing value with median
data_impMedian = data.Bare_Nuclei.fillna(data.Bare_Nuclei.median())#, inplace = True)
data_impMedian.isnull().sum() #now no more missing values for column Bare_Nuclei

# %%
#Impute by using linear interpolation; inplace = True is not set to not rewrite the original data.
data_impInter = data.Bare_Nuclei.interpolate(method='linear', direction = 'forward') 
data_impInter.isna().any()

# %% [markdown]
# ### 6.3 Outliers
# All the necessary modules:
# - Pandas and Numpy
# - Seaborn and matplotlib > For outliers visualization
# - zscore from scipy.stats for outliers > For explore outliers 

# %%
import pandas as pd
import numpy as np

import seaborn as sns 
import matplotlib.pyplot as plt

from scipy.stats import zscore
from sklearn.datasets import fetch_california_housing
from math import cos,pi

# %%
#download the data and assign to Data1.
Data1 = fetch_california_housing()

#check feature names
Data1.feature_names

#convert to pd df.
House = pd.DataFrame(Data1.data, columns=Data1.feature_names)
House.head()

House.shape

# %% [markdown]
# Outliers visualisations:
# - Boxplot
# - Scatterplot
# - Histogram
# - Z-score calculation

# %%
#Boxplot
fig = plt.figure(figsize=(10,5))
sns.boxplot(House.MedInc)
plt.title(
    'Box Plot: Median income for households within a block (\'000 dollars)', 
    fontsize=15)
plt.xlabel(
    'Median Income (tens of thousand of dollars)', 
    fontsize=14)
plt.show()

# %%
#Scatterplot
House.plot(kind='scatter', x='MedInc', y='Population', alpha=1, color='green')
plt.xlabel('Median Income')
plt.ylabel('Population')
plt.title('Median Income vs Population')

# %%
#Histogram
House.MedInc.hist() #single feature
House.hist(figsize = (20,15)) #all features

# %%
#Z-score calculation
result = zscore(House.MedInc)
#add result as additional attribute in House
House['resultZ'] = result

# %% [markdown]
# Typically, z-score can be used to explore and identify outliers. Add one additional column to store the value of z-score. (&pm; 3)

# %%
display(House[~((House['resultZ'] < 3) & (House['resultZ'] > -3))]) 

#remove such outliers and restore data 
House_noOutliers = House[((House['resultZ'] < 3) & (House['resultZ'] > -3))]
display(House_noOutliers)

# %% [markdown]
# ### 6.4 Subsetting
# 
# The data contains a lot of missing values. We can use precision method to remove columns that have 80% of missing values. By using:
# `data.isnull().sum(axis=1) / len(data.columns)-1`

# %%
import pandas as pd
import numpy as np

data = pd.read_excel('Datasets/cell phone total.xlsx', header=[0]) 
print(data.head())

# %%
threshold = data.isnull().sum(axis=1)/(len(data.columns)-1) 

#exclude the 1st column which is the name of countries
remove_row = threshold[threshold>0.8].index

data.drop(remove_row, axis=0, inplace = True)
print(data.head()) 

#check to make sure it moves only those with missing values >80%
print(len(data))

# %%
#check for duplicate data 
data.duplicated()

# %%
# Print out all the columns. Suppose the 1st column is not treated as column. Rename the 1st columns as ‘Country’. 
print(data.columns)
data.rename(columns={'Mobile cellular subscriptions, total number':'Country'}, inplace = True)
print(data.head())

# %%
# set country as index.
data.set_index("Country", inplace = True)
print(data.head())

# %% [markdown]
# Subsetting by columns: now select the subset of United Kingdom and save in `data_sub1`, then extract Northern European countries:
# 
# > Note: if you putting a wrong brackets for .loc function, you may get an error as Too Many Indexers
# 
# Then continue to get only selected columns by using `loc[:, "COL_NAMES"]`, with optional sorting with `.sort_values(by=['COL'])`

# %%
#Subsetting by columns: now select the subset of United Kingdom and save in data_sub1.
data_sub1 = data.loc["United Kingdom"]
print(data_sub1)

# %%
#obtain index of all the Northen European countries
data_sub1 = data.loc[["United Kingdom","Sweden", "Denmark", "Finland", "Norway","Ireland", "Lithuania", "Latvia", "Estonia", "Iceland"]]
print(data_sub1)

type(data_sub1) #check the type of data_sub1, it is a data frame

# %%
# Continue to extract only data from 2000 to 2011 from data_sub1.
# Then sort the values according to a specific column. 
data_sub1.loc[:, '2000':'2011'].sort_values(by=['Country'])

# %% [markdown]
# Subsetting a data to only select row and columns, and based on their conditions.

# %%
#Subset the data to only Finland, Norway, and Ireland with the cellular subscription for year 2003 and 2005. Then filter the data where the subscription amount of year 2005 is less than 4000000. Store this subset and replace data_sub2.

data_sub2 = data.loc[["Finland","Norway", "Ireland"],['2003','2005']] 
print(data_sub2)

print(data_sub2[data_sub2['2005'] < 4500000])

# %% [markdown]
# ### 6.5 Reshaping
# Reshaping the table by using `melt()` or `stack()`:
# 
# 
# Let the Country be a column, Year be a column, and Value be a column.\
# Store the new reshape data in data_new reset index so that Country is not an index for us to make it a data column.

# %%
data_sub2.describe()
data_new=pd.melt(data_sub2)

data_sub2 = data_sub2.reset_index()
data_sub2.columns = data_sub2.columns.str.replace(' ', '')

data_new = pd.melt(data_sub2, id_vars = ['Country'], value_vars = ['2003', '2005'], var_name='Years', value_name='Values')
print(data_new)

# %%
data_sub2.stack() #normal stack method (run and check the output)

# %%
data_sub2.set_index(['Country']).stack().reset_index() #set the index

# %%
#Reshape data_new from long to wide by using pivot function of pandas
print(data_new) #print before change

# %%
data_new = data_new.pivot(index = 'Country', columns='Years', values='Values')
print(data_new) # print after change

# %% [markdown]
# > Note: to avoid key error such as id_vear not present, you can try to reset the index of `data_sub2`, and remove whitespaces in column names (if any).

# %%
data_sub2 = data_sub2.reset_index() 
data_sub2.columns = data_sub2.columns.str.replace(' ', '')

print(data_sub2)

# %% [markdown]
# ### 6.6 Date and Time
# 
# This section will focus on date and time, in order to analyze time series data. There are two ways to convert date and time:
# 
# 1. Using `to_datetime()`: `pd.to_datetime(DF['COLUMN'], format = 'FORMAT').dt.(date|time)`
# 2. Using `parse_dates()` or `astype()`

# %%
data = pd.read_csv('Datasets/AirQualityUCI.csv', header=[0], sep=";")
print(data.head())
print(data.shape)

# %% [markdown]
# Before proceeding, handle the missing data. We need to work with data without missing values.
# - Remove any columns with missing data more than 80%.

# %%
threshold=data.isnull().sum()/len(data) 
print(threshold)

#get the index of each columns and store in remove_col
remove_col = threshold[threshold>0.8].index 

data.drop(remove_col, axis=1, inplace = True)
print(data.columns)
threshold = data.isnull().sum(axis=1)/(len(data.columns)-1)
print(threshold)

remove_row = threshold[threshold>0.8].index
data.drop(remove_row, axis=0, inplace = True)
print(data.head()) #check to make sure it moves only those with missing values >80%
print(len(data))

# %% [markdown]
# Before converting to time, check the datatype of the date and time first. Then convert to time.\
# \
# If you want to parsing Time directly, error is occurred. This may also happen to Date if the default format is not match. \
# What you can do is specify the original format from the data to avoid parsing error. For e.g., in this data, the time format is 18.00.00, we can declare this format = '%H.%M.%S'

# %%
print(data.dtypes)
data.columns

# %%
#change the type of Date by using to_datetime function.
data['Date'] = pd.to_datetime(data['Date'])
#changing the time may cause error due to incorrect format hence as specified.
data['Time'] = pd.to_datetime(data['Time'], format = '%H.%M.%S').dt.time

# %%
# Another alternative way to transform object date is using parse_dates or astype. 
# alternative 1
data1 = pd.read_csv("Datasets\AirQualityUCI.csv", header=[0], sep=";", parse_dates=["Date"])
data1.dtypes

#alternative 2
data2 = pd.read_csv("Datasets\AirQualityUCI.csv", header=[0], sep=";")
data2['Date'] = data2.Date.astype('datetime64[ns]')
data2.dtypes


# %%
#7.	Assemble Multiple Columns

data3 = pd.DataFrame({'Year': [2020, 2021], 'Month': [6,7], 'Day': [1,2]})
data3['Date'] = pd.to_datetime(data3)
data3

# %%
#8.	To extract day, month and year:

data['Year'] = data['Date'].dt.year
data['Month']= data['Date'].dt.month
data['Day']= data['Date'].dt.day

data['week_of_year'] = data['Date'].dt.week
data['day_of_week'] = data['Date'].dt.dayofweek
data['is_leap_year'] = data['Date'].dt.is_leap_year

data.head()


