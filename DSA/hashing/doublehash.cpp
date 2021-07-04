#include <bits/stdc++.h>

using namespace std;

#define tablesize 13
#define prime 7

class doublehash 
{
	int *hashtable;
	int currentsize;

	public:

	bool isfull()
	{
		return (currentsize == tablesize);
	}

	int hash1(int key) {  return (key%tablesize);  }
	int hash2(int key) {  return (prime - (key%prime));}

	doublehash()
	{
		hashtable = new int[tablesize];
		currentsize = 0;
		for(int i=0;i<tablesize; i++)
			hashtable[i] = -1;
	}

	void inserthash(int key)
	{
		if(isfull())	return ;
		int index = hash1(key);// for the first hash key

		if(hashtable[index] != -1)
		{
			// when there is collision
			// as it is not empty not -1
			int index2=hash2(key);
			int i=1;
			while(1) {
				int newindex = (
						index + i *index2
						) % tablesize;
				if(hashtable[newindex] == -1)
				{
					hashtable[newindex] = key;
					break;
				}
				i++;
			}
		}
		else
			hashtable[index] = key;
		currentsize++;
	}

	void search(int key)
	{
		int index1=hash1(key);
		int index2=hash2(key);
		int i=0;
		while(hashtable[(index1 + i*index2)%tablesize] != key)
		{
			if(hashtable[(index1 + i*index2)%tablesize]==-1)
			{
				cout<<key<<" does not exist"<<endl;
				return;
			}
			i++;
		}
		cout<<key<<" found "<<endl;
	}
	void displayhash()
	{
		for(int i=0;i<tablesize;i++)
		{
			if(hashtable[i] != -1)
			cout<<i<<"->"<<hashtable[i]<<endl;
			else
				cout<<i<<endl;
		}
	}
};
int main()
{
	int a[]={19,23,654,132,335};
	int n=sizeof(a)/sizeof(a[0]);

	doublehash h;
	for(int i=0;i<n;i++)
		h.inserthash(a[i]);
	
	h.search(654);
	h.search(100);
	h.displayhash();
	return 0;
}