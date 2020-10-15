// --------
// Copy.c++
// --------

// https://en.cppreference.com/w/cpp/algorithm/copy

#include <algorithm> // copy, equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

using namespace std;

void test0 () {
    const int  ia[]  = {2, 3, 4};
    int        ob[5] = {};
    const int* b     = begin(ia);
    const int* e     = end(ia);
    int*       x     = begin(ob) + 1;
    int*       p     = copy(b, e, x);
    assert(p == begin(ob) + 4);
    assert(equal(begin(ob), end(ob), begin({0, 2, 3, 4, 0})));}

void test1 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    vector<int>::iterator     p = copy(b, e, x);
    assert(p == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 2, 3, 4, 0})));}

int main () {
    cout << "Copy.c++" << endl;
    test0();
    test1();
    cout << "Done." << endl;
    return 0;}
