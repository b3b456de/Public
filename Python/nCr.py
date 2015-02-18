#Calculates the binomial coefficient
#Using a more efficient algorithm than

raw = input("Enter n,k: ")
x = raw.split()
c = int(x[0])
r = int(x[1])

def nCr(n,k):
    coef,i = 1,1
    while i <= k:
        coef = coef*(n+1-i)/i
        i+=1
    return coef

print(nCr(c,r))
