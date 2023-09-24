PS를 하며 C++의 `std::vector<T>`에 대해 유용하다고 생각한 기능들을 간략하게 정리한다. 대부분 `algorithm`헤더를 불러와야 하고, `std` 네임스페이스에 있다.

## 정렬
```cpp
vector<int> v;
...
sort(v.begin(), v.end());
```
원본 벡터를 변경해 정렬한다. $O(n \log{n})$

## 중복제거
```cpp
vector<int> v;
...
v.erase(unique(v.begin(), v.end()), v.end())
```

## 이분 탐색(binary search)
> 벡터가 이미 오름차순 정렬된 상태여야 한다.

```cpp
vector<int> v;
...
sort(v.begin(), v.end());

bool found = lower_bound(v.begin(), v.end(), value);
int index = lower_bound(v.begin(), v.end(), value) - v.begin();
```
단순히 있는지 확인하는 방법, 몇번째 index에 있는 값인지 확인하는 방법이 있다.

## 활용 예제
[BOJ - 18870번 실버2](https://www.acmicpc.net/problem/18870)

```cpp
#include <iostream>  
#include <vector>  
#include <algorithm>  
  
using namespace std;  
  
int main() {  
	ios::sync_with_stdio(false);  
	cin.tie(nullptr);  
	cout.tie(nullptr);  
	  
	int n;  
	cin >> n;  
	vector<int> v;  
	vector<int> graph;  
	for (int i = 0; i < n; i++) {  
		int r;  
		cin >> r;  
		v.push_back(r);  
		graph.push_back(r);  
	}  
	  
	sort(graph.begin(), graph.end());  
	  
	graph.erase(unique(graph.begin(), graph.end()), graph.end());  
	  
	for (int i = 0; i < n; i++) {  
		int index = lower_bound(graph.begin(), graph.end(), v[i]) - graph.begin();  
		cout << index << ' ';  
	}
}
```

쉽게 생각해서 $x_i$ 보다 작은 값의 개수를 출력하면 된다. 값들을 정렬한 후 빠른 탐색을 위해 이분 탐색으로 몇 번째 값인지 알아내면 된다.
1. 입력된 벡터를 2개의 벡터에 똑같이 저장한다. 하나는 원본, 나머지는 작은 원소 카운터용이다.
2. 카운터로 쓰기 위한 벡터는 중복을 제거한 후 이분 탐색을 위해 정렬한다.
3. 이분 탐색을 수행해 몇 번쨰 값인지 알아낸 후 출력한다.