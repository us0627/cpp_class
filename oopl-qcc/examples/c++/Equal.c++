// ---------
// Equal.c++
// ---------

// https://en.cppreference.com/w/cpp/algorithm/equal

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

using namespace std;

void test0 () {
    const int  ia[] = {2, 3, 4};
    const int  ib[] = {0, 2, 3, 4, 0};
    const int* b    = begin(ia);
    const int* e    = end(ia);
    const int* c    = begin(ib) + 1;
    assert(equal(b, e, c));}

void test1 () {
    const list<int>             ix = {2, 3, 4};
    const vector<int>           iy = {0, 2, 3, 4, 0};
    list<int>::const_iterator   b  = begin(ix);
    list<int>::const_iterator   e  = end(ix);
    vector<int>::const_iterator c  = begin(iy) + 1;
    assert(equal(b, e, c));}

int main () {
    cout << "Equal.c++" << endl;
    test0();
    test1();
    cout << "Done." << endl;
    return 0;}
