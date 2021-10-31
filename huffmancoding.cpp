#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
#include<iomanip>
using namespace std;
struct Node{
    double frequency; // luu xac suat xuat hien 
    Node* left; // luu Node ben trai
    Node* right; // luu Node ben phai
};
template<int n> class huffmanCode{ // n == so phan tu cua list
    private:
        Node* root;
        //---------------------------------------------
        struct comp
        {
            bool operator()(Node* l, Node* r)
            {
                // highest priority item has lowest frequency
                return l->frequency > r->frequency;
            }
        };
        //---------------------------------------------
        priority_queue< Node*,vector<Node*>,comp > queueNode;
        queue<Node*> allNode;
    public:
        huffmanCode( double *a ){
            double sum;
            for ( int i = 0; i<n; i++ ){
                Node* initNode = new Node;  // khoi tao cac node cuoi cung cua cay
                    initNode -> frequency = a[i];
                    initNode -> left = NULL;
                    initNode -> right = NULL;
                // luu gia tri cho queue
                queueNode.push(initNode);
                allNode.push(initNode);
                // luu lai bang frequency
                sum += a[i]; // tim tong cac phan tu
                if ( a[i] == 0){
                    cout<<"Zero.";
                    exit(-1);
                }

            }
            if ( sum != 1.0){
                    cout<<sum<<endl;
                    cout<<"Error: >1";
                    exit(-1);
            }
        }
        ~huffmanCode(){
            while( !allNode.empty()){
                delete allNode.front();
                allNode.front() == NULL;
                allNode.pop();
            }
            cout<<"Destructuring tree.\n";
            cout<<"Destructed.\n";
        }
        private:
            void createTree(){
                for ( int i=0; i<n ; i++){
                    if ( i == n-1){
                        root = queueNode.top();
                        return;
                    }
                    Node* newNode = new Node;
                    float val1, val2;
                    newNode -> left = queueNode.top();
                        val1 = queueNode.top() -> frequency;
                        queueNode.pop();
                    newNode -> right = queueNode.top();
                        val2 = queueNode.top() -> frequency;
                        newNode -> frequency = val1 + val2;
                    queueNode.pop();
                    queueNode.push(newNode);  
                    allNode.push(newNode);              
                }
                return;
            }
            void printCode(Node* root, string m){
                if ( root -> left == nullptr){
                        cout<<"|  "<<setw(9)<<left<<root->frequency<<"|   "<<left<<setw(7)<<m<<"|"<<endl;
                        return;
                    }
                if ( root -> right == nullptr){
                        cout<<"|  "<<setw(9)<<left<<root->frequency<<"|   "<<left<<setw(7)<<m<<"|"<<endl;
                        return;
                    }
                    printCode(root ->left, m+'0');
                    printCode(root ->right, m+'1');
            }
        public:
            void print(){
                createTree();
                cout<<"+----------------------+"<<endl;
                cout<<"| Frequency "<<setw(5)<<"|   Code   | "<<endl;
                printCode(root,"");
                cout<<"+----------------------+"<<endl;

                return;
            }
};

int main(){
    double a[8] = {0.055, 0.055, 0.055,0.055, 0.14, 0.14, 0.25, 0.25};
    huffmanCode<8> huffmancode(a);
    huffmancode.print();
    return 0;
}