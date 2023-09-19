/* class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
            sort(g.begin(),g.end());//孩子胃口
            sort(s.begin(),s.end());//饼干
            int index = s.size()-1;//保存饼干的下标
            int cnt = 0;
            for(int i = g.size()-1;i>=0;i--){//遍历胃口
                if(index >= 0 && g[i]<=s[index]){//饼干的大小要大于孩子的胃口
                    cnt++;
                    index--;
                }
            }
            return cnt;
    }
}; */