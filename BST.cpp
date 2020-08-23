//IMPLEMENTATION OF BINARY SEARCH TREES..

#include<cstddef>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
struct node *head=NULL;


void display(struct node *k)
{
    if (k!=NULL)
    {
        display(k->left);
        cout<<k->data<<",";
        display(k->right);
    }
}


void insert()
{
    struct node *temp,*k;
    temp=(struct node *)malloc(sizeof(struct node));
    cout<<"Enter the value to be inserted : ";

    cin>>temp->data;
    temp->left=NULL;
    temp->right=NULL;

    k=head;
    if (head==NULL)
    {
        head=temp;
        return;
    }
    while(1==1)
    {
        if (k->left==NULL)
        {
            if(temp->data<k->data)
            {
                k->left=temp;
                return; 
            }
        }
        if(k->right==NULL)
        {
            
            if(temp->data>k->data) 
            {
                k->right=temp;
                return;
            }
        }
        
        if(temp->data<k->data)
        {
            k=k->left;
            continue;
        }
        if(temp->data>k->data)
        {
            k=k->right;
        }
    }
}



struct node* mintree(struct node *root)
{
    while (1)
    {
        if (root->left==NULL);
            return root;
        root=root->left;
    }
}


struct node* del(struct node *root,int key)
{
    if (root==NULL)
        return root;
    else if(key<root->data)
        root->left=del(root->left,key);
    else if (key>root->data)
        root->right=del(root->right,key);
    else if(key==root->data)
    {
        struct node *temp;
        if ((root->left==NULL)&&(root->right==NULL))
        {
            delete root;
            root=NULL;
        }
        else if((root->left==NULL)&&(root->right!=NULL))
        {
            temp=root;
            root=root->right;
            delete temp;
        }
        else if((root->left!=NULL)&&(root->right==NULL))
        {
            temp=root;
            root=root->left;
            delete temp;
        }
        else if((root->left!=NULL)&&(root->right!=NULL))
        {
            temp=mintree(root->right);
            root->data=temp->data;
            root->right=del(root->right,temp->data);
        }
    }
    return root;
}


int main()
{   
    char c='y';
    int ch;
    while(ch!=4)
    {
        cout<<"1.Insert     2.Display       3.Delete        4.Exit      ||           Enter your choice : ";
        cin>>ch; 
        switch(ch)
        {
            case 1:
                insert();
            break;

            case 2:
                cout<<endl<<"Displaying BST inorder"<<endl;
                display(head);
                cout<<"\n\n";
            break;

            case 3:
                int key;
                cout<<"Enter the element to be deleted : ";
                cin>>key;
                head=del(head,key);
            break;

            case 4:
                //Do nothing and exit
            break;

            default:
                cout<<"Wrong choice";
        }
    }
    return 0;
}
