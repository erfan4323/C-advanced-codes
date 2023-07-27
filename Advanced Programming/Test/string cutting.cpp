#include <iostream>
#include <string>
#include <vector>

using namespace std;
string inputString = "DesId|SourceId,MessageType,ContentId,VolumeByte,SendTime|ReciveTime,Status";

// Function to split a string based on a delimiter
vector<string> splitString(const string& input, char delimiter) {
    vector<string> tokens;  // A vector to store the split tokens
    string token;  // A temporary string to hold each token
    size_t startPos = 0;  // The starting position for substring extraction
    size_t endPos = input.find(delimiter);  // Find the first occurrence of the delimiter

    while (endPos != string::npos) {  // Loop until all occurrences of the delimiter are found
        token = input.substr(startPos, endPos - startPos);  // Extract the token from input
        tokens.push_back(token);  // Add the token to the vector of tokens
        startPos = endPos + 1;  // Move the starting position to the next character
        endPos = input.find(delimiter, startPos);  // Find the next occurrence of the delimiter
    }

    // Add the last token (after the last delimiter)
    token = input.substr(startPos, endPos);  // Extract the last token from input
    tokens.push_back(token);  // Add the last token to the vector of tokens

    return tokens;  // Return the vector of split tokens
}

vector<string> gettingSplitedstring(string input){
    // Split the string based on ","
    vector<string> tokens = splitString(input, ',');

    // Print the given string
    cout << "the given string: \"" << input << "\"\n";
    
    vector<string> result;
    // Print the result
    for (const string& token : tokens) {
        result.push_back(token);
    }
    return result;
}


int main() {
    
    vector<string> fileId = gettingSplitedstring(inputString);
    
    //string desId = fileId[0], source = fileId[1], messtype = fileId[2], conId = fileId[3], volByte = fileId[4], senTime = fileId[5];
    
    for (const string& a : fileId){
        cout << a << endl;
    }
    return 0;
}