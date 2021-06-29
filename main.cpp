#include <iostream>
#include <string>
#include <string.h>
#define SIZE 10
#define LL long long
LL TRANS_ID=201901419;
using namespace std;

//This is the structure for containing all information about product
struct ITEM_INFO
{
    LL id;
    string name;
    float rate;
    int quantity;
};

//It is the node of hash table which represents a particular product
struct PRODUCT_LIST
{
    LL prod_id;
    string prod_name;
    float prod_rate;
    int prod_quantity;
    PRODUCT_LIST *next;
};



//THIS IS THE DATA SET OF PRODUCTS AVALIABLE IN INVENTORY
ITEM_INFO DATA[100]= {
{111100000001,"product_1",100,20},{111100000002,"product_2",110,20},{111100000003,"product_3",120,20},{111100000004,"product_4",130,20},{111100000005,"product_5",140,20},{111100000006,"product_6",150,20},{111100000007,"product_7",160,20},{111100000008,"product_8",170,20},{111100000009,"product_9",180,20},{111100000010,"product_10",190,20},
{111100000011,"product_11",200,20},{111100000012,"product_12",210,20},{111100000013,"product_13",220,20},{111100000014,"product_14",230,20},{111100000015,"product_15",240,20},{111100000016,"product_16",250,20},{111100000017,"product_17",260,20},{111100000018,"product_18",270,20},{111100000019,"product_19",280,20},{111100000020,"product_20",290,20},
{111100000021,"product_21",300,20},{111100000022,"product_22",310,20},{111100000023,"product_23",320,20},{111100000024,"product_24",330,20},{111100000025,"product_25",340,20},{111100000026,"product_26",350,20},{111100000027,"product_27",360,20},{111100000028,"product_28",370,20},{111100000029,"product_29",380,20},{111100000030,"product_30",390,20},
{111100000031,"product_31",400,20},{111100000032,"product_32",410,20},{111100000033,"product_33",420,20},{111100000034,"product_34",430,20},{111100000035,"product_35",440,20},{111100000036,"product_36",450,20},{111100000037,"product_37",460,20},{111100000038,"product_38",470,20},{111100000039,"product_39",480,20},{111100000040,"product_40",490,20},
{111100000041,"product_41",500,20},{111100000042,"product_42",510,20},{111100000043,"product_43",520,20},{111100000044,"product_44",530,20},{111100000045,"product_45",540,20},{111100000046,"product_46",550,20},{111100000047,"product_47",560,20},{111100000048,"product_48",570,20},{111100000049,"product_49",580,20},{222200001111,"product_50",590,20},
{222200001114,"product_51",600,20},{222200001117,"product_52",610,20},{222200001120,"product_53",620,20},{222200001123,"product_54",630,20},{222200001126,"product_55",640,20},{222200001129,"product_56",650,20},{222200001132,"product_57",660,20},{222200001135,"product_58",670,20},{222200001138,"product_59",680,20},{222200001141,"product_60",690,20},
{222200001144,"product_61",700,20},{222200001147,"product_62",710,20},{222200001150,"product_63",720,20},{222200001153,"product_64",730,20},{222200001156,"product_65",740,20},{222200001159,"product_66",750,20},{222200001162,"product_67",760,20},{222200001165,"product_68",770,20},{222200001168,"product_69",780,20},{222200001171,"product_70",790,20},
{222200001174,"product_71",800,20},{222200001177,"product_72",810,20},{222200001180,"product_73",820,20},{222200001183,"product_74",830,20},{222200001186,"product_75",840,20},{222200001189,"product_76",850,20},{222200001192,"product_77",860,20},{222200001195,"product_78",870,20},{222200001198,"product_79",880,20},{222200001201,"product_80",890,20},
{222200001204,"product_81",900,20},{222200001207,"product_82",910,20},{222200001210,"product_83",920,20},{222200001213,"product_84",930,20},{222200001216,"product_85",940,20},{222200001219,"product_86",950,20},{222200001222,"product_87",960,20},{222200001225,"product_88",970,20},{222200001228,"product_89",980,20},{222200001231,"product_90",990,20},
{222200001234,"product_91",1000,20},{222200001237,"product_92",1010,20},{222200001240,"product_93",1020,20},{222200001243,"product_94",1030,20},{222200001246,"product_95",1040,20},{222200001249,"product_96",1050,20},{222200001252,"product_97",1060,20},{222200001255,"product_98",1070,20},{222200001258,"product_99",1080,20},{222200001261,"product_100",1090,20}
};






