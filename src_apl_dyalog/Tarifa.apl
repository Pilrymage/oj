⎕IO ⎕ML ⎕FR ⎕PP ← 0 1 1287 34
lines ← (⊃⎕NGET '/dev/stdin' 1)~⊂''
xn ← ×/0 1+⍎¨lines[0 1]
⎕ ←  xn-+/⍎¨2↓lines