#include <bits/stdc++.h>
using namespace std;
//unordered_map<char, int> map;
stack<char> st;

int precedence(char ch)
{
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
}

string infix_to_postfix(string& input)
{
    int i = 0, n = input.length();
    string output;
    for(i = 0; i < n; i++)
    {
        if(input[i] >= 'a' && input[i] <= 'z')
        {
            output.push_back(input[i]);
        }
        else if(input[i] == '(')
        {
            st.push(input[i]);
        }
        else if(input[i] == ')')
        {
            while(!st.empty() && (st.top() != '('))
            {
                output.push_back(st.top());
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            if(st.empty() || (st.top() == '('))
            {
                st.push(input[i]);
            }
            else
            {
                while(!st.empty() && (precedence(st.top()) >= precedence(input[i])) && (st.top() != '('))
                {
                    output.push_back(st.top());
                    st.pop();
                }
                st.push(input[i]);
            }
        }
    }
    while(!st.empty())
    {
        output.push_back(st.top());
        st.pop();
    }
    return output;
}
int main() 
{
	string input, output;
	cin >> input;
	output = infix_to_postfix(input);
	cout << "Input: " << input << endl;
	cout << "Output : " << output << endl;
	return 0;
} 