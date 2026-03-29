⎕IO ⎕ML ← 0 1
lines ← 1↓⊃⎕NGET '/dev/stdin' 1
⎕ ← ↑{⍕×/⌈3÷⍨¯2+⍎⍵}¨lines
