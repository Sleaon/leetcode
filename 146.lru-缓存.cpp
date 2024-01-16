/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <unordered_map>
class LRUCache {
  struct Node {
    int key;
    int value;
    Node* next;
    Node* pre;
  };

 public:
  LRUCache(int capacity)
      : head_(new Node()),
        tail_(new Node()),
        capacity_(capacity),
        size_(0),
        cache_() {
    head_->next = tail_;
    tail_->pre = head_;
  }
  ~LRUCache() {
    delete head_;
    delete tail_;
  }

  int get(int key) {
    auto it = cache_.find(key);
    if (it != cache_.end()) {
      auto node = it->second;
      MoveTail(node);
      return node->value;
    }
    return -1;
  }

  void put(int key, int value) {
    auto it = cache_.find(key);
    if (it != cache_.end()) {
      auto node = it->second;
      MoveTail(node);
      node->value = value;
    } else {
      if (size_ == capacity_) {
        auto need_remove = head_->next;
        head_->next = need_remove->next;
        need_remove->next->pre = head_;
        cache_.erase(need_remove->key);
        delete need_remove;
        size_--;
      }
      auto node = new Node{key, value, nullptr, nullptr};
      AddTail(node);
      cache_.emplace(key, node);
      size_++;
    }
  }

 private:
  inline void MoveTail(Node* node) {
    node->pre->next = node->next;
    node->next->pre = node->pre;
    AddTail(node);
  }
  inline void AddTail(Node* node) {
    node->next = tail_;
    node->pre = tail_->pre;
    tail_->pre->next = node;
    tail_->pre = node;
  }
  Node* head_;
  Node* tail_;
  int capacity_;
  int size_;
  std::unordered_map<int, Node*> cache_;
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
