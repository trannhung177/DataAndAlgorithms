#include <bits/stdc++.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

// -------------- MI PHAM - DANH SACH LIEN KET DON -------------
// Khai bao cau truc Mi Pham
struct MIPHAM{
	int maMP;
	int maHD=0;
	char tenMP[30];
	int SLBan;
	float giaBan;
	float thanhTien;
};
// Khai bao CTDL
struct NodeMP{
	MIPHAM info;
	struct NodeMP *next;
};

struct ListMP{
	NodeMP *Head;
	NodeMP *Tail;
};

void KhoiTaoMP(ListMP &MP){
	MP.Head = NULL;
	MP.Tail = NULL;
}
NodeMP *getNodeMP(MIPHAM mp){
	NodeMP *p;
	p = new NodeMP;
	if(p==NULL){
		cout<<"Cap phat loi!";
		exit(1);
	}
	p->info = mp;
	p->next = NULL;
	return p;
}

// Chen phan tu
void ChenCuoiMP(ListMP &MP, NodeMP *p){
	if(MP.Head == NULL){
		MP.Head = p;
		MP.Tail = MP.Head;
	}
	else{
		MP.Tail -> next =p;
		MP.Tail = p;
	}
}
 
void XoaDauMP(ListMP &Q){
	NodeMP *p = Q.Head;
	if(Q.Head!=NULL){
		p = Q.Head;
Q.Head = Q.Head -> next;
delete p;
if ( Q.Head == NULL ) 
Q.Tail = NULL;
}
	}

// Nhap mi pham

void NhapMP(MIPHAM &mp){
	cout<<"Nhap ma mi pham: ";
	cin>>mp.maMP;
	cout<<"Nhap ten mi pham: ";
	fflush(stdin);
	gets(mp.tenMP);
	cout<<"So luong ban:";
	cin>>mp.SLBan;
	cout<<"Gia ban:";
	cin>>mp.giaBan;
	mp.thanhTien=mp.SLBan*mp.giaBan;
	}
	
// Nhap DS Mi Pham
void NhapDSMP(ListMP &MP){
	int n;
	MIPHAM mp;
	NodeMP *p;
		cout<<"Nhap so mi pham: ";
		cin>>n;
		for(int i=0;i<n;i++){
			cout<<"								\n";
			NhapMP(mp);
			p=getNodeMP(mp);
			ChenCuoiMP(MP,p);
		}
}


// Hien mi pham
void HienMP(MIPHAM &mp)
{
	cout<<setw(15)<<mp.maMP
		<<setw(15)<<mp.tenMP
		<<setw(15)<<mp.SLBan
		<<setw(15)<<mp.giaBan
		<<setw(15)<<mp.thanhTien<<endl;
}


// Hien DS Mi Pham
void HienDSMP(ListMP MP){
	NodeMP *p;
	cout<<"\n------ Danh sach mi pham ------\n";
	cout<<setw(15)<<"Ma mi pham"
		<<setw(15)<<"Ten mi pham"
		<<setw(15)<<"So luong ban"
		<<setw(15)<<"Gia ban"
		<<setw(15)<<"Thanh tien"<<endl;
	for(p=MP.Head;p!=NULL;p=p->next){
		HienMP(p->info);
	}
}


// Luu file Danh Sach Mi Pham
void LuuFileMP(ListMP &Q)
{
	FILE *f;
    f = fopen("MiPham.dat","wb");
    int n=0;
    NodeMP *p;
    for(p=Q.Head; p!=NULL; p=p->next)
        n= n+1;
    fwrite(&n,sizeof(int),1,f);
    for(p=Q.Head; p!=NULL; p=p->next)
        fwrite(&p->info,sizeof(MIPHAM),1,f);
    fclose(f);
    if(f!=NULL)
    	cout<<"\nLuu file thanh cong!"<<endl;
	else
		cout<<"\nLuu file that bai!"<<endl;
}


