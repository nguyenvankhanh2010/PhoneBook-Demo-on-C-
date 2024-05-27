#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <iomanip>
#define SIZE 100 // Kích thu?c c?a b?ng bam
#include <vector>
#include <ctime>

using namespace std;

void thongtinHoten(string hoTen);
void xoatentrongdanhba(string tenluachon,string so);
void luuvaonhatki(string phuongthuc,string ten,string sdt,string moi);
void addContactdauvao(string chuoi1,string chuoi2);

// PHAN GIAO DIEN
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Loading()
{
	char a=178,b=219;
	cout<<"\n\t\t\t\t\t\tLoading......\n";
	cout<<"\t\t\t\t\t";
	for (int i=0;i<25;i++)
		cout<<a;
	cout<<"\r";
	cout<<"\t\t\t\t\t";
	for (int j=0;j<25;j++)
	{
		cout<<b;
		Sleep(100);
	}
	cout<<"\n";
}
void daluutenlienhe()
{
	gotoxy(37,9);
	cout<<char(218);
	for (int i=0; i<20;i++)
		cout<<char(196);
	cout<<char(191);
	gotoxy(37,10);
	cout<<char(179)<<"Da luu thanh cong!!!"<<char(179);
	gotoxy(37,11);
	cout<<char(192);
	for (int i=0;i<20;i++)
		cout<<char(196);
	cout<<char(217);
}
void daluutenlienhe2()
{
	gotoxy(73,9);
	cout<<char(218);
	for (int i=0; i<13;i++)
		cout<<char(196);
	cout<<char(191);
	gotoxy(73,10);
	cout<<char(179)<<"Thanh cong!!!"<<char(179);
	gotoxy(73,11);
	cout<<char(192);
	for (int i=0;i<13;i++)
		cout<<char(196);
	cout<<char(217);
}
void addavatar()
{
	fstream newfile;
	newfile.open("anh-danhba.txt",ios::in);
	if(newfile.is_open())
	{
		string txt;
		while(getline(newfile,txt))
		{
			cout<<"\t\t\t\t"<<txt<<endl;
			Sleep(20);
		}
		newfile.close();
	}		
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;
 
    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}
