import random
alpha = 'abcdefghijklmnopqrstuvwxyz'
npt = open('a.txt', 'w')
ept = open('b.txt', 'w')
i = 0
a = input();
while i < int(a):
    npt.write(random.choice(alpha))
    ept.write(random.choice(alpha))
    i += 1
