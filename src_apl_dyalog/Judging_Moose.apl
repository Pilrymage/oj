⎕IO ⎕ML ⎕FR ⎕PP ← 0 1 1287 34
lines ← ⊃(⊃⎕NGET '/dev/stdin' 1)~⊂''
⎕ ← {∧/0=⍵:'Not a moose'⋄=/⍵:'Even',+/⍵⋄'Odd',2×⌈/⍵}⍎lines