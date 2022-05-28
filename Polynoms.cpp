#include "Polynoms.h"
#include <iostream>
using namespace std;
Polynoms Polynoms:: polynomial_combine()
    {

        for (int i=0 ; i<100; i++)
        {
            for(int j=i+1 ; j<100 ; j++)
            {
                if(exp[i]==exp[j])
                {
                    coef[i]+=coef[j];
                    coef[j]=0;

                }
            }
        }
        return (*this);
    }
 Polynoms::Polynoms ()
    {
        for (int k=0 ;k<100; k++)
        {
            exp[k]=-1;
            coef[k]=0;
        }
    }
void Polynoms::enter_terms()
    {
        int temp;

        int n ;
        cout<<" enter the number of terms : ";
        cin>>n;
        for (int i=0 ; i<n ; i++)
        {
            cout<<" exponent : ";
            cin>>exp[i];
        }
         for (int i=0 ; i<n ;i++)
         {
             for(int j=i+1; j<n; j++)
             {
                 if(exp[i]<exp[j])
                 {
                     temp=exp[j];
                     exp[j]=exp[i];
                     exp[i]=temp;
                 }
             }
         }

    cout<<" the coefficients : "<<endl;
    for(int i=0 ; i<n ; i++)
    {
        cout<<" the coefficient of the term  "<<exp[i]<<"  :  ";
        cin>>coef[i];
    }
}
void  Polynoms::display()
{
    for (int i =0 ;exp[i]!=-1 ; i++)
    {
        if(coef[i]!=0)
            cout<<" + "<<coef[i]<<" * x ^ "<<exp[i];
    }
}
Polynoms  Polynoms::operator+ (const Polynoms & p)
{
    int s=0, l=0, d;
    for(int i=0 ; i<100; i++)
    {
        if(exp[i]!=-1)
            s++;
    }
    for(int i=0 ; i<100; i++)
    {
        if(p.exp[i]!=-1)
            l++;
    }

    Polynoms res;
    if(p.exp[0]==exp[0])
    {
        for(int i=0; i<s; i++)
        {
        res.coef[i]=coef[i]+p.coef[i];
        res.exp[i]=exp[i];
        }
        return res;
    }
   else if(exp[0]>p.exp[0])
    {
        for(int i=0; i<s; i++)
        {
            if(exp[i]==p.exp[0])
                d=i;
        }
        for(int i=0 ; i<d; i++)
        {
            res.coef[i]=coef[i];
            res.exp[i]=exp[i];
        }
        for(int i=d; i<=s ; i++)
        {
            res.coef[i]=coef[i]+p.coef[i-d];
            res.exp[i]=exp[i];
        }
        return res;
    }
    else if (exp[0]<p.exp[0])
    {
        for(int i=0; i<l; i++)
        {
            if(exp[0]==p.exp[i])
                d=i;
        }
        for(int i=0 ; i<=d; i++)
        {
            res.coef[i]=p.coef[i];
            res.exp[i]=p.exp[i];
        }
        for(int i=d; i<=s ; i++)
        {
            res.coef[i]=coef[i-d]+p.coef[i];
            res.exp[i]=p.exp[i];
        }
        return res;
    }
}
const Polynoms Polynoms::operator= (const Polynoms &p)
{
    for(int i=0 ; i<100; i++)
    {
        exp[i]=p.exp[i];
        coef[i]=p.coef[i];
    }
    return (*this);
}
Polynoms Polynoms::operator* (const Polynoms &p)
{
    Polynoms res;
    int i=1;

    res.exp[0]=-2;
    res.coef[0]=0;
            for(int j=0 ; exp[j]!=-1 ; j++)
            {
                for(int k=0 ; p.exp[k]!=-1 ; k++)
                {
                    res.exp[i]=exp[j]+p.exp[k];
                    res.coef[i]=coef[j]*p.coef[k];
                    i++;
                }
            }


    return res.polynomial_combine();
}
Polynoms Polynoms::operator+= (const Polynoms &p)
{
    int s=0, l=0, d;
    for(int i=0 ; i<100; i++)
    {
        if(exp[i]!=-1)
            s++;
    }
    for(int i=0 ; i<100; i++)
    {
        if(p.exp[i]!=-1)
            l++;
    }

    Polynoms res;
    if(p.exp[0]==exp[0])
    {
        for(int i=0; i<s; i++)
        {
        coef[i]=coef[i]+p.coef[i];
        exp[i]=exp[i];
        }
        return res;
    }
   else if(exp[0]>p.exp[0])
    {
        for(int i=0; i<s; i++)
        {
            if(exp[i]==p.exp[0])
                d=i;
        }

        for(int i=d; i<=s ; i++)
        {
            coef[i]=coef[i]+p.coef[i-d];
            exp[i]=exp[i];
        }
        return res;
    }
    else if (exp[0]<p.exp[0])
    {
        for(int i=0; i<l; i++)
        {
            if(exp[0]==p.exp[i])
                d=i;
        }
        for(int i=0 ; i<=d; i++)
        {
            coef[i]=p.coef[i];
            exp[i]=p.exp[i];
        }
        for(int i=d; i<=s ; i++)
        {
            coef[i]=coef[i-d]+p.coef[i];
            exp[i]=p.exp[i];
        }
        return res;
    }
}
Polynoms Polynoms:: operator*= (const Polynoms& p)
{
            (*this)=(*this)*p;
    return (*this);
}
