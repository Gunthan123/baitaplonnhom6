#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct sinhvien{
	float ma;
	char name[30];
	char lop[30];
	char gioitinh[30];
	float gpa;
};
struct node{
	sinhvien data;
	node *next;
};
struct list{
	node *head;
	node *tail;
};
void CreatList(list &l){
	l.head=l.tail=NULL;
}
node *CreateNode(sinhvien x){
	node *p= new node;
	cout<<"ma sinh vien:";
	cin>>x.ma;
	cout<<"ho ten:";
	fflush(stdin);
	gets(x.name);
	cout<<"lop:";
	fflush(stdin);
	gets(x.lop);
	cout<<"gioi tinh:";
	fflush(stdin);
	gets(x.gioitinh);
	cout<<"diem tong ket:";
	cin>>x.gpa;
	p->data=x;
	p->next=NULL;
	return p;
}
void addhead(list &l,node *p){
	if(l.head==NULL){
		l.head=l.tail=p;
	}
	else{
		p->next=l.head;
		l.head=p;
	}
}
void addtail(list &l,node *p){
	if(l.head==NULL){
		l.head=l.tail=p;
	}
	else{
		l.tail->next=p;
		l.tail=p;
	}
}
void sapxep(list &l){
	node *p,*q;
	for(node *p=l.head;p!=l.tail;p=p->next){
		for(q=p->next;q!=NULL;q=q->next){
			if(p->data.ma>q->data.ma){
				sinhvien x=p->data;
				p->data=q->data;
				q->data=x;
			}
		}
	}
}
void xoacuoi(list &l){
	for(node *i=l.head;i!=NULL;i=i->next){
		if(i->next==l.tail){
			delete l.tail;
			i->next=NULL;
			l.tail=i;
		}
	}
}
void xoadau(list &l){
	for(node *k=l.head;k!=NULL;k=k->next){
		if(k==l.head){
			delete l.head;
			k=k->next;
			l.head=k;
		}
	}
}
void input(list &l, int n){
	for(int i=0; i<n; i++){
		sinhvien x;
		cout<<"\t\t==================\n";
		cout<<"SINH VIEN THU:"<<i<<endl;
		node *p=CreateNode(x);
		addtail(l,p);
	}
}
void xuat(sinhvien x){
	cout<<"\n"<<x.ma;
	cout<<"\t"<<x.name;
	cout<<"\t"<<x.lop;
	cout<<"\t"<<x.gioitinh;
	cout<<"\t"<<x.gpa;
}
void output(list l){
	node *p=l.head;
	sinhvien x;
	while(p!=NULL){
		xuat(p->data);
		p=p->next;
	}
}
void timkiem(list l){
	int u;
	cout<<"\nnhap ma sinh vien can tim:";
	cin>>u;
	for(node *h=l.head;h!=NULL;h=h->next){
		if(h->data.ma==u){
			output(l);
			return;
		}
	}
	cout<<"khong ton tai sinh vien co ma sinh vien can tim:\n"<<u;
}
void huydanhsach(list &l){
	for(node *p=l.head;p!=NULL;p=p->next){
		node *o=l.head;
		l.head=p->next;
		delete o;
	}
	l.tail=NULL;
}
int main(){
	int n;
	list l;
	sinhvien x;
	node *p;
	while(true){
	cout<<"\n\t=====MENU======";
	cout<<"\n1. nhap thong tin sinh vien:";
	cout<<"\n2. xuat thong tin sinh vien:";
	cout<<"\n3. them sinh vien vao dau:";
	cout<<"\n4. them sinh vien vao cuoi:";
	cout<<"\n5. sap xep sinh vien theo ma sinh vien:";
	cout<<"\n6. xoa sinh vien dau danh sach:";
	cout<<"\n7. xoa sinh vien cuoi danh sach:";
	cout<<"\n8. tim kiem sinh vien theo ma sinh vien:";
	cout<<"\n9. huy toan bo danh sach sinh vien:";
	cout<<"\n10. thoat.";
	int chon;
	cout<<"\n\t===>moi chon so:";
	cin>>chon;
	switch(chon){
	     case 1:{
	     	int n;
	        cout<<"nhap so luong sinh vien:";
	        cin>>n;
	     	input(l,n);
			break;
		 }
		 case 2:{
		 	output(l);
			break;
		 }
		 case 3:{
		 	p=CreateNode(x);
		    cout<<"sau khi them sinh vien dau danh sach la:";
		 	addhead(l,p);
		 	output(l);
			break;
		 }
		 case 4:{
		 	p=CreateNode(x);
		 	cout<<"sau khi them sinh vien vao cuoi danh sach la:";
		 	addtail(l,p);
		 	output(l);
			break;
		 }
		  case 5:{
		  	cout<<"sau khi sap xep la:\n";
		  	sapxep(l);
		  	output(l);
			break;
		  }
		  case 6:{
		  	cout<<"danh sach sinh vien sau khi xoa:\n";
		  	xoadau(l);
		  	output(l);
			break;
		  }
		  case 7:{
		  	cout<<"danh sach sau khi xoa:\n";
		  	xoacuoi(l);
		  	output(l);
			break;
		  }
		  case 8:{
		  	cout<<"sau khi tim kiem la:\n";
		  	timkiem(l);
			break;
		  }
		  case 9:{
		  	cout<<"sau khi da huy moi nhap lai tu dau:\n";
		  	huydanhsach(l);
			break;
		  }
		  case 10:{
		  	cout<<"thoat!\n";
			break;
		  }
	}
}
}
