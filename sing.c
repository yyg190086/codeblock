#include <stdio.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 1000

// 哈希表
struct HashTable {
    int keys[HASH_TABLE_SIZE];
    int values[HASH_TABLE_SIZE];
};

// 初始化哈希表
void init_hash_table(struct HashTable *hash_table) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hash_table->keys[i] = -1;
        hash_table->values[i] = 0;
    }
}

// 将字符插入哈希表
void insert_char_into_hash_table(struct HashTable *hash_table, char c) {
    int index = c % HASH_TABLE_SIZE;
    while (hash_table->keys[index] != -1 && hash_table->keys[index] != c) {
        index = (index + 1) % HASH_TABLE_SIZE;
    }
    hash_table->keys[index] = c;
    hash_table->values[index]++;
}

// 从哈希表中查找字符
int find_char_in_hash_table(struct HashTable *hash_table, char c) {
    int index = c % HASH_TABLE_SIZE;
    while (hash_table->keys[index] != -1 && hash_table->keys[index] != c) {
        index = (index + 1) % HASH_TABLE_SIZE;
    }
    return hash_table->values[index];
}

// 获取不重复字符组成的字符串
char *get_unique_chars_string(const char *str) {
    struct HashTable hash_table;
    init_hash_table(&hash_table);

    // 将字符串中的每个字符插入哈希表
    for (int i = 0; str[i] != '\0'; i++) {
        insert_char_into_hash_table(&hash_table, str[i]);
    }

    // 遍历哈希表，找到不重复的字符
    char *unique_chars_str = malloc(sizeof(char) * 100);
    int index = 0;
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        if (hash_table.values[i] == 1) {
            unique_chars_str[index++] = hash_table.keys[i];
        }
    }
    unique_chars_str[index] = '\0';

    return unique_chars_str;
}

int main() {
    char *str = "abcabcbb";
    char *unique_chars_str = get_unique_chars_string(str);
    printf("不重复字符组成的字符串：%s\n", unique_chars_str);

    return 0;
}