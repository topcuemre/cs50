import csv
from sys import argv,exit

def maxlen(s, sub):
    ans = [0] * len(s)
    for i in range(len(s) - len(sub), -1, -1):
        if s[i: i + len(sub)] == sub:
            if i +len(sub) > len(s) - 1:
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i + len(sub)]
    
    return max(ans)

def prints(reader, arr):
    for i in reader:
        x = i[0]
        vl = [int(val) for val in i[1:]]
        if vl == arr:
            print(x)
            return
    print("no match")
    
def main():
    if (not(len(argv) == 3)):
        print("incorrect number of arguments")
        exit(1)
    database = argv[1]
    with open(database) as file:
        readd = csv.reader(file)
        seqs = next(readd)[1:]
        seq = argv[2]
        with open(seq) as file:
            reads = file.read()
            res = [ maxlen(reads,diz) for diz in seqs]
        prints(readd, res)
    
main()
        
        
    
    
    





