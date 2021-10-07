#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long binsearch( vector<long > tree, long max, long len , long M);

int main() {
  long N, M , input;
  vector<long> tree;
  cin >> N >> M;
  
  for(long i =0; i< N; i++){
    
    cin >> input;
    tree.push_back(input);
  }

  long max = *max_element(tree.begin(), tree.end());
  
  long ans = binsearch(tree, max, tree.size(), M );
  cout << ans;
  
  return 0;
}

long binsearch( vector<long> tree, long max, long len , long M){
  long start = 0;
  long end = max;
  long mid=0;
  long sum =0;
  long is_plus ;
  long ans = 0;

  while (start <= end){
  
    sum=0;
    
    mid = (start + end)/2;
    
    for(long i =0; i< len; i++){
      is_plus =  (tree[i] - mid);
      
      if(is_plus > 0){
        sum += is_plus;
      }
    }

    if (M <= sum){ // 더 높은 톱이 가능  
      start = mid +1;
      if(ans < mid){ // 가능한 상태에서 톱 길이의 최대 값을 저장하자.
        ans = mid;
      }
    }

    else{ // 더 낮은 톱이 필요
      end = mid -1;
    }
  }

  return ans;
}