// -------------
// Functions.c++
// -------------

#include <cstdio>

#include <algorithm> // transform
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

using namespace std;

int square1 (int v) {
    return v * v;}

void test0 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    auto                      f = square1;
    vector<int>::iterator     p = transform(b, e, x, f);
    assert(p == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}

template <typename T>
T square2 (T v) {
    return v * v;}

void test1 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    auto                      f = square2<int>;
    vector<int>::iterator     p = transform(b, e, x, f);
    assert(p == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}

int main () {
    cout << "Functions.c++" << endl;
    test0();
    test1();
    cout << "Done." << endl;
    return 0;}
