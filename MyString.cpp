#include "MyString.hpp"

size_t MyString::size() const {
    return (s.size());
}

size_t MyString::length() const {
    return (s.size());
}

bool MyString::empty() const {
    if (s.size() == 0) {
        return true;
    }
    return false;
}

void MyString::push_back(char c) {
    s.push_back(c);
}

void MyString::pop_back() {
    s.pop_back();
}

void MyString::resize(size_t n) {
    if (n <= s.size()) {
        for (size_t i = s.size(); n < i; --i) {
            s.pop_back();
        }
    }
    else {
        for (size_t i = s.size(); n > i; ++i) {
            s.push_back('\0');
        }
    }
}
void MyString::resize(size_t n, char c) {
    if (n <= s.size()) {
        for (size_t i = s.size(); n < i; --i) {
            s.pop_back();
        }
    } 
    else {
        for (size_t i = s.size(); n > i; ++i) {
            s.push_back(c);
        }
    }
}

size_t MyString::find(char c, size_t pos) const {
    if (s.size() == 0) {
        return -1;
    }
    for (size_t i = pos, N = s.size() - 1; i < N; ++i) {
        if (s[i] == c) {
            return i;
        }
        else {
            continue;
        }
    }
    return -1;
}

size_t MyString::rfind(char c, size_t pos) const {
    if (s.size() == 0) {
        return -1;
    }
    if (pos == std::string::npos) {
        for (size_t i = s.size() - 1, N = 0; i > N; --i) {
            if (s[i] == c) {
                return i;
            }
            else {
                continue;
            }
        }
    }
    if (pos != std::string::npos) {
        if (pos >= s.size()) {
            pos = s.size() - 1;
        }
        for (size_t i = pos, N = 0; i > N; --i) {

            if (s[i] == c) {
                return i;
            }
            else {
                continue;
            }
        }
    }
    return -1;
}


MyString MyString::substr(size_t pos, size_t len) const {
    MyString sub;
    if (pos<=s.size()){
        size_t x = 1;
    for (size_t i = pos, N = s.size() - 1; x<=len && i<=N; ++i) {
        sub.push_back(s[i]);
        ++x;
    }
        return sub;
    }
    return MyString();
}


size_t MyString::find(const MyString& str, size_t pos) const {
    MyString test;
    MyString storeIt = "";
    if (str.size()>s.size()) {
        return -1;
    }
    else if (str.length() == 0 && pos <= s.size()) {
        return pos;
    }    
    for (size_t i = 0, N = s.size(); i < N; ++i) {
        test.push_back(s[i]);
    }
    for (size_t i = pos, N = s.size() - str.length(); i <= N; ++i) {
        size_t k = 0;
        for (size_t j = i, M = str.length(); k < M; ++j, ++k) {            
            if (test.s[j] == str.s[k]) {
                storeIt.push_back(j);              
            }
            else {
                break;
            }            
        }  
        if (storeIt.length() == str.length()) {
            return storeIt.s[0];
        }
        else {
            storeIt.resize(0);
        }
    }
    return -1;
}

size_t MyString::rfind(const MyString& str, size_t pos) const {
    MyString test;
    MyString storeIt = "";
    if (pos == std::string::npos || pos > s.size()) {
        pos = s.size();
    }
    if (str.length() == 0 && pos == s.size() ) {
        return s.size();
    }
    else if (str.length() == 0 && pos < s.size()) {
        return s.size() - pos;
    }

    for (size_t i = 0, N = s.size(); i < N; ++i) {
            test.push_back(s[i]);
    }    
    for (size_t i = pos - (str.length()-1), N = 0; i > N; --i) {
        size_t k = 0;
        for (size_t j = i, M = str.length(), L = s.size(); k < M && j < L; ++j, ++k) {
            
            if (test.s[j] == str.s[k]) {
                storeIt.push_back(j);
            }
            else {
                break;
            }
        }
        if (storeIt.length() == str.length()) {
            return storeIt.s[0];
        }
        else {
            storeIt.resize(0);
        }
    }
    return -1;
}
#include "students-ignore3.h"
