#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<int> input(int);
int maxPossibleVolume(vector<int>&, int);

int main(){
    int n;
    cin>>n;

    vector<int> water = input(n);
    cout<<"Max Volume this container can hold: "<<maxPossibleVolume(water, n);
}

int maxPossibleVolume(vector<int>& water, int n){
    int s=0, e=n-1; // pointer to start and end of the given data
    int volume = 0;

    for(int f=0, r=e; f<r; f++, r--){
        if(water[s]<water[f]){
            s=f;
        }
        if(water[e]<water[r]){
            e=r;
        }
    }
    return min(water[s],water[e]) * abs(s-e); // calculate volume and return it
}

vector<int> input(int n){
    vector<int> water(n);
    for(int j=0; j<n; j++)
        cin>>water[j];
    return water;
}
