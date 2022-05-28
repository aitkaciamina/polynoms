#ifndef POLYNOMS_H
#define POLYNOMS_H


class Polynoms
{
public:
    Polynoms ();
    void enter_terms();
    Polynoms operator+ (const Polynoms & p);
    const Polynoms operator= (const Polynoms &p);
    Polynoms operator* (const Polynoms &p);
    void display();
    Polynoms operator+= (const Polynoms &p);
    Polynoms operator*= (const Polynoms& p);
private :
    int exp[100];
    int coef[100];
    Polynoms polynomial_combine();
};

#endif // POLYNOMS_H