class INVENTORY
{
    private:
        //DECLARATION IS STATIC BECAUSE WHEN WE INHERIT THIS INVENTORY IN OTHER CLASSES
        //WE WANT THE SAME DATASET OF ITEMS NOT DIFFERENT COPIES
        static PRODUCT_LIST **PRODUCTS;

    public:

        //Constructor for predefining the values
        INVENTORY()
        {
            PRODUCTS=new PRODUCT_LIST*[SIZE];
            int i=0;
            while(i<SIZE)
            {
                PRODUCTS[i]=NULL;
                i++;
            }
        }
        //THIS FUNCTION IS FOR GETTING ALL INFORMATION OF ITEM IT IS SIMILAR TO GET_PRODUCT_INFO
        PRODUCT_LIST *SEARCH_PRODUCT_INFO(LL id)
        {
            int index=id%SIZE;
            PRODUCT_LIST *p=PRODUCTS[index];
            if(p==NULL)
            {
                return NULL;
            }
            else
            {
                while(p!=NULL)
                {
                    if(p->prod_id==id)
                    {
                        return p;
                    }
                    p=p->next;
                }
                return NULL;
            }
        }


        //THIS FUNCTION IS FOR SEARCHING THE ID OF PRODUCT IN INVENTORY
        bool SEARCH_PRODUCT(LL id)
        {
            int index=id%SIZE;
            PRODUCT_LIST *p=PRODUCTS[index];

            if(p==NULL)
                return false;
            else
            {
                while(p!=NULL)
                {
                    if(p->prod_id==id)
                    {
                        return true;
                    }
                    p=p->next;
                }
                return false;
            }
        }



        //It is the function for adding the new product
        void ADD_PRODUCTS(ITEM_INFO var)
        {
            LL temp_id=var.id;
            int index=(temp_id)%SIZE;
            PRODUCT_LIST *p=PRODUCTS[index];
            PRODUCT_LIST *new_item=NULL;

            if(p==NULL)
            {
                new_item=new PRODUCT_LIST;
                new_item->prod_id=var.id;
                new_item->prod_name=var.name;
                new_item->prod_rate=var.rate;
                new_item->prod_quantity=var.quantity;
                new_item->next=NULL;
                PRODUCTS[index]=new_item;
            }
            else
            {
                while(p->next!=NULL)
                {
                    p=p->next;
                }
                new_item=new PRODUCT_LIST;
                new_item->prod_id=var.id;
                new_item->prod_name=var.name;
                new_item->prod_rate=var.rate;
                new_item->prod_quantity=var.quantity;
                new_item->next=NULL;
                p->next=new_item;
            }
        }

        //THIS METHOD IS FOR DELETING THE PRODUCT
        int DELETE_PRODUCT(LL Id)
        {
            int index=Id%SIZE;
            PRODUCT_LIST *p=PRODUCTS[index];
            PRODUCT_LIST *prev=NULL;
            bool check=SEARCH_PRODUCT(Id);

            if(check==true)
            {
                if(p->prod_id==Id && p->next==NULL)
                {
                    PRODUCTS[index]=NULL;
                }
                else
                {
                    while( p!=NULL && p->next!=NULL && p->prod_id!=Id)
                    {
                        prev=p;
                        p=p->next;
                    }
                    prev->next=p->next;
                }
            }
            else
            {
                cout<<"Invalid id";
                return 0;
            }
        }


        //THIS IS FOR UPDATING THE ITEM INFORMATION OF ANY PRODUCT
        void UPDATE_ITEM_INFO(LL id)
        {
            PRODUCT_LIST *ITEM=SEARCH_PRODUCT_INFO(id);
            int n;

            if(ITEM!=NULL)
            {
                cout<<"What you want to update "<<endl;
                cout<<"Press 1 for deleting the product :"<<endl;
                cout<<"Press 2 for changing the name of product "<<endl;
                cout<<"Press 3 for changing the rate of product: "<<endl;
                cout<<"Press 4 for changing the quantity of product :"<<endl;
                cout<<"Press 5 for exit :"<<endl;

                cin>>n;
                while(n!=5)
                {
                    if(n==1)
                    {
                        DELETE_PRODUCT(id);
                    }
                    else if(n==2)
                    {
                        string New_name;
                        cout<<"Enter the new name :"<<endl;
                        cin>>New_name;
                        ITEM->prod_name=New_name;
                    }
                    else if(n==3)
                    {
                        float new_rate;
                        cout<<"Enter the new Rate :"<<endl;
                        cin>>new_rate;
                        ITEM->prod_rate=new_rate;
                    }
                    else if(n==4)
                    {
                        int new_quan;
                        cout<<"Enter the new Quantity "<<endl;
                        cin>>new_quan;
                        ITEM->prod_quantity=new_quan;
                    }
                    cin>>n;
                }
            }
            else
            {
                cout<<"Invalid product id "<<endl;
            }
        }

