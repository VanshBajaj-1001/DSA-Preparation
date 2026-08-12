# Prefix Sum — DSA Notes

## 1. What is Prefix Sum?

Prefix Sum is a technique used to quickly calculate the **sum of elements in a range**.

Instead of calculating the sum again and again for every subarray, we store the cumulative sum.

### Basic Idea

For:

```text
nums = [2, 4, 1, 5, 3]
```

Prefix sum:

```text
[2, 6, 7, 12, 15]
```

Because:

```text
prefix[0] = 2

prefix[1] = 2 + 4 = 6

prefix[2] = 2 + 4 + 1 = 7

prefix[3] = 2 + 4 + 1 + 5 = 12

prefix[4] = 2 + 4 + 1 + 5 + 3 = 15
```

---

# 2. Why Do We Use Prefix Sum?

Suppose we repeatedly need:

> Find the sum from index `l` to index `r`.

Without Prefix Sum, we might calculate:

```cpp
for(int i = l; i <= r; i++)
    sum += nums[i];
```

This takes:

```text
O(n)
```

for one query.

If there are many queries, this becomes expensive.

With Prefix Sum:

```text
Range Sum = prefix[r] - prefix[l - 1]
```

So each range sum can be calculated in:

```text
O(1)
```

---

# 3. How to Build Prefix Sum

For:

```text
nums = [2, 4, 1, 5, 3]
```

We can create:

```cpp
vector<int> prefix(n);
```

Then:

```cpp
prefix[0] = nums[0];

for(int i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + nums[i];
}
```

Result:

```text
nums:
[2, 4, 1, 5, 3]

prefix:
[2, 6, 7, 12, 15]
```

---

# 4. Range Sum Formula

To find the sum from index `l` to `r`:

### If `l == 0`

```text
sum = prefix[r]
```

### Otherwise

```text
sum = prefix[r] - prefix[l - 1]
```

## Example

```text
nums = [2,4,1,5,3]
```

Find the sum from index `1` to `3`:

```text
[4,1,5]
```

Prefix:

```text
[2,6,7,12,15]
```

Therefore:

```text
sum = prefix[3] - prefix[0]
    = 12 - 2
    = 10
```

---

# 5. The Easier Prefix Sum Pattern

A very useful way to build prefix sum is to create an array of size `n + 1`.

For:

```text
nums = [2,4,1,5,3]
```

Create:

```text
prefix = [0,2,6,7,12,15]
```

Here:

```text
prefix[i] = sum of elements before index i
```

So:

```text
prefix[0] = 0
prefix[1] = 2
prefix[2] = 6
prefix[3] = 7
prefix[4] = 12
prefix[5] = 15
```

### Code

```cpp
vector<int> prefix(n + 1, 0);

for(int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + nums[i];
}
```

Now the range sum from `l` to `r` becomes:

```cpp
prefix[r + 1] - prefix[l]
```

This version avoids having a separate `l == 0` case.

---

# 6. How to Identify Prefix Sum Problems

Look for these signals:

- **sum of subarray**
- **sum of elements from `l` to `r`**
- **range sum queries**
- **subarray sum**
- **number of subarrays with sum K**
- **find a subarray with a particular sum**
- **multiple range sum queries**
- **cumulative sum**
- **running sum**

Ask yourself:

> **Am I repeatedly dealing with sums of contiguous ranges?**

If yes, Prefix Sum should come to mind.

---

# 7. Prefix Sum + HashMap

This is one of the **most important Prefix Sum patterns**.

It is used for problems such as:

> Find the number of subarrays whose sum is equal to `K`.

Example:

```text
nums = [1,2,3]
K = 3
```

Valid subarrays:

```text
[1,2]
[3]
```

Answer:

```text
2
```

---

# 8. The Main Idea Behind Prefix Sum + HashMap

Suppose the current prefix sum is:

```text
currentSum
```

We want some previous prefix sum:

```text
previousSum
```

such that:

```text
currentSum - previousSum = K
```

Rearrange:

```text
previousSum = currentSum - K
```

So while traversing the array:

```text
currentSum = currentSum + nums[i]
```

we check:

```cpp
if(mp.count(currentSum - K))
```

If it exists, we found one or more subarrays with sum `K`.

---

# 9. Example: Subarray Sum Equals K

```text
nums = [1,2,3]
K = 3
```

Start:

```text
sum = 0
```

We initialize:

```cpp
mp[0] = 1;
```

This means:

> Prefix sum `0` has occurred once.

### i = 0

```text
sum = 1
```

Check:

```text
sum - K = 1 - 3 = -2
```

Not found.

Store:

```text
mp[1] = 1
```

---

### i = 1

```text
sum = 3
```

Check:

```text
sum - K = 3 - 3 = 0
```

`0` exists in the map.

Therefore we found:

```text
[1,2]
```

Answer becomes:

```text
1
```

Store:

```text
mp[3]++
```

---

### i = 2

```text
sum = 6
```

Check:

```text
sum - K = 6 - 3 = 3
```

