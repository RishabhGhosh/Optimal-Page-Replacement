#include <bits/stdc++.h>
#define ll long long int
#define sw "      "
using namespace std;


int main()
{
	cout<<"enter string: ";
	string s;
	cin>>s;
	cout<<"enter no of frames: ";
	int t;
	cin>>t;
	vector <char> p;
	int fold=0;
	for(int ini=0;ini<t;ini++){
		char c=' ';
		p.push_back(c);
	}
	
	for(int i=0;i<s.length();i++){
		
	int alp=0;
		vector <char> v;
		for(int k=i+1;k<s.length();k++){
			char a=s[k];
			//cout<<a;
			v.push_back(a);
		}
			cout<<endl;
		char ch=s[i];
		if(find(p.begin(),p.end(),ch)!=p.end()){
			//do nothing
		}
		else{
			alp=1;
			fold++;
			int flag=0;
			int ddd=0;
			for(int l=0;l<t;l++){
				char cc=p[l];
				if(find(v.begin(),v.end(),cc)!=v.end()){
					flag=0;
					
				}
				else{
					p[l]=ch;
					flag==1;
					ddd=1;
					break;
				}
			}
			if(ddd!=1){
				vector <pair <int,int> > pp;
				for(int m=0;m<t;m++){
					char bb=p[m];
					int mm=m;
					for(int jj=i+1;jj<s.length();jj++){
						if(s[jj]==bb){
							int u=jj;
							//cout<<mm<<u<<endl;
							pp.push_back(make_pair(u,mm));
							break;
						}
					}
				}
				sort(pp.begin(),pp.end());
				reverse(pp.begin(),pp.end());
				int index=pp[0].second;
				p[index]=ch;
				pp.erase(pp.begin(),pp.end());
			}
		}
			for(int in=0;in<t;in++){
		cout<<p[in]<<" ";
	}
	if(alp==1) cout<<sw<<"  p.f occurs | counter = "<<fold;
		v.erase(v.begin(),v.end());
	}
	cout<<endl<<endl<<"total no of page fault: "<<fold;
	return 0;
}


