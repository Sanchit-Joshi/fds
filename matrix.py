import numpy

#creating two matrices of same size


rows= int(input("Enter the number of rows:"))
col = int(input("Enter the number of columns:"))
 
 
print("Enter the elements of first matrix row viz: ")
entries = list(map(int, input().split()))
x = numpy.array(entries).reshape(rows, col)

print("Enter the elements of second matrix row viz: ")
entries = list(map(int, input().split()))
y = numpy.array(entries).reshape(rows, col)

ch="y"
while ch=="y":
	print("Enter your choice number")
	print("1. Addition of matrices")
	print("2. Subtraction of matrices")
	print("3. Product of matrices")
	print("4. Transpose of first matrix")
	print("5. Transpose of second matrix")
	
	opt = int(input())
	
	if opt==1:
		print("The addition of matrices is : ")
		print(numpy.add(x, y))
		
	elif opt==2:
		print("The subtraction of matrices is : ")
		print(numpy.subtract(x, y))
	
	elif opt==3:
		print ("The product of matrices is : ")
		print (numpy.dot(x,y))
	
	elif opt==4:
		print("The transpose of first matrix is : ")
		print(x.T)

	
	elif opt==5:
		print("The transpose of given matrix is : ")
		print(y.T)

		
	else:
		print("Invalid choide")
		
	print("Continue?     *y/n*")
	ch=input()
	
	
	
	

