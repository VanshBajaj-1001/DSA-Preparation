# Binary Search

Binary Search is an efficient searching technique used mainly on **sorted data**.

### Time Complexity

* Brute Force Search → `O(n)`
* Binary Search → `O(log n)`

### Space Complexity

* Iterative → `O(1)`
* Recursive → `O(log n)` due to recursion stack

---

# 1. Basic Binary Search

Used when the array is sorted and we need to find a specific element.

### Logic

1. Set `low = 0`
2. Set `high = n - 1`
3. Find middle:
   `mid = low + (high - low) / 2`
4. Compare `arr[mid]` with target:

   * Equal → answer found
   * Smaller → search right half
   * Greater → search left half

### C++

```cpp
int binarySearch(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        else if (arr[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}
```

---

# 2. Why `low + (high - low) / 2`?

Avoid:

```cpp
mid = (low + high) / 2;
```

Because `low + high` can overflow for very large values.

Prefer:

```cpp
mid = low + (high - low) / 2;
```

---

# 3. Binary Search on Answer

One of the **most important Binary Search patterns**.

Instead of searching for an element, we search for the **minimum/maximum possible answer**.

### Example

Suppose the answer can be:

```text
1 2 3 4 5 6 7 8 9 10
```

And a condition behaves like:

```text
false false false false true true true true true true
```

We need to find the **first true**.

Binary Search can find it in `O(log n)`.

---

# 4. First Occurrence

Used when the array contains duplicates and we need the **first position** of target.

Example:

```text
arr = [1, 2, 2, 2, 3, 4]
target = 2
```

Answer:

```text
1
```

### Logic

When `arr[mid] == target`:

* Store `mid`
* Continue searching left

```cpp
int firstOccurrence(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}
```

---

# 5. Last Occurrence

Same idea, but when target is found, move right.

```cpp
int lastOccurrence(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}
```

---

# 6. Lower Bound

Lower Bound = **first index where `arr[i] >= target`**

Example:

```text
arr = [1, 2, 4, 4, 5, 7]
target = 4
```

Answer:

```text
2
```

### C++

```cpp
int lowerBound(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}
```

### Remember

```text
Lower Bound → first element >= target
```

---

# 7. Upper Bound

Upper Bound = **first index where `arr[i] > target`**

Example:

```text
arr = [1, 2, 4, 4, 5, 7]
target = 4
```

Answer:

```text
4
```

### C++

```cpp
int upperBound(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}
```

### Remember

```text
Upper Bound → first element > target
```

---

# 8. Count Occurrences

For a sorted array:

```text
count = lastOccurrence - firstOccurrence + 1
```

Example:

```text
[1, 2, 2, 2, 3]

first = 1
last = 3

count = 3 - 1 + 1
      = 3
```

---

# 9. Search Insert Position

Find the position where target should be inserted while keeping the array sorted.

This is basically **Lower Bound**.

```cpp
int searchInsert(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}
```

---

# 10. Integer Square Root

Find:

```text
floor(sqrt(x))
```

Example:

```text
x = 8

sqrt(8) = 2.82

answer = 2
```

We can binary search from:

```text
1 → x
```

### C++

```cpp
int mySqrt(int x) {
    int low = 1;
    int high = x;
    int ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid * mid <= x) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}
```

### Important

Use `long long` for:

```cpp
mid * mid
```

to avoid integer overflow.

---

# 11. Binary Search in Rotated Sorted Array

Example:

```text
Original:
[1, 2, 3, 4, 5, 6, 7]

Rotated:
[4, 5, 6, 7, 1, 2, 3]
```

The array is not completely sorted, but **one half is always sorted**.

### Logic

At every step:

```text
if left half is sorted:
    check whether target lies inside it

else:
    right half is sorted
```

### C++

```cpp
int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half is sorted
        if (nums[low] <= nums[mid]) {

            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        // Right half is sorted
        else {

            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}
```

---

# 12. Find Minimum in Rotated Sorted Array

Example:

```text
[4, 5, 6, 7, 0, 1, 2]
```

Answer:

```text
0
```

### Key Observation

Compare:

```cpp
nums[mid] with nums[high]
```

If:

```cpp
nums[mid] > nums[high]
```

minimum is on the right.

Otherwise, minimum is on the left including `mid`.

### C++

```cpp
int findMin(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[high])
            low = mid + 1;
        else
            high = mid;
    }

    return nums[low];
}
```

---

# 13. Find Peak Element

A peak element is greater than its neighbors.

