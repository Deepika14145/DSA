bool isValidTag(const string& tag) {
    int n = tag.length();

    // Condition 1: Should start with "</" and end with ">"
    if (n < 4 || tag.substr(0, 2) != "</" || tag[n - 1] != '>') 
        return false;

    // Extract the body part (characters between "</" and ">")
    string body = tag.substr(2, n - 3);

    // Condition 2: Body should be non-empty
    if (body.empty()) 
        return false;

    // Condition 3: Body should only contain lowercase letters or digits
    for (char ch : body) {
        if (!islower(ch) && !isdigit(ch)) 
            return false;
    }

    return true;
}
