class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_size=s.size();
	    int words_size=words.size();
        if (words_size==0 || s_size==0 || words_size>s_size)
            return {};
	    vector<vector<int>> map;
	    string::size_type position;
	    for (int i=0;i<words_size;++i)
	    {
		    map.push_back(vector<int>({}));
		    if (s.find(words.at(i))==s.npos)
			    return {};
		    position=-1;
		    while (1)
		    {
			    position=s.find(words.at(i),position+1);
                if (position==s.npos)
                    break;
                map.at(i).push_back(int(position));
		    }
	    }
	    vector<int> answer(find_substr(map,words_size,words.at(0).size()));
        return answer;
    }
    vector<int> find_substr(vector<vector<int>>&map,const int & words_size,const int &single_words_size)
    {
	    vector<vector<int>>judge;
        vector<vector<int>>ans(map);
        vector<vector<int>>ans_judge;
        ans.erase(ans.begin());
        int time=0; 
        for (int i=0;i<map.at(0).size();++i)
        {
            ans_judge=(look_for_continue(ans,single_words_size,map.at(0).at(i)));
            for (int j=0;j<ans_judge.size();++j)
            {
        	    judge.push_back(ans_judge.at(j));
        	    judge.at(time++).push_back(map.at(0).at(i)); 
		    }
            ans_judge.clear();
        }
        time=judge.size();
        int j;
        vector<int>answer;
	    for (int i=0;i<time;++i)
		    if (judge.at(i).size()==words_size)
		    {
			    sort(judge.at(i).begin(),judge.at(i).end());
			    for (j=0;j<words_size-1;++j)
				    if (judge.at(i).at(j+1)!=judge.at(i).at(j)+single_words_size)
					    break;
			    if (j==words_size-1)
				    answer.push_back(judge.at(i).at(0));
		    }
        sort(answer.begin(),answer.end());
        vector<int>::iterator ite = unique(answer.begin(),answer.end());
    	answer.erase(ite,answer.end());
	    return answer;
    }
    vector<vector<int>> look_for_continue(vector<vector<int>>& map,const int& single_words_size,const int& index)
    {
        if (map.size()==0)
            return {{}};
        double quotient;
        vector<int> correct_position;
        for (int i=0;i<map.at(0).size();++i)
        {
            quotient=(map.at(0).at(i)-index)/double(single_words_size);
            if (quotient==double(int(quotient)))
                correct_position.push_back(int(map.at(0).at(i)));   
        }
        if (correct_position.size()==0)
            return {{}};
        vector<vector<int>> ans(map);
        ans.erase(ans.begin());
        vector<vector<int>> ans_judge;
        vector<vector<int>> judge;
        int time=0;
        for (int i=0;i<correct_position.size();++i)
        {
            ans_judge=look_for_continue(ans,single_words_size,index);
		    for (int j=0;j<ans_judge.size();++j)
            {
        	    judge.push_back(vector<int>(ans_judge.at(j)));
        	    judge.at(time++).push_back(correct_position.at(i));
		    }
        }
        return judge;
    }
};
