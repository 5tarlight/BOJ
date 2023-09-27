`algorithm`헤더의 `std::next_permutation`는 주어진 배열에 대해서 가능한 모든 permutation을 제공한다.

[doc](https://cplusplus.com/reference/algorithm/next_permutation/)

```cpp
template <class BidirectionalIterator>
bool next_permutation (BidirectionalIterator first, BidirectionalIterator last);
```

순열을 만들 배열의 시작 지점 iterator와 종료 지점 iterator를 파라미터로 받는다. 사전순으로 찾으니 정렬되어 있지 않으면 모든 순열을 다 찾을 수 없을 수도 있다. 더이상 순열을 만들 수 없는 경우 `false`를 리턴한다.

```cpp
#include <iostream>  
#include <algorithm>  
  
using namespace std;  
  
int main() {  
	ios::sync_with_stdio(false);  
	cin.tie(nullptr);  
	cout.tie(nullptr);  
	  
	int perm[] = { 1, 1, 0, 0, 0 };  
	int data[] = { 1, 2, 3, 4, 5 };  
	  
	sort(perm, perm + 5);  
	  
	do {  
		for (int i = 0; i < 5; i++) {  
			if (perm[i] == 1)  
			cout << data[i] << ' ';  
		}
		
		cout << '\n';
	} while (next_permutation(perm, perm + 5));  
}
```
```
4 5 
3 5 
3 4 
2 5 
2 4 
2 3 
1 5 
1 4 
1 3 
1 2 
```

이걸 응용해서 특정 배열에서 n개를 뽑는 경우를 모두 구할 수도 있다.