void DocFileMP(ListMP &Q)
{
	FILE *f;
	KhoiTaoMP(Q);
    MIPHAM x;
    int i,n;
    NodeMP *p;
    f =fopen("MiPham.dat","rb");
    fread(&n,sizeof(int),1,f);
    for(i=0; i<n; i++)
    {
        fread(&x,sizeof(MIPHAM),1,f);
        p = getNodeMP(x);
        ChenCuoiMP(Q,p);
    }
    fclose(f);
    if(f!=NULL)
    	cout<<"\nDoc file thanh cong!"<<endl;
	else
		cout<<"\nDoc file that bai!"<<endl;
}

// Sap xep mi pham theo thu tu tang dan so luong
void SapXepTangDanMP(ListMP &MP){
	NodeMP *p,*q;
	MIPHAM tg;
	p=MP.Head;
	while(p!=NULL){
		q=p->next;
		while(q!=NULL){
			if(p->info.SLBan>q->info.SLBan){
			
			tg=p->info;
			p->info=q->info;
			q->info=tg;
			}
			q=q->next;
		}
		p=p->next;
	}
}

//Tim kiem mat hang theo ten
NodeMP* timMHTen(ListMP &Q){
	
	char tenMP[30];
	cout<<"Ten mi pham can tim:";
	fflush(stdin);
	gets(tenMP);
	NodeMP *p = Q.Head;
	cout<<setw(15)<<"Ma mi pham"
		<<setw(15)<<"Ten mi pham"
		<<setw(15)<<"So luong ban"
		<<setw(15)<<"Gia ban"
		<<setw(15)<<"Thanh tien"<<endl;
	while(p!=NULL){
		if(strcmp(p->info.tenMP,tenMP)==0){
			HienMP(p->info);
			break;
		}
		p=p->next;
	}
}




// ------------ NHAN VIEN - QUEUE ----------------

// Khai bao cau truc Nhan Vien
struct NHANVIEN{
	int maNV;
	char tenNV[30];
	char queQuan[30];
	float luongCB;
	float phuCap;
	
};

// Khai bao CTDL
struct NodeNV
{
    NodeNV *pNext;
    NodeNV *pPrev;
    NHANVIEN data;
};

struct Queue
{
    NodeNV *pHead;
    NodeNV *pTail;
};

NodeNV *CreateNode(NHANVIEN nv)
{
    NodeNV *p = new NodeNV;
    if (p == NULL)
    {
        cout<<"Khong du bo nho cap phat";
        return NULL;
    }
    else
    {
        p->data = nv;
        p->pNext = NULL;
        p->pPrev =NULL;
        return p;
    }
}

void CreateQueue(Queue &NV)
{
    NV.pHead = NULL;
    NV.pTail = NULL;
}

void EnQueue (Queue &NV, NodeNV *p)
{
    if (NV.pHead == NULL)
    {
       NV.pHead = NV.pTail = p;
    }
    else
    {
        p->pNext = NV.pHead;
        NV.pHead->pPrev = p;
        NV.pHead = p;
    }
}

void DeQueue (Queue &NV)
{
    NodeNV *p;
    if (NV.pHead == NULL)
    {
        cout<<"Queue rong!";
        return;
    }
    p = NV.pTail;
    NV.pTail = NV.pTail->pPrev;
    NV.pTail->pNext = NULL;
    delete p;
}

// Nhap Nhan Vien
void NhapNV(NHANVIEN &nv){
	cout<<"					\n";
	cout<<"Nhap ma nhan vien: ";
	cin>>nv.maNV;
	cout<<"Nhap ten nhan vien: ";
	fflush(stdin);
	gets(nv.tenNV);
	cout<<"Nhap que quan: ";
	fflush(stdin);
	gets(nv.queQuan);
	cout<<"Nhap luong co ban: ";
	cin>>nv.luongCB;
	cout<<"Nhap phu cap: ";
	cin>>nv.phuCap;	
}

