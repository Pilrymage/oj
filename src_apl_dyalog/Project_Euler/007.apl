⎕IO ⎕ML ⎕FR ⎕PP ← 0 1 1287 34
v ← 2↓⍳120000
primes ← (~v∊v∘.×v)/v
10001 ⊃ primes
⎕ ← lines