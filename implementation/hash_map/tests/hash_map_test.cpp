#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/hash_map.hpp"
#include <utility>
#include <string>

TEST(HashMapInsert, SizeChange) {
    const auto HashFunction = [](int, int) {
        return 2;
    };

    HashMap<int, std::string, decltype(HashFunction), 4> hm (HashFunction);

    EXPECT_EQ(hm.hashMapArr[2].size(), 0);

    const bool ret = hm.insert({3, "Hello"});

    EXPECT_EQ(hm.hashMapArr[2].size(), 1);
    EXPECT_TRUE(ret);
}

TEST(HashMapInsert, ValueCheck) {
    const auto HashFunction = [](int, int) {
        return 2;
    };

    HashMap<int, std::string, decltype(HashFunction), 4> hm (HashFunction);

    const bool ret = hm.insert({3, "Hello"});

    EXPECT_EQ(hm.hashMapArr[2].front(), std::make_pair(3, std::string("Hello")));
    EXPECT_TRUE(ret);
}

TEST(HashMapInsert,ValueAlreadyStored) {
    const auto HashFunction = [](int, int) {
        return 2;
    };

    HashMap<int, std::string, decltype(HashFunction), 4> hm (HashFunction);

    EXPECT_EQ(hm.hashMapArr[2].size(), 0);

    bool ret = hm.insert({3, "Hello"});

    EXPECT_EQ(hm.hashMapArr[2].size(), 1);
    EXPECT_TRUE(ret);

    ret = hm.insert({3, "world"});
    EXPECT_EQ(hm.hashMapArr[2].size(), 1);
    EXPECT_EQ(hm.hashMapArr[2].front(), std::make_pair(3, std::string("Hello")));
    EXPECT_FALSE(ret);
}

TEST(HashMapSearch, EmptyHashMap) {
    const auto HashFunction = [](int, int) {
        return 2;
    };

    HashMap<int, std::string, decltype(HashFunction), 4> hm (HashFunction);

    EXPECT_FALSE(
        hm.search(3).first
    );
}

TEST(HashMapSearch, NonEmptyHashMap) {
    const auto HashFunction = [](int, int) {
        return 2;
    };

    HashMap<int, std::string, decltype(HashFunction), 4> hm (HashFunction);

    hm.hashMapArr[2].push_back({9, "owner"});

    const auto& found = hm.search(9);

    EXPECT_TRUE(
        found.first
    );
    
    EXPECT_EQ(
            found.second,
            std::string("owner")
    );
}

TEST(HashMapErase, ValueDoesNotExist) {
    const auto HashFunction = [](int, int) {
        return 2;
    };

    HashMap<int, std::string, decltype(HashFunction), 4> hm (HashFunction);

    EXPECT_FALSE(
        hm.erase(3)
    );
}

TEST(HashMapErase, ValueDoesExist) {
    const auto HashFunction = [](int, int) {
        return 2;
    };

    HashMap<int, std::string, decltype(HashFunction), 4> hm (HashFunction);

    hm.insert({9, "car"});

    EXPECT_TRUE(
        hm.erase(9)
    );

    const auto& found = hm.search(9);

    EXPECT_FALSE(found.first);
}
