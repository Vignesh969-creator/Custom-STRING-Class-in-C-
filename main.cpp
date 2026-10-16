#include <iostream>
#include <cstring>
using namespace std;
class STRING{
char*str;
	public:
		STRING(){
			str=new char[0];
		}
		STRING(const char*p){
			int len=0;
			const char*s=p;
			while(*s){
				len++;
				s++;
			}
		str=new char[len+1];
		my_strcpy(str,p);	
		}
		STRING(const STRING &a){
		int len=0;
		char*s=a.str;
		while(*s){
			s++;
			len++;
		}			
		str=new char[len+1];
		my_strcpy(str,a.str);
		}
		
	STRING  operator=(STRING& a){
				
		char*p=a.str;
		if(str!=0){
		delete [] str;
		str=0;

		}
		int len=0;
		while(*p){
			p++;
			len++;
		}
		str=new char[len+1];
		my_strcpy(str,a.str);
		return a;	
	}

	void  operator =(const char *p){
		if(str!=0){
			delete [] str;
			str=0;
		}
		str=new char[strlen(p)+1];
		my_strcpy(str,p);

	}
	~STRING(){
		if(str!=nullptr){
			delete [] str;
			str=0;
		}
	
	}		

		
	void getdata(){
		cout<<str<<endl;
	}
	
	STRING operator +(STRING &a){
		int len1=0,len2=0;
		char*p=a.str;
		while(*p){
			len1++;
			p++;
		}
		p=str;
		while(*p){
		p++;
		len2++;
		}
		
		p=new char [len1+len2+1];
		my_strcat(p,str);
		my_strcat(p,a.str);
	 	static STRING  s(p);
		delete [] p;	
		 return s;
		
	
	}
	STRING& operator +(const char *p){
		int len1=0,len2=0;
		const char*q=p;
		while(*q){
			len1++;
			q++;
		}
		q=str;
		while(*q){
		len2++;
		q++;
		}
		static STRING s;
	//	cout<<sizeof(s.str)<<endl;	
		s.str=new char[len1+len2+1];
		my_strcat(s.str,str);
		my_strcat(s.str,p);
		return s;
	}
	char& operator [](int i){
		return str[i];
	}
		
	friend istream& operator >> (istream & ,const STRING &);	
	friend ostream& operator <<(ostream &o,const STRING &);
	friend STRING& operator +(const char*,STRING&);
	bool operator==(const STRING&a){
		int b=0;
		b=my_strcmp(str,a.str);
		if(b!=0)
			return 0;
		return 1;
	}
	bool operator <(const STRING &a){
		char*p=a.str,*q=str;
		while(1){
			int b=*p-*q;
			if(b>0)
				return 1;
			else if(b==0){
				q++;
				p++;
			}else{

			return 0;
		}
		}	
	}


	bool operator >(const STRING &a){
		char*p=a.str,*q=str;
		while(1){
			int b=*q-*p;
			if(b>0)
				return 1;
			else if(b==0){
				q++;
				p++;
			}else{

			return 0;
		}
		}	
	}
	
	bool operator >=(const STRING &a){
		char*p=a.str,*q=str;
		while(*p){
			int b=*q-*p;
			if(b>0){
				return 1;
			}else if(b==0){
					q++;
					p++;
			}else{
			return 0;
			}
				
		}
		if(*q-*p==0)
			return 1;
		else if(*q-*p>0){
			return 1;
		}else{
		return 0;
		}

	}


	bool operator <=(const STRING &a){
		char*p=a.str,*q=str;
		while(*p){
			int b=*p-*q;
			if(b>0){
				return 1;
			}else if(b==0){
					q++;
					p++;
			}else{
			return 0;
			}
				
		}
		if(*p-*q==0)
			return 1;
		else if(*p-*q>0){
			return 1;
		}else{
		return 0;
		}

	}
	bool operator !=(const STRING &a){
		char*p=a.str,*q=str;
		while(*p){
			int b=*p-*q;
			if(b>0 || b<0){
				return 1;
			}else if(b==0){
				q++;
				p++;
			}
		}
		if(*p-*q==0)
			return 0;
		return 1;

	}
	
