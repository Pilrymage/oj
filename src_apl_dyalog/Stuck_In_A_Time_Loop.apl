⎕IO ⎕ML ← 0 1
lines ← ⊃⎕NGET '/dev/stdin' 1
n ← ⍎0⊃lines
⎕ ← ↑(' Abracadabra',⍨⍕)¨1↓⍳1+n