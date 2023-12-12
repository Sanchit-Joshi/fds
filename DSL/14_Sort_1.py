def create_arr():
	arr=[]
	n=int(input("Enter number of students"))
	for i in range(n):
		ele=int(input())
		arr.append(ele)
		
	return arr
	
def bubble_sort(arr):
	n=len(arr)
	for i in range(0,5):
		for j in range(n-1-i):
			if arr[j]>arr[j+1]:
				temp=arr[j]
				arr[j]=arr[j+1]
				arr[j+1]=temp
	return arr
	
def selection_sort(arr):
	n = len(arr)
	for i in range(n-1):
		min = i
		for j in range(i+1,n):
			if arr[j]<arr[min]:
				min =j
		temp = arr[i]
		arr[i] = arr[min]
		arr[min] = temp

	return arr
	
print("-------WELCOME--------")
print("Enter unsorted list")

stud=create_arr()
print(stud)

print("\n 1. Selection sort \n 2. Top 5 scores using Bubble sort")
ch=int(input("Enter your choice"))

if ch==1:
	print(selection_sort(stud))
	
elif ch==2:
	arr = bubble_sort(stud)
	print("Sorted array: ",arr)
	print("Top 5 scores")
	print(arr[-5:])

else:
	print("Invalid choice")