        //This will show the whole database
        void SHOW_DATABASE()
        {
            int i=0;
            PRODUCT_LIST *p=NULL;
            while(i<10)
            {
                p=PRODUCTS[i];
                while(p!=NULL)
                {
                    cout<<p->prod_id<<"  "<<p->prod_name<<"  "<<p->prod_rate<<"  "<<p->prod_quantity<<endl;
                    p=p->next;
                }
                p=NULL;
                i++;
            }
        }


        //STOCK UPDATION
        void UPDATE_INVENTORY_STOCK(LL item_id,int Quantity)
        {
            PRODUCT_LIST *p=SEARCH_PRODUCT_INFO(item_id);
            if(p!=NULL)
            {
                p->prod_quantity = p->prod_quantity - Quantity;
            }
        }

        //THIS IS FOR DISPLAYING THE UPDATED INVENTORY
        void SHOW_INVENTORY_DETAIL(LL item_id)
        {
            PRODUCT_LIST *p=SEARCH_PRODUCT_INFO(item_id);
            cout<<"ITEM ID"<<"             "<<"ITEM NAME"<<"        "<<"ITEM RATE"<<"        "<<"ITEM QUANTITY"<<endl;
            if(p!=NULL)
            {
                cout<<p->prod_id<<"        "<<p->prod_name<<"        "<<p->prod_rate<<"             "<<p->prod_quantity<<endl;
            }
        }

};
//ASSIGNING THE MEMORY TO STATIC VARIABLE PRODUCTS
PRODUCT_LIST** INVENTORY::PRODUCTS;

class MANAGER:public INVENTORY
{
    private:
        LL MANAGER_ID;
        string MANAGER_NAME;

    public:
        //MAKING THE CONSTRUCTOR
        MANAGER()
        {
            MANAGER_ID=201901419;
            MANAGER_NAME="DHAIRYA";
        }

        //THIS METHOD IS FOR ADDING NEW PRODUCT IN INVENTORY DATABASE
        void ADD_NEW_PRODUCT_IN_INVENTORY()
        {
            ITEM_INFO var;

            cout<<"Enter the product ID of new product:"<<endl;
            cin>>var.id;

            cout<<"Enter the name of product :"<<endl;
            cin>>var.name;

            cout<<"Enter the rate of product :"<<endl;
            cin>>var.rate;

            cout<<"Enter the quantity of product :"<<endl;
            cin>>var.quantity;

            ADD_PRODUCTS(var);
        }

};

//THIS IS THE STRUCTURE FOR STORING THE CUSTOMER DATA
struct CUSTOMER_INFO
{
    long long int custom_id;
    string custom_name;
    float point;
};

//THIS IS CUSTOMER LIST
struct CUSTOMER_LIST
{
    long long int customer_id;
    string customer_name;
    float customer_point;
    CUSTOMER_LIST *next;
};


