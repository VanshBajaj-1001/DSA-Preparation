# Backtracking — DSA Notes

## 1. What is Backtracking?

Backtracking is a technique used to explore **all possible choices/solutions** by:

1. Making a choice
2. Exploring that choice
3. Undoing the choice
4. Trying the next choice

### Core Idea

```text
Choose
  ↓
Explore
  ↓
Undo
  ↓
Try next choice
```

The most important part is:

> **Make a choice → Recursive call → Undo the choice**

---

# 2. When Should You Think About Backtracking?

Look for problems involving:

- **All possible combinations**
- **All possible permutations**
- **All possible subsets**
- **Generate all**
- **Find all possible ways**
- **Choose / pick elements**
- **Partition a string/array**
- **Arrange elements**
- **Different possibilities**
- **Generate valid configurations**
- **Can we construct a solution by making choices?**

Ask yourself:

> **Do I need to explore multiple possible choices and potentially undo a choice to try another?**

If yes, Backtracking is a strong candidate.

---

# 3. Basic Backtracking Structure

The general structure is:

```cpp
void solve(...) {

    // Base case

    for(each possible choice) {

        // Make choice

        solve(...);

        // Undo choice
    }
}
```

The **undo** step is what makes this Backtracking.

---

# 4. Simple Example — Subsets

Given:

```text
nums = [1,2,3]
```

Generate all subsets.

Possible answers:

```text
[]
[1]
[2]
[3]
[1,2]
[1,3]
[2,3]
[1,2,3]
```

For every element we have two choices:

```text
Take it
OR
Don't take it
```

This creates a binary decision tree.

```text
                    []
                 /      \
              take 1    skip 1
               [1]        []
              /   \       /  \
          take2  skip2  take2 skip2
           [1,2] [1]     [2]   []
```

---

# 5. Subsets Code

```cpp
vector<vector<int>> ans;
vector<int> curr;

void solve(vector<int>& nums, int index) {

    if(index == nums.size()) {
        ans.push_back(curr);
        return;
    }

    // Take nums[index]
    curr.push_back(nums[index]);
    solve(nums, index + 1);

    // Undo
    curr.pop_back();

    // Don't take nums[index]
    solve(nums, index + 1);
}
```

### Important

This:

```cpp
curr.push_back(nums[index]);
solve(nums, index + 1);
curr.pop_back();
```

is the classic Backtracking pattern.

---

# 6. Why Do We `pop_back()`?

Suppose:

```text
curr = [1,2]
```

We choose:

```text
3
```

Now:

```text
curr = [1,2,3]
```

We explore this possibility.

After finishing:

```cpp
curr.pop_back();
```

we get:

```text
curr = [1,2]
```

Now we can explore another possibility.

Without `pop_back()`:

```text
[1,2,3]
```

would remain in `curr`, and our next branch would be incorrect.

Therefore:

> **`pop_back()` undoes the choice we just made.**

---

# 7. The Backtracking Tree

For:

```text
nums = [1,2]
```

The recursion tree is:

```text
                    []
                 /      \
              take 1    skip 1
               [1]        []
              /   \       /  \
          take2  skip2  take2 skip2
          [1,2]   [1]    [2]   []
```

Final answers:

```text
[]
[1]
[2]
[1,2]
```

The tree represents **all possible choices**.

---

# 8. Permutations

Another very common Backtracking problem is generating permutations.

For:

```text
nums = [1,2,3]
```

Possible permutations:

```text
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]
```

Here, unlike subsets, we can choose **any unused element** at every level.

---

# 9. Permutation Code

```cpp
vector<vector<int>> ans;
vector<int> curr;
vector<bool> used;

void solve(vector<int>& nums) {

    if(curr.size() == nums.size()) {
        ans.push_back(curr);
        return;
    }

    for(int i = 0; i < nums.size(); i++) {

        if(used[i])
            continue;

        // Make choice
        used[i] = true;
        curr.push_back(nums[i]);

        solve(nums);

        // Undo choice
        curr.pop_back();
        used[i] = false;
    }
}
```

### Important Difference

For Subsets:

```text
Take / Don't Take
```

For Permutations:

```text
Choose any unused element
```

---

# 10. Combination Problems

Suppose:

> Choose `k` numbers from `1...n`.

Example:

```text
n = 4
k = 2
```

Answers:

