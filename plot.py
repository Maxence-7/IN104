import matplotlib.pyplot as plt

def lecture_fichier(nom_fichier):
    f = open(nom_fichier, 'r')
    f.readline()
    X,Y = [],[]
    i=0
    for l in f.readlines():
        X.append(i)
        i=i+1
        Y.append(float(l))
    f.close()
    return X,Y
    
X,Y=lecture_fichier("dataCorrel.dat")

dY=[]

for i in range(len(X)-1):
    dY.append(Y[i+1]-Y[i])
    
plt.plot(X,Y)
#plt.plot(X[:len(X)-1],dY)
plt.show()