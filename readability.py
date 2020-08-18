from cs50 import get_string

text = get_string("text :")
lc = 0
wc = 1
sc = 0
n = len(text)
for i in range(n):
    if ((text[i] <= 'z' and  text[i] >= 'a') or (text[i] <= 'Z' and text[i] >= 'A')):
        lc += 1
    if (text[i] == ' '):
        wc += 1
    if (text[i] == '.' or text[i] == '!' or text[i] == '?'):
        sc += 1
    else:
        continue
    
X = round(0.0588 * lc * 100 / wc - 0.296 * sc * 100 / wc - 15.8)
if (X > 16):
    print("Grade 16+\n")
if (X > 1 and X <= 16):
    print("Grade \n", X)
if (X < 1):
    print("Before Grade 1\n")