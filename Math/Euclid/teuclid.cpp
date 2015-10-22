#include "teuclid.h"

TEuclid::TEuclid()
{
}

long TEuclid::Gcd(long a, long b)
{
    if(b==0)
        return a;
    else
    {
        long c=a%b;
        return     Gcd(b,c);
    }

}
