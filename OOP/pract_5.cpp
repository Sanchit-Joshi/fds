//Problem Statement: Implement a function template for selection sort.Write a program that inputs,
//sorts and outputs an intger array and a float array
#include<iostream>

using namespace std;




template <class T>
void selection_sort( T *array, int n){



    int i,j,min;
    T temp;

    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(array[j]<array[min])
            min=j;
        }

        temp=array[i];
        array[i]=array[min];
        array[min]=temp;

    }


    cout<<"\n\n Array after sorting: ";
    for(int i=0;i<n;i++){
            cout<<array[i]<<"\t";
        }
}

int main(){
    int ch;
    int n;
    int *s1 = NULL;
    float *s2 = NULL;
    cout<<"Welcome\n"<<"1.Enter Integers\n"<<"2.Enter Float numbers\n"<<"3.exit\n\n"<<"Enter choice: ";
    cin>>ch;
    switch(ch) {
        case 1:
            
            cout << "Enter number of elements: ";
            cin >> n;
            s1= new int[n];
            for(int i = 0; i < n; i++) {
                cin >> s1[i];
            }
            selection_sort<int>(s1 , n);
            delete[] s1;
            break;

        case 2:

            cout << "Enter number of elements: ";
            cin >> n;
            s2 = new float[n];
            for(int i = 0; i < n; i++) {
                cin >> s2[i];
            }
            selection_sort<float>(s2 , n);
            delete[] s2;
            break;
        
        case 3:
            exit(0);
            break;

        

    }
    return 0;

}
