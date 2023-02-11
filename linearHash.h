#include <bits/stdc++.h>
#include <iostream>
#include "Vector.h"
#include "linkedList.h"
#include "String.h"
using namespace std;



class LinearHash {	
	private:

		LinkedList *primary;
		LinkedList *overflow;
		int BucketSize,ptr;
		Pair* bucket = new Pair(primary,overflow);
		Vector *v = new Vector(bucket);
		Vector *s = new Vector(0);
		int size;
		int capacity;

		