CUSTOMER_INFO CUSTOMER_DATASET[100]={
{9400000001,"customer_1",0},{9400000002,"customer_2",0},{9400000003,"customer_3",0},{9400000004,"customer_4",0},{9400000005,"customer_5",0},{9400000006,"customer_6",0},{9400000007,"customer_7",0},{9400000008,"customer_8",0},{9400000009,"customer_9",0},{9400000010,"customer_10",0},
{9400000011,"customer_11",0},{9400000012,"customer_12",0},{9400000013,"customer_13",0},{9400000014,"customer_14",0},{9400000015,"customer_15",0},{9400000016,"customer_16",0},{9400000017,"customer_17",0},{9400000018,"customer_18",0},{9400000019,"customer_19",0},{9400000020,"customer_20",0},
{9400000021,"customer_21",0},{9400000022,"customer_22",0},{9400000023,"customer_23",0},{9400000024,"customer_24",0},{9400000025,"customer_25",0},{9400000026,"customer_26",0},{9400000027,"customer_27",0},{9400000028,"customer_28",0},{9400000029,"customer_29",0},{9400000030,"customer_30",0},
{9400000031,"customer_31",0},{9400000032,"customer_32",0},{9400000033,"customer_33",0},{9400000034,"customer_34",0},{9400000035,"customer_35",0},{9400000036,"customer_36",0},{9400000037,"customer_37",0},{9400000038,"customer_38",0},{9400000039,"customer_39",0},{9400000040,"customer_40",0},
{9400000041,"customer_41",0},{9400000042,"customer_42",0},{9400000043,"customer_43",0},{9400000044,"customer_44",0},{9400000045,"customer_45",0},{9400000046,"customer_46",0},{9400000047,"customer_47",0},{9400000048,"customer_48",0},{9400000049,"customer_49",0},{9400000050,"customer_50",0},
{9400000051,"customer_51",0},{9400000052,"customer_52",0},{9400000053,"customer_53",0},{9400000054,"customer_54",0},{9400000055,"customer_55",0},{9400000056,"customer_56",0},{9400000057,"customer_57",0},{9400000058,"customer_58",0},{9400000059,"customer_59",0},{9400000060,"customer_60",0},
{9400000061,"customer_61",0},{9400000062,"customer_62",0},{9400000063,"customer_63",0},{9400000064,"customer_64",0},{9400000065,"customer_65",0},{9400000066,"customer_66",0},{9400000067,"customer_67",0},{9400000068,"customer_68",0},{9400000069,"customer_69",0},{9400000070,"customer_70",0},
{9400000071,"customer_71",0},{9400000072,"customer_72",0},{9400000073,"customer_73",0},{9400000074,"customer_74",0},{9400000075,"customer_75",0},{9400000076,"customer_76",0},{9400000077,"customer_77",0},{9400000078,"customer_78",0},{9400000079,"customer_79",0},{9400000080,"customer_80",0},
{9400000081,"customer_81",0},{9400000082,"customer_82",0},{9400000083,"customer_83",0},{9400000084,"customer_84",0},{9400000085,"customer_85",0},{9400000086,"customer_86",0},{9400000087,"customer_87",0},{9400000088,"customer_88",0},{9400000089,"customer_89",0},{9400000090,"customer_90",0},
{9400000091,"customer_91",0},{9400000092,"customer_92",0},{9400000093,"customer_93",0},{9400000094,"customer_94",0},{9400000095,"customer_95",0},{9400000096,"customer_96",0},{9400000097,"customer_97",0},{9400000098,"customer_98",0},{9400000099,"customer_99",0},{9400000100,"customer_100",0}
};

class CUSTOMER
{
    private:
        static CUSTOMER_LIST **CUSTOMERS;

    public:
        //CONSTRUCTOR FOR CREATING A HASH TABLE OF CUSTOMERS
        CUSTOMER()
        {
            CUSTOMERS=new CUSTOMER_LIST*[SIZE];
            int i=0;
            while(i<SIZE)
            {
                CUSTOMERS[i]=NULL;
                i++;
            }
        }

        //FOR CHECKING IF THE CUSTOMER IS THERE OR NOT
        bool CHECK_CUSTOMER(long long int id)
        {
            int index=id%SIZE;
            CUSTOMER_LIST *p=CUSTOMERS[index];

            if(p==NULL)
            {
                return false;
            }
            else
            {
                while(p!=NULL)
                {
                    if(p->customer_id==id)
                    {
                        return true;
                    }
                    p=p->next;
                }
                return false;
            }
        }

        //THIS METHOD IS FOR GETTING WHOLE INFORMATION ABOUT CUSTOMER
        CUSTOMER_LIST *CUSTOMER_INFORMATION(long long int id)
        {
            int index=id%SIZE;
            CUSTOMER_LIST *cus=CUSTOMERS[index];
            if(cus==NULL)
            {
                return NULL;
            }
            else
            {
                while(cus!=NULL)
                {
                    if(cus->customer_id==id)
                    {
                        return cus;
                    }
                    cus=cus->next;
                }
                return NULL;
            }
        }

