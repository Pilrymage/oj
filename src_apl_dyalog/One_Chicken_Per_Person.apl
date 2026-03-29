⎕IO ⎕ML ⎕FR ⎕PP ← 0 1 1287 34
lines ← ⊃(⊃⎕NGET '/dev/stdin' 1)~⊂''
⎕ ← { 
    ⍵>1:'Dr. Chaz will have',⍵,'pieces of chicken left over!'
    ⍵=1:'Dr. Chaz will have 1 piece of chicken left over!'
    ⍵=¯1:'Dr. Chaz needs 1 more piece of chicken!'
    ⍵<¯1:'Dr. Chaz needs',(|⍵),'more pieces of chicken!'
}--/⍎lines
⍝ ⎕ ← { ⍵>1:'Dr. Chaz will have',⍵,'pieces of chicken left over!'⋄⍵=1:'Dr. Chaz will have 1 piece of chicken left over!'⋄⍵=¯1:'Dr. Chaz needs 1 more piece of chicken!'⋄⍵<¯1:'Dr. Chaz needs',(|⍵),'more pieces of chicken!'}--/⍎lines