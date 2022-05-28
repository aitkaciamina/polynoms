#include <iostream>
#include"Polynoms.h"
using namespace std;

int main()
{
    Polynoms p1;
    p1.enter_terms();
    cout<<endl;
    p1.display();
    Polynoms p2;
    cout<<endl;
    p2.enter_terms();
    p2.display();
    Polynoms p3;
    p3=p1+p2;
    cout<<endl;
    cout<<" the sum is : ";
    p3.display();
    cout<<" the multiplication is : "<<endl;
    Polynoms p4;
    p4=p1*p2;
    p4.display();
    p2+=p1;
    p2.display();
    Polynoms p5;
    p5.enter_terms();
    p5.display();
    p5*=p1;
    p5.display();
    return 0;
}
