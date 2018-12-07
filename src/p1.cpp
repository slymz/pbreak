/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto i = head;
        auto mid = head;
        bool inc = false;
        while( i->next  ) {
            i = i->next;
            if(inc) mid = mid->next;
            inc = !inc;
        }
        return inc ? mid->next : mid;
    }
};

// what kind of fresh hell is this?!
static int speedHackh=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();




class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int b = 0;
        int e = A.size()-1;
        while(b<e) {
            int peak = (b+e)/2;
            if( A[peak] < A[peak+1] ) {
                b = peak+1;
            }
            else {
                e = peak;
            }
        }
        return b;
    }
};


class Solution {
public:
    bool buddyStrings(string const & A, string const & B) {
        int n = A.size();
        if(n != B.size()) {
            return false;
        }
        int swapped = -1; // -1 notinit, 0 not swapped, 1 swapped
        int j;
        for(int i = 0; i<n; ++i) {
            if(A[i] == B[i]) continue;
            if (swapped == -1) {
                j = i;
                swapped = 0;
            }
            else if (swapped == 0) {
                if( A[i] == B[j] && B[i] == A[j]) swapped = 1;
                else return false;
            }
            else {
                return false;
            }
        }



        if(swapped == -1) {
            // A == B
            unordered_map<char, int> charCnt;
            for(char c  : A) {
                if(++charCnt[c] == 2) return true;
            }
        }

        return swapped == 1;
    }
};


class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {


        std::vector< std::vector<int> > adj(N);
        for( auto const & edge : dislikes ){
            adj[edge[0]-1].push_back(edge[1]-1);
            adj[edge[1]-1].push_back(edge[0]-1);
        }

        std::vector<int> q;
        std::vector<int> color(N,-1);
        for( int i = 0; i<N; ++i ) {
            if( color[i] != -1 ) continue;
            q.clear();
            q.push_back(i);
            while(!q.empty()) {
                int u = q.front(); q.erase(q.begin());
                for( int v : adj[u] ) {
                    if(color[v] == -1) {
                        color[v] = (color[u]+1) % 2;
                        q.push_back(v);
                    }
                    else if( color[v] == color[u] ) return false;
                }
            }
        }
        return true;
    }
};