// Nhap Danh sach Nhan Vien
void NhapDSNV(Queue &NV, NHANVIEN &nv)
{
    int n;
    cout<<"\n\t NHAP DANH SACH NHAN VIEN ";
    cout<<"\nNhap so nhan vien: ";
    cin>>n;
    for (int i=0; i<n; i++)
    {	
    	cout<<"\n						\n";
        cout<<"Nhap nhan vien thu "<<i+1;
        NhapNV(nv);
        NodeNV *p = CreateNode(nv);
        EnQueue(NV,p);
    }
}

void HienNV(NHANVIEN nv)
{
    cout<<setw(15)<<nv.maNV
		<<setw(15)<<nv.tenNV
		<<setw(20)<<nv.queQuan
		<<setw(15)<<nv.luongCB
		<<setw(15)<<nv.phuCap<<endl;
}

void HienDSNV(Queue NV)
{
    
    cout<<setw(15)<<"Ma NV"
		<<setw(15)<<"Ho ten"
		<<setw(20)<<"Que quan"
		<<setw(15)<<"Luong CB"
		<<setw(15)<<"Phu cap"<<endl;
    NodeNV *p = NV.pHead;
    while(p != NULL)
    {
        HienNV(p->data);
        cout<<endl;
        p = p->pNext;
    }
    
}

void PushNV(Queue &NV, NHANVIEN &nv)
{
    cout<<"NHAP THONG TIN NHAN VIEN";
    NhapNV(nv);
    NodeNV *p = CreateNode(nv);
    EnQueue(NV,p);
}


// Luu file DS Nhan Vien
void LuuFileNV(Queue NV)
{
	FILE *f;
   	f=fopen("NhanVien.txt","w");
   	for(NodeNV *p=NV.pHead;p!=NULL;p=p->pNext)
     {
	 fwrite(&p->data,sizeof(NHANVIEN),1,f);
	 }
    fclose(f);
    if(f!=NULL)
    	cout<<"\nLuu file thanh cong!"<<endl;
	else
		cout<<"\nLuu file that bai!"<<endl;
}

// Doc File DS Nhan Vien
void DocFileNV(Queue &NV){
	CreateQueue(NV);
	FILE *f;
	NHANVIEN nv;
	NodeNV *p;
	f = fopen("NhanVien.txt","rb");
	if(f==NULL){
		cout<<"Loi mo tep!";
		return;
	}
	while(true){
		fread(&nv,sizeof(NHANVIEN),1,f);
		if(feof(f)) break;
		p=CreateNode(nv);
		EnQueue(NV,p);
	}
	fclose(f);
	cout<<"Doc File thanh cong!\n"<<endl;
	cout<<"Danh sach Nhan Vien trong file la: "<<endl;
	HienDSNV(NV);
}


// Tim kiem Nhan Vien theo que quan
NodeNV *TimKiemNV(Queue &NV){
	char quequan[30];
	cout<<"\nNhap que quan Nhan Vien can tim: ";
	fflush(stdin);
	gets(quequan);
	NodeNV *p = NV.pHead;
	cout<<setw(15)<<"Ma NV"
		<<setw(15)<<"Ho ten"
		<<setw(20)<<"Que quan"
		<<setw(15)<<"Luong CB"
		<<setw(15)<<"Phu cap"<<endl;
	while(p!=NULL){
		if(strcmp(p->data.queQuan,quequan)==0){
			HienNV(p->data);
		}
		p=p->pNext;
	}
}



// ---------- HOA DON - DANH SACH LIEN KET DOI ----------
//Khai bao cau truc Hoa Don
struct HOADON{
	int maHD;
	NHANVIEN NV;
	char tenKH[30];
	char ngayLap[30];
	int SL;
	float tongTien;
};


// Khai bao CTDL
struct NodeHD{
	HOADON data;
	struct NodeHD *pnext;
	struct NodeHD *prev;
};

