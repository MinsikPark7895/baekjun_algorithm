import sys
input = sys.stdin.readline

cnt = {}    # {나무이름: 개수}
total = 0

for line in sys.stdin:
    name = line.strip()
    if not name:
        continue
    total += 1
    cnt[name] = cnt.get(name, 0) + 1

for name in sorted(cnt.keys()):
    print(f"{name} {cnt[name]*100/total:.4f}")