        //THIS FUNCTION IS FOR ADDING A NEW CUSTOMER
        void ADD_NEW_CUSTOMER_DATA(CUSTOMER_INFO var)
        {
            long long int id=var.custom_id;
            int index=id%SIZE;
            CUSTOMER_LIST *p=CUSTOMERS[index];
            CUSTOMER_LIST *new_customer=NULL;

            if(p==NULL)
            {
                new_customer=new CUSTOMER_LIST;
                new_customer->customer_id=var.custom_id;
                new_customer->customer_name=var.custom_name;
                new_customer->customer_point=var.point;
                new_customer->next=NULL;
                CUSTOMERS[index]=new_customer;
            }
            else
            {
                while(p->next!=NULL)
                {
                    p=p->next;
                }
                new_customer=new CUSTOMER_LIST;
                new_customer->customer_id=var.custom_id;
                new_customer->customer_name=var.custom_name;
                new_customer->customer_point=var.point;
                new_customer->next=NULL;
                p->next=new_customer;
            }
        }

        //THIS IS FOR SHOWING THE INFORMATION OF CUSTOMERS
        void SHOW_CUSTOMER_DATABASE()
        {
            int i=0;
            CUSTOMER_LIST *p=NULL;
            while(i<SIZE)
            {
                p=CUSTOMERS[i];
                while(p!=NULL)
                {
                    cout<<p->customer_id<<"   "<<p->customer_name<<"   "<<p->customer_point<<endl;
                    p=p->next;
                }
                i++;
            }
        }

        //THIS METHOD IS FOR ADDING THE POINTS IN CUSTOMER DATABASE
        void ADD_POINTS(long long int id,float Points_to_added)
        {
            CUSTOMER_LIST *p=CUSTOMER_INFORMATION(id);
            if(p!=NULL)
            {
                p->customer_point = p->customer_point + Points_to_added;
            }
        }


        //THIS METHOD IS FOR SHOWING THE CUSTOMER DETAIL AFTER BILL
        void CUSTOMER_DETAILS(LL cus_id)
        {
            CUSTOMER_LIST *cus=CUSTOMER_INFORMATION(cus_id);
            cout<<"CUSTOMER ID"<<"          "<<"CUSTOMER NAME"<< "          "<<"CUSTOMER POINTS"<<endl;
            cout<<cus->customer_id<<"         "<<cus->customer_name<<"            "<<cus->customer_point<<endl;
        }
};
//ASSIGNING THE MEMORY TO STATIC VARIABLE
CUSTOMER_LIST ** CUSTOMER::CUSTOMERS;



//THIS IS FOR REPRESENTING THE BOUGHT ITEMS IN THE FORM OF LIST
struct BOUGHT_ITEM
{
    LL BOUGHT_ITEM_ID;
    string BOUGHT_ITEM_NAME;
    float BOUGHT_ITEM_RATE;
    int BOUGHT_ITEM_QUANTITY;
    float BOUGHT_ITEM_AMMOUNT;
    BOUGHT_ITEM *next_item;
};

class BILLING:public CUSTOMER,public INVENTORY
{
    private:

        LL Transaction_ID;
        LL CUSTOMER_ID;
        float Total_Ammount;
        BOUGHT_ITEM *FIRST_ITEM;   //THIS WILL CONTAIN THE ADDRESS OF FIRST BOUGHT ITEM
        BOUGHT_ITEM *LAST_ITEM;    //THIS WILL CONTAIN THE ADRESS OF LAST BOUGHT ITEM


        //REDEFINING THE SCOPE OF INVENTORY FUNCTION IN PRIVATE SO BILLING OBJECT CAN NOT ACCESS THEM
        using INVENTORY::ADD_PRODUCTS;
        using INVENTORY::DELETE_PRODUCT;
        using INVENTORY::UPDATE_ITEM_INFO;
        using INVENTORY::SHOW_DATABASE;
        using INVENTORY::SHOW_INVENTORY_DETAIL;

    public:

        //CONSTRUCTOR
        BILLING()
        {
            Transaction_ID=TRANS_ID;    //THIS IS RANDOM TRANSACTION ID
            CUSTOMER_ID=0;
            Total_Ammount=0;
            FIRST_ITEM=NULL;
            LAST_ITEM=NULL;
        }

