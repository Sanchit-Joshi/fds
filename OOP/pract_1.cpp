/* 
Implement a class Complex which represents the Complex Number data type. Implement the following
1.	Constructor (including a default constructor which creates the complex number 0+0i).
2.	Overload operator+ to add two complex numbers.
3.	Overload operator* to multiply two complex numbers.
4.	Overload operators << and >> to print and read Complex Numbers
*/

#include<iostream>
using namespace std;

class Complex{

    private:
    float real,img;
    public:
    Complex(); //default constructor
    friend istream & operator >>(istream &, Complex &); //input
    friend ostream & operator <<(const ostream & , Complex &); //output

    Complex operator + (Complex);//addition
    Complex operator * (Complex);//multiplication

};

Complex::Complex(){
    real=0.0;
    img=0.0;
}

istream & operator >> (istream &, Complex & i){
    cin>>i.real>>i.img;
}

ostream & operator << (const ostream &, Complex & i){
    cout<<i.real<<" + "<<i.img<<"i";
    
}

Complex Complex::operator + (Complex i){
    Complex temp;
    temp.real= real + i.real;
    temp.img = img + i.real;
    return temp;
}

Complex Complex::operator * (Complex i){
    Complex temp;
    temp.real = real*i.real - img*i.img;
    temp.img = real*i.img + img*i.real;
    return temp;
}

int main(){
    Complex c1,c2,c3;
    cout<<"Enter the first complex number: ";
    cin>>c1;
    cout<<c1<<endl;
    cout<<"Enter the second complex number: ";
    cin>>c2;
    cout<<c2<<endl;
    c3=c1+c2;
    cout<<"Sum of the complex numbers: "<<c3<<endl;
    c3=c1*c2;
    cout<<"Product of the complex numbers: "<<c3<<endl;
    return 0;
}