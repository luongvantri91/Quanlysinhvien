#include<conio.h>
#include<stdio.h>
#include "mylib.h"
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define soitem 5
#define soitem1 7
#define soitem2 7
#define soitem3 7
#define soitem4 6

int trung_dulieu=0;
int thi_qua=0;
char mn[4][40]={"         MENU LOP         ","      MENU SINH VIEN      ","       MENU MON HOC       ","        MENU  DIEM        "};
char td[soitem][40]={"      Quan Ly Lop      ","   Quan Ly Sinh Vien   ","    Quan Ly Mon Hoc    ","      Quan Ly Diem     ","         Thoat         "};

char td1[soitem1][40]={"    Nhap Danh Sach Lop    ","     In Danh Sach Lop     ","        Tim Lop Hoc       ","     Sua Thong Tin Lop    ","         Xoa lop          ","         Save file        ","         Load file        "};

char td2[soitem2][40]={" Nhap Danh Sach Sinh Vien ","  In Danh Sach Sinh Vien  ","       Tim Sinh Vien      "," Sua Thong Tin Sinh Vien  ","      Xoa Sinh Vien       ","         Save file        ","         Load file        "};

char td3[soitem3][40]={"  Nhap Danh Sach Mon Hoc  ","   In Danh Sach Mon Hoc   ","        Tim Mon Hoc       ","  Sua Thong Tin Mon Hoc   ","       Xoa Mon Hoc        ","         Save file        ","         Load file        "};

char td4[soitem4][40]={"    Nhap Danh Sach Diem   ","     In Danh Sach Diem    ","    Tim Diem Sinh Vien    "/*,"    Xoa Diem Sinh Vien    "*/,"     In danh sach thi     ","         Save file        ","         Load file        "};

char wn[MAX][80]={"Chua nhap ma lop !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Chua nhap ten lop !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Ma lop vuot qua so ky tu cho phep !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Ten lop vuot qua so ky tu cho phep !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Ma lop trung !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Nhap tiep khong ? c/k",
				  "Chua nhap ma sinh vien !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Chua nhap ho sinh vien !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Chua nhap ten sinh vien !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Chua nhap phai sinh vien !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Phai khong hop le !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Ma lop khong ton tai!!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Ma sinh vien trung!!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Ho sinh vien vuot qua so ky tu cho phep !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Ten sinh vien vuot qua so ky tu cho phep !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Chua nhap ma mon hoc !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Chua nhap ten mon hoc !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Chua nhap so tiet ly thuyet !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Chua nhap so tiet thuc hanh !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Ma mon hoc vuot qua so ky tu cho phep !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Ten mon hoc vuot qua so ky tu cho phep !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Ma mon hoc trung !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Nhap sai so tiet ly thuyet !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Nhap sai so tiet thuc hanh !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Chua nhap lan  !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Chua nhap diem  !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Ma mon hoc khong ton tai !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Ma sinh vien khong ton tai !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Nhap lan sai !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Nhap diem sai !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Chua tao danh sach mon hoc !!! ESC: Thoat",
				  "Chua tao danh sach lop !!! ESC: Thoat",
				  "Lop nay chua tao danh sach sinh vien !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Chua nhap bang diem !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Du lieu bi trung !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Khong the save file !!! ESC: Thoat",
				  "Khong co du lieu !!! ESC: Thoat",
				  "Tap tin khong ton tai !!! ESC: Thoat",
				  "Sinh vien da thi dat trong lan 1 !!! ENTER: Tiep tuc nhap / ESC: Thoat",
				  "Sua thanh cong !!! ESC: Thoat",
				  "Xoa thanh cong !!! ESC: Thoat",
				  };
				  
struct lop
{
	char malop[10];
	char tenlop[20];
};

struct dsl
{
	int n;
	struct lop nodes[MAX];
};

struct sinhvien
{
	int masv;
	char ho[10];
	char ten[10];
	char phai[5];
	char ml[10];
};

struct dssv
{
	struct sinhvien info;
	struct dssv *left,*right;
};
typedef struct dssv *ptr_sv;

struct monhoc
{
	char mamh[10];
	char tenmh[30];
	int stlt;
	int stth;

};

struct dsmh
{
	struct monhoc infomh;
	struct dsmh *next;
};
typedef struct dsmh *ptr_mh;

struct diem
{
	int msv;
	char mmh[10];
	int lan;
	int diem;
};

struct dsd
{
	struct diem infod;
	struct dsd *next;
};
typedef struct dsd *ptr_d;

void mau(int maunen,int mauchu)
{
	SetBGColor(maunen);
	SetColor(mauchu);
}
void Warning(char *s,int maunen)
{
	do
	{
	mau(9,15);
	gotoxy(5,21);
	puts(s);
	Sleep(500);
	mau(maunen,15);
	gotoxy(5,21);
	for(int i=0;i<75;i++)
	printf(" ");
	Sleep(300);

	}while(!kbhit());
	mau(maunen,15);
	gotoxy(5,21);
	for(int i=0;i<75;i++)
	printf(" ");

}

void nennhap()
{
	mau(2,15);
	system("cls");
	gotoxy(0,1);
	for(int i=0;i<80;i++)
	printf("%c",196);
	gotoxy(0,3);
	for(int i=0;i<80;i++)
	printf("%c",196);
	mau(15,0);
	gotoxy(0,2);
	for(int i=0;i<80;i++)
	printf(" ");
	mau(2,15);
	mau(2,0);
	gotoxy(0,24);
	for(int i=0;i<80;i++) printf("%c",177);
	gotoxy(0,23);
	for(int i=0;i<80;i++) printf("%c",177);
	gotoxy(0,22);
	for(int i=0;i<80;i++) printf("%c",177);
	mau(2,15);
	gotoxy(30,4);
	printf("Bam ESC de thoat !!!");
}
void nenxuat()
{
	mau(5,15);
	system("cls");
	gotoxy(0,1);
	for(int i=0;i<80;i++)
	printf("%c",196);
	gotoxy(0,3);
	for(int i=0;i<80;i++)
	printf("%c",196);
	mau(15,0);
	gotoxy(0,2);
	for(int i=0;i<80;i++)
	printf(" ");
	mau(5,15);
	gotoxy(0,22);
	for(int i=0;i<80;i++) printf("%c",196);
	mau(5,10);
	gotoxy(1,23);
	printf("ESC: Thoat");
	gotoxy(64,23);
	printf("Prev %c %c %c Next",27,179,26);
}
void nentim()
{
	mau(4,15);
	system("cls");
	gotoxy(0,1);
	for(int i=0;i<80;i++)
	printf("%c",196);
	gotoxy(0,3);
	for(int i=0;i<80;i++)
	printf("%c",196);
	mau(15,0);
	gotoxy(0,2);
	for(int i=0;i<80;i++)
	printf(" ");
	mau(4,15);
	gotoxy(0,22);
	for(int i=0;i<80;i++) printf("%c",196);
	mau(4,10);
	gotoxy(1,23);
	printf("ESC: Thoat");

}
char ktkytu(char c)
{
	char c1;
	if(c==0) c1=getch();
	else c1=c;
	return c1;
}
void format_chuoi(char *s)
{
	int i;
	for(i=0; i<strlen(s); i++) //tra ve do dai chuoi
		if(s[i] != 32)
		{
			int j;
			for(j=0; j<strlen(s)-i+1; j++)
				s[j]=s[j+i];
			break;
		}
	for(i=0; i<strlen(s)-1; i++)    //xoa khoang trang giua
		if(s[i]==32 && s[i+1]==32)
		{
			int j;
			for(j=i+1; j<strlen(s); j++)
			s[j]=s[j+1];
			i--;
		}
	for(i=strlen(s)-1; i>=0; i--) //xoa khoang trang sau
		if(s[i] != 32)
		{
			s[i+1]='\0';
			break;
		}
}
void chu_in(char *s)
{
	strcpy(s, strlwr(s));	//chuyen tat ca thanh chu nho và copy vào "chuoi"
	s[0]= toupper(s[0]);	//chuyen chu cai dau tien cua day thành chu hoa
	int i;
	for(i=0; i<strlen(s);i++)
		if(s[i]==32)
			s[i+1]=toupper(s[i+1]); //chuyen chu sau space thanh chu hoa
}
int kiemtramalop(dsl l, char s[])
{
	for(int i=0;i<l.n;i++)
	if(strcmp(s,l.nodes[i].malop)==0)
        return 1;
	return 0;
}
int timmalop(dsl l,char str[])
{
	for(int i=0;i<l.n;i++)
	if(strcmp(l.nodes[i].malop,str)==0) return i;
	return -1;
}
int kiemtramamh(ptr_mh mh,char s[])
{
	ptr_mh p;
	for(p=mh;p!=NULL;p=p->next)
	if(strcmp(s,p->infomh.mamh)==0)
	return 0;
	return 1;
}
int kiemtrabd(ptr_d bd,int s)
{
	ptr_d p;
	for(p=bd;p!=NULL;p=p->next)
	if(p->infod.msv==s) return 1;
	return 0;
}
int kiemtramlsv(ptr_sv sv,char s[])
{
	ptr_sv p;
	for(p=sv;p!=NULL;p=p->right)
	if(strcmp(s,p->info.ml)==0)
	return 1;
	return 0;
}
int kiemtramasv(ptr_sv sv, int s)
{
	ptr_sv p;
	for(p=sv;p!=NULL;p=p->right)
	if(p->info.masv==s)
	return 1;
	return 0;
}
void delete_first(ptr_sv &sv)
{
	ptr_sv tam=sv;
	if(sv->right==NULL)
	sv=NULL;
	else
	{
		sv=tam->right;
		sv->left=NULL;
	}
	delete(tam);
}
void xoa(ptr_sv &sv,ptr_sv p)
{
	if(p==sv) delete_first(sv);
		else
		{
			ptr_sv q,r;
			q=p->left;
			r=p->right;
			r->left=q;
			q->right=r;
			delete(p);
		}
}
void xoa1(ptr_d &bd,ptr_d p)
{
	if(p==bd)
	{
		bd=p->next;
		delete(p);
	}
	else
	{
		ptr_d q=bd;
		while(q->next!=p) q=q->next;
		q->next=p->next;
		delete(p);
	}
}
void nhaplop(struct dsl &l)
{

	int i;
	char c,c1,ch;
	nennhap();
	gotoxy(31,2);
	mau(15,0);
	printf("NHAP DANH SACH LOP");
	mau(2,15);
	gotoxy(20,8);
	printf("Ma lop");
	gotoxy(20,10);
	printf("Ten lop");
	gotoxy(51,8); printf("%c",25);
	gotoxy(51,10); printf("%c",24);
	while(1)
	{
		lop tam;
		int m=-1,tl=-1;

		mau(0,15);
		gotoxy(30,8);
		for(i=0;i<20;i++) printf(" ");
		gotoxy(30,10);
		for(i=0;i<20;i++) printf(" ");

nhapmalop:/*	mau(2,15);
			gotoxy(20,12);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,13);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,14);
			for(i=0;i<60;i++) printf(" ");*/
			mau(2,14);
			gotoxy(20,12);
			printf("*** Huong dan ***");
			gotoxy(20,13);
			printf("- Ma lop gom cac ky tu(a-z) va cac so (0->9)");
			gotoxy(20,14);
			printf("- Chieu dai toi da 10 ky tu");
			gotoxy(31+m,8);
				mau(0,15);
				c=getch();
				c1=ktkytu(c);

				while(c1!=27&&c1!=13&&c1!=80&&c1!=72&&c1!=77&&c1!=75&&c1!=9)
				{
					if(c1==8&&m>-1)
					{
						m--;
						gotoxy(31+m,8);
						printf(" ");
						gotoxy(31+m,8);

					}
					else
					{
						if(c1>='0'&&c1<='9'||c1>='A'&&c1<='Z'||c1>='a'&&c1<='z'&&m<9)
						{
							printf("%c",c1);
							tam.malop[++m]=c1;
							tam.malop[m]=toupper(tam.malop[m]);
						}
					}
					tam.malop[m+1]='\0';
					c=getch();
					c1=ktkytu(c);
				}
			if(c1==27) return;
			if(c1==72||c1==75||c1==77) goto nhapmalop;
			if(c1==13||c1==80||c1==9)
nhaptenlop:	mau(2,15);
			gotoxy(20,12);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,13);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,14);
			for(i=0;i<60;i++) printf(" ");
			mau(2,14);
			gotoxy(20,12);
			printf("*** Huong dan");
			gotoxy(20,13);
			printf("- Ten lop gom cac ky tu(a-z) va cac so (0->9)");
			gotoxy(20,14);
			printf("- Chieu dai toi da 20 ky tu");
			gotoxy(31+tl,10);
			mau(0,15);
			c=getch();
			c1=ktkytu(c);

			while(c1!=27&&c1!=13&&c1!=80&&c1!=72&&c1!=77&&c1!=75&&c1!=9)
			{
				if(c1==8&&tl>-1)
				{
					tl--;
					gotoxy(31+tl,10);
					printf(" ");
					gotoxy(31+tl,10);

				}
				else
				{
						if(c1>='0'&&c1<='9'||c1>='A'&&c1<='Z'||c1>='a'&&c1<='z')
						{
							printf("%c",c1);
							tam.tenlop[++tl]=c1;
							tam.tenlop[tl]=toupper(tam.tenlop[tl]);
						}
				}
				tam.tenlop[tl+1]='\0';
				c=getch();
				c1=ktkytu(c);
			}

			if(c1==27) return;
			if(c1==72) goto nhapmalop;
			if(c1==80||c1==77||c1==75||c1==9) goto nhaptenlop;
			if(c1==13)
			{
				if(m==-1)
				{
					Warning(wn[0],2);
					do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapmalop;
				}
				if(tl==-1)
				{
					Warning(wn[1],2);
					do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhaptenlop;
				}
				if(m>9)
				{
					Warning(wn[2],2);
					do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapmalop;
				}
				if(tl>19)
				{
					Warning(wn[3],2);
					do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhaptenlop;
				}
				if(kiemtramalop(l,tam.malop)==1)
				{
					Warning(wn[4],2);
					do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapmalop;
				}
				l.nodes[l.n++]=tam;
			}
	}
}
int tinhmaso(int j,int m)
{
	int s=1,k=m-j;
	for(int i=0;i<k;i++)
	s=s*10;
	return s;
}
void sapxep(ptr_sv &sv)
{
	ptr_sv p,q,pmin;
	sinhvien min;
	for(p=sv;p->right!=NULL;p=p->right)
	{
		min=p->info;
		pmin=p;
		for(q=p->right;q!=NULL;q=q->right)
		if(strcmp(min.ten,q->info.ten)>0)
		{
			min=q->info;
			pmin=q;
		}
		else
		if(strcmp(min.ten,q->info.ten)==0&&strcmp(min.ho,q->info.ho)>0)
		{
			min=q->info;
			pmin=q;
		}
		pmin->info=p->info;
		p->info=min;
	}
}
void insert_right(ptr_sv &sv,ptr_sv p)
{
	ptr_sv q;
	q=sv;
	if(sv==NULL)
	{
		p->left=NULL;
		sv=p;
	}
	else
	if(sv->right==NULL)
	{
		p->left=sv;
		sv->right=p;
	}
	else
	{
		for(q=sv;q->right!=NULL;q=q->right);
		q->right=p;
		p->left=q;
	}
	p->right=NULL;
	sapxep(sv);
}

