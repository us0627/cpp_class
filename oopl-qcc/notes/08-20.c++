// -----------
// Tue, 20 Aug
// -----------

/*
N 450C

Canvas
    ask and answer questions
    please be proactive
*/

int i = ...;

Tiger x(...);
Mammal& r = x;

Tiger y(...);
y = x;
y = r;        // no		mn:Assigning mammal reference to tiger

Mammal m(...);
Tiger& s = m;  // no		mn:Assigning mammal to tiger reference
y = m;    //		mn:Assigning tiger to mammal

int i = 2;
int j = i;

domain_error x("abc");
string s = x.what();   // this is misleading
char*  a = x.what();

/*
vector manages an array
that is usually larger than what's needed
and keeps its elements at the front of the array
cost of adding element
    to the back: O(1), unless full: O(n)
    to the front/middle: O(n)
cost of removing element
    to the back: O(1)
    to the front/middle: O(n)
cost of indexing
    O(1)
*/

vector<int> x(10, 2);
int& r = x[5];
x.push_back(3);
cout << r;            // no		mn: when vectors grow, it clears the old spaces and starts with new space, so referrences will die.

deque<int> x(10, 2);
int& r = x[5];
x.push_back(3);
cout << r;            // ok		mn: deque grows vertically and horizontally.

int  i = 2;
int  j = i;
int& r = i;

// meaning of const

int i; // does not have to be initialized
i = 2;
++i;

const int ci;     // no
const int ci = 2; // has to be initialized
++ci;             // no

// pointer, read/write device, can not point to constants

int  i = 2;
int* p;
p = &i;
++*p

const int ci = 2;
int*      p  = &ci; // no		mn: Why would you need this, you would immediately do ++*pi, so they (people who wrote the standards) said no

// pointer to constant, read only device, can point to constants and non-constants

const int ci = 2;
const int cj = 3;
const int* pc;    // pointer to constant, read only device
pc = &ci;
pc = &cj;
++*pc;            // no
cout << *pc;

int i = 2;
pc = &i;

// constant pointer, read/write device, can not point to constants
// the pointer itself, must be initialized, and can't change later

const int  ci = 2;
int* const cp;       // no, must be initialized
int* const cp = &ci; // no
int i = 2;
int* const cq = &i;
int j = 3;
cq = &j;             // no

int* const a = new int[10];
...
++a;         // no
delete [] a;

// constant pointer to constant

const int* const cpc;       // no
const int        ci  = 2;
const int* const cpc = &ci;
++*cpc;                     // no
int              i   = 2;
const int* const cqc = &i;

// reference, read/write device, most like int* const

int& r;     // no
int  i = 2;
int& r = i;
r = 3;

// reference to constant, read-only device, most like const int* const

const int ci = 2;
int&      s  = ci; // no

const int& r;        // no
const int  ci = 2;
const int& r  = ci;
r = 3;               // no

int        i = 2;
const int& s = i;

int        i = 2;
const int* p = &i;
int*       q = &i;
++i;
++*p;              // no
++*q;              // ok

int       i;
const int ci = ...;

int a[s];      // O(1)
int a[s] = {}; // O(n)

T a[s];      // O(n)
T a[s] = {}; // O(n)

equal(a + 5, a + 10, b + 15)

/*
the smallest that a could be is 10
the smallest that b could be is 20
*/

int a[] = {2, 3, 4};
int b[] = {2, 3, 4};

bool equal (int* b, int* e, int* c) {
    write a loop

cout << equal(a, a + 3, b); // true; T1 -> int*, T2 -> int*

int  a[] = {2, 3, 4};
long b[] = {2, 3, 4};

bool equal (int* b, int* e, long* c) {
    write a loop

cout << equal(a, a + 3, b); // true; T1 -> int*, T2 -> long*

long a[] = {2, 3, 4};
long b[] = {2, 3, 4};

bool equal (long* b, long* e, long* c) {
    write a loop

cout << equal(a, a + 3, b); // true; T1 -> long*, T2 -> int*

template <typename T1, typename T2>
bool equal (T1* b, T1* e, T2* c) {
    // ...
    }

template <typename T1, typename T2>
struct A {
    int    i;
    double d;
    T1     x;
    T2     y;}

A<int, int>
A<int, long>

deque<int> x(...);
//int* p = &x[0];
//++p;
deque<int>::iterator p = x.begin();
++p;
cout << *p;

list<int> y(...);

template <typename T1, typename T2>
bool equal (T1 b, T1 e, T2 c) {
    // ...
    }

cout << equal(x.begin(), x.end(), y.begin()); // T1 -> deque<int>::iterator, T2 -> list<int>::iteator
cout << equal(begin(x),  end(x),  begin(y));  // T1 -> deque<int>::iterator, T2 -> list<int>::iteator

begin(x) -> x.begin()
end(x)   -> x.end()

/*
when defining algorithm you want to be as undemanding as possible
when defining a container you want to be as accommodating as possible
*/

template <typename II1, typename II2>
bool my_equal (II1 b, II1 e, II2 c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

/*
iterator concepts

what operations does II1 need:
!=
++
* (read-only)
copyable

what operations does II2 need:
++
* (read-only)
copyable

input iterator
*/

template <typename II, typename OI>
OI my_copy (II b, II e, OI x) {
    while (b != e) {
        *x = *b;
        ++b;
        ++x;}
    return x;}

/*
what operations does OI need:
++
* (write only)
copyable

output iterator
*/

template <typename FI, typename T>
void my_fill (FI b, FI e, const T& v) {
    while (b != e) {
        *b = v;
        ++b;}}

/*
what operations does FI need:
!=
++
* (read/write only)
copyable

forward iterator
*/

/*
what operations does BI need:
!=
++
--
* (read/write only)
copyable

bidirectional iterator
*/

/*
what operations does RI need:
!=
++
--
* (read/write only)
copyable
[]
<
>
<=
>=
+ int
- int
-

random access iterator
*/

for (auto v : a)
    s += v;

auto b = begin(a);
auto e = end(a);
while (b != e) {
    auto v = *b;
    s += v;
    ++b;}

struct A { // by default everything is public
    ...};

class A {  // by default everything is private
    ...};

/*
this is a convention, not a rule
if everything is public, use struct
otherwise, use class
*/

template <typename T>
class A {}

class A {
    A () {}             // default constructor

    A (A        rhs) {} // no
    A (A&       rhs) {} // no
    A (const A& rhs) {} // copy constructor

    A& operator = (const A& rhs) {return *this;} // copy assignment

    ~A () {}};

int main () {
    A x;            // default constructor

    A y = x;        // copy    constructor
    A y(x);         // copy    constructor
    A y{x};         // copy    constructor

    x = y;          // copy    assignment
    x.operator=(y); // copy    assignment

    A z;
    (x = y) = z;

    return 0;} // destructor runs on x, y, and z
