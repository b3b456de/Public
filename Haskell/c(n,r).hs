c :: Int -> Int -> Int
c n r = 
	if n == r then 1
	else if r == 0 then 1
	else c (n-1) (r-1) + c (n-1) r

main = 	do
	n <- getInt
	r <- getInt
	print(c 100 3)
