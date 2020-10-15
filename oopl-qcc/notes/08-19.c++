// -----------
// Mon, 19 Aug
// -----------

/*
N 450C

Canvas
    ask and answer questions
    please be proactive
*/

std::cout << ...

int i = 2;

// type  of i is int
// value of i is 2

ostream cout;

// type  of cout is ostream
// value of cout is an object that is connected stdout

ostream& x = (cout << "hi"); // returning cout

cout << "hi" << "ghaith";

int j = i;
++j;
cout << i; // 2

int& k = i;
++k;
cout << i; // 3

cout << "\n"; // newline

/*
output is buffered
*/

cout << flush; // flush the buffer

cout << endl;  // newline and flush the buffer

int i = 2;
int j = 3;
int k = (i << j);
k = (2 << 3);

cout << i; // 2
cout << k; // 16

i << j; // no
i +  j; // no

(i << j) = 5; // no

cout << (2 << 3);

/*
an r-value can be on the rhs of assignment, but not on the lhs
an r-value is something that I can NOT address
<< takes two r-values and returns an r-value
*/

// examples of r-values
2

i <<= j;
cout << i; // 16

/*
an l-value can be on the lhs or the rhs of assignment
an l-value is something that I can address
*/

// examples of l-value
i

/*
<<= takes an l-value on the lhs, takes an r-value on the right
<<= returns an l-value
*/

int m = 2;
k = (m <<= j); // in-place
cout << m;     // 16
cout << k;     // 16

int y = 2;
(y <<= j) = 5;

i    << j // built-in           bit-shift operator
cout << i // an ostream defined output    operator

/*
operator overloading
when ostream overloaded an operator for output
could they have chosen ,,, // no
have to choose an already defined token
they chose <<
can't change the precedence    of the overloaded operator
can't change the associativity of the overloaded operator
CAN change the r-value / l-value nature of the arguments and the return

you can NOT overload an operator on a builtin-type
*/

i + j * k // * has a higher precedence than +

i - j - k // - is left  associative
i = j = k // = is right associative

cout << "usha";
cout << endl;

ostream& x = (cout << "usha");

(cout << "hi") << "usha";
cout << "hi" << "usha";

/*
ostream's << takes an l-value on the lhs, and an r-value on the rhs, and returns an l-value
*/

/*
double d = 2.34;
int    j = 3;
?      k = (d << j);
*/

/*
Collatz Conjecture

take a positive int
if even divide   by 2
if odd  multiply by 3 and add 1
repeat until 1

5 16 8 4 2 1

the cycle length of  5 is 6
the cycle length of 10 is 7
*/

/*
assertions are good for preconditions, for postconditions
they're not good for testing,    unit-test framework is good, e.g. Google Test
they're not good for user input, exceptions are good
*/

/*
work in teams of two, sharing a machine

1. run the code as is, confirm success
2. identify and fix the tests
3. run the code, confirm failure
4. identify and fix the code
5. run the code, confirm success
*/

int i = 2;
int j = ++i;
cout << i;   // 3
cout << j;   // 3

++i;
++2; // no

++i = j;

/*
pre-increment (++) takes an l-value and returns l-value
*/

int i = 2;
int j = i++;
cout << i;   // 3
cout << j;   // 2

i++;
2++; // no

/*
post-increment (++) takes an l-value and returns r-value
*/

i++ = j; // no

(i + j) = k; // no
++(i + j);   // no
(i + j)++;   // no

&2       // no
&i
&++i
&i++     // no
&(i + j) //

int i = 2;
++++i;     // => ++(++i);
cout << i; // 4

i++++; // no

int i = 2;
++i;
++i;
cout << i; // 4

++i++;   // no
++(i++); // no

int i = 2;
cout << (i++); // 2
cout << i;     // 3

for (int i = 0; i < s; ++i)
    ...

for (int i = 0; i < s; i++)
    ...

int i = 0;
while (i < s) {
    ...
    ++i;}

for (Arian i = 0; i < s; i++)
    ...

int i = 2;
/*
the type  of i is int
the value of i is 2
*/

class Arian {
    ...};

int main () {
    Arian x(...);
    ++x;
    return 0;}

/*
the type  of x is Arian
the value of x is an Arian object
*/

/*
the type  of ++x is Arian
the value of ++x is x
*/

ostream cout(...);

/*
the type  of cout is ostream
the value of cout is an ostream object
*/

int i = 2;
int j = 3;

i + j;           // no
int k = (i + j);
k = (i + j);
(i + j) = 5;     // no
k = (2 + 3);

int i = 2;
int j = 3;
i += j;
int k = (i += j);
k = (i += j);
(i += j) = 5;
2 += 3;           // no
i += 3;

/*
two tokens: *, &
two contexts: modifying a type, modifying a variable
*/

int i = 2;
int j = i;
++j;
cout << i; // 2

int* p = i;  // no
int* p = &i; // & needs an l-value
cout << p;   // <an address>
cout << *p;  // 2, * needs a pointer
j  = *p;
*p = 5;
cout << i;   // 5

int  i = 2;
int* p = &i;
++p;         // be careful
cout << i;   // 2

int  i = 2;
int* p = &i;
++*p;
cout << i;   // 3

int j = 3;
p = &j;
++*p;
cout << j;   // 4

