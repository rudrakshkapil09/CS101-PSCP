#include <iostream>
using namespace std;

class Complex{
private:
    double real;
    double imag;
public:
    //constructors
    Complex(){
        real = 0.0;
        imag = 0.0;
    }
    
    Complex(double real, double imag){
        this->real = real;
        this->imag = imag;
    }
    
    //member functions
    void getSum(Complex com1, Complex com2){
        real = com1.real + com2.real;
        imag = com1.imag + com2.imag;
    }
    
    void getDiff(Complex com1, Complex com2){
        real = com1.real - com2.real;
        imag = com1.imag - com2.imag;
    }
    
    void getProd(Complex com1, Complex com2){
        real = com1.real * com2.real - com1.imag * com2.imag;
        imag = com1.real * com2.imag + com1.imag * com2.real;
    }
    
    void Display(){
        cout << real << " + i(" << imag << ")";
        cout << endl;
    }
};

int main()
{
    cout << "\n\n[This is a program that uses a class to carry out complex number operations]\n";
    
    //create two complex members
    Complex a(2.0,0.4);
    Complex b(2.5,0.6);
    Complex res;
    
    cout << "The imaginary numbers are\n";
    a.Display();
    b.Display();
    
    cout << "Addition:\n";
    res.getSum(a, b);
    res.Display();
    
    cout << "Difference:\n";
    res.getDiff(b, a);
    res.Display();
    
    cout << "Product:\n";
    res.getProd(a, b);
    res.Display();
    
    return 0;
}
