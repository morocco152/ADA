import matplotlib.pyplot as plt
import numpy as np
import time
from math import sin
import random
import sys

#prom side 
def avg(list_,tam):
    a = 0
    for i in list_:
        a += i
    return (a/tam)*1000

#gen_array
def gen_array(K):
    new_l = []
    for i in range(K):
        new_l.append(random.randint(-K, K))
    return new_l

#print_side
def prin_array(_ar):
    for x in _ar:
        print(x,end="\t")
    print("\n")


#costos 
cos_t_ins = []
cos_t_bub = []

#ins_sort side
def insertionSort(arr):
    arr = arr[:]
    start_time = time.time()
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j] :
                arr[j + 1] = arr[j]
                j -= 1
        arr[j + 1] = key
    end_time = time.time()
    return (end_time-start_time)*1000

#bub_sort side
def mergeSort(arr):
    if len(arr) > 1: #mientras se pueda partir
        mid = len(arr)//2
        L = arr[:mid] #derecha e izquierda
        R = arr[mid:]
        mergeSort(L) #recursividad 
        mergeSort(R)
        i = j = k = 0 #los divididos
        while i < len(L) and j < len(R):
            if L[i] < R[j]: # empieza a ordenarse
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

def init_mergeSort(arr):
    arr = arr[:]
    start_time = time.time()
    mergeSort(arr)
    end_time = time.time()
    return (end_time-start_time)*1000

#text input and vector
t_ins = [] #aquí se guarda los tiempo
t_bub = []

avg_lis_ins = [] #tenemos los promedios apra graficar
avg_lis_bob = []

n = int(input("#arrays:  "))
K = [10,20,30,400,500]

#executer 
def exe():
    for i in K:
        main(n,i)

#executing side
def main(n,K):
    for i in range(n):
        new_arr = []
        new_arr = gen_array(K) #variado
        new_arr_1 = new_arr
        #new_arr.sort(reverse=True) #decreciente
        #new_arr.sort #creciente
        t_ins.append(insertionSort(new_arr))
        t_bub.append(init_mergeSort(new_arr_1))

    avg_lis_ins.append(avg(t_ins,K))
    avg_lis_bob.append(avg(t_bub,K))

#plot 
def plot():
    
    plt.title("Insert sort vs Bubble Sort")
    plt.xlabel("Time")
    plt.ylabel("(n) elemtos en el arreglo")
    plt.plot(avg_lis_ins, label = "Insert Sort")
    plt.plot(avg_lis_bob, label = "Bubble Sort")
    plt.legend()
    plt.plot(avg_lis_ins)
    plt.plot(avg_lis_bob)
    plt.show()

#main side
exe()
plot()

