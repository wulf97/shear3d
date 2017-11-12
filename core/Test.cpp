#include "Test.h"
#include "test_1.h"
#include "test_2.h"

//#define TEST_1
#define TEST_2

Test::Test() {

}

Test::~Test() {

}

void Test::init() {
#ifdef TEST_1
    test_1();
#endif
#ifdef TEST_2
    test_2();
#endif
}
