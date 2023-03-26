unsigned int hashFunction(const std::string& key, int tableSize) {
    unsigned int hashVal = 0;
    unsigned int a = 33;
    for (char ch : key) {
        hashVal = (a * hashVal) + ch;
        a = a * 33;
    }
    return hashVal % tableSize;
}