```text
[1,2]
[1,3]
[1,4]
[2,3]
[2,4]
[3,4]
```

Here we usually maintain a `start` index.

```cpp
void solve(int start, int k) {

    if(curr.size() == k) {
        ans.push_back(curr);
        return;
    }

    for(int i = start; i <= n; i++) {

        curr.push_back(i);

        solve(i + 1, k);

        curr.pop_back();
    }
}
```

The `i + 1` prevents us from selecting the same element again.

---

# 11. String Partitioning

Backtracking can also be used to partition strings.

Example:

```text
s = "aab"
```

Possible partitions include:

```text
[a,a,b]
[aa,b]
```

This is the idea behind:

**LeetCode 131 — Palindrome Partitioning**

At every index, we try different ending positions:

```text
a
aa
aab
```

If the selected substring is a palindrome, we choose it and recurse.

```cpp
for(int i = start; i < s.size(); i++) {

    if(isPalindrome(s, start, i)) {

        curr.push_back(
            s.substr(start, i - start + 1)
        );

        solve(s, i + 1);

        curr.pop_back();
    }
}
```

---

# 12. General Backtracking Template

This is the template you should remember:

```cpp
void solve(...) {

    if(base_case) {
        ans.push_back(curr);
        return;
    }

    for(each possible choice) {

        // Make choice
        curr.push_back(choice);

        // Explore
        solve(...);

        // Undo choice
        curr.pop_back();
    }
}
```

---

# 13. Backtracking + Constraints

Sometimes we don't want to explore every possibility.

We can **prune** invalid choices.

Example:

```cpp
if(choice is invalid)
    continue;
```

This is called **pruning**.

### Without pruning

```text
Explore everything
```

### With pruning

```text
Invalid choice
     ↓
Stop immediately
     ↓
Try another choice
```

Pruning can dramatically reduce the number of recursive calls.

---

# 14. Example — N Queens

In N Queens, we need to place `N` queens on an `N × N` chessboard such that no two queens attack each other.

At each row:

```text
Try column 0
Try column 1
Try column 2
...
```

If a position is invalid:

```text
Don't continue that branch
```

If valid:

```text
Place queen
↓
Move to next row
↓
Eventually undo queen
```

The basic pattern is:

```text
Choose position
      ↓
Check if valid
      ↓
Place queen
      ↓
Recursive call
      ↓
Remove queen
```

---

# 15. Backtracking + Memoization

Backtracking can sometimes be combined with **memoization**.

The basic idea:

```text
Backtracking
     +
Repeated states
     ↓
Memoization
```

Instead of solving the same state repeatedly, store its result.

For example:

```text
solve(index)
```

If the answer for `index` has already been calculated:

```cpp
if(dp[index] != -1)
    return dp[index];
```

This is useful in problems such as:

- **LeetCode 139 — Word Break**
- **LeetCode 140 — Word Break II**
- **LeetCode 91 — Decode Ways**

---

# 16. Backtracking vs Backtracking + Memoization

### Normal Backtracking

```text
Try choice
 ↓
Recursive call
 ↓
Try another choice
```

May repeatedly solve the same state.

### Backtracking + Memoization

```text
Try choice
 ↓
Recursive call
 ↓
Have we solved this state before?
      ↓
    YES → use stored answer
    NO  → calculate and store
```

This can reduce the time significantly.

---

# 17. How to Identify Backtracking vs DP

Ask:

### Do I need to generate ALL possibilities?

```text
YES
 ↓
Think Backtracking
```

Examples:

```text
Subsets
Permutations
Combinations
Palindrome Partitioning
N Queens
Sudoku
```

### Do I only need one answer/count/minimum/maximum?

Then ask:

> Are there repeated states?

If yes:

```text
Recursion + Memoization
```

may be appropriate.

Examples:

```text
Word Break
Decode Ways
```

---

# 18. Backtracking vs Dynamic Programming

Don't automatically call every recursive + memoized problem Backtracking.

### Backtracking

Usually focuses on:

```text
Generate / explore choices
```

Examples:

```text
Subsets
Permutations
Combinations
N Queens
Sudoku
```

### DP

Usually focuses on:

```text
Optimal answer / count / possibility
+
Overlapping subproblems
```

Examples:

```text
House Robber
Coin Change
Climbing Stairs
```

Some problems can use both ideas, such as:

```text
Word Break
Decode Ways
```

---

# 19. Common Backtracking Patterns

## Pattern 1 — Take / Don't Take

Used for:

```text
Subsets
Subset Sum
Some combination problems
```

```cpp
take
solve()
undo

don't take
solve()
```

---

## Pattern 2 — Loop + Start Index

Used for:

```text
Combinations
Combination Sum
Palindrome Partitioning
```

```cpp
for(int i = start; i < n; i++) {

    choose

    solve(i + 1);

    undo
}
```

---

## Pattern 3 — Loop + Used Array

Used for:

```text
Permutations
```

```cpp
for(int i = 0; i < n; i++) {

    if(used[i])
        continue;

    used[i] = true;
    curr.push_back(nums[i]);

    solve();

    curr.pop_back();
    used[i] = false;
}
```

---

## Pattern 4 — Constraint Checking + Pruning

Used for:

```text
N Queens
Sudoku
Combination problems with constraints
```

```cpp
if(!valid(choice))
    continue;

choose

solve()

undo
```

---

# 20. Time Complexity

Backtracking is often **exponential** because we may explore many possible choices.

For example, subsets of `n` elements:

```text
2^n
```

because every element has two choices:

```text
Take
Don't Take
```

Permutations:

```text
n!
```

because there are `n!` possible arrangements.

Therefore, always check the constraints before deciding whether Backtracking is practical.

---

# 21. How Constraints Help

Constraints are extremely important for Backtracking.

If:

```text
n <= 15
```

or:

```text
n <= 20
```

an exponential solution might be intended.

For example:

```text
2^20 ≈ 1 million
```

which may be manageable.

But:

```text
2^100
```

is far too large.

So when you see a small constraint:

```text
n <= 10
n <= 15
n <= 20
```

think:

> **Could this be Backtracking?**

---

# 22. Backtracking Recognition Cheat Sheet

| Problem Pattern | Likely Technique |
|---|---|
| Generate all subsets | Backtracking |
| Generate all permutations | Backtracking |
| Generate all combinations | Backtracking |
| Partition a string in all ways | Backtracking |
| Place elements under constraints | Backtracking |
| N Queens | Backtracking + Pruning |
| Sudoku | Backtracking + Pruning |
| Word Break | Recursion + Memoization |
| Decode Ways | Recursion + Memoization |
| Need minimum/maximum/count with overlapping states | DP / Memoization |

---

# 23. Mental Template

When you see a new problem:

```text
Do I need to explore multiple choices?
            ↓
           YES
            ↓
Do I need ALL possible solutions?
            ↓
           YES
            ↓
       BACKTRACKING
            ↓
     Make a choice
            ↓
       Recursive call
            ↓
       Undo the choice
            ↓
       Try next choice
```

If the same state appears repeatedly:

```text
Repeated states
      ↓
Memoization
```

If many branches can be ruled out early:

```text
Invalid branch
      ↓
Pruning
```

---

# 24. Most Important Things to Remember

### Backtracking =

```text
Choose
↓
Explore
↓
Undo
```

### The most important line

```cpp
curr.pop_back();
```

It **undoes the previous choice**.

### Subsets

```text
Take / Don't Take
```

### Permutations

```text
Choose any unused element
```

### Combinations

```text
Use start index
```

### Constraint Problems

```text
Choose
↓
Check validity
↓
Explore
↓
Undo
```

### Repeated States

```text
Backtracking / Recursion
+
Memoization
```

### Small Constraints

```text
n <= 10 / 15 / 20
```

should make you consider Backtracking.

---

# Quick Backtracking Cheat Sheet

```text
SUBSETS
Take / Don't Take
↓
2^n


PERMUTATIONS
Choose unused element
↓
n!


COMBINATIONS
Choose from start index
↓
Avoid duplicates


PARTITIONING
Choose a valid substring
↓
Recursive call
↓
Undo


CONSTRAINT PROBLEMS
Check if choice is valid
↓
Choose
↓
Explore
↓
Undo


GENERAL PATTERN

void solve(...) {

    if(base_case) {
        // store answer
        return;
    }

    for(each choice) {

        // choose
        curr.push_back(choice);

        // explore
        solve(...);

        // undo
        curr.pop_back();
    }
}


REPEATED STATES
↓
Memoization


TOO MANY INVALID BRANCHES
↓
Pruning
```