struct ListHD{
	NodeHD *Head;
	NodeHD *Tail;
};

void KhoiTaoHD(ListHD &HD){
	HD.Head = NULL;
	HD.Tail = NULL;
}

NodeHD* getNodeHD(HOADON hd){
	NodeHD *p = new NodeHD;
	if(p==NULL){
		cout<<"Khong du bo nho!\n";
		return NULL;
	}
	else
	{
		p->data = hd;
		p->pnext = NULL;
		p->prev = NULL;
		return p;
	}
}
//them cuoi

void ThemCuoiHD(ListHD &HD, NodeHD *p){
	if(HD.Head==NULL){
		HD.Head=HD.Tail=p;
	}
	else
	{
		HD.Tail->pnext=p;
		p->prev=HD.Tail;
		HD.Tail=p;
	}
}
//them sau
void ThemSauHD( ListHD &HD, NodeHD *q, NodeHD *p )
{
	NodeHD *k;
	if(q!=NULL){
		k=q->pnext;
		p->pnext = k;
		p->prev=q;
		q->pnext=p;	
	}
}

// Xoa dau
void XoaDauHD(ListHD &Q){
	NodeHD *p = Q.Head;
	if(Q.Head!=NULL){
		Q.Head=Q.Head->pnext;
		Q.Head->prev=NULL;
		free(p);
		if(Q.Head==NULL) Q.Tail = NULL;
	}
}

// Xoa truoc
void XoaTruocHD(ListHD &HD,NodeHD *q){
	 NodeHD *p;
	if(q!=NULL){
		if (q == HD.Head)
		{
		printf("\n Ko xoa duoc hoa don o vi tri dau!");
		exit(1);
		}
		p = q -> prev; //lay phan tu can huy bo
		q -> prev = p -> prev;
		if ( p == HD.Head ) HD.Head = q;
		else p -> prev -> pnext = q;
			free(p);
		}
	}
	
	
// Xoa ma Hoa Don
int XoaMaHD(ListHD &HD, ListMP &MP){
	int mHD;
	cout<<"Nhap ma Hoa Don muon xoa: ";
	cin>>mHD;
	NodeHD *p = HD.Head, *q = NULL;
	while(p!=NULL){
		if(mHD==p->data.maHD) break;
		q=p;
		p=p->pnext;
	}
	if(p==NULL) return 0;
	if(q!=NULL){
		if(p==HD.Tail){	HD.Tail=q; }
			q->pnext=p->pnext;
			free(p);
	}
	else XoaDauHD(HD);
	return 1;
}


// Nhap thong tin Hoa Don
void NhapHD(HOADON &hd, MIPHAM &mp, ListMP &MP){
	cout<<"Nhap ma hoa don: ";
	cin>>hd.maHD;
	cout<<"Nhap ten khach hang: ";
	fflush(stdin);
	gets(hd.tenKH);
	cout<<"Ngay lap: ";
	fflush(stdin);
	gets(hd.ngayLap);
	cout<<"So luong mi pham: ";
	cin>>hd.SL;
	hd.tongTien=0;
	for(int i=0;i<hd.SL;i++){
		NhapMP(mp);
		mp.maHD=hd.maHD;
		hd.tongTien+=mp.thanhTien;
		NodeMP *p = getNodeMP(mp);
		ChenCuoiMP(MP,p);
	}
}


// Nhap Danh Sach Hoa Don
void NhapDSHD(ListHD &HD,MIPHAM &mp,ListMP &MP){
	HOADON hd;
	NodeHD *p;
	int n;
	cout<<"Nhap so luong hoa don: ";cin>>n;
	for(int i=0;i<n;i++){
		cout<<"--------------------------\n";
		cout<<"Nhap thong tin hoa don thu "<<i+1<<":"<<endl;
		NhapHD(hd,mp,MP);
		p=getNodeHD(hd);
		ThemCuoiHD(HD,p);
	}
}

