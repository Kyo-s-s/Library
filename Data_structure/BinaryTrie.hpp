template<int length = 30> struct BinaryTrie {
    struct Node {
        vector<int> next;
        int parent, val, cnt;
        Node(int parent = -1, int val = -1) : parent(parent), val(val), cnt(0) {
            next = vector<int>(2, -1);
        }
    };
    vector<Node> nodes;

    BinaryTrie() {
        nodes = { Node() };
    }

    int add_node(int parent, int val) {
        nodes.push_back(Node(parent, val));
        return nodes.size() - 1;
    }

    int insert(unsigned long long x) { return insert(bitset<length>(x)); }
    int insert(const bitset<length> &s) {
        int now_node = 0;
        nodes[now_node].cnt++;
        for (int i = length - 1; i >= 0; i--) {
            int next = s[i];
            if (nodes[now_node].next[next] == -1) {
                nodes[now_node].next[next] = add_node(now_node, next);
            }
            now_node = nodes[now_node].next[next];
            nodes[now_node].cnt++;
        }
        return now_node;
    }

    void erase(unsigned long long x) { erase(bitset<length>(x)); }
    void erase(const bitset<length> &s) {
        if (!find(s)) return;
        int now_node = 0;
        nodes[now_node].cnt--;
        for (int i = length - 1; i >= 0; i--) {
            int next = s[i];
            now_node = nodes[now_node].next[next];
            nodes[now_node].cnt--;
        }
    }


    bool find(long long x) { return find(bitset<length>(x)); }
    bool find(const bitset<length> &s) {
        int now_node = 0;
        if (nodes[now_node].cnt == 0) {
            return false;
        }
        for (int i = length - 1; i >= 0; i--) {
            int next = s[i];
            if (nodes[now_node].next[next] == -1) {
                return false;
            }
            now_node = nodes[now_node].next[next];
            if (nodes[now_node].cnt == 0) {
                return false;
            }
        }
        return true;
    }

    unsigned long long min_element(unsigned long long x = 0LL) {
        return min_element(bitset<length>(x)).to_ullong();
    }
    bitset<length> min_element(const bitset<length> &s = bitset<length>()) {
        assert(nodes[0].cnt > 0);
        int now_node = 0;
        bitset<length> ret;
        for (int i = length - 1; i >= 0; i--) {
            int next = s[i];
            if (nodes[now_node].next[next] == -1 || nodes[nodes[now_node].next[next]].cnt == 0) {
                next = 1 - next;
            }
            ret[i] = next ^ s[i];
            now_node = nodes[now_node].next[next];
        }
        return ret;
    }
};
