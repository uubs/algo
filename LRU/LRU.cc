#include <list>
#include <unordered_map>
#include <iostream>

using CacheList = std::list<std::pair<int, int>>;
using CacheHashList = std::unordered_map<int, std::list<std::pair<int, int>>::iterator>;

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) , _size(0){  }

    void Put(int key, int val) {
        if (_size < _capacity) { // 未放满
            // 放到list中
            _cache_list.push_front(std::make_pair(key, val));
            // 放到hash表中
            _cache_hash_list.insert({key, _cache_list.begin()});
            ++ _size;
        } else { // 放满
            // 先删除产生位置
            _cache_hash_list.erase(key);
            _cache_list.pop_back();
            // 放到list中
            _cache_list.push_front(std::make_pair(key, val));
            // 放到hash表中
            _cache_hash_list.insert({key, _cache_list.begin()});
        }
    }

    bool Get(int key, int& val) {
        if (_cache_hash_list.find(key) != _cache_hash_list.end()) { // 存在
            val = _cache_hash_list.at(key)->second;

            // 先删除
            _cache_list.erase(_cache_hash_list.at(key));
            _cache_hash_list.erase(key);

            // 放到list中
            _cache_list.push_front(std::make_pair(key, val));
            // 放到hash表中
            _cache_hash_list.insert({key, _cache_list.begin()});
            return true;

        }
        return false;

    }


private:
    int _capacity;
    int _size;

    CacheList _cache_list;
    CacheHashList _cache_hash_list;
};

int main() {
    LRUCache cache(3);

    cache.Put(1, 2);
    cache.Put(2, 3);
    cache.Put(6, 7);

    int val;
    if (cache.Get(6, val)) {
        std::cout << "cache.Get(6) = " <<  val << std::endl;
    } else {
        std::cout << "key == 6 is not exit" << std::endl;
    }
    cache.Put(3, 5);
    cache.Put(9, 8);
}
