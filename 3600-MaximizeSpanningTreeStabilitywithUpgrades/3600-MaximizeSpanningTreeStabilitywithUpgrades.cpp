// Last updated: 12/03/2026, 16:03:06
1class Solution {
2public:
3    
4    struct DSU {
5        vector<int> p, r;
6        DSU(int n){
7            p.resize(n);
8            r.resize(n,0);
9            for(int i=0;i<n;i++) p[i]=i;
10        }
11        int find(int x){
12            if(p[x]==x) return x;
13            return p[x]=find(p[x]);
14        }
15        bool unite(int a,int b){
16            a=find(a); b=find(b);
17            if(a==b) return false;
18            if(r[a]<r[b]) swap(a,b);
19            p[b]=a;
20            if(r[a]==r[b]) r[a]++;
21            return true;
22        }
23    };
24
25    bool can(int n, vector<vector<int>>& edges, int k, int x){
26        
27        DSU dsu(n);
28        int used=0;
29        int upgrades=0;
30
31        vector<vector<int>> opt;
32
33        for(auto &e:edges){
34            int u=e[0],v=e[1],s=e[2],must=e[3];
35
36            if(must){
37                if(s < x) return false;
38                if(!dsu.unite(u,v)) return false;
39                used++;
40            }else{
41                opt.push_back(e);
42            }
43        }
44
45        for(auto &e:opt){
46            int u=e[0],v=e[1],s=e[2];
47
48            if(s >= x){
49                if(dsu.unite(u,v)) used++;
50            }
51        }
52
53        for(auto &e:opt){
54            int u=e[0],v=e[1],s=e[2];
55
56            if(s < x && s*2 >= x){
57                if(dsu.unite(u,v)){
58                    upgrades++;
59                    used++;
60                    if(upgrades>k) return false;
61                }
62            }
63        }
64
65        return used==n-1;
66    }
67
68    int maxStability(int n, vector<vector<int>>& edges, int k) {
69        
70        int lo=0, hi=2e5, ans=-1;
71
72        while(lo<=hi){
73            int mid=(lo+hi)/2;
74
75            if(can(n,edges,k,mid)){
76                ans=mid;
77                lo=mid+1;
78            }else{
79                hi=mid-1;
80            }
81        }
82
83        return ans;
84    }
85};