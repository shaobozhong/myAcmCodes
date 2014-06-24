struct Trie 
{
        int mk[maxn];
        int child[maxn][maxc];
        int dfn;
        inline void New(int p){
                memset(child[p],0,sizeof(child[p]));
        }
        void init()        {
                memset(mk,0,sizeof(mk));
                New(0);
                dfn = 0;
        }
        int add(char str[]){
                int i,p = 0,l = strlen(str);
                for(i = 0;i < l;++i){
                        if(!child[p][str[i] - 'a']){
                                child[p][str[i] - 'a'] = ++dfn;
                                New(dfn);
                        }
                        p = child[p][str[i] - 'a'];
                }
                mk[p]++;
                return p;
        }
        int find(char str[]){
                int i,p = 0,l = strlen(str);
                for(i = 0;i < l;++i)
                        if(!child[p][str[i] - 'a'])
                                return -1;
                        else p = child[p][str[i] - 'a'];
                if(mk[p])return p;
                else return -1;
        }
};
