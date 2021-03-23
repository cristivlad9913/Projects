#include <iostream>
#include <vector>
using namespace std;


class Car
{
protected:

    int nr;
public:
   virtual void read(istream &in)=0;
   virtual void write(ostream &out)=0;
   friend istream & operator>>(istream &in,Car &p)
   {
       p.read(in);
       return in;
   }
   friend ostream & operator<<(ostream &out,Car &p)
   {
       p.write(out);
       return out;
   }
};


class Coupe:public Car
{
    private:
        string carName;
    string description;
    int horsePower;

public:
Coupe(string,string,int);
   virtual ~Coupe();
Coupe& operator=(Coupe &p);
    virtual void read(istream &in);
    virtual void write(ostream &out);
    friend istream& operator>>(istream&,Coupe&);
    friend ostream& operator<<(ostream&,Coupe&);
};


Coupe::Coupe(string a="",string b="",int c=0)
{
    carName=a;
description=b;
horsePower=c;
}



void Coupe::read(istream &in)
{
    string a,b;
    int hp;
    cin.get();
    cout<<"Coupe name: ";
    getline(in,b);
    carName=b;
    cout<<"Description of the Coupe car: ";
    getline(in,a);
     description=a;
    cout<<"Horsepower: ";
    cin>>hp;
    horsePower=hp;
}


void Coupe::write(ostream &out)
{
    out<<"Name: "<<carName<<endl;
    out<<"Description: "<<description<<endl;
    out<<"Horsepower: "<<horsePower<<endl;
}

Coupe& Coupe :: operator=(Coupe &p)
{
    if(this!=&p)
    {
        carName=p.carName;
        description=p.description;
        horsePower=p.horsePower;
    }
    return *this;
}

Coupe::~Coupe()
{

}

istream& operator>>(istream&in,Coupe&p)
{
    p.read(in);
    return in;
}
ostream& operator<<(ostream&out,Coupe&p)
{
    p.write(out);
    return out;
}


class HH:public Car
{
    private:
        string carName;
string description;
int horsePower;

public:
HH(string,string,int);
   virtual ~HH();
HH& operator=(HH &p);
    virtual void read(istream &in);
    virtual void write(ostream &out);
    friend istream& operator>>(istream&,HH&);
    friend ostream& operator<<(ostream&,HH&);
};
HH::HH(string a="",string b="",int c=0)
{
carName=a;
description=b;
horsePower=c;
}



void HH::read(istream &in)
{
    string a;
    int hp;
    cin.get();
cout<<"HH name: ";getline(in,a);
carName=a;
    cout<<"Description of the HH car: ";
    getline(in,a);
    description=a;
    cout<<"Horsepower: ";
    in>>hp;
    horsePower=hp;
}


void HH::write(ostream &out)
{
    out<<"Name: "<<carName<<endl;
    out<<"Description: "<<description<<endl;
    out<<"Horsepower: "<<horsePower<<endl;
}

HH& HH :: operator=(HH &p)
{
    if(this!=&p)
    {   carName=p.carName;
        description=p.description;
        horsePower=p.horsePower;
    }
    return *this;
}

HH::~HH()
{

}
istream& operator>>(istream&in,HH&p)
{
    p.read(in);
    return in;
}
ostream& operator<<(ostream&out,HH&p)
{
    p.write(out);
    return out;
}


class Cabrio:public Car
{
    private:
        string carName;
string description;
int horsePower;

public:
Cabrio(string,string,int);
   virtual ~Cabrio();
Cabrio& operator=(Cabrio &p);
    virtual void read(istream &in);
    virtual void write(ostream &out);
    friend istream& operator>>(istream&,Cabrio&);
    friend ostream& operator<<(ostream&,Cabrio&);
};
Cabrio::Cabrio(string a="",string b="",int c=0)
{
    carName=a;
description=b;
horsePower=c;
}



void Cabrio::read(istream &in)
{
    string a;
    int hp;
    cin.get();
    cout<<"Cabrio name: ";
    getline(in,a);
    carName=a;
    cout<<"Description of the Cabrio car: ";
    getline(in,a);
    description=a;
    cout<<"Horsepower: ";
    cin>>hp;
    horsePower=hp;
}


void Cabrio::write(ostream &out)
{
    out<<"Name: "<<carName<<endl;
    out<<"Description: "<<description<<endl;
    out<<"Horsepower: "<<horsePower<<endl;
}

Cabrio& Cabrio :: operator=(Cabrio &p)
{
    if(this!=&p)
    {   carName=p.carName;
        description=p.description;
        horsePower=p.horsePower;
    }
    return *this;
}

Cabrio::~Cabrio()
{

}
istream& operator>>(istream&in,Cabrio&p)
{
    p.read(in);
    return in;
}
ostream& operator<<(ostream&out,Cabrio&p)
{
    p.write(out);
    return out;
}





template <class t> class superSport
{
private:
    t cars_number;
    string carName;
    string description;
    t cars_sold;
public:
    superSport()
    {
        cars_number=0;
        carName="";
        description="";
        cars_sold=0;
    }
    superSport(const superSport &p )
    {
        cars_number=p.cars_number;
        carName=p.carName;
        description=p.description;
        cars_sold=p.cars_sold;
    }
    t set_cars_number(t x)
    {
        cars_number+=x;
    }
    t get_cars_number()
    {
        return cars_number;
    }
   t set_cars_sold(t x)
    {
       cars_sold=x;
    }

    t get_cars_sold()
    {
        return cars_sold;
    }



    void write(ostream &out)
    {
        out<<"There are "<<cars_number<<" supersport cars"<<endl;
        out<<"There are "<<cars_sold<<" supersport cars sold"<<endl;
    }
    friend ostream &operator<<(ostream &out,superSport &p)
    {
        p.write(out);
        return out;
    }

};

template <> class superSport<int>
{
private:
    int cars_number;
    string carName;
    string description;
    int cars_sold;
public:
    superSport()
    {
        cars_number=0;
        carName="";
        description="";
        cars_sold=0;
    }
    superSport(const superSport &p)
    {
        cars_number=p.cars_number;
    }
   void set_cars_number(int a)
    {
        cars_number+=a;
    }
    void set_cars_sold(int a)
    {
        cars_sold=a;
    }


    int get_cars_number() const
    {
        return cars_number;
    }
    int get_cars_sold() const
    {
        return cars_sold;
    }

  void write(ostream &out)
    {
        out<<"There are "<<cars_number<<" supersport cars left"<<endl;
        out<<"There are "<<cars_sold<<" supersport cars sold"<<endl;
    }
    friend ostream &operator<<(ostream &out,superSport &p)
    {
        p.write(out);
        return out;
    }



};
template <class t> class Exposition
{
private:
  superSport < int > p;
    static int nr_cars;
    int n;
    t **v;
    vector<pair<string,int>> dataCar;

public:
    Exposition(int n=0)
    {
        n=n;
        v=new t*[n];
    }
    Exposition(Exposition &a)
{
    delete[] v;
    n=a.n;
    v=a.v;
}
    Exposition(const Exposition &p)
    {
        delete v;
        n=p.n;
        v=new Car*[n];
        for(int i=0;i<n;i++)
            v[i]=p.v[i];

    }
    ~Exposition()
    {
        delete[] v;
        n=0;
    }
    void add_car(int i)
    {   static int cs=0;
        string type;
        prob4:
        try
        {
        cout<<"Type of the car: coupe/hh/cabrio/supersport "<<i+1<<": ";cin>>type;
        if(type=="coupe")
        {
            v[i]=new Coupe;
            cin>>*v[i];
        }
        else
            if(type=="hh")
        {
            v[i]=new HH;
            cin>>*v[i];
        }
        else
            if(type=="cabrio")
        {
            v[i]=new Cabrio;
            cin>>*v[i];
        }
        else
            if(type=="supersport")
        {
            v[i]=NULL;
            string name;
            int price;
            int sold;
            cin.get();
            cout<<"Supersport name: ";getline(cin,name);

            cout<<"Supersport price: ";cin>>price;
            prob1:
            try{
        cout<<"You want to buy this car? (1=yes, 0=no):  ";cin>>sold;

              if(sold==1)
               {

                    dataCar.push_back(make_pair(name,-1));
                    cs++;
                    cout<<"This car has been sold!"<<endl;
               }
            else
                if(sold==0)
                {
                    dataCar.push_back(make_pair(name,price));
                    p.set_cars_number(1);
                    cout<<"This car hasn't been sold!"<<endl;
                }
                else throw sold;
            }
            catch(int sold)
            {
                cout<<"Sold must be 1/0!"<<endl;
                goto prob1;
            }
        }
        else throw type;
        }
        catch (string type)
        {
        cout<<endl;
        cout<<"Please write coupe/hh/cabrio/supersport with small caps!"<<endl;
            goto prob4;
        }
        if(i==n-1)
        {
            p.set_cars_sold(cs);

        }
}

        void read(istream &in)
           {
               prob2:
        try
        {
           cout<<"Write numbers of cars you want to read: ";cin>>n;
           if(n<=0)
            throw n;
        }
        catch(int n)
        {
            cout<<"Number of cars must be positive!"<<endl;
            goto prob2;
        }


        delete[] v;
        v=new t*[n];
        for(int i=0;i<n;i++)
        {
            add_car(i);
            nr_cars++;
        }
           }

    void write(ostream &out)
    {
        vector<pair<string,int>>:: iterator iter=dataCar.begin(); //doar de frumusete
        for(int i=0;i<n;i++)
        {
            if(dynamic_cast<Coupe*> (v[i])!=NULL)
            {
                cout<<"Car "<<i+1<<" type: Coupe"<<endl<<*v[i]<<endl;
                cout<<"------------"<<endl;
            }
        else
            if(dynamic_cast<HH*> (v[i])!=NULL)
        {
          cout<<"Car "<<i+1<<" type: HH"<<endl<<*v[i]<<endl;
           cout<<"------------"<<endl;
        }
        else
            if(dynamic_cast<Cabrio *>(v[i])!=NULL)
            {cout<<"Car "<<i+1<<" type: Cabrio"<<endl<<*v[i]<<endl;
             cout<<"------------"<<endl;
             }
     else
        {

             cout<<"Car number: "<<i+1<<" type: supersport"<<endl;


                  cout<<"Name:" <<dataCar[i].first<<endl;
             cout<<"Price:" <<dataCar[i].second<<endl;


              cout<<"------------"<<endl;

        }

    }

     cout<<"Cars that have been bought:"<<endl;
    for(int j=0; j<dataCar.size()+1; j++)
        if(dataCar[j].second==-1)
        cout<<"->"<<dataCar[j].first<<endl;

        cout<<p;
    }
    friend istream& operator>>(istream& in,Exposition &a)
    {
        a.read(in);
        return in;
    }
    friend ostream& operator<<(ostream &out,Exposition &a)
    {

     a.write(out);
     return out;
    }
};
template <class t>  int Exposition<t>::nr_cars=0;


void menu_output()
{


    cout<<"\t\t Pascu Cristian Vlad grupa 211 proiect 3 tema 5"<<endl<<endl<<endl;
    cout<<"Please write car type with low caps"<<endl<<endl;
    Exposition<Car> *p=new Exposition <Car>;
     cin>>*p;
     cout<<endl<<endl;
     cout<<"All cars: "<<endl<<endl;
     cout<<*p;
}
int main()
{
menu_output();
    return 0;
}
