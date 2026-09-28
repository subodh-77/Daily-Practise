class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int maxdepth = -1;
        int openbracket = 0;
        for(int i = 0;i<n;i++){
            if(s[i]=='('){openbracket++;}
            if(s[i]==')'){openbracket--;}
            if(maxdepth<openbracket){
                maxdepth = openbracket;
            }
        }
        return maxdepth;

    }
};