# Lazy Segment Tree

느리게 갱신되는 세그먼트 트리. 범위 업데이트를 $O(\log n)$ 에 처리한다.

기본적인 사용법은 기존 세그트리와 거의 동일하지만 update의 마지막 파라미터 val이 다르다.

`a[idx] = val` 에서 `a[idx] += val`로 구현이 변경되었다. 범위에 val만큼 더한다.

## lazy_sum_segtree.cpp

느린 전파를 사용한 부분합