        //THIS IS FOR ASSIGNING THE CUSTOMER ID TO BILL
        void ASSIGN_CUSTOMER_ID(LL cus_id)
        {
            Transaction_ID = TRANS_ID;
            CUSTOMER_ID = cus_id;
        }


        //THIS METHOD IS FOR ADDING A NEW CUSTOMER IN DATA BASE
        void UPLOAD_NEW_CUSTOMER(LL id)
        {
            CUSTOMER_INFO var;
            cout<<"This customer id is new so we gonna enter it in the database :"<<endl;
            cout<<"Enter the customer name :";
            var.custom_id=id;
            var.point=0;
            cin>>var.custom_name;

            ADD_NEW_CUSTOMER_DATA(var);
        }

        //THIS IS FOR ADDING THE ITEM IN THE LIST
        int ADD_ITEM_IN_LIST(LL item_id,int quant)
        {
            PRODUCT_LIST *p=SEARCH_PRODUCT_INFO(item_id);
            if(p->prod_quantity < quant)
            {
                cout<<"This item is out of stock you have to enter another one"<<endl;
                return 0;
            }
            else
            {

                if(FIRST_ITEM==NULL)
                {
                    FIRST_ITEM=new BOUGHT_ITEM;
                    FIRST_ITEM->BOUGHT_ITEM_ID=item_id;
                    if(p!=NULL)
                    {
                        FIRST_ITEM->BOUGHT_ITEM_NAME=p->prod_name;
                        FIRST_ITEM->BOUGHT_ITEM_QUANTITY=quant;
                        FIRST_ITEM->BOUGHT_ITEM_RATE=p->prod_rate;
                        FIRST_ITEM->BOUGHT_ITEM_AMMOUNT=FIRST_ITEM->BOUGHT_ITEM_QUANTITY*FIRST_ITEM->BOUGHT_ITEM_RATE;
                        Total_Ammount = Total_Ammount + FIRST_ITEM->BOUGHT_ITEM_AMMOUNT;
                        LAST_ITEM=FIRST_ITEM;
                        FIRST_ITEM->next_item=NULL;
                    }

                }
                else
                {
                    BOUGHT_ITEM *t=FIRST_ITEM;
                    while(t)
                    {
                        if(t->BOUGHT_ITEM_ID==item_id)
                        {
                            t->BOUGHT_ITEM_QUANTITY = t->BOUGHT_ITEM_QUANTITY + quant;
                            t->BOUGHT_ITEM_AMMOUNT = t->BOUGHT_ITEM_QUANTITY *t->BOUGHT_ITEM_RATE;
                            Total_Ammount = Total_Ammount +(quant*t->BOUGHT_ITEM_RATE);
                            return 1;
                        }
                        t=t->next_item;
                    }
                    BOUGHT_ITEM *new_item=new BOUGHT_ITEM;
                    new_item->BOUGHT_ITEM_ID=item_id;
                    if(p!=NULL)
                    {
                        new_item->BOUGHT_ITEM_NAME=p->prod_name;
                        new_item->BOUGHT_ITEM_QUANTITY=quant;
                        new_item->BOUGHT_ITEM_RATE=p->prod_rate;
                        new_item->BOUGHT_ITEM_AMMOUNT=new_item->BOUGHT_ITEM_QUANTITY*new_item->BOUGHT_ITEM_RATE;
                        Total_Ammount = Total_Ammount + new_item->BOUGHT_ITEM_AMMOUNT;
                        new_item->next_item=NULL;
                        LAST_ITEM->next_item=new_item;
                        LAST_ITEM=new_item;

                    }

                }
                return 1;

            }
        }

        //THIS IS FOR BUYING THE ITEMS
        int BUY_ITEMS(LL item_id,int Quant)
        {
            return ADD_ITEM_IN_LIST(item_id,Quant);
        }


