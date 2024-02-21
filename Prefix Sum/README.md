# ***Prefix Sum***

## Motivation
If I have array of size $n$, and want to answer $q$ questions in form what the sum of element from $l$ to $r$ is ?

for first time it look easy can solve as following :
```cpp
#include<iostream>
using namespace std;

int main(){
    int n ; // size of array 
    cin >> n ;
    int arr[n] ; // declare the array
    for(int i = 0 ; i < n ; i ++)
        cin >> arr[i] ; // input the array elements
    int q ; cin >> q ; // take the number of questions
    for(int i = 0 ; i < q ; i ++){
        int l , r ;
        cin >> l >> r ; // take the start and end of intervail
        int ans = 0 ;
        for(int j = l - 1 ; j < r ; j ++)
            // note we start l - 1 as it 0-indexed 
            // for example : if he mean l = 0 index will say 1
            ans += arr[j] ;
        cout << ans << endl ;
    }
}
```

### But, What wrong in this ?
### But, First what is its time complexity ? 
if we look to block again :
```cpp
#include<iostream>
using namespace std;

int main(){
    int n ; 
    cin >> n ;
    int arr[n] ; 
    for(int i = 0 ; i < n ; i ++)
        cin >> arr[i] ; // o(n)
    int q ; cin >> q ; 
    for(int i = 0 ; i < q ; i ++){ // o(q)
        int l , r ;
        cin >> l >> r ;
        int ans = 0 ;
        for(int j = l - 1 ; j < r ; j ++)
            ans += arr[j] ; // o(n)
        cout << ans << endl ;
    }
}
```
So we will find time complexity is $O(qn)$, The problem is that if $n = 2*10^5$ and $q = 2 * 10^5 $ it will take $4*10^{10}$ !!!!!!!!!!!!!!!!

So go on to see how to solve this problem.
## Range Query

the idea is to precompute the values, **but How ?**

Let's say we have a one-indexed integer array $\texttt{arr}$ of size $n$ and we
want to compute the sum of values from $l$ to $r$, where $(1 \leq l \leq r \leq n)$ So : 

$$Sum = \texttt{arr}[l]+\texttt{arr}[l+1]+\cdots+\texttt{arr}[r]$$

let that $n = 6$ and array as following :

![alt text](image.png)

## Resources : 
1 - [CPH Book](https://usaco.guide/CPH.pdf#page=94)

2 - [USACO Book](https://darrenyao.com/usacobook/cpp.pdf#page=60)

3 - [USACO guide](https://usaco.guide/silver/prefix-sums)

4 - [LeetCode Problemset](https://leetcode.com/tag/prefix-sum/)
