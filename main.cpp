#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main() {

    int n=0, ope=0, x=0;
    while (scanf("%d", &n) ==1) {
        queue<int> que;
        stack<int> stack;
        priority_queue<int> pq;
        bool isS = true, isQ = true, isPQ = true;

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &ope, &x);
            if(ope==1){
                if (isS)
                    stack.push(x);
                if (isQ)
                    que.push(x);
                if (isPQ)
                    pq.push(x);
            }
            else{
                if (isS)
                    if (stack.empty() or stack.top() != x)
                        isS = false;
                    else stack.pop();
                if (isQ)
                    if (que.empty() or que.front() != x)
                        isQ = false;
                    else que.pop();

                if (isPQ)
                    if (pq.empty() or pq.top() != x)
                        isPQ = false;
                    else pq.pop();
            }
        }
        if (isS and !isQ and !isPQ) {
            cout << "stack" << endl;
        }
        else if (!isS and isQ and !isPQ) {
           cout << "queue" << endl;
        }
        else if(!isS and !isQ and isPQ) {
            cout << "priority queue" << endl;
        }
        else if (!isS and !isQ and !isPQ){
            cout << "impossible" << endl;
        }
        else{
            cout << "not sure" << endl;
        }
    }
    return 0;
}
