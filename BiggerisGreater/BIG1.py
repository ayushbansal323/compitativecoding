import math
import os
import random
import re
import sys

# Complete the biggerIsGreater function below.
def biggerIsGreater(w):
    w1=list(w)

    lst = []
    for i in range((len(w1)-1),-1,-1):
        for j in range(len(lst)):
            #fptr.write(w1[i]+"  "+lst[j][0] + '\n')
            if (w1[i]<lst[j][0]):
                temp=w1[lst[j][1]]
                w1[lst[j][1]]=w1[i]
                w1[i]=temp
                for k in range(i+1,len(w1)):
                    for l in range(i+1,len(w1)):
                        if(w[l]<w[k]):
                            temp=w1[l]
                            w1[l]=w1[k]
                            w1[k]=temp
                return "".join(w1)
        lst.append([w1[i],i]) 
    return "no answer"
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    T = int(input())

    for T_itr in range(T):
        w = input()

        result = biggerIsGreater(w)

        fptr.write(result + '\n')

    fptr.close()