	int my_strcmp(char*S1,char*S2){
		int ans=0;
		while(*S1){
			if(*S1-*S2!=0){
				return *S1-*S2;
			}
		S1++;
		S2++;	
		}
		return *S1-*S2;
	}
	void my_strcpy(char*D,const char*S){
		while(*D++=*S++);
	}
	void my_strcat(char*D,const char*S){
		while(*D)
			D++;
		while(*D++=*S++);

	}

	friend void strrev(STRING &);
	friend void strupr(STRING&);	
	friend void strlwr(STRING&);
	friend int strlen(STRING&);
	friend void strcpy(STRING&,STRING&);
	friend int strcmp(STRING&,STRING&);
	friend char*strchr(STRING&,char);
	friend char*strrchr(STRING&,char);
	friend void strcat(STRING&,STRING&);
	friend void strncpy(STRING&,STRING&,int);
	friend int strncmp(STRING&,STRING&,int);
	friend void strncat(STRING&,STRING&,int);
	friend char*strstr(STRING&,const char*);
};

void my_strcat(char*D,const char*S){
		while(*D)
			D++;
		while(*D++=*S++);

}
void my_strcpy(char*D,char*S){
	while(*D++=*S++);
}
STRING& operator + (const char*p,STRING&a){
static STRING s;
s.str=new char[strlen(p)+strlen(a.str)+1];
char*q=a.str;
char*t=s.str;
strcpy(t,p);
my_strcat(t,a.str);
return s;
}


char*strstr(STRING&S,const char *s){
		
return strstr(S.str,s);

}

void my_strncat(char*D,char*S,int c){
while(*D){
D++;
}
while(c && *S){
*D=*S;
D++;
S++;
c--;
}
*D='\0';
}

void strncat(STRING&S,STRING&D,int c){
char*p=new char[strlen(S.str)+1];
my_strcpy(p,S.str);
if(S.str!=0){
delete [] S.str;
S.str=0;

}
S.str=new char[strlen(p)+c+1];
my_strcpy(S.str,p);
//strncat(S.str,D.str,c);
my_strncat(S.str,D.str,c);
delete p;
}

int strncmp(STRING&S1,STRING&S2,int c){
char*p=S1.str,*q=S2.str;
while(*p && c){
int ans=*p-*q;
	if(ans!=0)	
		return ans;
c--;
p++;
q++;

}
if(c==0)
	return 0;
int ans=*p-*q;
return ans;



}
void strncpy(STRING&D,STRING&S,int c){
if(D.str!=0){
delete []  D.str;
D.str=0;
}
int i=0,j=0;
D.str=new char[c+1];
char*p=S.str,*q=D.str;
while(*p && c){
q[i]=p[j];
i++;
j++;
c--;
}
q[i]='\0';

}

void strcat(STRING&D,STRING&S){
int len1=strlen(D.str);
char*p=new char[len1+1];
my_strcpy(p,D.str);
	if(D.str!=0){
		delete [] D.str;
		D.str=0;
	}
int len2=strlen(S.str);
D.str=new char[len1+len2+1];
my_strcpy(D.str,p);
my_strcat(D.str,S.str);
delete [] p;
}


char*strrchr(STRING&S,char ch){
char*p=S.str;
int len=strlen(S);
int i=len-1;
while(i>=0){
	if(p[i]==ch){
		return &p[i];
	}
i--;

}
cout<<"Char not found"<<endl;
return 0;
}
char*strchr(STRING&S,char ch){
char*p=S.str;
while(*p){
if(*p==ch){
	return p;
}
p++;
}
cout<<"Char nor present"<<endl;
return 0;
}
int strcmp(STRING&s1,STRING&s2){
char*p=s1.str,*q=s2.str;
while(*p){
	int ans=*p-*q;
	if(ans!=0)
		return ans;
p++;
q++;
}
int ans=*p-*q;
if(ans==0)
	return 0;
return ans;

}

