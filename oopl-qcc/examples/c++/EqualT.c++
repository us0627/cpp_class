// ----------
// EqualT.c++
// ----------

// https://en.cppreference.com/w/cpp/algorithm/equal

#include <cstdio>

#include <algorithm>  // equal
#include <functional> // function
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename II1, typename II2>
bool my_equal (II1 b, II1 e, II2 c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

using EqualArraySignature = function<bool (const int*,                const int*,                const int*)>;
using EqualListSignature  = function<bool (list<int>::const_iterator, list<int>::const_iterator, vector<int>::const_iterator)>;

struct EqualArrayFixture : TestWithParam<EqualArraySignature>
    {};

struct EqualListFixture : TestWithParam<EqualListSignature>
    {};

INSTANTIATE_TEST_CASE_P(
    EqualArrayInstantiation,
    EqualArrayFixture,
    Values(
        my_equal<const int*, const int*>,
        my_equal<const int*, const int*>),);

INSTANTIATE_TEST_CASE_P(
    EqualListInstantiation,
    EqualListFixture,
    Values(
        my_equal<list<int>::const_iterator, vector<int>::const_iterator>,
        my_equal<list<int>::const_iterator, vector<int>::const_iterator>),);

TEST_P(EqualArrayFixture, test0) {
    const int  ia[] = {2, 3, 4};
    const int  ib[] = {0, 2, 3, 4, 0};
    const int* b    = begin(ia);
    const int* e    = end(ia);
    const int* c    = begin(ib) + 1;
    ASSERT_TRUE(GetParam()(b, e, c));}

TEST_P(EqualListFixture, test1) {
    const list<int>             ix = {2, 3, 4};
    const vector<int>           iy = {0, 2, 3, 4, 0};
    list<int>::const_iterator   b  = begin(ix);
    list<int>::const_iterator   e  = end(ix);
    vector<int>::const_iterator c  = begin(iy) + 1;
    ASSERT_TRUE(GetParam()(b, e, c));}
