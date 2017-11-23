import sys
from random import randint, seed, uniform, shuffle

def gen(n=100000, iWidth=0, genType=1, maxW=10000000, maxH=100000):
	w = []
	for i in range(n):
		if randint(1,5) == 1 and i != 0:
			w.append(w[randint(0,i-1)])
		else:
			w.append(randint(1,maxW))

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
				newBlock[1] = randint(1,maxH)
			blocks.append(newBlock)

	if genType == 2:#increasing heights with small perturbations
		h = []
		for i in range(n):
			if randint(1,20) == 1 and i != 0:
				h.append(h[randint(0,i-1)])
			else:
				h.append(randint(1,maxH))

		h.sort()

		for i in range(int(n//2)):
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

if __name__ == "__main__":

	args = {key:int(value) for key, value in [x.split("=") for x in sys.argv[1:-1] if x.find("=") != -1]}
	seed(int(sys.argv[len(sys.argv)-1]))

	gen(**args)