// Hien thong tin tung hoa don
void HienHD(HOADON &hd, ListMP &mp){
	cout<<setw(18)<<hd.maHD
	<<setw(20)<<hd.tenKH
	<<setw(15)<<hd.ngayLap
	<<setw(10)<<hd.SL<<endl;
	cout<<"\nDanh sach mi pham cua hoa don"<<endl;
	cout<<setw(15)<<"Ma mi pham"
	<<setw(15)<<"Ten mi pham"
	<<setw(15)<<"So luong ban"
	<<setw(15)<<"Gia ban"
	<<setw(15)<<"Thanh tien"<<endl;
	for(NodeMP *k = mp.Head; k!=NULL;k=k->next){
		if(hd.maHD==k->info.maHD)
		HienMP(k->info);
	}
	cout<<"Tong tien cua Hoa Don: "<<hd.tongTien<<endl;
}


// Hien Danh Sach Hoa Don
void HienDSHD(ListHD HD,ListMP &mp){
	NodeHD *p;
	for(p=HD.Head; p!=NULL; p=p->pnext){
	cout<<"\n----------- Thong tin Hoa Don ------------\n";
	cout<<setw(18)<<"Ma hoa don"
	<<setw(20)<<"Ten khach hang"
	<<setw(15)<<"Ngay lap"
	<<setw(15)<<"SL mi pham"<<endl;
		HienHD(p->data,mp);
	}	

}


// Luu File Danh Sach hoa don
void LuuFileHD(ListHD HD){
	FILE *f;
	f = fopen("HoaDon.txt", "wb");
	for(NodeHD*p = HD.Head; p!=NULL;p=p->pnext){
		fwrite(&p -> data,sizeof(HOADON),1,f);
	}
	fclose(f);
	if(f!=NULL)
    	cout<<"\nLuu file thanh cong!"<<endl;
	else
		cout<<"\nLuu file that bai!"<<endl;
}


// Doc File Danh Sach Hoa Don
 /*
 NOTE: (Ko lam theo no dell chay dau)
 - Nho la nhap hoa don khong can MI PHAM
 - Nhap Hoa Don
 - Luu File Hoa Don
 - Luu File Mi Pham
 - Doc File Hoa Don
*/
void DocFileHD(ListHD &HD,ListMP &mp){
	KhoiTaoHD(HD);
	FILE *f;
	HOADON hd;
	NodeHD *p;
	f=fopen("HoaDon.txt","rb");
	if(f==NULL){
		cout<<"Loi mo tep!";
		return;
	}
	while(true){
		fread(&hd,sizeof(HOADON),1,f);
		if(feof(f)) break;
		p=getNodeHD(hd);
		ThemCuoiHD(HD,p);
	}
	fclose(f);
	cout<<"Danh sach hoa don trong file la: "<<endl;
	HienDSHD(HD,mp);
	
}


// Tim Khach Hang co tien mua hang lon nhat
void KHTT_Max(ListHD HD)
{
	NodeHD *p;
	float max=0;
	cout<<"\nKhach hang co tien mua lon nhat: ";
	for(p=HD.Head;p!=NULL;p=p->pnext)
	{
		if(max<p->data.tongTien)
			max=p->data.tongTien;
		
	}
	for(p=HD.Head;p!=NULL;p=p->pnext)
	{
		if(p->data.tongTien==max)
			cout<<p->data.tenKH<<endl;
	}
	
}


// Sap xep Hoa Don theo tong tien giam dan
void SapXepGiamDanTT(ListHD &HD){
	NodeHD *p,*q;
	HOADON tg;
	p=HD.Head;
	while(p!=NULL){
		q=p->pnext;
		while(q!=NULL){
			if(p->data.tongTien<q->data.tongTien)
			swap(p->data.tongTien,q->data.tongTien);
			q=q->pnext;
		}
		p=p->pnext;
		
	}
	
}


