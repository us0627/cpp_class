// --------
// Fill.c++
// --------

// https://en.cppreference.com/w/cpp/algorithm/fill

#include <algorithm> // equal, fill
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list

using namespace std;

void test0 () {
    int  a[5]   = {};
    int* b      = begin(a) + 1;
    int* e      = end(a)   - 1;
    const int v = 2;
    fill(b, e, v);
    assert(equal(begin(a), end(a), begin({0, 2, 2, 2, 0})));}

void test1 () {
    list<int>           x(5);
    list<int>::iterator b = begin(x);
    list<int>::iterator e = end(x);
    const int           v = 2;
    ++b;
    --e;
    fill(b, e, v);
    assert(equal(begin(x), end(x), begin({0, 2, 2, 2, 0})));}

int main () {
    cout << "Fill.c++" << endl;
    test0();
    test1();
    cout << "Done." << endl;
    return 0;}
