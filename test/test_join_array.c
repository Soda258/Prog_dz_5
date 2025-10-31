#include "../extra/Unity/unity.h"
#include "../include/array_function.h"

#define SIZE 10

void setUp(void) {}
void tearDown(void) {}

const int size = 11;

void test_JoinIntArray1(void) {
    int array1[] = {1,2,3,4,5};
    int array2[] = {1,2,3,4,5,6};
    int actual[SIZE];
    int expected[] = {1,2,3,4,5,1,2,3,4,5,6};
    join_int_arrays(array1, 5, array2, 6, actual);

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, size);
}

void test_JoinIntArray2(void) {
    int array1[] = {1,2,3,4,5,6};
    int array2[] = {1,2,3,4,5};
    int actual[SIZE];
    int expected[] = {1,2,3,4,5, 6,1,2,3,4,5,};
    join_int_arrays(array1, 6, array2, 5, actual);

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, size);
}

void test_JoinIntArray3(void) {
    const int size = 7;
    int array1[] = {1,2,3,4,5,6};
    int array2[] = {1};
    int actual[SIZE];
    int expected[] = {1,2,3,4,5, 6, 1};
    join_int_arrays(array1, 6, array2, 1, actual);

    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, size);
}

void join_int_arrays(int* src1, size_t size_src1, int* src2, size_t size_src2, int* dest){
    int res[SIZE];
    for(int i = 0; i < size_src1; i++){
        res[i] = src1[i];
    }
    for(int i = size_src1; i < size_src1 + size_src2; i++){
        res[i] = src2[i];
    }
    printf("%ls",res);
}

int main(int argc, char** argv) {
    UNITY_BEGIN();
    RUN_TEST(test_JoinIntArray1);
    RUN_TEST(test_JoinIntArray2);
    RUN_TEST(test_JoinIntArray3);
    return UNITY_END();
}