Example:

```text
[1, 2, 3, 1]
```

Peak:

```text
3
```

### Logic

Compare:

```cpp
nums[mid] and nums[mid + 1]
```

If:

```cpp
nums[mid] < nums[mid + 1]
```

then peak exists on the right.

Otherwise peak exists on the left including `mid`.

### C++

```cpp
int findPeakElement(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] < nums[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}
```

---

# 14. Search in 2D Matrix

If the matrix is sorted row-wise and column-wise in a suitable way, Binary Search can be used.

For a matrix where every row is sorted and the first element of each row is greater than the last element of the previous row, treat it like a **1D sorted array**.

Example:

```text
1  3  5
7  9  11
13 15 17
```

Virtual 1D array:

```text
[1,3,5,7,9,11,13,15,17]
```

Convert index:

```cpp
row = mid / columns;
col = mid % columns;
```

### C++

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = 0;
    int high = rows * cols - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int row = mid / cols;
        int col = mid % cols;

        if (matrix[row][col] == target)
            return true;

        else if (matrix[row][col] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return false;
}
```

---

# 15. Binary Search on Answer

This is extremely important for LeetCode.

Typical question:

> Find the minimum possible value such that a condition becomes true.

Example:

```text
Possible answers:

1 2 3 4 5 6 7 8 9

Condition:

F F F F T T T T T
```

Binary Search finds:

```text
first T
```

### General Template

```cpp
int low = minimumAnswer;
int high = maximumAnswer;

while (low < high) {
    int mid = low + (high - low) / 2;

    if (check(mid))
        high = mid;
    else
        low = mid + 1;
}

return low;
```

---

# 16. Minimum Capacity / Minimum Speed Problems

Common Binary Search on Answer problems:

* Koko Eating Bananas
* Capacity To Ship Packages Within D Days
* Minimum Days to Make M Bouquets
* Split Array Largest Sum
* Allocate Minimum Number of Pages
* Aggressive Cows
* Painter's Partition

The common pattern is:

```text
Find minimum X
such that X satisfies the condition.
```

---

# 17. Maximum Possible Answer

Sometimes we need the **maximum value** that satisfies a condition.

Pattern:

```text
T T T T F F F
```

We want the **last true**.

### Template

```cpp
int low = minimumAnswer;
int high = maximumAnswer;

while (low < high) {
    int mid = low + (high - low + 1) / 2;

    if (check(mid))
        low = mid;
    else
        high = mid - 1;
}

return low;
```

### Important

For maximum answer problems:

```cpp
mid = low + (high - low + 1) / 2;
```

The `+1` prevents infinite loops.

---

# 18. Finding First True

Pattern:

```text
F F F F T T T T
```

Template:

```cpp
while (low < high) {
    int mid = low + (high - low) / 2;

    if (check(mid))
        high = mid;
    else
        low = mid + 1;
}

return low;
```

---

# 19. Finding Last True

Pattern:

```text
T T T T F F F
```

Template:

```cpp
while (low < high) {
    int mid = low + (high - low + 1) / 2;

    if (check(mid))
        low = mid;
    else
        high = mid - 1;
}

return low;
```

---

# 20. Binary Search with Duplicates

Rotated arrays containing duplicates are trickier.

Example:

```text
[2, 5, 6, 0, 0, 1, 2]
```

Sometimes:

```cpp
nums[low] == nums[mid] == nums[high]
```

In this case we cannot determine which half is sorted.

So:

```cpp
low++;
high--;
```

### Pattern

```cpp
if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
    low++;
    high--;
}
```

---

# 21. Recursive Binary Search

Binary Search can also be implemented recursively.

```cpp
int binarySearch(vector<int>& arr, int low, int high, int target) {

    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[mid] < target)
        return binarySearch(arr, mid + 1, high, target);

    return binarySearch(arr, low, mid - 1, target);
}
```

Usually, the **iterative version is preferred** because it uses `O(1)` extra space.

---

# 22. When Should I Think About Binary Search?

Whenever you see:

### 1. Sorted Array

```text
sorted + searching
        ↓
