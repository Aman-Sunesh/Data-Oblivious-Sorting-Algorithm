#include <iostream>
#include <algorithm>

#include "secret.h"

using namespace std;


void secret_sort(std::vector<Secret> & arr)
{
// ...
}

void shuffle(std::vector<Secret> & arr)
{
    int n = (int)arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if ( arr[j + 1] ^ arr[j] )
                std::swap(arr[j], arr[j + 1] );
}

void test()
{
    auto phrase = encrypt("Some phrase");
    cout << decrypt(phrase) << '\n';
    shuffle(phrase);
    cout << decrypt(phrase) << '\n';
    secret_sort(phrase);
    cout << decrypt(phrase) << '\n';
}
/* this function outputs:
Some phrase
***********
Some phrase
*/


int main()
{
    std::vector<uint> shuffled = { 285518085, 352427273, 687915277, 772094988, 973324812,
                               1023617548, 1023617548, 1375820812, 1996510979, 2046984461, 2164405007,
                               2181047308, 2248146956, 3322173964, 3506702083, 3657463820, 3657463820,
                               3691114251, 3691134731, 3691134731, 3691330311, 3808498700, 3808498700,
                               3892499980, 3926193676, 4060310279
                             };

    auto secret = import_vec(shuffled);

    secret_sort(secret);

    cout << decrypt(secret) << '\n';
}
