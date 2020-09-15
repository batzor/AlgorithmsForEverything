#include<iostream>
#include<vector>
#include<algorithm>

struct Meeting {
    float time;
    int a, b;
};
bool sortByTime(const Meeting &a, const Meeting &b)
{
        return a.time < b.time;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    int T, N;
    std::cin >> T;
    
    for(int t = 0;t < T;t++){
        std::cin >> N;
        int v[N];
        std::vector<Meeting> events;
        for(int i = 0; i < N;i++){
            std::cin >> v[i];
            for(int j = 0;j < i;j++){
                if(v[j] > v[i]){
                    Meeting m;
                    m.time = ((float)(i - j)) / (v[j] - v[i]);
                    m.a = i;
                    m.b = j;
                    events.push_back(m);
                }
            }
        }
        std::sort(events.begin(), events.end(), sortByTime);
        
        int inf[N];
        for(int i = 0;i < N;i++){
            std::vector<int> inf_list;
            inf_list.push_back(i);
            for(auto m : events){
                bool e1 = false, e2 = false;
                e1 = std::find(inf_list.begin(), inf_list.end(), m.a) != inf_list.end();
                e2 = std::find(inf_list.begin(), inf_list.end(), m.b) != inf_list.end();
                if(e1 && !e2){
                    inf_list.push_back(m.b);
                }
                if(e2 && !e1){
                    inf_list.push_back(m.a);
                }
            }

            inf[i] = inf_list.size();
        }

        int worst = 1, best = N;
        for(int i = 0;i < N;i++){
            if(inf[i] > worst)
                worst = inf[i];
            if(inf[i] < best)
                best = inf[i];
        }
        std::cout << best << " " << worst << std::endl;
    }
}
