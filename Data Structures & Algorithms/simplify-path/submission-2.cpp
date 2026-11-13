class Solution {
public:
    string simplifyPath(string path) {
        vector<string> seperations;
        vector<string> directories;

        int i = 0;
        while (i < path.size()) {
            if (path[i]=='/' and i+1 < path.size() and path[i+1] == '/') {
                i++;
                continue;
            }

            int saved_i;
            if (path[i] == '/') {
                saved_i = i;
                i++;
                while (i < path.size() and path[i] != '/') {
                    i++;
                }
            }

            seperations.push_back(path.substr(saved_i,i - saved_i));
        }
        
        for (string s : seperations) {
            if (s== "/" || s=="/.") {
                continue;
            }
            if (s == "/..") {
                if (!directories.empty()) {
                    directories.pop_back();
                }
                continue;
            }

            directories.push_back(s);
        }

        string res = "";

        for (string s : directories) {
            res+=s;
        }

        if (res=="") {
            return "/";
        }
        return res;

    }
};