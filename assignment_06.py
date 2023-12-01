from datetime import datetime
#list of A div
list_A=[[346,'9/8/2004'],[345,'8/7/2004'],[365,'7/9/2004']]
list_B=[]


print(sorted(list_A, key=lambda x: x[1]))
'''def sort_dob(lst):
   
    n = len(lst)
     
    for i in range(0, n):
        for j in range(0, n-i-1):
             
            if (lst[j][1] > lst[j + 1][1]):
                temp = lst[j]
                lst[j] = lst[j + 1]
                lst[j + 1] = lst
     
    return lst
'''  
    
'''def sort_dob( list1):
    
    for i in range(1,len(list1)):
        new_list = list1[i][1]
        print(new_list)
        j = i - 1 
        
        y = datetime.strptime(list1[j][1],"%d/%m/%Y")
        z = datetime.strptime(new_list,"%d/%m/%Y")
        while j >= 0 and y > z:
            list1[j+1] = list1[j]
            j-=1
            break
        else:
            list1[j+1][1] = list1
        
    print(list1)
    
print(sort_dob(list_A))
'''
