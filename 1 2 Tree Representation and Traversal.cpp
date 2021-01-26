//construct a tree

#include<bits/stdc++.h>

using namespace std;

#define MAX 100

int tree[MAX];

int complete_node;

void root(int r){
    if(tree[1]==NULL)
        tree[1]=r;
    else
        cout<<"Root was declared before\n ";

}

void left(int child, int parent){
    if(tree[parent]==NULL)
        cout<<"Can't be inserted \n";
    else
        tree[parent*2]=child;

}

void right(int child, int parent){
    if(tree[parent]==NULL)
        cout<<"Can't be inserted \n";
    else
        tree[parent*2 +1]=child;

}

void print(){

    for(int i=1;i<MAX;i++){
        if(tree[i]==NULL)
            cout<<"__";
        else
            cout<<tree[i];
    }
}

int get_right_child(int index)
{
// node is not null
// and the result must lie within the number of nodes for a complete binary tree
     if(tree[index]!=NULL && ((2*index)+1)<=complete_node)
        return (2*index)+1;
// right child doesn't exist
     return -1;
}

int get_left_child(int index)
{
// node is not null
// and the result must lie within the number of nodes for a complete binary tree
     if(tree[index]!=NULL && (2*index)<=complete_node)
        return 2*index;
// left child doesn't exist
     return -1;
}

int get_parent(int index)
{
     if(tree[index]!=NULL && index/2!=NULL)
        return index/2;
     else
        return -1;
}

void preorder(int index)
{
// checking for valid index and null node
    if(index>0 && tree[index]!=NULL)
        {
            printf(" %d ",tree[index]); // visiting root
            preorder(get_left_child(index)); //visiting left subtree
            preorder(get_right_child(index)); //visiting right subtree
        }
}

void postorder(int index)
{
// checking for valid index and null node
    if(index>0 && tree[index]!=NULL)
        {
            postorder(get_left_child(index)); //visiting left subtree
            postorder(get_right_child(index)); //visiting right subtree
            printf(" %d ",tree[index]); //visiting root
        }
}

void inorder(int index)
{
// checking for valid index and null node
    if(index>0 && tree[index]!=NULL)
     {
        inorder(get_left_child(index)); //visiting left subtree
        printf(" %d ",tree[index]); //visiting root
        inorder(get_right_child(index)); // visiting right subtree
     }
}


int main(){
    int level=0;
    int r;
    cout<<"Enter the root: ";
    cin>>r;

    root(r);
    for(int i=2;;i++){
    string s="";
    int c,p;

    cout<<"Where do you want to insert? Enter choice: ";
    cin>>s;
    if(s=="left"){
        cout<<"Enter child: ";
        cin>>c;
        cout<<"with which node? ";
        cin>>p;
        level=max(level,p);
        left(c,p);

    }
     else if(s=="right"){

        cout<<"Enter child: ";
        cin>>c;
        cout<<"with which node? ";
        cin>>p;
        level=max(level,p);
        right(c,p);

    }
    else if(s=="stop")break;
    getchar();
}
    int k=0;
    while(level!=0){
        level/=2;
        k++;
    }
    complete_node=pow(2,k+1)-1;

    cout<<complete_node;

    print();

    cout<<"\n";

    cout<<"\t\t\t______________________________________________\n\n\n";
    printf("Preorder:\n");
    preorder(1);
    printf("\nPostorder:\n");
    postorder(1);
    printf("\nInorder:\n");
    inorder(1);
    printf("\n");


    return 0;

}
