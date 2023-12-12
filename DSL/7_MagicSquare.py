def magic_square(n):
    #creating a zero matrix of size n*n
    matrix = [[0 for x in range(n)] for y in range(n)]
     #initializing the position of i and j 
    
    i = n//2
    j=n-1

    num =1 
    #filling the matrix with numbers
    while num <= (n*n):
        if i==-1 and j==n:
            i=0
            j=n-2
        else:
            if i<0:
                i=n-1
            if j==n:
                j=0
        if matrix[i][j]!=0:
            i=i+1
            j=j-2
            continue
        else:
            matrix[i][j]=num
            num+=1
        i=i-1
        j=j+1
    #printing the matrix
    print("Magic Square for n =",n)
    print("Sum of each row or column",n*(n**2+1)/2)
    for i in range(n):
        for j in range(n):
            print(matrix[i][j],end=" ")
        print()

n=int(input("Enter the size of the magic square: "))
magic_square(n)
