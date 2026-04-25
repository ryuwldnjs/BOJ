#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;
char str[100+5];
stack<char> st;
int main()
{
	while(true)
	{
		while (!st.empty())//사용전 큐 청소 해주기 
			st.pop();
			
		
		bool answer = true;
		fgets(str,sizeof(str), stdin);
		int size = strlen(str);
		if(str[0]=='.') // . 하나 입력 받았을때 끝 
			break;
			
		for(int i=0;i<size;i++)
		{
			if(str[i]=='(' || str[i]=='[')
				st.push(str[i]);
				
			if(str[i]==')') //짝 찾았을때 --1
			{
				if(!st.empty() && st.top() == '(')
					st.pop();
				else
				{
					answer = false;
					break;
				}
			}
			
			if(str[i]==']') //짝 찾았을때 --2
			{
				if(!st.empty() && st.top() == '[')
					st.pop();
				else
				{
					answer = false;
					break;
				}
			}
					
			
		}
		if(st.empty() && answer)
			printf("yes\n");
		else
			printf("no\n");		
	}
	return 0;
}