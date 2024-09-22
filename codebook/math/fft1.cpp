using cpx = complex<double>;

void fft(vector<cpx> &data, bool inverse = false) {
    int size = data.size();
    for (int i = 1, j = 0; i < size; ++i) {
        int bit = size >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(data[i], data[j]);
    }

    for (int len = 1; len < size; len <<= 1) {
        double angle = (inverse ? M_PI : -M_PI) / len;
        cpx w(cos(angle), sin(angle));
        for (int start = 0; start < size; start += len << 1) {
            cpx p(1, 0);
            for (int k = 0; k < len; ++k) {
                cpx tmp = data[start + len + k] * p;
                data[start + len + k] = data[start + k] - tmp;
                data[start + k] += tmp;
                p *= w;
            }
        }
    }

    if (inverse)
        for (int i = 0; i < size; ++i)
            data[i] /= size;
}