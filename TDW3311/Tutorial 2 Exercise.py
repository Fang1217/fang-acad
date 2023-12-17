'''
Same analysis as Tutorial 2 but using Muar dataset instead.
'''

import pandas as pd
import numpy as np
import scipy.stats as st

data = pd.read_excel('Datasets/Muar.xlsx', header = 0)

#Export to .csv file
data.to_csv('Datasets/Muar.csv', index = False)

#Using Muar.csv file
data = pd.read_csv('Datasets/Muar.csv')
print(data)

'''
Q1: Daily average temperatures in Muar
'''
daily_average = data.mean(axis=1)
print('Daily average: \n', daily_average)

'''
Q2: Sample mean of temperature in 365 days]
'''
print('Sample mean: %.2f' % daily_average.mean())

'''
Q3: Sample variance of temperature in 365 days
'''
print('Sample var: %.2f' % daily_average.var())

'''
Q4: Median of Time 1100 and 1700
'''
print('Medians:\n', data[['Time 1100', 'Time 1700']].median())

'''
Q5: Descriptive/Summary Statistics
'''
data.describe()

'''
Part 2: Parameter Point Estimation
'''
daily_average = data.mean(axis=1)
daily_average.hist(grid=False)

data.hist(sharex = True, sharey = True, grid = False)

mean_interval = st.norm.interval(
    confidence = .95, 
    loc = np.mean(daily_average), 
    scale = st.sem(daily_average)
)
print("(%.2f %.2f)" % mean_interval)