void khungnhapsdt()
{
	gotoxy(29,3);
	cout<<char(220);
	for (int i=0;i<40;i++)
		cout<<char(220);
	cout<<char(220);
	gotoxy(29,4);
	cout<<char(221);
	gotoxy(29,6);
	cout<<char(221);
	gotoxy(29,5);
	cout<<char(221);
	gotoxy(29,7);
	cout<<char(221);
	gotoxy(29,8);
	cout<<char(221);
	gotoxy(29,9);
	cout<<char(221);
	gotoxy(70,5);
	cout<<char(222);
	gotoxy(70,4);
	cout<<char(222);
	gotoxy(70,6);
	cout<<char(222);
	gotoxy(70,7);
	cout<<char(222);
	gotoxy(70,8);
	cout<<char(222);
	gotoxy(70,9);
	cout<<char(222);
	gotoxy(29,10);
	cout<<char(223);
	for (int i=0;i<40;i++)
	cout<<char(223);
	cout<<char(223);
}
void khungdisplayPhonebook()
{
	gotoxy(32,12);
	cout<<char(218);
	for (int i=0;i<36;i++)
		cout<<char(196);
	cout<<char(191);
	for (int i=0;i<11;i++)
	{
		gotoxy(32,13+i);
		cout<<char(179);
	}
	for (int i=0; i<11;i++)
	{
		gotoxy(69,13+i);
		cout<<char(179);
	}
	gotoxy(32,24);
	cout<<char(192);
	for (int i=0;i<36;i++)
		cout<<char(196);	
	cout<<char(217);	
	
	gotoxy(31,11);
	cout<<char(218);
	for (int i=0;i<38;i++)
		cout<<char(196);
	cout<<char(191);
	for (int i=0;i<13;i++)
	{
		gotoxy(31,12+i);
		cout<<char(179);
	}
	for (int i=0; i<13;i++)
	{
		gotoxy(70,12+i);
		cout<<char(179);
	}
	gotoxy(31,25);
	cout<<char(192);
	for (int i=0;i<38;i++)
		cout<<char(196);
	cout<<char(217);
	
	gotoxy(50,24);
	cout<<char(31);
	gotoxy(50,12);
	cout<<char(30);	
} 
void addnutbanphim()
{
	gotoxy(37,26);
	cout<<char(218);
	for (int i=0;i<8;i++)
		cout<<char(196);
	cout<<char(191);
	gotoxy(37,27);
	cout<<char(179)<<"BAN PHIM"<<char(179);
	gotoxy(37,28);
	cout<<char(192);
	for (int i=0;i<8;i++)
		cout<<char(196);
	cout<<char(217);
}
void addnutganday()
{
	gotoxy(47,26);
	cout<<char(218);
	for (int i=0;i<7;i++)
		cout<<char(196);
	cout<<char(191);
	gotoxy(47,27);
	cout<<char(179)<<"GAN DAY"<<char(179);
	gotoxy(47,28);
	cout<<char(192);
	for (int i=0;i<7;i++)
		cout<<char(196);
	cout<<char(217);
}
void addnutdanhba()		
{
	gotoxy(56,26);
	cout<<char(218);
	for (int i=0;i<7;i++)
		cout<<char(196);
	cout<<char(191);
	gotoxy(56,27);
	cout<<char(179)<<"DANH BA"<<char(179);
	gotoxy(56,28);
	cout<<char(192);
	for (int i=0;i<7;i++)
		cout<<char(196);
	cout<<char(217);
}
void addnutsuaten()
{
    gotoxy(66,5);// o thay doi ten
	cout<<char(218);
	for (int i=0;i<11;i++)
		cout<<char(196);
	cout<<char(191);
	gotoxy(66,6);
	cout<<char(179)<<"Sua doi ten"<<char(179);
	gotoxy(66,7);
	cout<<char(192);
	for (int i=0;i<11;i++)
		cout<<char(196);
	cout<<char(217);
}
void addnutsuasdt()
{
    gotoxy(79,5);
	cout<<char(218);
	for (int i=0;i<11;i++)
		cout<<char(196);
	cout<<char(191);
	gotoxy(79,6);
	cout<<char(179)<<"Sua doi sdt"<<char(179);
	gotoxy(79,7);
	cout<<char(192);
	for (int i=0;i<11;i++)
		cout<<char(196);
	cout<<char(217);
}
void addnutxoa()
{
    gotoxy(92,5);//// o xoa
	cout<<char(218);
	for (int i=0;i<3;i++)
		cout<<char(196);
	cout<<char(191);
	gotoxy(92,6);
	cout<<char(179)<<"Xoa"<<char(179);
	gotoxy(92,7);
	cout<<char(192);
	for (int i=0;i<3;i++)
		cout<<char(196);
	cout<<char(217);
}
void luachonnutbanphim()
{
	gotoxy(37,26);
	cout<<char(220);
	for (int i=0;i<8;i++)
		cout<<char(220);
	cout<<char(220);
	gotoxy(37,27);
	cout<<char(221)<<"BAN PHIM"<<char(222);
	gotoxy(37,28);
	cout<<char(223);
	for (int i=0;i<8;i++)
		cout<<char(223);
	cout<<char(223);
}
void luachonnutganday()
{
	gotoxy(47,26);
	cout<<char(220);
	for (int i=0;i<7;i++)
		cout<<char(220);
	cout<<char(220);
	gotoxy(47,27);
	cout<<char(221)<<"GAN DAY"<<char(222);
	gotoxy(47,28);
	cout<<char(223);
	for (int i=0;i<7;i++)
		cout<<char(223);
	cout<<char(223);
}
void luachonnutdanhba()
{
	gotoxy(56,26);
	cout<<char(220);
	for (int i=0;i<7;i++)
		cout<<char(220);
	cout<<char(220);
	gotoxy(56,27);
	cout<<char(221)<<"DANH BA"<<char(222);
	gotoxy(56,28);
	cout<<char(223);
	for (int i=0;i<7;i++)
		cout<<char(223);
	cout<<char(223);
}
void addtheme()
{
	fstream newfile;
	newfile.open("anh-danhba.txt",ios::in);
	if(newfile.is_open())
	{
		string txt;
		while(getline(newfile,txt))
		{
			cout<<"\t\t\t\t"<<txt<<endl;
		}
		newfile.close();
	addnutbanphim();
	addnutganday();
	addnutdanhba();
	}
}

