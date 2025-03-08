class Codec {
    public:
        void preorder(TreeNode* root, string& str){
            if(!root){
                str.push_back('#');
                return;
            }
    
            str.append(to_string(root->val)+',');
            preorder(root->left, str);
            preorder(root->right, str);
        }
    
        string serialize(TreeNode* root) {
            string str="";
            preorder(root, str);
            return str;
        }
    
        // using substr to mitigate the processed string.
        TreeNode* solve(string& data){
            if(data.empty()) 
                return NULL;
            
            if(data[0] == '#'){
                data = data.substr(1);
                return NULL;
            }
    
            string num = "";
            int pos = 0;
            while(data[pos] != ','){
                num += data[pos];
                pos++;
            }
    
            data = data.substr(pos+1); // adding +1 to skip ','
    
            TreeNode* root = new TreeNode(stoi(num));
            root->left = solve(data);
            root->right = solve(data);
    
            return root;
        }
    
        TreeNode* deserialize(string data) {
            if(data.size() <= 1) return NULL; //if data="#" or data="" -> return NULL
            return solve(data);
        }
    };