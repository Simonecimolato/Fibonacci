//
//  main.cpp
//  Simonacci
//
//  Created by Simone Cimolato on 18/12/16.
//  Copyright © 2016 Simone Cimolato. All rights reserved.
//
//  Use this code, but do not redistribuite it.
//

#include <iostream>
using namespace std;

/*
 ** Using documented GCC type unsigned __int128 instead of undocumented
 ** obsolescent typedef name __uint128_t.  Works with GCC 4.7.1 but not
 ** GCC 4.1.2 (but __uint128_t works with GCC 4.1.2) on Mac OS X 10.7.4.
 */
typedef __int128 int128_t;

/*      UINT64_MAX 18446744073709551615ULL */
#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19

#define STRINGIZER(x)   # x
#define TO_STRING(x)    STRINGIZER(x)

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}



int main(int argc, const char * argv[]) {
    
    short int terms;
    
    cout<<"How many terms? ";
    cin>>terms;
    
    __int128 num1 = 1;
    __int128 num2 = 0;
    
    for (int i = 0; i < terms; i++){
        num1 += num2;
        cout<<num1<<endl;
        num2 += num1;
        cout<<num2<<endl;
    }
    return 0;
}