void hiendanhba()
{
	cout<<"\t\t\t\t\t-------DANH BA-------"<<endl;
	cout<<endl;
//	gotoxy(2,40);
//	cout<<"Phim len de chon."<<endl;
//	cout<<"Phim xuong de huy."<<endl;
}
void hienbanphim()
{
	gotoxy(35,13);
	cout<<" 1\t\t   2\t\t3\n";
	gotoxy(35,15);
	cout<<" 4\t\t   5\t\t6";
	gotoxy(35,17);
	cout<<" 7\t\t   8\t\t9";
	gotoxy(35,19);
	cout<<" *\t\t   0\t\t#";
}
void luachonnutxoa()
{
	gotoxy(25,7);
	cout<<char(220);
	for (int i=0;i<3;i++)
		cout<<char(220);
	cout<<char(220);
	gotoxy(25,8);
	cout<<char(221)<<"Xoa"<<char(222);
	gotoxy(25,9);
	cout<<char(223);
	for (int i=0;i<3;i++)
		cout<<char(223);
	cout<<char(223);
	
}
void luachonnutsuasdt()//option xoa trong danh ba
{
	gotoxy(45,7);
	cout<<char(220);
	for (int i=0;i<13;i++)
		cout<<char(220);
	cout<<char(220);
	gotoxy(45,8);
	cout<<char(221)<<"Chinh sua sdt"<<char(222);
	gotoxy(45,9);
	cout<<char(223);
	for (int i=0;i<13;i++)
		cout<<char(223);
	cout<<char(223);
}
void luachonnutsuaten()//option xoa trong danh ba
{
	gotoxy(30,7);
	cout<<char(220);
	for (int i=0;i<13;i++)
		cout<<char(220);
	cout<<char(220);
	gotoxy(30,8);
	cout<<char(221)<<"Chinh sua ten"<<char(222);
	gotoxy(30,9);
	cout<<char(223);
	for (int i=0;i<13;i++)
		cout<<char(223);
	cout<<char(223);
}
void chonsuaten()
{
    	gotoxy(66,5);
	cout<<char(220);
	for (int i=0;i<11;i++)
		cout<<char(220);
	cout<<char(220);
	gotoxy(66,6);
	cout<<char(221)<<"Sua doi ten"<<char(222);
	gotoxy(66,7);
	cout<<char(223);
	for (int i=0;i<11;i++)
		cout<<char(223);
	cout<<char(223);
}
void chonsuasdt()
{
    	gotoxy(79,5);
	cout<<char(220);
	for (int i=0;i<11;i++)
		cout<<char(220);
	cout<<char(220);
	gotoxy(79,6);
	cout<<char(221)<<"Sua doi sdt"<<char(222);
	gotoxy(79,7);
	cout<<char(223);
	for (int i=0;i<11;i++)
		cout<<char(223);
	cout<<char(223);
}
void chonxoa()
{
    gotoxy(92,5);//// o xoa
	cout<<char(220);
	for (int i=0;i<3;i++)
		cout<<char(220);
	cout<<char(220);
	gotoxy(92,6);
	cout<<char(221)<<"Xoa"<<char(222);
	gotoxy(92,7);
	cout<<char(223);
	for (int i=0;i<3;i++)
		cout<<char(223);
	cout<<char(223);
}
void khungaddnhom()
{
	gotoxy(70,4);
	cout<<char(218);
	for (int i=0;i<12;i++)
		cout<<char(196);
	cout<<char(191);
	gotoxy(70,5);
	cout<<char(179)<<"ADD vao nhom"<<char(179);
	gotoxy(70,6);
	cout<<char(192);
	for (int i=0;i<12;i++)
		cout<<char(196);
	cout<<char(217);
	
}
void khungsuathongtin()
{
	gotoxy(70,7);
	cout<<char(218);
	for (int i=0;i<13;i++)
		cout<<char(196);
	cout<<char(191);
	gotoxy(70,8);
	cout<<char(179)<<"Sua thong tin"<<char(179);
	gotoxy(70,9);
	cout<<char(192);
	for (int i=0;i<13;i++)
		cout<<char(196);
	cout<<char(217);
	
}
void chonaddnhom()
{
	gotoxy(70,4);
	cout<<char(220);
	for (int i=0;i<12;i++)
		cout<<char(220);
	cout<<char(220);
	gotoxy(70,5);
	cout<<char(221)<<"ADD vao nhom"<<char(222);
	gotoxy(70,6);
	cout<<char(223);
	for (int i=0;i<12;i++)
		cout<<char(223);
	cout<<char(223);
	
}
void chonsuathongtin()
{
	gotoxy(70,7);
	cout<<char(220);
	for (int i=0;i<13;i++)
		cout<<char(220);
	cout<<char(220);
	gotoxy(70,8);
	cout<<char(221)<<"Sua thong tin"<<char(222);
	gotoxy(70,9);
	cout<<char(223);
	for (int i=0;i<13;i++)
		cout<<char(223);
	cout<<char(223);
}
void an2nut()
{
	for (int i=0; i<6;i++)
	{
		gotoxy(70,4+i);
		for (int j=0;j<15; j++)
		cout<<char(32);
	}
}
void nutlichsu()
{
	gotoxy(65,2);
	cout<<char(218);
	for (int i=0;i<7;i++)
		cout<<char(196);
	cout<<char(191);
	gotoxy(65,3);
	cout<<char(179)<<"Lich su"<<char(179);
	gotoxy(65,4);
	cout<<char(192);
	for (int i=0;i<7;i++)
		cout<<char(196);
	cout<<char(217);
}
void nutqlnhom()
{
	gotoxy(74,2);
	cout<<char(218);
	for (int i=0;i<7;i++)
		cout<<char(196);
	cout<<char(191);
	gotoxy(74,3);
	cout<<char(179)<<"QL nhom"<<char(179);
	gotoxy(74,4);
	cout<<char(192);
	for (int i=0;i<7;i++)
		cout<<char(196);
	cout<<char(217);
}
void chonnutlichsu()
{
	gotoxy(65,2);
	cout<<char(220);
	for (int i=0;i<7;i++)
		cout<<char(220);
	cout<<char(220);
	gotoxy(65,3);
	cout<<char(221)<<"Lich su"<<char(222);
	gotoxy(65,4);
	cout<<char(223);
	for (int i=0;i<7;i++)
		cout<<char(223);
	cout<<char(223);
}
void chonnutqlnhom()
{
	gotoxy(74,2);
	cout<<char(220);
	for (int i=0;i<7;i++)
		cout<<char(220);
	cout<<char(220);
	gotoxy(74,3);
	cout<<char(221)<<"QL nhom"<<char(222);
	gotoxy(74,4);
	cout<<char(223);
	for (int i=0;i<7;i++)
		cout<<char(223);
	cout<<char(223);
}
//PHAN GIAO DIEN



