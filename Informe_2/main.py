import sys

#Fibonacci iterativo ---------------------------
def fib_ite(n):
    a = 0
    b = 1
    for i in range(1,n):
        b += a
        a = b-a
    return n if n == 0 else b

#Fibonacci recursivo ---------------------------
def fib_rec(n):
    if n <= 1:
        return n 
    return fib_rec(n-1) + fib_rec(n-2)

#sys.setrecursionlimit(100000)
#fib_ite(1073741824)
#fib_rec(1073741824)

#Fibonacci modular ------------------------------
def get_pisano(n):
    
    a = 0
    b = 1 
    c = a + b 
    
    for i in range(n*n):
        c = (a + b) % n
        a = b 
        b = c
        if a == 0 and b == 1:
            return i + 1 

def fib_mod(n, m):

    if n <= 1:
        return n 
    
    a = 0 
    b = 1
    n = n % get_pisano(m)
    
    for i in range(n-1):
        aux = 0
        aux = b 
        b = (a + b) % m
        a = aux

    return b % m

#print(fib_mod(1073741824,1048576))

#Fib using memory

# Importamos la librería sys para subir el limite de recursividad de Python.
import sys

# La función recursiva realiza varias veces los mismos cálculos.
def fibonacci_recursivo(n):
    if n == 0 or n == 1:
        return 1

    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2)


# En cambio en la función dinámica vamos a utilizar la técnica de la
# memorización, guardando los resultados ya hechos en un diccionario.
def fibonacci_dinamico(n, memo = []):
    if n == 0 or n == 1:
        return 1


    # Primero intentamos buscar el resultado en memoria.
    try:
        return memo[n]

    # En caso de no existir realizamos el cálculo.
    except KeyError:
        resultado = fibonacci_dinamico(n - 1, memo) + fibonacci_dinamico(n - 2, memo)
        memo[n] = resultado

        return resultado

#sys.setrecursionlimit(1000000002)
#resultado = fibonacci_dinamico(10000)

# get min
def min_v(x, y):
    if x < y : 
        return x 
    return y 

def printt(x, m):
    for i in range(m+1):
        count = 0 
        for j in x:
            if i == j:
                count += 1 
        print(i, ":", count)

# Counting squares
def countSquareMatrices(a, N, M, x, y):
    count = 0
    ans = []
    for i in range(1, N):
        for j in range(1, M):
            if (a[i][j] == 0):
                continue
            
            a[i][j] = min([a[i - 1][j],
                      a[i][j - 1], a[i - 1][j - 1]])+1
            
            # saving
            count += a[i][j]
            
            ans.append(a[i][j])
    
    m = min_v(x,y)

    # printing 
    printt(ans, m)
    
    return count
 
# executing 
    
arr = [[ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1],
      [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1],
      [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1],
      [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1]]
 
print(countSquareMatrices(arr, 13, 13, 4, 4))