/*                                █                                  
                                 ███                                 
                                ██  █                                
                               ██ ████                               
                              ██  █   █                              
                             ██ ████ ███                             
                            ██  █    █  █                            
                           ██ ████  ██████                           
                          ██  █   ███     █                          
                         ██ ████ ██  █   ███                         
                        ██  █    █ ████ ██  █                        
                       ██ ████  ██ █    █ ████                       
                      ██  █   ███  ██  ██ █   █                      
                     ██ ████ ██  ███ ███  ██ ███                     
                    ██  █    █ ███   █  ███  █  █                    
                   ██ ████  ██ █  █ █████  ███████                   
                  ██  █   ███  ████ █    ███      █                  
                 ██ ████ ██  ███    ██  ██  █    ███                 
                ██  █    █ ███  █  ██ ███ ████  ██  █                
               ██ ████  ██ █  ██████  █   █   ███ ████               
              ██  █   ███  ████     ████ ███ ██   █   █              
             ██ ████ ██  ███   █   ██    █   █ █ ███ ███             
            ██  █    █ ███  █ ███ ██ █  ███ ██ █ █   █  █            
           ██ ████  ██ █  ███ █   █  ████   █  █ ██ ██████           
          ██  █   ███  ████   ██ █████   █ █████ █  █     █          
         ██ ████ ██  ███   █ ██  █    █ ██ █     █████   ███         
        ██  █    █ ███  █ ██ █ ████  ██ █  ██   ██    █ ██  █        
       ██ ████  ██ █  ███ █  █ █   ███  ████ █ ██ █  ██ █ ████       
      ██  █   ███  ████   ████ ██ ██  ███    █ █  ████  █ █   █      
     ██ ████ ██  ███   █ ██    █  █ ███  █  ██ ████   ███ ██ ███     
    ██  █    █ ███  █ ██ █ █  █████ █  ██████  █   █ ██   █  █  █    
   ██ ████  ██ █  ███ █  █ ████     ████     ████ ██ █ █ █████████   
  ██  █   ███  ████   ████ █   █   ██   █   ██    █  █ █ █        █  
 ██ ████ ██  ███   █ ██    ██ ███ ██ █ ███ ██ █  █████ █ ██      ███ 
██  █    █ ███  █ ██ █ █  ██  █   █  █ █   █  ████     █ █ █    ██  █
                can a pattern figure out the rule?
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define pb push_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
#define F first
#define S second
#define vll vector<ll>
#define fin(i,n1,n2) for(int i=n1;i<n2;i++)
#define nif(i,n1,n2) for(int i=n1;i>n2;i--)
#define all(x) x.begin(),x.end()
#define m69 998244353
#define m420 1000000007
void spit(auto x){for(auto e:x)cout<<e<<" ";cout<<endl;}
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)) && 1)

struct fraction{
    ll num;
    ll den;
    ll gcd(ll a,ll b){
        return (!a&&!b?1:__gcd(abs(a),abs(b)));
    }
    fraction(){
        num=1;
        den=1;
    }
    fraction(pair<ll,ll> a){
        ll g=gcd(a.F,a.S);
        num=a.F/g;
        den=a.S/g;
        if(den<0){
            num*=-1;
            den*=-1;
        }
    }
    fraction inv(){
        fraction res;
        res.num=den;
        res.den=num;
        if(res.den<0){
            res.num*=-1;
            res.den*=-1;
        }
        return res;
    }
    fraction operator + (fraction a){
        fraction res;
        res.num=(num*a.den+a.num*den);
        res.den=den*a.den;
        ll g=gcd(res.num,res.den);
        res.num/=g;
        res.den/=g;
        if(res.den<0){
            res.num*=-1;
            res.den*=-1;
        }
        return res;
    }
    fraction operator - (fraction a){
        fraction self;
        self.num=num,self.den=den;
        a.num*=-1;
        return self+a;
    }
    fraction operator * (fraction a){
        fraction res;
        res.num=num*a.num;
        res.den=den*a.den;
        ll g=gcd(res.num,res.den);
        res.num/=g;
        res.den/=g;
        if(res.den<0){
            res.num*=-1;
            res.den*=-1;
        }
        return res;
    }
    fraction operator / (fraction a){
        fraction self;
        self.num=num,self.den=den;
        fraction res=a.inv()*self;
        return res;
    }
    void print() const{
        cout<<num<<"/"<<den;
    }
};
bool operator <(const fraction& l, const fraction& r) {
     return l.num*r.den<l.den*r.num;
};
bool operator >(const fraction& l, const fraction& r) {
     return l.num*r.den>l.den*r.num;
};
bool operator ==(const fraction& l, const fraction& r) {
     return l.num*r.den==l.den*r.num;
};

struct point{
    fraction X;
    fraction Y;
    point(){
        X=fraction({0,1});
        Y=fraction({0,1});
    }
    point(ll a,ll b){
        X=fraction({a,1});
        Y=fraction({b,1});
    }
    point(fraction a,fraction b){
        X=a;
        Y=b;
    }
    point(fraction a,ll b){
        X=a;
        Y=fraction({b,1});
    }
    point(ll a,fraction b){
        X=fraction({a,1});
        Y=b;
    }
    point(pair<ll,ll> p){
        X=fraction({p.F,1});
        Y=fraction({p.S,1});
    }
    void print() const{
        cout<<"{";
        X.print();
        cout<<" ";
        Y.print();
        cout<<"}"<<endl;
    }
};
bool operator <(const point& l, const point& r) {
    if(l.X==r.X)
        return l.Y<r.Y;
    return l.X<r.X;
};
bool operator >(const point& l, const point& r) {
    if(l.X==r.X)
        return l.Y>r.Y;
    return l.X>r.X;
};
bool operator ==(const point& l, const point& r) {
     return (l.X==r.X && l.Y==r.Y);
};

struct line{
    fraction slope;
    point X_intercept;
    point Y_intercept;

    line(){
        slope=fraction({0,1});
        X_intercept=point(0,0);
        Y_intercept=point(0,0);
    }
    line(pair<ll,ll> p1,pair<ll,ll> p2){
        line(point(p1),point(p2));
    }
    line(point p1,point p2){
        fraction num=p1.Y-p2.Y;
        fraction den=p1.X-p2.X;
        slope=num/den;
        if(slope.den==0) {
            if(slope.num<0)
                slope.num*=-1;
            Y_intercept.X=fraction({0,1});
            Y_intercept.Y=fraction({1,0});
            X_intercept.X=p1.X;
            X_intercept.Y=fraction({0,1});
        } else {
            Y_intercept.X=fraction({0,1});
            X_intercept.Y=fraction({0,1});
            Y_intercept.Y=p1.Y-slope*p1.X;
            X_intercept.X=fraction({0,1})-Y_intercept.Y/slope;
        }
    }
    void print(){
        if(slope.den==0){
            cout<<"X = ";
            X_intercept.X.print();
            cout<<endl;      
        } else {
            cout<<"Y = ";
            slope.print();
            cout<<" * X + ";
            Y_intercept.Y.print();
            cout<<endl;
        }
    }
    fraction getX(fraction yy){
        if(slope.den==0)
            return X_intercept.X;
        return (yy-Y_intercept.Y)/slope;
    }
    fraction getY(fraction xx){
        return slope*xx + Y_intercept.Y;
    }
    point intersect(line L){
        point res;
        if(L.slope.den==0||slope.den==0){
            if(slope.den==0){
                res.X=X_intercept.X;
                res.Y=L.slope*res.X+L.Y_intercept.Y;
            } else {
                res.X=L.X_intercept.X;
                res.Y=slope*res.X+Y_intercept.Y;
            }
        } else {
            res.X=(L.Y_intercept.Y-Y_intercept.Y)/(slope-L.slope);
            res.Y=slope*res.X+Y_intercept.Y;
        }
        return res;
    }
};
bool operator <(const line& l, const line& r){
    if(l.slope==r.slope){
        if(l.slope.den!=0)
            return l.Y_intercept<r.Y_intercept;
        else
            return l.X_intercept<r.X_intercept;
    }
    return l.slope<r.slope;
}
bool operator >(const line& l, const line& r){
    if(l.slope==r.slope){
        if(l.slope.den!=0)
            return l.Y_intercept>r.Y_intercept;
        else
            return l.X_intercept>r.X_intercept;
    }
    return l.slope>r.slope;
}
bool operator ==(const line& l, const line& r){
    return l.slope==r.slope && l.X_intercept==r.X_intercept 
            && l.Y_intercept==r.Y_intercept;
}

bool testLine(){
    cout<<"LINE TEST"<<endl;
    vector<vector<ll>> tc={
        {0,0,1,1},
        {4,3,5,6},
        {0,0,5,0},
        {7,8,9,11},
        {0,0,0,0},
        {1,2,3,4},
        {1,0,99,88},
        {12,12,1,1},
        {5,7,9,7},
        {1,2,1,9},
        {0,1,1,0}
    };
    for(auto test:tc){
        spit(test);
        line A(point(test[0],test[1]),point(test[2],test[3]));
        A.print();
        cout<<endl;
    }
    return true;
}
bool testIntersec(){
    cout<<"INTERSECTION TEST"<<endl;
    vector<vll> tc={
        {4,3,3,4,5,1,9,1},
        {0,1,8,1,2,7,2,9},
        {0,1,1,0,0,0,1,1},
        {-1733,-98233,-12323,226,-1733,-98233,-12323,-226},
        {12,256,9,18,123,-196,-122,-99},
        {-1 ,0 ,0 ,1,1 ,0 ,-1, 0},
        {4, 3, 3, 7,12 ,256, 9, 18},
    };
    for(auto test:tc){
        line A(point(test[0],test[1]),point(test[2],test[3]));
        line B(point(test[4],test[5]),point(test[6],test[7]));
        A.print();
        B.print();
        A.intersect(B).print();
        cout<<endl;
    }
}
bool testFrac(){
    cout<<"FRACTION TEST"<<endl;
    vector<vll> tc={
        {1,1,1,1},
        {3 ,4 ,5, 6},
        {232, 1 ,1 ,232},
        {-1733 ,-98233, -12323, -226},
        {1 ,0, 0, 1},
        {-1 ,0 ,0 ,1},
        {1 ,0 ,-1, 0},
        {4, 3, 3, 7},
        {12 ,256, 9, 18},
        {123, -196, -122, -99},
    };
    for(auto test:tc){
        fraction f1({test[0],test[1]});
        fraction f2({test[2],test[3]});
        cout<<"[ ";
        f1.print();
        cout<<" ";
        f2.print();
        cout<<" ]: ";
        (f1+f2).print();
        cout<<" ";
        (f1-f2).print();
        cout<<" ";
        (f1*f2).print();
        cout<<" ";
        (f1/f2).print();
        cout<<endl;
    }
}

int32_t main() {
    testFrac();
    testLine();
    testIntersec();
}