//tong tien hoa don nho nhat
void KHTT_Min(ListHD HD)
{
	NodeHD *p;
	float min=0;
	cout<<"\nKhach hang co tien mua lon nhat: ";
	for(p=HD.Head;p!=NULL;p=p->pnext)
	{
		if(min>p->data.tongTien)
			min=p->data.tongTien;
		
	}
	for(p=HD.Head;p!=NULL;p=p->pnext)
	{
		if(p->data.tongTien==min)
			cout<<p->data.tenKH<<endl;
	}
	
}
//tong tien hoa don
void tongTienHD(ListHD HD)
{
	NodeHD *p;
	float tongTienHD=0;
	for(p=HD.Head;p!=NULL;p=p->pnext)
	{
		tongTienHD+=p->data.tongTien;
	}
	cout<<"Tong Tien Cac Don Hang La:"<<tongTienHD;	
}



//sap xep 2
void SapXepTangDanTT(ListHD &HD){
	NodeHD *p,*q;
	HOADON hd ;
	p=HD.Head;
	while(p!=NULL){
		q=p->pnext;
		while(q!=NULL){
			if(p->data.tongTien>q->data.tongTien)
			swap(p->data.tongTien,q->data.tongTien);
				q=q->pnext;
		}
		p=p->pnext;
	}
	
}


//tim HD theo maHD
void timHDma(ListHD &HD,ListMP &mp)
{
    NodeHD *p;
    int x;
    int d=0;
    cout<<"\nNhap ma hoa don can tim : ";
    cin>>x;
//	cout<<"Ma HD";
//	cout<<"Ten Khach Hang";
//	cout<<"Ngay lap";
    for(p=HD.Head;p!=NULL;p=p->pnext)
        if(p->data.maHD==x)
        {
            HienHD(p->data,mp);
            d++;
        }
        if(d==0)
            cout<<"\nKhong co ma hang hoa can tim !";
}


