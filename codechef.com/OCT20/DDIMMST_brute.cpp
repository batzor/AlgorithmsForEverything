#include <bits/stdc++.h>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ar array
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T> bool umin(T& a, const T& b) {
    return b<a?a=b, 1:0;

}
template<class T> bool umax(T& a, const T& b) { 
    return a<b?a=b, 1:0;

} 

ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb)/2;
        f(mb)?rb=mb:lb=mb+1; 

    } 
    return lb;

}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb+1)/2;
        f(mb)?lb=mb:rb=mb-1; 

    } 
    return lb;

}

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
    cin >> x;

}
void read(double& d) {
    string t;
    read(t);
    d=stod(t);
}

void read(long double& d) {
    string t;
    read(t);
    d=stold(t);
}

template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);

}
template<class A> void read(vt<A>& x) {
    EACH(a, x)
        read(a);

}
template<class A, size_t S> void read(array<A, S>& x) {
    EACH(a, x)
        read(a);

}

string to_string(char c) {
    return string(1, c);

}
string to_string(bool b) {
    return b?"true":"false";

}
string to_string(const char* s) {
    return string(s);

}
string to_string(string s) {
    return s;

}
string to_string(vt<bool> v) {
    string res;
    FOR(sz(v))
        res+=char('0'+v[i]);
    return res;

}

template<size_t S> string to_string(bitset<S> b) {
    string res;
    FOR(S)
        res+=char('0'+b[i]);
    return res;

}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
        if(!f)
            res+=' ';
        f=0;
        res+=to_string(x);

    }
    return res;

}

template<class A> void write(A x) {
    cout << to_string(x);

}
template<class H, class... T> void write(const H& h, const T&... t) { 
    write(h);
    write(t...);

}
void print() {
    write("\n");

}
template<class H, class... T> void print(const H& h, const T&... t) { 
    write(h);
    if(sizeof...(t))
        write(' ');
    print(t...);

}

void DBG() {
    cerr << "]" << endl;

}
template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t))
        cerr << ", ";
    DBG(t...);

}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

template<class T> void offset(ll o, T& x) {
    x+=o;

}
template<class T> void offset(ll o, vt<T>& x) {
    EACH(a, x)
        offset(o, a);

}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
    EACH(a, x)
        offset(o, a);

}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);

}

template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
    v=vt<T>(n, x);

}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
    v=vt<T>(n);
    EACH(a, v)
        vti(a, x, m);
}

void gg() {
    print(-1);
    exit(0);
}


// A structure to represent a node in adjacency list 
struct AdjListNode { 
    int dest; 
    int weight; 
    struct AdjListNode* next; 
}; 

// A structure to represent an adjacency list 
struct AdjList { 
    struct AdjListNode* head; // pointer to head node of list 
}; 

// A structure to represent a graph. A graph is an array of adjacency lists. 
// Size of array will be V (number of vertices in graph) 
struct Graph { 
    int V; 
    struct AdjList* array; 
}; 

// A utility function to create a new adjacency list node 
struct AdjListNode* newAdjListNode(int dest, int weight) 
{ 
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest; 
    newNode->weight = weight; 
    newNode->next = NULL; 
    return newNode; 
} 

// A utility function that creates a graph of V vertices 
struct Graph* createGraph(int V) 
{ 
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)); 
    graph->V = V; 

    // Create an array of adjacency lists. Size of array will be V 
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList)); 

    // Initialize each adjacency list as empty by making head as NULL 
    for (int i = 0; i < V; ++i) 
        graph->array[i].head = NULL; 

    return graph; 
} 

// Adds an edge to an undirected graph 
void addEdge(struct Graph* graph, int src, int dest, int weight) 
{ 
    // Add an edge from src to dest. A new node is added to the adjacency 
    // list of src. The node is added at the beginning 
    struct AdjListNode* newNode = newAdjListNode(dest, weight); 
    newNode->next = graph->array[src].head; 
    graph->array[src].head = newNode; 

    // Since graph is undirected, add an edge from dest to src also 
    newNode = newAdjListNode(src, weight); 
    newNode->next = graph->array[dest].head; 
    graph->array[dest].head = newNode; 
} 

// Structure to represent a min heap node 
struct MinHeapNode { 
    int v; 
    int key; 
}; 

// Structure to represent a min heap 
struct MinHeap { 
    int size; // Number of heap nodes present currently 
    int capacity; // Capacity of min heap 
    int* pos; // This is needed for decreaseKey() 
    struct MinHeapNode** array; 
}; 

// A utility function to create a new Min Heap Node 
struct MinHeapNode* newMinHeapNode(int v, int key) 
{ 
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode)); 
    minHeapNode->v = v; 
    minHeapNode->key = key; 
    return minHeapNode; 
} 

// A utilit function to create a Min Heap 
struct MinHeap* createMinHeap(int capacity) 
{ 
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap)); 
    minHeap->pos = (int*)malloc(capacity * sizeof(int)); 
    minHeap->size = 0; 
    minHeap->capacity = capacity; 
    minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*)); 
    return minHeap; 
} 

// A utility function to swap two nodes of min heap. Needed for min heapify 
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) 
{ 
    struct MinHeapNode* t = *a; 
    *a = *b; 
    *b = t; 
} 

