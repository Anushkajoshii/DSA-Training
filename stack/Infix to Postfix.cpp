//GFG
class Solution {
  int precedence(char a){
      if(a== '^'){
          return 3;
      }
      else if( a == '*' || a=='/'){
          return 2;
      }
      else if( a == '+' || a=='-'){
          return 1;
      }
      return 0;
      
  } 
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string str = "";
        int n = s.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || isdigit(ch)) {
                str.push_back(ch);
            } else if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    str.push_back(st.top());
                    st.pop();
                }
                st.pop();
            } else {
                while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                    str.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
        }

        while (!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }

        
        return str;
    }
};