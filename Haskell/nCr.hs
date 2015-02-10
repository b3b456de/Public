main = print(nCr 10 4)

nCr_h n k i = if i <= k then (nCr_h n k (i+1))*(n+1-i)/i else 1

nCr n k = nCr_h n k 1

