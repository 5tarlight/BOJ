#include "testlib.h"

using namespace std;

const int MAX_TESTCOUNT = 30000;
const int MAX_N = 30000;
const int MAX_VAL = 1'000'000;

int main(int argc, char** argv) {
    registerValidation(argc, argv);

    int testCount = inf.readInt(1, MAX_TESTCOUNT, "test-count");
    inf.readEoln();
    int sum_n = 0;

    for (int tc = 1; tc <= testCount; tc++) {
        setTestCase(tc);
        int n = inf.readInt(1, MAX_N, "n");
        sum_n += n;
        ensuref(
            sum_n <= MAX_N,
            "sum of n over all cases should not exceed %d",
            MAX_N
        );
        inf.readEoln();
        inf.readInts(n, 1, MAX_VAL, "a");
        inf.readEoln();
    }

    inf.readEof();

    return 0;
}
