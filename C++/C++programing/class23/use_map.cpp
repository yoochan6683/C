#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef map<int, string> MAP_INT_STRING;
typedef multimap <int, string> MMAP_INT_STRING;

typedef map<string, string> DIRECTORY_WITHCASE;
typedef map<string, string> DIRECTORY_NOCASE;

template<typename T>
void DisplayContents(const T& input) {
    for (auto iE = input.cbegin(); iE != input.cend(); ++iE) {
        cout << iE->first << "->" << iE->second << '\n';
    }
}

// void output(const auto& table) {
//    for(auto const& [key, val] : table) { 
//         cout << key << "->" << val << '\n';
//     }
//     cout << '\n'; 
// };

int main() {
    MAP_INT_STRING mapInToString;
    // using value_type    
    mapInToString.insert(MAP_INT_STRING::value_type(3, "Three"));
    // using function make_pair
    mapInToString.insert(make_pair(-1, "Minus One"));
    // using a pair object directly
    mapInToString.insert(pair<int, string>(1000, "One Thousand"));
    // using an array style
    mapInToString[100000] = "One Million";
    cout << "Size " << mapInToString.size() << '\n';
    // #1 approach
    DisplayContents(mapInToString);

    // #2 approach
    map<int, string>::iterator it;
    for(it = mapInToString.begin(); it != mapInToString.end(); ++it) {        
        cout << it->first << "->" << it->second << '\n';
    }
    cout << '\n';

    // #3 approach C++ 11 version
    for(auto const& x : mapInToString) { 
        cout << x.first << "->" << x.second << '\n';
    }
    cout << '\n';

    // #4 approach C++ 17 version
    for(auto const& [key, val] : mapInToString) { 
        cout << key << "->" << val << '\n';
    }
    cout << '\n';

    // output(mapInToString);

    MMAP_INT_STRING mmapInToString(mapInToString.cbegin(), mapInToString.cend());
    mmapInToString.insert(make_pair(1000, "Thousand"));
    DisplayContents(mmapInToString);
    cout << "The number 1000 " << mmapInToString.count(1000) << '\n';

    int Key = 1000;
    auto iPairFound = mapInToString.find(Key);
    if (iPairFound != mapInToString.end()) {
        cout << "key: " << iPairFound->first << "->" << iPairFound->second << '\n';
    } else {
        cout << "Sorry. pair with key " << Key << " is not found" << '\n';
    }

    return 0;
