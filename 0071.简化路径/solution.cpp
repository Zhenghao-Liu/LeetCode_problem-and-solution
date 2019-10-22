class Solution {
public:
    string simplifyPath(string path) {
        int path_size=path.size();
        if (path_size<2)
            return "/";
        stack<string> current_path;
        string command;
        for (int i=0;i<path_size;++i)
        {
            while (i<path_size && path.at(i)=='/')
            {
                ++i;
            }
            command.clear();
            while (i<path_size && path.at(i)!='/')
            {
                command=command+path.at(i);
                ++i;
            }
            if (command==".")
                continue;
            else if (command=="..")
            {
                if (current_path.empty())
                    continue;
                else
                    current_path.pop();
            }
            else if (!command.empty())
                current_path.push(command);
        }
        if (current_path.empty())
            return "/";
        command.clear();
        while(!current_path.empty())
        {
            command='/'+current_path.top()+command;
            current_path.pop();
        }
        return command;
    }
};
