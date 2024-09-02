#include "bits/stdc++.h"

using namespace std;

using cpx = complex<long double>;

void fft(vector<cpx> &data, bool inverse=false) {
    int size = data.size();
    vector<cpx> roots(size / 2);

    // Bit reversal permutation
    for (int i = 1, j = 0; i < size; i++) {
        int bit = size / 2;

        while (j >= bit)
            j -= bit, bit >>= 1;

        if (i < (j += bit))
            swap(data[i], data[j]);
    }
    
    // Precompute roots of unity
    long double angle = 2 * acosl(-1) / size * (inverse ? -1 : 1);

    for (int i = 0; i < size / 2; i++)
        roots[i] = cpx(cosl(angle * i), sinl(angle * i));
        
    // FFT
    for (int len = 2; len <= size; len <<= 1) {
        int step = size / len;
        for (int start = 0; start < size; start += len) {
            for (int k = 0; k < len / 2; k++) {
                auto even = data[start + k];
                auto odd = data[start + k + len / 2] * roots[step * k];
                data[start + k] = even + odd;
                data[start + k + len / 2] = even - odd;
            }
        }
    }

    // Normalize if inverse FFT
    if (inverse) {
        for (auto &value : data)
            value /= size;
    }
}