// A standard function to heapify at given idx 
// This function also updates position of nodes when they are swapped. 
// Position is needed for decreaseKey() 
void minHeapify(struct MinHeap* minHeap, int idx) 
{ 
    int smallest, left, right; 
    smallest = idx; 
    left = 2 * idx + 1; 
    right = 2 * idx + 2; 

    if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key) 
        smallest = left; 

    if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key) 
        smallest = right; 

    if (smallest != idx) { 
        // The nodes to be swapped in min heap 
        MinHeapNode* smallestNode = minHeap->array[smallest]; 
        MinHeapNode* idxNode = minHeap->array[idx]; 

        // Swap positions 
        minHeap->pos[smallestNode->v] = idx; 
        minHeap->pos[idxNode->v] = smallest; 

        // Swap nodes 
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]); 

        minHeapify(minHeap, smallest); 
    } 
} 

// A utility function to check if the given minHeap is ampty or not 
int isEmpty(struct MinHeap* minHeap) { 
    return minHeap->size == 0; 
} 

// Standard function to extract minimum node from heap 
struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
{ 
    if (isEmpty(minHeap)) 
        return NULL; 

    // Store the root node 
    struct MinHeapNode* root = minHeap->array[0]; 

    // Replace root node with last node 
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1]; 
    minHeap->array[0] = lastNode; 

    // Update position of last node 
    minHeap->pos[root->v] = minHeap->size - 1; 
    minHeap->pos[lastNode->v] = 0; 

    // Reduce heap size and heapify root 
    --minHeap->size; 
    minHeapify(minHeap, 0); 

    return root; 
} 

// Function to decrease key value of a given vertex v. This function 
// uses pos[] of min heap to get the current index of node in min heap 
void decreaseKey(struct MinHeap* minHeap, int v, int key) 
{ 
    // Get the index of v in heap array 
    int i = minHeap->pos[v]; 

    // Get the node and update its key value 
    minHeap->array[i]->key = key; 

    // Travel up while the complete tree is not hepified. 
    // This is a O(Logn) loop 
    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key) { 
        // Swap this node with its parent 
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2; 
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i; 
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]); 

        // move to parent index 
        i = (i - 1) / 2; 
    } 
} 

// A utility function to check if a given vertex 
// 'v' is in min heap or not 
bool isInMinHeap(struct MinHeap* minHeap, int v) 
{ 
    if (minHeap->pos[v] < minHeap->size) 
        return true; 
    return false; 
} 

// A utility function used to print the constructed MST 
void printArr(int arr[], int n) 
{ 
    for (int i = 1; i < n; ++i) 
        printf("%d - %d\n", arr[i], i); 
} 

// The main function that constructs Minimum Spanning Tree (MST) 
// using Prim's algorithm 
void PrimMST(struct Graph* graph, int parent[]) 
{ 
    int V = graph->V; // Get the number of vertices in graph 
    int key[V]; // Key values used to pick minimum weight edge in cut 

    // minHeap represents set E 
    struct MinHeap* minHeap = createMinHeap(V); 

    // Initialize min heap with all vertices. Key value of 
    // all vertices (except 0th vertex) is initially infinite 
    for (int v = 1; v < V; ++v) { 
        parent[v] = -1; 
        key[v] = INT_MAX; 
        minHeap->array[v] = newMinHeapNode(v, key[v]); 
        minHeap->pos[v] = v; 
    } 

    // Make key value of 0th vertex as 0 so that it 
    // is extracted first 
    key[0] = 0; 
    minHeap->array[0] = newMinHeapNode(0, key[0]); 
    minHeap->pos[0] = 0; 

    // Initially size of min heap is equal to V 
    minHeap->size = V; 

    // In the following loop, min heap contains all nodes 
    // not yet added to MST. 
    ll score = 0;
    while (!isEmpty(minHeap)) { 
        // Extract the vertex with minimum key value 
        struct MinHeapNode* minHeapNode = extractMin(minHeap); 
        int u = minHeapNode->v; // Store the extracted vertex number 

        // Traverse through all adjacent vertices of u (the extracted 
        // vertex) and update their key values 
        struct AdjListNode* pCrawl = graph->array[u].head; 
        while (pCrawl != NULL) { 
            int v = pCrawl->dest; 

            // If v is not yet included in MST and weight of u-v is 
            // less than key value of v, then update key value and 
            // parent of v 
            if (isInMinHeap(minHeap, v) && pCrawl->weight < key[v]) { 
                key[v] = pCrawl->weight; 
                score += pCrawl->weight;
                parent[v] = u; 
                decreaseKey(minHeap, v, key[v]); 
            } 
            pCrawl = pCrawl->next; 
        } 
    } 
} 

void solve() {
    int n, d;
    read(n, d);
    vt<vt<int>> vertices;
    FOR(n){
        vt<int> v;
        FOR(d){
            int x;
            read(x);
            v.pb(x);
        }
        vertices.pb(v);
    }

    struct Graph* graph = createGraph(n);
    FOR(i, vertices.size()){
        FOR(j, i + 1, vertices.size()){
            int w = 0;
            FOR(k, d){
                w -= abs(vertices[i][k] - vertices[j][k]);
            }
            addEdge(graph, i, j, w);
        }
    }
    int parent[n];
    PrimMST(graph, parent);
    ll score = 0;
    FOR(i, 1, n){
       int v = parent[i];
       FOR(k, d){
           score += abs(vertices[i][k] - vertices[v][k]);
       }
    }
    print(score);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    //read(t);
    FOR(t) {
        solve();
    }
}
