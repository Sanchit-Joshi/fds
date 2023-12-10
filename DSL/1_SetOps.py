def remove_duplicates(lst):
    list1=[]
    for val in lst:
        if val not in list1:
            list1.append(val)
    return list1

#intersection 
def intersection(list1,list2):
    list3=[]    
    for x in list1:
        if x in list2:
           list3.append(x)
    return list3
#union
def union(list1,list2):
    list3=list1.copy()
    for x in list2:
        if x not in list3:
            list3.append(x)
    return list3

#difference
def difference(list1,list2):
    list3=[]
    for x in list1:
        if x not in list2:
            list3.append(x)
    return list3
#symm_diff
def symm_diff(list1,list2):
    list3=union(difference(list1,list2),difference(list2,list1))
    return list3


#input all students
stud=[]
n = int(input("Enter number of students in the class: "))
print("Enter the names of",n,"students :")
for i in range(0, n):
    val = input()
    stud.append(val) 
print(remove_duplicates(stud))

#input cricket students
c=[]
n = int(input("Enter number of students playing cricket: "))
print("Enter the names of",n,"students :")
for i in range(0, n):
    val = input()
    c.append(val) 
cricket=remove_duplicates(c)


#input badminton students
b=[]
n = int(input("Enter number of students playing badminton: "))
print("Enter the names of",n,"students :")
for i in range(0, n):
    val = input()
    b.append(val) 
badminton=remove_duplicates(b)


#input badminton students
f=[]
n = int(input("Enter number of students playing football: "))
print("Enter the names of",n,"students :")
for i in range(0, n):
    val = input()
    f.append(val) 
football=remove_duplicates(f)



print("-----------------------------------------")
print("a. list of students who play both cricket and badminton:")
print(intersection(cricket,badminton))
print("\n b. list of students who play either cricket or badminton but not both:")
print(symm_diff(cricket,badminton))
print("\n c.number of students who play neither cricket nor badminton:")
print(len(difference(football,union(cricket,badminton))))
print("\n d. number of students who play cricket and football but not badminton")
print(len(difference(intersection(cricket,football),badminton)))
