⎕ML ⎕FR ⎕PP ←  1 1287 34
⍝ Pollard's p-1 algorithm
N ← 600851475143 
j ← 323
pow ← {⍵, N|×⍨¯1↑⍵}
l ← ⌈2⍟j
⎕ ← {N|⍺×⍵}/(⌽j⊤⍨l⍴2)/(pow⍣(l-1)) 2