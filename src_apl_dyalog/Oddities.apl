⎕IO ⎕ML ⎕FR ⎕PP ← 0 1 1287 34
lines ← 1↓(⊃⎕NGET '/dev/stdin' 1)~⊂''
⎕ ← ↑lines,¨' is even' ' is odd' [2|⍎¨lines]