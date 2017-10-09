#include <string>
#include <list>

void tokenize( std::string & str, std::list<std::string & tokens) {
    std::string line(str);
    int len = str.size();

    for(int i=0; i<len, i++) {
        char c = str[i];
        if( isdigit(c) ) {
            num += c;
        else if( isalpha(c) ) {
            ident +=c;
        else

            
class Parser {
    private:
        std::list>std::string> lTokens;
        std::string curr_tok;

    public:
        next();
        int to_Int(const std::string s & s);
};
