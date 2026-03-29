⎕IO ⎕ML ← 0 1
lines ← ⊃⎕NGET '/dev/stdin' 1
results ← (×/2,⍎)¨ lines
lines_with_nl ← (⍕¨ results) ,¨ ⎕UCS 10
⎕ ← lines_with_nl