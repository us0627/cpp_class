// ---------
// CopyT.c++
// ---------

// https://en.cppreference.com/w/cpp/algorithm/copy

#include <cstdio>

#include <algorithm>  // copy, equal
#include <functional> // function
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename II, typename OI>
OI my_copy (II b, II e, OI x) {
    while (b != e) {
        *x = *b;
        ++b;
        ++x;}
    return x;}

using CopyArraySignature = function<int*                  (const int*,                const int*,                int*)>;
using CopyListSignature  = function<vector<int>::iterator (list<int>::const_iterator, list<int>::const_iterator, vector<int>::iterator)>;

struct CopyArrayFixture : TestWithParam<CopyArraySignature>
    {};

struct CopyListFixture : TestWithParam<CopyListSignature>
    {};

INSTANTIATE_TEST_CASE_P(
    CopyArrayInstantiation,
    CopyArrayFixture,
    Values(
           copy<const int*, int*>,
        my_copy<const int*, int*>),);

INSTANTIATE_TEST_CASE_P(
    CopyListInstantiation,
    CopyListFixture,
    Values(
           copy<list<int>::const_iterator, vector<int>::iterator>,
        my_copy<list<int>::const_iterator, vector<int>::iterator>),);

TEST_P(CopyArrayFixture, test0) {
    const int  ia[]  = {2, 3, 4};
    int        ob[5] = {};
    const int* b     = begin(ia);
    const int* e     = end(ia);
    int*       x     = begin(ob) + 1;
    int*       p     = GetParam()(b, e, x);
    ASSERT_EQ(p, begin(ob) + 4);
    ASSERT_TRUE(equal(begin(ob), end(ob), begin({0, 2, 3, 4, 0})));}

TEST_P(CopyListFixture, test1) {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    vector<int>::iterator     p = GetParam()(b, e, x);
    ASSERT_EQ(p, begin(oy) + 4);
    ASSERT_TRUE(equal(begin(oy), end(oy), begin({0, 2, 3, 4, 0})));}
