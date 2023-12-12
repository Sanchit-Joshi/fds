#average of marks
def avg(list1):
	cnt=0
	sum=0
	for i in range(len(list1)):
		if list1[i] > -1:
			sum = sum+ list1[i]
			cnt+=1
	
	avg=sum/cnt
	return ("Average marks of the class are ",avg)
	
#highest marks
def highest_marks(list1):
	max=0
	for i in range(len(list1)):
		if list1[i]>max:
			max=list1[i]

	return ("Highest marks in the class are ",max)

#lowest marks
def lowest_marks(list1):
	min=999
	for i in range(len(list1)):
		if list1[i] != -1:	
			if list1[i] < min:
				min=list1[i]
	
	return ("Lowest marks in the class are ",min)
	
#absent students
def absent(list1):
	cnt=0
	for i in range(len(list1)):
		if list1[i] ==  -1 :
			cnt+=1
	return ("Number of absent students is: ",cnt)
	
#most frequents marks
def freq_marks(list1):
    i=0
    Max=0
    print("marks frequency cout :")
    for x in list1:
        if list1.index(x)==i:
            print(x," : ",list1.count(x))
            if list1.count(x) > Max:
                Max=list1.count(x)
                marks=x
        i+=1
    return ( "Most frequent --> " + str(marks) +"  :  "+  str(Max) )
	

#input marks of all students
marks=[]
n = int(input("Enter number of students in the class: "))
print("Enter the marks of",n,"students :   *enter -1 if student was absent*")
for i in range(0, n):
    val = int(input())
    marks.append(val) 
   
print(marks)


print("Class report for subject 'Fundamentals of Data Structure': ")

ch="y"
while ch=="y":
	print("Enter your choice number")
	print("1. Average marks of the class")
	print("2. Highest marks in the class")
	print("3. Lowest marks in the class")
	print("4. Number of Absent students")
	print("5. Most frequent marks in the class")
	
	opt = int(input())
	
	if opt==1:
		print(avg(marks))
		
	elif opt==2:
		print(highest_marks(marks))
	
	elif opt==3:
		print(lowest_marks(marks))
	
	elif opt==4:
		print(absent(marks))
	
	elif opt==5:
		print(freq_marks(marks))
		
	else:
		print("Invalid choide")
		
	print("Continue?     *y/n*")
	ch=input()
