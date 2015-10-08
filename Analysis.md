## Analysis of code using `IntList`
### a) 
```c++
for (size_t i = 0;  i < n;  ++i)
    myList.push_back(i);
```
* **Cost Metric**: 
* **Precise Formula**:
* **Closed Form**:
* **Asymptotic Complexity**:
* **Justification**:


### b)
```c++
for (size_t i = 0; i < n;  i += 2)
    myList.push_back(i);
```
* **Cost Metric**: 
* **Precise Formula**:
* **Closed Form**:
* **Asymptotic Complexity**:
* **Justification**:

### c)
```c++
for (size_t i = 0;  i < n;  ++i)
    for (size_t j = 0;  j < n;  ++j)
        myList.push_back(i);
```
* **Cost Metric**: 
* **Precise Formula**:
* **Closed Form**:
* **Asymptotic Complexity**:
* **Justification**:

### d) 
```c++
for (size_t i = 0;  i < n;  ++i)
    myList.push_back(i);
for (size_t j = 0;  j < n;  ++j)
    myList.push_back(j);
```
* **Cost Metric**: 
* **Precise Formula**:
* **Closed Form**:
* **Asymptotic Complexity**:
* **Justification**:

### e)
```cpp
for (size_t i = 0;  i < n;  ++i)
    for (size_t j = 0;  j < i;  ++j)
        myList.push_back(j);
```
* **Cost Metric**: 
* **Precise Formula**:
* **Closed Form**:
* **Asymptotic Complexity**:
* **Justification**:

### f)
```cpp
for (int i = 1;  i < n;  ++i)
    for (int j = 0;  j < i;  ++j )
        for (int k = 0;  k < j*i;  ++k)
            myList.push_back(i);
```
* **Cost Metric**: 
* **Precise Formula**:
* **Closed Form**:
* **Asymptotic Complexity**:
* **Justification**:

## Analysis of operations on `IntLists`

### g) Copying a list
* **Cost Metric**: 
* **Precise Formula**:
* **Closed Form**:
* **Asymptotic Complexity**:
* **Justification**:

### h) Determining whether the list contains some value `V`
* **Cost Metric**: 
* **Precise Formula**:
* **Closed Form**:
* **Asymptotic Complexity**:
* **Justification**:

### i) Determining whether two lists are equal
* **Cost Metric**: 
* **Precise Formula**:
* **Closed Form**:
* **Asymptotic Complexity**:
* **Justification**:


### j) Returning the `k`th element of the list (where `k` is a parameter)
* **Cost Metric**: 
* **Precise Formula**:
* **Closed Form**:
* **Asymptotic Complexity**:
* **Justification**:
