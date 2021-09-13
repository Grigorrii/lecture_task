#include "mystring.h"

MyString::MyString() : size(0), buffer(NULL) {};

MyString::MyString(const MyString& s){
    size = s.size;
    if (size==0)buffer=NULL;
    else{
        buffer = new char[size];
        for(unsigned int i = 0; i<size;i++) buffer[i]=s.buffer[i];
    }
}

MyString::MyString(const char * cs){
    size = 0;
    unsigned i;
    while(cs[size]!='\0')size++;
    buffer = new char[size];
    for(i = 0; i<size;i++) buffer[i]=cs[i];
}

MyString::~MyString(){
    size = 0;
    delete [] buffer;
}
size_t MyString::length() const
{
    return size-1;
}
void MyString::clear(){
    if (size>0) delete [] buffer;
    size = 1;
    buffer = new char[size];
    buffer[0]='\0';
}
MyString& MyString::add(const MyString& s){
    MyString str;
    str+=s;
    *this = str;
    return *this;
}
MyString& MyString::add(const char* cs){
    *this+=cs;
    return *this;
}

MyString& MyString::operator=(const MyString& s)
{
unsigned i;
size=s.size;
delete [] buffer;
buffer=new char[size];
for(i=0;i<(size-1);i++)buffer[i]=s.buffer[i];
buffer[size-1]='\0';
return *this;
}

MyString& MyString::operator=(const char* cs)
{
unsigned i,j;
for(i=0;cs[i]!='\0';i++);
size=i+1;
delete [] buffer;
buffer=new char[size];
for(j=0;j<(size-1);j++)buffer[j]=cs[j];
buffer[i]='\0';
return *this;
}

MyString& MyString::operator=(const char& c)
{
unsigned i;
delete [] buffer;
buffer=new char[1+1];
for(i=0;i<1;i++)buffer[i]=c;
buffer[i]='\0';
return *this;
}

MyString& MyString::operator+=(const MyString& s)
{
int sz=s.size+size-1;
unsigned i,j,k;
char* str=new char[sz];
for(i=0;i<sz-1;i++)str[i]=buffer[i];
for(j=0;j<s.length();j++)str[j+sz-1]=s.buffer[j];
delete [] buffer;
size=sz;
buffer=new char[size];
for(k=0;k<size;k++)buffer[k]=str[k];
return *this;
}

MyString& MyString::operator+=(const char* cs)
{
unsigned i,j,k,l;
for(i=0;cs[i]!='\0';i++);
char *str=new char[size+i];
for(l=0;l<size-1;l++)str[l]=buffer[l];
for(j=0;j<=i;j++)
str[size+j-1]=cs[j];
delete [] buffer;
buffer=new char[size+i];
for(k=0;k<(size+i);k++)buffer[k]=str[k];
size+=i;
return *this;
}

MyString& MyString::operator+=(const char& c)
{
unsigned i,k,sz=sz+1;
char* str=new char[sz];
for(i=0;i<(size-1);i++)
str[i]=buffer[i];
delete [] buffer;
buffer=new char[sz];
size=sz;
for(k=0;k<(sz-2);k++)
buffer[k]=str[k];
buffer[sz-2]=c;
buffer[sz-1]='\0';
return *this;
}
istream& operator>> ( istream& is, MyString& s )
{
    getline(is,s);
    return is;
}

istream& getline ( istream& is, MyString& s)
{
  s.clear();
  char ch=getchar();
    while(ch != '\0'){
    s.push_back(ch);
    ch=getchar();
    }
    return is;
}

ostream& operator<< ( ostream& os, const MyString& s )
{
  for (unsigned i = 0 ; i < s.size ; i++)os << s.buffer[i];
    return os;
}

int MyString::compare(const char* cs) const
{
MyString str(cs);
return this->compare(str);
}


int MyString::compare(const MyString& s) const
{
unsigned i,j;
int compare;
bool less=1;
bool greater=1;
bool equal=1;
if(size!=s.size)
equal=0;
else
for(i=0;i<s.size;i++)
{
if(buffer[i]!=s.buffer[i])
equal=0;
}
for(i=0,j=0;j<s.length();i++,j++)
{
if(buffer[i]>=s.buffer[j])
less=0;
}
if(less||equal)
greater=0;
if(less)
compare=-1;
if(greater)
compare=1;
if(equal)
compare=0;
return compare;
}


void MyString :: push_back ( const char& c )
{
  unsigned pre = size;
  expandMem(1);
  buffer[pre] = c;
}

void MyString :: expandMem ( const size_t& n )
{
  unsigned exp = n+size;
  char *temp = new char[exp+1];
  memset(temp, 0, exp+1);
  temp[exp] = '\0';
  for(unsigned i=0;i<size;i++)
  temp[i] = buffer[i];
  clear();
  size = exp;
  buffer = new char[size+1];
  memset(buffer, 0, size+1);
  buffer[size] = '\0';
  for(unsigned i = 0;temp[i]!='\0';i++)
  buffer[i] = temp[i];
  delete[] temp;
  temp = NULL;
}
