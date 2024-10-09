class Solution {
public:
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
       using ll = long long;
       vector<ll> ans(heroes.size(), 0);
       vector<pair<int, int>> iheroes;
       for(int i = 0; const auto& hero : heroes){
        iheroes.emplace_back(hero, i);
        ++i;
       }

       vector<pair<int, int>> imonsters;
       for(int i = 0; const auto& monster : monsters){
        imonsters.emplace_back(monster, i);
        ++i;
       }

       sort(iheroes.begin(), iheroes.end());
       sort(imonsters.begin(), imonsters.end());

      int ihero_id = 0;
      for(int i = 0; i < imonsters.size() && ihero_id < iheroes.size();){
        if(imonsters[i].first > iheroes[ihero_id].first){
          if(ihero_id == iheroes.size() - 1){
            ++ihero_id;
            continue;
          }

          ans[iheroes[ihero_id + 1].second] += ans[iheroes[ihero_id].second];
          ++ihero_id; 
        }else{
          ans[iheroes[ihero_id].second] += coins[imonsters[i].second];
          ++i;
        }
      }

      while(ihero_id < iheroes.size() - 1){
        ans[iheroes[ihero_id + 1].second] += ans[iheroes[ihero_id].second];
        ++ihero_id;
      }

      return ans;
    }
};