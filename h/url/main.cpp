#include<iostream>
#include<memory>
#include<string>
#include<algorithm>
#include<map>
#include<utility>

using namespace std;



class Database
{
    map<int,pair<string,string>> db;            // name , id, shorten_url
    public:
    void Update_db(string name , int id , string url)
    {
        pair<string,string> user_details;
        user_details = make_pair(name,url);
        db[id] = user_details;
    }
    bool check(int id)
    {
        if(db.find(id) != db.end())
        {
            cout<<"url already present : ";
            return true;
        }
        return false;
    }
};


class Generate
{
    public:
        virtual string generate_url(string name ,int id){};
        virtual int extract_url(string name ,string url){};
        virtual ~Generate() {}

};

class ShortUrl:public Generate
{
    // vector<int> 
    public:
        string generate_url(string name,int n) override
        {
            Database db;
            if(db.check(n))
            {
                cout<<"Already present"<<endl;
                return "";
            }

            char alphaMap[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef""ghijklmnopqrstuvwxyz0123456789";
            string url;
            while (n > 0) { 
                // converting urlID to url
                url.push_back(alphaMap[n%62]);
                n /= 62;
            }
            reverse(url.begin(), url.end());
            url  =  "https//ash_url/" + url;
            
            db.Update_db(name,n,url);

            return url;
        }
};

class ExtractId:public Generate
{
    public:
    // virtual string generate_url(string name, string shortURL) override = 0;
        int extract_url(string name ,string shortURL) override
        {
            Database db;
            size_t urlID = 0; 
           
                for (size_t i=0; i < shortURL.size(); i++) {
                    // if char is in between A and Z
                    if ('A' <= shortURL[i] && shortURL[i] <= 'Z')
                        urlID = urlID*62 + shortURL[i] - 'A';
                    // if char is in between a and z (till 26 we have A to Z)
                    if ('a' <= shortURL[i] && shortURL[i] <= 'z')
                        urlID = urlID*62 + shortURL[i] - 'a' + 26;
                    
                    // if char is in between 0 and 9 (till 52 we have a to b)
                    if ('0' <= shortURL[i] && shortURL[i] <= '9')
                        urlID = urlID*62 + shortURL[i] - '0' + 52;
                }

                if(db.check(urlID))
                {
                    cout<<"Url already present"<<endl;
                    return 0;
                }
                db.Update_db(name,urlID,shortURL);
            

            
            
            return urlID;
        }
        
};



int main()
{
    string name ;
    cout <<"Enter your name : ";
    cin>>name;
    cout<<"\n\n";
    int n ;
    cout<<"Enter what you want "<<endl;
    cout<<"1->generate url\n2->extract id"<<endl;
    cin>>n;


    string url = "";

    Generate* function_btn=nullptr;

    if(n==1)
    {
        int id;
        cout<<"Enter your id to generate url"<<endl;
        cin>>id;
        function_btn = new ShortUrl;
        url = function_btn->generate_url(name,n);
        cout<<"Your url : "<<url<<endl;
    }
    else if(n==2)
    {
        string your_url = "";
        cout<<"ENter your url : ";
        cin>>your_url;
        cout<<endl;
        int your_id = 0;
        function_btn = new ExtractId;
        your_id = function_btn->extract_url(name,your_url);
        cout<<"Your id : "<<your_id<<endl;
    }

    delete function_btn;
    return 0;
}