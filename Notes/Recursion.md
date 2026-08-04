# Subsequences - Theory

## What is a Subsequence?
A subsequence is obtained by deleting zero or more elements from a sequence **without changing the order** of the remaining elements.

Example:
String = "abc"

Subsequences:
"", "a", "b", "c", "ab", "ac", "bc", "abc"

- "ac" ✅
- "ca" ❌ (order changes)

---

## Total Number of Subsequences

For a string/array of length **n**:

- Including empty subsequence = **2ⁿ**
- Excluding empty subsequence = **2ⁿ − 1**

Reason:
Each element has two choices:
- Pick
- Don't Pick

Total choices = 2 × 2 × ... × 2 = 2ⁿ

---

## Subsequence vs Substring

| Subsequence | Substring |
|-------------|-----------|
| Characters can be skipped | Characters must be contiguous |
| Order must remain same | Consecutive characters only |
| Count = 2ⁿ | Count = n(n+1)/2 |

Example:

String = "abcde"

Subsequence:
- ace
- abe

Substring:
- abc
- bcd

---

## Pick / Not Pick Recursion

At every index, make two choices:

1. Pick the current element
2. Do not pick the current element

```cpp
solve(index, curr)

if(index == n){
    print(curr);
    return;
}

curr += arr[index];
solve(index + 1, curr);

curr.pop_back();
solve(index + 1, curr);