int& r = 2;         // no
int& r = i;         // references need l-values
cout << r;          // 2
cout << (&r == &i); // true

int i;
i = 2;

int* p;
p = &i;

int& r;     // no
int& r = i;
r = 5;
cout << &r;
cout << &i;

int    i   = 2;
int*   p   = &i;
int**  pp  = &p;
int*** ppp = &pp;

void f (int j) {
    ++j;}

int main () {
    int i = 2;
    f(i);
    f(185);
    cout << i; // 2
    return 0;}

void g (int* p) {
    assert(p);
    ++p;}

int main () {
    int j = 2;
    g(j);      // no
    g(&j);
    g(185);    // no
    g(0);
    cout << j; // 3
    return 0;}

void h (int& r) {
    ++*r;         // no
    ++r;}

int main () {
    int k = 2;
    h(&k);     // no
    h(k);
    h(185);    // no
    h(0);      // no
    cout << k; // 3
    return 0;}

// using the return

int f (...) {
    ...
    if (<something wrong>)
        return <special value>;
    ...

void g (...) {
    ...
    int i = f(...);
    if (i == <special value>)
        <something wrong>
    ...}

// use a global

h = 0;

int f (...) {
    ...
    if (<something wrong>)
        h = <special value>
        return ...
    ...

void g (...) {
    ...
    h = 0;
    int i = f(...);
    if (h == <special value>)
        <something wrong>
    ...}

// using a parameter

int f (..., int& e2) {
    ...
    if (<something wrong>)
        e2 = <special value>
        return ...
    ...

void g (...) {
    ...
    int e = 0;
    int i = f(..., e);
    if (e == <special value>)
        <something wrong>
    ...}

// using exceptions

int f (...) {
    ...
    if (<something wrong>)
        throw <special value>
    ...

void g (...) {
    ...
    try {
        ...
        int i = f(...);
        ...}
    catch (type-of-special-value x) {
        <something wrong>
    ...}

// using exceptions

int f (...) {
    ...
    if (<something wrong>)
        throw E(...);
    ...

void g (...) {
    ...
    try {
        ...
        int i = f(...);
        ...}
    catch (E x) {
        <something wrong>
    ...}

/*
1.
call g
f did not throw
do the rest of f
do the rest of the try body
skip the catch
do the rest of g

2.
call g
f does throw
do NOT do the rest of f
do NOT do the rest of the try body
do the catch
do the rest of g
*/

// using exceptions

int f (...) {
    ...
    if (<something wrong>)
        throw M(...);
    ...

void g (...) {
    ...
    try {
        ...
        int i = f(...);
        ...}
    catch (E x) {
        <something wrong>
    ...}

/*
3.
call g
f does throw
do NOT do the rest of f
do NOT do the rest of the try body
do NOT do the catch
do NOT do the rest of g
we go to the caller of the caller of g and keep looking for a catcher
*/

// using exceptions

int f (...) {
    ...
    if (<something wrong>) {
        Mammal x(...);
        throw x;}            // throw ALWAYS copies
    if (<something wrong>)
        throw Tiger(...);
    ...}

void g (...) {
    ...
    try {
        ...
        int i = f(...);
        ...}
    catch (Tiger& x) {     // always catch children first
        <something wrong>
    catch (Mammal& x) {    // ALWAYS catch by reference
        <something wrong>
    ...}

// using exceptions

int f (...) {
    ...
    if (<something wrong>)
        throw Tiger(...);
    ...}

void g (...) {
    ...
    try {
        ...
        int i = f(...);
        ...}
    catch (Mammal& x) {   // ALWAYS catch by reference
        <something wrong>
    ...}

// using exceptions

int f (...) {
    ...
    if (<something wrong>)
        throw Tiger(...);
    ...}

void g (...) {
    ...
    try {
        ...
        int i = f(...);
        ...}
    catch (Tiger& x) {
        throw Lion(...);} // must go to next higher try block
    catch (Mammal& x) {
        <something wrong>
    ...}

// using exceptions

int f (...) {
    ...
    if (<something wrong>)
        throw Tiger(...);
    ...}

void g (...) {
    ...
    try {
        ...
        int i = f(...);
        ...}
    catch (Tiger& x) {
        throw Tiger(...);} // throw a different tiger
    catch (Mammal& x) {
        <something wrong>
    ...}

// using exceptions

int f (...) {
    ...
    if (<something wrong>)
        throw Tiger(...);
    ...}

void g (...) {
    ...
    try {
        ...
        int i = f(...);
        ...}
    catch (Tiger& x) {
        throw x;}         // throw the original tiger
    catch (Mammal& x) {
        <something wrong>
    ...}

// using exceptions

int f (...) {
    ...
    if (<something wrong>)
        throw Tiger(...);
    ...}

void g (...) {
    ...
    try {
        ...
        int i = f(...);
        ...}
    catch (Tiger& x) {
        throw;}           // throw the original tiger
    catch (Mammal& x) {
        <something wrong>
    ...}

// using exceptions

int f (...) {
    ...
    if (<something wrong>)
        throw Tiger(...);
    ...}

void g (...) {
    ...
    try {
        ...
        int i = f(...);
        ...}
    catch (...) {
        throw;}           // throw the original exception
    catch (Mammal& x) {
        <something wrong>
    ...}
