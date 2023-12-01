def create_arr():
	arr=[]
	n=int(input("Enter number of students"))
	for i in range(n):
		ele=int(input())
		arr.append(ele)
		
	return arr
	
def r_binary_search(arr,high,low,x):
	
	mid = low + (high - low)//2
	if high>=low:
		
		if arr[mid]==x:
			return mid
		elif x < arr[mid]:
			return r_binary_search(arr, low , mid+1 , x)
		
		else:
			return r_binary_search(arr, mid-1 , high , x)
	else:
		return -1

def i_binary_search(arr,high,low,x):
	mid = low + (high - low)//2
	if high>=low:
		
		if arr[mid]==x:
			return mid
		elif x < arr[mid]:
			low = mid+1
		
		else:
			high = mid-1
	else:
		return -1


def fibonacci_search(arr , n , x):
	f1=0
	f2=1
	f3=f1+f2
	offset=-1
	while(f3<n):
		f1=f2
		f2=f3
		f3=f1+f2
	while(f3>1):
		i=min(offset+f1,n-1)
		if(arr[i]==x):
			return i
		else:
			if(x<arr[i]):
				f3=f1
				f2=f2-f1
				f1=f3-f2
			else:
				f3=f2
				f2=f1
				f1=f3-f2
				offset=i
	
	if(f2==1 and (offset+1)<n and arr[offset+1]==x):
		return offset+1
	else:
		return -1
	
	
	
attendance= [1,2,3,4,5]
print(attendance)
x=int(input("Enter roll no. to be searched"))

print(" 1.Recursive Binary Search \n 2. Iterative Binary Search \n 3. Fibonacci Search")
ch = int(input("Enter your desired choice"))

if ch==1:
	print(" searching using Reccursive Binary Search")
	high = len(attendance)
	low=0
	result= r_binary_search(attendance , high , low , x)
	if result != -1:
        	print("Present")
	else:
		print("Absent")
        	
        	
elif ch==2:
	print(" searching using Iterative Binary Search")
	high = len(attendance)
	low=0
	result= i_binary_search(attendance , high , low , x)
	if result != -1:
        	print("Present")
	else:
		print("Absent")
elif ch==3:
	print(" searching using Fibonacci Search")
	result = fibonacci_search(attendance,len(attendance),x)
	if result == -1:
		print("Absent")
	else:
		print("Present")
	
else:
	print("Invalid choice")
