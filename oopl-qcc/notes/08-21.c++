// -----------
// Tue, 20 Aug
// -----------

/*
N 450C

Canvas
    ask and answer questions
    please be proactive
*/

y = x;
y.operator=(x);

int i = 2;
int j = i;
j = i;

T x = ...;
T y = x;
y = x;

int s;
cin >> s;
int a[s]; // no

void f (T& y) {
    ...}

void f (T y) {
    ...}

int main () {
    T x(...);
    f(x);
    return 0;}

T x;

int i;

void f (int j) {
    ...}

int main () {
    int i = 2;
    f(i);

    f(2);
    return 0;}

vector<int>::iterator p = transform(b, e, x, [] (int x) -> int {return pow(x, 2);});

auto i = 2;

/*
{2, 3, 4}
initializer_list<int>
*/

/*
special notation in constructors
member initialization lists
*/

/*
if you define ANY constructor, you lose the compliler-generated default constructor
*/

A<int> x;
cout << x._v; // no

template <typename T>
struct A {
    int    i;
    double d;
    T      x;};

void test22 () {
    A<int> x = {2, 3.45, 6};
    assert(sizeof(x) == 24);}

template <typename T>
struct A {
    static int cv;};

/*
pointer this
which points to an object which contains iv
*/

cout << *this.iv;   // no
cout << (*this).iv;
cout << this->iv;

/*
in a class method no this
*/

template <typename T>
class complex {
    friend T real (const complex& x) {
        return x._r;}

    private:
        T _r;
        T _i;

    public:
        complex () = default;
        complex (const complex&) = default;
        complex& operator = (const complex&) = default;

//        ? real (...) {
//            ...}
    };

// template <typename T>
// T real (const complex<T>& x) {
//     x._r;}

int main () {
    complex<int> x;
    cout << x.real(...);    // no
    cout << real(x);
    return 0;}

T  v(...);
T* a = new T[s];   // T(),  s times
fill(a, a + s, v); // =(T), s times

vector<T> x(s, v); // T(T), s times

cout << x[i];
cout << x.operator[](i);

template <typename T>
class vector {
    private:
        int _s;
        T*  _a;

    public:
        T& operator [] (int i) {
            ...}

        const T& operator [] (int i) const {
            ...}

int main () {
    vector<int> x(10, 2);
    cout << x[1];               // 2
    x[1] = 3;
    cout << x[1];               // 3

    const vector<int> y(10, 2);
    cout << y[1];
    y[1] = 3;                   // no
    return 0;}

Shape* p;

if (...)
    p = new Circle(...);
else
    p = new Triangle(...);

cout << p->area();

struct A {
    virtual void f (int) {...}};

struct B : A {
    void f (int) {...}};

int main () {
    A* p = new B;
    p->f(2);      // B::f
    return 0;}

struct A {
    virtual void f (int) {...}};

struct B : A {
    void g (int) {...}};

int main () {
    A* p = new B;
    p->f(2);      // A::f
    return 0;}

struct A {
    virtual void f (int) {...}};

struct B : A {
    void f (long) {...}};

int main () {
    A* p = new B;
    p->f(2);      // A::f
    return 0;}

struct A {
    virtual void f (int) = 0;} // pure virtual method

void A::f (int) {...}

struct B : A {
    void f (int) {...} };

int main () {
	A x;          // no

    A* p = new B;
    p->f(2);      // B::f
    return 0;}

/*
consequences of a pure virtual method

1. the parent becomes abstract
2. the child must define the method or become abstract
3. the parent can optionally define the method
*/

/*
competitive programming
40 years

20 years

2016
southwest usa, texas, oklahoma, louisiana
65 teams from 25 schools
12 best students, 4 teams of 3

2015: 2nd, Rice 1st, Thailand
2016: 2nd, Rice 1st, Morocco, four teams were in the top 7
2017: 1st, 2nd, 3rd, 4th, South Dakota
2018: 1st, Bejing
2019: 1st, Portugal
2020: Moscow
*/

Shape* p;

Circle x(...);
Triangle y(...);

if (...)
    p = &x;
else
    p = &y;

cout << p->area();


