        //THIS IS FOR CANCELING ANY ITEM
        int CANCEL_ITEM(LL id,int quan,LL customer_id)
        {
            BOUGHT_ITEM *p=FIRST_ITEM;
            BOUGHT_ITEM *q=nullptr;
            float prev_amm ;

            if(p->BOUGHT_ITEM_ID==id)
            {
                prev_amm = p->BOUGHT_ITEM_AMMOUNT;
                int t=p->BOUGHT_ITEM_QUANTITY;
                p->BOUGHT_ITEM_QUANTITY = p->BOUGHT_ITEM_QUANTITY - quan;
                if(p->BOUGHT_ITEM_QUANTITY <=0)
                {
                    UPDATE_INVENTORY_STOCK(id,-t);
                    Total_Ammount = Total_Ammount - prev_amm;
                    FIRST_ITEM = p->next_item;
                    return 0;
                }
                UPDATE_INVENTORY_STOCK(id,-quan);
                p->BOUGHT_ITEM_AMMOUNT = p->BOUGHT_ITEM_AMMOUNT - (quan*p->BOUGHT_ITEM_RATE);
                Total_Ammount = Total_Ammount - (quan* p->BOUGHT_ITEM_RATE);
            }
            else
            {

                while(p && p->BOUGHT_ITEM_ID!=id)
                {
                    q=p;
                    p=p->next_item;
                }

                if(p!=nullptr)
                {
                    int t=p->BOUGHT_ITEM_QUANTITY;
                    prev_amm = p->BOUGHT_ITEM_AMMOUNT;
                    p->BOUGHT_ITEM_QUANTITY = p->BOUGHT_ITEM_QUANTITY - quan;
                    if(p->BOUGHT_ITEM_QUANTITY <=0)
                    {
                        UPDATE_INVENTORY_STOCK(id,-t);
                        Total_Ammount = Total_Ammount - prev_amm;
                        q->next_item = p->next_item;
                        return 0;
                    }
                    UPDATE_INVENTORY_STOCK(id,-quan);
                    p->BOUGHT_ITEM_AMMOUNT = p->BOUGHT_ITEM_AMMOUNT - (quan*p->BOUGHT_ITEM_RATE);
                    Total_Ammount = Total_Ammount - quan*p->BOUGHT_ITEM_RATE;
                }
                else
                {
                    cout<<"You have not bought item of this item id "<<endl;
                }
            }
        }

        //THIS IS FOR ADDING THE POINTS IN CUSTOMER DATA BASE
        void ADD_CUSTOMERS_POINT(LL cus_id)
        {
            ADD_POINTS(cus_id,Total_Ammount);
        }

        //THIS IS FOR PRINTING THE BLL
        int PRINT_THE_BILL()
        {
            cout<<"_______________________________BILL GENERATED________________________________________________"<<endl<<endl;
            BOUGHT_ITEM *p=FIRST_ITEM;
            cout<<"Transaction id :"<<Transaction_ID<<"          "<<"Customer id :"<<CUSTOMER_ID;
            cout<<endl<<endl;
            if(p==NULL)
            {
                cout<<"There is nothing you bought "<<endl;
                return 0;
            }
            cout<<"Item ID"<<"               "<<"Item Name"<<"            "<<"Quantity"<<"            "<<"Rate"<<"           ";
            cout<<"Ammount per item"<<endl;
            while(p!=NULL)
            {
                cout<<p->BOUGHT_ITEM_ID<<"          "<<p->BOUGHT_ITEM_NAME<<"            "<<p->BOUGHT_ITEM_QUANTITY;
                cout<<"                   "<<p->BOUGHT_ITEM_RATE<<"            "<<p->BOUGHT_ITEM_AMMOUNT<<endl;
                p=p->next_item;
            }
            cout<<endl<<"Grand total is :"<<Total_Ammount<<endl;

        }


        //THIS METHOD IS FOR DELETING THE CURRENT DATASET OF BILLING
        //THIS WILL WORK AS SAME AS DISTRUCTOR BUT WE DO NOT WANT TO DESTROY THE OBJECT
        //SO I HAVE JUST MAKE A FUNCTION WHICH WORKS AS SAME AS DESTRUCTOR
        void MAKE_NULL()
        {
            BOUGHT_ITEM *p=FIRST_ITEM;
            BOUGHT_ITEM *q=NULL;

            while(p)
            {
                q=p;
                p=p->next_item;
                q->BOUGHT_ITEM_AMMOUNT=0;
                q->BOUGHT_ITEM_ID=0;
                q->BOUGHT_ITEM_NAME="";
                q->BOUGHT_ITEM_QUANTITY=0;
                q->BOUGHT_ITEM_RATE=0;
                q->next_item=NULL;
                q=NULL;
            }
            Total_Ammount = 0;
            FIRST_ITEM=NULL;
            LAST_ITEM=NULL;
        }


};

