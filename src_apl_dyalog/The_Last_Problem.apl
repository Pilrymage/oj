⎕IO ⎕ML ← 0 1
lines ← ⊃⎕NGET '/dev/stdin' 1
⎕ ← 'Thank you, ', (0⊃lines) , ', and farewell!'