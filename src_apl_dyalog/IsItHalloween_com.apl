⎕IO ⎕ML ⎕FR ⎕PP ← 0 1 1287 34
lines ← ⊃(⊃⎕NGET '/dev/stdin' 1)~⊂''
⎕ ← 'nope' 'yup' ⊃⍨(⊂lines)∊'DEC 25' 'OCT 31'