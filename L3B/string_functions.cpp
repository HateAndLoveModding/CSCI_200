#include "string_functions.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned long string_length(const string STR)  {
    unsigned long result = -1;
    result = STR.length();
    return result;
}

char string_char_at(const string STR, const int IDX) {
    char result = '\0';
    result = STR.at(IDX);
    std::cout << "TODO: implement string_char_at(\"" << STR << "\", " << IDX << ")" << std::endl;
    return result;
}

string string_append(const string LEFT, const string RIGHT)  {
    string result = LEFT;
    result = LEFT + RIGHT;
    std::cout << "TODO: implement string_append(\"" << LEFT << "\", \"" << RIGHT << "\")" << std::endl;
    return result;
}

string string_insert(const string STR, const string TO_INSERT, const int IDX) {
    string result;
    for(int i=0;i<IDX;i++) {
        result = result + STR.at(i);
    }
    result = result + TO_INSERT;
    cout << "Result: " << result << endl;
    for(string::size_type i=IDX;i<STR.size();i++) {
        result = result + STR.at(i);
    }
    std::cout << "TODO: implement string_insert(\"" << STR << "\", \"" << TO_INSERT << "\", " << IDX << ")" << std::endl;
    return result;
}

size_t string_find(const string STR, const char C)  {
    size_t result = 0;
    for(string::size_type i=0; i<STR.size(); i++) {
        if(STR.at(i)==C) {
            result = i;
            return result;
        }
    }
    std::cout << "TODO: implement string_find(\"" << STR << "\", '" << C << "')" << std::endl;
    return string::npos;
}

string string_substring(const string STR, const int IDX, const int LEN) {
    string result;
    for(int i=IDX; i<LEN+IDX; i++) {
        result = result + STR.at(i);
    }
    std::cout << "TODO: implement string_substring(\"" << STR << "\", " << IDX << ", " << LEN << ")" << std::endl;
    return result;
}

string string_replace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) {
    string result;
    int index=-1;
    for (string::size_type i = 0; i < STR.size(); i++) {
        bool found = true;
        for (string::size_type j = 0; j < TEXT_TO_REPLACE.size(); j++) {
            if (STR.at(i+j) != TEXT_TO_REPLACE.at(j)) {
                found = false;
                break;
            }
        }
        if (found) {
            index = i;
            break;
        }
    }
    if(index!=-1) {
        for(int i=0; i<index; i++) {
            result = result + STR.at(i);
        }
        result = result + REPLACE_WITH;
        for(string::size_type i=index+TEXT_TO_REPLACE.size(); i<STR.size(); i++) {
            result = result + STR.at(i);
        }
    } else {
        result = STR;
    }
    std::cout << "TODO: implement string_replace(\"" << STR << "\", \"" << TEXT_TO_REPLACE << "\", \"" << REPLACE_WITH << ")\"" << std::endl;
    return result;
}

string string_first_word(const string STR)  {
    string result;
    int index = string_find(STR, ' ');
    if(index==-1) {
        return STR;
    }
    for(int i=0; i<index; i++) {
        result = result + STR.at(i);
    }
    std::cout << "TODO: implement string_first_word(\"" << STR << "\")" << std::endl;
    return result;
}

string string_remove_first_word(const string STR)  {
    string result;
    int index = string_find(STR, ' ');
    if(index==-1) {
        return "";
    }
    for(string::size_type i=index+1; i<STR.size(); i++) {
        result = result + STR.at(i);
    }
    std::cout << "TODO: implement string_remove_first_word(\"" << STR << ")\"" << std::endl;
    return result;
}

string string_second_word(const string STR)  {
    string result;
    int index = string_find(STR, ' ');
    if(index==-1) {
        return "";
    }
    for(string::size_type i=index+1; i<STR.size(); i++) {
        if(STR.at(i)==' ') {
            break;
        }
        result = result + STR.at(i);
    }
    std::cout << "TODO: implement string_second_word(\"" << STR << "\")" << std::endl;
    return result;
}

string string_third_word(const string STR)  {
    string result;
    int num=0, index=-1;
    for(string::size_type i=0; i<STR.size(); i++) {
        if(STR.at(i)==' ') {
            num++;
        }
        if(num==2) {
            index=i;
            break;
        }
    }
    if(index==-1) {
        return "";
    }
    for(string::size_type i=index+1; i<STR.size(); i++) {
        if(STR.at(i)==' ') {
            break;
        }
        result = result + STR.at(i);
    }
    std::cout << "TODO: implement string_third_word(\"" << STR << "\")" << std::endl;
    return result;
}

string string_nth_word(const string STR, const int N)  {
    string result;
    int num=0, index=-1;
    if(N==1) {
        return string_first_word(STR);
    }
    for(string::size_type i=0; i<STR.size(); i++) {
        if(STR.at(i)==' ') {
            num++;
        }
        if(num==N-1) {
            index=i;
            break;
        }
    }
    if(index==-1) {
        return "";
    }
    for(string::size_type i=index+1; i<STR.size(); i++) {
        if(STR.at(i)==' ') {
            break;
        }
        result = result + STR.at(i);
    }
    std::cout << "TODO: implement string_nth_word(\"" << STR << "\", " << N << ")" << std::endl;
    return result;
}

vector<string> string_tokenize(const string STR, const char DELIMINATOR) {
    vector<string> result;
    string word;
    for(string::size_type i=0; i<STR.size(); i++) {
        if(STR.at(i)==DELIMINATOR) {
            result.push_back(word);
            word = "";
        } else {
            word = word + STR.at(i);
        }
    }
    result.push_back(word);
    std::cout << "TODO: implement string_tokenize(\"" << STR << "\", '" << DELIMINATOR << "')" << std::endl;
    return result;
}

string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)  {
    string result = STR;
    for(string::size_type i=0; i<STR.size(); i++) {
        if(STR.at(i)==TARGET) {
            result.at(i) = REPLACEMENT;
        }
    }
    std::cout << "TODO: implement string_substitute(\"" << STR << "\", '" << TARGET << "', '" << REPLACEMENT << "')" << std::endl;
    return result;
}

string string_to_lower(const string STR) {
    string result;
    for(string::size_type i=0; i<STR.size(); i++) {
        if(STR.at(i)>=65 && STR.at(i)<=90) {
            result = result + (char)(STR.at(i)+32);
        } else {
            result = result + STR.at(i);
        }
    }
    std::cout << "TODO: implement string_to_lower(\"" << STR << "\")" << std::endl;
    return result;
}

string string_to_upper(const string STR) {
    string result;
    for(string::size_type i=0; i<STR.size(); i++) {
        if(STR.at(i)>=97 && STR.at(i)<=122) {
            result = result + (char)(STR.at(i)-32);
        } else {
            result = result + STR.at(i);
        }
    }
    std::cout << "TODO: implement string_to_upper(\"" << STR << "\")" << std::endl;
    return result;
}

int string_compare(const string LHS, const string RHS) {
    for(string::size_type i=0; i<LHS.size() && i<RHS.size(); i++) {
        if(LHS.at(i)<RHS.at(i)) {
            return -1;
        } else if(LHS.at(i)>RHS.at(i)) {
            return 1;
        }
    }
    if(LHS.size()<RHS.size()) {
        return -1;
    } else if(LHS.size()>RHS.size()) {
        return 1;
    }
    std::cout << "TODO: implement string_compare(\"" << LHS << "\", \"" << RHS << "\")" << std::endl;
    return 0;
}