void nhapsv(ptr_sv &sv,dsl l)
{
	int i;
	char c,c1,ch;
	nennhap();
	mau(15,0);
	gotoxy(28,2);
	printf("NHAP DANH SACH SINH VIEN");
	mau(2,15);
	gotoxy(20,8);
	printf("Ma sinh vien");
	gotoxy(20,10);
	printf("Ho sinh vien");
	gotoxy(20,12);
	printf("Ten sinh vien");
	gotoxy(20,14);
	printf("Phai (nam/nu)");
	gotoxy(20,16);
	printf("Ma lop");
	gotoxy(56,8); printf("%c",25);
	gotoxy(56,10); printf("%c%c",24,25);
	gotoxy(56,12); printf("%c%c",24,25);
	gotoxy(44,14); printf("%c%c",24,25);
	gotoxy(56,16); printf("%c",24);
	while(1)
	{
		ptr_sv tam;
		tam=new dssv;
		int ml=-1,msv=0,h=-1,t=-1,p=-1;
		int s[10];
		mau(0,15);
		gotoxy(35,8);
		for(i=0;i<10;i++) printf(" ");
		gotoxy(35,10);
		for(i=0;i<20;i++) printf(" ");
		gotoxy(35,12);
		for(i=0;i<20;i++) printf(" ");
		gotoxy(35,14);
		for(i=0;i<8;i++) printf(" ");
		gotoxy(35,16);
		for(i=0;i<20;i++) printf(" ");
nhapmasv:	mau(2,15);
			gotoxy(20,18);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,19);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,20);
			for(i=0;i<60;i++) printf(" ");
			mau(2,14);
			gotoxy(20,18);
			printf("*** Huong dan");
			gotoxy(20,19);
			printf("- Ma sinh vien gom cac so (0->9)");
			gotoxy(20,20);
			printf("- Ngoai ra khong bao gom ky tu khac");
			gotoxy(35+msv,8);
				mau(0,15);
				c=getch();
				c1=ktkytu(c);

				while(c1!=27&&c1!=13&&c1!=80&&c1!=72&&c1!=77&&c1!=75&&c1!=9)
				{
					if(c1==8&&msv>0)
					{
						msv--;
						gotoxy(35+msv,8);
						printf(" ");
						gotoxy(35+msv,8);

					}
					else
					{
						if(c1>='0'&&c1<='9')
						{
							printf("%c",c1);
							s[++msv]=c1-'0';
						}
					}
					c=getch();
					c1=ktkytu(c);
				}
			if(c1==27) return;
			if(c1==72||c1==75||c1==77) goto nhapmasv;
			if(c1==13||c1==80||c1==9)
nhapho:		mau(2,15);
			gotoxy(20,18);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,19);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,20);
			for(i=0;i<60;i++) printf(" ");
			mau(2,14);
			gotoxy(20,18);
			printf("*** Huong dan");
			gotoxy(20,19);
			printf("- Ho sinh vien gom cac ky tu(a->z) va khoang trang");
			gotoxy(20,20);
			printf("- Chieu dai toi da 10 ky tu");
		gotoxy(36+h,10);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=27&&c1!=13&&c1!=80&&c1!=72&&c1!=77&&c1!=75&&c1!=9)
		{
			if(c1==8&&h>-1)
			{
				h--;
				gotoxy(36+h,10);
				printf(" ");
				gotoxy(36+h,10);
			}
			else
			{
				if(c1==' '||c1>='A'&&c1<='Z'||c1>='a'&&c1<='z')
					{
						printf("%c",c1);
						tam->info.ho[++h]=c1;
					}
			}
			tam->info.ho[h+1]='\0';
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==72) goto nhapmasv;
		if(c1==75||c1==77) goto nhapho;
		if(c1==80||c1==13||c1==9)
nhapten:	mau(2,15);
			gotoxy(20,18);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,19);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,20);
			for(i=0;i<60;i++) printf(" ");
			mau(2,14);
			gotoxy(20,18);
			printf("*** Huong dan");
			gotoxy(20,19);
			printf("- Ten sinh vien gom cac ky tu(a->z) va khoang trang");
			gotoxy(20,20);
			printf("- Chieu dai toi da 10 ky tu");
		gotoxy(36+t,12);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=27&&c1!=13&&c1!=80&&c1!=72&&c1!=77&&c1!=75&&c1!=9)
		{
			if(c1==8&&t>-1)
			{
				t--;
				gotoxy(36+t,12);
				printf(" ");
				gotoxy(36+t,12);
			}
			else
			{
				if(c1==' '||c1>='A'&&c1<='Z'||c1>='a'&&c1<='z')
				{
						printf("%c",c1);
						tam->info.ten[++t]=c1;
				}
			}
			tam->info.ten[t+1]='\0';
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==72) goto nhapho;
		if(c1==75||c1==77) goto nhapten;
		if(c1==80||c1==13||c1==9)
nhapphai:	mau(2,15);
			gotoxy(20,18);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,19);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,20);
			for(i=0;i<60;i++) printf(" ");
			mau(2,14);
			gotoxy(20,18);
			printf("*** Huong dan");
			gotoxy(20,19);
			printf("- Phai chi co the la 'nam' hoac 'nu'");
			gotoxy(20,20);
			printf("- Ngoai ra khong con truong hop khac");
		gotoxy(36+p,14);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=27&&c1!=13&&c1!=80&&c1!=72&&c1!=77&&c1!=75&&c1!=9)
		{
			if(c1==8&&p>-1)
			{
				p--;
				gotoxy(36+p,14);
				printf(" ");
				gotoxy(36+p,14);
			}
			else
			{
					if(c1>='A'&&c1<='Z'||c1>='a'&&c1<='z')
					{
						printf("%c",c1);
						tam->info.phai[++p]=c1;
					}
			}
			tam->info.phai[p+1]='\0';
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==75||c1==77) goto nhapphai;
		if(c1==72) goto nhapten;
		if(c1==80||c1==13||c1==9)
