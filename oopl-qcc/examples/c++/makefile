.DEFAULT_GOAL := all

ifeq ($(shell uname), Darwin)
    CPPCHECK := cppcheck
    CXX      := g++-9
    CXXFLAGS := -fprofile-arcs -ftest-coverage -pedantic -std=c++17 -O3 -I/usr/local/include -Wall -Wextra
    LDFLAGS  := -lgtest -lgtest_main
    GCOV     := gcov-9
    VALGRIND := valgrind
else
    CPPCHECK := cppcheck
    CXX      := g++
    CXXFLAGS := -fprofile-arcs -ftest-coverage -pedantic -std=c++17 -O3 -Wall -Wextra
    LDFLAGS  := -lgtest -lgtest_main -pthread
    GCOV     := gcov
    VALGRIND := valgrind
endif

FILES :=                    \
    Hello                   \
    UnitTests3              \
    Coverage1               \
    Coverage2               \
    Coverage3               \
    IsPrime                 \
    IsPrimeT                \
    Variables               \
    Arguments               \
    IncrT                   \
    Exceptions              \
    Operators               \
    Types                   \
    Consts                  \
    Arrays1                 \
    Equal                   \
    EqualT                  \
    Copy                    \
    CopyT                   \
    Fill                    \
    FillT                   \
    Iterators               \
    Iteration               \
    Functions               \
    Lambdas                 \
    Classes                 \
    InstanceVariables       \
    ClassVariables          \
    InstanceMethods         \
    ConstMethods            \
    ClassMethods            \
    Complex                 \
    ComplexT                \
    Arrays2                 \
    Vector1                 \
    Vector1T                \
    Shapes1T                \
    MethodOverriding1       \
    Shapes2T                \
    MethodOverriding2       \
    Shapes3T

%: %.c++
	-$(CPPCHECK) $<
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

%.c++x: %
	./$<

%.c++g: %
	./$<
	$(GCOV) -b $<.c++ | grep -A 5 "File '$<.c++'"

%.c++v: %
	$(VALGRIND) ./$<

all: $(FILES)

clean:
	rm -f *.bin
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f *.plist
	rm -f $(FILES)

docker:
	docker run -it -v $(PWD):/usr/gcc -w /usr/gcc gpdowning/gcc

run: $(FILES:=.c++x)

versions:
	which         astyle
	astyle        --version
	@echo
	dpkg -s       libboost-dev | grep 'Version'
	@echo
	ls -al        /usr/lib/*.a
	@echo
	which         checktestdata
	checktestdata --version
	@echo
	which         cmake
	cmake         --version
	@echo
	which         cppcheck
	cppcheck      --version
	@echo
	which         doxygen
	doxygen       --version
	@echo
	which         g++
	g++           --version
	@echo
	which         gcov
	gcov          --version
	@echo
	which         git
	git           --version
	@echo
	which         make
	make          --version
	@echo
	which         valgrind
	valgrind      --version
	@echo
	which         vim
	vim           --version
