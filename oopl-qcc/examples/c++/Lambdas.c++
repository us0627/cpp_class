// -----------
// Lambdas.c++
// -----------

#include <algorithm> // transform
#include <cassert>   // assert
#include <cmath>     // pow
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

using namespace std;

void test0 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    auto                      f = [] (int x) -> int {return pow(x, 2);};
    vector<int>::iterator     p = transform(b, e, x, f);
    assert(p == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}

void test1 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    int                       n = 2;
    auto                      f = [n] (int x) -> int {return pow(x, n);};
    ++n;
    vector<int>::iterator     p = transform(b, e, x, f);
    assert(p == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}

void test2 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    int                       n = 1;
    auto                      f = [&n] (int x) -> int {return pow(x, n);};
    ++n;
    vector<int>::iterator     p = transform(b, e, x, f);
    assert(p == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}

int main () {
    cout << "Lambdas.c++" << endl;
    test0();
    test1();
    test2();
    cout << "Done." << endl;
    return 0;}
