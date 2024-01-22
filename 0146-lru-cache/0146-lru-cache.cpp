// LRU Method
class LRUCache {
private:
    int size;
    list<int> infos;
    unordered_map<int, pair<int, list<int>::iterator>> umap;
public:
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key){
        if (umap.find(key) == umap.end()){
            return -1; 
        }
        auto itr = umap[key].second;
        int val = umap[key].first;
        infos.erase(itr);
        infos.push_back(key);
        umap[key].second = --infos.end();
        return val;
    }

    void put(int key, int val){
        if (umap.find(key) != umap.end()){
            auto itr = umap[key].second;
            infos.erase(itr);
        }
        infos.push_back(key);
        umap[key] = {val, --infos.end()};

        if (umap.size() > size){
            int key = infos.front();
            umap.erase(key);
            infos.pop_front();
        }
    }

};
