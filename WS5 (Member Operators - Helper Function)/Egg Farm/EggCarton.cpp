#define _CRT_SECURE_NO_WARNINGS
#include "EggCarton.h"
#include "iostream"
using namespace std;

namespace sdds {
    EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize)
    {
        if ((size % 6 == 0) && size >= 6 && size <= 36 && noOfEggs >= 0 && noOfEggs <= size )
        {
            cartoonSz = size;
            eggsNum = noOfEggs;
            isJumbo = jumboSize;
        }
        else
        {
            setBroken();
        }
    }

    std::ostream& EggCarton::display(std::ostream& ostr) const
    {
        displayCarton(cartoonSz, eggsNum, isJumbo, ostr);
        return ostr;
    }

    void EggCarton::setBroken()
    {
        cartoonSz = -1;
        eggsNum = -1;
    }
    
    std::ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, std::ostream& ostr)const {
        int cartonWidth = size == 6 ? 3 : 6;
        for (int i = 0; i < size; i++) {
            ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
            ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
        }
        if (size < 0)
        {
            cout << "Broken Egg Carton!";
            cout << endl;
        }
        return ostr;
    }

    int EggCarton::getEggsNum() const
    {
        return eggsNum;
    }

    istream& EggCarton::read(istream& istr )
    {
        char jFlag;
        int szCarton;
        int numEggs;

        cin >> jFlag;
        if (jFlag == 'j')
        {
            isJumbo = true;
        }
        else
        {
            isJumbo = false;
        }

        cin.ignore();
        cin >> szCarton;
        cin.ignore();
        cin >> numEggs;

        if ((szCarton % 6 == 0) && szCarton >= 6 && szCarton <= 36 && numEggs >= 0 && numEggs <= szCarton)
        {
            cartoonSz = szCarton;
            eggsNum = numEggs;
        }
        else
        {
            setBroken();
        }

        return istr;
        
    }

    // Type Conversion Operator overloads

   EggCarton::operator bool() const
    {
        return (cartoonSz > 0 ? true : false);
    }

    EggCarton::operator int() const
    {
        return (*this ? eggsNum : -1);
    }

    EggCarton::operator double() const
    {
        double totalW = -1.0;

        if (*this && isJumbo)
        {
            totalW = (double(eggsNum) * JumboEggWieght) / 1000.0;
        }
        else if (*this && !isJumbo)
        {
            totalW = (double(eggsNum) * RegularEggWieght)/1000.0;
        }
        
        return totalW;
    }

    //Unary Operator overloads :

    // prefix operator
    EggCarton& EggCarton::operator--() 
    {
        if (*this && eggsNum > 0)
        {
            eggsNum--;
        }
        return *this;
    }

    //prefix operator
    EggCarton& EggCarton::operator++()
    {
        if (*this)
        {
            eggsNum++;

            if (eggsNum > cartoonSz)
            {
                setBroken();
            }
        }
        return *this;
    }

    EggCarton temp;
    // postfix operator
    EggCarton& EggCarton::operator--(int) 
    {
        temp = *this;

        --(*this);

        return temp;        
    }
 
    //postfix operator 
    EggCarton& EggCarton::operator++(int) 
    {
        temp = *this;
        
        ++(*this);

        return temp;
    }

    //Binary Member Operators

    EggCarton& EggCarton::operator=(int eggsNum)
    {
        this->eggsNum = eggsNum;

        if (this->eggsNum > cartoonSz)
        {
            setBroken();
        }

        return *this;
    }

    EggCarton& EggCarton::operator+=(int eggsNum) 
    {
        if (*this)
        {
            this->eggsNum += eggsNum;

            if (this->eggsNum > cartoonSz)
            {
                setBroken();
            }
        }

        return *this;
    }

    EggCarton& EggCarton::operator+=(EggCarton& right)
    {
        int emptySpots;

        if (*this)
        {
            emptySpots = cartoonSz - this->eggsNum;

            if (emptySpots > 0)
            {
                if (right.eggsNum > emptySpots) {
                    *this += emptySpots;
                    right.eggsNum -= emptySpots;
                } 
                else if (right.eggsNum <= emptySpots)
                {
                    *this =+ right.eggsNum;
                    right.eggsNum = 0;
                }
            }
        }
        return *this;
    }

    bool EggCarton::operator==(const EggCarton& right) const
    {
        double w1, w2;
        bool check = false;

        if (this->isJumbo)
        {
            w1 = (double(eggsNum) * JumboEggWieght)/1000.0;
        }
        else
        {
            w1 = (double(eggsNum) * RegularEggWieght)/1000.0;
        }
        
        if (right.isJumbo)
        {
            w2 = (double(eggsNum) * JumboEggWieght)/1000.0;
        }
        else
        {
            w2 = (double(eggsNum) * RegularEggWieght)/1000.0;
        }
     
        if (w1 - w2 > -0.001 && w1 - w2 < 0.001)
        {
            check = true;
        }

        return !check;
    }


    // Helper Binary Operator Overload

    int operator+(int left, const EggCarton& right)
    {
        
        return (right ? left + right.getEggsNum() : left);

    }

    std::ostream& operator<<(std::ostream& ostr, const EggCarton& right)
    {
        right.display();

        return ostr;
    }

    std::istream& operator>>(std::istream& istr, EggCarton& right)
    {
        right.read(istr);

        return istr;
    }

}