nhapml:		mau(2,15);
			gotoxy(20,18);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,19);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,20);
			for(i=0;i<60;i++) printf(" ");
			mau(2,14);
			gotoxy(20,18);
			printf("*** Huong dan");
			gotoxy(20,19);
			printf("- Ma lop chi gom cac ky tu(a->z) va so(0->9)");
			gotoxy(20,20);
			printf("- Chieu dai toi da 10 ky tu");
		gotoxy(36+ml,16);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=27&&c1!=13&&c1!=80&&c1!=72&&c1!=77&&c1!=75&&c1!=9)
		{
			if(c1==8&&ml>-1)
			{
				ml--;
				gotoxy(36+ml,16);
				printf(" ");
				gotoxy(36+ml,16);
			}
			else
			{
				if(c1!=8)
				{
					if(c1>=0)
					{
						printf("%c",c1);
						tam->info.ml[++ml]=c1;
						tam->info.ml[ml]=toupper(tam->info.ml[ml]);
					}
				}
			}
			tam->info.ml[ml+1]='\0';
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==72) goto nhapphai;
		if(c1==80||c1==75||c1==77||c1==9) goto nhapml;
		if(c1==13)
		{
			if(msv==0)
			{
				Warning(wn[6],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapmasv;
			}
			if(h==-1)
			{
				Warning(wn[7],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapho;
			}
			if(t==-1)
			{
				Warning(wn[8],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapten;
			}
			if(p==-1)
			{
				Warning(wn[9],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapphai;
			}
			if(ml==-1)
			{
				Warning(wn[0],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapml;
			}
			if(h>9)
			{
				Warning(wn[13],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapho;
			}
			if(t>9)
			{
				Warning(wn[14],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapten;
			}
			tam->info.masv=0;
			for(int j=msv;j>0;j--)
			tam->info.masv += s[j]*tinhmaso(j,msv);
			if(kiemtramasv(sv,tam->info.masv)==1)
			{
				Warning(wn[12],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapmasv;
			}
			if(strcmp(tam->info.phai,"nam")!=0&&strcmp(tam->info.phai,"nu")!=0)
			{
				Warning(wn[10],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapphai;
			}
			if(kiemtramalop(l,tam->info.ml)==0)
			{
				Warning(wn[11],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapml;
			}
			format_chuoi(tam->info.ho); chu_in(tam->info.ho);
			format_chuoi(tam->info.ten); chu_in(tam->info.ten);
			chu_in(tam->info.phai);
			insert_right(sv,tam);
			/*if(trungma==1)
			{
				trungma=0;
				Warning(wn[12],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapmasv;
			}*/
		}
	}
}
void insert_mh(ptr_mh &mh,ptr_mh tam)
{
	ptr_mh p;
	tam->next=NULL;
	if(mh==NULL)
	mh=tam;
	else
	{
		for(p=mh;p->next!=NULL;p=p->next);
		p->next=tam;
	}
}
void nhapmh(ptr_mh &mh)
{
	char c,c1,ch;
	nennhap();
	mau(15,0);
	gotoxy(30,2);
	printf("NHAP DANH SACH MON HOC");
	mau(2,15);
	gotoxy(20,8);
	printf("Ma mon hoc");
	gotoxy(20,10);
	printf("Ten mon hoc");
	gotoxy(20,12);
	printf("So tiet LT");
	gotoxy(20,14);
	printf("So tiet TH");
	gotoxy(56,8); printf("%c",25); gotoxy(66,10); printf("%c%c",24,25);
	gotoxy(44,12); printf("%c%c",24,25); gotoxy(44,14); printf("%c",24);
	while(1)
	{
		int m=-1,t=-1,lt=0,th=0;
		int i;
		int u[10],v[10];
		ptr_mh tam;
		tam=new dsmh;
		mau(0,15);
		gotoxy(35,8);
		for(i=0;i<20;i++) printf(" ");
		gotoxy(35,10);
		for(i=0;i<30;i++) printf(" ");
		gotoxy(35,12);
		for(i=0;i<8;i++) printf(" ");
		gotoxy(35,14);
		for(i=0;i<8;i++) printf(" ");
nhapmamh:	mau(2,15);
			gotoxy(20,16);
	 		for(i=0;i<60;i++) printf(" ");
			gotoxy(20,17);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,18);
			for(i=0;i<60;i++) printf(" ");
			mau(2,14);
			gotoxy(20,16);
			printf("*** Huong dan");
			gotoxy(20,17);
			printf("- Ma mon hoc chi gom cac ky tu(a->z) va so(0->9)");
			gotoxy(20,18);
			printf("- Chieu dai toi da 10 ky tu");
		gotoxy(36+m,8);
			mau(0,15);
			c=getch();
			c1=ktkytu(c);
			while(c1!=13&&c1!=27&&c1!=72&&c1!=75&&c1!=77&&c1!=80&&c1!=9)
			{
				if(c1==8&&m>-1)
				{
					m--;
					gotoxy(36+m,8);
					printf(" ");
					gotoxy(36+m,8);
				}
				else
				{

					if(c1>='0'&&c1<='9'||c1>='A'&&c1<='Z'||c1>='a'&&c1<='z')
					{
						printf("%c",c1);
						tam->infomh.mamh[++m]=c1;
						tam->infomh.mamh[m]=toupper(tam->infomh.mamh[m]);
					}

				}
				tam->infomh.mamh[m+1]='\0';
				c=getch();
				c1=ktkytu(c);
			}
		if(c1==27) return;
		if(c1==72||c1==75||c1==77) goto nhapmamh;
		if(c1==80||c1==13||c1==9)
nhaptenmh:	mau(2,15);
			gotoxy(20,16);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,17);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,18);
			for(i=0;i<60;i++) printf(" ");
			mau(2,14);
			gotoxy(20,16);
			printf("*** Huong dan");
			gotoxy(20,17);
			printf("- Ten mon hoc chi gom cac ky tu(a->z) va khoang trang");
			gotoxy(20,18);
			printf("- Chieu dai toi da 30 ky tu");
		gotoxy(36+t,10);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=13&&c1!=27&&c1!=72&&c1!=75&&c1!=77&&c1!=80&&c1!=9)
		{
			if(c1==8&&t>-1)
			{
				t--;
				gotoxy(36+t,10);
				printf(" ");
				gotoxy(36+t,10);
			}
			else
			{
				if(c1>='A'&&c1<='Z'||c1>='a'&&c1<='z'||c1==' ')
				{
					printf("%c",c1);
					tam->infomh.tenmh[++t]=c1;
				}
			}
			tam->infomh.tenmh[t+1]='\0';
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==72) goto nhapmamh;
		if(c1==75||c1==77) goto nhaptenmh;
		if(c1==80||c1==13||c1==9)
nhapstlt:	mau(2,15);
			gotoxy(20,16);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,17);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,18);
			for(i=0;i<60;i++) printf(" ");
			mau(2,14);
			gotoxy(20,16);
			printf("*** Huong dan");
			gotoxy(20,17);
			printf("- So tiet LT gom cac so(0->9)");
			gotoxy(20,18);
			printf("- La 1 so chia het cho 15 va nho hon 200");
		gotoxy(35+lt,12);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=13&&c1!=27&&c1!=72&&c1!=75&&c1!=77&&c1!=80&&c1!=9)
		{
			if(c1==8&&lt>0)
			{
				lt--;
				gotoxy(35+lt,12);
				printf(" ");
				gotoxy(35+lt,12);
			}
			else
			{
				if(c>='0'&&c<='9')
				{
					printf("%c",c1);
					u[++lt]=c1-'0';
				}
			}
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==72) goto nhaptenmh;
		if(c1==75||c1==77) goto nhapstlt;
		if(c1==80||c1==13||c1==9)
nhapstth:	mau(2,15);
			gotoxy(20,16);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,17);
			for(i=0;i<60;i++) printf(" ");
			gotoxy(20,18);
			for(i=0;i<60;i++) printf(" ");
			mau(2,14);
			gotoxy(20,16);
			printf("*** Huong dan");
			gotoxy(20,17);
			printf("- So tiet TH gom cac so(0->9)");
			gotoxy(20,18);
			printf("- La 1 so chia het cho 15 va nho hon 200");
		gotoxy(35+th,14);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=13&&c1!=27&&c1!=72&&c1!=75&&c1!=77&&c1!=80&&c1!=9)
		{
			if(c1==8&&th>0)
			{
				th--;
				gotoxy(35+th,14);
				printf(" ");
				gotoxy(35+th,14);
			}
			else
			{
				if(c>='0'&&c<='9')
				{
					printf("%c",c1);
					v[++th]=c1-'0';
				}
			}
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==72) goto nhapstlt;
		if(c1==75||c1==77||c1==80||c1==9) goto nhapstth;
		if(c1==13)
		{
			if(m==-1)
			{
				Warning(wn[15],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapmamh;
			}
			if(t==-1)
			{
				Warning(wn[16],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhaptenmh;
			}
			if(lt==0)
			{
				Warning(wn[17],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapstlt;
			}
			if(th==0)
			{
				Warning(wn[18],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapstth;
			}
			if(m>9)
			{
				Warning(wn[19],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapmamh;
			}
			if(t>29)
			{
				Warning(wn[20],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhaptenmh;
			}
			tam->infomh.stlt=0;
			for(int j=lt;j>0;j--)
			tam->infomh.stlt += u[j]*tinhmaso(j,lt);
			tam->infomh.stth=0;
			for(int j=th;j>0;j--)
			tam->infomh.stth += v[j]*tinhmaso(j,th);
			if(kiemtramamh(mh,tam->infomh.mamh)==0)
			{
				Warning(wn[21],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapmamh;
			}
			if((tam->infomh.stlt)>200||(tam->infomh.stlt)%15!=0)
			{
				Warning(wn[22],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapstlt;
			}
			if((tam->infomh.stth)>200||(tam->infomh.stth)%15!=0)
			{
				Warning(wn[23],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapstth;
			}
			format_chuoi(tam->infomh.tenmh);
			chu_in(tam->infomh.tenmh);
			insert_mh(mh,tam);
		}
	}
}
void insert_diem(ptr_d &bd,ptr_d tam)
{
	ptr_d p=bd;
	while(p!=NULL)
	{
		if(strcmp(p->infod.mmh,tam->infod.mmh)==0&&p->infod.msv==tam->infod.msv&&p->infod.lan==tam->infod.lan)
		{
			trung_dulieu=1;
			return;
		}
		if(strcmp(p->infod.mmh,tam->infod.mmh)==0&&p->infod.msv==tam->infod.msv&&tam->infod.lan==2&&p->infod.diem>=5)
		{
			thi_qua=1;
			return;
		}
		p=p->next;
	}

	tam->next=NULL;
	if(bd==NULL)
	bd=tam;
	else
	{
		for(p=bd;p->next!=NULL;p=p->next);
		p->next=tam;
	}
}
void nhapdiem(ptr_d &bd,ptr_sv sv,ptr_mh mh)
{
	char c,c1,ch;
	int i;
	nennhap();
	gotoxy(31,2);
	mau(15,0);
	printf("NHAP DANH SACH DIEM");
	mau(2,15);
	gotoxy(20,8);
	printf("Ma mon hoc");
	gotoxy(20,10);
	printf("Ma sinh vien");
	gotoxy(20,12);
	printf("Lan");
	gotoxy(20,14);
	printf("Diem");
	gotoxy(56,8); printf("%c",25);
	gotoxy(56,10); printf("%c%c",24,25);
	gotoxy(44,12); printf("%c%c",24,25);
	gotoxy(44,14); printf("%c",24);
	while(1)
	{
		ptr_d tam;
		tam=new dsd;
		int mho=-1,ms=0,l=0,d=0;
		int q[10],t[10],u[10];
		mau(0,15);
		gotoxy(35,8);
		for(i=0;i<20;i++) printf(" ");
		gotoxy(35,10);
		for(i=0;i<20;i++) printf(" ");
		gotoxy(35,12);
		for(i=0;i<8;i++) printf(" ");
		gotoxy(35,14);
		for(i=0;i<8;i++) printf(" ");
nhapmonhoc:
		mau(2,15);
		gotoxy(20,16);
		for(i=0;i<60;i++) printf(" ");
		gotoxy(20,17);
		for(i=0;i<60;i++) printf(" ");
		gotoxy(20,18);
		for(i=0;i<60;i++) printf(" ");
		mau(2,14);
		gotoxy(20,16);
		printf("*** Huong dan");
		gotoxy(20,17);
		printf("- Ma mon hoc gom cac ky tu(a-z) va cac so (0->9)");
		gotoxy(20,18);
		printf("- Chieu dai toi da 10 ky tu");
		gotoxy(36+mho,8);
			mau(0,15);
			c=getch();
			c1=ktkytu(c);
			while(c1!=13&&c1!=27&&c1!=72&&c1!=75&&c1!=77&&c1!=80&&c1!=9)
			{
				if(c1==8&&mho>-1)
				{
					mho--;
					gotoxy(36+mho,8);
					printf(" ");
					gotoxy(36+mho,8);
				}
				else
				{
					if(c>='0'&&c<='9'||c>='A'&&c<='Z'||c>='a'&&c<='z')
					{
						printf("%c",c1);
						tam->infod.mmh[++mho]=c1;
						tam->infod.mmh[mho]=toupper(tam->infod.mmh[mho]);
					}
				}
				tam->infod.mmh[mho+1]='\0';
				c=getch();
				c1=ktkytu(c);
			}
		if(c1==27) return;
		if(c1==72||c1==75||c1==77) goto nhapmonhoc;
		if(c1==80||c1==13||c1==9)
nhapmsv:
		mau(2,15);
		gotoxy(20,16);
		for(i=0;i<60;i++) printf(" ");
		gotoxy(20,17);
		for(i=0;i<60;i++) printf(" ");
		gotoxy(20,18);
		for(i=0;i<60;i++) printf(" ");
		mau(2,14);
		gotoxy(20,16);
		printf("*** Huong dan");
		gotoxy(20,17);
		printf("- Ma sinh vien gom cac so (0->9)");
		gotoxy(20,18);
		printf("- Ngoai ra khong bao gom ky tu khac");
		gotoxy(35+ms,10);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=13&&c1!=27&&c1!=72&&c1!=75&&c1!=77&&c1!=80&&c1!=9)
		{
			if(c1==8&&ms>0)
			{
				ms--;
				gotoxy(35+ms,10);
				printf(" ");
				gotoxy(35+ms,10);
			}
			else
			{
				if(c1>='0'&&c1<='9')
				{
					printf("%c",c1);
					q[++ms]=c1-48;
				}
			}
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==72) goto nhapmonhoc;
		if(c1==75||c1==77) goto nhapmsv;
		if(c1==13||c1==80||c1==9)
nhaplan:
		mau(2,15);
		gotoxy(20,16);
		for(i=0;i<60;i++) printf(" ");
		gotoxy(20,17);
		for(i=0;i<60;i++) printf(" ");
		gotoxy(20,18);
		for(i=0;i<60;i++) printf(" ");
		mau(2,14);
		gotoxy(20,16);
		printf("*** Huong dan");
		gotoxy(20,17);
		printf("- Lan chi co the la '1' hoac '2'");
		gotoxy(20,18);
		printf("- Ngoai ra khong con truong hop khac");
		gotoxy(35+l,12);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=13&&c1!=27&&c1!=72&&c1!=75&&c1!=77&&c1!=80&&c1!=9)
		{
			if(c1==8&&l>0)
			{
				l--;
				gotoxy(35+l,12);
				printf(" ");
				gotoxy(35+l,12);
			}
			else
			{
				if(c1>='0'&&c1<='9')
				{
					printf("%c",c1);
					t[++l]=c1-48;
				}
			}
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==72) goto nhapmsv;
		if(c1==75||c1==77) goto nhaplan;
		if(c1==13||c1==80||c1==9)
nhapdiem:
		mau(2,15);
		gotoxy(20,16);
		for(i=0;i<60;i++) printf(" ");
		gotoxy(20,17);
		for(i=0;i<60;i++) printf(" ");
		gotoxy(20,18);
		for(i=0;i<60;i++) printf(" ");
		mau(2,14);
		gotoxy(20,16);
		printf("*** Huong dan");
		gotoxy(20,17);
		printf("- Diem la 1 so trong khoang(0->10)");
		gotoxy(20,18);
		printf("- Ngoai ra khong bao gom ky tu khac");
		gotoxy(35+d,14);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=13&&c1!=27&&c1!=72&&c1!=75&&c1!=77&&c1!=80&&c1!=9)
		{
			if(c1==8&&d>0)
			{
				d--;
				gotoxy(35+d,14);
				printf(" ");
				gotoxy(35+d,14);
			}
			else
			{
				if(c1>='0'&&c1<='9')
				{
					printf("%c",c1);
					u[++d]=c1-48;
				}
			}
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==72) goto nhaplan;
		if(c1==75||c1==77||c1==80||c1==9) goto nhapdiem;
		if(c1==13)
		{
			if(mho==-1)
			{
				Warning(wn[15],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapmonhoc;
			}
			if(ms==0)
			{
				Warning(wn[6],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapmsv;
			}
			if(l==0)
			{
				Warning(wn[24],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhaplan;
			}
			if(d==0)
			{
				Warning(wn[25],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapdiem;
			}
			if(mho>9)
			{
				Warning(wn[19],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapmonhoc;
			}
			if(kiemtramamh(mh,tam->infod.mmh)==1)
			{
				Warning(wn[26],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapmonhoc;
			}
			tam->infod.msv = 0;
			for(int j=ms;j>0;j--)
			tam->infod.msv += q[j]*tinhmaso(j,ms);
			tam->infod.lan = 0;
			for(int j=l;j>0;j--)
			tam->infod.lan += t[j]*tinhmaso(j,l);
			tam->infod.diem = 0;
			for(int j=d;j>0;j--)
			tam->infod.diem += u[j]*tinhmaso(j,d);
			if(kiemtramasv(sv,tam->infod.msv)==0)
			{
				Warning(wn[27],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapmsv;
			}
			if(tam->infod.lan>2||tam->infod.lan<1)
			{
				Warning(wn[28],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhaplan;
			}
			if(tam->infod.diem<0||tam->infod.diem>10)
			{
				Warning(wn[29],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapdiem;
			}
			insert_diem(bd,tam);
			if(trung_dulieu==1)
			{
				trung_dulieu=0;
				Warning(wn[34],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapmonhoc;
			}
			if(thi_qua==1)
			{
				thi_qua=0;
				Warning(wn[38],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto nhapmsv;
			}
		}
	}
}
int demmh(ptr_mh mh)
{
	ptr_mh p;
	int dem=0;
	for(p=mh;p!=NULL;p=p->next)
	dem++;
	return dem;
}
void xuatmh(ptr_mh mh)
{
	ptr_mh p=mh;
	int trang=1,tongtrang,stt=0,dem=demmh(mh),i,j;
	char tam,ch;
	if(dem%7==0) tongtrang=dem/7;
	else tongtrang=dem/7+1;
	system("cls");
	nenxuat();
	mau(15,0);
	gotoxy(32,2);
	printf("DANH SACH MON HOC");
	if(mh==NULL)
	{
		Warning(wn[30],5);
		do
		{
			ch=getch();
		}while(ch!=27);
		if(ch==27) return;
	}
	do
	{
		mau(5,15);
		gotoxy(4,4);
		printf("%c",218);
		for(i=0;i<5;i++) printf("%c",196);	printf("%c",194);
		for(i=0;i<12;i++) printf("%c",196);	printf("%c",194);
		for(i=0;i<24;i++) printf("%c",196);	printf("%c",194);
		for(i=0;i<12;i++) printf("%c",196);	printf("%c",194);
		for(i=0;i<12;i++) printf("%c",196);	printf("%c",191);
		gotoxy(4,5);
		printf("%c STT %c MA MON HOC %c       TEN MON HOC      %c SO TIET LT %c SO TIET TH %c",179,179,179,179,179,179);
		for(i=0;i<7;i++)
		{
			mau(5,15);
			gotoxy(4,6+2*i);
			printf("%c",195);
			for(j=0;j<5;j++) printf("%c",196);	printf("%c",197);
			for(j=0;j<12;j++) printf("%c",196);	printf("%c",197);
			for(j=0;j<24;j++) printf("%c",196);	printf("%c",197);
			for(j=0;j<12;j++) printf("%c",196);	printf("%c",197);
			for(j=0;j<12;j++) printf("%c",196);	printf("%c",180);
			gotoxy(4,7+2*i);
			printf("%c     %c            %c                        %c            %c            %c",179,179,179,179,179,179);
		}
		gotoxy(4,20);
		printf("%c",192);
		for(i=0;i<5;i++) printf("%c",196);	printf("%c",193);
		for(i=0;i<12;i++) printf("%c",196);	printf("%c",193);
		for(i=0;i<24;i++) printf("%c",196);	printf("%c",193);
		for(i=0;i<12;i++) printf("%c",196);	printf("%c",193);
		for(i=0;i<12;i++) printf("%c",196);
		printf("%c",217);
		for(i=0;i<7;i++)
		{
			gotoxy(5,7+2*i);
			printf("  %-2d ",stt+1);
			gotoxy(11,7+2*i);
			printf("  %-10s",p->infomh.mamh);
			gotoxy(24,7+2*i);
			printf("  %-22s",p->infomh.tenmh);
			gotoxy(49,7+2*i);
			printf("    %-8d",p->infomh.stlt);
			gotoxy(62,7+2*i);
			printf("    %-8d",p->infomh.stth);
			stt++;
			p=p->next;
			if(p==NULL) break;
		}
		mau(5,15);
		gotoxy(35,21);
		printf("Trang: %d / %d",trang,tongtrang);

next1:
		tam=getch();
		if(tam==27) return;
		if(tam!=75&&tam!=77) goto next1;
		if(tam==77)
		{
			if(p==NULL)
			goto next1;
			trang++;
			continue;
		}
		if(tam==75)
		{
			if(stt<=7) goto next1;
			if(p==NULL&&dem%7!=0)
			{
				stt=stt-dem%7-7;
				p=mh;
				for(j=stt;j>0;j--)
				p=p->next;
			}
			else
			{
				stt=stt-14;
				p=mh;
				for(j=stt;j>0;j--)
				p=p->next;
			}
			trang--;
			continue;
		}
	}while(1);
}
void xuatlop(dsl l)
{
	int trang=1,tongtrang,i,j,stt=0;
	char tam,ch;
	if(l.n%7==0) tongtrang=l.n/7;
	else tongtrang=l.n/7+1;
	system("cls");
	nenxuat();
	mau(15,0);
	gotoxy(34,2);
	printf("DANH SACH LOP");
	if(l.n<=0)
	{
		Warning(wn[31],5);
		do
		{
			ch=getch();
		}while(ch!=27);
		if(ch==27) return;
	}

	do
	{
		mau(5,15);
		gotoxy(12,4); printf("%c",218);
		for(i=0;i<5;i++) printf("%c",196); printf("%c",194);
		for(i=0;i<12;i++) printf("%c",196); printf("%c",194);
		for(i=0;i<34;i++) printf("%c",196); printf("%c",191);
		gotoxy(12,5);
		printf("%c STT %c   MA LOP   %c             TEN LOP              %c",179,179,179,179);
		for(i=0;i<7;i++)
		{
			mau(5,15);
			gotoxy(12,6+2*i); printf("%c",195);
			for(j=0;j<5;j++) printf("%c",196); printf("%c",197);
			for(j=0;j<12;j++) printf("%c",196); printf("%c",197);
			for(j=0;j<34;j++) printf("%c",196); printf("%c",180);
			gotoxy(12,7+2*i);
			printf("%c     %c            %c                                  %c",179,179,179,179);
		}
		gotoxy(12,20);
		printf("%c",192);
		for(i=0;i<5;i++) printf("%c",196); printf("%c",193);
		for(i=0;i<12;i++) printf("%c",196); printf("%c",193);
		for(i=0;i<34;i++) printf("%c",196); printf("%c",217);
		for(i=0;i<7;i++)
		{
			gotoxy(13,7+2*i);
			printf("  %-2d ",stt+1);
			gotoxy(19,7+2*i);
			printf("  %-10s",l.nodes[stt].malop);
			gotoxy(32,7+2*i);
			printf("          %-24s",l.nodes[stt].tenlop);
			stt++;
			if(stt>=l.n)
			break;
		}
		mau(5,15);
		gotoxy(35,21);
		printf("Trang: %d / %d",trang,tongtrang);
next2:
		tam=getch();
		if(tam==27) return;
		if(tam!=75&&tam!=77) goto next2;
		if(tam==77)
		{
			if(stt==l.n) goto next2;
			trang++;
			continue;
		}
		if(tam==75)
		{
			if(stt<=7) goto next2;
			if(stt==l.n&&l.n%7!=0)
			stt=stt-l.n%7-7;
			else
			stt=stt-14;
			trang--;
			continue;
		}
	}while(1);
}
void xuatsv(ptr_sv sv,dsl l)
{
	ptr_sv p=sv;
	sinhvien a[5000];
	int trang=1,tongtrang,stt=0,i,j,dem=0,m=-1;
	char tam,str[20],c,c1,ch;
	system("cls");
	nenxuat();
	mau(9,15);
	gotoxy(30,9); printf("%c",201);
	for(i=0;i<22;i++) printf("%c",205);
	printf("%c",187);
	for(i=0;i<5;i++)
	{
		gotoxy(30,10+i);
		printf("%c                      %c",186,186);
	}
	gotoxy(30,15); printf("%c",200);
	for(i=0;i<22;i++) printf("%c",205);
	printf("%c",188);
	gotoxy(37,10); printf("NHAP MA LOP");
	mau(0,15);
	gotoxy(33,12);
	for(i=0;i<18;i++) printf(" ");
	gotoxy(33,13);
	for(i=0;i<18;i++) printf(" ");
b1:	gotoxy(34+m,13);
	mau(0,15);
	c=getch();
	c1=ktkytu(c);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
	{
		if(c1==8&&m>-1)
		{
			m--;
			gotoxy(34+m,13);
			printf(" ");
			gotoxy(34+m,13);
		}
		else
		{
			if(c1!=8&&c>0)
			{
				printf("%c",c1);
				str[++m]=c1;
				str[m]=toupper(str[m]);
			}
		}
		str[m+1]='\0';
		c=getch();
		c1=ktkytu(c);
	}
	if(c==27) return;
	if(c==72||c==75||c==77||c==80) goto b1;
	if(c==13)
	{

		if(m==-1)
		{
			Warning(wn[0],5);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto b1;
		}
		if(kiemtramalop(l,str)==0)
		{
			Warning(wn[11],5);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto b1;
		}
		if(kiemtramlsv(sv,str)==0)
		{
			Warning(wn[32],5);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto b1;
		}
	}
	for(p=sv;p!=NULL;p=p->right)
	if(strcmp(str,p->info.ml)==0)
	a[dem++]=p->info;
	if(dem%7==0) tongtrang=dem/7;
	else tongtrang=dem/7+1;
	mau(15,0);
	gotoxy(31,2);
	printf("DANH SACH SINH VIEN");
	do
	{
		mau(5,15);
		gotoxy(5,4); printf("%c",218);
		for(i=0;i<5;i++) printf("%c",196); printf("%c",194);
		for(i=0;i<14;i++) printf("%c",196); printf("%c",194);
		for(i=0;i<12;i++) printf("%c",196); printf("%c",194);
		for(i=0;i<12;i++) printf("%c",196); printf("%c",194);
		for(i=0;i<12;i++) printf("%c",196); printf("%c",194);
		for(i=0;i<8;i++) printf("%c",196);	printf("%c",191);
		gotoxy(5,5);
		printf("%c STT %c MA SINH VIEN %c     HO     %c    TEN     %c   MA LOP   %c  PHAI  %c",179,179,179,179,179,179,179);
		for(i=0;i<7;i++)
		{
			gotoxy(5,6+2*i); printf("%c",195);
			for(j=0;j<5;j++) printf("%c",196); printf("%c",197);
			for(j=0;j<14;j++) printf("%c",196); printf("%c",197);
			for(j=0;j<12;j++) printf("%c",196); printf("%c",197);
			for(j=0;j<12;j++) printf("%c",196); printf("%c",197);
			for(j=0;j<12;j++) printf("%c",196); printf("%c",197);
			for(j=0;j<8;j++) printf("%c",196);  printf("%c",180);
			gotoxy(5,7+2*i);
			printf("%c     %c              %c            %c            %c            %c        %c",179,179,179,179,179,179,179);
		}
		gotoxy(5,20); printf("%c",192);
		for(i=0;i<5;i++) printf("%c",196); printf("%c",193);
		for(i=0;i<14;i++) printf("%c",196); printf("%c",193);
		for(i=0;i<12;i++) printf("%c",196); printf("%c",193);
		for(i=0;i<12;i++) printf("%c",196); printf("%c",193);
		for(i=0;i<12;i++) printf("%c",196); printf("%c",193);
		for(i=0;i<8;i++) printf("%c",196);  printf("%c",217);
		for(i=0;i<7;i++)
		{
			gotoxy(6,7+2*i);
			printf("  %-2d ",stt+1);
			gotoxy(12,7+2*i);
			printf("     %-9d",a[stt].masv);
			gotoxy(27,7+2*i);
			printf("  %-10s",a[stt].ho);
			gotoxy(40,7+2*i);
			printf("  %-10s",a[stt].ten);
			gotoxy(53,7+2*i);
			printf("  %-10s",a[stt].ml);
			gotoxy(66,7+2*i);
			printf("   %-5s",a[stt].phai);
			stt++;
			if(stt>=dem)
			break;
		}
		mau(5,15);
		gotoxy(35,21);
		printf("Trang: %d / %d",trang,tongtrang);
next3:
		tam=getch();
		if(tam==27) return;
		if(tam!=75&&tam!=77) goto next3;
		if(tam==77)
		{
			if(stt==dem)
			goto next3;
			trang++;
			continue;
		}
		if(tam==75)
		{
			if(stt<=7) goto next3;
			if(stt==dem&&dem%7!=0)
			stt=stt-dem%7-7;
			else
			stt=stt-14;
			trang--;
			continue;
		}
	}while(1);
}
void xuatdiem(ptr_d bd,dsl l,ptr_mh mh,ptr_sv sv)
{
	ptr_sv q;
	int i,j,h=-1,m=-1,dem=0,dem1=0,dem2=0,trang=1,tongtrang,stt=0;
	char str1[20],str2[20],c2,c1,tam,ch;
	sinhvien a[5000];
	diem b[5000],c[5000];
	ptr_d p;
	nenxuat();
	mau(9,15);
	gotoxy(24,7); printf("%c",201);
	for(i=0;i<32;i++) printf("%c",205);
	printf("%c",187);
	for(i=0;i<8;i++)
	{
		gotoxy(24,8+i);
		printf("%c                                %c",186,186);
	}
	gotoxy(24,16); printf("%c",200);
	for(i=0;i<32;i++) printf("%c",205);
	printf("%c",188);
	gotoxy(34,8); printf("NHAP MA MON HOC");
	gotoxy(36,12); printf("NHAP MA LOP");
	gotoxy(53,10); printf("%c",25);
	gotoxy(53,14); printf("%c",24);
	mau(0,15);
	gotoxy(31,10);
	for(i=0;i<21;i++) printf(" ");
	gotoxy(31,14);
	for(i=0;i<21;i++) printf(" ");
b2:	gotoxy(32+h,10);
	mau(0,15);
	c2=getch();
	c1=ktkytu(c2);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27&&c1!=9)
	{
		if(c1==8&&h>-1)
		{
			h--;
			gotoxy(32+h,10);
			printf(" ");
			gotoxy(32+h,10);
		}
		else
		{
			if(c1!=8&&c1>0)
			{
				printf("%c",c1);
				str1[++h]=c1;
				str1[h]=toupper(str1[h]);
			}
		}
		str1[h+1]='\0';
		c2=getch();
		c1=ktkytu(c2);
	}
	if(c1==27) return;
	if(c1==72||c1==75||c1==77) goto b2;
	if(c1==80||c1==13||c1==9)
b3:	gotoxy(32+m,14);
	mau(0,15);
	c2=getch();
	c1=ktkytu(c2);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27&&c1!=9)
	{
		if(c1==8&&m>-1)
		{
			m--;
			gotoxy(32+m,14);
			printf(" ");
			gotoxy(32+m,14);
		}
		else
		{
			if(c1!=8&&c1>0)
			{
				printf("%c",c1);
				str2[++m]=c1;
				str2[m]=toupper(str2[m]);
			}
		}
		str2[m+1]='\0';
		c2=getch();
		c1=ktkytu(c2);
	}
	if(c1==27) return;
	if(c1==80||c1==75||c1==77||c1==9) goto b3;
	if(c1==72) goto b2;
	if(c1==13)
	{
		if(h==-1)
		{
			Warning(wn[15],5);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto b2;
		}
		if(m==-1)
		{
			Warning(wn[0],5);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto b3;
		}
		if(kiemtramamh(mh,str1)==1)
		{
			Warning(wn[26],5);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto b2;
		}
		if(kiemtramalop(l,str2)==0)
		{
			Warning(wn[11],5);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto b3;
		}
	}
	for(q=sv;q!=NULL;q=q->right)
	if(strcmp(str2,q->info.ml)==0)
	a[dem++]=q->info;
	for(p=bd;p!=NULL;p=p->next)
	if(strcmp(str1,p->infod.mmh)==0)
	b[dem1++]=p->infod;
	for(i=0;i<dem;i++)
	{
		for(j=0;j<dem1;j++)
		{
			if(b[j].msv==a[i].masv)
			{
				c[dem2++]=b[j];
			}
		}
	}
	if(dem2%7==0)tongtrang=dem2/7;
	else tongtrang=dem2/7+1;
	if(dem2<=0)
	{
		Warning(wn[33],5);
		do
		{
			ch=getch();
		}while(ch!=27&&ch!=13);
		if(ch==27) return;
		if(ch==13) goto b2;
	}
	mau(15,0);
	gotoxy(31,2);
	printf("BANG DIEM SINH VIEN");
	do
	{
		mau(5,15);
		gotoxy(15,4); printf("%c",218);
		for(i=0;i<5;i++) printf("%c",196); printf("%c",194);
		for(i=0;i<14;i++) printf("%c",196); printf("%c",194);
		for(i=0;i<12;i++) printf("%c",196); printf("%c",194);
		for(i=0;i<6;i++) printf("%c",196); printf("%c",194);
		for(i=0;i<6;i++) printf("%c",196); printf("%c",191);
		gotoxy(15,5);
		printf("%c STT %c MA SINH VIEN %c MA MON HOC %c LAN1 %c LAN2 %c",179,179,179,179,179,179);
		for(i=0;i<7;i++)
		{
			gotoxy(15,6+2*i); printf("%c",195);
			for(j=0;j<5;j++)  printf("%c",196); printf("%c",197);
			for(j=0;j<14;j++) printf("%c",196); printf("%c",197);
			for(j=0;j<12;j++) printf("%c",196); printf("%c",197);
			for(j=0;j<6;j++)  printf("%c",196); printf("%c",197);
			for(j=0;j<6;j++)  printf("%c",196); printf("%c",180);
			gotoxy(15,7+2*i);
			printf("%c     %c              %c            %c      %c      %c",179,179,179,179,179,179);
		}
		gotoxy(15,20); printf("%c",192);
		for(i=0;i<5;i++) printf("%c",196); printf("%c",193);
		for(i=0;i<14;i++) printf("%c",196); printf("%c",193);
		for(i=0;i<12;i++) printf("%c",196); printf("%c",193);
		for(i=0;i<6;i++) printf("%c",196); printf("%c",193);
		for(i=0;i<6;i++) printf("%c",196); printf("%c",217);
		for(i=0;i<7;i++)
		{
			gotoxy(16,7+2*i);
			printf("  %-2d ",stt+1);
			gotoxy(22,7+2*i);
			printf("      %-8d",c[stt].msv);
			gotoxy(37,7+2*i);
			printf("  %-10s",c[stt].mmh);
			if(c[stt].lan==1)
			gotoxy(50,7+2*i);
			else
			gotoxy(57,7+2*i);
			printf("  %-4d",c[stt].diem);
			stt++;
			if(stt>=dem2)
			break;
		}
		mau(5,15);
		gotoxy(35,21);
		printf("Trang: %d / %d",trang,tongtrang);
next4:
		tam=getch();
		if(tam==27) return;
		if(tam!=75&&tam!=77) goto next4;
		if(tam==77)
		{
			if(stt==dem2)
			goto next4;
			trang++;
			continue;
		}
		if(tam==75)
		{
			if(stt<=7) goto next4;
			if(stt==dem2&&dem2%7!=0)
			stt=stt-dem2%7-7;
			else
			stt=stt-14;
			trang--;
			continue;
		}
	}while(1);
}
void xuatdsthi(ptr_sv sv,dsl l,ptr_mh mh)
{
	ptr_sv p;
	sinhvien a[5000];
	char c1,c2,str1[25],str2[25],tam,ch;
	int m=-1,h=-1,stt=0,trang=1,tongtrang,dem=0,i,j;
	system("cls");
	nenxuat();
	mau(15,0);
	gotoxy(33,2);
	printf("DANH SACH THI");
	mau(9,15);
	gotoxy(24,7); printf("%c",201);
	for(i=0;i<32;i++) printf("%c",205);
	printf("%c",187);
	for(i=0;i<8;i++)
	{
		gotoxy(24,8+i);
		printf("%c                                %c",186,186);
	}
	gotoxy(24,16); printf("%c",200);
	for(i=0;i<32;i++) printf("%c",205);
	printf("%c",188);
	gotoxy(34,8); printf("NHAP MA MON HOC");
	gotoxy(36,12); printf("NHAP MA LOP");
	gotoxy(53,10); printf("%c",25);
	gotoxy(53,14); printf("%c",24);
	mau(0,15);
	gotoxy(31,10);
	for(i=0;i<21;i++) printf(" ");
	gotoxy(31,14);
	for(i=0;i<21;i++) printf(" ");
b4:	gotoxy(32+h,10);
	mau(0,15);
	c2=getch();
	c1=ktkytu(c2);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
	{
		if(c1==8&&h>-1)
		{
			h--;
			gotoxy(32+h,10);
			printf(" ");
			gotoxy(32+h,10);
		}
		else
		{
			if(c1!=8&&c1>0)
			{
				printf("%c",c1);
				str1[++h]=c1;
				str1[h]=toupper(str1[h]);
			}
		}
		str1[h+1]='\0';
		c2=getch();
		c1=ktkytu(c2);
	}
	if(c1==27) return;
	if(c1==72||c1==75||c1==77) goto b4;
	if(c1==80||c1==13)
b5:	gotoxy(32+m,14);
	mau(0,15);
	c2=getch();
	c1=ktkytu(c2);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
	{
		if(c1==8&&m>-1)
		{
			m--;
			gotoxy(32+m,14);
			printf(" ");
			gotoxy(32+m,14);
		}
		else
		{
			if(c1!=8&&c1>0)
			{
				printf("%c",c1);
				str2[++m]=c1;
				str2[m]=toupper(str2[m]);
			}
		}
		str2[m+1]='\0';
		c2=getch();
		c1=ktkytu(c2);
	}
	if(c1==27) return;
	if(c1==80||c1==75||c1==77) goto b5;
	if(c1==72) goto b4;
	if(c1==13)
	{
		if(h==-1)
		{
			Warning(wn[15],5);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto b4;
		}
		if(m==-1)
		{
			Warning(wn[0],5);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto b5;
		}
		if(kiemtramamh(mh,str1)==1)
		{
			Warning(wn[26],5);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto b4;
		}
		if(kiemtramalop(l,str2)==0)
		{
			Warning(wn[11],5);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto b5;
		}
	}
	for(p=sv;p!=NULL;p=p->right)
	if(strcmp(p->info.ml,str2)==0)
	a[dem++]=p->info;
	if(dem%7==0) tongtrang=dem/7;
	else tongtrang=dem/7+1;
	if(dem<=0)
	{
		Warning(wn[32],5);
		do
		{
			ch=getch();
		}while(ch!=27&&ch!=13);
		if(ch==27) return;
		if(ch==13) goto b4;
	}
	mau(15,0);
	gotoxy(31,2);
	printf("DANH SACH THI/MMH: %s",str1);
	do
	{
		mau(5,15);
		gotoxy(6,4); printf("%c",218);
		for(i=0;i<5;i++) printf("%c",196); printf("%c",194);
		for(i=0;i<14;i++) printf("%c",196); printf("%c",194);
		for(i=0;i<21;i++) printf("%c",196); printf("%c",194);
		for(i=0;i<12;i++) printf("%c",196); printf("%c",194);
		for(i=0;i<10;i++) printf("%c",196); printf("%c",191);
		gotoxy(6,5);
		printf("%c STT %c MA SINH VIEN %c      HO VA TEN      %c   MA LOP   %c  KY TEN  %c",179,179,179,179,179,179);
		for(i=0;i<7;i++)
		{
			gotoxy(6,6+2*i); printf("%c",195);
			for(j=0;j<5;j++) printf("%c",196); printf("%c",197);
			for(j=0;j<14;j++) printf("%c",196); printf("%c",197);
			for(j=0;j<21;j++) printf("%c",196); printf("%c",197);
			for(j=0;j<12;j++) printf("%c",196); printf("%c",197);
			for(j=0;j<10;j++) printf("%c",196); printf("%c",180);
			gotoxy(6,7+2*i);
			printf("%c     %c              %c                     %c            %c          %c",179,179,179,179,179,179);
		}
		gotoxy(6,20); printf("%c",192);
		for(i=0;i<5;i++) printf("%c",196); printf("%c",193);
		for(i=0;i<14;i++) printf("%c",196); printf("%c",193);
		for(i=0;i<21;i++) printf("%c",196); printf("%c",193);
		for(i=0;i<12;i++) printf("%c",196); printf("%c",193);
		for(i=0;i<10;i++) printf("%c",196); printf("%c",217);
		for(i=0;i<7;i++)
		{
			gotoxy(7,7+2*i);
			printf("  %-2d ",stt+1);
			gotoxy(13,7+2*i);
			printf("      %-8d",a[stt].masv);
			gotoxy(28,7+2*i);
			printf("  %s %s",a[stt].ho,a[stt].ten);
			gotoxy(50,7+2*i);
			printf("  %-10s",str2);
			stt++;
			if(stt>=dem)
			break;
		}
		mau(5,15);
		gotoxy(35,21);
		printf("Trang: %d / %d",trang,tongtrang);
next5:
		tam=getch();
		if(tam==27) return;
		if(tam!=77&&tam!=75) goto next5;
		if(tam==77)
		{
			if(stt==dem)
			goto next5;
			trang++;
			continue;
		}
		if(tam==75)
		{
			if(stt<=7) goto next5;
			if(stt==dem&&dem%7!=0)
			stt=stt-dem%7-7;
			else
			stt=stt-14;
			trang--;
			continue;
		}
	}while(1);
}
void save_lop(dsl l)
{
	char s;
	int i;
	FILE *f1;
	mau(2,15);
	system("cls");
	gotoxy(1,23);
	printf("ESC: Thoat");
	f1=fopen("dslop.txt","w");
	if(f1==NULL)
	{
		Warning(wn[35],2);
		do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
	}
	if(l.n==0)
	{
		Warning(wn[36],2);
		do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
	}
	for(i=0;i<l.n;i++)
	fwrite(&l.nodes[i],sizeof(lop),1,f1);
	fclose(f1);
	mau(2,15);
	system("cls");
	gotoxy(1,23);
	printf("ESC: Thoat");
	mau(4,15);
	gotoxy(15,9);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,10);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,11);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,12);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,13);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,14);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,15);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(26,12);
	printf("SAVE FILE LOP THANH CONG !!!");
	do{
		s=getch();
	}while(s!=27);
	if(s==27) return;
}
void load_lop(dsl &l)
{
	int i;
	char s;
	FILE *f2;
	mau(2,15);
	system("cls");
	gotoxy(1,23);
	printf("ESC: Thoat");
	f2=fopen("dslop.txt","r");
	if(f2==NULL)
	{
		Warning(wn[37],2);
		do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
	}
	l.n=0;
	while(fread(&l.nodes[l.n],sizeof(lop),1,f2)==1)
	{
		l.n++;
	}
	fclose(f2);
	if(l.n==0)
	{
		Warning(wn[36],2);
		do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
	}
	mau(2,15);
	system("cls");
	gotoxy(1,23);
	printf("ESC: Thoat");
	mau(4,15);
	gotoxy(15,9);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,10);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,11);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,12);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,13);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,14);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,15);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(26,12);
	printf("LOAD FILE LOP THANH CONG !!!");
	do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
}
void save_mh(ptr_mh mh)
{
	ptr_mh p;
	int i;
	char s;
	FILE *f3;
	mau(2,15);
	system("cls");
	gotoxy(1,23);
	printf("ESC: Thoat");
	f3=fopen("dsmh.txt","w");
	if(f3==NULL)
	{
		Warning(wn[35],2);
		do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
	}
	if(mh==NULL)
	{
		Warning(wn[36],2);
		do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
	}
	for(p=mh;p!=NULL;p=p->next)
	fwrite(&p->infomh,sizeof(monhoc),1,f3);
	fclose(f3);
	mau(2,15);
	system("cls");
	gotoxy(1,23);
	printf("ESC: Thoat");
	mau(4,15);
	gotoxy(15,9);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,10);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,11);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,12);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,13);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,14);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,15);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(24,12);
	printf("SAVE FILE MON HOC THANH CONG !!!");
	do{
		s=getch();
	}while(s!=27);
	if(s==27) return;
}
void load_mh(ptr_mh &mh)
{
	ptr_mh p;
	int i;
	char s;
	FILE *f4;
	mau(2,15);
	system("cls");
	gotoxy(1,23);
	printf("ESC: Thoat");
	f4=fopen("dsmh.txt","r");
	if(f4==NULL)
	{
		Warning(wn[37],2);
		do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
	}
	p=new dsmh;
	while(fread(&p->infomh,sizeof(monhoc),1,f4)==1)
	{
		insert_mh(mh,p);
		p=new dsmh;
	}
	fclose(f4);
	if(mh==NULL)
	{
		Warning(wn[36],2);
		do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
	}
	mau(2,15);
	system("cls");
	gotoxy(1,23);
	printf("ESC: Thoat");
	mau(4,15);
	gotoxy(15,9);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,10);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,11);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,12);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,13);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,14);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,15);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(24,12);
	printf("LOAD FILE MON HOC THANH CONG !!!");
	do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
}
void save_sv(ptr_sv sv)
{
	ptr_sv p;
	int i;
	char s;
	FILE *f5;
	mau(2,15);
	system("cls");
	gotoxy(1,23);
	printf("ESC: Thoat");
	f5=fopen("dssv.txt","w");
	if(f5==NULL)
	{
		Warning(wn[35],2);
		do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
	}
	if(sv==NULL)
	{
		Warning(wn[36],2);
		do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
	}
	for(p=sv;p!=NULL;p=p->right)
	fwrite(&p->info,sizeof(sinhvien),1,f5);
	fclose(f5);
	mau(2,15);
	system("cls");
	gotoxy(1,23);
	printf("ESC: Thoat");
	mau(4,15);
	gotoxy(15,9);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,10);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,11);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,12);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,13);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,14);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,15);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(23,12);
	printf("SAVE FILE SINH VIEN THANH CONG !!!");
	do{
		s=getch();
	}while(s!=27);
	if(s==27) return;
}
void load_sv(ptr_sv &sv)
{
	ptr_sv p;
	int i;
	char s;
	FILE *f6;
	mau(2,15);
	system("cls");
	gotoxy(1,23);
	printf("ESC: Thoat");
	f6=fopen("dssv.txt","r");
	if(f6==NULL)
	{
		Warning(wn[37],2);
		do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
	}
	p=new dssv;
	while(fread(&p->info,sizeof(sinhvien),1,f6)==1)
	{
		insert_right(sv,p);
		p=new dssv;
	}
	fclose(f6);
	if(sv==NULL)
	{
		Warning(wn[36],2);
		do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
	}
	mau(2,15);
	system("cls");
	gotoxy(1,23);
	printf("ESC: Thoat");
	mau(4,15);
	gotoxy(15,9);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,10);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,11);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,12);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,13);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,14);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,15);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(23,12);
	printf("LOAD FILE SINH VIEN THANH CONG !!!");
	do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
}
void save_diem(ptr_d bd)
{
	ptr_d p;
	int i;
	char s;
	FILE *f7;
	mau(2,15);
	system("cls");
	gotoxy(1,23);
	printf("ESC: Thoat");
	f7=fopen("dsd.txt","w");
	if(f7==NULL)
	{
		Warning(wn[35],2);
		do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
	}
	if(bd==NULL)
	{
		Warning(wn[36],2);
		do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
	}
	for(p=bd;p!=NULL;p=p->next)
	fwrite(&p->infod,sizeof(diem),1,f7);
	fclose(f7);
	mau(2,15);
	system("cls");
	gotoxy(1,23);
	printf("ESC: Thoat");
	mau(4,15);
	gotoxy(15,9);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,10);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,11);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,12);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,13);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,14);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,15);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(23,12);
	printf("SAVE FILE BANG DIEM THANH CONG !!!");
	do{
		s=getch();
	}while(s!=27);
	if(s==27) return;
}
void load_diem(ptr_d &bd)
{
	ptr_d p;
	int i;
	char s;
	FILE *f8;
	mau(2,15);
	system("cls");
	gotoxy(1,23);
	printf("ESC: Thoat");
	f8=fopen("dsd.txt","r");
	if(f8==NULL)
	{
		Warning(wn[37],2);
		do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
	}
	p=new dsd;
	while(fread(&p->infod,sizeof(diem),1,f8)==1)
	{
		insert_diem(bd,p);
		p=new dsd;
	}
	fclose(f8);
	if(bd==NULL)
	{
		Warning(wn[36],2);
		do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
	}
	mau(2,15);
	system("cls");
	gotoxy(1,23);
	printf("ESC: Thoat");
	mau(4,15);
	gotoxy(15,9);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,10);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,11);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,12);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,13);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,14);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(15,15);
	for(i=0;i<50;i++) printf(" ");
	gotoxy(23,12);
	printf("LOAD FILE BANG DIEM THANH CONG !!!");
	do
		{
			s=getch();
		}while(s!=27);
		if(s==27) return;
}
void khung()
{
	int i;
	mau(9,15);
	gotoxy(30,9); printf("%c",201);
	for(i=0;i<22;i++) printf("%c",205);
	printf("%c",187);
	for(i=0;i<5;i++)
	{
		gotoxy(30,10+i);
		printf("%c                      %c",186,186);
	}
	gotoxy(30,15); printf("%c",200);
	for(i=0;i<22;i++) printf("%c",205);
	printf("%c",188);

	mau(0,15);
	gotoxy(33,12);
	for(i=0;i<18;i++) printf(" ");
	gotoxy(33,13);
	for(i=0;i<18;i++) printf(" ");
}
void timlop(dsl l)
{
	int i,m=-1,stt=1;
	char str[20],c,c1,ch;
	nentim();
	mau(15,0);
	gotoxy(32,2);
	printf("CHUC NANG TIM LOP");
	khung();
	mau(9,15);
	gotoxy(37,10); printf("NHAP MA LOP");
t1:	gotoxy(34+m,13);
	mau(0,15);
	c=getch();
	c1=ktkytu(c);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
	{
		if(c1==8&&m>-1)
		{
			m--;
			gotoxy(34+m,13);
			printf(" ");
			gotoxy(34+m,13);
		}
		else
		{
			if(c1!=8&&c1>0)
			{
				printf("%c",c1);
				str[++m]=c1;
				str[m]=toupper(str[m]);
			}
		}
		str[m+1]='\0';
		c=getch();
		c1=ktkytu(c);
	}
	if(c1==27) return;
	if(c1==72||c1==75||c1==77||c1==80) goto t1;
	if(c1==13)
	{
		if(m==-1)
		{
			Warning(wn[0],4);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto t1;
		}
		if(kiemtramalop(l,str)==0)
		{
			Warning(wn[11],4);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto t1;
		}
	}
	nentim();
	mau(15,0);
	gotoxy(34,2);
	printf("THONG TIN LOP");
	mau(4,15);
	gotoxy(12,10); printf("%c",218);
	for(i=0;i<5;i++) printf("%c",196); printf("%c",194);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",194);
	for(i=0;i<34;i++) printf("%c",196); printf("%c",191);
	gotoxy(12,11);
	printf("%c STT %c   MA LOP   %c             TEN LOP              %c",179,179,179,179);
	gotoxy(12,12); printf("%c",195);
	for(i=0;i<5;i++) printf("%c",196); printf("%c",197);
	for(i=0;i<12;i++) printf("%c",196);	printf("%c",197);
	for(i=0;i<34;i++) printf("%c",196); printf("%c",180);
	gotoxy(12,13);
	printf("%c     %c            %c                                  %c",179,179,179,179);
	gotoxy(12,14); printf("%c",192);
	for(i=0;i<5;i++) printf("%c",196); printf("%c",193);
	for(i=0;i<12;i++) printf("%c",196);	printf("%c",193);
	for(i=0;i<34;i++) printf("%c",196); printf("%c",217);
	for(i=0;i<l.n;i++)
	if(strcmp(str,l.nodes[i].malop)==0)
	{
		gotoxy(13,13); printf("  %d  ",stt);
		gotoxy(19,13); printf("  %-10s",str);
		gotoxy(32,13); printf("          %-24s",l.nodes[i].tenlop);
	}
	do
	{
		ch=getch();
	}while(ch!=27);
	if(ch==27) return;
}
void timmh(ptr_mh mh)
{
	ptr_mh p;
	int i,m=-1,stt=1;
	char str[20],c,c1,ch;
	nentim();
	mau(15,0);
	gotoxy(30,2);
	printf("CHUC NANG TIM MON HOC");
	khung();
	mau(9,15);
	gotoxy(35,10); printf("NHAP MA MON HOC");
t2: gotoxy(34+m,13);
	mau(0,15);
	c=getch();
	c1=ktkytu(c);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
	{
		if(c1==8&&m>-1)
		{
			m--;
			gotoxy(34+m,13);
			printf(" ");
			gotoxy(34+m,13);
		}
		else
		{
			if(c1!=8&&c1>0)
			{
				printf("%c",c1);
				str[++m]=c1;
				str[m]=toupper(str[m]);
			}
		}
		str[m+1]='\0';
		c=getch();
		c1=ktkytu(c);
	}
	if(c1==27) return;
	if(c1==72||c1==75||c1==77||c1==80) goto t2;
	if(c1==13)
	{
		if(m==-1)
		{
			Warning(wn[15],4);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto t2;
		}
		if(kiemtramamh(mh,str)==1)
		{
			Warning(wn[26],4);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto t2;
		}
	}
	nentim();
	mau(15,0);
	gotoxy(30,2);
	printf("THONG TIN MON HOC");
	mau(4,15);
	gotoxy(4,10); printf("%c",218);
	for(i=0;i<5;i++) printf("%c",196); printf("%c",194);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",194);
	for(i=0;i<24;i++) printf("%c",196); printf("%c",194);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",194);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",191);
	gotoxy(4,11);
	printf("%c STT %c MA MON HOC %c       TEN MON HOC      %c SO TIET LT %c SO TIET TH %c",179,179,179,179,179,179);
	gotoxy(4,12); printf("%c",195);
	for(i=0;i<5;i++) printf("%c",196); printf("%c",197);
	for(i=0;i<12;i++) printf("%c",196);	printf("%c",197);
	for(i=0;i<24;i++) printf("%c",196); printf("%c",197);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",197);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",180);
	gotoxy(4,13);
	printf("%c     %c            %c                        %c            %c            %c",179,179,179,179,179,179);
	gotoxy(4,14); printf("%c",192);
	for(i=0;i<5;i++) printf("%c",196); printf("%c",193);
	for(i=0;i<12;i++) printf("%c",196);	printf("%c",193);
	for(i=0;i<24;i++) printf("%c",196); printf("%c",193);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",193);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",217);
	for(p=mh;p!=NULL;p=p->next)
	if(strcmp(str,p->infomh.mamh)==0)
	{
		gotoxy(5,13); printf("  %d  ",stt);
		gotoxy(11,13); printf("  %-10s",p->infomh.mamh);
		gotoxy(24,13); printf("    %-20s",p->infomh.tenmh);
		gotoxy(49,13); printf("     %-7d",p->infomh.stlt);
		gotoxy(62,13); printf("     %-7d",p->infomh.stth);
	}
	do
	{
		ch=getch();
	}while(ch!=27);
	if(ch==27) return;
}
void timsv(ptr_sv sv)
{
	ptr_sv p;
	int i,m=0,stt=1,ms[10],maso=0;
	char c,c1,ch;
	nentim();
	mau(15,0);
	gotoxy(29,2);
	printf("CHUC NANG TIM SINH VIEN");
	khung();
	mau(9,15);
	gotoxy(34,10); printf("NHAP MA SINH VIEN");
t3: gotoxy(33+m,13);
	mau(0,15);
	c=getch();
	c1=ktkytu(c);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
	{
		if(c1==8&&m>0)
		{
			m--;
			gotoxy(33+m,13);
			printf(" ");
			gotoxy(33+m,13);
		}
		else
		{
			if(c1>='0'&&c1<='9')
			{
				printf("%c",c1);
				ms[++m]=c1-'0';
			}
		}
		c=getch();
		c1=ktkytu(c);
	}
	if(c1==27) return;
	if(c1==72||c1==75||c1==77||c1==80) goto t3;
	if(c1==13)
	{
		if(m==0)
		{
			Warning(wn[6],4);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto t3;
		}
		for(i=m;i>0;i--)
		maso += ms[i]*tinhmaso(i,m);
		if(kiemtramasv(sv,maso)==0)
		{
			Warning(wn[27],4);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto t3;
		}
	}
	nentim();
	mau(15,0);
	gotoxy(29,2);
	printf("THONG TIN SINH VIEN");
	mau(4,15);
	gotoxy(6,10); printf("%c",218);
	for(i=0;i<5;i++) printf("%c",196); printf("%c",194);
	for(i=0;i<14;i++) printf("%c",196); printf("%c",194);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",194);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",194);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",194);
	for(i=0;i<8;i++) printf("%c",196); printf("%c",191);
	gotoxy(6,11);
	printf("%c STT %c MA SINH VIEN %c     HO     %c    TEN     %c   MA LOP   %c  PHAI  %c",179,179,179,179,179,179,179);
	gotoxy(6,12); printf("%c",195);
	for(i=0;i<5;i++) printf("%c",196); printf("%c",197);
	for(i=0;i<14;i++) printf("%c",196);	printf("%c",197);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",197);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",197);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",197);
	for(i=0;i<8;i++) printf("%c",196); printf("%c",180);
	gotoxy(6,13);
	printf("%c     %c              %c            %c            %c            %c        %c",179,179,179,179,179,179,179);
	gotoxy(6,14); printf("%c",192);
	for(i=0;i<5;i++) printf("%c",196); printf("%c",193);
	for(i=0;i<14;i++) printf("%c",196);	printf("%c",193);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",193);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",193);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",193);
	for(i=0;i<8;i++) printf("%c",196); printf("%c",217);
	for(p=sv;p!=NULL;p=p->right)
	if(p->info.masv==maso)
	{
		gotoxy(7,13); printf("  %d  ",stt);
		gotoxy(13,13); printf("      %-8d",maso);
		gotoxy(28,13); printf("    %-8s",p->info.ho);
		gotoxy(41,13); printf("    %-8s",p->info.ten);
		gotoxy(54,13); printf("   %-9s",p->info.ml);
		gotoxy(67,13); printf("   %-5s",p->info.phai);
	}
	do
	{
		ch=getch();
	}while(ch!=27);
	if(ch==27) return;
}
void timdiem(ptr_d bd,ptr_sv sv)
{
	ptr_d p;
	int i,j,m=0,stt=1,ms[10],maso=0;
	char c,c1,ch;
	system("cls");
	nentim();
	mau(15,0);
	gotoxy(27,2);
	printf("CHUC NANG TIM DIEM SINH VIEN");
	khung();
	mau(9,15);
	gotoxy(34,10); printf("NHAP MA SINH VIEN");
t5: gotoxy(33+m,13);
	mau(0,15);
	c=getch();
	c1=ktkytu(c);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
	{
		if(c1==8&&m>0)
		{
			m--;
			gotoxy(33+m,13);
			printf(" ");
			gotoxy(33+m,13);
		}
		else
		{
			if(c1>='0'&&c1<='9')
			{
				printf("%c",c1);
				ms[++m]=c1-'0';
			}
		}
		c=getch();
		c1=ktkytu(c);
	}
	if(c1==27) return;
	if(c1==80||c1==75||c1==77||c1==72) goto t5;
	if(c1==13)
	{
		if(m==0)
		{
			Warning(wn[6],4);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto t5;
		}
		for(i=m;i>0;i--)
		maso += ms[i]*tinhmaso(i,m);
		if(kiemtramasv(sv,maso)==0)
		{
			Warning(wn[27],4);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto t5;
		}
		if(kiemtrabd(bd,maso)==0)
		{
			Warning(wn[33],4);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto t5;
		}
	}
	nentim();
	mau(15,0);
	gotoxy(31,2);
	printf("DIEM SINH VIEN");
	mau(4,15);
	ptr_sv q=sv;
	gotoxy(22,5);
	for(q=sv;q!=NULL;q=q->right)
	if(maso==q->info.masv)
	{
		printf ("Sinh vien: %s %s",q->info.ho,q->info.ten);
		printf(" - Ma SV: %d",q->info.masv);
	}
	gotoxy(22,7); printf("%c",218);
	for(i=0;i<5;i++) printf("%c",196); printf("%c",194);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",194);
	for(i=0;i<6;i++) printf("%c",196); printf("%c",194);
	for(i=0;i<6;i++) printf("%c",196); printf("%c",191);
	gotoxy(22,8);
	printf("%c STT %c MA MON HOC %c LAN1 %c LAN2 %c",179,179,179,179,179,179);
	j=0;
	for(p=bd;p!=NULL;p=p->next)
	if(p->infod.msv==maso)
	{
		gotoxy(22,9+2*j); printf("%c",195);
		for(i=0;i<5;i++) printf("%c",196); printf("%c",197);
		for(i=0;i<12;i++) printf("%c",196); printf("%c",197);
		for(i=0;i<6;i++) printf("%c",196); printf("%c",197);
		for(i=0;i<6;i++) printf("%c",196); printf("%c",180);

		gotoxy(22,10+2*j); printf("%c  %d  %c",179,stt,179);
		gotoxy(29,10+2*j); printf("   %-9s%c",p->infod.mmh,179);
		if(p->infod.lan==1)
		{
			gotoxy(42,10+2*j);
			printf("  %-4d%c      %c",p->infod.diem,179,179);
		}
		else
		{
			gotoxy(48,10+2*j);
			printf("%c  %-4d%c",179,p->infod.diem,179);
		}
		stt++;
		j++;
	}
	gotoxy(22,10+j); printf("%c",192);
	for(i=0;i<5;i++) printf("%c",196); printf("%c",193);
	for(i=0;i<12;i++) printf("%c",196); printf("%c",193);
	for(i=0;i<6;i++) printf("%c",196); printf("%c",193);
	for(i=0;i<6;i++) printf("%c",196); printf("%c",217);
	do
	{
		ch=getch();
	}while(ch!=27);
}
void sualop(dsl &l,ptr_sv &sv)
{
	int i,m=-1,ml=-1,tl=-1;
	char str[20],c,c1,ch;
	lop tam;
	nennhap();
	mau(15,0);
	gotoxy(27,2);
	printf("CHUC NANG SUA THONG TIN LOP");
	khung();
	mau(9,15);
	gotoxy(37,10); printf("NHAP MA LOP");
s1:	gotoxy(34+m,13);
	mau(0,15);
	c=getch();
	c1=ktkytu(c);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
	{
		if(c1==8&&m>-1)
		{
			m--;
			gotoxy(34+m,13);
			printf(" ");
			gotoxy(34+m,13);
		}
		else
		{
			if(c1!=8&&c1>0)
			{
				printf("%c",c1);
				str[++m]=c1;
				str[m]=toupper(str[m]);
			}
		}
		str[m+1]='\0';
		c=getch();
		c1=ktkytu(c);
	}
	if(c1==27) return;
	if(c1==72||c1==75||c1==77||c1==80) goto s1;
	if(c1==13)
	{
		if(m==-1)
		{
			Warning(wn[0],2);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto s1;
		}
		if(kiemtramalop(l,str)==0)
		{
			Warning(wn[11],2);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto s1;
		}
	}
	nennhap();
	mau(15,0);
	gotoxy(27,2);
	printf("CHUC NANG SUA THONG TIN LOP");
	mau(2,15);
	gotoxy(25,10); printf("Sua");
	gotoxy(25,16); printf("Sua");
	mau(0,15);
	gotoxy(30,10);
	for(i=0;i<20;i++) printf(" ");
	gotoxy(30,16);
	for(i=0;i<20;i++) printf(" ");
	for(int i=0;i<l.n;i++)
	if(strcmp(l.nodes[i].malop,str)==0)
	{
		mau(2,10);
		gotoxy(20,8); printf("Ma lop: "); puts(l.nodes[i].malop);
		gotoxy(20,14); printf("Ten lop: ");  puts(l.nodes[i].tenlop);
s2:		gotoxy(31+ml,10);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=13&&c1!=27&&c1!=75&&c1!=72&&c1!=77&&c1!=80)
		{
			if(c1==8&&ml>-1)
			{
				ml--;
				gotoxy(31+ml,10); printf(" ");
				gotoxy(31+ml,10);
			}
			else
			{
				if(c1>='0'&&c1<='9'||c1>='A'&&c1<='Z'||c1>='a'&&c1<='z')
					{
						printf("%c",c1);
						tam.malop[++ml]=c1;
						tam.malop[ml]=toupper(tam.malop[ml]);
					}
			}
			tam.malop[ml+1]='\0';
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==72||c1==77||c1==75) goto s2;
		if(c1==80||c1==13)
s3:		gotoxy(31+tl,16);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=13&&c1!=27&&c1!=75&&c1!=72&&c1!=77&&c1!=80)
		{
			if(c1==8&&tl>-1)
			{
				tl--;
				gotoxy(31+tl,16); printf(" ");
				gotoxy(31+tl,16);
			}
			else
			{
				if(c1>='0'&&c1<='9'||c1>='A'&&c1<='Z'||c1>='a'&&c1<='z')
					{
						printf("%c",c1);
						tam.tenlop[++tl]=c1;
						tam.tenlop[tl]=toupper(tam.tenlop[tl]);
					}
			}
			tam.tenlop[tl+1]='\0';
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==80||c1==77||c1==75) goto s3;
		if(c1==72) goto s2;
		if(c1==13)
		{
			if(ml==-1)
				{
					Warning(wn[0],2);
					do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s2;
				}
				if(tl==-1)
				{
					Warning(wn[1],2);
					do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s3;
				}
				if(ml>9)
				{
					Warning(wn[2],2);
					do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s2;
				}
				if(tl>19)
				{
					Warning(wn[3],2);
					do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s3;
				}
				if(strcmp(tam.malop,l.nodes[i].malop)!=0&&kiemtramalop(l,tam.malop)==1)
				{
					Warning(wn[4],2);
					do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s2;
				}
				ptr_sv q=sv;
				for(q=sv;q!=NULL;q=q->right)
				if(strcmp(q->info.ml,l.nodes[i].malop)==0)
				{
					strcpy(q->info.ml,tam.malop);
				}
				l.nodes[i] = tam;

		}
	}
	Warning(wn[39],2);
	do
	{
		ch=getch();
	}while(ch!=27);
}
void suamh(ptr_mh &mh,ptr_d &bd)
{
	int i,m=-1,mmh=-1,tmh=-1,lt=0,th=0,stt=1,tlt[10],tth[10];
	char str[20],c,c1,ch;
	ptr_mh p=mh;
	monhoc tam;
	nennhap();
	mau(15,0);
	gotoxy(25,2);
	printf("CHUC NANG SUA THONG TIN MON HOC");
	khung();
	mau(9,15);
	gotoxy(35,10); printf("NHAP MA MON HOC");
s4: gotoxy(34+m,13);
	mau(0,15);
	c=getch();
	c1=ktkytu(c);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
	{
		if(c1==8&&m>-1)
		{
			m--;
			gotoxy(34+m,13);
			printf(" ");
			gotoxy(34+m,13);
		}
		else
		{
			if(c1!=8&&c1>0)
			{
				printf("%c",c1);
				str[++m]=c1;
				str[m]=toupper(str[m]);
			}
		}
		str[m+1]='\0';
		c=getch();
		c1=ktkytu(c);
	}
	if(c1==27) return;
	if(c1==72||c1==75||c1==77||c1==80) goto s4;
	if(c1==13)
	{
		if(m==-1)
		{
			Warning(wn[15],2);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto s4;
		}
		if(kiemtramamh(mh,str)==1)
		{
			Warning(wn[26],2);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto s4;
		}
	}
	nennhap();
	mau(15,0);
	gotoxy(25,2);
	printf("CHUC NANG SUA THONG TIN MON HOC");
	mau(2,15);
	gotoxy(25,10); printf("Sua"); gotoxy(25,14); printf("Sua");
	gotoxy(20,18); printf("Sua"); gotoxy(45,18); printf("Sua");
	mau(0,15);
	gotoxy(30,10); for(i=0;i<20;i++) printf(" ");
	gotoxy(30,14); for(i=0;i<30;i++) printf(" ");
	gotoxy(25,18); for(i=0;i<8;i++) printf(" ");
	gotoxy(50,18); for(i=0;i<8;i++) printf(" ");
	for(p=mh;p!=NULL;p=p->next)
	if(strcmp(str,p->infomh.mamh)==0)
	{
		mau(2,10);
		gotoxy(20,8); printf("Ma mon hoc: "); puts(p->infomh.mamh);
		gotoxy(20,12); printf("Ten mon hoc: "); puts(p->infomh.tenmh);
		gotoxy(25,16); printf("STLT: %d",p->infomh.stlt);
		gotoxy(50,16); printf("STTH: %d",p->infomh.stth);
s5:		gotoxy(31+mmh,10);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
		{
			if(c1==8&&mmh>-1)
			{
				mmh--;
				gotoxy(31+mmh,10); printf(" ");
				gotoxy(31+mmh,10);
			}
			else
			{
				if(c1>='0'&&c1<='9'||c1>='A'&&c1<='Z'||c1>='a'&&c1<='z')
				{
					printf("%c",c1);
					tam.mamh[++mmh]=c1;
					tam.mamh[mmh]=toupper(tam.mamh[mmh]);
				}
			}
			tam.mamh[mmh+1]='\0';
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==72||c1==75||c1==77) goto s5;
		if(c1==80||c1==13)
s6:		gotoxy(31+tmh,14);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
		{
			if(c1==8&&tmh>-1)
			{
				tmh--;
				gotoxy(31+tmh,14); printf(" ");
				gotoxy(31+tmh,14);
			}
			else
			{
				if(c1==' '||c1>='A'&&c1<='Z'||c1>='a'&&c1<='z')
				{
					printf("%c",c1);
					tam.tenmh[++tmh]=c1;
				}
			}
			tam.tenmh[tmh+1]='\0';
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==75||c1==77) goto s6;
		if(c1==72) goto s5;
		if(c1==80||c1==13)
s7:     gotoxy(25+lt,18);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
		{
			if(c1==8&&lt>0)
			{
				lt--;
				gotoxy(25+lt,18); printf(" ");
				gotoxy(25+lt,18);
			}
			else
			{
				if(c1>='0'&&c1<='9')
				{
					printf("%c",c1);
					tlt[++lt]=c1-'0';
				}
			}
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==75||c1==80) goto s7;
		if(c1==72) goto s6;
		if(c1==13||c1==77)
s8: 	gotoxy(50+th,18);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
		{
			if(c1==8&&th>0)
			{
				th--;
				gotoxy(50+th,18); printf(" ");
				gotoxy(50+th,18);
			}
			else
			{
				if(c1>='0'&&c1<='9')
				{
					printf("%c",c1);
					tth[++th]=c1-'0';
				}
			}
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==75) goto s7;
		if(c1==72) goto s6;
		if(c1==80||c1==77) goto s8;
		if(c1==13)
		{
			if(mmh==-1)
			{
				Warning(wn[15],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s5;
			}
			if(tmh==-1)
			{
				Warning(wn[16],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s6;
			}
			if(lt==0)
			{
				Warning(wn[17],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s7;
			}
			if(th==0)
			{
				Warning(wn[18],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s8;
			}
			if(mmh>9)
			{
				Warning(wn[19],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s5;
			}
			if(tmh>29)
			{
				Warning(wn[20],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s6;
			}
			tam.stlt=0;
			for(int j=lt;j>0;j--)
			tam.stlt += tlt[j]*tinhmaso(j,lt);
			tam.stth=0;
			for(int j=th;j>0;j--)
			tam.stth += tth[j]*tinhmaso(j,th);
			if(strcmp(tam.mamh,p->infomh.mamh)!=0&&kiemtramamh(mh,tam.mamh)==0)
			{
				Warning(wn[21],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s5;
			}
			if((tam.stlt)>200||(tam.stlt)%15!=0)
			{
				Warning(wn[22],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s7;
			}
			if((tam.stth)>200||(tam.stth)%15!=0)
			{
				Warning(wn[23],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s8;
			}
			format_chuoi(tam.tenmh);
			chu_in(tam.tenmh);
			ptr_d q=bd;
			for(q=bd;q!=NULL;q=q->next)
			if(strcmp(q->infod.mmh,p->infomh.mamh)==0)
			{
				strcpy(q->infod.mmh,tam.mamh);
			}
			p->infomh=tam;
		}
	}
	Warning(wn[39],2);
	do
	{
		ch=getch();
	}while(ch!=27);
}
void suasv(ptr_sv &sv,dsl l,ptr_d &bd)
{
	int i,m=0,ms[10],mso[10],maso=0,msv=0,h=-1,t=-1,p=-1,ml=-1;
	char c,c1,ch;
	sinhvien tam;
	ptr_sv q=sv;
	nennhap();
	mau(15,0);
	gotoxy(24,2);
	printf("CHUC NANG SUA THONG TIN SINH VIEN");
	khung();
	mau(9,15);
	gotoxy(34,10); printf("NHAP MA SINH VIEN");
s9: gotoxy(33+m,13);
	mau(0,15);
	c=getch();
	c1=ktkytu(c);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
	{
		if(c1==8&&m>0)
		{
			m--;
			gotoxy(33+m,13);
			printf(" ");
			gotoxy(33+m,13);
		}
		else
		{
			if(c1>='0'&&c1<='9')
			{
				printf("%c",c1);
				ms[++m]=c1-'0';
			}
		}
		c=getch();
		c1=ktkytu(c);
	}
	if(c1==27) return;
	if(c1==72||c1==75||c1==77||c1==80) goto s9;
	if(c1==13)
	{
		if(m==0)
		{
			Warning(wn[6],2);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto s9;
		}
		for(i=m;i>0;i--)
		maso += ms[i]*tinhmaso(i,m);
		if(kiemtramasv(sv,maso)==0)
		{
			Warning(wn[27],2);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto s9;
		}
	}
	nennhap();
	mau(15,0);
	gotoxy(24,2);
	printf("CHUC NANG SUA THONG TIN SINH VIEN");
	mau(2,15); gotoxy(27,10); printf("Sua");
	gotoxy(10,14); printf("Sua"); gotoxy(40,14); printf("Sua");
	gotoxy(10,18); printf("Sua"); gotoxy(40,18); printf("Sua");
	mau(0,15);
	gotoxy(33,10); for(i=0;i<10;i++) printf(" ");
	gotoxy(15,14); for(i=0;i<17;i++) printf(" ");
	gotoxy(45,14); for(i=0;i<17;i++) printf(" ");
	gotoxy(15,18); for(i=0;i<17;i++) printf(" ");
	gotoxy(45,18); for(i=0;i<17;i++) printf(" ");
	for(q=sv;q!=NULL;q=q->right)
	if(q->info.masv==maso)
	{
		mau(2,10);
		gotoxy(27,8); printf("Ma sinh vien: %d",q->info.masv);
		gotoxy(10,12); printf("Ho sinh vien: "); puts(q->info.ho);
		gotoxy(40,12); printf("Ten sinh vien: "); puts(q->info.ten);
		gotoxy(10,16); printf("Phai: "); puts(q->info.phai);
		gotoxy(40,16); printf("Ma lop: "); puts(q->info.ml);
s10: 	gotoxy(33+msv,10);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=27&&c1!=13&&c1!=80&&c1!=72&&c1!=77&&c1!=75)
		{
			if(c1==8&&msv>0)
			{
				msv--;
				gotoxy(33+msv,10);
			 	printf(" ");
				gotoxy(33+msv,10);

			}
			else
			{
				if(c1>='0'&&c1<='9')
				{
					printf("%c",c1);
					mso[++msv]=c1-'0';
				}
			}
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==72||c1==75||c1==77) goto s10;
		if(c1==13||c1==80)
s11:	gotoxy(16+h,14);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=27&&c1!=13&&c1!=80&&c1!=72&&c1!=77&&c1!=75)
		{
			if(c1==8&&h>-1)
			{
				h--;
				gotoxy(16+h,14);
				printf(" ");
				gotoxy(16+h,14);
			}
			else
			{
				if(c1==' '||c1>='A'&&c1<='Z'||c1>='a'&&c1<='z')
					{
						printf("%c",c1);
						tam.ho[++h]=c1;
					}
			}
			tam.ho[h+1]='\0';
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==72) goto s10;
		if(c1==75) goto s11;
		if(c1==80) goto s13;
		if(c1==13||c1==77)
s12:	gotoxy(46+t,14);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=27&&c1!=13&&c1!=80&&c1!=72&&c1!=77&&c1!=75)
		{
			if(c1==8&&t>-1)
			{
				t--;
				gotoxy(46+t,14);
				printf(" ");
				gotoxy(46+t,14);
			}
			else
			{
				if(c1==' '||c1>='A'&&c1<='Z'||c1>='a'&&c1<='z')
				{
						printf("%c",c1);
						tam.ten[++t]=c1;
				}
			}
			tam.ten[t+1]='\0';
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==72) goto s10;
		if(c1==77) goto s12;
		if(c1==75) goto s11;
		if(c1==80) goto s14;
		if(c1==13)
s13:	gotoxy(16+p,18);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=27&&c1!=13&&c1!=80&&c1!=72&&c1!=77&&c1!=75)
		{
			if(c1==8&&p>-1)
			{
				p--;
				gotoxy(16+p,18);
				printf(" ");
				gotoxy(16+p,18);
			}
			else
			{
					if(c1>='A'&&c1<='Z'||c1>='a'&&c1<='z')
					{
						printf("%c",c1);
						tam.phai[++p]=c1;
					}
			}
			tam.phai[p+1]='\0';
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==75||c1==80) goto s13;
		if(c1==72) goto s11;
		if(c1==13||c1==77)
s14:	gotoxy(46+ml,18);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=27&&c1!=13&&c1!=80&&c1!=72&&c1!=77&&c1!=75)
		{
			if(c1==8&&ml>-1)
			{
				ml--;
				gotoxy(46+ml,18);
				printf(" ");
				gotoxy(46+ml,18);
			}
			else
			{
				if(c1!=8)
				{
					if(c1>=0)
					{
						printf("%c",c1);
						tam.ml[++ml]=c1;
						tam.ml[ml]=toupper(tam.ml[ml]);
					}
				}
			}
			tam.ml[ml+1]='\0';
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==72) goto s12;
		if(c1==80||c1==77) goto s14;
		if(c1==75) goto s13;
		if(c1==13)
		{
			if(msv==0)
			{
				Warning(wn[6],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s10;
			}
			if(h==-1)
			{
				Warning(wn[7],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s11;
			}
			if(t==-1)
			{
				Warning(wn[8],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s12;
			}
			if(p==-1)
			{
				Warning(wn[9],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s13;
			}
			if(ml==-1)
			{
				Warning(wn[0],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s14;
			}
			if(h>9)
			{
				Warning(wn[13],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s11;
			}
			if(t>9)
			{
				Warning(wn[14],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s12;
			}
			tam.masv=0;
			for(int j=msv;j>0;j--)
			tam.masv += mso[j]*tinhmaso(j,msv);
			if(tam.masv!=q->info.masv&&kiemtramasv(sv,tam.masv)==1)
			{
				Warning(wn[12],2);
				do
				{
					ch=getch();
				}while(ch!=27&&ch!=13);
				if(ch==27) return;
				if(ch==13) goto s10;
				}
			}
			if(strcmp(tam.phai,"nam")!=0&&strcmp(tam.phai,"nu")!=0)
			{
				Warning(wn[10],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s13;
			}
			if(kiemtramalop(l,tam.ml)==0)
			{
				Warning(wn[11],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s14;
			}
			format_chuoi(tam.ho); chu_in(tam.ho);
			format_chuoi(tam.ten); chu_in(tam.ten);
			chu_in(tam.phai);
			ptr_d k=bd;
			for(k=bd;k!=NULL;k=k->next)
			if(k->infod.msv==q->info.masv)
			{
				k->infod.msv = tam.masv;
			}
			q->info=tam;
	}
	Warning(wn[39],2);
	do
	{
		ch=getch();
	}while(ch!=27);
}
/*void suadiem(ptr_d &bd)
{
	int m=0,h=-1,ms[10],maso=0;
	char c,c1,ch,str[20];
	ptr_d tam,p=bd;
	nenxuat();
	mau(9,15);
	gotoxy(24,7); printf("%c",201);
	for(i=0;i<32;i++) printf("%c",205);
	printf("%c",187);
	for(i=0;i<8;i++)
	{
		gotoxy(24,8+i);
		printf("%c                                %c",186,186);
	}
	gotoxy(24,16); printf("%c",200);
	for(i=0;i<32;i++) printf("%c",205);
	printf("%c",188);
	gotoxy(34,8); printf("NHAP MA MON HOC");
	gotoxy(33,12); printf("NHAP MA SINH VIEN");
	gotoxy(53,10); printf("%c",25);
	gotoxy(53,14); printf("%c",24);
	mau(0,15);
	gotoxy(31,10);
	for(i=0;i<21;i++) printf(" ");
	gotoxy(31,14);
	for(i=0;i<21;i++) printf(" ");
s15:gotoxy(32+h,10);
	mau(0,15);
	c=getch();
	c1=ktkytu(c);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27&&c1!=9)
	{
		if(c1==8&&h>-1)
		{
			h--;
			gotoxy(32+h,10);
			printf(" ");
			gotoxy(32+h,10);
		}
		else
		{
			if(c1!=8&&c1>0)
			{
				printf("%c",c1);
				str1[++h]=c1;
				str1[h]=toupper(str1[h]);
			}
		}
		str1[h+1]='\0';
		c=getch();
		c1=ktkytu(c);
	}
	if(c1==27) return;
	if(c1==72||c1==75||c1==77) goto s15;
	if(c1==80||c1==13||c1==9)
s16: gotoxy(31+m,14);
	mau(0,15);
	c=getch();
	c1=ktkytu(c);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27&&c1!=9)
	{
		if(c1==8&&m>0)
		{
			m--;
			gotoxy(33+m,13);
			printf(" ");
			gotoxy(33+m,13);
		}
		else
		{
			if(c1>='0'&&c1<='9')
			{
				printf("%c",c1);
				ms[++m]=c1-'0';
			}
		}
		c=getch();
		c1=ktkytu(c);
	}
	if(c1==27) return;
	if(c1==72||c1==75||c1==77||c1==80||c1==9) goto s16;
	if(c1==13)
	{
		if(h==-1)
		{
			Warning(wn[15],2);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto s15;
		}
		if(m==0)
		{
			Warning(wn[6],2);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto s15;
		}
		if(kiemtramamh(mh,str)==1)
		{
			Warning(wn[26],2);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto s15;
		}

		for(i=m;i>0;i--)
		maso += ms[i]*tinhmaso(i,m);
		if(kiemtramasv(sv,maso)==0)
		{
			Warning(wn[27],2);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto s16;
		}
	}
	for(p=bd;p!=NULL;p=p->next)
	if(strcmp(p->infod.mmh,str)==0&&p->infod.msv==maso)
	{
		nennhap();
		mau(15,0);
		gotoxy(28,2);
		printf("CHUC NANG SUA DIEM SINH VIEN");
		gotoxy(25,8); printf("Ma sinh vien: %d",p->infod.msv);
		gotoxy(25,10); printf("Ma mon hoc: %s",p->infod.mmh);
		gotoxy(15,12); printf("Lan 1: ");
		gotoxy(35,12); printf("Lan 2: ");
		if(p->infod.lan==1)
			gotoxy(22,12);
		else
			gotoxy(42,12);
		printf("%d",p->infod.diem);
		gotoxy(15,14);printf("Sua");gotoxy(35,14);printf("Sua");
		gotoxy(20,14);	for(i=0;i<10;i++) printf(" ");
		gotoxy(40,14);	for(i=0;i<10;i++) printf(" ");
s17:
		gotoxy(20+d1,14);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=13&&c1!=27&&c1!=72&&c1!=75&&c1!=77&&c1!=80&&c1!=9)
		{
			if(c1==8&&d1>0)
			{
				d1--;
				gotoxy(20+d1,14);
				printf(" ");
				gotoxy(20+d1,14);
			}
			else
			{
				if(c1>='0'&&c1<='9')
				{
					printf("%c",c1);
					u[++d1]=c1-48;
				}
			}
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==75||c1==72||c1==80) goto s17;
		if(c1==13||c1==9||c1==77)
s18:
		gotoxy(40+d2,14);
		mau(0,15);
		c=getch();
		c1=ktkytu(c);
		while(c1!=13&&c1!=27&&c1!=72&&c1!=75&&c1!=77&&c1!=80&&c1!=9)
		{
			if(c1==8&&d2>0)
			{
				d2--;
				gotoxy(40+d2,14);
				printf(" ");
				gotoxy(40+d2,14);
			}
			else
			{
				if(c1>='0'&&c1<='9')
				{
					printf("%c",c1);
					v[++d2]=c1-48;
				}
			}
			c=getch();
			c1=ktkytu(c);
		}
		if(c1==27) return;
		if(c1==75) goto s16;
		if(c1==72||c1==77||c1==9||c1==80) goto s17;
		if(c1==13)
		{
			if(d1==0||d2==0)
			{
				Warning(wn[25],2);
				do
					{
						ch=getch();
					}while(ch!=27&&ch!=13);
					if(ch==27) return;
					if(ch==13) goto s17;
			}
		}
	}
}*/
void xoalop(dsl &l,ptr_sv &sv)
{
	int m=-1,vitri;
	char str[20],c,c1,ch;
	nentim();
	mau(15,0);
	gotoxy(32,2);
	printf("CHUC NANG XOA LOP");
	khung();
	mau(9,15);
	gotoxy(37,10); printf("NHAP MA LOP");
x1:	gotoxy(34+m,13);
	mau(0,15);
	c=getch();
	c1=ktkytu(c);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
	{
		if(c1==8&&m>-1)
		{
			m--;
			gotoxy(34+m,13);
			printf(" ");
			gotoxy(34+m,13);
		}
		else
		{
			if(c1!=8&&c1>0)
			{
				printf("%c",c1);
				str[++m]=c1;
				str[m]=toupper(str[m]);
			}
		}
		str[m+1]='\0';
		c=getch();
		c1=ktkytu(c);
	}
	if(c1==27) return;
	if(c1==72||c1==75||c1==77||c1==80) goto x1;
	if(c1==13)
	{
		if(m==-1)
		{
			Warning(wn[0],4);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto x1;
		}
		if(kiemtramalop(l,str)==0)
		{
			Warning(wn[11],4);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto x1;
		}
	}
	mau(15,0);
	gotoxy(32,2);
	printf("CHUC NANG XOA LOP");
	vitri=timmalop(l,str);
	for(int j=vitri;j<l.n;j++)
	l.nodes[j]=l.nodes[j+1];
	l.n--;
	ptr_sv p=sv;
	for(p=sv;p!=NULL;p=p->right)
	if(strcmp(p->info.ml,str)==0)
	xoa(sv,p);
	Warning(wn[40],4);
	do
	{
		ch=getch();
	}while(ch!=27);
}
void xoamh(ptr_mh &mh,ptr_d &bd)
{
	int m=-1;
	char c,c1,ch,str[20];
	ptr_mh p=mh;
	nentim();
	mau(15,0);
	gotoxy(30,2);
	printf("CHUC NANG XOA MON HOC");
	khung();
	mau(9,15);
	mau(9,15);
	gotoxy(35,10); printf("NHAP MA MON HOC");
x2: gotoxy(34+m,13);
	mau(0,15);
	c=getch();
	c1=ktkytu(c);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
	{
		if(c1==8&&m>-1)
		{
			m--;
			gotoxy(34+m,13);
			printf(" ");
			gotoxy(34+m,13);
		}
		else
		{
			if(c1!=8&&c1>0)
			{
				printf("%c",c1);
				str[++m]=c1;
				str[m]=toupper(str[m]);
			}
		}
		str[m+1]='\0';
		c=getch();
		c1=ktkytu(c);
	}
	if(c1==27) return;
	if(c1==72||c1==75||c1==77||c1==80) goto x2;
	if(c1==13)
	{
		if(m==-1)
		{
			Warning(wn[15],4);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto x2;
		}
		if(kiemtramamh(mh,str)==1)
		{
			Warning(wn[26],4);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto x2;
		}
	}
	while(p!=NULL)
	{
		if(strcmp(p->infomh.mamh,str)==0)
		{
			if(p==mh)
			{
				mh=p->next;
				delete(p);
			}
			else
			{
				ptr_mh q=mh;
				while(q->next!=p) q=q->next;
				q->next = p->next;
				delete(p);
			}
		}
		else p=p->next;
	}
	ptr_d k=bd;
	for(k=bd;k!=NULL;k=k->next)
	if(strcmp(k->infod.mmh,str)==0)
	xoa1(bd,k);
	Warning(wn[40],4);
	do
	{
		ch=getch();
	}while(ch!=27);
}
void xoasv(ptr_sv &sv,ptr_d &bd)
{
	int m=0,i,ms[10],maso=0;
	char c,c1,ch;
	ptr_sv p=sv;
	nentim();
	mau(15,0);
	gotoxy(29,2);
	printf("CHUC NANG TIM SINH VIEN");
	khung();
	mau(9,15);
	gotoxy(34,10); printf("NHAP MA SINH VIEN");
x3: gotoxy(33+m,13);
	mau(0,15);
	c=getch();
	c1=ktkytu(c);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27)
	{
		if(c1==8&&m>0)
		{
			m--;
			gotoxy(33+m,13);
			printf(" ");
			gotoxy(33+m,13);
		}
		else
		{
			if(c1>='0'&&c1<='9')
			{
				printf("%c",c1);
				ms[++m]=c1-'0';
			}
		}
		c=getch();
		c1=ktkytu(c);
	}
	if(c1==27) return;
	if(c1==72||c1==75||c1==77||c1==80) goto x3;
	if(c1==13)
	{
		if(m==0)
		{
			Warning(wn[6],4);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto x3;
		}
		for(i=m;i>0;i--)
		maso += ms[i]*tinhmaso(i,m);
		if(kiemtramasv(sv,maso)==0)
		{
			Warning(wn[27],4);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto x3;
		}
	}
	for(p=sv;p!=NULL;p=p->right)
	if(p->info.masv==maso)
	xoa(sv,p);
	ptr_d k=bd;
	for(k=bd;k!=NULL;k=k->next)
	if(k->infod.msv==maso)
	xoa1(bd,k);
	Warning(wn[40],4);
	do
	{
		ch=getch();
	}while(ch!=27);
}
/*void xoadiem(ptr_d &bd,ptr_mh mh,ptr_sv sv)
{
	int i,m=0,h=-1,ms[10],maso=0;
	char c,c1,ch,str[20];
	ptr_d p=bd;
	nenxuat();
	mau(9,15);
	gotoxy(24,7); printf("%c",201);
	for(i=0;i<32;i++) printf("%c",205);
	printf("%c",187);
	for(i=0;i<8;i++)
	{
		gotoxy(24,8+i);
		printf("%c                                %c",186,186);
	}
	gotoxy(24,16); printf("%c",200);
	for(i=0;i<32;i++) printf("%c",205);
	printf("%c",188);
	gotoxy(34,8); printf("NHAP MA MON HOC");
	gotoxy(33,12); printf("NHAP MA SINH VIEN");
	gotoxy(53,10); printf("%c",25);
	gotoxy(53,14); printf("%c",24);
	mau(0,15);
	gotoxy(31,10);
	for(i=0;i<21;i++) printf(" ");
	gotoxy(31,14);
	for(i=0;i<21;i++) printf(" ");
s15:gotoxy(32+h,10);
	mau(0,15);
	c=getch();
	c1=ktkytu(c);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27&&c1!=9)
	{
		if(c1==8&&h>-1)
		{
			h--;
			gotoxy(32+h,10);
			printf(" ");
			gotoxy(32+h,10);
		}
		else
		{
			if(c1!=8&&c1>0)
			{
				printf("%c",c1);
				str[++h]=c1;
				str[h]=toupper(str[h]);
			}
		}
		str[h+1]='\0';
		c=getch();
		c1=ktkytu(c);
	}
	if(c1==27) return;
	if(c1==72||c1==75||c1==77) goto s15;
	if(c1==80||c1==13||c1==9)
s16: gotoxy(31+m,14);
	mau(0,15);
	c=getch();
	c1=ktkytu(c);
	while(c1!=72&&c1!=77&&c1!=75&&c1!=80&&c1!=13&&c1!=27&&c1!=9)
	{
		if(c1==8&&m>0)
		{
			m--;
			gotoxy(33+m,13);
			printf(" ");
			gotoxy(33+m,13);
		}
		else
		{
			if(c1>='0'&&c1<='9')
			{
				printf("%c",c1);
				ms[++m]=c1-'0';
			}
		}
		c=getch();
		c1=ktkytu(c);
	}
	if(c1==27) return;
	if(c1==72||c1==75||c1==77||c1==80||c1==9) goto s16;
	if(c1==13)
	{
		if(h==-1)
		{
			Warning(wn[15],2);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto s15;
		}
		if(m==0)
		{
			Warning(wn[6],2);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto s15;
		}
		if(kiemtramamh(mh,str)==1)
		{
			Warning(wn[26],2);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto s15;
		}

		for(i=m;i>0;i--)
		maso += ms[i]*tinhmaso(i,m);
		if(kiemtramasv(sv,maso)==0)
		{
			Warning(wn[27],2);
			do
			{
				ch=getch();
			}while(ch!=27&&ch!=13);
			if(ch==27) return;
			if(ch==13) goto s16;
		}
	}
	for(p=bd;p!=NULL;p=p->next)
	if(strcmp(p->infod.mmh,str)==0&&p->infod.msv==maso)
	{
		if(p==bd)
			{
				bd=p->next;
				delete(p);
			}
			else
			{
				ptr_d q=bd;
				while(q->next!=p) q=q->next;
				q->next = p->next;
				delete(p);
			}
	}
	Warning(wn[40],4);
	do
	{
		ch=getch();
	}while(ch!=27);
}*/
void bangmenuchinh()
{
	mau(3,15);
	system("cls");
	
	mau(3,15);		
	gotoxy(5,0);
	printf("Cau Truc Du Lieu & Giai Thuat");
	
		
	gotoxy(55,0);
	printf("Ths. Luu Nguyen Ky Thu");
    mau(3,15);
	
	gotoxy(0,1);
	for(int i=0;i<80;i++)	printf("%c",177);
	gotoxy(30,3);
	mau(3,14);
	printf("CHUONG TRINH QUAN LY SINH VIEN");
	
	mau(0,15);
	gotoxy(60,5);
	mau(5,15);
	gotoxy(60,9);
	printf("                 ");
	gotoxy(60,10);
	printf("      NHOM 8     ");
	gotoxy(60,11);
	printf("                 ");
	mau(9,15);
	gotoxy(60,13);
	printf("                 ");
	gotoxy(60,14);
	printf("   Luong Van Tri  ");
	gotoxy(60,15);
	printf("                 ");
	gotoxy(60,17);
	printf("                 ");
	gotoxy(60,18);
	printf("  Nguyen Thi Nga ");
	gotoxy(60,19);
	printf("                 ");

	

}
int menuchinh()
{
	bangmenuchinh();
	int item,i;
	char c;
	for(i=0;i<soitem;i++)
	{
		mau(15,4);
		gotoxy(3,5+i*4);
		printf("                       ");
		gotoxy(3,6+i*4);
		printf(td[i]);
		gotoxy(3,7+i*4);
		printf("                       ");

	}
	item=0;
	{
		mau(2,15);
		gotoxy(3,5+item*4);
		printf("                       ");
		gotoxy(3,6+item*4);
		printf(td[item]);
		gotoxy(3,7+item*4);
		printf("                       ");
	}
	while(1)
	{
		c=getch();
		if(c==13) return item+1;
		switch(c)
		{
			case 80:
				{
					if(item==soitem-1)
					{
						mau(15,4);
						gotoxy(3,5+item*4);
						printf("                       ");
						gotoxy(3,6+item*4);
						printf(td[item]);
						gotoxy(3,7+item*4);
						printf("                       ");
						item=0;
						goto a;
					}
					mau(15,4);
					gotoxy(3,5+item*4);
					printf("                       ");
					gotoxy(3,6+item*4);
					printf(td[item]);
					gotoxy(3,7+item*4);
					printf("                       ");
					item++;
a:					mau(2,15);
					gotoxy(3,5+item*4);
					printf("                       ");
					gotoxy(3,6+item*4);
					printf(td[item]);
					gotoxy(3,7+item*4);
					printf("                       ");
					break;
				}
			case 72:
				{
					if(item==0)
					{
						mau(15,4);
						gotoxy(3,5+item*4);
						printf("                       ");
						gotoxy(3,6+item*4);
						printf(td[item]);
						gotoxy(3,7+item*4);
						printf("                       ");
						item=soitem-1;
						goto b;
					}
					mau(15,4);
					gotoxy(3,5+item*4);
					printf("                       ");
					gotoxy(3,6+item*4);
					printf(td[item]);
					gotoxy(3,7+item*4);
					printf("                       ");
					item--;
b:					mau(2,15);
					gotoxy(3,5+item*4);
					printf("                       ");
					gotoxy(3,6+item*4);
					printf(td[item]);
					gotoxy(3,7+item*4);
					printf("                       ");
					break;
				}
		}
	}
}

void bangmenuphu(char s[],int soit)
{
	int i;
	mau(3,15);
	system("cls");
	mau(4,15);
	gotoxy(30,5);
	printf("                          ");
	gotoxy(30,6);
	printf("%s",s);
	gotoxy(30,7);
	printf("                          ");
	for(i=0;i<soit;i++)
	{
		mau(15,9);
		gotoxy(30,8+2*i);printf("                          ");
		mau(8,9);
		gotoxy(30,9+2*i);printf("                          ");
	}
	mau(3,14);
	gotoxy(30,9+2*soit);
	printf(" ESC: Quay lai Menu chinh ");
}
int menuphu(char s[],char td[][40],int soit)
{
	bangmenuphu(s,soit);
	int i,item;
	char c;
	for(i=0;i<soit;i++)
	{
		mau(15,1);
		gotoxy(30,8+2*i);
		printf(td[i]);
	}
	item=0;
	{
		mau(9,15);
		gotoxy(30,8+2*item);
		printf(td[item]);
	}
	while(1)
	{
		c=getch();
		if(c==27) return 0;
		if(c==13)  return item+1;
		switch(c)
		{
			case 80:
				{
					if(item==soit-1)
					{
						mau(15,1);
						gotoxy(30,8+2*item);
						printf(td[item]);
						item=0;
						goto c;
					}
					mau(15,1);
					gotoxy(30,8+2*item);
					printf(td[item]);
					item++;
c:					mau(9,15);
					gotoxy(30,8+2*item);
					printf(td[item]);
					break;
				}
			case 72:
				{
					if(item==0)
					{
						mau(15,1);
						gotoxy(30,8+2*item);
						printf(td[item]);
						item=soit-1;
						goto d;
					}
					mau(15,1);
					gotoxy(30,8+2*item);
					printf(td[item]);
					item--;
d:					mau(9,15);
					gotoxy(30,8+2*item);
					printf(td[item]);
					break;
				}
		}
	}
}
int nut(char *ten,int x,int y,int trangthai)
{
	int i;
	mau(9,15);
	gotoxy(x,y);
	printf("%c",201);
	for(i=0;i<7;i++)
	{
		printf("%c",205);
	}
	printf("%c",187);
	gotoxy(x,y+1);
	printf("%c",186);
	gotoxy(x+8,y+1);
	printf("%c",186);
	gotoxy(x,y+2);
	printf("%c",200);
	for(i=0;i<7;i++)
	{
		printf("%c",205);
	}
	printf("%c",188);
	//space = (8-strlen(ten))/2;
	gotoxy(x+1,y+1);
	printf("       ");
	gotoxy(x+2,y+1);

	if(trangthai==1)
	{
		mau(9,12);
	}else{
		mau(9,15);
	}
	printf("%s",ten);
	return trangthai;
}
int hienNut(char *ten,char *ten2,int x,int y)
{

	int tt = 2;			//chon trang thai dau
	nut(ten2,x+11,y,1);
	nut(ten,x,y,2);
	while(1){
		char ch;
		ch = getch();
		if(ch=='\r'){
			return tt ;
		}
		switch(ch){
			case 77:{

				nut(ten,x,y,2);
				nut(ten2,x+11,y,1);
				tt = 2;
				break;
			}
			case 75:{
				nut(ten2,x+11,y,2);
				nut(ten,x,y,1);
				tt = 1;
				break;
			}
		}
	}
}
main()
{
	ptr_d bd;
	ptr_mh mh;
	ptr_sv sv;
	bd=NULL;
	mh=NULL;
	sv=NULL;
	dsl l;
	l.n=0;
	int ttn;
	int chon,chon1,chon2,chon3,chon4;
	system("cls");
	while(1)
	{
mnc:	system("cls");
		chon=menuchinh();
		switch(chon)
		{
			case 1:
				{
					while(1)
					{

mnp:					chon1=menuphu(mn[0],td1,soitem1);
						switch(chon1)
						{
							case 1:
								{
									system("cls");
									nhaplop(l);
									goto mnp;
									break;
									{
									system("cls");
									save_lop(l);
									goto mnp;
									break;
								    }
								    {
									system("cls");
									load_lop(l);
									goto mnp;
									break;
								}
								}
							case 2:
								{
									system("cls");
									xuatlop(l);
									goto mnp;
									break;
								}
							case 3:
								{
									system("cls");
									timlop(l);
									goto mnp;
									break;
								}
							case 4:
								{
									system("cls");
									sualop(l,sv);
									goto mnp;
									break;
								}
							case 5:
								{
									system("cls");
									xoalop(l,sv);
									goto mnp;
									break;
								}
							case 6:
								{
									system("cls");
									save_lop(l);
									goto mnp;
									break;
								}
							case 7:
								{
									system("cls");
									load_lop(l);
									goto mnp;
									break;
								}
							case 0:
								{
									goto mnc;
									break;
								}
						}
					}
					break;
				}
			case 2:
				{
					while(1)
					{

						chon2=menuphu(mn[1],td2,soitem2);
						switch(chon2)
						{
							case 1:
								{
									system("cls");
									nhapsv(sv,l);
									goto mnc;
									break;
								}
							case 2:
								{
									system("cls");
									xuatsv(sv,l);
									goto mnc;
									break;
								}
							/*case 3:
								{
									system("cls");
									xuatdsthi(sv,l,mh);
									goto mnc;
									break;
								}*/
							case 3:
								{
									system("cls");
									timsv(sv);
									goto mnc;
									break;
								}
							case 4:
								{
									system("cls");
									suasv(sv,l,bd);
									goto mnc;
									break;
								}
							case 5:
								{
									system("cls");
									xoasv(sv,bd);
									goto mnc;
									break;
								}
							case 6:
								{
									system("cls");
									save_sv(sv);
									goto mnc;
									break;
								}
							case 7:
								{
									system("cls");
									load_sv(sv);
									goto mnc;
									break;
								}
							case 0:
								{
									goto mnc;
									break;
								}
						}
					}
					break;
				}
			case 3:
				{
					while(1)
					{

						chon3=menuphu(mn[2],td3,soitem3);
						switch(chon3)
						{
							case 1:
								{
									system("cls");
									nhapmh(mh);
									goto mnc;
									break;
								}
							case 2:
								{
									system("cls");
									xuatmh(mh);
									goto mnc;
									break;
								}
							case 3:
								{
									system("cls");
									timmh(mh);
									goto mnc;
									break;
								}
							case 4:
								{
									system("cls");
									suamh(mh,bd);
									goto mnc;
									break;
								}
							case 5:
								{
									system("cls");
									xoamh(mh,bd);
									goto mnc;
									break;
								}
							case 6:
								{
									system("cls");
									save_mh(mh);
									goto mnc;
									break;
								}
							case 7:
								{
									system("cls");
									load_mh(mh);
									goto mnc;
									break;
								}
							case 0:
								{
									goto mnc;
									break;
								}
						}
					}
					break;
				}
			case 4:
				{
					while(1)
					{

						chon4=menuphu(mn[3],td4,soitem4);
						switch(chon4)
						{
							case 1:
								{
									system("cls");
									nhapdiem(bd,sv,mh);
									goto mnc;
									break;
								}
							case 2:
								{
									system("cls");
									xuatdiem(bd,l,mh,sv);
									goto mnc;
									break;
								}
							case 3:
								{
									system("cls");
									timdiem(bd,sv);
									goto mnc;
									break;
								}
							case 4:
								{
									system("cls");
									xuatdsthi(sv,l,mh);
									goto mnc;
									break;
								}
							case 5:
								{
									system("cls");
									save_diem(bd);
									goto mnc;
									break;
								}
							case 6:
								{
									system("cls");
									load_diem(bd);
									goto mnc;
									break;
								}
							case 0:
								{
									goto mnc;
									break;
								}
						}
					}
					break;
				}
			case 5:
			{
				mau(9,15);
					gotoxy(31,8); printf("%c",218);
					for(int i=0;i<22;i++) printf("%c",196);
					printf("%c",191);
					for(int j=0;j<7;j++)
					{
						for(int i=0;i<24;i++)
						{
							if(i==0||i==23)
							{
								gotoxy(31+i,9+j); printf("%c",179);
							}
							else
							{
								gotoxy(31+i,9+j); printf(" ");
							}
						}
					}
					gotoxy(31,16); printf("%c",192);
					for(int i=0;i<22;i++) printf("%c",196);
					printf("%c",217);
					mau(9,15);
					gotoxy(34,10); printf("BAN CO MUON THOAT?");
					char ok[10]="THOAT";
					char no[10]="KHONG";
					ttn=hienNut(ok,no,33,12);
					if(ttn==1) return 0;
					else goto mnc;
					break;
			}
		}
	}
}
