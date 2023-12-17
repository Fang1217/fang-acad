'''Lab 3: Quantitative Techniques II'''

'''
1. Parametric Tests
'''

'''
Q1: Daily average for each location and create two histograms
'''

#import library
import pandas as pd
import matplotlib.pyplot as plt

#import temperature files
dataMelaka = pd.read_csv('Datasets/Melaka_Tengah.csv')
dataMuar = pd.read_csv('Datasets/Muar.csv')

#calculate daily average
dailyAverageMelaka = dataMelaka.mean(axis = 1)
dailyAverageMuar = dataMuar.mean(axis = 1)

#create histogram for both datasets
histMelaka = plt.subplot(2, 2, 1)
histMelaka.hist(dailyAverageMelaka)
histMelaka.set_title('Melaka Tengah')
histMelaka.set_xlabel('Temperature')
histMelaka.set_ylabel('Frequency')

histMuar = plt.subplot(2, 2, 2)
histMuar.hist(dailyAverageMuar, color = 'r')
histMuar.set_title('Muar')
histMuar.set_xlabel('Temperature')
histMuar.set_ylabel('Frequency')

'''
Q2: Z-test

Q2 Case Study 1: Temperature between Melaka Tengah and Muar

- Sample size >= 30
- Data points are independent
- Data points are normally distributed
- Data points are randomly selected from a population
- Samples of possible shall have the same size

- Hypothesis test:
    H0 - Difference in mean temp between Melaka Tengah and Muar is 0;
    H1 - Difference in mean temp between Melaka Tengah and Muar is not 0.

- Find the conclusion.
'''

#perform two sample z-test

import pandas as pd
from statsmodels.stats.weightstats import ztest
import scipy.stats as st

#import temperature files
dataMelaka = pd.read_csv('Datasets/Melaka_Tengah.csv')
dataMuar = pd.read_csv('Datasets/Muar.csv')

#calculate daily average
dailyAverageMelaka = dataMelaka.mean(axis = 1)
dailyAverageMuar = dataMuar.mean(axis = 1)

#perform two sample z-test
z, p_value = ztest(
    dailyAverageMelaka, dailyAverageMuar, 
    value = 0, 
    alternative = 'two-sided')

#find critical values, 95% confidence
alpha = 0.05 #significance, (1 - confidence)

criticalZ = st.norm.ppf(1 - alpha/2) #two tailed test

#compare z-statistics with critical z-value
if abs(z) > criticalZ:
    print('Reject null hypothesis: The difference in mean temperature between Melaka Tengah and Muar is not zero.')
else:
    print('Fail to reject null hypothesis: The difference in mean temperature between Melaka Tengah and Muar is zero.')


'''
Q3: t test

Case Study 2: Rice Flour.csv

- Two samples are independent
- Population distributions are normal
- Sample size is less than 30.

- Hypothesis test:
    H0 - The weight of rice flour packets from the two batches are the same
    H1 - The weight of rice flour packets from the two batches are not the same

'''
#import library
import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_excel('Datasets/RiceFlour.xlsx', header=0)
data.to_csv('Datasets/RiceFlour.csv', index = False)

#import flour file
dataFlour = pd.read_csv('Datasets/RiceFlour.csv')

#seperate the datasets into Flour1 and Flour2
Flour1 = dataFlour['RiceFlour 1']
Flour2 = dataFlour['RiceFlour 2']

#create histogram for both datasets
Flour1Hist = plt.subplot(2, 2, 3)
plt.cla()
Flour1Hist.hist(Flour1)
Flour1Hist.set_title('Rice Flour 1')
Flour1Hist.set_xlabel('Weight')
Flour1Hist.set_ylabel('Frequency')
Flour2Hist = plt.subplot(2, 2, 4)
plt.cla()
Flour2Hist.hist(Flour2)
Flour2Hist.set_title('Rice Flour 2')
Flour2Hist.set_xlabel('Weight')
Flour2Hist.set_ylabel('Frequency')

from statsmodels.stats.weightstats import ttest_ind

#perform two sample t-test with unequal variance
t, p, degreeOfFreedom = ttest_ind(Flour1, Flour2, alternative = 'two-sided', usevar = 'unequal')

print(p)
print(t)

#define significance level (alpha)
alpha = 0.05

#calculatte critical value for a two-tailed test with (1 - alpha/2) probability
critical_value = st.t.ppf(1-alpha/2, degreeOfFreedom)

#compare t-score with critical value
if abs(t) > critical_value:
    print('Reject the null hypothesis: There is a significant difference between the two datasets.')
else:
    print('Fail to reject null hypothesis: No significant evidence of a difference between the two datasets.')
    
'''
Q4: Paired-t test

Case Study 3: Weights.csv

Hypothesis Test:
    H0 - There is no significant difference in the weights of swimmers before and after completing training
    H1 - There is a significant difference in the weights of swimmers before and after completing training.

'''
import pandas as pd
from scipy.stats import ttest_rel

#converting csv from excel)
pd.read_excel('Datasets/Weights.xlsx', header=0).to_csv('Datasets/Weights.csv', index = False)

#import flour file
weights = pd.read_csv('Datasets/Weights.csv')

weightDifference = weights['Before Training'] - weights['After Training']

#perform paired t-test
t, p = ttest_rel(weights['Before Training'], weights['After Training'])

#define significance level (alpha)
alpha = 0.05

#compare p-value with significance level
if p < alpha:
    print('Reject the null hypothesis: Swimmers weight significantly less after training')
else:
    print('Fail to reject null hypothesis: No significant evidence that swimmers weight significantly less after training')