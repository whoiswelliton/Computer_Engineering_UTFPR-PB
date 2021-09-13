# -*- coding: utf-8 -*-
"""L06 Welliton - Gaussian Distribution.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1kfujU9LGesU9EOCBEGyvMxxDxbgVlhGg
"""

import os
import random
import librosa
import scipy as sp
import numpy as np
import pandas as pd
import pylab as py 
import sklearn
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.impute import SimpleImputer
from mlxtend.plotting import plot_decision_regions
from mlxtend.plotting import scatterplotmatrix
import statsmodels.api as sm 


#visualização
import seaborn as sns
import librosa.display
import IPython.display as ipd
import matplotlib.pyplot as plt

from google.colab import drive
drive.mount('/content/drive')

"""#**CARREGANDO DATASET**"""

features = pd.read_csv('/content/drive/My Drive/Audio Dataset/timeaudiofeatures1.csv')
all = pd.read_csv('/content/drive/My Drive/Audio Dataset/audio_all.csv')
x = pd.read_csv('/content/drive/My Drive/Audio Dataset/audio_data.csv')
y = pd.read_csv('/content/drive/My Drive/Audio Dataset/audio_labels.csv')
all.shape

all.head()

Gaussian = all.iloc[:,0:3]
Class = all.iloc[:,7:8]
Bernoulli = all.iloc[:,3:8]

X = x.to_numpy()
Y = y.to_numpy()

Gaussian.head()

Bernoulli.tail()

"""Normalizando os dados"""

scaler = StandardScaler()
scaler.fit(X)
X_std = scaler.transform(X)

"""#1. **VERIFICAÇÃO DE DISTRIBUIÇÕES (GAUSSIANA OU BERNOULLI)**"""

def descritive(x):
    # calculating descriptives of variable
    min = np.min(x)
    max = x.max()
    ran = x.max()-x.min()
    mean = x.mean()
    median = np.median(x)
    std = x.std()
    skew = sp.stats.skew(x)
    kurt = sp.stats.kurtosis(x)
    x

    # calculating points of standard deviation
    points = mean-std, mean+std

    # plotting the variable with every information
    sns.displot(x, kde=True)
    
    sns.lineplot(points, [0,0], color = 'black', label = "std")
    sns.scatterplot([min,max], [0,0], color = 'orange', label = "min/max")
    sns.scatterplot([mean], [0], color = 'red', label = "mean")
    sns.scatterplot([median], [0], color = 'blue', label = "median")
    plt.ylabel('density')
    print(f"std {round(mean-std,2)} {round(mean+std,2)}") 
    print(f"kurtosis {round(kurt,2)}") 
    print(f"skewnees {round(skew,2)}") 
    print(f"range {round(min,2),round(max,2),round(ran,2)}") 
    print(f"mean {round(mean,2)}") 
    print(f"median {round(median,2)}")

"""Apenas as 3 primeiras features tem distribuição gaussiana, as 2 contínuas e 1 discreta, nas categóricas a ditribuição é de bernoulli

- Feature 1: Amplitude Envelope - Dist. Gaussiana
"""

descritive(X[:,0])

sm.qqplot(X[:,0], line = 'r') 
py.show()

"""- Feature 2: Root-Mean Square - Dist. Gaussiana"""

descritive(X[:,1])

sm.qqplot(X[:,1], line = 'r') 
py.show()

"""- Feature 3: Zero-Crossing Rate - Dist. Gaussiana"""

descritive(X[:,2])

sm.qqplot(X[:,2], line = 'r') 
py.show()

"""- Feature 4 - Frequency Range - Dist. Bernoulli"""

descritive(X[:,3])

sm.qqplot(X[:,3], line = None) 
py.show()

"""- Feature 5: Time Decay - Dist. Bernoilli"""

descritive(X[:,4])

sm.qqplot(X[:,4], line = None) 
py.show()

"""- Feature 5 & 6 - One Hot Encoding de SOURCES - Dist. Bernoulli"""

descritive(X[:,5])

sm.qqplot(X[:,5], line = None) 
py.show()

descritive(X[:,6])

sm.qqplot(X[:,6], line = None) 
py.show()

"""#2. **COVARIÂNCIA E CORRELAÇÃO**

- Matriz de Covariância
"""

cov = np.cov(X_std.T)
fig, ax = plt.subplots(figsize=(10,8))     
sns.heatmap(cov, vmin=-1, vmax=1, cmap='viridis',annot=True,linewidths=5,ax=ax)

"""- Matriz de Correlação"""