int main()
{
    MANAGER M;
    BILLING B;
    int i=0;

    //READING THE DATA AND UPLOADING IN THE INVENTORY
    while(i<100)
    {
        M.ADD_PRODUCTS(DATA[i]);
        i++;
    }
    i=0;

    //READING THE DATA AND UPLOADING IN THE CUSTOMER DATABASE
    while(i<100)
    {
        B.ADD_NEW_CUSTOMER_DATA(CUSTOMER_DATASET[i]);
        i++;
    }

    LL customer_s_id;
    int number_of_items;
    LL purchased_item_id;
    int Purchased_item_quantity;
    bool checker;
    int n;
    cout<<"Press 1 for go to billing and press 0 for exit : ";
    cin>>n;
    cout<<endl<<endl;

    while(n!=0)
    {

        cout<<"Enter your customer id : ";
        cin>>customer_s_id;
        checker=B.CHECK_CUSTOMER(customer_s_id);
        if(checker==false)
        {
            //THIS IS FOR IF NEW CUSTOMER ARRIVE THEN WE WILL UPLOAD IT IN THE DATA BASE
            B.UPLOAD_NEW_CUSTOMER(customer_s_id);
        }
        cout<<"Enter the number of items you want to buy : ";
        cin>>number_of_items;
        cout<<endl<<endl;
        B.ASSIGN_CUSTOMER_ID(customer_s_id);
        LL ARRAY_ITEMS[number_of_items];

        for(int i=0;i<number_of_items;i++)
        {
            cout<<"Enter the item id you want to buy : ";
            cin>>purchased_item_id;
            cout<<endl;
            checker = B.SEARCH_PRODUCT(purchased_item_id);
            if(checker==false)
            {
                cout<<endl;
                cout<<"Item is not available,you have to buy another one"<<endl;
                i--;
                continue;
            }
            else
            {
                cout<<"Enter the quantity of the item: ";
                cin>>Purchased_item_quantity;
                int k=B.BUY_ITEMS(purchased_item_id,Purchased_item_quantity);
                if(k==0)
                {
                    i--;
                    continue;
                }
                B.UPDATE_INVENTORY_STOCK(purchased_item_id,Purchased_item_quantity);
                ARRAY_ITEMS[i] = purchased_item_id;

            }
        }

        cout<<endl;

        string d;
        cout<<"Do you want to cancel any item press Y for canceling and press N for continue billing : ";
        cin>>d;
        cout<<endl;

        while(d=="Y")
        {
            LL cancel_id;
            int cancel_quant;
            cout<<"Enter the item id you want to cancel :";
            cin>>cancel_id;
            cout<<endl;

            cout<<"Enter the quantity you want to reduce :";
            cin>>cancel_quant;
            cout<<endl;
            B.CANCEL_ITEM(cancel_id,cancel_quant,customer_s_id);
            cout<<endl<<"Do you want to cancel any item again ";
            cin>>d;
        }
        B.ADD_CUSTOMERS_POINT(customer_s_id);
        cout<<endl<<endl;
        B.PRINT_THE_BILL();
        cout<<endl<<endl<<endl;
        cout<<"____________________CUSTOMER DATABASE AFTER A SHOPING EPISODE_______________________________"<<endl<<endl;
        B.CUSTOMER_DETAILS(customer_s_id);
        cout<<endl<<endl;

        int r=0;
        //FLUSHING THE DUPLICATE ITEMS
        while(r<number_of_items)
        {
            int j=0;
            for(j=r+1;j<number_of_items;j++)
            {
                if(ARRAY_ITEMS[r]==ARRAY_ITEMS[j])
                {
                    ARRAY_ITEMS[j]=-1;
                }
            }
            r++;
        }
        r=0;
        cout<<endl<<endl;
        cout<<"__________________INVENTORY DATA BASE UPDATION AFTER BILLING________________________________"<<endl<<endl;
        while(r<number_of_items)
        {
            if(ARRAY_ITEMS[r]!=-1)
            {
                M.SHOW_INVENTORY_DETAIL(ARRAY_ITEMS[r]);
                cout<<endl;
            }
            r++;
        }
        cout<<endl<<endl;
        TRANS_ID++;
        B.MAKE_NULL();
        cout<<endl;
        cout<<"Press 1 for continue billing and press 0 for exit :"<<endl;
        cin>>n;
        if(n==0)
            break;
    }




}

