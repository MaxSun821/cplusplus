#include "myset.h"
#include "mymap.h"

int main() {
    max::set<int> collection;
    collection.insert(1);
    collection.insert(2);
    collection.insert(3);
    collection.insert(4);
    collection.insert(5);
    collection.insert(6);

	max::set<int>::iterator it = collection.begin();
    while (it != collection.end()) {
		cout << *it << " ";
        ++it;
    }
    cout << endl;

    max::map<std::string, std::string> dict;
	dict.insert(make_pair("key1", "value1"));
	dict.insert(make_pair("key2", "value2"));
	dict.insert(make_pair("key3", "value3"));
    max::map<std::string, std::string>::iterator it2 = dict.begin();
    while (it2 != dict.end()) {
        cout << it2->first << ": " << it2->second << endl;
		++it2;
    }
	cout << endl;
    return 0;
}
