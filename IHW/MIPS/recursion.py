cache = dict()

def fibbo(num_da_sequencia):
    if(num_da_sequencia==1):
        return 1
    if(num_da_sequencia==0):
        return 0
    else:
        if(num_da_sequencia in cache):
            return cache[num_da_sequencia]
        else:
            cache[num_da_sequencia] = fibbo(num_da_sequencia-1)+fibbo(num_da_sequencia-2)
            return cache[num_da_sequencia]
"""
                5
               |  |
              4    3
             | \
            3    2
           / |  | \
          2  1  1  0
"""
def fatorial(num):
    if(num==1):#caso base
        return 1
    else:#como se aproximar dele?
        return num*fatorial(num-1)

print(fibbo(7))
print(fatorial(5))