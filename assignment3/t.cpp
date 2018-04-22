#include <iostream>   // for I/O facilities
#include <algorithm>
#include <ctime>
#include <time.h>
#include "btree_set.h" // 
using namespace std;

double elapsed_time(clock_t start, clock_t finish) {
	//return time in milliseconds
	return (finish-start)/(double)(CLOCKS_PER_SEC/1000);
}

int main (int argc, char * const argv[]) {

	int const SIZE = 100000;
	int TIMES = 30;

	srand( time(NULL) );

	clock_t start, finish;
	double insertingTime = 0;
	int treeSize = 0;
	int nodes = 0;
	int height = 0;
	int bytes = 0;

    cout << "\n\nbtree_set Class Test Program 1 - START\n\n";
	
	// Make a btree_set, and verify that empty() says it is empty.

	btree::btree_set<int,std::less<int>,std::allocator<int>,64> S1; //minimum size is 16 try 32,64, 128 etc
	btree::btree_set<int,std::less<int>,std::allocator<int>,32> S2;
	btree::btree_set<int,std::less<int>,std::allocator<int>,64> S3;
	btree::btree_set<int,std::less<int>,std::allocator<int>,128> S4;
	btree::btree_set<int,std::less<int>,std::allocator<int>,256> S5;
	btree::btree_set<int,std::less<int>,std::allocator<int>,512> S6;
	btree::btree_set<int,std::less<int>,std::allocator<int>,1024> S7;
	btree::btree_set<int,std::less<int>,std::allocator<int>,2048> S8;
	btree::btree_set<int,std::less<int>,std::allocator<int>,4096> S9;
	btree::btree_set<int,std::less<int>,std::allocator<int>,8192> S10;
	btree::btree_set<int,std::less<int>,std::allocator<int>,16384> S11;
	
	// first one (and parts of the second and third) give the type of the values to be stored in the Btree
	//fourth template argument is the node size in bytes
	//cout << "S1.empty() = " << S1.empty() << "\n";
	//cout << "S1.size() = " << S1.size() << "\n";
	//cout << "S1.nodes() = " >> S1.bytes_used() << "\n";

	/*
       
	// Put something in it, and verify that it is no longer empty.
	cout << "S1: inserting 10" << "\n";
        S1.insert(10);
	cout << "S1.empty() = " << S1.empty() << "\n";
	cout << "S1.size() = " << S1.size() << "\n";
	//cout << "S1.nodes() = " >> S1.nodes() << "\n";

*/
	cout << "\n\nbtree_set Class Test Program 1 - DONE\n\n";

	int arr[SIZE];

	//int *arr1 = 0;
	//arr1 = new int[10000];

	for (int i = 0; i < SIZE; i++) {
		//arr[i] = rand() % SIZE*10;
		arr[i] = i;
	}
	double average = 0;

	random_shuffle(std::begin(arr), std::end(arr));
	for (int j = 0; j < TIMES; j++) {
		random_shuffle(std::begin(arr), std::end(arr));
		start = clock();	
		for (int i =0; i < SIZE; i++) {
		//while (!S3.full()) {
			//int x = rand() % SIZE*10;
			S1.insert(arr[i]);

		}

		finish = clock();
		insertingTime += elapsed_time(start, finish);
		treeSize += S1.size();
		nodes += S1.nodes();
		height += S1.height(); 
		bytes += S1.bytes_used();
		average += S1.average_bytes_per_value();
		if (j != TIMES-1) {
		S1.clear();	
		}
	}		

	cout << "inserting random numbers into Btree\n";
	cout << "S1.size() = " << treeSize / TIMES << "\n";
	cout << "S1.nodes() = " << nodes / TIMES << "\n";
	cout << "S1.height() = " << height / TIMES << "\n";
	cout << "S1.average_bytes_per_value() = " << S1.average_bytes_per_value() << "\n";
	cout << "Insertion time = " << insertingTime / TIMES << "\n";
	cout << "Bytes Used by btree = " << bytes / TIMES << "\n";
	//cout << "Average/TIME = " << average / TIMES << "\n";
	cout << "fullness of the tree = " << S1.fullness() << "\n";
	cout << "overhead = " << S1.overhead() << "\n";



    return 0;
}