#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the biggerIsGreater function below.
def biggerIsGreater(w):
    w1=list(w)
    for i in range((len(w1)-1),0,-1):
        for j in range(i,-1,-1):
            fptr.write(str(i)+" "+str(j)+" "+w1[i]+" "+w1[j] + '\n')
            if (w1[i]>w1[j]):
                fptr.write(str(i)+" "+str(j) + '\n')
                temp=w1[i]
                w1[i]=w1[j]
                w1[j]=temp
                for k in range(j+1,len(w1)):
                    for l in range(j+1,len(w1)):
                        if(w[l]<w[k]):
                            temp=w1[l]
                            w1[l]=w1[k]
                            w1[k]=temp
                return "".join(w1)  
    return "no answer"
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    T = int(input())

    for T_itr in range(T):
        w = input()

        result = biggerIsGreater(w)

        fptr.write(result + '\n')

    fptr.close()

