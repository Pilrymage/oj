⎕IO ⎕ML ← 0 1
lines ← ⍎⊃⊃⎕NGET '/dev/stdin' 1
(lines)[0] -← 2
⎕ ← 'NO' 'YES' ⊃⍨∧/1≤lines