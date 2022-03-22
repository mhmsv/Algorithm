

#include <iostream>
using namespace std;
 
class State {
public:
    State(int d, State *n = NULL, State *p = NULL): next(n), prev(p) {
		count = 0;
        cities[0] = d;
        }
    void insert_city(int id)
    {
    	count++;
    	cities[count] = id;
	}
    int count ;
    int cities[1000];
    State *next;
    State *prev;
};



void push_back(State *list, int x) {
    State *new_state = new State(x);

    if (list != NULL) {
        State *p = list;
        while (p->next != NULL)
            p = p->next;
        new_state->prev = p;
        p->next = new_state;
    } else
     return;
}


bool search_new_city(int first,int second,State* list)
{
	State *p = list;
	while( p != NULL)
	{
		for(int i = 0; i < 1000; i++)
		{
			if (p -> cities[i] == first || p -> cities[i] == second )
			{
				if( p-> cities[i] == first)
					p->insert_city(second);
				if (p->cities[i] == second)
					p->insert_city(first);
				return true;
			}
		}
		p = p ->next;
	}
	return false;
}

int main() {
  
    int n,m;
    cin >> n >> m;
    int state_counter = 1;
    int dummy1,dummy2;
    cin >> dummy1 >> dummy2;
    State head(dummy1);
    head.insert_city(dummy2);
    for( int i = 0; i < m-1; i++)
    {
    	cin >> dummy1 >> dummy2;
    	if( search_new_city(dummy1,dummy2,&head) == false)
    	{
    		push_back(&head,dummy1);
    		search_new_city(dummy1,dummy2,&head);
    		state_counter++;
    	}
    }
  cout << state_counter << endl;       
}
