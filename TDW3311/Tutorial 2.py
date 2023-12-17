'''Lab 2: Quantitative Techniques I'''

import pandas as pd

data = pd.read_excel('Datasets/Melaka_Tengah.xlsx', header=0)
data.to_csv('Datasets/Melaka_Tengah.csv', index = False)

data = pd.read_csv('Datasets/Melaka_Tengah.csv')

#print the entire data
print(data)

#print the top 5 of the dataset
data.head

#print the top 10 of the dataset
data.head(10)

#print the last 5 rows.
data.tail()

#print the last 7 rows.
data.tail(7) # Last 7 rows.

#print the shape of data set
data.shape 
#print the subset of the dataset
data.iloc[0:10] #inclusive, exclusive (0-9)

#print the datatype of the dataset
data.dtypes 

#create new dataframe data in some columns
new_df = pd.DataFrame(data, columns = ['Time 1100', 'Time 1700'])
new_df

#average for each row
daily_average = data.mean(axis=1)
print(daily_average)

#average for each column
col_average = data.mean(axis=0)
col_average

#print selected column mean
data[['Time 0500', 'Time 1400']].mean()


'''
Q1-3: Daily average temp
'''
daily_average = data.mean(axis=1)
print('The average of temperature in Melaka Tengah in 365 days is %.2f' 
      % daily_average.mean())
print('The variance of temperaturue in Melaka in Melaka Tengah in 365 days is %.2f'
      % daily_average.var())

   
'''
Q4: Median: of Time 1100 and Time 1700
'''
print('Medians:\n', data[['Time 1100', 'Time 1700']].median())


'''
Q5: Descriptive/Summary Statistics
'''
data.describe()

#Summary statistics for selected columns

#Using .agg method
statistics = data.agg(
    {'Time 1100':['mean','min','max','max','skew'],
     'Time 1700':['mean','min','max','max','skew']})
print (statistics)


'''
Part 2: Parameter Estimation
'''

'''
2.1 Point Estimation: The Method of Moments
'''

#Visualization of the histogram, with daily average
daily_average = data.mean(axis=1)
daily_average.hist(grid=False)
# Overall temperature mean 
temp_mean = daily_average.mean()
print('Mean: %.2f' % temp_mean)

# 8 Histogram (Different column)
data.hist(sharex = True, sharey = True, grid = False)

'''
2.2 Mean Interval Estimation
'''

import numpy as np
import scipy.stats as st

daily_average = data.mean(axis=1)
#create 95% of confidence interval for population mean temperature
mean_interval = st.norm.interval(
    confidence = .95, 
    loc = np.mean(daily_average), 
    scale = st.sem(daily_average)
)
print("(%.2f %.2f)" % mean_interval)
