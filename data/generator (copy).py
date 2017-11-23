import sys
import math
from random import randint
from random import shuffle
from random import uniform

n = int(sys.argv[1])
iWidth = int(sys.argv[2])
genType = int(sys.argv[3])

maxHW = 2*n
w = []
for i in range(n):
	if randint(1,5) == 1 and i != 0:
		w.append(w[randint(0,i-1)])
	else:
		w.append(randint(1,maxHW))

w.sort()
w.reverse()

blocks = []

if genType == 1: #uniform random
	for i in range(n):
		newBlock = [0,0]
		if iWidth:
			newBlock[0] = n-i
		else:
			newBlock[0] = w[i]
		if randint(0,8) == 0 and i != 0:
			newBlock[1] = blocks[randint(0,i-1)][1];
		else:
			newBlock[1] = randint(1,maxHW)
		blocks.append(newBlock)

if genType == 2:#increasing heights with small perturbations
	h = []
	for i in range(n):
		if randint(1,20) == 1 and i != 0:
			h.append(h[randint(0,i-1)])
		else:
			h.append(randint(1,maxHW))

	h.sort()

	for i in range(int(n)):
		pos1 = randint(0,n-1)
		posD = 0;
		while True:
			posD = int(50*uniform(-1,1)**4);
			if posD + pos1 >= 0 and pos1+posD < n:
				break
		h[pos1],h[pos1+posD] = h[pos1+posD],h[pos1]
	if iWidth:
		blocks = [[n-i,h[i]] for i in range(n)]
	else:
		blocks = [[w[i],h[i]] for i in range(n)]


if not iWidth:
	shuffle(blocks)
print(n)
for block in blocks:
	print(str(block[0]) + " " + str(block[1]))