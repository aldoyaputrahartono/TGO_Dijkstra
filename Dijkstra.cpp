#include<bits/stdc++.h>
using namespace std;

//enum nama kota yang tersedia
enum City {
	VE, JO, LO, AM, AE, JU, VP, SW, KW, PH, BW, TLE, KH, BKC
};

//mendefinisikan iPair
typedef pair<City, int> iPair;

//dist untuk menampung jarak sementara dari source ke suatu kota dan set nilai awal infinite
vector<int> dist(100, INT_MAX);

//print nama kota
string cek(int city){
	switch(city){
		case VE:
			return "VE";
			break;
		case JO:
			return "JO";
			break;
		case LO:
			return "LO";
			break;
		case AM:
			return "AM";
			break;
		case AE:
			return "AE";
			break;
		case JU:
			return "JU";
			break;
		case VP:
			return "VP";
			break;
		case SW:
			return "SW";
			break;
		case KW:
			return "KW";
			break;
		case PH:
			return "PH";
			break;
		case BW:
			return "BW";
			break;
		case TLE:
			return "TLE";
			break;
		case KH:
			return "KH";
			break;
		case BKC:
			return "BKC";
			break;
		default:
			return "NOPE";
	}
}

//adjacency list untuk undirected weighted graph
void addEdge(vector<iPair> adj[], City u, City v, int wt){
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

//algoritma Dijkstra
void shortestPath(vector<pair<City,int> > adj[], int V, City src, City dst){
    //deklarasi priority queue
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
    
    //jarak dari source ke source adalah 0
    dist[src] = 0;
    
    //masukkan ke pq dengan format pair<source, dist>
    pq.push(make_pair(src, dist[src]));
	
    //selama pq belum habis (masih ada jalan yang belum ditelusuri)
    while(!pq.empty()){
    	//u untuk menampung source
        City u = pq.top().first;
        pq.pop();
		
        //jika kota saat ini adalah kota tujuan, maka break
        if(dst == u) break;
        
        //iterasi semua kota yang bertetangga dengan kota saat ini
        for(auto x:adj[u]){
            //v untuk menampung destination dan weight menampung jaraknya
            City v = x.first;
            int weight = x.second;
            
            //jika jarak menuju kota v lebih besar daripada (jarak menuju kota sekarang + weight)
            //maka update jarak menuju kota v dan masukkan ke pq
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }
}

int main(){
    //banyak kota
    int V = 14;
    
    //inisialisasi vector sebagai daftar keterhubungan antar kota dengan pair<destination, weight>
    vector<iPair> adj[V];
    
    //input pengguna
    City asal, tujuan;
    cout<<"Kota yang tersedia:"<<endl;
    for(int i=0;i<14;i++){
        printf("%2d ",i);
        cout<<cek(i)<<endl;
    }
    cout<<"Masukkan angka kota asal: "; scanf("%d",&asal);
    cout<<"Masukkan angka kota tujuan: "; scanf("%d",&tujuan);
    
    //membentuk graph dengan memanggil fungsi addEdge(adj, source, destination, weight)
    addEdge(adj, KW, BW, 2);
    addEdge(adj, PH, BW, 2);
    addEdge(adj, KW, PH, 2);
    addEdge(adj, JO, AM, 3);
    addEdge(adj, VP, SW, 3);
    addEdge(adj, SW, KW, 3);
    addEdge(adj, BW, TLE, 3);
    addEdge(adj, BW, KH, 3);
    addEdge(adj, VE, JU, 3);
    addEdge(adj, LO, AM, 4);
    addEdge(adj, VE, AM, 4);
    addEdge(adj, JU, SW, 4);
    addEdge(adj, KH, BKC, 4);
    addEdge(adj, JO, AE, 5);
    addEdge(adj, AM, VP, 5);
    addEdge(adj, AM, SW, 6);
    addEdge(adj, KH, TLE, 6);
    addEdge(adj, VE, VP, 7);
    addEdge(adj, JU, AE, 7);
    addEdge(adj, VE, BW, 11);
    addEdge(adj, AE, BW, 13);
    
    //hitung shortest path
    shortestPath(adj, V, asal, tujuan);
    
    //output
    cout<<endl<<"Jarak dari kota "<<cek(asal)<<" ke kota "<<cek(tujuan)<<" adalah "<<dist[tujuan]<<endl;
    return 0; 
}
