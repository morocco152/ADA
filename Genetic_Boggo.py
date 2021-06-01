import random

#Array inicial
START = [6, 3, 2, 4, 1, 0, 5]

#Clase Bogo tiene el array inicial y target final(sort)
class Bogo_Gen(object):

    def __init__(self,chrm_s,chrm_t):
        self.chrm_s = chrm_s
        self.chrm_t = chrm_t

    def get_len(self):
        return len(self.chrm_s)
    
    def permuatation(self):
        n = self.get_len()
        for i in range(0,n):
            r = random.randint(0,n-1)
            self.chrm_s[i], self.chrm_s[r] = self.chrm_s[r], self.chrm_s[i]

    def cal_fitness(self):
        fitness = 0
        for gs, gt in zip(self.chrm_s, self.chrm_t):
            if gs == gt:
                fitness += 1

        p = fitness * 100 / self.get_len()
        print (self.chrm_s," Fitness : ", fitness, " ,percent : ", p, "%")

        if fitness == self.get_len():
            return True
        return False

    def _exe(self):
        while (self.cal_fitness() == False):
            self.permuatation()

def main():
    global START
    TARGET = START.copy()
    TARGET.sort()
    obj = Bogo_Gen(START,TARGET)
    obj._exe()

main()
