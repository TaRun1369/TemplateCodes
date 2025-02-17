vector<int> lps(s.size(), 0);
        int n = s.size();
        for(int i = 1;i<n;i++){
            int j = lps[i - 1];
            if(s[i] == s[j]) lps[i] = j + 1;

            else{
                while(j > 0 && s[i] != s[j]){
                    j--;
                    j = lps[j];
                }
                if(s[i] == s[j]) lps[i] = j + 1;
            }
        }
