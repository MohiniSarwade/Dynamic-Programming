
////with repaeatation with permutation

#include <bits/stdc++.h> 
using namespace std; 

set<vector<int>>s;
// The vector v stores current subset. 
void printAllSubsetsRec(int arr[], int n, vector<int> v, 
						int sum) 
{ 
	// If remaining sum is 0, then print all 
	// elements of current subset. 
	if (sum == 0) { 
      	//sort(v.begin(),v.end());
      	s.insert(v); 
		return; 
	} 

	// If no remaining elements, 
	if (n == 0) 
		return; 

	// We consider two cases for every element. 
	// a) We do not include last element. 
	// b) We include last element in current subset. 
	printAllSubsetsRec(arr, n - 1, v, sum); 
  for(int i=0;i<n;i++)
  {
    if(arr[i]<=sum)
    {	
      	v.push_back(arr[i]); 
		printAllSubsetsRec(arr, n, v, sum - arr[i]);
      	v.pop_back();
    }
  }
} 

// Wrapper over printAllSubsetsRec() 
void printAllSubsets(int arr[], int n, int sum) 
{ 
	vector<int> v; 
	printAllSubsetsRec(arr, n, v, sum); 
  	for(auto i:s)
    {
      vector<int>v=i;
      for(int j=0;j<v.size();j++)
        cout<<v[j]<<" ";
   	  cout<<endl;
    }
} 

// Driver code 
int main() 
{ 
	int arr[] = {1,2,5}; 
	int sum = 5; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printAllSubsets(arr, n, sum); 
	return 0; 
} 
/////////////////////////////////////////////////////////////////////////////4

//without repaeatation without permutation

#include <bits/stdc++.h> 
using namespace std; 
  
// The vector v stores current subset. 
void printAllSubsetsRec(int arr[], int n, vector<int> v, 
                        int sum) 
{ 
    // If remaining sum is 0, then print all 
    // elements of current subset. 
    if (sum == 0) { 
        for (auto x : v) 
            cout << x << " "; 
        cout << endl; 
        return; 
    } 
  
    // If no remaining elements, 
    if (n == 0) 
        return; 
  
    // We consider two cases for every element. 
    // a) We do not include last element. 
    // b) We include last element in current subset. 
    printAllSubsetsRec(arr, n - 1, v, sum); 
    v.push_back(arr[n - 1]); 
    printAllSubsetsRec(arr, n - 1, v, sum - arr[n - 1]); 
} 
  
// Wrapper over printAllSubsetsRec() 
void printAllSubsets(int arr[], int n, int sum) 
{ 
    vector<int> v; 
    printAllSubsetsRec(arr, n, v, sum); 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 2, 5, 8, 4, 6, 11 }; 
    int sum = 13; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    printAllSubsets(arr, n, sum); 
    return 0; 
} 