import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def postorder(start, end):
    if start > end:
        return
    
    root = tree[start]

    idx = start + 1
    while idx <= end and tree[idx] < root:
        idx += 1
    
    postorder(start + 1, idx - 1)
    postorder(idx, end)

    print(root)

tree = []

while True:
    line = input().strip()
    if not line:
        break
    tree.append(int(line))

postorder(0, len(tree) - 1)

