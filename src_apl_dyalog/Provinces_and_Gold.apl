⎕IO ⎕ML ⎕FR ⎕PP ← 0 1 1287 34
lines ← ⊃(⊃⎕NGET '/dev/stdin' 1)~⊂''
⎕ ← 'Copper' 'Estate or Copper' 'Estate or Silver' 'Duchy or Silver' 'Duchy or Gold' 'Province or Gold' ⊃⍨ 0 2 3 5 6 8 ⍸ 3 2 1 +.×⍎lines