corr = np.corrcoef(X_std.T)
fig, ax = plt.subplots(figsize=(10,8))        
sns.heatmap(corr, vmin=-1, vmax=1, cmap='viridis',annot=True,linewidths=5,ax=ax)

"""- **Scatterplot**"""

sns.pairplot(all, kind="scatter", hue = 'CLASS')

"""- **Pairplot**

"""

sns.pairplot(features, hue = "CLASS")

"""- **Multiple Linear Regression**"""

sns.set_theme()
g = sns.lmplot(data=features, x="AMP", y="RMS", hue="CLASS", height=5)
g.set_axis_labels("AMP", "RMS")

sns.set_theme()
g = sns.lmplot(data=features, x="RMS", y="ZCR", hue="CLASS", height=5)
g.set_axis_labels("RMS", "ZCR")

sns.set_theme()
g = sns.lmplot(data=features, x="AMP", y="ZCR", hue="CLASS", height=5)
g.set_axis_labels("AMP", "ZCR")

"""#3. **REMOVENDO OUTLIERS**

Por hora escolhi remover os outliers se baseando nos dados por cada feature, que nos dá 3 verificações, para uma resposta mais refinada ainda podemos remover outliers verificando por classe x feature o que seriam necessárias 15 verificações...
"""

features.describe()

"""Serão considerados OUTLIERS todos os dados acima e abaixo de 3 Desvios Padrões da média"""

index = []

"""- AMP Outliers"""

lower_limit1 = features.AMP.mean() -3*features.AMP.std()
upper_limit1 = features.AMP.mean() + 3*features.AMP.std()
lower_limit1, upper_limit1

index.append(features.AMP[(features.AMP>upper_limit1) | (features.AMP<lower_limit1)].index)
index

"""- RMS Outliers"""

lower_limit2 = features.RMS.mean() -3*features.RMS.std()
upper_limit2 = features.RMS.mean() + 3*features.RMS.std()
lower_limit2, upper_limit2

index.append(features.RMS[(features.RMS>upper_limit2) | (features.RMS<lower_limit2)].index)
index

"""- ZCR Outliers

"""

lower_limit3 = features.ZCR.mean() -3*features.ZCR.std()
upper_limit3 = features.ZCR.mean() + 3*features.ZCR.std()
lower_limit3, upper_limit3

index.append(features.ZCR[(features.ZCR>upper_limit3) | (features.ZCR<lower_limit3)].index)
index

#achatando tudo em uma lista só
flattened  = [val for sublist in index for val in sublist]
flattened

#removendo índices duplicados
to_remove = list(set(flattened))
to_remove

#removendo tuplas dos índices correspondentes aos dados outliers do dataset com strings e do com números
clean_data1 = features.drop(to_remove)
clean_data2 = all.drop(to_remove)
clean_data1.shape

#Salvando novos datasets sem os outliers
audioft_cleanStr =  pd.DataFrame(clean_data1)
audioft_cleanNmb = pd.DataFrame(clean_data2)

audioft_cleanStr.to_csv('/content/drive/My Drive/Audio Dataset/audioft_cleanStr.csv', index = False)
audioft_cleanNmb.to_csv('/content/drive/My Drive/Audio Dataset/audioft_cleanNmb.csv', index = False)

"""#4. **DISTRIBUIÇÃO NORMAL MULTIVARIADA (2D)**

Justificativa: A escolha sobre a distribuição, foi porque como optei por exibir as distribuições de acordo com a classe, cada feature nos gera 5 distribuições por features, a representação 3D teria 15 distribuições, o que com 10 em 2D já fica poluído ao observarmos. 
A representação utilizada foi a:
- **Kernel Density Estimate**

AMP x RMS
"""

sns.jointplot(data=clean_data, x="AMP", y="RMS", hue="CLASS")

sns.set_theme(style="ticks")
g = sns.jointplot(data= clean_data, x="AMP", y="RMS", hue="CLASS", kind="kde",)

"""AMP x ZCR"""

sns.jointplot(data=clean_data, x="AMP", y="ZCR", hue="CLASS")

sns.set_theme(style="ticks")
g = sns.jointplot(data= clean_data, x="AMP", y="ZCR", hue="CLASS", kind="kde",)

"""RMS x ZCR"""

sns.jointplot(data=clean_data, x="RMS", y="ZCR", hue="CLASS")

sns.set_theme(style="ticks")
g = sns.jointplot(data= clean_data, x="RMS", y="ZCR", hue="CLASS", kind="kde",)