# fibonacci.cpp

$n$번째 피보나치 수열의 값을 $10^9 + 7$로 나눈 나머지를 구한다.
시간복잡도는 $O(\log n)$

# Cordinates Compression

## cord_compress_sort.cpp

2번 정렬해 1차원 좌표를 압축한다. 시간복잡도는 $O(n\log n)$.
중복된 값은 같은 압축된 좌표를 갖는다.

## cord_compress_sort_distinct.cpp

위와 같은 알고리즘. 중복된 값이더라도 다른 압축된 좌표를 갖는다.
값이 같으면 입력된 순서대로 작은 압축된 좌표를 갖는다.

## cord_compress_bsearch.cpp

1번 정렬, 이분 탐색을 통해 좌표를 압축한다. 시간복잡도는 $O(n \log n)$.
값이 같으면 같은 압축된 좌표를 갖는다.