void strcpy(STRING&s,STRING&d){
	char*p=s.str;
	if(p!=0){
		delete [] p;
		p=0;	
	}
	int len=strlen(d);
	s.str=new char[len+1];
	p=s.str;
	char*q=d.str;
	while(*q){
	*p=*q;
	p++;
	q++;

	}
	*p=*q;


}


void strrev(STRING &s){
char*p=s.str;
char*q=s.str;
while(*q)
	q++;
q=q-1;
while(p<q){
char temp=*p;
*p=*q;
*q=temp;
p++;
q--;
}
}
void strupr(STRING& s){
char*p=s.str;
while(*p){
if(*p>='a' && *p<='z')
	*p^=32;
p++;
}


}

void strlwr(STRING& s){
char*p=s.str;
while(*p){
if(*p>='A' && *p<='Z')
	*p^=32;
p++;
}
}

int strlen(STRING& s){
int len=0;
char*p=s.str;
while(*p){
	p++;
	len++;
}

return len;
}

istream& operator >>(istream &i,const STRING &a){
char*p=new char[3000];
i>>p;
int len=0;
if(a.str!=nullptr){
	delete [] a.str;
	a.str=0;
}
a.str=new char[strlen(p)+1];
strcpy(a.str,p);
delete [] p;
return i;
}
ostream& operator<<(ostream &o,const STRING &a){
cout<<a.str;

}

int main(){

STRING S1;//default constructor
STRING S2("Hello"); //parameterized constructor
STRING S3("World"); //parameterized constructor
STRING S4(S3); //copy constructor

cout<<"S1:"<<S1<<endl;
cout<<"S2:"<<S2<<endl;
cout<<"S3:"<<S3<<endl;
cout<<"S4:"<<S4<<endl;

//Assignment operator
STRING S5=S4;
cout<<"S5:"<<S5<<endl;




//Addition operator
STRING S6=S2+S3;
STRING S7="hello" +S3;
STRING S8=S2+"world";
cout<<"S6:"<<S6<<endl;
cout<<"S7:"<<S7<<endl;
cout<<"S8:"<<S8<<endl;


//subscript operator

cout<<"Subscript operator:"<<S2[0]<<endl;
cout<<"Subscript operator:"<<S3[2]<<endl;


// Input and output
STRING s7;
cout<<"Enter a string:";
cin>>s7;
cout<<"You entered:"<< s7 << endl;

// Comparison operators
STRING a("Apple");
STRING b("Banana");

cout << "\nComparison Operators:" << endl;
cout << "a == b: " << (a == b) << endl;
cout << "a != b: " << (a != b) << endl;
cout << "a > b: " << (a > b) << endl;
cout << "a < b: " << (a < b) << endl;
cout << "a >= b: " << (a >= b) << endl;
cout << "a <= b: " << (a <= b) << endl;

// strcpy
STRING c;
strcpy(c, S2);
cout << "strcpy(c, S2): " << c << endl;

// strncpy
strncpy(c, S3, 3);
cout << "strncpy(c, S3, 3): " << c << endl;

// strcmp
cout << "\nstrcmp(a, b): " << strcmp(a, b) << endl;

// strncmp
cout << "strncmp(a, b, 2): " << strncmp(a, b, 2) << endl;

// strcat
STRING d("Good");
STRING e("Morning");
strcat(d, e);
cout << "strcat(d, e): " << d << endl;

// strncat
STRING f("Hello");
STRING g("World");
strncat(f, g, 3);
cout << "strncat(f, g, 3): " << f << endl;

// strrev
STRING h("Embedded");
strrev(h);
cout << "strrev(h): " << h << endl;

// strupr
STRING i("hello");
strupr(i);
cout << "strupr(i): " << i << endl;

// strlwr
STRING j("HELLO");
strlwr(j);
cout << "strlwr(j): " << j << endl;

// strchr
STRING k("Programming");
cout << "strchr(k, 'g'): " << strchr(k, 'g') << endl;

// strrchr
cout << "strrchr(k, 'g'): " << strrchr(k, 'g') << endl;

// strstr
cout << "strstr(k, \"gram\"): "<< strstr(k, "gram") << endl;

// strlen
cout << "strlen(k): " << strlen(k) << endl;

}
