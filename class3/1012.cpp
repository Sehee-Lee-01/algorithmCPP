#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int T, M, N, K, tempX, tempY;
    scanf("%d", &T);
    for (int i=0; i<T; i++) {
        scanf("%d %d %d", &M, &N, &K);

        // Make cabbage reference list
        set<pair<int, int>> caggageLocation;
        for (int j=0; j<K; j++) {
            scanf("%d %d", &tempX, &tempY);
            caggageLocation.insert(make_pair(tempX, tempY));
        }
        
        // Initialize visited cabbage Index
        vector<pair<int, int>> willVisit; // stack
        set<pair<int, int>> visited;
        int needLarva = 0;

        // Start visit
        for (auto cabbage: caggageLocation) {
            // if not visited before
            if (visited.find(cabbage)==visited.end()) {
                willVisit.push_back(cabbage);
                needLarva++;
                // Visit all cabbage lump
                while(!willVisit.empty()) {
                    // Visit back cabbage of stack
                    pair<int, int> currentCabbage = willVisit.back();
                    willVisit.pop_back();
                    visited.insert(currentCabbage);
                    
                    // Current cabbage location
                    tempX=currentCabbage.first, tempY=currentCabbage.second;
                    
                    // near cabbage(4 path) 
                    pair<int, int> nearCabbageLocation;
                    set<pair<int, int>>::iterator findNearCabbage;                    
                    for (int path=0; path<4; path++) {
                        switch (path) {
                        case 0: // up
                            if (tempY>0) {nearCabbageLocation = make_pair(tempX, tempY-1);}
                            break;
                        case 1: //right
                            if (tempY<50) {nearCabbageLocation = make_pair(tempX, tempY+1);}   
                            break;
                        case 2: // left
                            if (tempX>0) {nearCabbageLocation = make_pair(tempX-1, tempY);}
                            break;                   
                        case 3: // down
                            if (tempX<50) {nearCabbageLocation = make_pair(tempX+1, tempY);}                
                            break;
                        }
                        // find near cabbage in caggage location list
                        findNearCabbage = caggageLocation.find(nearCabbageLocation);
                        if (findNearCabbage!=caggageLocation.end()) {
                            // if not visited before
                            if (visited.find(nearCabbageLocation)==visited.end()) {
                                willVisit.push_back(nearCabbageLocation);
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", needLarva);
    }
}