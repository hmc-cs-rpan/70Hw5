## Analysis of code using `IntList`
### a) 
```c++
for (size_t i = 0;  i < n;  ++i)
    myList.push_back(i);
```
* **Cost Metric**: n, where n is the number of times we call push_back
* **Precise Formula**: ![\sum_{i=0}^{n-1}1 = n]
* (https://latex.codecogs.com/gif.latex?%5Csum_%7Bi%3D0%7D%5E%7Bn-1%7D1+%3D+n)
* **Closed Form**: n
* **Asymptotic Complexity**: O(N)
* **Justification**: because push_back is O(1), and we call it once per i in n


### b)
```c++
for (size_t i = 0; i < n;  i += 2)
    myList.push_back(i);
```
* **Cost Metric**: n, where n is the twice the number of calls of push_back
* **Precise Formula**: ![\sum_{i=0}^{(n/2)-1}1 = n/2]
* (https://latex.codecogs.com/gif.latex?%5Csum_%7Bi%3D0%7D%5E%7Bn%2F2-1%7D1+%3D+n%2F2)
* **Closed Form**: n/2
* **Asymptotic Complexity**: O(N)
* **Justification**: push_back is O(1), and we call it n/2 times, since we
* increment i by 2 each time. Asymptotic complexity is O(N) because we ignore 
* coefficients and constants in Big Cow

### c)
```c++
for (size_t i = 0;  i < n;  ++i)
    for (size_t j = 0;  j < n;  ++j)
        myList.push_back(i);
```
* **Cost Metric**: n, where n is the number of times we call push_back
* **Precise Formula**: ![\sum_{i=0}^{n-1}\sum_{j=0}^{n-1}1 = n^2]
* (https://latex.codecogs.com/gif.latex?%5Csum_%7Bi%3D0%7D%5E%7Bn-1%7D%5Csum_%7Bj%3D0%7D%5E%7Bn-1%7D1+%3D)
* **Closed Form**: n^2
* **Asymptotic Complexity**: O(N^2)
* **Justification**: push_back is O(1), and we call it n times in one for loop.
* We call said for loop n times, giving us a O(N^2). 

### d) 
```c++
for (size_t i = 0;  i < n;  ++i)
    myList.push_back(i);
for (size_t j = 0;  j < n;  ++j)
    myList.push_back(j);
```
* **Cost Metric**: n, where n is the number of times we call push_back
* **Precise Formula**: ![\sum_{i=0}^{n-1}1 + \sum_{j=0}^{n-1}1 = 2n]
* (https://latex.codecogs.com/gif.latex?%5Csum_%7Bi%3D0%7D%5E%7Bn-1%7D1&plus%3B+%5Csum_%7Bj%3D0%7D%5E%7Bn-1%7D1+%3D)
* **Closed Form**: 2n
* **Asymptotic Complexity**: O(N)
* **Justification**: push_back is O(1), and we call it n times for each of
* our two for loops. O(N) because we don't care about coefficients

### e)
```cpp
for (size_t i = 0;  i < n;  ++i)
    for (size_t j = 0;  j < i;  ++j)
        myList.push_back(j);
```
* **Cost Metric**: n, where n is the number of times we call push_back
* **Precise Formula**: ![\sum_{i=0}^{n-1}\sum_{j=0}^{i}1 = \frac{1}{2}n(n-1)]
* (https://latex.codecogs.com/gif.latex?%5Csum_%7Bi%3D0%7D%5E%7Bn-1%7D%5Csum_%7Bj%3D0%7D%5E%7Bi%7D1+%3D+%5Cfrac%7B1%7D%7B2%7Dn%28n&plus%3B1%29)
* **Closed Form**: (n(n-1))/2
* **Asymptotic Complexity**: O(N^2)
* **Justification**: push_back is O(1), we call it i times in increments of 1,
* up to n, meaning 1 + 2 + 3 + ... + n. This simplifies to (n(n-1))/2. O(N^2)
* because N^2 increases more quickly than N for large N.

### f)
```cpp
for (int i = 1;  i < n;  ++i)
    for (int j = 0;  j < i;  ++j )
        for (int k = 0;  k < j*i;  ++k)
            myList.push_back(i);
```
* **Cost Metric**: n, where n is the number of times we call push_back
* **Precise Formula**: ![\sum_{i=1}^{n-1}\sum_{j=0}^{i-1}\sum_{k=0}^{j*i-1}1]
* (https://latex.codecogs.com/gif.latex?%5Csum_%7Bi%3D1%7D%5E%7Bn-1%7D%5Csum_%7Bj%3D0%7D%5E%7Bi-1%7D%5Csum_%7Bk%3D0%7D%5E%7Bj%2Ai-1%7D1)
* **Closed Form**: ((n(n-1))/2)^2
* **Asymptotic Complexity**: O(N^4)
* **Justification**: The first two summations are the same as part (e), and
* the third summation iterates j*i times, which is synonymous to the first two
* summations. Hence, we square our previous result, giving us O(N^4).

## Analysis of operations on `IntLists`

### g) Copying a list
* **Cost Metric**: n, where n is the size of the list to copy
* **Precise Formula**: ![\sum_{i=0}^{n-1}1 = n]
* (https://latex.codecogs.com/gif.latex?%5Csum_%7Bi%3D0%7D%5E%7Bn-1%7D1+%3D+n)
* **Closed Form**: n
* **Asymptotic Complexity**: O(N)
* **Justification**: We call push_back once per element in the list so with an
* n-element list, this would call push_back n times. push_back is O(1), so 
* calling it N times will yield O(N)

### h) Determining whether the list contains some value `V`
* **Cost Metric**: n, where n is the size of the list
* **Precise Formula**: ![\sum_{i=0}^{n-1}2 = 2n]
* (https://latex.codecogs.com/gif.latex?%5Csum_%7Bi%3D0%7D%5E%7Bn-1%7D2+%3D+2n)
* **Closed Form**: 2n
* **Asymptotic Complexity**: O(N)
* **Justification**: We call the dereference operator and the equality operator
* once per element in an n-element list. Since both operators are O(1), we
* have 2*O(1) for each element. We cannot guarantee that we will find value
* V, so the worst case scenario will have us iterating through the entire list
* giving us O(N).

### i) Determining whether two lists are equal
* **Cost Metric**: n, where n is the size of the list
* **Precise Formula**: ![\sum_{i=0}^{n-1}5 = 5n]
* (https://latex.codecogs.com/gif.latex?%5Csum_%7Bi%3D0%7D%5E%7Bn-1%7D5+%3D+5n)
* **Closed Form**: 5n
* **Asymptotic Complexity**: O(N)
* **Justification**: For each element in our list we dereference 2 iterators,
* call the equality operator, and increment 2 iterators. All of these
* operations are O(1), so we have a total of 5*O(1) per element in an
* n-element list. The worst case scenario will require us to check all n
* elements, so we have O(N) because we ignore constants.


### j) Returning the `k`th element of the list (where `k` is a parameter)
* **Cost Metric**: k, where k is the position of the element in the list
* **Precise Formula**: ![\sum_{i=0}^{k-1}1 = k]
* (https://latex.codecogs.com/gif.latex?%5Csum_%7Bi%3D0%7D%5E%7Bk-1%7D1+%3D+k)
* **Closed Form**: k
* **Asymptotic Complexity**: O(N)
* **Justification**: For each element prior to the `k`th element, we increment
* the iterator, which is an operation of O(1). We do this k-1 times, so this
* runs in linear time, O(N).
