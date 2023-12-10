def create_arr():
	arr=[]
	n=int(input("Enter number of students"))
	for i in range(n):
		ele=int(input())
		arr.append(ele)
		
	return arr
	
def insertion_sort(arr):
	n = len(arr)
	for i in range(1,n):
		key = arr[i]
		j = i-1
		while j>=0 and key<arr[j]:
			arr[j+1] = arr[j]
			j-=1
		arr[j+1] = key
	return arr

	
def shell_sort(arr):
    n = len(arr)
    interval = n // 2

    while interval > 0:
        for i in range(interval, n):
            temp = arr[i]
            j = i
            while j >= interval and arr[j - interval] > temp:
                arr[j] = arr[j - interval]
                j -= interval
            arr[j] = temp

        interval //= 2

    return arr

print("-------WELCOME--------")
print("Enter unsorted list")

stud=[58,62,45,78,23,59,68,45,18,23]
print(stud)

print("\n 1. Insertion sort \n 2. Top 5 scores using Shell sort")
ch=int(input("Enter your choice"))

if ch==1:
	print(insertion_sort(stud))
	
elif ch==2:
	arr = shell_sort(stud)
	print("Sorted array: ",arr)
	print("Top 5 scores")
	print(arr[-5:])
	
else:
	print("Invalid choice")
	