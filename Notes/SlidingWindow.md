# Sliding Window — DSA Notes

## 1. What is Sliding Window?

Sliding Window is a technique used mainly for problems involving **contiguous subarrays or substrings**.

Instead of repeatedly calculating every possible range, we maintain a window:

```text
[left ........ right]
```

and move it through the array/string.

### Core Idea

```text
Expand → Check condition → Shrink if needed → Update answer
```

The two pointers are:

- `left` → start of the current window
- `right` → end of the current window

---

# 2. How to Identify Sliding Window Problems

Look for these strong signals:

- **subarray**
- **substring**
- **contiguous**
- **consecutive**
- **longest**
- **shortest / minimum**
- **at most K**
- **exactly K**
- **window of size K**

Ask yourself:

> **Can I maintain a contiguous range `[left, right]` and update it as I move through the input?**

If yes, Sliding Window is a strong candidate.

---

# 3. Types of Sliding Window

## A. Fixed-Size Window

The window size `K` is given.

### Example

> Find the maximum sum of a subarray of size `K`.

```text
nums = [2,1,5,1,3,2]
K = 3
```

Windows:

```text
[2,1,5] = 8
[1,5,1] = 7
[5,1,3] = 9
[1,3,2] = 6
```

Answer:

```text
9
```

### Logic

Calculate the first window, then slide it.

When a new element enters:

```text
add new element
```

When an old element leaves:

```text
remove old element
```

### Template

```cpp
int sum = 0;

for(int i = 0; i < k; i++)
    sum += nums[i];

int ans = sum;

for(int i = k; i < nums.size(); i++) {
    sum += nums[i];
    sum -= nums[i - k];

    ans = max(ans, sum);
}
```

### Important Pattern

```text
NEW element → add
OLD element → remove
```

This avoids recalculating the entire window.

---

# 4. Variable-Size Window

Here, the window size is **not fixed**.

Instead, the problem gives us a condition that the window must satisfy.

### General Template

```cpp
int left = 0;

for(int right = 0; right < n; right++) {

    // Add nums[right] to the window

    while(window is invalid) {

        // Remove nums[left]

        left++;
    }

    // Window is valid
    // Update answer
}
```

### Core Pattern

```text
right → expand the window
left  → shrink the window
```

---

# 5. Longest Valid Window

For problems asking for the **longest** valid subarray/substring:

```text
Expand right
      ↓
Window becomes invalid?
      ↓
Shrink from left
      ↓
Window becomes valid
      ↓
Update MAX answer
```

## Example: Longest Substring Without Repeating Characters

```text
s = "abcabcbb"
```

We want the longest substring with no repeated characters.

Use:

```cpp
unordered_set<char> st;
```

### Code

```cpp
int left = 0;
int ans = 0;

for(int right = 0; right < s.size(); right++) {

    while(st.count(s[right])) {
        st.erase(s[left]);
        left++;
    }

    st.insert(s[right]);

    ans = max(ans, right - left + 1);
}
```

### Example

Window grows:

```text
[a]
[a b]
[a b c]
```

Next `a` arrives:

```text
[a b c a]
```

Invalid because `a` is repeated.

Shrink:

```text
[b c a]
```

Now valid again.

Window length:

```cpp
right - left + 1
```

---

# 6. Minimum Valid Window

For problems asking for the **minimum/shortest** valid subarray:

```text
Expand right
      ↓
Condition becomes satisfied
      ↓
Shrink from left as much as possible
      ↓
Update MIN answer
```

## Example: Minimum Size Subarray Sum

```text
nums = [2,3,1,2,4,3]
target = 7
```

Expand:

```text
2       → 2
2+3     → 5
2+3+1   → 6
2+3+1+2 → 8
```

Now:

```text
sum >= 7
```

So shrink from the left:

```text
[2,3,1,2] → 8
[3,1,2]   → 6
```

The condition fails, so stop shrinking.

Later we find:

```text
[4,3] → 7
```

Length = `2`.

### Code

```cpp
int left = 0;
int sum = 0;
int ans = INT_MAX;

for(int right = 0; right < nums.size(); right++) {

    sum += nums[right];

    while(sum >= target) {

        ans = min(ans, right - left + 1);

        sum -= nums[left];
        left++;
    }
}

return ans == INT_MAX ? 0 : ans;
```

---

# 7. Data Structures Commonly Used

Sliding Window is often combined with another small data structure.

## Set

Useful for checking uniqueness:

```cpp
unordered_set<char> st;
```

Example:

```text
Longest substring without repeating characters
```

## HashMap

Useful for frequencies/counts:

```cpp
unordered_map<char, int> freq;
```

Common for:

- Character frequency
- At most K distinct characters
- Anagram-type windows
- Frequency-based conditions

---

# 8. Important Recognition Cheat Sheet

| Problem Pattern | Technique |
|---|---|
| Fixed window of size `K` | Fixed Sliding Window |
| Longest + condition | Expand + Shrink + MAX |
| Minimum + condition | Expand + Shrink + MIN |
| Longest substring without repeating | Sliding Window + Set/Map |
| At most K distinct | Sliding Window + HashMap |
| Window of size K | Fixed Sliding Window |
| Contiguous subarray/substring | Consider Sliding Window |

---

# 9. Sliding Window vs Prefix Sum

Not every subarray problem is Sliding Window.

### Think Sliding Window when:

```text
Contiguous range
        +
Can maintain a valid window
        ↓
Sliding Window
```

### Think Prefix Sum + HashMap when:

```text
Exact subarray sum
+
Negative numbers may exist
        ↓
Prefix Sum + HashMap
```

For example:

> Number of subarrays whose sum equals `K`

is commonly solved using:

```text
Prefix Sum + HashMap
```

rather than a normal sliding window when negative numbers are allowed.

---

# 10. Time Complexity

A major advantage of Sliding Window is that each element usually enters and leaves the window at most once.

Therefore:

```text
Time: O(n)
```

Space depends on the data structure:

```text
Space: O(1)
```

or

```text
Space: O(k)
```

---

# 11. Mental Template

When you see a new problem, think:

```text
Is it about a contiguous subarray/substring?
              ↓
             YES
              ↓
Can I maintain a window [left, right]?
              ↓
             YES
              ↓
Is the window fixed size?
       ↙              ↘
     YES              NO
      ↓                ↓
 Fixed Window      Variable Window
                       ↓
              What is the condition?
                       ↓
          ┌────────────┴────────────┐
          ↓                         ↓
       Longest                   Minimum
          ↓                         ↓
   Shrink when invalid       Shrink while valid
   Update MAX                Update MIN
```

---

# 12. Most Important Things to Remember

### Fixed Window

```text
Add right
Remove left
```

### Variable Window

```text
Expand right
Shrink left
```

### Longest

```text
Make window valid
Then maximize its length
```

### Minimum

```text
Make condition valid
Then shrink as much as possible
```

### Recognition Question

> **Can I maintain a contiguous range and efficiently update it when `left` or `right` moves?**

If yes, Sliding Window should immediately come to mind.

---

# Quick Cheat Sheet

```text
FIXED SIZE
K is given
↓
Add right
Remove left
↓
Update answer


VARIABLE SIZE
K is NOT given
↓
Expand right
↓
Check condition
↓
If invalid → shrink left
↓
Update answer


LONGEST
Shrink when invalid
Update MAX


MINIMUM
Shrink while valid
Update MIN


COMMON DATA STRUCTURES
Set → uniqueness
HashMap → frequency/count


WARNING
Exact sum + negative numbers
↓
Usually Prefix Sum + HashMap
```