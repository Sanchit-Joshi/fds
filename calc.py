def add(a,b):
	return a+b

def sub(a,b):
	return a-b
	
def mul(a,b):
	return a*b
	
def div(a,b):
	return a/b
ch= "y"

while ch=="y":

	print("---Calculator---")
	print("1.Addition")
	print("2.Subtraction")
	print("3.Multiplication")
	print("4.Division")
	c=int(input("Enter your choice Operation"))
	a=int(input("Enter first number"))
	b=int(input("Enter second number"))

	if c==1:
		print(add(a,b))

	elif c==2:
		print(sub(a,b))

	elif c==3:
		print(mul(a,b))
		
	elif c==4:
		print(div(a,b))
		
	else:
		print("Invalid Choice")
		
	ch=input("Continue? y/n")

