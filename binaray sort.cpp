#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void disp(vector<int> arr);
int binsearch(vector<int> arr, int target);

int main() {
  vector<int> arr = {4,3,5,6,1,2,9,8,7};
  int target = 1;
  sort(arr.begin(), arr.end(), greater<int>() );
  disp(arr);
  
  sort(arr.begin(), arr.end() );
  disp(arr);
  
  int loc = binsearch(arr, target);
  if(loc != -1){
    cout << "the value you looking for is in " << loc << " index and the value is " << target;
  }
  else{
    cout << "The " << target << " does not exist in the vector";
  }
  
}

void disp(vector<int> arr){
  for(int i =0 ; i< arr.size(); i++){
    cout << arr[i] << " ";
  }
  cout << '\n';
}

int binsearch(vector<int> arr, int target){
  int len = arr.size();
  int start= 0;
  int end = len-1;
  int search = -1;
  while(start <= end ){
    int mid = (start + end)/2;
    if(target == arr[mid]){
      search = mid;
      break;
    }
    else if(target < arr[mid]){
      end = mid - 1;
    }
    else {
      start = mid+1;
    }
    
  }
  return search;
}