//CODE CHÍNH


struct Contact {
    string name;
    string phoneNumber;
    Contact* next;  
};
Contact* phonebook[SIZE];


Contact* Hienthitimkiem[SIZE];
struct lichsu{
	string thoigian;
	string luachon;
	string tenlienhe;
	string sodt;
	string newdata;
};
lichsu lichsu[100];



struct Contact2 {//struct của nhom
    string name;
    string phoneNumber;

    Contact2(const string& n, const string& phone) : name(n), phoneNumber(phone) {}
};
struct Group{
    string name;
    vector<Contact2> contacts;  // Danh sách các tên liên hệ trong nhóm
    vector<Group> subgroups;//Danh sach nhom con

    Group(const string& n) : name(n) {}

    void addContact(const Contact2& contact) {
        contacts.push_back(contact);
    }
};
Group groupA("NHOM LIEN HE: ");


int hashFunction(string ten)
{   
    int sum = 0;
    int n=ten.size();
    for (int i=0; i<n; i++)
        {
    	sum=sum+(int)ten[i];
        }
    return sum % SIZE;
}
void addContact(string ten, string sdt) 
{	
 	int index=hashFunction(ten);
     	//tach lay ten

    Contact* newContact = new Contact();//Khoi tao con tro moi
    newContact->name = ten;
    newContact->phoneNumber = sdt;
    newContact->next = NULL; // 

    if (phonebook[index] == NULL) {	// Neu ô dó chua có gia tri
        phonebook[index] = newContact;
    } else {		// N?u ô dã có m?c, thêm mot node moi voo sao cuoi
        Contact* current = phonebook[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newContact;
    }
    
    
    luuvaonhatki("Luu ten lien he",ten,sdt,"");//luu vao lich su
}
void savePhonebookToFile(string ten, string sdt) 
{
    int index = hashFunction(ten);
     Contact* newContact = new Contact();//Khoi tao con tro moi
    newContact->name = ten;
    newContact->phoneNumber = sdt;
    ofstream file("phonebook.txt",ios::in | ios::app );
    if (file.is_open()) {
         
                file << newContact->name << "," << newContact->phoneNumber << endl;
    
        
        file.close();
        daluutenlienhe();//Thong bao da luu thanh cong
    } else {
        cout << "Khong the mo file." << endl;
    }
}
void savePhonebookToFile2(string ten, string sdt) 
{
    int index = hashFunction(ten);
     Contact* newContact = new Contact();//Khoi tao con tro moi
    newContact->name = ten;
    newContact->phoneNumber = sdt;
    ofstream file("phonebook.txt",ios::in | ios::app );
    if (file.is_open()) {
         
                file << newContact->name << "," << newContact->phoneNumber << endl;
    
        
        file.close();
        daluutenlienhe2();//Thong bao da luu thanh cong
    } else {
        cout << "Khong the mo file." << endl;
    }
}
	
void xulidong(string line)
{
    string chuoi1;
    string chuoi2;

    // Khoi tao bien dem và chi so cho vòng l?p
    int i = 0;
    int vi_tri_dau = 0;

    // Duyet qua chuoi g?c
    while (i < line.length()) 
	{
        // Neu gap dau phay, tách chuoi và cap nhat vi tri vat dau cho chuoi tiep theo
        if (line[i] == ',') 
		{
            chuoi1 = line.substr(vi_tri_dau, i - vi_tri_dau);
            vi_tri_dau = i + 1;
        }
        i++;
    }
    	// Lay phan con lai cua chuoi cho vào chuoi2
    chuoi2 = line.substr(vi_tri_dau);
    addContactdauvao(chuoi1,chuoi2); 
}	
void addContactdauvao(string ten,string sdt)
{
	int index=hashFunction(ten);
     	//tach lay ten

    Contact* newContact = new Contact();//Khoi tao con tro moi
    newContact->name = ten;
    newContact->phoneNumber = sdt;
    newContact->next = NULL; // 

    if (phonebook[index] == NULL) {	// Neu ô dó chua có gia tri
        phonebook[index] = newContact;
    } else {		// N?u ô dã có m?c, thêm mot node moi voo sao cuoi
        Contact* current = phonebook[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newContact;
    }
}

void loaddulieuvaoHash()
{
	ifstream file("phonebook.txt"); // Vao duong dan file

    if (file.is_open()) {
        string line;
        while (getline(file, line))
        {
			xulidong(line);//xu li dòng do
	    }
        file.close();
    } else 
	{
        cout << "Khong the mo file." << endl;
    }
    	
}
	
void searchContactByName(const string& substring, int& soluongten,int& i) 
{
    int k = 0;
    int l = 0;

    for (int m = 0; m < SIZE; m++) 
	{
        Contact* current = phonebook[m];
        while (current != NULL) {
            size_t found = current->name.find(substring);
            if (found != string::npos) {
                Hienthitimkiem[l] = current;
                l++;
                k++;
                goto repeat;
            }
        repeat:
            current = current->next;
        }
    }

    if (k == 0)
    {
     gotoxy(33, 7);
        cout << "Khong tim thay ten lien he!!!";
        i=1;
    }
    else {
        for (int i = 0; i < l; i++) {
            gotoxy(33, 6 + i);
            cout << Hienthitimkiem[i]->name;
            gotoxy(53, 6 + i);
            cout << Hienthitimkiem[i]->phoneNumber;
        }
    }
    soluongten=l;
}

 	

Contact* searchContactByPhoneNumber(const string& sdt) 
{
    for (int i = 0; i < SIZE; i++) {
        Contact* current = phonebook[i];//tao con tro moi tai index do
        while (current != NULL) 
		{
            if (current->phoneNumber == sdt) {
                return current; // Tr? v? con tr? d?n m?c có s? di?n tho?i tuong ?ng
            }
            current = current->next;
        }
    }
    return NULL; // Không tìm th?y m?c có s? di?n tho?i tuong ?ng
}

void displayPhonebook() 
{
	khungdisplayPhonebook();
    Contact DShienthi[SIZE];
    int j=0;//tong so luong gia tri trong mang(bat dau tu 0 / de ko can duyet het)
    for (int i = 0; i < SIZE; i++) {
        Contact* current = phonebook[i];
        while (current != NULL) 
        {
            DShienthi[j].name=current->name;
            DShienthi[j].phoneNumber=current->phoneNumber;
            j++;
            current = current->next;
        }
    }
    
    
    
     for (int i = 0; i < j-1; ++i) //Sap xep lai
        for (int k=i+1;k<j;k++)
     {
         if(DShienthi[i].name >DShienthi[k].name)
         {
            Contact f=DShienthi[i];
            DShienthi[i]=DShienthi[k];
            DShienthi[k]=f;
         }
    }
    
    for (int i = 0; i < j; ++i) //Xuat
    {
    gotoxy(35,13+i);
    cout<<DShienthi[i].name;
    gotoxy(57,13+i);
	cout<<DShienthi[i].phoneNumber;
    }

}
void bangthongtin(int j,string& tenluachon)
{
//Khung		
	gotoxy(65,1);
		cout<<char(218);
	for (int i=0;i<31;i++)
	cout<<char(196);
	cout<<char(191);
	gotoxy(65,2);
		cout<<char(124);
	gotoxy(65,3);
		cout<<char(124);
	gotoxy(65,4);
		cout<<char(124);
	gotoxy(65,5);
	cout<<char(124);
	gotoxy(65,6);
		cout<<char(124);
	gotoxy(65,7);
		cout<<char(124);
	gotoxy(65,8);
		cout<<char(124);
	gotoxy(65,9);
		cout<<char(124);
	gotoxy(65,10);
		cout<<char(192);
	for (int i=0;i<31;i++)
	cout<<char(196);
	cout<<char(217);
		
	gotoxy(97,2);
		cout<<char(124);
	gotoxy(97,3);
		cout<<char(124);
	gotoxy(97,4);
		cout<<char(124);
	gotoxy(97,5);
	cout<<char(124);
	gotoxy(97,6);
		cout<<char(124);
	gotoxy(97,7);
		cout<<char(124);
	gotoxy(97,8);
		cout<<char(124);
	gotoxy(97,9);
		cout<<char(124);
	addnutsuaten();
	addnutsuasdt();
	addnutxoa();

	
//Khung
	 
        thongtinHoten(Hienthitimkiem[j]->name);
        
        
        //hien thi so dien thoai khi biet chinh xac ten
        int index = hashFunction(Hienthitimkiem[j]->name);
    Contact* current = phonebook[index];
      	while (current != NULL) 
		  {
        	if (current->name == Hienthitimkiem[j]->name) 
        {
        	gotoxy(67,3);
            cout<<"So dien thoai: "<<current->phoneNumber; // Tra ve con tro d?n m?c có tên tuong ung
        }
        current = current->next;
    	}
    	gotoxy(67,4);
    	cout<<"Dia chi: ";
    	
    	tenluachon=Hienthitimkiem[j]->name;
        
}
void thongtinHoten(string hoTen)
{
    string A,B;
    int viTriKhoangTrangDauTien = hoTen.find(' '); // Tìm vi trí cua khoang trang dau tiên

    // Neu không tìm thay khoang trang, mac dinh ten la toa bo chuoi, ho rong~
    if (viTriKhoangTrangDauTien !=string::npos) {
                size_t viTriKhoangTrangCuoiCung = hoTen.find_last_of(' ');
        A= hoTen.substr(0, viTriKhoangTrangCuoiCung); // H?
        B=hoTen.substr(viTriKhoangTrangCuoiCung + 1, hoTen.length() - viTriKhoangTrangCuoiCung); // Tên
    } else 
    {
        B=hoTen; // Ðua toàn bo chuoi vào vector neu không có khoang trang
    }
    gotoxy(67,2);
    cout<<"Ho: "<<A<<"    "<<"Ten: "<<B;
}
void thaydoiten(string tenluachon,string a)
{
	string b;
	int index = hashFunction(tenluachon);
    Contact* current = phonebook[index];
      	while (current != NULL) 
		  {
        	if (current->name == tenluachon) 
        	{
        	current->name=a;//Doi ten truc tiep node do	(ban luu ngoai chua doi)
        	b=current->phoneNumber;//Lay thong tin de luu
        	}
        current = current->next;
    	}
    xoatentrongdanhba(tenluachon,b);//Xoa ten ban luu ngoai de luu ten moi
    savePhonebookToFile2(a,b);//luu theo ham cu
    luuvaonhatki("Thay doi ten ",tenluachon,b,a);//luu vao lich su
}
void thaydoiso(string tenluachon,string a)
{
	string b;
	for (int i = 0; i < SIZE; i++) {
    Contact* current = phonebook[i];
      	while (current != NULL) 
		  {
        	if (current->name == tenluachon) 
        	{
        	b=current->phoneNumber;//dùng de xoa du'ng ten trong ham xoa
        	current->phoneNumber=a;//doi truc tiep trong mang 
        	}
        current = current->next;
    	}
    }
	xoatentrongdanhba(tenluachon,b);//Xoa ten ban luu ngoai de luu ten moi
    savePhonebookToFile2(tenluachon,a);//luu theo ham cu~
        luuvaonhatki("Thay doi so ",tenluachon,b,a);//luu vao lich su

}
void xoaso(string tenluachon)
{
	string b;
	for (int m = 0; m < SIZE; m++) {
		
        Contact* current = phonebook[m];
        Contact* previous = NULL;

        while (current != NULL) {
            if (current->name == tenluachon) {
            	b=current->phoneNumber;//dùng de xoa du'ng ten trong ham xoa
                if (previous == NULL) {
                    // Neu liên he can xóa là liên he dau tiên trong danh sách liên ket,
                    // cap nhat con tro dau danh sách liên ket
                    phonebook[m] = current->next;
                } else {
                    // Neu liên he can xóa không phai là liên he dau tiên,
                    // cap nhat con tro cua liên he truoc dó de bo qua liên he can xóa
                    previous->next = current->next;
                }

                delete current; // Giai phóng bo nho
                goto repeat;
            }

        repeat:
            previous = current;
            current = current->next;
        }
    }
    xoatentrongdanhba(tenluachon,b);
    luuvaonhatki("Xoa lien he",tenluachon,b,"");//luu vao lich su

}
void xoatentrongdanhba(string tenluachon,string so)
{
	string chuoixoa=tenluachon+","+so;//se ra chinh xac hang de can xoa gom ten+sdt
	ifstream fileIn("phonebook.txt");

    // Kiem tra xem file có mo thành công không
    if (!fileIn.is_open()) {
        cerr << "Không th? m? file." << endl;
        return;
    }

    // Vector de lýu truoc noi dung cac file
    vector<string> lines;

    // Ð?c t?ng d?ng t? file và lýu vào vector
    string line;
    while (getline(fileIn, line)) {
        lines.push_back(line);
    }

    // Ðóng file doc
    fileIn.close();

    // Mo file de ghi
    ofstream fileOut("phonebook.txt");

    // Kiem tra xem file có m? thành công không
    if (!fileOut.is_open()) {
        cerr << "Không th? m? file." << std::endl;
        return;
    }

    // Ghi lai các dong không chua chuoi can xóa
    for (int i = 0; i < lines.size(); ++i) {
        if (lines[i].find(chuoixoa) == string::npos){
            fileOut << lines[i] << endl;
        }
    }

    // Ðóng file ghi
    fileOut.close();
}
void luuvaonhatki(string phuongthuc,string ten,string sdt,string moi)
{
	 // thoi gian hien tai tính theo he thong
   time_t now = time(0);
   
   // convert sang string
   char* timehientai = ctime(&now);
   
	int i=0;
	while(lichsu[i].luachon!="")
	{
		i++;
	}
	lichsu[i].luachon=phuongthuc;
	lichsu[i].tenlienhe=ten;
	lichsu[i].sodt=sdt;
	lichsu[i].thoigian=timehientai;
	if(moi=="")
		lichsu[i].newdata="";
	else
	lichsu[i].newdata="thanh: << "+moi+" >>";
}
void hienlichsu()
{
	int i=0;
	int l=0;//dinh dang vi tri
	while(lichsu[i].luachon!="")
	{
		gotoxy(5,10+l);
		cout<<lichsu[i].thoigian;
		gotoxy(35,10+l);
		cout<<"* "<<lichsu[i].luachon<<" *";
		gotoxy(60,10+l);
		cout<<lichsu[i].tenlienhe<<" "<<char(196)<<char(196)<<" "<<lichsu[i].sodt;
		gotoxy(65,10+l+1);
		cout<<lichsu[i].newdata;
		i++;
		
		l=l+2;//dinh dang vi tri
	}
}
void displayGroup(const Group& group, int depth = 0) 
{
    for (int i = 0; i < depth; ++i) {
        cout << "  ";
    }
    cout << group.name << endl;

    for (const auto& contact : group.contacts) {
        for (int i = 0; i < depth + 1; ++i) {
            cout << "  ";
        }
        cout << "Contact: " << contact.name << ", Phone: " << contact.phoneNumber << endl;
    }

    for (const auto& subgroup : group.subgroups) {
        displayGroup(subgroup, depth + 1);
    }
}
//CODE CHÍNH
int main()
{
    int choice;
    loaddulieuvaoHash();//load du lieu vao lai Hash
	SetWindowSize(110,50);
	cout<<"\t\t\t\t\t-------DANH BA-------"<<endl;
	cout<<endl;
	addavatar();
	Loading();
	system("cls");	
	hiendanhba();
	addavatar();
	addnutbanphim();
	addnutganday();
	addnutdanhba();
	ShowCur(0);
	int k=0;
	luachonnutbanphim();// cho con tro o chon nut ban phim
	string tenluachon;
	luachon:
	while(1)
	{
		if(_kbhit())
		{
			char c=_getch();
			system("cls");
			cout<<"\t\t\t\t\t-------DANH BA-------"<<endl;
			cout<<"\n";
			addtheme();
			if(c==-32)
			{	
				c=_getch();
				if(c==77)// mui ten phai de qua phai
					k=k+1;
				if(c==75)// mui ten trai de qua trai
					k=k-1;
				if(k>2) // reset ve neu qua nut
					k=0;
				if(k<0)// reset ve neu qua nut
					k=2;
				if(k==0)
				{
					luachonnutbanphim();
					if(c==72)//an vo nut ban phim
					{
							system("cls");
							hiendanhba();
							addnutbanphim();
							addnutganday();
							addnutdanhba();
							hienbanphim();//ban phim 12345.....
							khungnhapsdt();//Khung nhap sdt trong ban phim
							gotoxy(32,6);
							string sdt;
						    cout<<"Nhap so dien thoai: ";
    						getline(cin,sdt);
    						Contact* foundContact =searchContactByPhoneNumber(sdt);//Kiem tra ten da luu chua bang so dien thoai
    						if (foundContact != NULL) {
    						gotoxy(37,8);
    						cout<< foundContact->name<<"\t"<< foundContact->phoneNumber << endl;//Khi co se hien len
							} 
							else 
							{// Chua co ten lien he thi se nhap
							string ten;
							gotoxy(32,7);
    						cout<<"Nhap ten lien he: ";
    						getline(cin,ten);
    						addContact(ten,sdt);
    						savePhonebookToFile(ten,sdt);
							}													
					}			
				}
				if(k==1)
				{
					luachonnutganday();
					if(c==72)//an vo nut 
					{
					system("cls");
					hiendanhba();
					addnutbanphim();
					addnutganday();
					addnutdanhba();
					nutlichsu();
					nutqlnhom();
					while(1)
					{
						if(_kbhit())
						{
							char c=_getch();
							if(c==-32)
							{	
								c=_getch();
								if(c==75)// mui ten trai de qua trai
									k=k-1;
									k=0;
								if(k<0)// reset ve neu qua nut
									k=1;
								if(k==0)
								{
									chonnutlichsu();
									nutqlnhom();
									if(c==72)//an nut len de chon nut lich su
									{		
										hienlichsu();	
										chonnutqlnhom();
										nutlichsu();		
									}
								}
								if(k==1)
								{
									nutlichsu();
									chonnutqlnhom();
									if(c==72)//an nut len de chon nut qlnhom
									{		
    									displayGroup(groupA);
										//xua trinh cac nhom
								}
							
							
							}
						}
					}
				}
			}
				if(k==2)
				{
					luachonnutdanhba();
					if (c==72)// an vao nut danh ba
					{
							system("cls");
							hiendanhba();
							addnutbanphim();
							addnutganday();
							addnutdanhba();
    						displayPhonebook();
    						gotoxy(30,4);
    						cout<<"Nhap ten lien he: ";
    						string ten2;
    						int q;
    						int soluongten;//so luong hien ra de lua chon chinh sua
    						getline(cin,ten2);
    						searchContactByName(ten2,soluongten,q);
    						if (q==1)//Bien kiem tra co tim thay ten hay ko
    							goto luachon;
    						gotoxy(34,6);
    						/////////option chinh sua ten
    						int vitri=0;
    						while(1)
    						if(_kbhit())
							{
							c=_getch();
    						if(c==-32)
							{
							int i;	
								c=_getch();
    								if(c==80)// mui ten phai de qua xuong
										k=k+1;
									if(c==72)// mui ten trai de qua le
										k=k-1;
									if(k>soluongten-1) // reset ve neu qua nut
										k=0;
									if(k<0)// reset ve neu qua nut
										k=soluongten-1;
									for (i=0; i<soluongten;i++)
                                        {
                                            if(k==i)
                                            {
                                                gotoxy(30,vitri);
                                                cout<<char(32)<<char(32);
                                                gotoxy(30,6+i);
                                                vitri=6+i;
                                                cout<<">>";
                                            }
                                        }
                                    if (c==77)
                                    {
                                    	int j=0;
                                    	khungaddnhom();
                                    	khungsuathongtin();
                                    	while(1)
    									if(_kbhit())
										{
										c=_getch();
    									if(c==-32)
										{
										int i;	
										c=_getch();
    									if(c==80)// mui ten phai de qua xuong
											j=j+1;
										if(c==72)// mui ten trai de qua le
											j=j-1;
										if(j>1) // reset ve neu qua nut
											j=0;
										if(j<0)// reset ve neu qua nut
											j=1;
										if(j==0)
										{
											chonaddnhom();
                                    		khungsuathongtin();
										}
										if(j==1)
										{
											khungaddnhom();
                                    		chonsuathongtin();
                                    		if(c==77)//chon sua thong tin
                                    		{
                                    			an2nut();
                                    			bangthongtin(k,tenluachon);//lay ra ten tim kiem
                                        		while(1)
    											{
    											if(_kbhit())
    												{
    												c=_getch();
    												if(c==-32)
    													{	
    													c=_getch();
    													if(c==77)// mui ten phai de qua phai
    														k=k+1;
    													if(c==75)// mui ten trai de qua trai
    														k=k-1;
    													if(k>2) // reset ve neu qua nut
    														k=0;
    													if(k<0)// reset ve neu qua nut
    														k=2;
    													if(k==0)
    														{
    				    									chonsuaten();
    				    									addnutsuasdt();
    														addnutxoa();
    														if(c==72)//bam lên de chon
    															{
    															gotoxy(67,8);
    															string a;
    															cout<<"Nhap ten moi: ";
    															getline(cin,a);
    															thaydoiten(tenluachon,a);
    															goto luachon;
    															}
    														}
    													if (k==1)
    														{
    														addnutsuaten();
    				    									chonsuasdt();
    				    									addnutxoa();
    				    									if(c==72)//bam lên de chon
    															{
    															gotoxy(67,8);
    															string a;
    															cout<<"Nhap so moi: ";
    															getline(cin,a);
    															thaydoiso(tenluachon,a);
    															goto luachon;
    															}
    														}
    													if(k==2)
    														{
    				   										chonxoa();
    				   										addnutsuaten();	
    														addnutsuasdt();
    															if(c==72)//bam lên de chon
    															{
    															xoaso(tenluachon);
    															daluutenlienhe2();//chi lay bang tb thanh cong															
    															goto luachon;
    															}
    														}
    													}		
                                        			}
                                     
    										
        										}
                                    		}
										}
										    
    							}
    						}	
    						////////option khi chon ten
    						}
					}
				}
			}
					
				if(c==80)// mui ten xuong de thoat
					{
					cout<<"Ban da thoat!!!";	
					exit(1);
					}
				
				}
			}
		}
		}
	}
	