`3` exists.

Therefore:

```text
[3]
```

is another valid subarray.

Answer:

```text
2
```

---

# 10. Code: Subarray Sum Equals K

```cpp
int subarraySum(vector<int>& nums, int k) {

    unordered_map<int, int> mp;

    mp[0] = 1;

    int sum = 0;
    int ans = 0;

    for(int num : nums) {

        sum += num;

        if(mp.count(sum - k)) {
            ans += mp[sum - k];
        }

        mp[sum]++;
    }

    return ans;
}
```

### Important line

```cpp
mp[0] = 1;
```

This handles subarrays that start from index `0`.

---

# 11. Why Prefix Sum + HashMap Works With Negative Numbers

This is an important difference between Prefix Sum and Sliding Window.

Consider:

```text
nums = [1,-1,1]
```

Negative numbers make normal Sliding Window difficult because:

> Increasing the window does not necessarily increase the sum.

But Prefix Sum does not care.

We simply calculate:

```text
prefix sum
```

and look for:

```text
currentSum - K
```

Therefore:

```text
Prefix Sum + HashMap
```

is commonly preferred for:

> **Subarray sum = K when negative numbers are possible.**

---

# 12. Prefix Sum vs Sliding Window

These two are easy to confuse.

## Sliding Window

Think:

```text
Contiguous range
+
Can maintain a valid window
```

Example:

```text
Longest substring without repeating characters
Minimum size subarray with sum >= target
```

---

## Prefix Sum

Think:

```text
Range sums
OR
Subarray sum relationships
```

Example:

```text
Range Sum Query
Subarray Sum Equals K
```

### Important Case

If the problem says:

> Number of subarrays whose sum equals K

and negative numbers are possible:

```text
Prefix Sum + HashMap
```

is usually the right approach.

---

# 13. 2D Prefix Sum

Prefix Sum can also be used with matrices.

Example:

```text
1 2 3
4 5 6
7 8 9
```

We can create a 2D prefix sum to quickly find the sum of any rectangular region.

This is useful for problems involving:

- Matrix range sums
- Submatrix sums
- Multiple rectangle queries

The basic idea is the same:

> Precalculate cumulative information so that future range queries become fast.

---

# 14. Common Prefix Sum Patterns

### Pattern 1 — Basic Prefix Sum

```text
nums
 ↓
prefix
 ↓
Range Sum
```

Used for:

```text
Range Sum Query
Multiple range queries
```

---

### Pattern 2 — Prefix Sum + HashMap

```text
currentSum
     ↓
currentSum - K
     ↓
Search in HashMap
```

Used for:

```text
Subarray Sum Equals K
Count subarrays with a particular sum
```

---

### Pattern 3 — Prefix Sum + Frequency

Instead of just checking whether a prefix sum exists, store:

```text
frequency of each prefix sum
```

This lets us count how many valid subarrays exist.

---

### Pattern 4 — 2D Prefix Sum

Used for:

```text
Matrix
 ↓
2D Prefix Sum
 ↓
Fast rectangle/submatrix sum
```

---

# 15. Time Complexity

### Building Prefix Sum

```text
O(n)
```

### Range Sum Query

```text
O(1)
```

after preprocessing.

### Prefix Sum + HashMap

Usually:

```text
Time: O(n)
Space: O(n)
```

---

# 16. Mental Template

When you see a new problem:

```text
Is it about a subarray/range?
          ↓
        YES
          ↓
Does it involve SUM?
          ↓
        YES
          ↓
Are there repeated range-sum queries?
          ↓
        YES
          ↓
     Prefix Sum
```

For:

```text
Find/count subarrays with sum = K
```

think:

```text
Prefix Sum + HashMap
```

---

# 17. Prefix Sum Cheat Sheet

```text
BASIC PREFIX SUM
nums
 ↓
prefix[i] = prefix[i-1] + nums[i]


RANGE SUM
sum(l,r)
 ↓
prefix[r] - prefix[l-1]

OR with n+1 prefix:

prefix[r+1] - prefix[l]


SUBARRAY SUM = K
 ↓
currentSum
 ↓
look for currentSum - K
 ↓
HashMap


NEGATIVE NUMBERS
 ↓
Sliding Window may fail
 ↓
Prefix Sum + HashMap


MATRIX
 ↓
2D Prefix Sum
 ↓
Fast rectangle sum
```

---

# 18. Most Important Things to Remember

### Basic Prefix Sum

> Store cumulative sums so that range sums can be calculated quickly.

### Range Sum

```cpp
prefix[r] - prefix[l - 1]
```

### `n + 1` Prefix Array

```cpp
prefix[r + 1] - prefix[l]
```

### Subarray Sum = K

Remember:

```text
currentSum - previousSum = K

previousSum = currentSum - K
```

Therefore:

```cpp
if(mp.count(sum - k))
```

### Most Important Recognition Question

> **Can I use cumulative sums to turn a repeated range/subarray sum calculation into a faster lookup?**

If yes, think **Prefix Sum**.