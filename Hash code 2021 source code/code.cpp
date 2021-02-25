#include <bits/stdc++.h>
using namespace std;

struct street{
    int B, E, L;
    string name;
};

struct car{
    int P;
    vector<string> path;
};

struct tp{
    string name;
    int no_cars, total_time;
};

int main()
{
    int D, I, S, V, F;
    cin>>D>>I>>S>>V>>F;
    
    unordered_map<string, int> streetTime;
    unordered_map<string, int> totalL;
    unordered_map<string, int> noCarsInStreet;
    
    vector<street> strts(S);
    
    //unordered_map<int, pair<string, pair<int, int>>> graph;
    unordered_map<int, vector<tp>> graph;
    
    for(int i=0; i<S; i++){
        int B, E, L;
        string name;
        cin>>B>>E>>name>>L;
        
        streetTime[name] = L;
        
        street st;
        st.B = B;
        st.E = E;
        st.name = name;
        st.L = L;
        strts[i] = st;
    }
    
    vector<car> cars(V);
    
    for(int i=0; i<V; i++){
        car c;
        int P;
        cin>>P;
        c.P = P;
        
        string first_car;
        
        int totalTime = 0;
        
        for(int j=0; j<P; j++){
            string path;
            cin>>path;
            if(j == 0){
                first_car = path;
                noCarsInStreet[first_car]++;
            }
            totalTime += streetTime[path];
            c.path.push_back(path);
        }
        
        totalL[first_car] = totalTime;
        
        cars[i] = c;
    }
    
    
    // for(int i=0; i<S; i++){
    //     graph[strts[i].E] = {strts[i].name, {noCarsInStreet[strts[i].name], totalL[strts[i].name]}};
    // }
    
    for(int i=0; i<S; i++){
        tp temp;
        string temp_name = strts[i].name;
        temp.name = temp_name;
        temp.no_cars = noCarsInStreet[temp_name];
        temp.total_time = totalL[temp_name];
        int End = strts[i].E;
        graph[End].push_back(temp);
    }

    cout<<graph.size()<<endl;
    
    for(auto g: graph){
        
        cout<<g.first<<endl;
        if((g.second).size() == 1){
            cout<<1<<endl;
            auto vec = g.second;
            string output_here = vec[0].name;
            cout<<output_here<<" "<<2;
        }
        else{
            cout<<(g.second).size()<<endl;
            
            int totaltimetime = 0;
            int total_cars = 0;
            
            auto vec = g.second;
            for(int i=0; i<vec.size(); i++){
                totaltimetime += vec[i].total_time;
                total_cars += vec[i].no_cars;
            }
            
            auto vec2 = g.second;
            for(int i=0; i<vec2.size(); i++){
                int ans_here = (int)((vec2[i].total_time / totaltimetime)*(total_cars));
                cout<<vec2[i].name<<" "<<ans_here<<endl;
            }
        }
            
    }
    
    return 0;
}
