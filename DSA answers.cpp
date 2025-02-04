#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <numeric>
#include <climits>
#include <String>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
// Find the largest element inside an array
//BruteForce appoarch has a time complexiety of NlogN which is still more then looping method
int findingLargestElementBF(vector <int> arr){
    sort(arr.begin(), arr.end());
    return arr[arr.size() -1];
}
//Looping approach and also this is a optimal approach because it has O(n) time complexiety which is the lowest posiible
int findLargestElement(vector <int> arr){
    int variable = arr[0];
    for(int i = 0; i< arr.size(); i++){
        if(variable <= arr[i]){
            variable = arr[i];
        }
    }
    return variable;
}
//recursion Approach
int findLargestElementRecur(vector <int> array , int n, int element){
    if(n == array.size() -1){
         return element;
    }
    if(element <= array[n]){
        element = array[n];
        return findLargestElementRecur(array, n+1, element);
    }
}
//Find the second largest element inside an array but catch is to not using sorting method
//Brute force appoarch -- this has a time complexiety of O(2n) which is good
int findSecondLargest(vector <int> vec){
    int largest = INT_MIN;
    int secondLargest = vec[0];
    for(int i = 0; i < vec.size() -1; i++){
        if(largest <= vec[i]){
            largest = vec[i];
        }
    }
    for(int j = 0; j < vec.size(); j++){
        if(secondLargest < vec[j] && vec[j] != largest){
            secondLargest = vec[j];
        }
    }
    return secondLargest;
}
//This is a most optimal approach to solve it. this has only time complexiety of O(n).
int findSecondLargestOP(vector <int> vec){
    int largest = vec[0];
    int secondLargest = INT_MIN;
    for(int i = 0; i < vec.size(); i++){
        if(largest < vec[i]){
            secondLargest = largest;
            largest = vec[i];
        }
        else if(vec[i] > secondLargest && vec[i] < largest){
            secondLargest = vec[i];
        }
    }
    return secondLargest;
}
// Check the array is sorted or not
bool findArrayIsSorted(vector <int> &array){
    int check = array[0];
    for(int i = 1; i < array.size(); i++){
        if(check <= array[i]){
            check = array[i];
            if(check == array.size() -2 && array[i] == array.size() -1){
                return true;
            }
        }
    }
    return false;
}
//Rotate the array by one place on left hand side
void rotateArray(vector <int> &vec){
 int temp  = vec[0];
 for(int i = 1 ; i < vec.size(); i++){
    vec[i-1] = vec[i]; 
 }
 vec[vec.size()-1] = temp;
}

//Push back the zeros to the back
void zeroShouldBeBack(vector <int> &vec){
    int first = 0;
    int index = 1;
    for(int i = 1; i < vec.size(); i++){
        if(vec[i] == 0){
            continue;
        }
        vec[index] = vec[i];
        first = index;
        index++;
    }
}
// move an array to kth place
void moveNElement(vector <int> &vec, int n){
    int k = vec.size();
     n = n%k;
    reverse(vec.begin(), vec.end());
    reverse(vec.begin(), vec.begin() + k);
    reverse(vec.begin() + k, vec.end());
    
}
// learning hashing :- hash will create different array and store repeatation in their according to ascii value
//we need to create a array with the highest value which is shown so we can occupy all the elements, it is uses more memory.
void learningHashing(vector <int> dev, int number){
    int hash[256] = {0};
    for(int i = 0; i < dev.size(); i++){
        hash[dev[i]]++;
    }
    cout << hash[number] << endl;
}
// we will not declare size of an array because it is storing data dynamically
// this will use less memory compare to hashing
// Did not declare map, so it was showing an error, later declared on top. 
void mapLearning(vector <int> vec, int key){
    map<int, int> mpp;
    for(int i = 0; i< vec.size(); i++){
        mpp[vec[i]]++;
    }
    cout << key << " -> " << mpp[key] << endl;
    
}

//Learned unordered map which is very good for time complexiety to store and fetch the data 
void unorderedMapLeaning(vector <int> vec, int key){
    unordered_map <int, int> mpp;
    for(int i = 0; i < vec.size(); i++){
        mpp[vec[i]]++;
    }
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " -> " << mpp[vec[i]] << endl;
    }
    

}

vector <int> nextAnswer(vector <int> &a){
    next_permutation(a.begin(), a.end());
    return a;
}
int main(){
    vector <int> vec = {1,2,3,4,5,6,5,4,4,2,2};
    int alpha = 2;
// hash is used below
learningHashing(vec, alpha);
// map function called using same resources because everytime we declare we are using memory.(Below use less memory then hash and sorted order)
mapLearning(vec, alpha);
// unordered map below
unorderedMapLeaning(vec, 5);
}


