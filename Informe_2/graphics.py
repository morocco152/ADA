import matplotlib.pyplot as plt
from tabulate import tabulate
import numpy as np

n_element = [256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576]
average_n = [4.98,5.64,6.365,7.23,7.655,8.17,9.09,9.685,10.115,10.97,11.94,12.6,13.095]	
ln_value = [2.60944,7.23832462504,7.9314718056,8.62461898616,9.04045,8.61776,10.7040605278,11.0047,10.6047,12.2752,12.701,14.1697964306,14.4776]

#plot 
def plot():
    
    plt.title("Insert sort vs Bubble Sort")
    plt.xlabel("Time")
    plt.ylabel("(n) elemtos en el arreglo")
    plt.plot(average_n, label = "Avg(n)")
    plt.plot(ln_value, label = "ln(n)+1")
    plt.legend()
    plt.show()

#main side

#draw table 
def draw():
    table = {'N #elements': [256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576], 
            'Average_n': [4.98,5.64,6.365,7.23,7.655,8.17,9.09,9.685,10.115,10.97,11.94,12.6,13.095], 
            'ln(n)+1': [2.60944,7.23832462504,7.9314718056,8.62461898616,9.04045,8.61776,10.7040605278,11.0047,10.6047,12.2752,12.701,14.1697964306,14.4776]}
    print(tabulate(table, headers = 'keys',tablefmt='fancy_grid',showindex = True))

plot()
draw()