def create_arr():
	arr=[]
	n=int(input("Enter number of students: "))
	print("Enter the roll no. of",n,"students : ")
	for i in range(n):
		ele=int(input())
		arr.append(ele)
		
	return arr
		
def linear_search(arr , x):
	
	flag=False
	for i in range(len(arr)):
		if arr[i]==x:
			flag = True
			
	if flag:
		print("Present")
	else:
		print("Absent")

def sentinal_search(arr,x):
	n=len(arr)
	last=arr[n-1]
	
	arr[n-1]=x
	i=0
	while (arr[i]!=x):
		i+=1
	
	arr[n-1]=last
	
	if ((i < n - 1) or (arr[n - 1] == x)):
		print("Present")
	else:
		print("Absent")
			

attendance= create_arr()
print(attendance)
x=int(input("Enter roll no. to be searched"))

print("1.Linear Search \n 2.Sentinal Search ")
ch=int(input("Enter your desired search"))

if ch == 1:
	print(" searching using Linear Search")
	linear_search(attendance , x)
elif ch==2:
	print(" searching using Sentinal Search")
	sentinal_search(attendance , x)

	
else:
	print("invalid choice")
