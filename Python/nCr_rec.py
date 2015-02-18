raw = input("Enter n,k: ")
x = raw.split()
c = int(x[0])
r = int(x[1])

def nCr(n,k):
    return nCr_h(n,k,1)

def nCr_h(n,k,i):
    if i <= k:
        return (n+1-i)/i*nCr_h(n,k,i+1)
    else:
        return 1

print(nCr(c,r))
