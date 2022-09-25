//Leanorine Lorenzana-Garcia BU-ID: U70358223
//Zachary Tan BU-ID: U71790150

//Runs in O(nlogn) time due to the use of maps

#include <vector>
#include "problem3a.h"
#include <map>
#include <string>
#include <iostream> 

using namespace std;

int mergeTogether(std::vector<std::string> &rankedListB, std::map<std::string, int> mymap, int left, int middle,  int right) {
	//mergeTogether combines and sorts
	
	//variable declaration
	std::vector<std::string> temp;
    int lsub = left;
	int rsub = middle;  
    int count = 0;
	
	//while loop to check first value of each side
    while ((lsub <= middle - 1 ) && (rsub <= right)) {
        if ((mymap.at(rankedListB[lsub])) <= (mymap.at(rankedListB[rsub]))) { //if first elem of left is less
            temp.push_back(rankedListB[lsub]); 
			lsub++; //increment left pointer
		} else {
            temp.push_back(rankedListB[rsub]);
			rsub++; //increment right pointer
            count += (middle - lsub); //increment count
			//this works because all elements to the right of the pointed element on the left
			//will always be greater than the pointed element on the right
        }
    }

    while (lsub <= middle-1) { //store remaining elements
        temp.push_back(rankedListB[lsub]); 
		lsub++;  
	}

    while (rsub <= right) {
        temp.push_back(rankedListB[rsub]);
		rsub++; 
	}
  
	for (int i = left; i <= right ; i++) //store temp in rankedListB
		rankedListB[i] = temp[i-left];
	
    return count;
}

int mergeSort(std::vector<std::string>& rankedListB, std::map<std::string, int> mymap, int left, int right){
   
	//Variable Declaration
    int middle, count = 0; 
    if (right > left) {
      	middle = (right + left)/2;
        count += mergeSort(rankedListB,  mymap, left, middle);
        count += mergeSort(rankedListB, mymap, middle + 1, right);
        //Merge the two parts
        count += mergeTogether(rankedListB, mymap, left, middle+1, right);
    }
    return count;
}

// countOOO computes the number of pairs of elements in rankedListA that are out of order in rankedListB
int countOOO(std::vector<std::string> rankedListA, std::vector<std::string> rankedListB) {
	
	//O(logn) map implements a red-black tree automatically 
	std::map<std::string, int> mymap; 

	for (int i = 0; i < rankedListA.size(); i++)
		mymap[rankedListA[i]] = i; 

	return mergeSort(rankedListB,  mymap, 0, rankedListA.size()-1);
}
