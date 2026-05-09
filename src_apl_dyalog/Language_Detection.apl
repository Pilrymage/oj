⎕IO ⎕ML ⎕FR ⎕PP ← 0 1 1287 3 4
lines ← ¯1↓(⊃⎕NGET '/dev/stdin' 1)~⊂''
y ← 'ENGLISH' 'SPANISH' 'GERMAN' 'FRENCH' 'ITALIAN' 'RUSSIAN' 'UNKNOWN' ['HELLO' 'HOLA' 'HALLO' 'BONJOUR' 'CIAO' 'ZDRAVSTVUJTE' ⍳ lines]
⎕ ← ↑(⊂'Case '),¨(⍕¨1+⍳≢y),¨(⊂': '),¨ y
