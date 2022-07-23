#include <iostream>
#include <set>
#include <map>
using namespace std;
class person_compare{
public:
	bool operator()(pair<string,int>p1, pair<string,int> p2){
		return p1.second<p2.second;
	}
};
int main(){
	int no_of_transactions,friends;//edges and nodes of the graph
	cin>>no_of_transactions>>friends;
	/*int x,y,amount;//person 1(x) pays amount to person 2(y)
	//array to store the final amount that each person will have at the end
	int net[100000]={0};
	while(no_of_transactions--){
		cin>>x>>y>>amount;
		net[x]-=amount;
		net[y]+=amount;
	}
	multiset<int>m;
	for(int i=0;i<friends;i++){
		if(net[i]!=0){
			m.insert(net[i]);
		}
	}
	int cnt=0;
	while(!m.empty()){
		auto low=m.begin();
		auto high=prev(m.end());
		int debit=*low;
		int credit=*high;
		m.erase(low);
		m.erase(high);
		int settlement_amount=min(-debit,credit);//settle
		cnt++;
		//transfering the money
		debit+=settlement_amount;
		credit-=settlement_amount;
		if(debit!=0){
			m.insert(debit);
		}
		if(credit!=0){
			m.insert(credit);
		}
	}
	cout<<"Number of transactions"<<cnt<<endl;*/
	string x,y;
	int amount;
	map<string,int> net;
	while(no_of_transactions--){
		cin>>x>>y>>amount;
		if(net.count(x)==0){
			net[x]=0;
		}
		if(net.count(y)==0){
			net[y]=0;
		}
		net[x]-=amount;
		net[y]-=amount;
	}
	multiset<pair<string,int>,person_compare>m;
	for(auto p:net){
		string person=p.first;
		int amount=p.second;
		if(net[person]!=0){
			m.insert(make_pair(person,amount));
		}
	}
	int cnt=0;
	while(!m.empty()){
		auto low=m.begin();
		auto high=prev(m.end());
		int debit=low->second;
		string debit_person=low->first;
		int credit=high->second;
		string credit_person=high->first;
		m.erase(low);
		m.erase(high);
		int settled_amount= min(-debit,credit);
		debit+=settled_amount;
		credit-=settled_amount;
		cout<<debit_person<<" will pay "<<settled_amount<<" to "<<credit_person<<endl;
		if(debit!=0){
			m.insert(make_pair(debit_person,debit));
		}
		if(credit!=0){
			m.insert(make_pair(credit_person,credit));
		}
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}