#include "bits/stdc++.h"
using namespace std;

struct node {
	int info;
	node *L, *R;
};

node *root, *bef, *cur;

void newPTB() {
	root = NULL;
}

bool isPTBKosong() {
	return root == NULL;	
}

void sisipNode(int IB) {
	node *newNode = (node*) malloc(sizeof(node));
	newNode->info = IB;
	newNode->L = NULL;
	newNode->R = NULL;
	
	if (isPTBKosong()) {
		root = newNode;
	} else {
		bef = root;
		cur = root;
		
		while (cur != NULL && cur->info != IB) {
			bef = cur;
			
			if (IB < cur->info) {
				cur = cur->L;
			} else {
				cur = cur->R;
			}
		}
		
		if (bef->info == IB) {
			cout << "Node " << IB << " sudah ada!" << endl;
		} else {
			if (IB < bef->info) {
				bef->L = newNode;
			} else {
				bef->R = newNode;
			}
		}
	}
}

void preOrder(node *bantu) {
	if (bantu != NULL) {
		cout << bantu->info << " ";
		preOrder(bantu->L);
		preOrder(bantu->R);
	}	
}

void inOrder(node *bantu) {
	if (bantu != NULL) {
		inOrder(bantu->L);
		cout << bantu->info << " ";
		inOrder(bantu->R);
	}	
}

void postOrder(node *bantu) {
	if (bantu != NULL) {
		postOrder(bantu->L);
		postOrder(bantu->R);
		cout << bantu->info << " ";
	}	
}

void cetak() {
	cout << "Pre-Order : ";
	preOrder(root);
	cout << endl;
	
	cout << "In-Order : ";
	inOrder(root);
	cout << endl;
	
	cout << "Post-Order : ";
	postOrder(root);
	cout << endl;
}

void hapusNode(int IH){
	if(isPTBKosong()){
		cout<<" PTB kosong"<<endl;
	}else{
		bef = root;
		cur = root;
		while(cur!=NULL && cur->info != IH){
			bef = cur;
			if(IH < cur->info){
				cur = cur->L;
			}else{
				cur = cur->R;
			}
		}
		hapus();
	}
}

void hapus(){

	node* temp;
    // Bila PTB terdiri dari akar saja atau akar dengan 1 anak kiri/kanan
    if (cur->L == NULL && cur->R == NULL)
    {
        if (bef == root && cur == root)
            root = NULL;
        else
        {
            if (cur == bef->L)
                bef->L = NULL;
            else
                bef->R = NULL;
        }
        free(cur);
    }
    // Bila PTB memiliki anak L dan anak R dgn banyak anak cabang
    else if (cur->L != NULL && cur->R != NULL)
    {
        temp = cur->L;
        bef = cur;
        while (temp->R != NULL)
        {
            bef = temp;
            temp = temp->R;
        }
        cur->info = temp->info;
        if (bef == cur)
            bef->L = temp->L;
        else
            bef->R = temp->L;
        free(temp);
    }
    // Bila PTB memiliki anak L saja dgn banyak anak cabang
    else if (cur->L != NULL && cur->R == NULL)
    {
        if (bef == cur)
            root = cur->L;
        else
        {
            if (cur == bef->L)
                bef->L = cur->L;
            else
                bef->R = cur->L;
        }
        free(cur);
    }
    // Bila PTB memiliki anak R saja dgn banyak anak cabang
    else if (cur->L == NULL && cur->R != NULL)
    {
        if (bef == cur)
            root = cur->R;
        else
        {
            if (cur == bef->R)
                bef->R = cur->R;
            else
                bef->L = cur->R;
        }
        free(cur);
    }


}

int main () {
	newPTB();
	sisipNode(50);
	sisipNode(40);
	sisipNode(70);
	sisipNode(30);
	sisipNode(45);
	sisipNode(42);
	sisipNode(60);
	cetak();	
}
