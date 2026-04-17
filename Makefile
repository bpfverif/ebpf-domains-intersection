all:
	gcc main.c intersection_allwise.c intersection_pairwise.c tnum.c -o intersection.out

clean:
	rm intersection.out