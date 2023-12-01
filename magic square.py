

def magic_square(n):

	#creating a matrix with all entries zero
	matrix=[ [0 for x in range(n)] for y in range(n)]
	
	#initiating position of 1 at (n/2,n-1)
	i = n / 2
	j = n - 1
	# Filling the matrix 
	num = 1
	while num <= (n * n): 
		if i == -1 and j == n: 
	    		j = n - 2
		    	i = 0
		else:  
			  
			if j == n: 
				j = 0    
			
			if i < 0: 
				i = n - 1
		if matrix[int(i)][int(j)]: 
		    j = j - 2
		    i = i + 1
		    continue
		else: 
		    matrix[int(i)][int(j)] = num 
		    num = num + 1
		
		
		j = j + 1
		i = i - 1 
		
			
		#printing the matrix:
	for i in range(0, n): 
		for j in range(0, n): 
    			print((matrix[i][j]),end = ' ') 
		#breaking line after each row
		if j == n - 1:  
			print()	
			
n=int(input("Enter size of magic square: "))
magic_square(n)


    

