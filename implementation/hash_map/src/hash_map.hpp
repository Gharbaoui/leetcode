#pragma once
#include <utility>
#include <array>
#include <list>
#include <cstdint>
#include <type_traits>
#include <algorithm>
#include <optional>

#ifndef TESTING
#define TESTING
#endif

template <typename Func, typename Key, std::uint16_t size>
concept CanBeHashed = requires(Func f, Key key) {
    {f(key, size)} -> std::convertible_to<std::uint16_t>;
}; // NOLINT

template <
    typename Key,
    typename T,
    typename Hash,
    std::uint16_t ArrSize>
requires CanBeHashed<Hash, Key, ArrSize>
class   HashMap {
 public:
    using ObjectType = std::pair<Key, T>;
    using ListOfObjects = std::list<ObjectType>;
    explicit HashMap(Hash& hf): hashFunction(hf) {} // NOLINT

    bool    insert(const ObjectType obj) {
         const std::uint16_t index = hashFunction(obj.first, ArrSize);
         auto& listOfObjs = hashMapArr[index];
        if (objectInList(index, obj.first)) {
            // object already stored
            return false;
        }
         listOfObjs.push_front(obj);
         return true;
    }

    std::pair<bool, std::optional<T>>    search(const Key& key) const {
         const std::uint16_t index = hashFunction(key, ArrSize);
         const auto& listOfObjs = hashMapArr[index];
         const auto& it = std::find_if(listOfObjs.begin(), listOfObjs.end(),
                 [&](const ObjectType& obj) {return obj.first == key;});
         const bool objectWasFound = (it != listOfObjs.end());
         if (objectWasFound) {
            return std::make_pair(
                    true,
                    std::make_optional(it->second));
         }
        return std::make_pair(
            false,
            std::optional<T>());
    }

    bool    erase(const Key& key) {
         const std::uint16_t index = hashFunction(key, ArrSize);
         auto& listOfObjs = hashMapArr[index];
         const auto& it = std::find_if(listOfObjs.begin(), listOfObjs.end(),
                 [&](const ObjectType& obj) {return obj.first == key;});
         const bool objectWasFound = (it != listOfObjs.end());
         if (objectWasFound) {
            listOfObjs.erase(it);
            return true;
         }
         return false;
    }

 private:
    bool    objectInList(std::uint16_t listIndex, const Key& key) const {
         const auto& listOfObjs = hashMapArr[listIndex];
         const auto& it = std::find_if(listOfObjs.begin(), listOfObjs.end(),
                 [&](const ObjectType& obj) {return obj.first == key;});
         return (it != listOfObjs.end());
    }

 private:
    Hash&  hashFunction;
    std::array<ListOfObjects, ArrSize> hashMapArr;
    #ifdef TESTING
    FRIEND_TEST(HashMapInsert, SizeChange);
    FRIEND_TEST(HashMapInsert, ValueCheck);
    FRIEND_TEST(HashMapInsert, ValueAlreadyStored);
    FRIEND_TEST(HashMapSearch, NonEmptyHashMap);
    #endif
};