int main (){
	MIPHAM mp;
	ListMP MP;
	KhoiTaoMP(MP);
	

	NHANVIEN nv;
	Queue NV;
	CreateQueue(NV);
	
	HOADON hd;
	ListHD HD;
	KhoiTaoHD(HD);
	
	int chon;
	int nhap;
	while(true)
	{
		cout<<"\n________________________________________QUAN LI KINH DOANH MI PHAM________________________";
		cout<<"\n===============================1: Quan Li MI PHAM==================================";
		cout<<"\n===============================2: Quan Li Nhan Vien=================================";
		cout<<"\n===============================3: Quan Li HOA DON===================================";
		cout<<"\n===============================0: De Thoat Chuong Trinh============================\n";
	cin>>chon;
	switch(chon) 
	{ 
		case 1: 
		while(true)
		{
			cout<<"\n_____________________________________Quan Li MI Pham___________________________";
			cout<<"\n|                         1: Nhap danh sach mi pham                            |";
			cout<<"\n|                         2: Hien danh sach mi pham                            |";
			cout<<"\n|                         3: Luu File danh sach mi pham                        |";
			cout<<"\n|                         4: Doc File danh sach mi pham                        |";
			cout<<"\n|                         5: Sap xep tang dan theo so luong                    |";
			cout<<"\n|                         6:Tim kiem  mi pham theo ten                         |";											
		//	cout<<"\n|                         7:Xoa mi pham theo ma                                |";                 
			cout<<"\n|______________________________________________________________________________|\n"<<endl;;
			cin>>nhap;
			switch(nhap)
			{			
				case 1:
					NhapDSMP(MP);
					break;
				case 2:
					HienDSMP(MP);
					break;
				case 3:
					LuuFileMP(MP);
					break;
				case 4:
					DocFileMP(MP);
					HienDSMP(MP);
					break;
				case 5:
					SapXepTangDanMP(MP);
					cout<<"Danh sach Mi Pham duoc sap xep tang dan theo so luong la: \n";
					HienDSMP(MP);
					break;
					
				case 6:
					timMHTen(MP);
					cout<<" \n";
					
					break;
//				case 7:
//					XoaMaMP(MP);
//					cout<<" \n";
//					HienDSMP(MP);
//					break;
				case 0:
					exit(0);
			}
		}
		break;
		case 2:
				while(true)
		{
			cout<<"\n______________________________________Quan Li NHAN VIEN_______________________";
			cout<<"\n|                          1: Nhap danh sach Nhan Vien                        |";
			cout<<"\n|                          2: Hien danh sach Nhan Vien                        |";
			cout<<"\n|                          3: Luu File danh sach Nhan Vien                    |";
			cout<<"\n|                          4: Doc File danh sach Nhan Vien                    |";
			cout<<"\n|                          5: Tim kiem Nhan Vien theo que quan                |";
			cout<<"\n|_____________________________________________________________________________|\n"<<endl;;
			cin>>nhap;
			switch(nhap)				
			{
				case 1:
					NhapDSNV(NV,nv);
					break;
				case 2:
					HienDSNV(NV);
					break;
				case 3:
					LuuFileNV(NV);
					break;
				case 4:
					DocFileNV(NV);
					break;
				case 5:
					TimKiemNV(NV);
					cout<<" \n";
					break;
				case 0:
					exit(0);
			}
		}
		break;
		case 3:
				while(true)
		{
			cout<<"\n_______________________Quan Li Hoa Don____________________________________";
			cout<<"\n|                    1: Nhap danh sach Hoa Don                            |";
			cout<<"\n|                    2: Hien danh sach Hoa Don                            |";
			cout<<"\n|                    3: Luu File danh sach Hoa Don                        |";
			cout<<"\n|                    4: Doc File danh sach Hoa Don                        |";
			cout<<"\n|                    5: Khach Hang co tien mua hang lon nhat              |";
			cout<<"\n|                    6: Khach Hang co tien mua hang nho nhat              |";
			cout<<"\n|                    7: Sap xep Hoa Don theo tong tien giam dan           |";
			cout<<"\n|                    8:Sap xep Hoa Don theo tong tien tang dan            |";
			cout<<"\n|                    9: Tim Hoa Don theo ma                               |";
			cout<<"\n|                    10: Xoa Hoa Don theo ma                              |";
			cout<<"\n|                    11: Tong tien hoa don                                |";
			cout<<"\n|_________________________________________________________________________|\n";
			cin>>nhap;
			switch(nhap)
			{
				case 1:
					NhapDSHD(HD,mp,MP);
					break;
				case 2:
					HienDSHD(HD,MP);
					break;
				case 3:
					LuuFileHD(HD);
					LuuFileMP(MP);
					break;
				case 4:
					DocFileMP(MP);
					DocFileHD(HD,MP);
					break;
				case 5:
					KHTT_Max(HD);
					break;
				case 6:
					KHTT_Min(HD);
					break;
				case 7:
					cout<<"Hoa don duoc sap xep giam dan theo tong tien la: \n";
					SapXepGiamDanTT(HD);
					HienDSHD(HD,MP);
					break;
				case 8:
            		SapXepTangDanTT(HD);
            		cout<<"Don Hang duoc sap xep tang dan theo tong tien la: \n";
		            HienDSHD(HD,MP);
		            break;	
				case 9:
					timHDma(HD,MP);
					cout<<" \n";
					break;	
				case 10:
					XoaMaHD(HD,MP);
					cout<<"Danh sach hoa don sau khi xoa la: \n";
					HienDSHD(HD,MP);
					break;
				case 11:
					cout<<"Tong tien hoa don la :";
					tongTienHD(HD);
				case 0:
					exit(0);
			}
		}
		break;
		
	}	
  }
}
					
		
		



