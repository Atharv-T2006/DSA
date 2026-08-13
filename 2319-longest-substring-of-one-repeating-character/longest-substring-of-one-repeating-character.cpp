class Solution {
private:
    struct Node {
        char leftChar, rightChar;
        int leftLen, rightLen, maxLen;
    };

    vector<Node> tree;

    Node merge(const Node& leftChild, const Node& rightChild, int leftSize, int rightSize) {
        Node parent;
        
        parent.leftChar = leftChild.leftChar;
        parent.rightChar = rightChild.rightChar;
        parent.leftLen = leftChild.leftLen;
        parent.rightLen = rightChild.rightLen;
        parent.maxLen = max(leftChild.maxLen, rightChild.maxLen);
        
     
        if (leftChild.rightChar == rightChild.leftChar) {
            int combinedMid = leftChild.rightLen + rightChild.leftLen;
            parent.maxLen = max(parent.maxLen, combinedMid);
            
            if (leftChild.leftLen == leftSize) {
                parent.leftLen += rightChild.leftLen;
            }
            if (rightChild.rightLen == rightSize) {
                parent.rightLen += leftChild.rightLen;
            }
        }
        return parent;
    }

   
    void buildTree(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node] = {s[start], s[start], 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(s, 2 * node, start, mid);
        buildTree(s, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

   
    void updateTree(int node, int start, int end, int idx, char val) {
        if (start == end) {
            tree[node] = {val, val, 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            updateTree(2 * node, start, mid, idx, val);
        } else {
            updateTree(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        tree.resize(4 * n);

        buildTree(s, 1, 0, n - 1);

        int k = queryIndices.size();
        vector<int> result(k);

        for (int i = 0; i < k; ++i) {
            updateTree(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            result[i] = tree[1].maxLen; 
        }
        return result;
    }
};