Binary Search
```

### 2. Monotonic Condition

If the answer looks like:

```text
F F F F T T T T
```

or:

```text
T T T T F F F
```

think:

```text
Binary Search on Answer
```

### 3. Minimum / Maximum

Words like:

* Minimum possible
* Maximum possible
* Smallest value
* Largest value
* Minimum capacity
* Minimum speed
* Maximum distance

can indicate Binary Search on Answer.

---

# 23. Binary Search Patterns

| Pattern                 | What to Find                 |
| ----------------------- | ---------------------------- |
| Basic Binary Search     | Exact target                 |
| First Occurrence        | First target                 |
| Last Occurrence         | Last target                  |
| Lower Bound             | First `>= target`            |
| Upper Bound             | First `> target`             |
| Search Insert Position  | Lower Bound                  |
| Rotated Array           | Search target                |
| Find Minimum            | Minimum in rotated array     |
| Peak Element            | Local maximum                |
| Binary Search on Answer | Minimum/maximum valid answer |
| 2D Matrix               | Search sorted matrix         |
| Duplicates              | Handle equal boundaries      |

---

# 24. Important C++ STL Functions

C++ already provides Binary Search functions.

### `binary_search()`

Returns whether an element exists.

```cpp
binary_search(arr.begin(), arr.end(), target);
```

Returns:

```text
true / false
```

---

### `lower_bound()`

Returns iterator to first element:

```text
>= target
```

```cpp
auto it = lower_bound(arr.begin(), arr.end(), target);
```

Index:

```cpp
int index = it - arr.begin();
```

---

### `upper_bound()`

Returns iterator to first element:

```text
> target
```

```cpp
auto it = upper_bound(arr.begin(), arr.end(), target);
```

---

# 25. Lower Bound vs Upper Bound

Remember this:

```text
Lower Bound
↓
First element >= target


Upper Bound
↓
First element > target
```

Example:

```text
arr = [1 2 2 2 4 5]

target = 2

lower_bound → index 1
upper_bound → index 4
```

Therefore:

```text
Number of occurrences
=
upper_bound - lower_bound
```

---

# 26. Common Mistakes

### Mistake 1

Using:

```cpp
mid = (low + high) / 2;
```

Prefer:

```cpp
mid = low + (high - low) / 2;
```

---

### Mistake 2

Wrong loop condition.

For the standard exact-search version:

```cpp
while (low <= high)
```

For first/last valid answer templates:

```cpp
while (low < high)
```

---

### Mistake 3

Infinite Loop

Wrong:

```cpp
low = mid;
```

Often causes:

```text
low == mid
```

Use:

```cpp
low = mid + 1;
```

or use the upper-mid pattern when searching for the last true.

---

### Mistake 4

Forgetting the array must have a useful monotonic structure.

Binary Search is not just:

> "Array is sorted."

The deeper idea is:

> **The search space can be divided based on a monotonic condition.**

---

# 27. Binary Search Cheat Sheet

```text
Exact Target
→ while(low <= high)

First Occurrence
→ ans = mid
→ high = mid - 1

Last Occurrence
→ ans = mid
→ low = mid + 1

Lower Bound
→ first >= target

Upper Bound
→ first > target

First True
→ if(check(mid))
      high = mid
  else
      low = mid + 1

Last True
→ if(check(mid))
      low = mid
  else
      high = mid - 1

Minimum Answer
→ first true

Maximum Answer
→ last true
```

---

# 28. Must-Know Binary Search Problems

### Basic

1. Binary Search
2. Search Insert Position
3. First and Last Position of Element
4. Sqrt(x)
5. Valid Perfect Square

### Rotated Array

6. Search in Rotated Sorted Array
7. Search in Rotated Sorted Array II
8. Find Minimum in Rotated Sorted Array
9. Find Minimum in Rotated Sorted Array II

### Peak / Boundaries

10. Find Peak Element
11. Find Smallest Letter Greater Than Target
12. Find First and Last Position
13. Find K Closest Elements

### Binary Search on Answer

14. Koko Eating Bananas
15. Capacity To Ship Packages Within D Days
16. Minimum Days to Make M Bouquets
17. Aggressive Cows
18. Allocate Books
19. Split Array Largest Sum
20. Painter's Partition

---

# 29. The Main Idea to Remember

Don't memorize 20 different Binary Search solutions.

Understand these **3 patterns**:

```text
1. Search for an exact element

2. Search for a boundary
   → first / last / lower bound / upper bound

3. Search for an answer
   → minimum or maximum valid value
```

If you can identify which of these three patterns a problem belongs to, most Binary Search problems become much easier.

---

# Binary Search Formula

```text
Search Space
     ↓
Choose Mid
     ↓
Check Condition
     ↓
Discard Half
     ↓
Repeat
```

### Core Principle

```text
Binary Search = Reduce the search space by half
```

### Complexity

```text
O(log n)
```
